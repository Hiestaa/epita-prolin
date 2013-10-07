///////////////////////////////////////////////////////////
//  Site.h
//  Implementation of the Class Site
//  Created on:      01-juil.-2013 11:13:44
//  Original author: Romain
///////////////////////////////////////////////////////////

#if !defined(EA_94B94CD5_08E7_4045_8E55_5968CCCE1B44__INCLUDED_)
#define EA_94B94CD5_08E7_4045_8E55_5968CCCE1B44__INCLUDED_


class Site
{

public:
	Site();
	Site(int sid, int x, int y, int c, bool bo);
	virtual ~Site();
	int cap;
	int id;
	int pos_x;
	int pos_y;
        bool boo;
};
#endif // !defined(EA_94B94CD5_08E7_4045_8E55_5968CCCE1B44__INCLUDED_)
