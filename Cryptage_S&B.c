/*
	Programme chiffrement/dechiffrement by Skull & Bones

						 		  ______   ___ ___  __    __  __        __
								 /\     \ |\  \\  \|\ \  |\ \|\ \      |\ \
								|\ ######\| ##/ ##/| ##  | ##| ##      | ##
								| ##___\##| ## ##/ | ##  | ##| ##      | ##
								 \##\   \ | ####/  | ##  | ##| ##      | ##
								 _\######\| ###(   | ## _| ##| ##      | ##
								|  \__| ##| ####\  | ##/ \ ##| ##_____ | ##_____
								 \##   \##| ## ##\  \## ## ##| ##\    \| ##\    \
						          \######  \##\_##\  \######/ \######## \########
*/

// Bibliothèques
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_ALPHABET_MIN 25
#define TAILLE_ALPHABET_MAX 25
#define TAILLE_SYMBOLES 25

int initialisation(); // Fonction initialisation

static void purger(void); // Enlever le retour à la ligne lors de la saisie

static void clean (char *chaine); // Eviter le buffer overflow

void chiffrement(); // Fonction cryptage

void dechiffrement(); // Fonction decryptage

void quitter();

void affichage();

int main() // Fonction principale
{
	int cryptageDecryptage = -1; // Variable cryptage/decryptage

	do
	{
		cryptageDecryptage = initialisation();

		switch(cryptageDecryptage) // Vérification variable cryptageDecryptage
		{
			case 0: // Si égal à 0
				quitter(); // Quitter
				break;
			case 1: // Si égal à 1
				chiffrement(); // Cryptage
				break;
			case 2: // Si égal à 2
				dechiffrement(); // Décryptage
				break;
		}
	} while(cryptageDecryptage != 0);

	printf("\n"); // Retour à la ligne

	return 0;
}

int initialisation() // Fonction initialisation
{
	char texte[4];
	int nombre = 0, ret;

	affichage();

	printf("\n\n   Mises à jour et nouveautés sur https://github.com/SkullAndBone/Cryptage-fr");

	printf("\n\n================================================================================\n");
	printf("\t\t\tProgramme de Chiffrement/Dechiffrement\n");
	printf("================================================================================\n");

	printf("\n\n================================================================================\n");
	printf("\t\t\t\t  Quitter -> 0\n\t\t\t\t Chiffrer --> 1\n\t\t\t\tDechiffrer --> 2\n"); // Demande cryptage/decryptage
	printf("================================================================================\n\n");

	printf("\n================================================================================\n");

	do // Tant que nombre différent de 0 ou 1
	{
		do // Tant que ce n'est pas un nombre
		{
			printf("\t\t\tVeuillez saisir votre choix : "); // Demande de saisie
			fgets(texte, sizeof texte, stdin); // Saisi nombre

			clean(texte); // Enlève le retour à la ligne

			ret = sscanf(texte, "%d", &nombre);

			if(ret != 1) // Tant que ce n'est pas un nombre
			{
				printf("\n"); // Retour à la ligne
			}
		} while(ret != 1); // Tant que ce n'est pas un nombre

		if(nombre != 0 &&nombre != 1 && nombre != 2) // Tant que nombre différent de 0 ou 1
		{
			printf("\n"); // Retour à la ligne
		}
	} while(nombre != 0 && nombre != 1 && nombre != 2); // Tant que nombre différent de 0 ou 1
	printf("================================================================================\n\n");

	affichage();

	printf("\n\n================================================================================\n");
	switch(nombre) // Vérification variable cryptageDecryptage
	{
		case 0:
			printf("\t\t\t          ===== FIN =====\n");
			break;
		case 1: // Si égal à 1
			printf("\t\t\t      ===== CHIFFREMENT =====\n");
			break;

		case 2: // Si égal à 2
			printf("\t\t\t     ===== DECHIFFREMENT =====\n");
			break;
	}
	printf("================================================================================\n\n");

	return(nombre); // On retourne la variable
}

static void purger(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {}
}

static void clean (char *chaine)
{
    char *p = strchr(chaine, '\n');

    if (p)
    {
        *p = 0;
    }

    else
    {
        purger();
    }
}

