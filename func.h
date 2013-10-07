
///////////////////////////////////////////////////////////
//  func.h
//  Implementation of some usefull functions
//  Created on:      01-juil.-2013 11:13:45
//  Original author: Romain
///////////////////////////////////////////////////////////

#if !defined(__FUNC__INCLUDED_)
#define __FUNC__INCLUDED_

# include <vector>
# include <string>
# include <sstream>

//std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);
int square(int n);
int sqdist(int x1, int y1, int x2, int y2);

#endif // !defined(__FUNC__INCLUDED_)
