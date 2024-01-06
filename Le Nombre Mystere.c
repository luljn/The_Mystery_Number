#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>



void AfficherMenu();
void ModeDemploie();
void AfficherMode();
void AfficherDiff();
void Aide1();
void Aide2();



const int MAX1 = 100, MAX2 = 1000, MAX3 = 10000, MIN1 = 1, MIN2 = 101, MIN3 = 1001;
int nombreMystere = 0, nombre = 0 /* le nombre que le joueur entre en mode 1 joueur*/, coupsRestant = 10 /* compteur de coups mode 1 joueur*/, choix = 0, choixMode = 0, choixDiff = 0;
int nombreMystere2 = 0, nombreMystere3 = 0, coup1 = 20 /* compteur de coups mode 1 joueur* (difficile) */, coup2 = 30; /* compteur de coups mode 1 joueur (très difficile) */
int nm1 = 0, nm2 = 0; // les nombres mystères que les 02 jouers vont entrer en mode 2 joueurs.
int num1 = 0, num2 = 0; // Les nombres que les 02 joueurs vont entrer à tour de rôle.
int cp1 = 10, cp2 = 10; // les compteurs de coups en mode 02 joueurs (facile)
int cpd1 = 20, cpd2 = 20; // les compteurs de coups en mode 02 joueurs (difficile)
int cpt1 = 30, cpt2 = 30; // les compteurs de coups en mode 02 joueurs (très difficlie)



