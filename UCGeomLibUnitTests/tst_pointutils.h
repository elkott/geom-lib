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


// ========================================
// VECTOR OPERATIONS
// ========================================

// NORMALIZE VECTOR
TEST(PointUtils, 2D_normalizeVector_1)
{
    // Input
    UCGeomLib::XY   lVec{10.0, 10.0};
    UCGeomLib::XY   lVecSol{0.707107, 0.707107};
    double          lMagSol{1.0};
    double          lTol   {1.0e-5  };

    // Calculate
    UCGeomLib::PointUtils::normalize(lVec);

    // Test
    EXPECT_NEAR(norm(lVec-lVecSol), 0.0, lTol)  << "Wrong vector normalization!";
    EXPECT_NEAR(norm(lVec), lMagSol, lTol)      << "Wrong vector normalization!";
}

TEST(PointUtils, 2D_normalizeVector_2)
{
    // Input
    UCGeomLib::XY   lVec{0.0, 0.0};

    // Test - Expect "Invalid Argument" exception!
    EXPECT_THROW(UCGeomLib::PointUtils::normalize(lVec), std::invalid_argument) << "Should have thrown an exception!";
}


TEST(PointUtils, 3D_normalizeVector_1)
{
    // Input
    UCGeomLib::XYZ  lVec{10.0, 10.0, 10.0};
    UCGeomLib::XYZ  lVecSol{0.5773502, 0.5773502, 0.5773502};
    double          lMagSol{1.0};
    double          lTol   {1.0e-5  };

    // Calculate
    UCGeomLib::PointUtils::normalize(lVec);

    // Test
    EXPECT_NEAR(norm(lVec-lVecSol), 0.0, lTol)  << "Wrong vector normalization!";
    EXPECT_NEAR(norm(lVec), lMagSol, lTol)      << "Wrong vector normalization!";
}

TEST(PointUtils, 3D_normalizeVector_2)
{
    // Input
    UCGeomLib::XYZ  lVec{0.0, 0.0, 0.0};

    // Test - Expect "Invalid Argument" exception!
    EXPECT_THROW(UCGeomLib::PointUtils::normalize(lVec), std::invalid_argument) << "Should have thrown an exception!";
}


// DOT PRODUCT
TEST(PointUtils, 2D_dotProduct_1)
{
    arma::vec2 pt0{0.0,0.0};
    arma::vec2 pt1{1.0,1.0};

    EXPECT_EQ(UCGeomLib::PointUtils::dot(pt0, pt1), 0.0) << "Wrong dot product!";
}

// DISTANCE BETWEEN TWO POINTS
TEST(PointUtils, 2D_pointToPpointDistance_1)
{
    // Input
    UCGeomLib::XY pt0{0.0,0.0};
    UCGeomLib::XY pt1{1.0,1.0};

    double        lSolution{std::sqrt(2.0)};
    double        lTol     {1.0e-5  };

    // Calculation
    double lDistance = UCGeomLib::PointUtils::ptPtDist<XY>(pt0, pt1);

    // Test
    EXPECT_NEAR(lDistance, lSolution, lTol) << "Wrong distance between two points!";
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


// ========================================
// OPERATIONS ON POINT SETS
// ========================================


// POINT SET CENTROID

TEST (PointUtils, 3D_pointSetCentroid_1)
{
    // Input
    Pts lPts{
        {0.0  , 1.0  , 2.0},
        {1.75 , 2.5  , 3.5},
        {9.15 , 1.15 , 4.25},
        {4.15 , 3.19 , 5.54},
        {10.0 , 10.0 , 2.0}
    };

    X       lSol    {5.01, 3.568, 3.458};
    double  lTol    {1.0e-5  };

    // Calculate
    X       lCentroid = PointUtils::centroid(lPts);

    // Test
    EXPECT_NEAR(PointUtils::ptPtDist(lCentroid, lSol), 0.0, lTol) << "Wrong centroid!";

}



#endif // TST_POINTUTILS_H
