#include <stdio.h>
#include <iostream>
//#include "WGS84toCartesian.hpp"
#include <array>
#include <vector>
#include <algorithm>
#include "Projection.h"
#include "proj.h"
#include "DTM.h"

int main (void) {

    Projection P("../data/Guerledan_Feb19_50cm_wgs84.txt");
    P.Proj();
    std::vector<PJ_XYZ> Coords = P.get_coords();
    DTM map(&Coords);
    map.point_set();
    map.create_raster();

    /*for(std::vector<PJ_XYZ>::iterator it = Coords.begin(); it != Coords.end() ; ++it)
    {
    	std::cout << it->x << std::endl;
    }*/
    /*int maxGreyLevelValue = 255;
    int pointsNb = cartCoords.size();

    std::vector<double> xPoints;
    std::vector<double> yPoints;
    std::vector<double> zPoints;

	for (int i = 0; i < pointsNb; i++)
    {
        xPoints.push_back(Coords[i].x);
        yPoints.push_back(Coords[i].y);
        zPoints.push_back(Coords[i].z);
    }

	std::vector<double>::iterator it = std::min_element(xPoints.begin(), xPoints.end());
	double  xMin = *it;
	it = std::max_element(xPoints.begin(), xPoints.end());
	double  xMax = *it;

	it = std::min_element(yPoints.begin(), yPoints.end());
	double  yMin = *it;
	it = std::max_element(yPoints.begin(), yPoints.end());
	double  yMax = *it;

	double width = yMax - yMin ;
	double height = xMax - xMin ;

    std::ofstream f("test.pgm",std::ios_base::out|std::ios_base::binary|std::ios_base::trunc);
                              
    f << "P5\n" << width << " " << height << "\n" << maxGreyLevelValue << "\n";
    char* lineGreyBuff = new char[width];
    imgPgm.write(reinterpret_cast<const char*>(lineGreyBuff), width);*/

    /*Map map(Coords);
    map.Triang_Del();
    double z;
    map.get_height(48.19517461, -3.028930672, z);
    std::cout << z << std::endl;*/




}  
//48.19517461 -3.028930672 -117.281