int main(){

	system("title Le Nombre Mystère");

	srand(time(NULL)); // On initialise le générateur de nombre aléatoire.
	nombreMystere = (rand() % (MAX1 - MIN1 + 1)) + MIN1; // On génère un nombre aléatoire compris entre 1 et 100.
	                                                     // On peut utiliser aussi "rand() % 100 + 1 ;"

	nombreMystere2 = (rand() % (MAX2 - MIN2 + 1)) + MIN2;

	nombreMystere3 = (rand() % (MAX3 - MIN3 + 1)) + MIN3;

	system("color 09");
	AfficherMenu();
	printf("\n\n\n\t\t\t\t\tVotre Choix : ");
	scanf("%d", &choix);

	if(choix == 2){

		ModeDemploie();
		system("cls");
		main();
	}

	if(choix == 3){

		system("cls");
		printf("\n\n\n\n\n\t\t\t\t\tFin du jeu.\n\n\n");
		exit(EXIT_SUCCESS);
		return 0;
	}

	if(choix < 1 || choix > 3){

		system("cls");
		printf("\n\n\n\t\t\t\t\tChoix non disponible :( !\n\n\t\t\t");
		system("pause");
		system("cls");
		main();
	}

	system("cls");
	sleep(0.5);

	AfficherMode();
	printf("\n\n\n\t\t\t\t\tVotre Choix : ");
	scanf("%d", &choixMode);

	if(choixMode == 3){

		Aide1();
		system("cls");
		main();
	}

	if(choixMode < 1 || choixMode > 3){

		system("cls");
		printf("\n\n\n\t\t\t\t\tChoix non disponible :( !\n\n\t\t\t");
		system("pause");
		system("cls");
		main();
	}

	system("cls");
	sleep(0.5);

	AfficherDiff();
	printf("\n\n\n\t\t\t\t\tVotre Choix : ");
	scanf("%d", &choixDiff);

	if(choixDiff == 4){

		Aide2();
		system("cls");
		main();
	}

	if(choixDiff < 1 || choixDiff > 4){

		system("cls");
		printf("\n\n\n\t\t\t\t\tChoix non disponible :( !\n\n\t\t\t");
		system("pause");
		system("cls");
		main();
	}


	system("cls");



// On gère le MODE 1 joueur.
	// Niveau Facile
	if(choixMode == 1 && choixDiff == 1 && choix == 1){

		printf("\n\t\t\t\t\"Le nombre mystere se trouve entre %d et %d.\"", MIN1, MAX1);

		do{

			system("color 09");
			printf("\n\n\t\t\t\t\tIl vous reste %d coup(s).", coupsRestant);
			printf("\n\t\t\t\t\tQuel est le nombre Mystere ?");
			printf("\n\t\t\t\t\tProposez un nombre : ");
			scanf("%d", &nombre);

			if(nombre > nombreMystere){

				system("color 0c");
				printf("\n\t\t\t\t\tC'est moins !\n");
				printf("\n\t\t\t\t\t");
				system("pause");
			}

			else if(nombre < nombreMystere){

				system("color 0c");
				printf("\n\t\t\t\t\tC'est plus !\n");
				printf("\n\t\t\t\t\t");
				system("pause");
			}

			coupsRestant--;

		}while(nombre != nombreMystere && coupsRestant > 0);

		if(nombre == nombreMystere){

			system("cls");
			printf("\n\n\n\t\t\t\t\tBravo :) , le nombre mystere est bien \"%d\".\n\n", nombreMystere);
			printf("\n\n\n\t\t\t\t\tFin du jeu.\n\n\n");
			printf("\n\n\n\t\t\t\t");
			system("pause");
		}

		if(coupsRestant == 0 && nombre != nombreMystere){

			system("cls");
			printf("\n\n\n\t\t\t\t\tVous n'avez pas pu trouver le nombre mystere :( !\n\n");
			printf("\n\n\n\t\t\t\t\tFin du jeu.\n\n\n");
			printf("\n\n\n\t\t\t\t");
			system("pause");
		}
	}

	// Niveau Difficile
	if(choixMode == 1 && choixDiff == 2 && choix == 1){

		printf("\n\t\t\t\t\"Le nombre mystere se trouve entre %d et %d.\"", MIN2, MAX2);

		do{

			system("color 09");
			printf("\n\n\t\t\t\t\tIl vous reste %d coup(s).", coup1);
			printf("\n\t\t\t\t\tQuel est le nombre Mystere ?");
			printf("\n\t\t\t\t\tProposez un nombre : ");
			scanf("%d", &nombre);

			if(nombre > nombreMystere2){

				system("color 0c");
				printf("\n\t\t\t\t\tC'est moins !\n");
				printf("\n\t\t\t\t\t");
				system("pause");
			}

			else if(nombre < nombreMystere2){

				system("color 0c");
				printf("\n\t\t\t\t\tC'est plus !\n");
				printf("\n\t\t\t\t\t");
				system("pause");
			}

			coup1--;

		}while(nombre != nombreMystere2 && coup1 > 0);

		if(nombre == nombreMystere2){

			system("cls");
			printf("\n\n\n\t\t\t\t\tBravo :) , le nombre mystere est bien \"%d\".\n\n", nombreMystere2);
			printf("\n\n\n\t\t\t\t\tFin du jeu.\n\n\n");
			printf("\n\n\n\t\t\t\t");
			system("pause");
		}

		if(coup1 == 0 && nombre != nombreMystere2){

			system("cls");
			printf("\n\n\n\t\t\t\t\tVous n'avez pas pu trouver le nombre mystere :( !\n\n");
			printf("\n\n\n\t\t\t\t\tFin du jeu.\n\n\n");
			printf("\n\n\n\t\t\t\t");
			system("pause");
		}
	}

	// Niveau Très Difficile
	if(choixMode == 1 && choixDiff == 3 && choix == 1){

		printf("\n\t\t\t\t\"Le nombre mystere se trouve entre %d et %d.\"", MIN3, MAX3);

		do{

			system("color 09");
			printf("\n\n\t\t\t\t\tIl vous reste %d coup(s).", coup2);
			printf("\n\t\t\t\t\tQuel est le nombre Mystere ?");
			printf("\n\t\t\t\t\tProposez un nombre : ");
			scanf("%d", &nombre);

			if(nombre > nombreMystere3){

				system("color 0c");
				printf("\n\t\t\t\t\tC'est moins !\n");
				printf("\n\t\t\t\t\t");
				system("pause");
			}

			else if(nombre < nombreMystere3){

				system("color 0c");
				printf("\n\t\t\t\t\tC'est plus !\n");
				printf("\n\t\t\t\t\t");
				system("pause");
			}

			coup2--;

		}while(nombre != nombreMystere3 && coup2 > 0);

		if(nombre == nombreMystere3){

			system("cls");
			printf("\n\n\n\t\t\t\t\tBravo :) , le nombre mystere est bien \"%d\".\n\n", nombreMystere3);
			printf("\n\n\n\t\t\t\t\tFin du jeu.\n\n\n");
			printf("\n\n\n\t\t\t\t");
			system("pause");
		}

		if(coup2 == 0 && nombre != nombreMystere3){

			system("cls");
			printf("\n\n\n\t\t\t\t\tVous n'avez pas pu trouver le nombre mystere :( !\n\n");
			printf("\n\n\n\t\t\t\t\tFin du jeu.\n\n\n");
			printf("\n\n\n\t\t\t\t");
			system("pause");
		}
	}
// Fin instructions du MODE 1 joueur

// On gère le mode 2 joueurs
	// Niveau Facile
	if(choixMode == 2 && choixDiff == 1 && choix == 1){

		printf("\n\n\t\t\t\t\tLe nombre doit etre compris entre 0 et 100");
		printf("\n\n\t\t\t\t\tJoueur 1, entrez le nombre mystere du Joueur 2 :");
		scanf("%d", &nm2);
		sleep(1);
		system("cls");
		system("color 0c");
		printf("\n\n\t\t\t\t\tLe nombre doit etre compris entre 0 et 100");
		printf("\n\n\t\t\t\t\tJoueur 2, entrez le nombre mystere du Joueur 1 :");
		scanf("%d", &nm1);


		do{

			system("cls");
			system("color 09");
			// Le joueur 1 joue
			printf("\n\n\t\t\t\t\tJoueur 1:\n");
			printf("\n\n\t\t\t\t\tIl vous reste %d coup(s).", cp1);
			printf("\n\t\t\t\t\tQuel est le nombre Mystere ?");
			printf("\n\t\t\t\t\tProposez un nombre : ");
			scanf("%d", &num1);

			if(num1 > nm1){

				printf("\n\t\t\t\t\tC'est moins !\n");
				printf("\n\t\t\t\t\t");
				system("pause");
			}

			else if(num1 < nm1){

				printf("\n\t\t\t\t\tC'est plus !\n");
				printf("\n\t\t\t\t\t");
				system("pause");
			}

			cp1--;

			system("cls");
			// Le joueur 2 joue
			system("color 0c");
			printf("\n\n\t\t\t\t\tJoueur 2:\n");
			printf("\n\n\t\t\t\t\tIl vous reste %d coup(s).", cp2);
			printf("\n\t\t\t\t\tQuel est le nombre Mystere ?");
			printf("\n\t\t\t\t\tProposez un nombre : ");
			scanf("%d", &num2);

			if(num2 > nm2){

				printf("\n\t\t\t\t\tC'est moins !\n");
				printf("\n\t\t\t\t\t");
				system("pause");
			}

			else if(num2 < nm2){

				printf("\n\t\t\t\t\tC'est plus !\n");
				printf("\n\t\t\t\t\t");
				system("pause");
			}

			cp2--;

	    }while((num1 != nm1 && cp1 > 0) && (num2 != nm2 && cp2 > 0));

		// On teste si le joueur 1 a trouvé son nombre mystère
		if(num1 == nm1){

		    system("cls");
		    system("color 09");
			printf("\n\n\n\t\t\t\t\tBravo :) , le nombre mystere est bien \"%d\".\n\n", nm1);
			printf("\n\n\n\t\t\t\t\tLe vainqueur est le Joueur 1.\n\n");
			printf("\n\n\n\t\t\t\t\tFin du jeu.\n\n\n");
			printf("\n\n\n\t\t\t\t");
			system("pause");
		}

		if(cp1 == 0 && num1 != nm1){

			system("cls");
			system("color 09");
			printf("\n\n\n\t\t\t\t\t Joueur 1 vous n'avez pas pu trouver le nombre mystere :( !\n\n");
			printf("\n\n\n\t\t\t\t\tFin du jeu.\n\n\n");
			printf("\n\n\n\t\t\t\t");
			system("pause");
		}
		// Fin test joueur 1

		// On teste si le joueur 2 a trouvé son nombre mystère
		if(num2 == nm2){

			system("cls");
			system("color 0c");
			printf("\n\n\n\t\t\t\t\tBravo :) , le nombre mystere est bien \"%d\".\n\n", nm2);
			printf("\n\n\n\t\t\t\t\tLe vainqueur est le Joueur 2.\n\n");
			printf("\n\n\n\t\t\t\t\tFin du jeu.\n\n\n");
			printf("\n\n\n\t\t\t\t");
			system("pause");
		}

		if(cp2 == 0 && num2 != nm2){

			system("cls");
			system("color 0c");
			printf("\n\n\n\t\t\t\t\t Joueur 2 vous n'avez pas pu trouver le nombre mystere :( !\n\n");
			printf("\n\n\n\t\t\t\t\tFin du jeu.\n\n\n");
			printf("\n\n\n\t\t\t\t");
			system("pause");
		}
		// Fin test joueur 2
	}

	// Niveau Difficile
	if(choixMode == 2 && choixDiff == 2 && choix == 1){

		printf("\n\n\t\t\t\t\tLe nombre doit etre compris entre 101 et 1000");
		printf("\n\n\t\t\t\t\tJoueur 1, entrez le nombre mystere du Joueur 2 :");
		scanf("%d", &nm2);
		sleep(1);
		system("cls");
		system("color 0c");
		printf("\n\n\t\t\t\t\tLe nombre doit etre compris entre 101 et 1000");
		printf("\n\n\t\t\t\t\tJoueur 2, entrez le nombre mystere du Joueur 1 :");
		scanf("%d", &nm1);


		do{

			system("cls");
			system("color 09");
			// Le joueur 1 joue
			printf("\n\n\t\t\t\t\tJoueur 1:\n");
			printf("\n\n\t\t\t\t\tIl vous reste %d coup(s).", cpd1);
			printf("\n\t\t\t\t\tQuel est le nombre Mystere ?");
			printf("\n\t\t\t\t\tProposez un nombre : ");
			scanf("%d", &num1);

			if(num1 > nm1){

				printf("\n\t\t\t\t\tC'est moins !\n");
				printf("\n\t\t\t\t\t");
				system("pause");
			}

			else if(num1 < nm1){

				printf("\n\t\t\t\t\tC'est plus !\n");
				printf("\n\t\t\t\t\t");
				system("pause");
			}

			cpd1--;

			system("cls");
			// Le joueur 2 joue
			system("color 0c");
			printf("\n\n\t\t\t\t\tJoueur 2:\n");
			printf("\n\n\t\t\t\t\tIl vous reste %d coup(s).", cpd2);
			printf("\n\t\t\t\t\tQuel est le nombre Mystere ?");
			printf("\n\t\t\t\t\tProposez un nombre : ");
			scanf("%d", &num2);

			if(num2 > nm2){

				printf("\n\t\t\t\t\tC'est moins !\n");
				printf("\n\t\t\t\t\t");
				system("pause");
			}

			else if(num2 < nm2){

				printf("\n\t\t\t\t\tC'est plus !\n");
				printf("\n\t\t\t\t\t");
				system("pause");
			}

			cpd2--;

	    }while((num1 != nm1 && cpd1 > 0) && (num2 != nm2 && cpd2 > 0));

		// On teste si le joueur 1 a trouvé son nombre mystère
		if(num1 == nm1){

		    system("cls");
		    system("color 09");
			printf("\n\n\n\t\t\t\t\tBravo :) , le nombre mystere est bien \"%d\".\n\n", nm1);
			printf("\n\n\n\t\t\t\t\tLe vainqueur est le Joueur 1.\n\n");
			printf("\n\n\n\t\t\t\t\tFin du jeu.\n\n\n");
			printf("\n\n\n\t\t\t\t");
			system("pause");
		}

		if(cpd1 == 0 && num1 != nm1){

			system("cls");
			system("color 09");
			printf("\n\n\n\t\t\t\t\t Joueur 1 vous n'avez pas pu trouver le nombre mystere :( !\n\n");
			printf("\n\n\n\t\t\t\t\tFin du jeu.\n\n\n");
			printf("\n\n\n\t\t\t\t");
			system("pause");
		}
		// Fin test joueur 1

		// On teste si le joueur 2 a trouvé son nombre mystère
		if(num2 == nm2){

			system("cls");
			system("color 0c");
			printf("\n\n\n\t\t\t\t\tBravo :) , le nombre mystere est bien \"%d\".\n\n", nm2);
			printf("\n\n\n\t\t\t\t\tLe vainqueur est le Joueur 2.\n\n");
			printf("\n\n\n\t\t\t\t\tFin du jeu.\n\n\n");
			printf("\n\n\n\t\t\t\t");
			system("pause");
		}

		if(cpd2 == 0 && num2 != nm2){

			system("cls");
			system("color 0c");
			printf("\n\n\n\t\t\t\t\t Joueur 2 vous n'avez pas pu trouver le nombre mystere :( !\n\n");
			printf("\n\n\n\t\t\t\t\tFin du jeu.\n\n\n");
			printf("\n\n\n\t\t\t\t");
			system("pause");
		}
		// Fin test joueur 2
	}

	// Niveau Très Difficile
	if(choixMode == 2 && choixDiff == 3 && choix == 1){

		printf("\n\n\t\t\t\t\tLe nombre doit etre compris entre 1001 et 10000");
		printf("\n\n\t\t\t\t\tJoueur 1, entrez le nombre mystere du Joueur 2 :");
		scanf("%d", &nm2);
		sleep(1);
		system("cls");
		system("color 0c");
		printf("\n\n\t\t\t\t\tLe nombre doit etre compris entre 1001 et 10000\n");
		printf("\n\n\t\t\t\t\tJoueur 2, entrez le nombre mystere du Joueur 1 :");
		scanf("%d", &nm1);


		do{

			system("cls");
			system("color 09");
			// Le joueur 1 joue
			printf("\n\n\t\t\t\t\tJoueur 1:\n");
			printf("\n\n\t\t\t\t\tIl vous reste %d coup(s).", cpt1);
			printf("\n\t\t\t\t\tQuel est le nombre Mystere ?");
			printf("\n\t\t\t\t\tProposez un nombre : ");
			scanf("%d", &num1);

			if(num1 > nm1){

				printf("\n\t\t\t\t\tC'est moins !\n");
				printf("\n\t\t\t\t\t");
				system("pause");
			}

			else if(num1 < nm1){

				printf("\n\t\t\t\t\tC'est plus !\n");
				printf("\n\t\t\t\t\t");
				system("pause");
			}

			cpt1--;

			system("cls");
			// Le joueur 2 joue
			system("color 0c");
			printf("\n\n\t\t\t\t\tJoueur 2:\n");
			printf("\n\n\t\t\t\t\tIl vous reste %d coup(s).", cpt2);
			printf("\n\t\t\t\t\tQuel est le nombre Mystere ?");
			printf("\n\t\t\t\t\tProposez un nombre : ");
			scanf("%d", &num2);

			if(num2 > nm2){

				printf("\n\t\t\t\t\tC'est moins !\n");
				printf("\n\t\t\t\t\t");
				system("pause");
			}

			else if(num2 < nm2){

				printf("\n\t\t\t\t\tC'est plus !\n");
				printf("\n\t\t\t\t\t");
				system("pause");
			}

			cpt2--;

	    }while((num1 != nm1 && cpt1 > 0) && (num2 != nm2 && cpt2 > 0));

		// On teste si le joueur 1 a trouvé son nombre mystère
		if(num1 == nm1){

		    system("cls");
		    system("color 09");
			printf("\n\n\n\t\t\t\t\tBravo :) , le nombre mystere est bien \"%d\".\n\n", nm1);
			printf("\n\n\n\t\t\t\t\tLe vainqueur est le Joueur 1.\n\n");
			printf("\n\n\n\t\t\t\t\tFin du jeu.\n\n\n");
			printf("\n\n\n\t\t\t\t");
			system("pause");
		}

		if(cpt1 == 0 && num1 != nm1){

			system("cls");
			system("color 09");
			printf("\n\n\n\t\t\t\t\t Joueur 1 vous n'avez pas pu trouver le nombre mystere :( !\n\n");
			printf("\n\n\n\t\t\t\t\tFin du jeu.\n\n\n");
			printf("\n\n\n\t\t\t\t");
			system("pause");
		}
		// Fin test joueur 1

		// On teste si le joueur 2 a trouvé son nombre mystère
		if(num2 == nm2){

			system("cls");
			system("color 0c");
			printf("\n\n\n\t\t\t\t\tBravo :) , le nombre mystere est bien \"%d\".\n\n", nm2);
			printf("\n\n\n\t\t\t\t\tLe vainqueur est le Joueur 2.\n\n");
			printf("\n\n\n\t\t\t\t\tFin du jeu.\n\n\n");
			printf("\n\n\n\t\t\t\t");
			system("pause");
		}

		if(cpt2 == 0 && num2 != nm2){

			system("cls");
			system("color 0c");
			printf("\n\n\n\t\t\t\t\t Joueur 2 vous n'avez pas pu trouver le nombre mystere :( !\n\n");
			printf("\n\n\n\t\t\t\t\tFin du jeu.\n\n\n");
			printf("\n\n\n\t\t\t\t");
			system("pause");
		}
		// Fin test joueur 2
	}
// Fin instructions du MODE 2 joueurs

	return 0;
}



