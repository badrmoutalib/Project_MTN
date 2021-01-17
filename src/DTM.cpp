#include "DTM.h"

DTM::DTM(std::vector<PJ_XYZ> *Coords)
{
	m_Coords = Coords;
}


void DTM::point_set()
{
	for(std::vector<PJ_XYZ>::iterator it = m_Coords->begin(); it != m_Coords->end() ; ++it)
    {
    	points.insert(Point(it->x, it->y, it->z));
    }
    
}
/**brief Set width
*/
void DTM::set_width(double width)
{
	m_width = width;
}


void DTM::create_raster()
{											
	/** brief Create DSM using Triangulated Irregular Network Data structure
	*/
	TIN dtm(points.points().begin(), points.points().end());
	/**brief Create 3-dimensional bounding-box 
	*/
	CGAL::Bbox_3 bbox = CGAL::bbox_3(points.points().begin(), points.points().end());
	/** brief Generate raster image
	*/ 
	std::size_t height = std::size_t((bbox.ymax() - bbox.ymin()) * m_width / (bbox.xmax() - bbox.xmin()));
	std::cerr << "Rastering with resolution " << m_width << "x" << height << std::endl;
	/** brief Use PPM format (Portable PixMap) 
	*/
	std::ofstream raster_ofile("raster.ppm", std::ios_base::binary);
	/** brief PPM header
	*/
	raster_ofile << "P6" << std::endl << m_width << " " << height << std::endl << 255 << std::endl;
	/** brief Use rainbow color ramp output
	*/
	Color_ramp color_ramp;
	/** brief Keeping track of location from one point to its neighbor allows
	*\ for fast locate in DT
	*/
	
	TIN::Face_handle location;
	/** brief Query each pixel of the image
	*/
	for (std::size_t y = 0; y < height; ++ y)
	    for (std::size_t x = 0; x < m_width; ++ x)
	    {
			Point_3 query (bbox.xmin() + x * (bbox.xmax() - bbox.xmin()) / double(m_width),
			             bbox.ymin() + (height-y) * (bbox.ymax() - bbox.ymin()) / double(height),
			             0); 
			location = dtm.locate(query, location);
			/** brief Points outside the convex hull will be colored black
			*/
			std::array<unsigned char, 3> colors { 0, 0, 0 };
			if (!dtm.is_infinite(location))
			{
				std::array<double, 3> barycentric_coordinates
				  = CGAL::Polygon_mesh_processing::barycentric_coordinates
				  (Point_2 (location->vertex(0)->point().x(), location->vertex(0)->point().y()),
				   Point_2 (location->vertex(1)->point().x(), location->vertex(1)->point().y()),
				   Point_2 (location->vertex(2)->point().x(), location->vertex(2)->point().y()),
				   Point_2 (query.x(), query.y()),
				   Kernel());
				double height_at_query
				  = (barycentric_coordinates[0] * location->vertex(0)->point().z()
				     + barycentric_coordinates[1] * location->vertex(1)->point().z()
				     + barycentric_coordinates[2] * location->vertex(2)->point().z());
				/** brief Color ramp generates a color depending on a value from 0 to 1
				*/
				double height_ratio = (height_at_query - bbox.zmin()) / (bbox.zmax() - bbox.zmin());
				colors = color_ramp.get(height_ratio);
			}
			raster_ofile.write ((char*)(&colors), 3);
	    }
	raster_ofile.close();
}
