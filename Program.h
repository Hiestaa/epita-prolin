///////////////////////////////////////////////////////////
//  Program.h
//  Implementation of the Class Program
//  Created on:      01-juil.-2013 11:13:44
//  Original author: Romain
///////////////////////////////////////////////////////////

#if !defined(EA_B9ACFDE7_CB62_468a_AB77_44879545335D__INCLUDED_)
#define EA_B9ACFDE7_CB62_468a_AB77_44879545335D__INCLUDED_

#include "SiteMan.h"

class Program
{

public:
	Program();
	virtual ~Program();
	SiteMan *m_SiteMan;

	void build(SiteMan sites);
	string solve();

private:
	prob;

};
#endif // !defined(EA_B9ACFDE7_CB62_468a_AB77_44879545335D__INCLUDED_)
