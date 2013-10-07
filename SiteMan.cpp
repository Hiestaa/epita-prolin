///////////////////////////////////////////////////////////
//  SiteMan.cpp
//  Implementation of the Class SiteMan
//  Created on:      01-juil.-2013 11:13:45
//  Original author: Romain
///////////////////////////////////////////////////////////

#include "SiteMan.h"


SiteMan::SiteMan(){
	this->sites = new std::vector<Site*>();
}



SiteMan::~SiteMan(){
	for(std::vector<Site*>::size_type i = 0; i != sites->size(); i++) {
		delete sites->at(i);
	}
}





void SiteMan::add_site(Site* new_site){
	sites->push_back(new_site);
}

int SiteMan::parse(const char* filename){
	std::string line;
	std::ifstream input_file (filename);
	int line_count = 0;
	int ret = 0;

	// open file
	if (!input_file.is_open()) {
		return 1;
	}
	if (!getline(input_file, line)) {
		return 1;
	}

	line_count++;

	// parse first line (dimensions)
	std::vector<std::string> dim = split(line, ' ');
	this->nb_to_build = atoi(dim[1].c_str());
	std::cout << "Dimensions: " << dim[0] << ", " << this->nb_to_build << std::endl;

	// parse other lines (datas)
	while (getline(input_file, line)) {
		// got the line
		line_count++;
		// parse it
		std::vector<std::string> site_data = split(line, ' ');

		// check errors
		if (site_data.size() < 4) {
			std::cerr << "Syntax error on line " << line_count << ": only " 
					<< site_data.size() << " items on the line" << std::endl;
			ret = 1;
			continue;
		}
		else {
			std::cout << "New site ! Id=" << site_data[0]
				<< ", pos=(" << site_data[1] << "," << site_data[2]
				<< "), capacity=" << site_data[3] << std::endl;
		}


		this->sites->push_back(new Site(
			atoi(site_data[0].c_str()),
			atoi(site_data[1].c_str()),
			atoi(site_data[2].c_str()),
			atoi(site_data[3].c_str()),
			false));
	}

	return ret;
}


int* SiteMan::get_dist_map(int dist_max, int* dist_map) {
	//int * dist_map = new int[dist_max][dist_max];
	int dist = 0;
	Site* s1, s2;
	for (int i = 0; i < this->sites->size(); ++i) {	
		for (int j = 0; j < this->sites->size(); ++j)	{
			if (i == j) {
				dist_map[i][j] = -1;
			}
			else {
				s1 = get(i);
				s2 = get(j);

				if (sqdist(s1->pos_x, s1->pos_y, s2->pos_x, s2->pos_y) <= square(dist_max)) {
					dist_map[i][j] = 1;
				}
				else {
					dist_map[i][j] = 0;
				}
			}
		}
	}
	return dist_map;
}

Site* SiteMan::get(int pos) {
	return sites->at(pos);
}

int SiteMan::get_nb_to_build() {
	return nb_to_build;
}

int SiteMan::get_nb_sites() {
	return sites->size();
}
