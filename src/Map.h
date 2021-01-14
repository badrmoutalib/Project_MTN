#pragma once 
#include <stdio.h>
#include <iostream>
#include <vector>
#include <delaunator.hpp>
#include "proj.h"
//#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Projection_traits_xy_3.h>
#include <CGAL/Point_set_3.h>
#include <CGAL/Point_set_3/IO.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Triangulation_vertex_base_with_info_2.h>
#include <CGAL/Triangulation_face_base_with_info_2.h>

#include <fstream>
#include <queue>
using Kernel = CGAL::Exact_predicates_inexact_constructions_kernel;
using Projection_traits = CGAL::Projection_traits_xy_3<Kernel>;
using Point_2 = Kernel::Point_2;
using Point_3 = Kernel::Point_3;
using Segment_3 = Kernel::Segment_3;
// Triangulated Irregular Network
using TIN = CGAL::Delaunay_triangulation_2<Projection_traits>;



class DTM
{

private:
	CGAL::Point_set_3<Point_3> points;
	std::vector<PJ_XYZ> m_Coords;


public:
	Map()
};


	
