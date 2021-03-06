% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/distributions.R
\name{mom_beta}
\alias{mom_beta}
\title{Method of moments for beta distribution}
\usage{
mom_beta(mean, sd)
}
\arguments{
\item{mean}{Mean of the random variable.}

\item{sd}{Standard deviation of the random variable.}
}
\value{
A list containing the parameters \code{shape1} and \code{shape2}.
}
\description{
Compute the parameters \code{shape1} and \code{shape2} of the beta distribution
using method of moments given the mean and standard
deviation of the random variable of interest.
}
\details{
If \eqn{\mu} is the mean and
\eqn{\sigma} is the standard deviation of the random variable, then the method
of moments estimates of the parameters \code{shape1} = \eqn{\alpha > 0} and
\code{shape2} = \eqn{\beta > 0} are:
\deqn{\alpha = \mu \left(\frac{\mu(1-\mu)}{\sigma^2}-1 \right)}
and
\deqn{\beta = (1 - \mu) \left(\frac{\mu(1-\mu)}{\sigma^2}-1 \right)}
}
\examples{
mom_beta(mean = .8, sd = .1)
# The function is vectorized.
mom_beta(mean = c(.6, .8), sd = c(.08, .1))

}
