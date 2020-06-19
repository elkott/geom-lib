#ifndef TST_POINTUTILS_H
#define TST_POINTUTILS_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <armadillo>
#include "../UCGeomLib/include/point_utils/pointutils.h"

using namespace std;
using namespace testing;

using namespace arma;
using namespace UCGeomLib;

// DOT PRODUCT
TEST(PointUtils, 2D_dot)
{
    arma::vec2 pt0{0.0,0.0};
    arma::vec2 pt1{1.0,1.0};

    EXPECT_EQ(UCGeomLib::PointUtils::dot(pt0, pt1), 0.0) << "Wrong dot product!";
}

// DISTANCE BETWEEN TWO POINTS
TEST(PointUtils, 2D_distance)
{
    UCGeomLib::XY pt0{0.0,0.0};
    UCGeomLib::XY pt1{1.0,1.0};

    EXPECT_EQ(UCGeomLib::PointUtils::distance(pt0, pt1), std::sqrt(2.0)) << "Wrong distance between two points!";
}

// ========================================
// SHORTEST DISTANCE BETWEEN POINT AND LINE
// ========================================
TEST(PointUtils, 2D_shortestDistance_pointToLine_1)
{
    // Input
    UCGeomLib::XY lPt      {5.0, 3.0};
    UCGeomLib::XY lLinePt  {4.0,-3.0};
    UCGeomLib::XY lLineDir {6.0, 2.0};

    double        lSolution{5.37587 };
    double        lTol     {1.0e-5  };

    // Calculation
    double  lShortestDistance = UCGeomLib::PointUtils::shortestDistanceToLine(lPt, lLinePt, lLineDir);

    // Test
    EXPECT_NEAR(lShortestDistance, lSolution, lTol) << "Wrong short distance between point and line!";
}

TEST(PointUtils, 2D_shortestDistance_pointToLine_2)
{
    // Input
    UCGeomLib::XY lPt      {1.0,-2.0};
    UCGeomLib::XY lLinePt  {4.0,-3.0};
    UCGeomLib::XY lLineDir {6.0, 2.0};

    double        lSolution{1.89737 };
    double        lTol     {1.0e-5  };

    // Calculation
    double  lShortestDistance = UCGeomLib::PointUtils::shortestDistanceToLine(lPt, lLinePt, lLineDir);

    // Test
    EXPECT_NEAR(lShortestDistance, lSolution, lTol) << "Wrong short distance between point and line!";
}

TEST(PointUtils, 2D_shortestDistance_pointToLine_3)
{
    // Input
    UCGeomLib::XY lPt      {1.6,-3.8};
    UCGeomLib::XY lLinePt  {4.0,-3.0};
    UCGeomLib::XY lLineDir {6.0, 2.0};

    double        lSolution{0.0     };
    double        lTol     {1.0e-5  };

    // Calculation
    double  lShortestDistance = UCGeomLib::PointUtils::shortestDistanceToLine(lPt, lLinePt, lLineDir);

    // Test
    EXPECT_NEAR(lShortestDistance, lSolution, lTol) << "Wrong short distance between point and line!";
}

TEST(PointUtils, 2D_shortestDistance_pointToLine_4)
{
    // Input
    UCGeomLib::XY lPt      {0.0, 5.0};
    UCGeomLib::XY lLinePt  {4.0, 0.0};
    UCGeomLib::XY lLineDir {6.0, 0.0};

    double        lSolution{5.0     };
    double        lTol     {1.0e-5  };

    // Calculation
    double  lShortestDistance = UCGeomLib::PointUtils::shortestDistanceToLine(lPt, lLinePt, lLineDir);

    // Test
    EXPECT_NEAR(lShortestDistance, lSolution, lTol) << "Wrong short distance between point and line!";
}

TEST(PointUtils, 2D_shortestDistance_pointToLine_5)
{
    // Input
    UCGeomLib::XY lPt      {0.0, 5.0};
    UCGeomLib::XY lLinePt  {4.0, 0.0};
    UCGeomLib::XY lLineDir {0.0,10.0};

    double        lSolution{4.0     };
    double        lTol     {1.0e-5  };

    // Calculation
    double  lShortestDistance = UCGeomLib::PointUtils::shortestDistanceToLine(lPt, lLinePt, lLineDir);

    // Test
    EXPECT_NEAR(lShortestDistance, lSolution, lTol) << "Wrong short distance between point and line!";
}

TEST(PointUtils, 2D_shortestDistance_pointToLine_6)
{
    // Input
    UCGeomLib::XY lPt      {4.0, 5.0};
    UCGeomLib::XY lLinePt  {4.0, 0.0};
    UCGeomLib::XY lLineDir {0.0,10.0};

    double        lSolution{0.0     };
    double        lTol     {1.0e-5  };

    // Calculation
    double  lShortestDistance = UCGeomLib::PointUtils::shortestDistanceToLine(lPt, lLinePt, lLineDir);

    // Test
    EXPECT_NEAR(lShortestDistance, lSolution, lTol) << "Wrong short distance between point and line!";
}


#endif // TST_POINTUTILS_H
