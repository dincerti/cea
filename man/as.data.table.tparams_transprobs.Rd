% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/tparams_transprobs.R
\name{as.data.table.tparams_transprobs}
\alias{as.data.table.tparams_transprobs}
\title{Coerce to \code{data.table}}
\usage{
\method{as.data.table}{tparams_transprobs}(x, ..., prefix = "prob_", sep = "_")
}
\arguments{
\item{x}{A \link{tparams_transprobs} object.}

\item{...}{Currently unused.}

\item{prefix, sep}{Arguments passed to \code{\link[=tpmatrix_names]{tpmatrix_names()}} for naming
the transition probability columns. The \code{states} argument is based on
the column names (i.e., names of the second dimension) of the \verb{$value}
element of \code{x}; if \code{NULL}, then states are named \code{s1}, ..., \code{sh} where h is
the number of states.}
}
\value{
A \code{data.table} with one row for each transition probability matrix.
}
\description{
Creates a \code{data.table} that combines the transition probability matrices
and ID columns from a \link{tparams_transprobs} object. This is often useful for
debugging.
}
\examples{
# Create tparams_transprobs object
hesim_dat <- hesim_data(strategies = data.frame(strategy_id = 1:2),
                        patients = data.frame(patient_id = 1:3))
input_data <- expand(hesim_dat, by = c("strategies", "patients"))    
tpmat_id <- tpmatrix_id(input_data, n_samples = 2)      
p_12 <- runif(nrow(tpmat_id), .6, .7) + 
  .05 * (tpmat_id$strategy_id == 2)
tpmat <- tpmatrix(
  C, p_12,
  0, 1
)
tprobs <- tparams_transprobs(tpmat, tpmat_id)

# Convert to data.table
as.data.table(tprobs)
as.data.table(tprobs, prefix = "")
as.data.table(tprobs, prefix = "", sep = ".")

}
\seealso{
\link{tparams_transprobs}
}
