// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "RSQLite_types.h"
#include <Rcpp.h>

using namespace Rcpp;

// rsqlite_connect
XPtr<SqliteConnectionPtr> rsqlite_connect(std::string path, bool allow_ext, int flags, std::string vfs = "");
RcppExport SEXP RSQLite_rsqlite_connect(SEXP pathSEXP, SEXP allow_extSEXP, SEXP flagsSEXP, SEXP vfsSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< std::string >::type path(pathSEXP );
        Rcpp::traits::input_parameter< bool >::type allow_ext(allow_extSEXP );
        Rcpp::traits::input_parameter< int >::type flags(flagsSEXP );
        Rcpp::traits::input_parameter< std::string >::type vfs(vfsSEXP );
        XPtr<SqliteConnectionPtr> __result = rsqlite_connect(path, allow_ext, flags, vfs);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// rsqlite_disconnect
void rsqlite_disconnect(XPtr<SqliteConnectionPtr> con);
RcppExport SEXP RSQLite_rsqlite_disconnect(SEXP conSEXP) {
BEGIN_RCPP
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< XPtr<SqliteConnectionPtr> >::type con(conSEXP );
        rsqlite_disconnect(con);
    }
    return R_NilValue;
END_RCPP
}
// rsqlite_get_exception
std::string rsqlite_get_exception(XPtr<SqliteConnectionPtr> con);
RcppExport SEXP RSQLite_rsqlite_get_exception(SEXP conSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< XPtr<SqliteConnectionPtr> >::type con(conSEXP );
        std::string __result = rsqlite_get_exception(con);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// rsqlite_copy_database
void rsqlite_copy_database(XPtr<SqliteConnectionPtr> from, XPtr<SqliteConnectionPtr> to);
RcppExport SEXP RSQLite_rsqlite_copy_database(SEXP fromSEXP, SEXP toSEXP) {
BEGIN_RCPP
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< XPtr<SqliteConnectionPtr> >::type from(fromSEXP );
        Rcpp::traits::input_parameter< XPtr<SqliteConnectionPtr> >::type to(toSEXP );
        rsqlite_copy_database(from, to);
    }
    return R_NilValue;
END_RCPP
}
// rsqlite_connection_valid
bool rsqlite_connection_valid(XPtr<SqliteConnectionPtr> con);
RcppExport SEXP RSQLite_rsqlite_connection_valid(SEXP conSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< XPtr<SqliteConnectionPtr> >::type con(conSEXP );
        bool __result = rsqlite_connection_valid(con);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// rsqlite_send_query
XPtr<SqliteResult> rsqlite_send_query(XPtr<SqliteConnectionPtr> con, std::string sql);
RcppExport SEXP RSQLite_rsqlite_send_query(SEXP conSEXP, SEXP sqlSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< XPtr<SqliteConnectionPtr> >::type con(conSEXP );
        Rcpp::traits::input_parameter< std::string >::type sql(sqlSEXP );
        XPtr<SqliteResult> __result = rsqlite_send_query(con, sql);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// rsqlite_clear_result
void rsqlite_clear_result(XPtr<SqliteResult> res);
RcppExport SEXP RSQLite_rsqlite_clear_result(SEXP resSEXP) {
BEGIN_RCPP
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< XPtr<SqliteResult> >::type res(resSEXP );
        rsqlite_clear_result(res);
    }
    return R_NilValue;
END_RCPP
}
// rsqlite_fetch
List rsqlite_fetch(XPtr<SqliteResult> res, int n = 10);
RcppExport SEXP RSQLite_rsqlite_fetch(SEXP resSEXP, SEXP nSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< XPtr<SqliteResult> >::type res(resSEXP );
        Rcpp::traits::input_parameter< int >::type n(nSEXP );
        List __result = rsqlite_fetch(res, n);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// rsqlite_bind_params
void rsqlite_bind_params(XPtr<SqliteResult> res, List params);
RcppExport SEXP RSQLite_rsqlite_bind_params(SEXP resSEXP, SEXP paramsSEXP) {
BEGIN_RCPP
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< XPtr<SqliteResult> >::type res(resSEXP );
        Rcpp::traits::input_parameter< List >::type params(paramsSEXP );
        rsqlite_bind_params(res, params);
    }
    return R_NilValue;
END_RCPP
}
// rsqlite_has_completed
bool rsqlite_has_completed(XPtr<SqliteResult> res);
RcppExport SEXP RSQLite_rsqlite_has_completed(SEXP resSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< XPtr<SqliteResult> >::type res(resSEXP );
        bool __result = rsqlite_has_completed(res);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// rsqlite_row_count
int rsqlite_row_count(XPtr<SqliteResult> res);
RcppExport SEXP RSQLite_rsqlite_row_count(SEXP resSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< XPtr<SqliteResult> >::type res(resSEXP );
        int __result = rsqlite_row_count(res);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// rsqlite_rows_affected
int rsqlite_rows_affected(XPtr<SqliteResult> res);
RcppExport SEXP RSQLite_rsqlite_rows_affected(SEXP resSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< XPtr<SqliteResult> >::type res(resSEXP );
        int __result = rsqlite_rows_affected(res);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// rsqlite_column_info
List rsqlite_column_info(XPtr<SqliteResult> res);
RcppExport SEXP RSQLite_rsqlite_column_info(SEXP resSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< XPtr<SqliteResult> >::type res(resSEXP );
        List __result = rsqlite_column_info(res);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// rsqlite_result_valid
bool rsqlite_result_valid(XPtr<SqliteResult> res);
RcppExport SEXP RSQLite_rsqlite_result_valid(SEXP resSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< XPtr<SqliteResult> >::type res(resSEXP );
        bool __result = rsqlite_result_valid(res);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// rsqliteVersion
CharacterVector rsqliteVersion();
RcppExport SEXP RSQLite_rsqliteVersion() {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        CharacterVector __result = rsqliteVersion();
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
