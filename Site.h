///////////////////////////////////////////////////////////
//  Site.h
//  Implementation of the Class Site
//  Created on:      01-juil.-2013 11:13:44
//  Original author: Romain
///////////////////////////////////////////////////////////

#if !defined(EA_94B94CD5_08E7_4045_8E55_5968CCCE1B44__INCLUDED_)
#define EA_94B94CD5_08E7_4045_8E55_5968CCCE1B44__INCLUDED_

#include "SiteMan.h"

class Site
{

public:
	Site();
	virtual ~Site();
	int cap;
	int id;
	int pos_x;
	int pos_y;
	SiteMan *m_SiteMan;

};
#endif // !defined(EA_94B94CD5_08E7_4045_8E55_5968CCCE1B44__INCLUDED_)
