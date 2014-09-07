#ifndef _RS_DBI_H
#define _RS_DBI_H 1
/*  
 * Copyright (C) 1999-2002 The Omega Project for Statistical Computing.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Rhelpers.h"
#include <ctype.h>


/* We now define 4 important data structures:
 * SQLiteDriver, RS_DBI_connection, RS_DBI_resultSet, and
 * RS_DBI_fields, corresponding to dbManager, dbConnection,
 * dbResultSet, and list of field descriptions.
 */

typedef enum enum_dbi_exception {
  RS_DBI_MESSAGE,
  RS_DBI_WARNING,
  RS_DBI_ERROR,
  RS_DBI_TERMINATE
} DBI_EXCEPTION;


/* First, the following fully describes the field output by a select
 * (or select-like) statement, and the mappings from the internal
 * database types to S classes.  This structure contains the info we need
 * to build the R/S list (or data.frame) that will receive the SQL
 * output.  It still needs some work to handle arbitrty BLOB's (namely
 * methods to map BLOBs into user-defined S objects).
 * Each element is an array of num_fields, this flds->Sclass[3] stores
 * the S class for the 4th output fields.
 */
typedef struct st_sdbi_fields {
  int num_fields;
  char  **name;         /* DBMS field names */
  int  *type;          /* DBMS internal types */
  int  *length;        /* DBMS lengths in bytes */
  int  *isVarLength;   /* DBMS variable-length char type */
  SEXPTYPE *Sclass;        /* R/S class (type) -- may be overriden */
} RS_DBI_fields;

typedef struct st_sdbi_exception {
  DBI_EXCEPTION  exceptionType; /* one of RS_DBI_WARN, RS_RBI_ERROR, etc */
  int  errorNum;            /* SQL error number (possibly driver-dependent*/
  char *errorMsg;           /* SQL error message */
} RS_DBI_exception;

/* The RS-DBI resultSet consists of a pointer to the actual DBMS 
 * resultSet (e.g., MySQL, Oracle) possibly NULL,  plus the fields 
 * defined by the RS-DBI implementation. 
 */
typedef struct st_sdbi_resultset {
  void  *drvResultSet;   /* the actual (driver's) cursor/result set */
  void  *drvData;        /* a pointer to driver-specific data */
  int  resultSetId;  
  int  isSelect;        /* boolean for testing SELECTs */
  char  *statement;      /* SQL statement */
  int  rowsAffected;    /* used by non-SELECT statements */
  int  rowCount;        /* rows fetched so far (SELECT-types)*/
  int  completed;       /* have we fetched all rows? */
  RS_DBI_fields *fields;
} RS_DBI_resultSet;

/* A dbConnection consists of a pointer to the actual implementation
 * (MySQL, Oracle, etc.) connection plus a resultSet and other
 * goodies used by the RS-DBI implementation.
 * The connection parameters (user, password, database name, etc.) are
 * defined by the actual driver -- we just set aside a void pointer.
 */

typedef struct st_sdbi_connection {
  void  *drvConnection;  /* pointer to the actual DBMS connection struct*/
  void  *drvData;        /* to be used at will by individual drivers */
  RS_DBI_resultSet  **resultSets;    /* vector to result set ptrs  */
  int   *resultSetIds;
  int   num_res;                    /* num of open resultSets */
  RS_DBI_exception *exception;
} RS_DBI_connection;

/* dbManager */
typedef struct st_sdbi_manager {
  int shared_cache;                /* use SQLite shared cache? */
  int num_con;                     /* num of opened connections */
  int counter;                     /* num of connections handled so far*/
  int fetch_default_rec;           /* default num of records per fetch */
  RS_DBI_exception *exception;    
} SQLiteDriver;

/* All RS_DBI functions and their signatures */

SQLiteDriver* getDriver();

/* dbConnection */
SEXP RS_DBI_allocConnection();
void RS_DBI_freeConnection(SEXP conHandle);
RS_DBI_connection *RS_DBI_getConnection(SEXP handle);
SEXP RS_DBI_asConHandle(RS_DBI_connection *con);

/* dbResultSet */
SEXP RS_DBI_allocResultSet(SEXP conHandle);
void RS_DBI_freeResultSet(SEXP rsHandle);
void RS_DBI_freeResultSet0(RS_DBI_resultSet *result, RS_DBI_connection *con);
RS_DBI_resultSet  *RS_DBI_getResultSet(SEXP rsHandle);
SEXP RS_DBI_asResHandle(SEXP conxp);

/* a simple object database (mapping table) -- it uses simple linear 
 * search (we don't expect to have more than a handful of simultaneous 
 * connections and/or resultSets. If this is not the case, we could
 * use a hash table, but I doubt it's worth it (famous last words!).
 * These are used for storing/retrieving object ids, such as
 * connection ids from the manager object, and resultSet ids from a 
 * connection object;  of course, this is transparent to the various
 * drivers -- they should deal with handles exclusively.
 */
int  RS_DBI_newEntry(int *table, int length);
int  RS_DBI_lookup(int *table, int length, int obj_id);
int  RS_DBI_listEntries(int *table, int length, int *entries);
void  RS_DBI_freeEntry(int *table, int indx);

/* description of the fields in a result set */
RS_DBI_fields *RS_DBI_allocFields(int num_fields);
SEXP RS_DBI_getFieldDescriptions(RS_DBI_fields *flds);
void           RS_DBI_freeFields(RS_DBI_fields *flds);

/* we (re)allocate the actual output list in here (with the help of
 * RS_DBI_fields).  This should be some kind of R/S "relation"
 * table, not a dataframe nor a list.
 */
void  RS_DBI_allocOutput(SEXP output, 
			RS_DBI_fields *flds,
			int num_rec,
			int expand);

/* utility funs (copy strings, convert from R/S types to string, etc.*/
char     *RS_DBI_copyString(const char *str);

/* We now define a generic data type name-Id mapping struct
 * and initialize the RS_dataTypeTable[].  Each driver could
 * define similar table for generating friendly type names
 */
struct data_types {
    char *typeName;
    int typeId;
};

/* return the primitive type name for a primitive type id */
char     *RS_DBI_getTypeName(int typeCode, const struct data_types table[]);
/* same, but callable from S/R and vectorized */
SEXP RS_DBI_SclassNames(SEXP types);  

SEXP RS_DBI_createNamedList(char  **names, 
				 SEXPTYPE *types,
				 int  *lengths,
				 int  n);
SEXP RS_DBI_copyFields(RS_DBI_fields *flds);

extern const struct data_types RS_dataTypeTable[];

SEXP DBI_newResultHandle(SEXP xp, SEXP resId);

#ifdef __cplusplus 
}
#endif
#endif   /* _RS_DBI_H */
