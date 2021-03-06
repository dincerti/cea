% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/tpmatrix.R
\name{qmatrix.msm}
\alias{qmatrix.msm}
\title{Transition intensity matrix from \code{msm} object}
\usage{
\method{qmatrix}{msm}(x, newdata = NULL, uncertainty = c("normal", "none"), n = 1000, ...)
}
\arguments{
\item{x}{A \code{\link[msm:msm]{msm::msm}} object.}

\item{newdata}{A data frame to look for variables with which to predict. A
separate transition intensity matrix is predicted based on each row in
\code{newdata}. Can be \code{NULL} if no covariates are included in the fitted \code{msm}
object.}

\item{uncertainty}{Method used to draw transition intensity matrices. If \verb{"none}",
then point estimates are used. If \code{"normal"}, then samples are drawn from the
multivariate normal distribution of the regression coefficients.}

\item{n}{Number of random observations of the parameters to draw.}

\item{...}{Further arguments passed to or from other methods. Currently unused.}
}
\value{
An array of transition intensity matrices with the third dimension
equal to the number of rows in \code{newdata}.
}
\description{
Draw transition intensity matrices for a probabilistic sensitivity analysis
from a fitted \code{msm} object.
}
\examples{
library("msm")
set.seed(101)
 qinit <- rbind(
   c(0, 0.28163, 0.01239),
   c(0, 0, 0.10204),
   c(0, 0, 0)
 )
fit <- msm(state_id ~ time, subject = patient_id, 
           data = onc3p[patient_id \%in\% sample(patient_id, 100)],
           covariates = list("1-2" =~ age + strategy_name), 
           qmatrix = qinit)
qmatrix(fit, newdata = data.frame(age = 55, strategy_name = "New 1"),
        uncertainty = "none")
qmatrix(fit, newdata = data.frame(age = 55, strategy_name = "New 1"),
        uncertainty = "normal",  n = 3)

}
\seealso{
\code{qmatrix.matrix()}
}
