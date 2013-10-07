///////////////////////////////////////////////////////////
//  Site.cpp
//  Implementation of the Class Site
//  Created on:      01-juil.-2013 11:13:45
//  Original author: Romain
///////////////////////////////////////////////////////////

#include "Site.h"


Site::Site(){

}

Site::Site(int sid, int x, int y, int c, bool bo) {
  this->id = sid;
  this->pos_x = x;
  this->pos_y = y;
  this->cap = c;
  this->boo = bo;
}

Site::~Site(){

}
