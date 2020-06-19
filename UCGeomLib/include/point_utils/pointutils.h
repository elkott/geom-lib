#ifndef POINTUTILS_H
#define POINTUTILS_H

#pragma once

#include <armadillo>
#include "../typedef.h"

namespace UCGeomLib{

namespace PointUtils{

double          dot                     (const UCGeomLib::XY &aA,
                                         const UCGeomLib::XY &aB);

double          distance                (const UCGeomLib::XY &aA,
                                         const UCGeomLib::XY &aB);

UCGeomLib::XY   normalize               (const UCGeomLib::XY &aV);

double          shortestDistanceToLine  (const UCGeomLib::XY &aPt,
                                         const UCGeomLib::XY &aLinePt,
                                         const UCGeomLib::XY &aLineDir);

UCGeomLib::XY   closestLinePtToPt       (const UCGeomLib::XY &aPt,
                                         const UCGeomLib::XY &aLinePt,
                                         const UCGeomLib::XY &aLineDir);

}
}

#endif // POINTUTILS_H
