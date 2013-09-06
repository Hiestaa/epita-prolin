///////////////////////////////////////////////////////////
//  SiteMan.h
//  Implementation of the Class SiteMan
//  Created on:      01-juil.-2013 11:13:45
//  Original author: Romain
///////////////////////////////////////////////////////////

#if !defined(EA_C5369476_B7A3_49b0_B937_88A854B9A4C8__INCLUDED_)
#define EA_C5369476_B7A3_49b0_B937_88A854B9A4C8__INCLUDED_

class SiteMan
{

public:
	SiteMan();
	virtual ~SiteMan();

	void add_site(Site* new_site);

private:
	List<Site>* sites;

};
#endif // !defined(EA_C5369476_B7A3_49b0_B937_88A854B9A4C8__INCLUDED_)