void chiffrement()
{
	char texte[200];
	int nombre = 0, ret = 0;
	int i = 0, n = 0;	
	unsigned long nombre2 = 0;
	char password[200];
	unsigned int ascii = 0;

	char alphabetMin[30] = "abcdefghijklmnopqrstuvwxyz\0";
	char alphabetMax[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\0";	
	char symboles[30] = "0123456789 -!().\'\"?/*+=:,>\0";

	unsigned int testNombre = 50000000;
	unsigned int nombreAscii = 0;
	int nombreOk = -1;

	do
	{
		printf("================================================================================\n");
		printf("Mot de passe : ");
		fgets(password, sizeof password, stdin); // Saisi du texte à crypter
		clean(password);
		printf("================================================================================\n\n");

		i = 0;

		while(password[n] != '\0')
		{
			n++;
		}

		while(i != n)
		{
			ascii = (int)password[i] + ascii;

			i++;
		}

		i = 0;

		printf("================================================================================\n");

		do // Tant que nombre différent de 0 ou 1
		{
			do // Tant que ce n'est pas un nombre
			{
				printf("Entrez un chiffre pour crypter (entre 0 et 1 000 000 000) : ");
				fgets(texte, sizeof texte, stdin); // Saisi nombre

				clean(texte); // Enlève le retour à la ligne

				ret = sscanf(texte, "%ld", &nombre2);

				if(ret != 1) // Tant que ce n'est pas un nombre
				{
					printf("\n"); // Retour à la ligne
				}
			} while(ret != 1); // Tant que ce n'est pas un nombre
		} while(nombre2 < 0 || nombre2 > 1000000000); // Tant que nombre différent de 0 ou 1

		printf("================================================================================\n\n");

		ascii = ascii + nombre2;

		nombreOk = 1;

		do
		{
			nombreAscii = 26 * testNombre;

			testNombre--;

			if(nombreAscii == ascii)
			{
				nombreOk = 0;
			}
		} while (testNombre != 0);

		if(nombreOk == 0)
		{
			printf("Erreur... Veuillez choisir un mot de passe et un nombre différent !\n\n");
		}

	} while (nombreOk != 1);

	printf("\n================================================================================\n");

	do // Tant que nombre différent de 0 ou 1
	{
		do // Tant que ce n'est pas un nombre
		{
			printf("Voulez vous écrire le résultat dans un fichier ? (0 -> oui, 1 -> non) : ");
			fgets(texte, sizeof texte, stdin); // Saisi nombre

			clean(texte); // Enlève le retour à la ligne

			ret = sscanf(texte, "%d", &nombre);

			if(ret != 1) // Tant que ce n'est pas un nombre
			{
				printf("\n"); // Retour à la ligne
			}
		} while(ret != 1); // Tant que ce n'est pas un nombre

		if(nombre != 0 && nombre != 1) // Tant que nombre différent de 0 ou 1
		{
			printf("\n"); // Retour à la ligne
		}
	} while(nombre != 0 && nombre != 1); // Tant que nombre différent de 0 ou 1

	int ecritureFichier = 0;
	ecritureFichier = nombre;

	printf("================================================================================\n\n");

	affichage();

	printf("\n================================================================================\n");
	printf("Texte à crypter : \n\n");
	fgets(texte, sizeof texte, stdin); // Saisi du texte à crypter
	clean(texte);
	printf("================================================================================\n\n");

	printf("\n"); // Retour à la ligne

	printf("\n================================================================================\n");
	printf("\t\t\t     ===== RESULTAT =====\n\n");

	// Chiffrement par substitution

	int p = 0;
	int boolAlphabet = 0;
	i = 0;

	while(texte[i] != '\0') // Tant que ce n'est pas la fin du texte
	{
		p = 0;
		boolAlphabet = 0;

		while(boolAlphabet != 1 && boolAlphabet != 2 && boolAlphabet != 3)
		{
			if(texte[i] == alphabetMin[p])
			{
				boolAlphabet = 1;
			}

			if(texte[i] == alphabetMax[p])
			{
				boolAlphabet = 2;
			}

			if(texte[i] == symboles[p])
			{
				boolAlphabet = 3;
			}

			p++;
		}

		switch(boolAlphabet)
		{
			case 1:
				texte[i] = alphabetMin[TAILLE_ALPHABET_MIN-(p-1)];
				break;
			case 2:
				texte[i] = alphabetMax[TAILLE_ALPHABET_MAX-(p-1)];
				break;
			case 3:
				texte[i] = symboles[TAILLE_SYMBOLES-(p-1)];
				break;
		}

		i++;
	}

	// Début deuxième cryptage avec mot de passe

	// Initialisation des variables
	// Déclarations des variables servant à ce cryptage

	i = 0;
	n = 0;

	int k = 0, l = 0;
	int alphabet = 0, caractere = 0;
	unsigned int asciiDeux = 0;

	asciiDeux = ascii; // Variable servant à toujours avoir une save de ascii (ascii devant être modifié)

	while(texte[i] != '\0') // Boucle pour avoir le nombre de caractères de texte
	{
		i++;
	}

	while(n != i)  // Tant qu'on à pas fait chaque caractère de la phrase à crypté
	{
		alphabet = 0; // Initialisation

		while(alphabet != 26)
		{
			if(texte[n] == alphabetMin[alphabet]) // Si le caractère est minuscule
			{
				caractere = 1; // On met la variable à 1 -> pour les minuscules
			}

			alphabet++;
		}

		if(caractere != 1) // Si le caractère n'est pas minuscule
		{
			alphabet = 0;

			while(alphabet != 26)
			{
				if(texte[n] == alphabetMax[alphabet]) // Si le caractère est en majuscule
				{
					caractere = 2; // On met la variable à 2 -> majuscules
				}

				alphabet++;
			}
		}

		if(caractere != 1 && caractere != 2) // Si le caractère n'est ni minuscule ni majuscule
		{
			alphabet = 0;

			while(alphabet != 26)
			{
				if(texte[n] == symboles[alphabet]) // Si c'est un symbole
				{
					caractere = 3; // On met la variable à 3 -> symboles
				}

				alphabet++;
			}
		}

		switch(caractere) // On vérifie la variable
		{
			case 1: // Si minuscule

				k = 0;
				l = 0;

				while(texte[n] != alphabetMin[l] && alphabetMin[l] != '\0')
				{

					l++;
				}

				k = k + l;

				while(ascii != 0)
				{
					texte[n] = alphabetMin[k];

					k++;

					if(k == 26)
					{
						k = 0;
					}

					ascii--;
				}
				break;
			case 2: // Si le caractère est en majuscule

				k = 0;
				l = 0;

				while(texte[n] != alphabetMax[l] && alphabetMax[l] != '\0')
				{

					l++;
				}

				k = k + l;

				while(ascii != 0)
				{
					texte[n] = alphabetMax[k];

					k++;

					if(k == 26)
					{
						k = 0;
					}

					ascii--;
				}
				break;
			case 3: // Si le caractère est un symbole

				k = 0;
				l = 0;

				while(texte[n] != symboles[l] && symboles[l] != '\0')
				{

					l++;
				}

				k = k + l;

				while(ascii != 0)
				{
					texte[n] = symboles[k];

					k++;

					if(k == 26)
					{
						k = 0;
					}

					ascii--;
				}
				break;

			// Si caractère inconnue on ne change rien (on pourrait rajouter un default pour mais flemme)
		}

		ascii = asciiDeux; // On remet ascii comme au début

		n++;

		caractere = 0; // Remet la variable caractère à 0 (Obvious is obvious)
	}

	printf("%s\n", texte); // Affiche la phrase décryptée

	// Fin deuxième cryptage avec mot de passe

	printf("===============================================================================\n");

	printf("\n\nAppuyez sur entrée pour continuer...");
	scanf("%c", &texte[0]);

	// Ecriture fichier

	if(ecritureFichier == 0) // Si l'utilisateur veut écrire dans un fichier
	{
		FILE* fichier = NULL;
		fichier = fopen("cryptage.txt", "w+");

		if(fichier != NULL) // Si aucune erreur d'ouverture
		{
			fprintf(fichier, "\n			  ______   ___ ___  __    __  __        __\n");
			fprintf(fichier, "			 /\\     \\ |\\  \\\\  \\|\\ \\  |\\ \\|\\ \\      |\\ \\\n");
			fprintf(fichier, "			|\\ ######\\| ##/ ##/| ##  | ##| ##      | ##\n");
			fprintf(fichier, "			| ##___\\##| ## ##/ | ##  | ##| ##      | ##\n");
			fprintf(fichier, "			 \\##\\   \\ | ####/  | ##  | ##| ##      | ##\n");
			fprintf(fichier, "			 _\\######\\| ###(   | ## _| ##| ##      | ##\n");
			fprintf(fichier, "			|  \\__| ##| ####\\  | ##/ \\ ##| ##_____ | ##_____\n");
			fprintf(fichier, "			 \\##   \\##| ## ##\\  \\## ## ##| ##\\    \\| ##\\    \\\n");
			fprintf(fichier, "		      \\######  \\##\\_##\\  \\######/ \\######## \\########\n\n");

			fprintf(fichier, "\n\n================================================================================\n");
			fprintf(fichier, "\t\t\tProgramme de Cryptage/Decryptage\n");
			fprintf(fichier, "================================================================================\n");

			fprintf(fichier, "\nPhrase cryptée : \n\n%s", texte);
			fprintf(fichier, "\n\nMises à jour et nouveautés sur https://github.com/SkullAndBone/Cryptage-fr");
		}

		else // Si erreur d'ouverture
		{
			printf("Erreur d'ouverture du fichier cryptage.txt !");  // Ecriture de l'erreur
		}

		fclose(fichier); // Fermeture du fichier
	}
}

void dechiffrement() // Fonction decryptage
{
	char texte[1000];
	char password[200];
	char texteDecrypt[1000];
	int nombre = 0, ret = 0;
	int i = 0, n = 0;
	int nombre2 = 0;
	unsigned int ascii = 0;
	int fichierDecryptage = 0;

	char alphabetMin[30] = "abcdefghijklmnopqrstuvwxyz\0";
	char alphabetMax[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\0";	
	char symboles[30] = "0123456789 -!().\'\"?/*+=:,>\0";

	FILE* fichierDecrypt = NULL;

	unsigned int testNombre = 50000000;
	unsigned int nombreAscii = 0;
	int nombreOk = -1;

	do
	{
		printf("================================================================================\n");
		printf("Mot de passe : ");
		fgets(password, sizeof password, stdin); // Saisi du texte à crypter
		clean(password);
		printf("================================================================================\n\n");

		i = 0;

		while(password[n] != '\0')
		{
			n++;
		}

		while(i != n)
		{
			ascii = (int)password[i] + ascii;

			i++;
		}

		i = 0;

		printf("================================================================================\n");

		do // Tant que nombre différent de 0 ou 1
		{
			do // Tant que ce n'est pas un nombre
			{
				printf("Entrez un chiffre pour décrypter (entre 0 et 1 000 000 000) : ");
				fgets(texte, sizeof texte, stdin); // Saisi nombre

				clean(texte); // Enlève le retour à la ligne

				ret = sscanf(texte, "%d", &nombre2);

				if(ret != 1) // Tant que ce n'est pas un nombre
				{
					printf("\n"); // Retour à la ligne
				}
			} while(ret != 1); // Tant que ce n'est pas un nombre
		} while(nombre2 < 0 || nombre2 > 1000000000); // Tant que nombre différent de 0 ou 1

		printf("================================================================================\n\n");

		ascii = ascii + nombre2;

		nombreOk = 1;

		do
		{
			nombreAscii = 26 * testNombre;

			testNombre--;

			if(nombreAscii == ascii)
			{
				nombreOk = 0;
			}
		} while (testNombre != 0);

		if(nombreOk == 0)
		{
			printf("Erreur... Veuillez choisir un mot de passe et un nombre différent !\n\n");
		}

	} while (nombreOk != 1);

	printf("\n================================================================================\n");

	do // Tant que nombre différent de 0 ou 1
	{
		do // Tant que ce n'est pas un nombre
		{
			printf("Voulez vous écrire le résultat dans un fichier ? (0 -> oui, 1 -> non) : ");
			fgets(texte, sizeof texte, stdin); // Saisi nombre

			clean(texte); // Enlève le retour à la ligne

			ret = sscanf(texte, "%d", &nombre);

			if(ret != 1) // Tant que ce n'est pas un nombre
			{
				printf("\n"); // Retour à la ligne
			}
		} while(ret != 1); // Tant que ce n'est pas un nombre

		if(nombre != 0 && nombre != 1) // Tant que nombre différent de 0 ou 1
		{
			printf("\n"); // Retour à la ligne
		}
	} while(nombre != 0 && nombre != 1); // Tant que nombre différent de 0 ou 1

	int ecritureFichier = 0;
	ecritureFichier = nombre;

	printf("================================================================================\n\n");

	do
	{
		affichage();

		printf("\n================================================================================\n");

		do // Tant que nombre différent de 0 ou 1
		{
			do // Tant que ce n'est pas un nombre
			{
				printf("                  == Utilisation du fichier decryptage.txt ==\n\n");
				printf("1 - Afficher l'aide pour utiliser le fichier de lecture de la phrase à décrypté\n");
				printf("                              2 - Continuer\n\n");
				printf("                                Choix : ");
				fgets(texte, sizeof texte, stdin); // Saisi nombre

				clean(texte); // Enlève le retour à la ligne

				ret = sscanf(texte, "%d", &nombre);

				if(ret != 1) // Tant que ce n'est pas un nombre
				{
					printf("\n"); // Retour à la ligne
				}
			} while(ret != 1); // Tant que ce n'est pas un nombre

			if(nombre != 1 && nombre != 2) // Tant que nombre différent de 1 ou 2
			{
				printf("\n"); // Retour à la ligne
			}
		} while(nombre != 1 && nombre != 2); // Tant que nombre différent de 1 ou 2

		switch(nombre)
		{
			case 1:
				printf("================================================================================\n\n");

				printf("\n================================================================================\n");

				printf("                                 == AIDE ==\n\n");
				printf("Pour utiliser le décryptage, il est plus facile sous Windows d'utiliser un\n");
				printf("Fichier dans lequel vous pourrez coller la phrase à decrypter afin de ne pas\n");
				printf("Avoir à tout réécrire. Créez donc un fichier nommé decryptage.txt puis collez\n");
				printf("Y la phrase à décrypter, le programme ira chercher la phrase automatiquement\n");
				printf("Et la décryptera.\n");

				printf("================================================================================\n\n");

				printf("Appuyez sur entrée pour continuer....");

				fgets(texte, sizeof texte, stdin);

				clean(texte); // Enlève le retour à la ligne

				break;
			case 2:
				printf("\n================================================================================\n");

				do // Tant que nombre différent de 0 ou 1
				{
					do // Tant que ce n'est pas un nombre
					{
						affichage();

						printf("\n================================================================================\n");

						printf("                  == Utilisation du fichier decryptage.txt ==\n\n");
						printf("             1 - Ne pas utiliser le fichier decryptage.txt\n");
						printf("                 2 - Utiliser le fichier decryptage.txt\n\n");
						printf("                                Choix : ");
						fgets(texte, sizeof texte, stdin); // Saisi nombre

						clean(texte); // Enlève le retour à la ligne

						ret = sscanf(texte, "%d", &nombre2);

						if(ret != 1) // Tant que ce n'est pas un nombre
						{
							printf("\n"); // Retour à la ligne
						}
					} while(ret != 1); // Tant que ce n'est pas un nombre

					if(nombre2 != 1 && nombre2 != 2) // Tant que nombre différent de 1 ou 2
					{
						printf("\n"); // Retour à la ligne
					}
				} while(nombre2 != 1 && nombre2 != 2); // Tant que nombre différent de 1 ou 2

				switch(nombre2)
				{
					case 1:
						fichierDecryptage = 0;
						break;
					case 2:
						fichierDecryptage = 1;
						break;
				}
				break;
		}
	} while(nombre != 2);

	nombre = 0;
	nombre2 = 0;

	switch(fichierDecryptage)
	{
		case 0:
			printf("\n================================================================================\n");
			printf("Texte à decrypter : \n\n");
			fgets(texte, sizeof texte, stdin); // Saisi du texte à crypter
			clean(texte);
			printf("================================================================================\n\n");

			printf("\n"); // Retour à la ligne
			break;
		case 1:
			fichierDecrypt = fopen("decryptage.txt", "r");

			if(fichierDecrypt != NULL)
			{
				fgets(texteDecrypt, 1000, fichierDecrypt);

				n = 0;
				i = 0;

				while(texteDecrypt[i] != '\0')
				{
					i++;
				}

				while(n != i)
				{
					texte[n] = texteDecrypt[n];

					n++;
				}
			}

			else
			{
				printf("\nErreur d'ouverture du fichier decryptage.txt !\n\n");
			}
			break;
	}

	printf("\n===============================================================================\n");
	printf("\t\t\t     ===== RESULTAT =====\n\n");

	// Début deuxième decryptage avec mot de passe

	// Initialisation des variables
	// Déclarations des variables servant à ce decryptage

	i = 0;
	n = 0;

	int k = 0, l = 0;
	int alphabet = 0, caractere = 0;
	unsigned int asciiDeux = 0;

	asciiDeux = ascii; // Variable servant à toujours avoir une save de ascii (ascii devant être modifié)

	while(texte[i] != '\0') // Boucle pour avoir le nombre de caractères de texte
	{
		i++;
	}

	while(n != i)  // Tant qu'on à pas fait chaque caractère de la phrase à crypté
	{
		alphabet = 0; // Initialisation

		while(alphabet != 26)
		{
			if(texte[n] == alphabetMin[alphabet]) // Si le caractère est minuscule
			{
				caractere = 1; // On met la variable à 1 -> pour les minuscules
			}

			alphabet++;
		}

		if(caractere != 1) // Si le caractère n'est pas minuscule
		{
			alphabet = 0;

			while(alphabet != 26)
			{
				if(texte[n] == alphabetMax[alphabet]) // Si le caractère est en majuscule
				{
					caractere = 2; // On met la variable à 2 -> majuscules
				}

				alphabet++;
			}
		}

		if(caractere != 1 && caractere != 2) // Si le caractère n'est ni minuscule ni majuscule
		{
			alphabet = 0;

			while(alphabet != 26)
			{
				if(texte[n] == symboles[alphabet]) // Si c'est un symbole
				{
					caractere = 3; // On met la variable à 3 -> symboles
				}

				alphabet++;
			}
		}

		switch(caractere) // On vérifie la variable
		{
			case 1: // Si minuscule

				k = 26;
				l = 0;

				while(texte[n] != alphabetMin[l] && alphabetMin[l] != '\0')
				{

					l++;
				}

				k = l;

				while(ascii != 0)
				{
					texte[n] = alphabetMin[k];

					k--;

					if(k == -1)
					{
						k = 25;
					}

					ascii--;
				}
				break;
			case 2: // Si le caractère est en majuscule

				k = 26;
				l = 0;

				while(texte[n] != alphabetMax[l] && alphabetMax[l] != '\0')
				{

					l++;
				}

				k = l;

				while(ascii != 0)
				{
					texte[n] = alphabetMax[k];

					k--;

					if(k == -1)
					{
						k = 25;
					}

					ascii--;
				}
				break;
			case 3: // Si le caractère est un symbole

				k = 26;
				l = 0;

				while(texte[n] != symboles[l] && symboles[l] != '\0')
				{

					l++;
				}

				k = l;

				while(ascii != -1)
				{
					texte[n] = symboles[k];

					k--;

					if(k == 0)
					{
						k = 25;
					}

					ascii--;
				}
				break;

			// Si caractère inconnue on ne change rien (on pourrait rajouter un default pour mais flemme)
		}

		ascii = asciiDeux; // On remet ascii comme au début

		n++;

		caractere = 0; // Remet la variable caractère à 0 (Obvious is obvious)
	}
	
	i = 0;

	// Fin premier decryptage avec mot de passe

	int p = 0;
	int boolAlphabet = 0;
	i = 0;

	while(texte[i] != '\0') // Tant que ce n'est pas la fin du texte
	{
		p = 0;
		boolAlphabet = 0;

		while(boolAlphabet != 1 && boolAlphabet != 2 && boolAlphabet != 3)
		{
			if(texte[i] == alphabetMin[p])
			{
				boolAlphabet = 1;
			}

			if(texte[i] == alphabetMax[p])
			{
				boolAlphabet = 2;
			}

			if(texte[i] == symboles[p])
			{
				boolAlphabet = 3;
			}

			p++;
		}

		switch(boolAlphabet)
		{
			case 1:
				texte[i] = alphabetMin[TAILLE_ALPHABET_MIN-(p-1)];
				break;
			case 2:
				texte[i] = alphabetMax[TAILLE_ALPHABET_MAX-(p-1)];
				break;
			case 3:
				texte[i] = symboles[TAILLE_SYMBOLES-(p-1)];
				break;
		}

		i++;
	}

	printf("%s\n", texte); // Affiche la phrase décryptée

	// Fin deuxième cryptage avec mot de passe

	printf("===============================================================================\n");

	printf("\n\nAppuyez sur entrée pour continuer...");
	scanf("%c", &texte[0]);

	// Ecriture fichier

	if(ecritureFichier == 0) // Si l'utilisateur veut écrire dans un fichier
	{
		FILE* fichier = NULL;
		fichier = fopen("cryptage.txt", "w+");

		if(fichier != NULL) // Si aucune erreur d'ouverture
		{
			fprintf(fichier, "\n			  ______   ___ ___  __    __  __        __\n");
			fprintf(fichier, "			 /\\     \\ |\\  \\\\  \\|\\ \\  |\\ \\|\\ \\      |\\ \\\n");
			fprintf(fichier, "			|\\ ######\\| ##/ ##/| ##  | ##| ##      | ##\n");
			fprintf(fichier, "			| ##___\\##| ## ##/ | ##  | ##| ##      | ##\n");
			fprintf(fichier, "			 \\##\\   \\ | ####/  | ##  | ##| ##      | ##\n");
			fprintf(fichier, "			 _\\######\\| ###(   | ## _| ##| ##      | ##\n");
			fprintf(fichier, "			|  \\__| ##| ####\\  | ##/ \\ ##| ##_____ | ##_____\n");
			fprintf(fichier, "			 \\##   \\##| ## ##\\  \\## ## ##| ##\\    \\| ##\\    \\\n");
			fprintf(fichier, "		      \\######  \\##\\_##\\  \\######/ \\######## \\########\n\n");

			fprintf(fichier, "\n\n================================================================================\n");
			fprintf(fichier, "\t\t\tProgramme de Cryptage/Decryptage\n");
			fprintf(fichier, "================================================================================\n");

			fprintf(fichier, "\nPhrase décryptée : \n\n%s", texte);
			fprintf(fichier, "\n\nMises à jour et nouveautés sur https://github.com/SkullAndBone/Cryptage-fr");
		}

		else // Si erreur d'ouverture
		{
			printf("Erreur d'ouverture du fichier cryptage.txt !");  // Ecriture de l'erreur
		}

		fclose(fichier); // Fermeture du fichier
	}

	if(fichierDecryptage == 1)
	{
		fclose(fichierDecrypt);
	}
}

void quitter()
{
	printf("\n   Mises à jour et nouveautés sur https://github.com/SkullAndBone/Cryptage-fr\n\n");
}

void affichage()
{
	printf("\033[H\033[2J");
	printf("\033[31m");

	printf("\n		  ______   ___ ___  __    __  __        __\n");
	printf("		 /\\     \\ |\\  \\\\  \\|\\ \\  |\\ \\|\\ \\      |\\ \\\n");
	printf("		|\\ ######\\| ##/ ##/| ##  | ##| ##      | ##\n");
	printf("		| ##___\\##| ## ##/ | ##  | ##| ##      | ##\n");
	printf("		 \\##\\   \\ | ####/  | ##  | ##| ##      | ##\n");
	printf("		 _\\######\\| ###(   | ## _| ##| ##      | ##\n");
	printf("		|  \\__| ##| ####\\  | ##/ \\ ##| ##_____ | ##_____\n");
	printf("		 \\##   \\##| ## ##\\  \\## ## ##| ##\\    \\| ##\\    \\\n");
	printf("	    	  \\######  \\##\\_##\\  \\######/ \\######## \\########\n\n");

	printf("\033[37m");
}
