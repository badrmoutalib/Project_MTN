#include <fstream>
#include "proj.h"
#include "Projection.h"

Projection::Projection(std::string Coord_Path): m_Coord_Path{Coord_Path}
{
	updateContext();
}

Projection::~Projection()
{
	
}

void Projection::updateContext()
{
	C = proj_context_create();
	proj_context_set_database_path(C, m_proj_dbPath, NULL, NULL);
    P = proj_create_crs_to_crs(C, "+proj=longlat +datum=WGS84 +no_defs", "+proj=lcc +lat_1=49 +lat_2=44 +lat_0=46.5 +lon_0=3 +x_0=700000 +y_0=6600000 +ellps=GRS80 +towgs84=0,0,0,0,0,0,0 +units=m +no_defs", NULL);    
    P = proj_normalize_for_visualization(C, P);
}

std::string Projection::get_file_path() const
{
	return  m_Coord_Path ;
}

std::vector<PJ_XYZ> Projection::get_coords() const
{
	return m_Coords;
}

void Projection::set_file_path(std::string Coord_Path)
{
	m_Coord_Path = Coord_Path;
}

void Projection::Proj()
{
	double lat, lng, elev;
	std::ifstream ifst(m_Coord_Path);

	while(!ifst.eof())
	{
		ifst >> lat >> lng >> elev;
		PJ_COORD a = proj_coord(lat,lng,elev,0);
		PJ_COORD b = proj_trans(P,PJ_FWD,a);
		m_Coords.push_back(b.xyz);
	}

	ifst.close();
	proj_destroy (P);
    proj_context_destroy (C);
}