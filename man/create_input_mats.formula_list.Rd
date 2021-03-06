% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/input_mats.R
\name{create_input_mats.formula_list}
\alias{create_input_mats.formula_list}
\title{Create input matrices from formula}
\usage{
\method{create_input_mats}{formula_list}(object, input_data, ...)
}
\arguments{
\item{object}{An object of the appropriate class.}

\item{input_data}{An object of class \code{expanded_hesim_data} returned by
\code{\link[=expand.hesim_data]{expand.hesim_data()}}. It is used to look for the variables needed to create
an input matrix for use in a statistical models and the ID variables for
indexing rows in the input matrix.}

\item{...}{Further arguments passed to \code{\link[=model.matrix]{model.matrix()}}.}
}
\value{
An object of class \code{input_mats}.
}
\description{
This is an internal function for creating input matrices from formulas. It
is currently used in some unit tests.
}
\seealso{
\code{\link[=create_input_mats]{create_input_mats()}}
}
\keyword{internal}
