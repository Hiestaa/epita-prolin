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

	// accessors
	Site* get(int pos);
	int get_nb_to_build();

private:
	std::vector<Site*> *sites;
	int nb_to_build;

};
#endif // !defined(EA_C5369476_B7A3_49b0_B937_88A854B9A4C8__INCLUDED_)
