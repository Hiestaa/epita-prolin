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
	
glp_prob *lp;
int ia[1+1000], ja[1+1000];
double ar[1+1000];
//j'ai rajouter des booléens aux sites
//parti init du problème
//Ci est fixe
//dij aussi
//n et m aussi
//seulement a declarer les booleens Bi = choix ou non du truc
//les sites ils ont eux meme des booléens mnt
lp = glp_create_prob();
glp_set_prob_name(lp, "sample");
glp_set_obj_dir(lp, GLP_MAX);

//debut de la creation de l'equation de contrainte x1 + x2 + x3 = m
//je l ai fait comme cela car c etait dans cet ordre la dans les exemples
 glp_set_row_name(lp, 1, "m");
 glp_set_row_bnds(lp, 1, GLP_UP, 0.0, 100.0);

 //equation de maximise
//fonction maximiser
//B1*C1 + ... Bn*Cn 

//attribution de x1 x2 avec ces coeffs dans la fonction maximise
glp_set_col_name(lp, 1, "x1");
glp_set_col_bnds(lp, 1, GLP_LO, 0.0, 0.0);
glp_set_obj_coef(lp, 1, 10.0);
glp_set_col_name(lp, 2, "x2");
glp_set_col_bnds(lp, 2, GLP_LO, 0.0, 0.0);
glp_set_obj_coef(lp, 2, 6.0);


//equation de contrainte representer de maniere matricielle Mij, i represente les lignes et j les colonnes r etant la valeur
// nous on a deux equation de contrainte
//1er equation :(B1 + ... Bn) = m qui correspond a 
//tant que la liste des sites man n est pas nuls placer les coeffs Ci devant les xi, manque l'attribution des coefficient Ci
i = 0;
while (i < n)
{
 ia[1] = 1, ja[i] = 1, ar[1] = 1;   
 //coeff i
i++;
}

//2eme equation : 
//dij(Bi + Bj) <=1 si i diff de j
//dij = sqrt((xi-xj)^2+(yi-yj)^2)





        //finir la fonction et connecter solve avec le reste
	//fonction distance a faire + tard
	//surement getter et setter des sites à mettre en place
	//faire passer le pl  ensuite au main ou du mons le connecter à solve

	return 0; 
}


std::string Program::solve(){
 /*partie solve*/
  //ici va juste falloir donner le lp
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
        printf("x = %g;\n", x[i]);
  }
 
 /* housekeeping */

  glp_delete_prob(lp);
  glp_free_env();
  return 0;
}
	
