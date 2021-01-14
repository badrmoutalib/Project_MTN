#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <array>
#include <vector>
#include "Projection.h"
#include "proj.h"
#include "DTM.h"

/**
    * \ Main
    * \ brief  Creates raster PPM file of a cloud point data of Guerlédan Lac.
    * \ author  Badr Moutalib
    * \ date  2021
*/
int main (int argc, char* argv[])
{
    /**
    * \ brief Creates a projection object and assigns the data file Path
    */
    Projection P(argv[1]);
    P.Proj();
    std::vector<PJ_XYZ> Coords = P.get_coords();
    /**
    * \ brief Creates a DTM map object and assigns the Coordinates pointer
    */
    DTM map(&Coords);
    map.point_set();
    /**
    * \ brief Sets width and create raster image in PPM format
    */
    map.set_width(atof(argv[2]));
    map.create_raster();
}  
