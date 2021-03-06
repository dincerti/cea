% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/utils.R
\name{absorbing}
\alias{absorbing}
\alias{absorbing.matrix}
\alias{absorbing.tparams_transprobs}
\title{Absorbing states}
\usage{
absorbing(x, ...)

\method{absorbing}{matrix}(x, ...)

\method{absorbing}{tparams_transprobs}(x, ...)
}
\arguments{
\item{x}{An object of the appropriate class. When \code{x} is a \code{matrix},
it must be a transition matrix in the format from the
\code{\link[mstate:mstate-package]{mstate}} package (see also \code{\link{IndivCtstmTrans}}).}
}
\description{
This is a generic function that returns a vector of absorbing states.
}
\keyword{internal}
