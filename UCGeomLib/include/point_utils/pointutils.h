#ifndef POINTUTILS_H
#define POINTUTILS_H

#pragma once
#include <stdexcept>

#include <armadillo>
#include "../preambles.h"

namespace UCGeomLib{

namespace PointUtils{

//!
//!\author Diaa ElKott
//!
template <typename  T>
double dot(const T &aV0, const T &aV1){
    return static_cast<double>(arma::dot(aV0,aV1));
}


template <typename T>
T normalized(const T &aV) {
    if(arma::sum(aV) <= UCGeomLib::ZERO){
        throw std::invalid_argument(UCGeomLib::ErrorCodes::INVALID_ARGUMENT);
    }
    return static_cast<T>(arma::normalise(aV));
}


template <typename T>
void normalize(T &aV){
    if(arma::sum(aV) <= UCGeomLib::ZERO){
        throw std::invalid_argument(UCGeomLib::ErrorCodes::INVALID_ARGUMENT);
    }
    aV = arma::normalise(aV);
}


template <typename T>
double ptPtDist(const T &aPt0, const T &aPt1){
    return static_cast<double>(arma::norm(aPt0-aPt1));
}


template <typename T>
T closestLinePtToPt(const T &aPt, const T &aLinePt, const T &aLineDir){

    // Local variables.
    T    lLineDir    = normalized(aLineDir);
    T    lV          = aPt - aLinePt;
    double    lProjDist   = PointUtils::dot(lV, lLineDir);

    // Closest line point to space point.
    return aLinePt + lProjDist * lLineDir;
}


template <typename T>
double shortestDistanceToLine(const T &aPt, const T &aLinePt, const T &aLineDir){
    auto lClosestPt = closestLinePtToPt(aPt, aLinePt, aLineDir);
    return ptPtDist(lClosestPt, aPt);
}

template  <typename T>
arma::vec centroid(const T &aPntSet){
    if(aPntSet.n_rows == 0){
        throw std::invalid_argument(UCGeomLib::ErrorCodes::INVALID_ARGUMENT);
    }

    arma::vec lCentroid;
    lCentroid.set_size(aPntSet.n_cols);

    for(Index i=0; i < aPntSet.n_cols; i++)
        lCentroid.at(i) = arma::mean(aPntSet.col(i));

    return lCentroid;

}

}
}

#endif // POINTUTILS_H
