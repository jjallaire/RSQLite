% Generated by roxygen2 (4.1.0): do not edit by hand
% Please edit documentation in R/ConnectionRead.R
\docType{methods}
\name{dbReadTable,SQLiteConnection,character-method}
\alias{dbReadTable,SQLiteConnection,character-method}
\title{Convenience functions for importing/exporting DBMS tables}
\usage{
\S4method{dbReadTable}{SQLiteConnection,character}(conn, name, row.names = NA,
  check.names = TRUE, select.cols = "*")
}
\arguments{
\item{conn}{a \code{\linkS4class{SQLiteConnection}} object, produced by
\code{\link[DBI]{dbConnect}}}

\item{name}{a character string specifying a table name. SQLite table names
are \emph{not} case sensitive, e.g., table names \code{ABC} and \code{abc}
are considered equal.}

\item{row.names}{A string or an index specifying the column in the DBMS table
to use as \code{row.names} in the output data.frame. Defaults to using the
\code{row_names} column if present. Set to \code{NULL} to never use
row names.}

\item{check.names}{If \code{TRUE}, the default, column names will be
converted to valid R identifiers.}

\item{select.cols}{A SQL statement (in the form of a character vector of
length 1) giving the columns to select. E.g. "*" selects all columns,
"x,y,z" selects three columns named as listed.}
}
\value{
A data.frame in the case of \code{dbReadTable}; otherwise a logical
indicating whether the operation was successful.
}
\description{
These functions mimic their R/S-Plus counterpart \code{get}, \code{assign},
\code{exists}, \code{remove}, and \code{objects}, except that they generate
code that gets remotely executed in a database engine.
}
\note{
Note that the data.frame returned by \code{dbReadTable} only has
primitive data, e.g., it does not coerce character data to factors.
}
\examples{
con <- dbConnect(SQLite())
dbWriteTable(con, "mtcars", mtcars)
dbReadTable(con, "mtcars")

# Supress row names
dbReadTable(con, "mtcars", row.names = FALSE)

dbDisconnect(con)
}

