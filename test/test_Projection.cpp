#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

#include <stdio.h>
#include <iostream>
#include <array>
#include "Projection.h"
#include "proj.h"

TEST_CASE("From WGS84 to Cartesian: Identical WGS84 position") {
    constexpr std::array<double, 2> WGS84Reference{52.247041, 10.575830};
    constexpr std::array<double, 2> expectedResult{0.0, 0.0};

    std::array<double, 2> result{wgs84::toCartesian(WGS84Reference, WGS84Reference)};

    REQUIRE(expectedResult[0] == Approx(result[0]));
    REQUIRE(expectedResult[1] == Approx(result[1]));
}