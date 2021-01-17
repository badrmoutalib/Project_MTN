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

Projection::Projection(std::array<double, 3> long_lat): m_long_lat{long_lat}
{

}


void Projection::updateContext()
{
	/** brief create projection context
	*\  Sets database path and then create transformation object with proj_create_crs_to_crs(Context, source coordinates system, target coordinate system, Options)
	*/
	C = proj_context_create();
	proj_context_set_database_path(C, m_proj_dbPath, NULL, NULL);
    P = proj_create_crs_to_crs(C, "+proj=longlat +datum=WGS84 +no_defs", /*"+proj=lcc +lon_0=-90 +lat_1=33 +lat_2=45"*/"+proj=lcc +lat_1=49 +lat_2=44 +lat_0=46.5 +lon_0=3 +x_0=700000 +y_0=6600000 +ellps=GRS80 +towgs84=0,0,0,0,0,0,0 +units=m +no_defs", NULL);    
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
	/** brief If projection constructed with file path 
	*/
	double lat, lng, elev;
	if(m_Coord_Path != "")
	{
		/** brief Get long lat and elev coordinates from every line 
		*\  add themro proj_coord(lat,long,elev,time) #proj member function
		*\  add the projection coordinates to proj_trans(Projection, Projection_forward, Projection coordinates)
		*\  add the transformed coordinates to the coordinate vector m_Coords.
		*/
		std::ifstream ifst(m_Coord_Path);

		while(!ifst.eof())
		{
			ifst >> lat >> lng >> elev;
			PJ_COORD a = proj_coord(lat,lng,elev,0);
			PJ_COORD b = proj_trans(P,PJ_FWD,a);
			m_Coords.push_back(b.xyz);
		}

		ifst.close();
	}
	/** brief If projection constructed with unique long lat coordinates
	*/
	else
	{
		PJ_COORD a = proj_coord(m_long_lat[0],m_long_lat[1],m_long_lat[2],0);
		PJ_COORD b = proj_trans(P,PJ_FWD,a);
		m_Coords.push_back(b.xyz);
	}
	proj_destroy (P);
    proj_context_destroy (C);

}