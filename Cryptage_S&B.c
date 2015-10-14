/*
	Programme cryptage/decryptage by Skull & Bones

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

int initialisation(); // Fonction initialisation

static void purger(void); // Enlever le retour à la ligne lors de la saisie

static void clean (char *chaine); // Eviter le buffer overflow

void cryptage(); // Fonction cryptage

void decryptage(); // Fonction decryptage

void affichage();

int main() // Fonction principale
{
	int cryptageDecryptage = 0; // Variable cryptage/decryptage

	cryptageDecryptage = initialisation();

	switch(cryptageDecryptage) // Vérification variable cryptageDecryptage
	{
		case 0: // Si égal à 0
			cryptage(); // Cryptage
			break;
		case 1: // Si égal à 1
			decryptage(); // Décryptage
			break;
	}

	printf("\n"); // Retour à la ligne

	return 0;
}

int initialisation() // Fonction initialisation
{
	char texte[4];
	int nombre = 0, ret;

	affichage();

	printf("\n\n================================================================================\n");
	printf("\t\t\tProgramme de Cryptage/Decryptage\n");
	printf("================================================================================\n");

	printf("\n\n================================================================================\n");
	printf("\t\t\t\t Crypter --> 0\n\t\t\t\tDecrypter --> 1\n"); // Demande cryptage/decryptage
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

		if(nombre != 0 && nombre != 1) // Tant que nombre différent de 0 ou 1
		{
			printf("\n"); // Retour à la ligne
		}
	} while(nombre != 0 && nombre != 1); // Tant que nombre différent de 0 ou 1
	printf("================================================================================\n\n");

	affichage();

	printf("\n\n================================================================================\n");
	switch(nombre) // Vérification variable cryptageDecryptage
	{
		case 0: // Si égal à 0
			printf("\t\t\t      ===== CRYPTAGE =====\n");
			break;

		case 1: // Si égal à 1
			printf("\t\t\t     ===== DECRYPTAGE =====\n");
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

void cryptage()
{
	char texte[200];
	int nombre = 0, ret = 0;
	int i = 0, n = 0;
	int nombre3 = 0;	
	int nombre2 = 0;
	int a = 0, b = 1;
	char password[200];
	int ascii = 0;

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
				printf("Entrez un chiffre pour crypter (entre 0 et 250) : ");
				fgets(texte, sizeof texte, stdin); // Saisi nombre

				clean(texte); // Enlève le retour à la ligne

				ret = sscanf(texte, "%d", &nombre3);

				if(ret != 1) // Tant que ce n'est pas un nombre
				{
					printf("\n"); // Retour à la ligne
				}
			} while(ret != 1); // Tant que ce n'est pas un nombre
		} while(nombre3 < 0 || nombre3 > 250); // Tant que nombre différent de 0 ou 1

		while(i != nombre3)
		{
			if(i != nombre3)
			{
				nombre2 = a;

				a = a + b;

				i++;	
			}
			
			if(i != nombre3)
			{
				nombre2 = b;

				b = a + b;

				i++;
			}
		}

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

	while(texte[i] != '\0') // Tant que ce n'est pas la fin du texte
	{
		i++; // Incrémentation i
	}

	if(i < 10) // Si i inférieur à 10
	{
		printf("\t\t\t\t   ");
	}

	else if(i < 20 && i > 10) // Si i compris entre 10 et 20
	{
		printf("\t\t\t\t");
	}

	else if(i < 30 && i > 20) // Si i compris entre 20 et 30
	{
		printf("\t\t\t   ");
	}

	else if(i < 40 && i > 30) // Si i compris entre 30 et 40
	{
		printf("\t\t     ");
	}

	else if(i < 50 && i > 40) // Si i compris entre 40 et 50
	{
		printf("\t\t");
	}

	else if(i < 60 && i > 50) // Si i compris entre 50 et 60
	{
		printf("\t     ");
	}

	else if(i < 70 && i > 60) // Si i compris entre 60 et 70
	{
		printf("\t");
	}

	i = 0;

	while(texte[i] != '\0') // Tant que ce n'est pas la fin du texte
	{
		switch(texte[i]) // Vérification de la lettre
		{

			// MAJUSCULES

			case 'A':
				texte[i] = 'Z';
				break;
			case 'B':
				texte[i] = 'Y';
				break;
			case 'C':
				texte[i] = 'X';
				break;
			case 'D':
				texte[i] = 'W';
				break;
			case 'E':
				texte[i] = 'V';
				break;
			case 'F':
				texte[i] = 'U';
				break;
			case 'G':
				texte[i] = 'T';
				break;
			case 'H':
				texte[i] = 'S';
				break;
			case 'I':
				texte[i] = 'R';
				break;
			case 'J':
				texte[i] = 'Q';
				break;
			case 'K':
				texte[i] = 'P';
				break;
			case 'L':
				texte[i] = 'O';
				break;
			case 'M':
				texte[i] = 'N';
				break;
			case 'N':
				texte[i] = 'M';
				break;
			case 'O':
				texte[i] = 'L';
				break;
			case 'P':
				texte[i] = 'K';
				break;
			case 'Q':
				texte[i] = 'J';
				break;
			case 'R':
				texte[i] = 'I';
				break;
			case 'S':
				texte[i] = 'H';
				break;
			case 'T':
				texte[i] = 'G';
				break;
			case 'U':
				texte[i] = 'F';
				break;
			case 'V':
				texte[i] = 'E';
				break;
			case 'W':
				texte[i] = 'D';
				break;
			case 'X':
				texte[i] = 'C';
				break;
			case 'Y':
				texte[i] = 'B';
				break;
			case 'Z':
				texte[i] = 'A';
				break;

			// MINUSCULES
			
			case 'a':
				texte[i] = 'z';
				break;
			case 'b':
				texte[i] = 'y';
				break;
			case 'c':
				texte[i] = 'x';
				break;
			case 'd':
				texte[i] = 'w';
				break;
			case 'e':
				texte[i] = 'v';
				break;
			case 'f':
				texte[i] = 'u';
				break;
			case 'g':
				texte[i] = 't';
				break;
			case 'h':
				texte[i] = 's';
				break;
			case 'i':
				texte[i] = 'r';
				break;
			case 'j':
				texte[i] = 'q';
				break;
			case 'k':
				texte[i] = 'p';
				break;
			case 'l':
				texte[i] = 'o';
				break;
			case 'm':
				texte[i] = 'n';
				break;
			case 'n':
				texte[i] = 'm';
				break;
			case 'o':
				texte[i] = 'l';
				break;
			case 'p':
				texte[i] = 'k';
				break;
			case 'q':
				texte[i] = 'j';
				break;
			case 'r':
				texte[i] = 'i';
				break;
			case 's':
				texte[i] = 'h';
				break;
			case 't':
				texte[i] = 'g';
				break;
			case 'u':
				texte[i] = 'f';
				break;
			case 'v':
				texte[i] = 'e';
				break;
			case 'w':
				texte[i] = 'd';
				break;
			case 'x':
				texte[i] = 'c';
				break;
			case 'y':
				texte[i] = 'b';
				break;
			case 'z':
				texte[i] = 'a';
				break;

			// AUTRES

	    	case ' ':
				texte[i] = ',';
				break;
			case '1':
				texte[i] = '4';
				break;
			case '2':
				texte[i] = ':';
				break;
			case '3':
				texte[i] = '(';
				break;
			case '4':
				texte[i] = '5';
				break;
			case '5':
				texte[i] = '\"';
				break;
			case '6':
				texte[i] = '8';
				break;
			case '7':
				texte[i] = '=';
				break;
			case '8':
				texte[i] = '+';
				break;
			case '9':
				texte[i] = '*';
				break;
			case ',':
				texte[i] = '/';
				break;
			case '\'':
				texte[i] = '?';
				break;
			case '.':
				texte[i] = '\'';
				break;
			case '/':
				texte[i] = '9';
				break;
			case '?':
				texte[i] = '7';
				break;
			case '!':
				texte[i] = '.';
				break;
			case '*':
				texte[i] = ')';
				break;
			case '-':
				texte[i] = '6';
				break;
			case '+':
				texte[i] = '!';
				break;
			case '\"':
				texte[i] = '1';
				break;
			case '(':
				texte[i] = '-';
				break;
			case ')':
				texte[i] = ' ';
				break;
			case '=':
				texte[i] = '2';
				break;
			case ':':
				texte[i] = '3';
				break;
			default:
				texte[i] = '$';
				break;
		}

		i++;
	}

	printf("%s\n", texte);

	printf("===============================================================================\n\n");

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
		}

		else // Si erreur d'ouverture
		{
			printf("Erreur d'ouverture du fichier cryptage.txt !");  // Ecriture de l'erreur
		}

		fclose(fichier); // Fermeture du fichier
	}
}

void decryptage() // Fonction decryptage
{
	char texte[1000];
	char password[200];
	char texteDecrypt[1000];
	int nombre = 0, ret = 0;
	int i = 0, n = 0;
	int nombre3 = 0;	
	int nombre2 = 0;
	int a = 0, b = 1;
	int ascii = 0;
	int fichierDecryptage = 0;

	char alphabetMin[30] = "abcdefghijklmnopqrstuvwxyz\0";
	char alphabetMax[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\0";	
	char symboles[30] = "123456789 -!().\'\"?/*+=:,\0";

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
				printf("Entrez un chiffre pour décrypter (entre 0 et 250) : ");
				fgets(texte, sizeof texte, stdin); // Saisi nombre

				clean(texte); // Enlève le retour à la ligne

				ret = sscanf(texte, "%d", &nombre3);

				if(ret != 1) // Tant que ce n'est pas un nombre
				{
					printf("\n"); // Retour à la ligne
				}
			} while(ret != 1); // Tant que ce n'est pas un nombre
		} while(nombre3 < 0 || nombre3 > 250); // Tant que nombre différent de 0 ou 1

		while(i != nombre3)
		{
			if(i != nombre3)
			{
				nombre2 = a;

				a = a + b;

				i++;	
			}
			
			if(i != nombre3)
			{
				nombre2 = b;

				b = a + b;

				i++;
			}
		}

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

	while(texte[i] != '\0') // Tant que ce n'est pas la fin du texte
	{
		i++; // Incrémentation i
	}

	if(i < 10) // Si i inférieur à 10
	{
		printf("\t\t\t\t   ");
	}

	else if(i < 20 && i > 10) // Si i compris entre 10 et 20
	{
		printf("\t\t\t\t");
	}

	else if(i < 30 && i > 20) // Si i compris entre 20 et 30
	{
		printf("\t\t\t   ");
	}

	else if(i < 40 && i > 30) // Si i compris entre 30 et 40
	{
		printf("\t\t     ");
	}

	else if(i < 50 && i > 40) // Si i compris entre 40 et 50
	{
		printf("\t\t");
	}

	else if(i < 60 && i > 50) // Si i compris entre 50 et 60
	{
		printf("\t     ");
	}

	else if(i < 70 && i > 60) // Si i compris entre 60 et 70
	{
		printf("\t");
	}

	i = 0;

	while(texte[i] != '\0') // Tant que ce n'est pas la fin du texte
	{
		switch(texte[i]) // Vérification de la lettre
		{

			// MAJUSCULES

			case 'A':
				texte[i] = 'Z';
				break;
			case 'B':
				texte[i] = 'Y';
				break;
			case 'C':
				texte[i] = 'X';
				break;
			case 'D':
				texte[i] = 'W';
				break;
			case 'E':
				texte[i] = 'V';
				break;
			case 'F':
				texte[i] = 'U';
				break;
			case 'G':
				texte[i] = 'T';
				break;
			case 'H':
				texte[i] = 'S';
				break;
			case 'I':
				texte[i] = 'R';
				break;
			case 'J':
				texte[i] = 'Q';
				break;
			case 'K':
				texte[i] = 'P';
				break;
			case 'L':
				texte[i] = 'O';
				break;
			case 'M':
				texte[i] = 'N';
				break;
			case 'N':
				texte[i] = 'M';
				break;
			case 'O':
				texte[i] = 'L';
				break;
			case 'P':
				texte[i] = 'K';
				break;
			case 'Q':
				texte[i] = 'J';
				break;
			case 'R':
				texte[i] = 'I';
				break;
			case 'S':
				texte[i] = 'H';
				break;
			case 'T':
				texte[i] = 'G';
				break;
			case 'U':
				texte[i] = 'F';
				break;
			case 'V':
				texte[i] = 'E';
				break;
			case 'W':
				texte[i] = 'D';
				break;
			case 'X':
				texte[i] = 'C';
				break;
			case 'Y':
				texte[i] = 'B';
				break;
			case 'Z':
				texte[i] = 'A';
				break;

			// MINUSCULES
			
			case 'a':
				texte[i] = 'z';
				break;
			case 'b':
				texte[i] = 'y';
				break;
			case 'c':
				texte[i] = 'x';
				break;
			case 'd':
				texte[i] = 'w';
				break;
			case 'e':
				texte[i] = 'v';
				break;
			case 'f':
				texte[i] = 'u';
				break;
			case 'g':
				texte[i] = 't';
				break;
			case 'h':
				texte[i] = 's';
				break;
			case 'i':
				texte[i] = 'r';
				break;
			case 'j':
				texte[i] = 'q';
				break;
			case 'k':
				texte[i] = 'p';
				break;
			case 'l':
				texte[i] = 'o';
				break;
			case 'm':
				texte[i] = 'n';
				break;
			case 'n':
				texte[i] = 'm';
				break;
			case 'o':
				texte[i] = 'l';
				break;
			case 'p':
				texte[i] = 'k';
				break;
			case 'q':
				texte[i] = 'j';
				break;
			case 'r':
				texte[i] = 'i';
				break;
			case 's':
				texte[i] = 'h';
				break;
			case 't':
				texte[i] = 'g';
				break;
			case 'u':
				texte[i] = 'f';
				break;
			case 'v':
				texte[i] = 'e';
				break;
			case 'w':
				texte[i] = 'd';
				break;
			case 'x':
				texte[i] = 'c';
				break;
			case 'y':
				texte[i] = 'b';
				break;
			case 'z':
				texte[i] = 'a';
				break;

			// AUTRES

			case '3':
				texte[i] = ':';
				break;
			case '2':
				texte[i] = '=';
				break;
			case ' ':
				texte[i] = ')';
	    		break;
	    	case '-':
	    		texte[i] = '(';
	    		break;
	    	case '1':
	    		texte[i] = '\"';
	    		break;
	    	case '!':
	    		texte[i] = '+';
	    		break;
	    	case '6':
	    		texte[i] = '-';
	    		break;
	    	case ')':
	    		texte[i] = '*';
	    		break;
	    	case '.':
	    		texte[i] = '!';
	    		break;
	    	case '7':
	    		texte[i] = '?';
	    		break;
	    	case '9':
	    		texte[i] = '/';
	    		break;
	    	case '\'':
	    		texte[i] = '.';
	    		break;
	    	case '?':
	    		texte[i] = '\'';
	    		break;
	    	case '/':
	    		texte[i] = ',';
	    		break;
	    	case '*':
	    		texte[i] = '9';
	    		break;
	    	case '+':
	    		texte[i] = '8';
	    		break;
	    	case '=':
	    		texte[i] = '7';
	    		break;
	    	case '8':
	    		texte[i] = '6';
	    		break;
	    	case '\"':
	    		texte[i] = '5';
	    		break;
	    	case '5':
	    		texte[i] = '4';
	    		break;
	    	case '(':
	    		texte[i] = '3';
	    		break;
	    	case ':':
	    		texte[i] = '2';
	    		break;
	    	case '4':
	    		texte[i] = '1';
	    		break;
	    	case ',':
	    		texte[i] = ' ';
	    		break;
		}

		i++;
	}

	printf("%s\n", texte);

	printf("===============================================================================\n\n");

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
