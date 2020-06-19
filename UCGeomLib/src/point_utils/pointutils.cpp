#include "../../include/point_utils/pointutils.h"

using namespace arma;
using namespace UCGeomLib;

double UCGeomLib::PointUtils::dot(const UCGeomLib::XY &aA, const UCGeomLib::XY &aB)
{
    return arma::dot(aA, aB);
}


double PointUtils::distance(const XY &aA, const XY &aB)
{
    return arma::norm(aA - aB);
}


XY PointUtils::normalize(const XY &aV)
{
    return arma::normalise(aV);
}


double PointUtils::shortestDistanceToLine(const XY &aPt,
                                          const XY &aLinePt,
                                          const XY &aLineDir)
{
    // Closest line point to space point.
    XY      lClosestPt  = closestLinePtToPt(aPt, aLinePt, aLineDir);

    // Return shortest distance.
    return  distance(lClosestPt, aPt);
}

XY PointUtils::closestLinePtToPt(const XY &aPt,
                                 const XY &aLinePt,
                                 const XY &aLineDir)
{
    // Local variables.
    XY      lLineDir    = normalize(aLineDir);
    XY      lV          = aPt - aLinePt;
    double  lProjDist   = dot(lV, lLineDir);

    // Closest line point to space point.
    XY      lClosestPt  = aLinePt + lProjDist * lLineDir;

    return  lClosestPt;
}
