#pragma once 
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <array>

#include "proj.h"

/**
	* \class  Projection
	* \brief  Use  Proj library
	* \brief  Projects cloud point data from Lat long to WGS84.
    * \author  Badr Moutalib
    * \date  2021
 */

class Projection
{

private:
	std::string m_Coord_Path = ""; /**< String Path for cloude point file. */
	std::vector<PJ_XYZ> m_Coords;/**< Vector output for X Y Z Coordinates after transformation. */
	std::array<double, 3> m_long_lat;/**< Array Input for long lat coordinates used for testing the projection. */
	const char* m_proj_dbPath = "../lib/proj/share/proj/proj.db"; /**< Const char pointer for proj library data base path. */
	PJ_CONTEXT *C = NULL; /**< Proj Context pointer to configure the projection. */
    PJ *P = NULL; /**< Projection pointer. */
    
public:
	void updateContext();//!< Member function to update the Projection configuration.
	Projection(std::array<double, 3> long_lat);//!< Constructor with unique long lat and heign coordinates.
	Projection(std::string Coord_Path);//!< Constructor with Path file for Point cloud file.
	~Projection(); //!< Destructor.
	std::string get_file_path() const; //!< File path getter.
	std::vector<PJ_XYZ> get_coords() const; //!< Coordinates getter.
	void set_file_path(std::string Coord_Path); //!< File path setter.
	void Proj(); //!< Projection implementation.
};