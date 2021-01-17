#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

#include <stdio.h>
#include <iostream>
#include <array>
#include "Projection.h"

TEST_CASE("From WGS84 to Lambert93") {
    constexpr std::array<double, 3> WGS84{48.19517461, -3.028930672, -117.281 };
    constexpr std::array<double, 2> expectedResult{48.1952, 0.0};
    Projection P(WGS84);
    P.Proj();
    std::vector<PJ_XYZ> Coords = P.get_coords();
    std::array<double, 2> result{Coords.begin()->x,Coords.end()->y};
    std::cout << expectedResult[1] << ", " << float(result[1]) << std::endl;
    REQUIRE(expectedResult[0] == Approx(result[0]));
    REQUIRE(expectedResult[1] == Approx(result[1]));
}