void AfficherMenu(){

	printf("\n\t\t\tBienvenu dans le jeu du \"Nombre Mystere\" !");
	printf("\n\n\n\t\t\t\t\t****__MENU__****");
	printf("\n\n\t\t\t\t\t1- NOUVELLE PARTIE.");
	printf("\n\t\t\t\t\t2- MODE D'EMPLOIE (COMMENT JOUER).");
	printf("\n\t\t\t\t\t3- QUITTER LE JEU.");
}



void ModeDemploie(){
	
	system("cls");
	printf("\n\n\t\tMODE D'EMPLOIE :");
	printf("\n\t\t~~~~~~~~~~~~~~");
	sleep(1);
	printf("\n\n\n\t\tCeci est le jeu du \"Nombre Mystere\".");
	sleep(2);
	printf("\n\t\tPour jouer vous devez proposer au et a mesure des nombres, jusqu'a trouver le fameux \"Nombre Mystere\" !");
	sleep(2);
	printf("\n\t\tA chaque fois que vous entrez un nombre, validez avec la touche \"ENTER\".");
	sleep(2);
	printf("\n\t\tCe \"Nombre Mystere\" peut se trouver entre %d et %d .", MIN1, MAX1);
	sleep(2);
	printf("\n\t\tOu entre %d et %d .", MIN2, MAX2);
	sleep(2);
	printf("\n\t\tOu entre %d et %d .", MIN3, MAX3);
	sleep(2);
	printf("\n\n\n\t\tBonne Chance :) !");
	sleep(1);
	printf("\n\n\n\t\t");
	system("pause");
}



