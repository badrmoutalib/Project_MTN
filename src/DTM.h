#pragma once 
#include <stdio.h>
#include <iostream>
#include <vector>
#include "proj.h"

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Projection_traits_xy_3.h>
#include <CGAL/Point_set_3.h>
#include <CGAL/Point_set_3/IO.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Triangulation_vertex_base_with_info_2.h>
#include <CGAL/Triangulation_face_base_with_info_2.h>
#include <CGAL/Polygon_mesh_processing/locate.h>
#include <CGAL/Polygon_mesh_processing/triangulate_hole.h>
#include <CGAL/Polygon_mesh_processing/border.h>
#include <CGAL/Polygon_mesh_processing/remesh.h> 
#include "Color_ramp.h"
#include <fstream>
#include <queue>

using Kernel = CGAL::Exact_predicates_inexact_constructions_kernel;
using Projection_traits = CGAL::Projection_traits_xy_3<Kernel>;
using Point_2 = Kernel::Point_2;
using Point_3 = Kernel::Point_3;
using Segment_3 = Kernel::Segment_3;
using TIN = CGAL::Delaunay_triangulation_2<Projection_traits>;

typedef Kernel::Point_3 Point;
/**
	* \ class  DTM
	* \ use  CGAL library
	* \ brief  triangulates the coordinates and creates a dtm object and then creates raster.
    * \ author  Badr Moutalib
    * \ date  2021
 */
class DTM
{

private:
	
	std::size_t m_width = 1920;/**< width set to default 1920. */
	CGAL::Point_set_3<Point_3> points;/**< x y z structure specific to CGAL lib. */
	std::vector<PJ_XYZ> *m_Coords;/**< brief x y z structure specific to Proj lib. */

public:

	DTM(std::vector<PJ_XYZ> *Coords); //!< Constructor Digital terrain Map param Coords PJ_XYZ vector pointer.
	void point_set(); //!< coords point setter in CGAL point_3 data structure.
	void set_width(double width); //!< Width setter.
	void create_raster();//!< Member function creates raster image in PPM file format.
};


	
