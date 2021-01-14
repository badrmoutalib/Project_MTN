#pragma once 
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "proj.h"

/**
	* \ class  Projection
	* \ Use  Proj library
	* \ brief  Projects cloud point data from WGS to cartesian.
    * \ author  Badr Moutalib
    * \ date  2021
 */

class Projection
{

private:
	std::string m_Coord_Path = "";
	std::vector<PJ_XYZ> m_Coords;
	const char* m_proj_dbPath = "../lib/proj/share/proj/proj.db"; 
	PJ_CONTEXT *C = NULL;
    PJ *P = NULL;
    
public:
	void updateContext();
	Projection(std::string Coord_Path);
	~Projection();
	std::string get_file_path() const;
	std::vector<PJ_XYZ> get_coords() const;
	void set_file_path(std::string Coord_Path);
	void Proj();
};