void AfficherMode(){

	printf("\n\t\t\tBienvenu dans le jeu du \"Nombre Mystere\" !");
	printf("\n\n\n\t\t\t\t\t****__MENU__****");
	printf("\n\n\t\t\t\t\t1- MODE 1 JOUEUR.");
	printf("\n\t\t\t\t\t2- MODE 2 JOUEURS.");
	printf("\n\t\t\t\t\t3- AIDE.");
}



void AfficherDiff(){

	printf("\n\t\t\tBienvenu dans le jeu du \"Nombre Mystere\" !");
	printf("\n\n\n\t\t\t\t\t****__MENU__****");
	printf("\n\n\t\t\t\t\t1- NIVEAU FACILE.");
	printf("\n\t\t\t\t\t2- NIVEAU DIFFICILE.");
	printf("\n\t\t\t\t\t3- NIVEAU TRES DIFFICILE.");
	printf("\n\t\t\t\t\t4- AIDE.");
}



void Aide1(){

	system("cls");
	printf("\n\n\t\tAIDE :");
	printf("\n\t\t~~~~");
	printf("\n\n\n\t\tEn mode 1 joueur, vous devez essayer de trouver un \"Nombre Mystere\" que le jeu choisi.\n");
	printf("\n\t\tEn mode 2 joueurs, chaque joueur entre un \"Nombre Mystere\" que l'autre devra trouver.");
	printf("\n\t\tLe premier qui trouve son \"Nombre Mystere\" remporte la partie.");
	printf("\n\n\n\t\tBonne Chance :) !");
	printf("\n\n\n\t\t");
	system("pause");
}



void Aide2(){

	system("cls");
	printf("\n\n\t\tAIDE :");
	printf("\n\t\t~~~~");
	printf("\n\n\n\t\tNIVEAU FACILE : le \"Nombre Mystere\" est compris entre 1 et 100.\n");
	printf("\n\t\tNIVEAU DIFFICILE : le \"Nombre Mystere\" est compris entre 101 et 1000.\n");
	printf("\n\t\tNIVEAU TRES DIFFICILE : le \"Nombre Mystere\" est compris entre 1001 et 10000.\n");
	printf("\n\n\n\t\tBonne Chance :) !");
	printf("\n\n\n\t\t");
	system("pause");
}
