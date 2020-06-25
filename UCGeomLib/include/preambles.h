#ifndef TYPEDEF_H
#define TYPEDEF_H

#pragma once

#include <armadillo>

namespace UCGeomLib {

//! Global variables.
const double  ZERO = 1.0e-6;


//! Type definitions.

typedef arma::uword Index;

typedef arma::vec   X;
typedef arma::vec2  XY;
typedef arma::vec3  XYZ;

typedef arma::mat   Pts;

//! Error codes.
namespace ErrorCodes {
const std::string INVALID_ARGUMENT {"Invalid Argument!"};
}

}

#endif // TYPEDEF_H
