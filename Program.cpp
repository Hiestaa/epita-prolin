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
  int ia[1+1000], ja[1+1000];
  double ar[1+1000];
  int n = sites->get_nb_sites();
  int m = sites->get_nb_to_build();
  int d[1000][1000];
  std::cout << "Calculating distance matrix" << std::endl;
  sites->get_dist_mat(50, d);
  std::cout << "Creating linear problem" << std::endl;
  //j'ai rajouter des booléens aux sites
  //parti init du problème
  //Ci est fixe
  //dij aussi
  //n et m aussi
  //seulement a declarer les booleens Bi = choix ou non du truc
  //les sites ils ont eux meme des booléens mnt
  lp = glp_create_prob();
  glp_set_prob_name(lp, "PLAM");
  glp_set_obj_dir(lp, GLP_MAX);

  int nbrows = (square(n)-n)/2 + n;

  //debut de la creation de l'equation de contrainte x1 + x2 + x3 = m
  //je l ai fait comme cela car c etait dans cet ordre la dans les exemples
  std::cout << "Nb rows: " << ((square(n)-n)/2 + 1) << std::endl;
  glp_add_rows(lp, nbrows);
  //attribution de x1 x2 avec ces coeffs dans la fonction maximise

  //faudra faire passer m dans la fonction
  glp_set_row_name(lp, 1, "nbentrepots");
  glp_set_row_bnds(lp, 1, GLP_DB, 0.0, m - 1);

  int x = 2;
  while (x < nbrows)
  {
    glp_set_row_name(lp, x, num2str(x).c_str());
    glp_set_row_bnds(lp, x, GLP_DB, 0.0, 100);
    x++;
  }
  //equation de maximise
  //fonction maximiser
  //B1*C1 + ... Bn*Cn 

  glp_add_cols(lp, n);


  int j = 1;
  while(j < n)
  {
	 //strcat correct coeff a changer
    glp_set_col_name(lp, j, num2str(j).c_str());
    //glp_set_col_kind(lp, j, GLP_BV);
    glp_set_col_bnds(lp, j, GLP_DB, 0.0, 1.0);
    glp_set_col_kind(lp, j, GLP_IV);
    glp_set_obj_coef(lp, j, sites->get(j)->cap);
    j++;
  }


  //equation de contrainte representer de maniere matricielle Mij, i represente les lignes et j les colonnes r etant la valeur
  // nous on a deux equation de contrainte
  //1er equation :(B1 + ... Bn) = m qui correspond a 
  //tant que la liste des sites man n est pas nuls placer les coeffs Ci devant les xi, manque l'attribution des coefficient Ci
  int i = 1;
  int h = 1;
  while (i < n)
  {
    ia[h] = 1, ja[h] = i, ar[h] = 1;   
    //coeff i
    i++;
    h++;
  }

  //2eme equation : 
  //dij(Bi + Bj) <=1 si i diff de j
  //dij = sqrt((xi-xj)^2+(yi-yj)^2)
int tmp = h;
int range = 2;
 int mem = 0;
  for (int ptr = 1; ptr < n; ptr++) {
      for (i = ptr; i <= n; i++) {
          for (j = 1; j <= n; j++) {
              
              ia[tmp] = range, ja[tmp] = j;
              
              if (j < ptr)
                  ar[tmp] = 0;
              else if (j == ptr)
                  mem = tmp;
              else if (j == i + ptr) {
                  ar[tmp] = d[ptr][i];
                  ar[mem] = d[ptr][i];
                  mem = 0;
              }
              else
                  ar[tmp] = 0;
              tmp++;
          }
          range++;
      }
  }

  //tot = nombre de rencontre entre i et j dans un paquets de n ou i et j sont differents
  // int y = 2;
  // int z = h;
  // for (int i = 1; i < n; i++)
  // {
  //   for (int j = 1; j < i; j++)
  //   {
  //     // dij(Bi + Bj) <=1 donc rajouter le <= 1
  //     if (i != j)
  //     {
  //       ia[z] = y, ja[z] = 1, ar[z] = d[i][j];
  //       z++;
  //       ia[z] = y, ja[z] = 2, ar[z] = d[i][j];
  //       //coeff ar[]  a changer ici dij
  //       z++;
  //     }
  //   }
  //   y++;
  // }
	//ligne a modif apres
	glp_load_matrix(lp, tmp - 1, ia, ja, ar);
  //finir la fonction et connecter solve avec le reste
	//fonction distance a faire + tard
	//surement getter et setter des sites à mettre en place
	//faire passer le pl  ensuite au main ou du mons le connecter à solve

	return 0; 
}


std::string Program::solve(int m, SiteMan* sites){
 /*partie solve*/
  /* solve problem */
  glp_simplex(lp, NULL);
  glp_intopt(lp, NULL);
  /* recover and display results */
  double z;
  z = glp_get_obj_val(lp);


  int i = 1;
  int res = 0;
  int total = 0;
  while (i < m + 1)
  {
    if (glp_mip_col_val(lp, i) > 0) {
      total += sites->get(i)->cap;
      res = 1;
    }
    else
      res = 0;
    std::cout << "x" << i << " = " << res << std::endl;
    i++;
  }

  std::cout << "Total storage: " << total << std::endl;
  std::cout << "Now freeing memory" << std::endl;
 
 /* housekeeping */

  glp_delete_prob(lp);
  glp_free_env();
  return 0;
}
	
