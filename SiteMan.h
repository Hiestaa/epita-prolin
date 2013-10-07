///////////////////////////////////////////////////////////
//  SiteMan.h
//  Implementation of the Class SiteMan
//  Created on:      01-juil.-2013 11:13:45
//  Original author: Romain
///////////////////////////////////////////////////////////

#if !defined(EA_C5369476_B7A3_49b0_B937_88A854B9A4C8__INCLUDED_)
#define EA_C5369476_B7A3_49b0_B937_88A854B9A4C8__INCLUDED_

# include <vector>
# include <fstream>
# include <iostream>
# include <stdlib.h>     /* atoi */
# include "Site.h"
# include "func.h"

class SiteMan
{

public:
	SiteMan();
	virtual ~SiteMan();

	void add_site(Site* new_site);
	int parse(const char* filename);
	// retourne une matrice telle que 
	// pour tout site i et j, mat[i][j] == 1 si dist(i, j) < dist_max, 0 sinon.
	//   note : si i == j, dist[i][j] == -1
	int* get_dist_mat(int dist_max);

	// accessors
	Site* get(int pos);
	int get_nb_to_build();

private:
	std::vector<Site*> *sites;
	int nb_to_build;

};
#endif // !defined(EA_C5369476_B7A3_49b0_B937_88A854B9A4C8__INCLUDED_)
