#ifndef TST_ARMADILLO_TESTS_H
#define TST_ARMADILLO_TESTS_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <armadillo>
#include "../UCGeomLib/include/preambles.h"

using namespace std;
using namespace testing;

using namespace arma;
using namespace UCGeomLib;


// ARMADILLO TESTS

TEST (ArmadilloTypes, svd_1)
{
    // Input
    Pts lPts{
        {0.0  , 1.0  },
        {1.75 , 2.5  },
        {9.15 , 1.15 },
        {4.15 , 3.19 },
        {10.0 , 10.0 }
    };

    X       lSvdSol         {17.2168,   5.13195 };
    X       lSvdUnitVSol    { 0.958332, 0.285657};
    double  lTol            { 5.0e-5            };

    // Calculate
    X       lSvd        = arma::svd(lPts);
    X       lSvdUnitV   = arma::normalise(lSvd);

    // Test
    EXPECT_NEAR(arma::norm(lSvd- lSvdSol),            0.0, lTol) << "Wrong SVD vector!";
    EXPECT_NEAR(arma::norm(lSvdUnitV - lSvdUnitVSol), 0.0, lTol) << "Wrong SVD vector!";
    EXPECT_NEAR(arma::norm(lSvdUnitV),                1.0, lTol) << "Wrong SVD vector!";
}

TEST (ArmadilloTypes, svd_2)
{
    // Input
    Pts lPts{
        {0.0 , 0.0 },
        {1.0 , 1.0 },
        {2.0 , 2.0 },
        {3.0 , 3.0 },
        {4.0 , 4.0 }
    };

    X lCentroid = {arma::mean(lPts.col(0)), arma::mean(lPts.col(1))};

//    lCentroid = arma::trans(lCentroid);

    Pts lSubtracted(lPts.n_rows, lPts.n_cols);

    for(Index i=0; i<lPts.n_rows; i++)
    {
        lSubtracted.row(i) = lPts.row(i) - arma::trans(lCentroid);
    }




    Pts lU, lV;
    X   lSvd, lS;

    X       lSvdSol         {14.7986,   0.0};
    X       lSvdUnitVSol    { 1.0,      0.0};
    double  lTol            { 5.0e-5       };

    // Calculate
    arma::svd(lU, lS, lV, lSubtracted);

    lSvd = lV.col(0);


//    X       lSvdUnitV   = arma::normalise(lSvd);

std::cout << "\n";
lU.raw_print(std::cout);
std::cout << "\n";
lS.raw_print(std::cout);
std::cout << "\n";
lV.raw_print(std::cout);
std::cout << "\n";
lSvd.raw_print(std::cout);


    // Test
//    EXPECT_NEAR(arma::norm(lSvd- lSvdSol),            0.0, lTol) << "Wrong SVD vector!";
//    EXPECT_NEAR(arma::norm(lSvdUnitV - lSvdUnitVSol), 0.0, lTol) << "Wrong SVD vector!";
//    EXPECT_NEAR(arma::norm(lSvdUnitV),                1.0, lTol) << "Wrong SVD vector!";
}



//TEST (ArmadilloTypes, matrix_1)
//{
//    // Input
//    Pts lPts{
//        {0.0  , 1.0  , 2.0},
//        {1.75 , 2.5  , 3.5},
//        {9.15 , 1.15 , 4.25},
//        {4.15 , 3.19 , 5.54},
//        {10.0 , 10.0 , 2.0}
//    };

//    X       lSol    {5.01, 3.568, 3.458};
//    double  lTol    {1.0e-5  };

//    // Calculate
//    X       lCentroid = PointUtils::centroid(lPts);

//    // Test
//    EXPECT_NEAR(PointUtils::ptPtDist(lCentroid, lSol), 0.0, lTol) << "Wrong centroid!";

//}


#endif // TST_ARMADILLO_TESTS_H
