///////////////////////////////////////////////////////////
//  Program.cpp
//  Implementation of the Class Program
//  Created on:      01-juil.-2013 11:13:44
//  Original author: Romain
///////////////////////////////////////////////////////////

#include "Program.h"


Program::Program(){

}



Program::~Program(){

}





int Program::build(SiteMan* sites){
	std::cerr << "Not impletented yet" << std::endl;
	return 2; // mettre 0 apres l'implementation ! (2 indique une erreur)
}


std::string Program::solve(){
 /*partie solve*/

  /* solve problem */
  glp_simplex(lp, NULL);
  /* recover and display results */
  z = glp_get_obj_val(lp);

  i = 0;
  int x[m];
  while (i < m + 1)
  {
     x[i] = glp_get_col_prim(lp, i);
     i++;
  }
  i = 0;
  while (i < m + 1)
  {
        printf("x = %g;\n”, x[i]);
  }
 
 /* housekeeping */

  glp_delete_prob(lp);
  glp_free_env();
  return 0;
}
	
