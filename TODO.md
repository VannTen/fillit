
Parser :
Creer un tableau/ une liste pour stocker l'ensemble des pieces tetris possible
On compare ensuite chacune des pieces entrees avec cette liste afin de determiner les pieces entrees

Possibilite de d'eliminer certaines tuiles au fur et a mesure.
>> Trier le tableau pour faciliter la comparaison.

Stockage des pieces : tableau de t_bool(2 dimensions) (1 pour une case pleine, 0 pour une case vide)
Tableau insere dans une liste (encapsule dans une structure avec l'ordre d'entree (lettre pour la sortie)

Validation de l'entree

format du parser
t_list *list_pieces_tetris(char *entre_du_programme);


Solver :

Creation d'une grille resultat en fonciton du nombre de pieces (n*4) prendre large, eventuellement a ajuster.

Condition d'arret : si on a 5 pieces, on a en tout 20 tuiles. 
Donc si on arrive a une solution avec un carre de 5 pieces de cotes (soit 25 pieces) on a trouve la solution optimum (vu au'un carre de $ fait 16)
Ou si epuisement de toutes les solutions.

Si l'entre contient des pieces identiques successives >> un seul test suffit.

Pour le test recursif :
Associer a chaque type de piece un mouvement

Procedure :
 Remplir en fonction du mouvement
 Appel recursif/iteratif possibilites decoulantes
 Effacer en fonction du mouvement.

Suggestion d'opti :
des que la solution depasse l'optimale, stocker la possibilite et ne pas l'explorer.
Y revenir une fois qu'aucune solution opti n'a ete trouve
Exemple :
Si le meilleur est 6 de cote, des qu'un arbre de possibilites depasse six, on stoppe l'exploration et on stock l'etape dans une liste (liste 7)
si aucune possibilite a 6 n'est trouve, on explore toute la liste des possbilites a 7, en excluant les 8, et ainsi de suite.


 Affichage :

 En fonction de la solution trouve, limiter l'affichage de la grille resultat (a la taille du carre);
 

 Gestion d'erreur :
 Parser l'ensemble de l'entree piece (au cas ou sont rajoutes d'autres caracteres)
Verifier les caracteres autorises.
Affichage de l'usage.

