#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <dirent.h>

typedef struct user{
	double id;
	char firstname[30];
	char lastname[30];
	char login[60];
	char pasword[30];
	char mail[30];

}user;

typedef struct
{
	int code;
	char nom[30];
	int quantite;
	float prix;
    float prixTTC;

}produit;

FILE *P,*F,*RE;
char box[30],N[]={'\n'},L[1],box2[30],nam[60];
int i,j,k,tmp,dim=0,dim2=0,test;
char tim[26];
float Price=0;

user R;

void green()
{
	printf("\033[0;32m");
}

void red()
{
	printf("\033[1;31m");
}

void yellow()
{
	printf("\033[1;33m");
}

void blue()
{
	printf("\033[0;34m");
}

void reset()
{
	printf("\033[0m");
}

void templive(char tim[]) //procédure permet de structurer la date et le dans dans un string aray passé dans les parametre .
{
	time_t my_time;
	int ti;
	struct tm * timeinfo;
	time (&my_time);
	timeinfo = localtime (&my_time);

	sprintf(tim,"%02d",timeinfo->tm_mday);
	strcat(tim,"-");

	ti=timeinfo->tm_mon+1;
	sprintf(box,"%02d",ti);
	strcat(tim,box);
	strcat(tim,"-");

	ti=timeinfo->tm_year+1900;
	sprintf(box,"%04d",ti);
	strcat(tim,box);
	strcat(tim,"  ");

	ti=timeinfo->tm_hour;
	sprintf(box,"%02d",ti);
	strcat(tim,box);
	strcat(tim,":");
	ti=timeinfo->tm_min;
	sprintf(box,"%02d",ti);
	strcat(tim,box);
	strcat(tim,":");
	ti=timeinfo->tm_sec;
	sprintf(box,"%02d",ti);
	strcat(tim,box);
	strcat(tim,"\0");
}

void Logo() // procédure qui desine un logo de pharmacie .
{
	templive(box2);
	yellow();
	printf(" %s\n",box2);
	green();
	printf("  \n\t\t\t                                   %c%c%c%c                 %c %c           \n",201,205,205,205,201,187);
	printf("  \t\t\t                                   %c",186);
	reset();
	printf(" Y O U'r            ");
	green();
	printf("%c %c               \n",186,186);
	printf("  \t\t\t                               %c%c%c%c%c%c%c%c%c%c%c%c%c        %c%c%c%c%c %c%c%c%c%c%c                             \n",205,205,205,205,206,205,205,205,205,205,205,205,205,201,205,205,205,205,188,200,205,205,205,187);
	printf("  \t\t\t                                   %c",186);
	reset();
	printf(" p   A   M   C  ");
	green();
	printf("%c%c%c%c%c %c%c%c%c%c%c                  \n",200,205,205,205,205,187,201,205,205,205,188);
	printf("  \t\t\t                                   %c",186);
	reset();
	printf("   H   R   A   Y    ");
	green();
	printf("%C %c    \n",186,186,186,219,16);
    printf("  \t\t\t                                                        %c %C                              \n",200,188);
    reset();
}

void welcom() // procédure qui fait un intro et un outro de programe  .
{
	system("cls");
	templive(box2);
	yellow();
	printf(" %s\n",box2);
	printf("\n\n\n\n\n\n\n\n\n\n");

    green();
	printf("  \n\t\t\t                                   %c%c%c%c                 %c %c           \n",201,205,205,205,201,187);
	printf("  \t\t\t                                   %c",186);
	reset();
	printf(" Y O U'r            ");
	green();
	printf("%c %c               \n",186,186);
	printf("  \t\t\t                               %c%c%c%c%c%c%c%c%c%c%c%c%c        %c%c%c%c%c %c%c%c%c%c%c                             \n",205,205,205,205,206,205,205,205,205,205,205,205,205,201,205,205,205,205,188,200,205,205,205,187);
	printf("  \t\t\t                                   %c",186);
	reset();
	printf(" p   A   M   C  ");
	green();
	printf("%c%c%c%c%c %c%c%c%c%c%c                  \n",200,205,205,205,205,187,201,205,205,205,188);
	printf("  \t\t\t                                   %c",186);
	reset();
	printf("   H   R   A   Y    ");
	green();
	printf("%C %c    \n",186,186,186,219,16);
    printf("  \t\t\t                                                        %c %C                              \n",200,188);
    yellow();
	printf("\n\n\n\n\n\n\n\n\n\n  \t\t\t                                                                                                  @outman.ouharri");
	reset();
	sleep(2);
}

int menu() //procédure qui affiche le menu des choix et retourne le choix choisie .
{
	system("cls");
	templive(box2);
	printf(" %s\n",box2);
	int choix;
    char op[5];

    printf("\n\n");
	do
	{
	test=1;
	printf("  \n\t\t\033[0;32m                                   %c%c%c%c                 %c %c           \n",201,205,205,205,201,187);
	printf("  \t\t                                   %c \033[0mY O U'r   \033[0;32m         %c %c               \n",186,186,186);
	printf("  \t\t                               %c%c%c%c%c%c%c%c%c%c%c%c%c        %c%c%c%c%c %c%c%c%c%c%c                             \n",205,205,205,205,206,205,205,205,205,205,205,205,205,201,205,205,205,205,188,200,205,205,205,187);
	printf("  \t\t                                   %c\033[0m p   A   M   C  \033[0;32m%c%c%c%c%c %c%c%c%c%c%c     \033[0m             \n",186,200,205,205,205,205,187,201,205,205,205,188);
	printf("  \t\t %C --------------------------- %c  \033[0;32m %c \033[0m  H   R   A   Y  \033[0;32m  %C %c  \033[0m  %c --------------------------- %c\n",17,219,186,186,186,219,16);
    printf("  \t\t%C                                                \033[0;32m       %c %C        \033[0m                           %c\n",30,200,188,30);
    printf("  \t\t|                                                                                             |\n");
    printf("  \t\t|                                                                                             |\n");
    printf("  \t\t|                         veuillez choisisez un numero selon votre choix:                     |\n");
    printf("  \t\t|                                                                                             |\n");
    printf("  \t\t|      \033[0;32m     %c\033[0m Ajouter  un  produit ---- (1)       \033[0;32m %c \033[0majouter plusieur produit - (2)           |\n",004,004);
    printf("  \t\t|                                                                                             |\n");
    printf("  \t\t|     \033[0;32m      %c \033[0mAfficher  les  produits - (3)       \033[0;32m %c \033[0mVendre un  produit ------- (4)           |\n",004,004);
    printf("  \t\t|                                                                                             |\n");
    printf("  \t\t|        \033[0;32m   %c \033[0mChercher un  produit ---- (5)       \033[0;32m %c \033[0mSuprrimer un produit ----- (6)           |\n",004,004);
    printf("  \t\t|                                                                                             |\n");
    printf("  \t\t|      \033[0;32m     %c \033[0mL'etat  de  stock ------- (7)       \033[0;32m %c \033[0mAlimentation de stock ---- (8)           |\n",004,004);
    printf("  \t\t|                                                                                             |\n");
    printf("  \t\t|        \033[0;32m   %c \033[0mStatitiques de vende ---- (9)       \033[0;32m %c \033[0mFaire  une  Note --------- (10)          |\n",004,004);
    printf("  \t\t|                                                                                             |\n");
    printf("  \t\t|                                                                                             |\n");
    printf("  \t\t|                                QUITER LE PROGRAME ---- (0)                                  |\n");
    printf("  \t\t|                                                                                             |\n");
    printf("  \t\t%c                                                                                             %c\n",31,31);
    printf("  \t\t %c ----------------------------------------------------------------------------------------- %c \n",17,16);
    printf("\n  \t\t\t %c Taper votre choix: ",5);
	gets(op);
	fflush(stdin);

	sscanf(op, "%d", &choix);
	fflush(stdin);

	for(i=0; i<strlen(op) ; i++) if( !isdigit(*(op+i)) ) test=0;

	if(choix<0 || choix>10 || test==0 )
	{
	    system("cls");
		printf("\n\t\t\aVEUILLER ENTRER UN CHOIX VALABLE !!! \n");
	}

	}while(choix<0 || choix>10 || test==0 ) ;

	return choix;

}

int menu2()
{
	do
	{
	test=1;
	printf("\n\n\n\t\t\t\t\t  %c ----------------------------------- %c\n",17,16);
	printf("\t\t\t\t\t%c                                         %c\n",30,30);
	printf("\t\t\t\t\t|  POUR RETOURNER AU  MENU --------- (1)  |\n");
	printf("\t\t\t\t\t|                                         |\n");
	printf("\t\t\t\t\t|  POUR CONTUNIEZ DANS VOTRE CHOIX - (2)  |\n");
	printf("\t\t\t\t\t|                                         |\n",31,31);
	printf("\t\t\t\t\t|  POUR FERMER  LA  SESION --------- (3)  |\n");
	printf("\t\t\t\t\t%c                                         %c\n",31,31);
	printf("\t\t\t\t\t  %c ----------------------------------- %c\n",17,16);

	printf("\n  \t\t\t\t\t %c Taper votre choix: ",5);
	fflush(stdin);
	gets(box);
	fflush(stdin);

	sscanf(box, "%d", &tmp);
	fflush(stdin);

	for(i=0; i<strlen(box) ; i++) if( !isdigit(*(box+i)) ) test=0;

	if(tmp<1 || tmp>3 || test==0 )
	{
	system("cls");
	printf("\n\t\t\a VEUILLER ENTRER UN CHOIX VALABLE !!! \n");
	}

	}while(tmp<1 || tmp>3 || test==0 ) ;

	return tmp;
}

void ajouterProduit(produit *p) //procédure qui permet de prendre les information d'un produit .
{
	produit D;//,*p=T,D;

    F = fopen("dim.txt","r");
	if( F!=NULL ) fscanf(F,"%d",&dim);
	fclose(F);

	printf("\n\n\tENTER LE NOM DE PRODUIT:\n");
	printf("\n\t*****************************************************************\n");
	printf("\t***                                                           ***");
	printf("\n\t                    ");
	fflush(stdin);
	gets(p->nom);
	printf("\t***                                                           ***");
	printf("\n\t*****************************************************************\n");
	again:
	printf("\n\n\tENTER LE CODE DE PRODUIT:\n");
	printf("\n\t*****************************************************************\n");
	printf("\t***                                                           ***");
	printf("\n\t                    ");
	fflush(stdin);
	scanf("%d",&p->code);

	P=fopen("Produit.bin","rb");

	if( P!=NULL )
	while( !feof(P) )
	{
		fflush(stdin);
		fread(&tmp,sizeof(int),1,P); //1- sizeof( nom de produit );
	    fread(&box,1,tmp,P); //2- nom de produit
	    strncpy(D.nom,box,tmp);
	    fread(&D.code,sizeof(int),1,P); //3- code de produit
	    fread(&D.prix,sizeof(int),1,P); //4- prix de produit
	    fread(&D.quantite,sizeof(int),1,P); //5-quantite de produit
	    fread(&D.prixTTC,sizeof(int),1,P); //6-prix ttc de produit
	    fread(&L,1,1,P);//7- retoure a la ligne

	    if( p->code==D.code )
	    {
	    	system("cls");
	    	Logo();
	    	printf("\n\n\tLE CODE (%d) EST CELUI DE PRODUIT -%s- VEUILLER ENTRER UN CODE VALABLE ! (try again): ",D.code,D.nom);
	    	goto again;
		}

	}
	fclose(P);

	printf("\t***                                                           ***");
	printf("\n\t*****************************************************************\n");
	printf("\n\n\tENTER LE PRIX DE PRODUIT:\n");
	printf("\n\t*****************************************************************\n");
	printf("\t***                                                           ***");
	printf("\n\t                    ");
	fflush(stdin);
	scanf("%f",&p->prix);
	printf("\t***                                                           ***");
	printf("\n\t*****************************************************************\n");
	printf("\n\n\tENTER LA QUANTITE DE PRODUIT:\n");
	printf("\n\t*****************************************************************\n");
	printf("\t***                                                           ***");
	printf("\n\t                    ");
	fflush(stdin);
	scanf("%d",&p->quantite);
	printf("\t***                                                           ***");
	printf("\n\t*****************************************************************\n");
	p->prixTTC=(p->prix+(p->prix*15)/100);
	(dim)++;
	F = fopen("dim.txt","w");
	fprintf(F,"%d",dim);
	fclose(F);

	//printf("\n\t\t\tDONE .");sleep(1);printf(" .");sleep(1);printf(" .");sleep(1);printf(" .");sleep(1);printf(" .");sleep(1);printf(" .");sleep(1);printf(" .");sleep(1);printf(" .");sleep(1);printf(" .");


}

void EngistrerProduit(produit p[]) //procédure qui permet d'enregistre des produit dans un fichier binaire .
{
	F = fopen("dim.txt","r");
	if( F!=NULL ) fscanf(F,"%d",&dim);
	fclose(F);

	P=fopen("Produit.bin","ab");

	for(i=0 ; i<dim ; i++)
	{
		tmp=strlen(p[i].nom)+1;
		strcat(p[i].nom,"\0");
		fwrite(&tmp,sizeof(int),1,P); //1- sizeof( nom de produit );
		fwrite(&p[i].nom,1,tmp,P);  //2- nom de produit
		fwrite(&p[i].code,sizeof(int),1,P); //3- code de produit
		fwrite(&p[i].prix,sizeof(int),1,P); //4- prix de produit
		fwrite(&p[i].quantite,sizeof(int),1,P); //5-quantite de produit
		p[i].prixTTC=p[i].prix+p[i].prix*15/100;
		fwrite(&p[i].prixTTC,sizeof(int),1,P); //6-prix ttc de produit
		fwrite(&N,1,1,P);//7- retoure a la ligne
	}
	fclose(P);

}

void RestaurerProduit(produit T[]) //procédure qui permet de recuperer les produit apartir d'un fichier binaire .
{
	F = fopen("dim.txt","r");
    produit *p=T,D;
	if( F!=NULL ) fscanf(F,"%d",&dim);
	fclose(F);

	P=fopen("Produit.bin","rb"); i=0;

	if( P!=NULL )
	while( !feof(P) && i<dim)
		{
			fflush(stdin);
			fread(&tmp,sizeof(int),1,P); //1- sizeof( nom de produit );
	    	fread(&box,1,tmp,P); //2- nom de produit
	    	strncpy(T[i].nom,box,tmp);
	    	fread(&T[i].code,sizeof(int),1,P); //3- code de produit
	    	fread(&T[i].prix,sizeof(int),1,P); //4- prix de produit
	    	fread(&T[i].quantite,sizeof(int),1,P); //5-quantite de produit
	    	fread(&T[i].prixTTC,sizeof(int),1,P); //6-prix ttc de produit
	    	fread(&L,1,1,P);//7- retoure a la ligne
	    	i++;
	     }

	fclose(P);
}

void afficherProduit(produit p, int dim) //procédure qui permet d'afficher un seule ou plusieure produit passé au parametre .
{
	if( dim==0)
	{

		printf("\n\n\n\t\t\t ------------------------------------------------------------------------------------");
	    printf("\n\t\t\t |                     |                  |                  |                      |");
	    printf("\n\t\t\t |     NOM PRODUIT     |   CODE PRODUIT   |   PRIX PRODUIT   |   QUANTITE PRODUIT   |");
	    printf("\n\t\t\t |                     |                  |                  |                      |");
	    printf("\n\t\t\t ------------------------------------------------------------------------------------");
    }


	    	printf("\n\t\t\t |                     |                  |                  |                      |");
	    	printf("\n\t\t\t |");
	    	if( strlen((p.nom))%2==0 ) { for(i=0 ; i<round((21-strlen(p.nom))/2 +0.2); i++) printf(" "); printf("%s",p.nom); for(i=0 ; i<=round((21-strlen(p.nom))/2 +0.2) ; i++) printf(" "); printf("|"); }
	    	else { for(i=0 ; i<(21-strlen(p.nom))/2; i++) printf(" "); printf("%s",p.nom); for(i=0 ; i<(21-strlen(p.nom))/2 ; i++) printf(" "); printf("|"); }

			sprintf(box,"%010d",p.code);
	    	for(i=0 ; i<4 ; i++) printf(" "); printf("%s",box); for(i=0 ; i<4 ; i++) printf(" "); printf("|");
	    	sprintf(box,"%.3f",p.prix);

	    	if( strlen(box)%2==0 ) { for(i=0 ; i<round(((18-strlen(box))/2) +0.2) ; i++) printf(" "); printf("%.3f",p.prix); for(i=0 ; i< round(((18-strlen(box))/2) +0.2) ; i++) printf(" "); printf("|"); }
	    	else { for(i=0 ; i<=round(((18-strlen(box))/2) +0.2) ; i++) printf(" "); printf("%.3f",p.prix); for(i=0 ; i< round(((18-strlen(box))/2) +0.2) ; i++) printf(" "); printf("|"); }
			sprintf(box,"%04d",p.quantite);

	    	for(i=0 ; i<9 ; i++) printf(" "); printf("%04d",p.quantite); for(i=0 ; i<9 ; i++) printf(" "); printf("|");
	    	printf("\n\t\t\t ------------------------------------------------------------------------------------");


}

float acheterProduit(produit T[] , int tesT , int *recu) //fonction qui permet de vendre un fichier et stocker l'historique dans un ficher binare et retourner le prix.
{
	int code;
	
	system("cls");
	Logo();
	
	float pre;
	int test=0,TMP,quan; i=j=k=0;
	char tir[]={"---------------------------------------------------------------------"};
	strcpy(R.login,"outman.ouharri");

	if( tesT != 2)
	{
		printf("\n\n\n\t\t %c ENTRER LE CODE DE PRODUIT : ",5);
		scanf("%d",&code);
		
		agaiN:
		i=j=k=0;
		*recu=0;
		test=0;
			
	F = fopen("dim.txt","r");
	if( F!=NULL ) fscanf(F,"%d",&dim);
	fclose(F);

	if( dim<=0 )  printf("\n\n\tACUN PRODUIT AU STOCK !");
	else
	{
		while( k<=dim && test!=1 )
		{
			if( T[k].code==code )
			{
				test=1;
				TMP=k;
				printf("\n\n\n\t\t\t ENTRER LA QUANTITE DE PRODUIT -%s- A VENDRE  (code : %d) : ",T[k].nom,code);
				scanf("%d",&quan);

				if( T[k].quantite==0 )
				{
					*recu=1;
					printf("\n\n\n\t\t\t IL NE RESTE AUCUN -%s- DANS LE STOCK (code : %d) !",T[k].nom,code);	
				} 
			    else if( (T[k].quantite-quan) < 0 )
				{
					*recu=1;
					printf("\n\n\n\t\t\t IL NE RESTE Que %d de produit -%s- DANS LE STOCK (code : %d) !",T[k].quantite,T[k].nom,code);
				}
				else
				{
					(T[k].quantite)-=quan;
					strcpy(box2,T[k].nom);

					j=1;
					dim2=0;
					P = fopen("dimhisto.txt","r");
					if( P!=NULL ) fscanf(P,"%d",&dim2);
					fclose(P);

					dim2++;

					P = fopen("dimhisto.txt","w");
					fprintf(P,"%d",dim2);
					fclose(P);

					templive(tim);
					
					F=fopen("historique.bin","ab");

					tmp=strlen(T[k].nom)+1;
					strcat(T[k].nom,"\0");
					fwrite(&tmp,sizeof(int),1,F);
					fwrite(&T[k].nom,1,tmp,F);
             	    fwrite(&T[k].code,sizeof(int),1,F);
             	    fwrite(&quan,sizeof(int),1,F);
             	    T[k].prixTTC=T[k].prix+T[k].prix*15/100;
					fwrite(&T[k].prixTTC,sizeof(float),1,F);  // prix totale paye

					tmp=strlen(R.login);
					fwrite(&tmp,sizeof(int),1,F);
					fwrite(&R.login,1,tmp,F);

					tmp=strlen(tim);
					fwrite(&tmp,sizeof(int),1,F);
					fwrite(&tim,1,tmp,F);
					fwrite(N,1,1,F);

					fclose(F);

					if( tesT==0 )
					{
						RE = fopen("recu.txt","w");

						templive(tim);

						fprintf(RE,"\n");
						fflush(stdin);
						fputs(tir,RE);
						fprintf(RE,"\n                     %s\n",tim);
						fputs(tir,RE);
                        fprintf(RE,"\n                   +---                 + +  ");
                        fprintf(RE,"\n                   ¦ Y O U'r            ¦ ¦   ");
                        fprintf(RE,"\n               ----+--------        +---- ++---+  ");
                        fprintf(RE,"\n                   ¦ p   A   M   C  +---- ++---+   ");
                        fprintf(RE,"\n                   ¦   H   R   A   Y    ¦ ¦   ");
                        fprintf(RE,"\n                                        + +   ");
                        fprintf(RE,"\n");
                        fflush(stdin);
						fputs(tir,RE);
						fprintf(RE,"\n");
	
						for(i=0 ; i<17 ; i++) fprintf(RE," ");
						
						fprintf(RE,"produit :       Quantité :     prix unit * Quant :   ");
						fprintf(RE,"\n");
						fflush(stdin);
						fputs(tir,RE);
						fprintf(RE,"\n");
						fprintf(RE,"\n");
						
						fflush(stdin);
						for(i=0 ; i<17 ; i++) fprintf(RE," ");
						fprintf(RE,"%s",T[TMP].nom);
						for(i=0 ; i<round(abs((16-strlen(T[TMP].nom)))) ; i++) fprintf(RE," ");
						
						fflush(stdin);
						sprintf(box,"%d",quan);
						fprintf(RE,"%d",quan);
						for(i=0 ; i<round(abs((15-strlen(box)))) ; i++) fprintf(RE," ");
						
						fflush(stdin);
						sprintf(box,"%d",T[TMP].prixTTC);
						sprintf(box,"%.4f",T[TMP].prixTTC);
						fprintf(RE,"%s",box);
						
						for(i=0 ; i<round(abs((10-strlen(box)))) ; i++) fprintf(RE," ");
						fprintf(RE,"* %d",quan);
						
						fprintf(RE,"\n");
						fprintf(RE,"\n");
												
	    				fclose(RE);
					}
					else if( tesT==1 )
					{
						RE = fopen("recu.txt","a");

						fflush(stdin);
						for(i=0 ; i<17 ; i++) fprintf(RE," ");
						fprintf(RE,"%s",T[TMP].nom);
						for(i=0 ; i<round(abs((16-strlen(T[TMP].nom)))) ; i++) fprintf(RE," ");
						
						fflush(stdin);
						sprintf(box,"%d",quan);
						fprintf(RE,"%d",quan);
						for(i=0 ; i<round(abs(15-strlen(box))) ; i++) fprintf(RE," ");
						
						fflush(stdin);
						sprintf(box,"%d",T[TMP].prixTTC);
						sprintf(box,"%.4f",T[TMP].prixTTC);
						fprintf(RE,"%s",box);
						
						for(i=0 ; i<round(abs((10-strlen(box)))) ; i++) fprintf(RE," ");
						fprintf(RE,"* %d",quan);
						
						fprintf(RE,"\n");
						fprintf(RE,"\n");
												
	    				fclose(RE);
					} 
				}
			}
				k++;
		}
	}	
			
	if( test==0 ){
					*recu=1;
					printf("\n\n\n\t\t\t\a LE PRODUIT QUE VOUS CHERCHER NE TROUVE PAS ! code:(%d)",code);
					printf("\n\n  \t\t\t\t    %c RESEYER : ( pour retourner en arriere taper (0) )",5);
					printf("\n\n\n\t\t %c ENTRER LE CODE DE PRODUIT : ",5);
					scanf("%d",&code);
					if( code!=0 )
					{
					  	goto agaiN;	
					}
			   	 }
			   	 
					else if( j==1 )
					{
						printf("\n\t\t\t LE produit - %s - code:(%d) est bien vendu !",box2,code);
						Price+=T[TMP].prixTTC*quan;
				    }
	}
	else 
	{
		RE = fopen("recu.txt","a");
		fputs(tir,RE);
		fprintf(RE,"\n");
		fprintf(RE,"\n");
		for(i=0 ; i<40 ; i++) fprintf(RE," ");
		fprintf(RE,"prix TTC TOTALE :  %.4f",Price);
		fprintf(RE,"\n");
		fputs(tir,RE);
		fclose(RE);	
		
		printf("\n\n\t\t\t\tLE PRIX TTC TOTALE A PAYER EST : %.4f DH (veuiller prendre le recu pour votre clien !)",Price);
		
	}

}

void triParPrix(produit p[]) //procédure qui permet de trier tous les produit selon le prix decroicont .
{
	produit TMP;
	F = fopen("dim.txt","r");
	fscanf(F,"%d",&dim);
	fclose(F);

	if( dim<0 )  printf("\n\n\tACUN PRODUIT AU STOCK !");
	else
	{

		do
		{
			test=1;
			for(i=0; i<dim-1 ;i++)
			{
				if(p[i].prix < p[i+1].prix)
				{
					TMP=p[i];
					p[i]=p[i+1];
					p[i+1]=TMP;
					test=0;
				}
			}
	    }while( test==0 );
	}
}

void triParAlphabet(produit p[]) //procédure qui permet de trier tous les produit selon l'ordre alphabetique decroicont .
{
	produit TMP;

	F = fopen("dim.txt","r");
	fscanf(F,"%d",&dim);
	fclose(F);

	if( dim<0 )  printf("\n\n\tACUN PRODUIT AU STOCK !");
	else
	{

		do
		{
			test=1;
			for(i=0; i<dim-1 ;i++)
			{
				if(strcmp(p[i].nom,p[i+1].nom)>0)
				{
					TMP=p[i];
					p[i]=p[i+1];
					p[i+1]=TMP;
					test=0;
				}
			}
	    }while( test==0 );
	}

}

void rechercheParCode(produit p[] , int code) //procédure qui permet de chercher un produit par son code .
{
	F = fopen("dim.txt","r");
	fscanf(F,"%d",&dim);
	fclose(F);

	test=0;

	for(i=0 ; i<dim ; i++)
	{
		if(p[i].code==code)
		{
			afficherProduit(p[i],0);
			test=1;
			break;
		}
	}
		if(test==0) printf("\n  \t\t\t %c Le code (%d) n'apartient a acun produit ! ",5,code);
}

void rechercherParQuantite(produit p[] , int quan) //procédure qui permet de chercher un produit par sa quantité .
{
	F = fopen("dim.txt","r");
	fscanf(F,"%d",&dim);
	fclose(F);
	test=0;

	for(i=0 ; i<dim ; i++)
	{
		if(p[i].quantite==quan)
		{
			afficherProduit(p[i],test);
			test++;
		}
	}
	if( test==0 ) printf("\n  \t\t\t %c AUCUN PRODUIT AU STOCK EST DE QUANTITE (%d)  ! ",5,quan);
}

void etatDuStock(produit p[]) //procédure qui permet d'afficher les produit dont la quantité est inferieure au 3 .
{
	F = fopen("dim.txt","r");
	fscanf(F,"%d",&dim);
	fclose(F);
	test=0;

	for(i=0 ; i<dim ; i++)
	{
		if(p[i].quantite<3)
		{
			if( test==0 ) 	printf("\n\n\n  \t\t\t\t\t %c LES PRODUIT AYANT LA QUANTITE INFERIEURE A 3  : ",5);
			afficherProduit(p[i],test);
			test++;
		}
	}
	if( test==0 ) 	printf("\n\n\n  \t\t\t\t\t %c TOUS LES PRODUIT SON EN BIEN ETAT  ! ",5);
}

void alimenterLeStock(produit p[]) //procédure qui permet de faire des modification de quantite dans un produit .
{
	int code,nv; test=0;

	F = fopen("dim.txt","r");
	fscanf(F,"%d",&dim);
	fclose(F);

	printf("\n\n\n  \t\t\t\t\t %c ENTRER LE CODE DE PRODUIT  : ",5);
	scanf("%d",&code);

	for(i=0 ; i<dim ; i++)
	{
		if(p[i].code==code)
		{
			printf("\n\n\n  \t\t\t\t\t %c ENTRER LA QUANTITE A AJOUTER POUR Le produit -%s- : ",5,p[i].nom);
			scanf("%d",&nv);
			p[i].quantite+=nv;
			test=1;
			break;
		}
	}
	if( test==0 ) printf("\n  \t\t\t %c Le code (%d) n'apartient a acun produit ! ",5,code);
}

void suprimerProduit(produit p[],int code) //procédure qui permet de chercher un produit par son code et le suprimer .
{
	F = fopen("dim.txt","r");
	fscanf(F,"%d",&dim);
	fclose(F);

	test=0;

	for(i=0 ; i<dim ; i++)
	{
		if(p[i].code==code)
		{
			for(j=i ; j<dim-1 ; j++)
			{
				p[j]=p[j+1];
			}

			test=1;

			dim--;

			F = fopen("dim.txt","w");
			fprintf(F,"%d",dim);
			fclose(F);

			break;
			break;
		}
		
		
	}
	if(test==0) printf("\n  \t\t\t %c Le code (%d) n'apartient a acun produit ! ",5,code);
	else printf("\n  \t\t\t %c Le Produit -%s- (code : %d) est bien supprimer  ! ",5,p[i].nom,code);
}

float vendeLyoum() //fonction qui permet d'afficher les produit vendu au joure actuel et le totale des prix vendu .
{
	char tim2[26];
	produit p; int quan;
	float s=0; test=0; j=0;

	F = fopen("dimhisto.txt","r");
	if( F!=NULL ) fscanf(F,"%d",&dim2);
	fclose(F);

	F=fopen("historique.bin","rb");
	test=0;

	if( F!=NULL ) {
    do
    {
		fread(&tmp,sizeof(int),1,F);
		fread(&p.nom,1,tmp,F);
		fread(&p.code,sizeof(int),1,F);
		fread(&quan,sizeof(int),1,F);
		fread(&p.prixTTC,sizeof(float),1,F);

		fread(&tmp,sizeof(int),1,F);
		fread(&R.login,1,tmp,F);

		fread(&tmp,sizeof(int),1,F);
		fread(&tim,1,tmp,F);
		fread(N,1,1,F);

		templive(tim2);


		if( !strncmp(tim,tim2,10) )
		{
		  s+=p.prixTTC;
		  if( j==0)
		  {

			printf("\n\n\n\t\t -------------------------------------------------------------------------------------------------------------------------");
		    printf("\n\t\t |                     |                  |                  |              |                        |                    |");
		    printf("\n\t\t |     NOM PRODUIT     |   CODE PRODUIT   |  PRIX TOTAL TTC  |   QUANTITE   | DATE ET HEURE DE VENDE |    NOM VENDEUR     |");
		    printf("\n\t\t |                     |                  |                  |              |                        |                    |");
		    printf("\n\t\t -------------------------------------------------------------------------------------------------------------------------");

		  }
            printf("\n\t\t |                     |                  |                  |              |                        |                    |");
	    	printf("\n\t\t |");

		    if( strlen((p.nom))%2==0 ) { for(i=0 ; i<round((21-strlen(p.nom))/2 +0.2); i++) printf(" "); printf("%s",p.nom); for(i=0 ; i<=round((21-strlen(p.nom))/2 +0.2) ; i++) printf(" "); printf("|"); }
	    	else { for(i=0 ; i<(21-strlen(p.nom))/2; i++) printf(" "); printf("%s",p.nom); for(i=0 ; i<(21-strlen(p.nom))/2 ; i++) printf(" "); printf("|"); }

			sprintf(box,"%010d",p.code);
	    	for(i=0 ; i<4 ; i++) printf(" "); printf("%s",box); for(i=0 ; i<4 ; i++) printf(" "); printf("|");

	    	sprintf(box,"%.3f",p.prixTTC);
	    	if( strlen(box)%2==0 ) { for(i=0 ; i<round(((18-strlen(box))/2) +0.2) ; i++) printf(" "); printf("%.3f",p.prixTTC); for(i=0 ; i< round(((18-strlen(box))/2) +0.2) ; i++) printf(" "); printf("|"); }
	    	else { for(i=0 ; i<=round(((18-strlen(box))/2) +0.2) ; i++) printf(" "); printf("%.3f",p.prixTTC); for(i=0 ; i< round(((18-strlen(box))/2) +0.2) ; i++) printf(" "); printf("|"); }

			sprintf(box,"%05d",quan);
	    	if( strlen(box)%2==0 ) { for(i=0 ; i<round(((14-strlen(box))/2) +0.2) ; i++) printf(" "); printf("%05d",quan); for(i=0 ; i< round(((14-strlen(box))/2) +0.2) ; i++) printf(" "); printf("|"); }
	    	else { for(i=0 ; i<=round(((14-strlen(box))/2) +0.2) ; i++) printf(" "); printf("%05d",quan); for(i=0 ; i< round(((14-strlen(box))/2) +0.2) ; i++) printf(" "); printf("|"); }

	    	for(i=0 ; i<2 ; i++) printf(" "); printf("%s",tim); for(i=0 ; i<2 ; i++) printf(" "); printf("|");

	    	if( strlen(R.login)%2==0 ) { for(i=0 ; i<round(((20-strlen(R.login))/2) +0.2) ; i++) printf(" "); printf("%s",R.login); for(i=0 ; i< round(((20-strlen(R.login))/2) +0.2) ; i++) printf(" "); printf("|"); }
	    	else { for(i=0 ; i<=round(((20-strlen(R.login))/2) +0.2) ; i++) printf(" "); printf("%s",R.login); for(i=0 ; i< round(((20-strlen(R.login))/2) +0.2) ; i++) printf(" "); printf("|"); }
			sprintf(box,"%04d",p.quantite);

		  printf("\n\t\t -------------------------------------------------------------------------------------------------------------------------");
		  j++;
		  test=1;
		}
	}while( !feof(F) && j<=dim2 );

	fclose(F);
	
	if( test==1 )
	{
		strncpy(box,tim2,10);
		printf("\n\t\t |                                                           |                                                            |");
		printf("\n\t\t |                                                           | PRIX TOTALE DES PRODUIT VENDU LE %s :",box);
	
		sprintf(box,"%.4f",s);
		if( strlen(box)%2==0 ) { for(i=0 ; i<round(((14-strlen(box))/2) +0.2) ; i++) printf(" "); printf("%.4f",s); for(i=0 ; i< round(((14-strlen(box))/2) +0.2) ; i++) printf(" "); printf("|"); }
		else { for(i=0 ; i<=round(((14-strlen(box))/2) +0.2) ; i++) printf(" "); printf("%.4f",s); for(i=0 ; i< round(((14-strlen(box))/2) +0.2) ; i++) printf(" "); printf("|"); }
		printf("\n\t\t |                                                           |                                                            |");
		printf("\n\t\t -------------------------------------------------------------------------------------------------------------------------");
	}
	else printf("\n\t AUCUN PRODUIT VENDU AUJOURD'HUI !");
	}
	else printf("\n\t AUCUN PRODUIT VENDU AUJOURD'HUI !");
}

void historique() //procédure qui permet d'afficher les produit vendu depuit le marche du programe .
{
	produit p;
	test=0; j=0; i=0;
	int quan,bb;

	P = fopen("dimhisto.txt","r");
	if( P!=NULL ) fscanf(P,"%d",&dim2);
	fclose(P);

	F=fopen("historique.bin","rb");

	if( F!=NULL ){
    do
    {
		fread(&tmp,sizeof(int),1,F);
		fread(&p.nom,1,tmp,F);
		fread(&p.code,sizeof(int),1,F);
		fread(&quan,sizeof(int),1,F);
		fread(&p.prixTTC,sizeof(float),1,F);

		fread(&tmp,sizeof(int),1,F);
		fread(&R.login,1,tmp,F);

		fread(&tmp,sizeof(int),1,F);
		fread(&tim,1,tmp,F);
		fread(N,1,1,F);

		  if( j==0)
		  {

			printf("\n\n\n\t\t -------------------------------------------------------------------------------------------------------------------------");
		    printf("\n\t\t |                     |                  |                  |              |                        |                    |");
		    printf("\n\t\t |     NOM PRODUIT     |   CODE PRODUIT   |  PRIX UNIT- TTC  |   QUANTITE   | DATE ET HEURE DE VENDE |    NOM VENDEUR     |");
		    printf("\n\t\t |                     |                  |                  |              |                        |                    |");
		    printf("\n\t\t -------------------------------------------------------------------------------------------------------------------------");

		  }
            printf("\n\t\t |                     |                  |                  |              |                        |                    |");
	    	printf("\n\t\t |");

		    if( strlen((p.nom))%2==0 ) { for(i=0 ; i<round((21-strlen(p.nom))/2 +0.2); i++) printf(" "); printf("%s",p.nom); for(i=0 ; i<=round((21-strlen(p.nom))/2 +0.2) ; i++) printf(" "); printf("|"); }
	    	else { for(i=0 ; i<(21-strlen(p.nom))/2; i++) printf(" "); printf("%s",p.nom); for(i=0 ; i<(21-strlen(p.nom))/2 ; i++) printf(" "); printf("|"); }

			sprintf(box,"%010d",p.code);
	    	for(i=0 ; i<4 ; i++) printf(" "); printf("%s",box); for(i=0 ; i<4 ; i++) printf(" "); printf("|");

	    	sprintf(box,"%.3f",p.prixTTC);
	    	if( strlen(box)%2==0 ) { for(i=0 ; i<round(((18-strlen(box))/2) +0.2) ; i++) printf(" "); printf("%.3f",p.prixTTC); for(i=0 ; i< round(((18-strlen(box))/2) +0.2) ; i++) printf(" "); printf("|"); }
	    	else { for(i=0 ; i<=round(((18-strlen(box))/2) +0.2) ; i++) printf(" "); printf("%.3f",p.prixTTC); for(i=0 ; i< round(((18-strlen(box))/2) +0.2) ; i++) printf(" "); printf("|"); }

			sprintf(box,"%05d",quan);
	    	if( strlen(box)%2==0 ) { for(i=0 ; i<round(((14-strlen(box))/2) +0.2) ; i++) printf(" "); printf("%05d",quan); for(i=0 ; i< round(((14-strlen(box))/2) +0.2) ; i++) printf(" "); printf("|"); }
	    	else { for(i=0 ; i<=round(((14-strlen(box))/2) +0.2) ; i++) printf(" "); printf("%05d",quan); for(i=0 ; i< round(((14-strlen(box))/2) +0.2) ; i++) printf(" "); printf("|"); }

	    	for(i=0 ; i<2 ; i++) printf(" "); printf("%s",tim); for(i=0 ; i<2 ; i++) printf(" "); printf("|");

	    	if( strlen(R.login)%2==0 ) { for(i=0 ; i<round(((20-strlen(R.login))/2) +0.2) ; i++) printf(" "); printf("%s",R.login); for(i=0 ; i< round(((20-strlen(R.login))/2) +0.2) ; i++) printf(" "); printf("|"); }
	    	else { for(i=0 ; i<=round(((20-strlen(R.login))/2) +0.2) ; i++) printf(" "); printf("%s",R.login); for(i=0 ; i< round(((20-strlen(R.login))/2) +0.2) ; i++) printf(" "); printf("|"); }
			sprintf(box,"%04d",p.quantite);

		  printf("\n\t\t -------------------------------------------------------------------------------------------------------------------------");

		  j++;
		  test=1;

	}while( !feof(F) && !(j<dim2) );
	}else printf("\n\t AUCUN PRODUIT VENDU !!");

	fclose(F);
}

float moyenLyoum() //fonction qui permet d'afficher la moyenne des prix des produits vendus en journée courante .
{
	char tim2[26];
	produit p;
	float s; int quan;
	test=0; j=0; i=0;

	P = fopen("dimhisto.txt","r");
	if( P!=NULL ) fscanf(P,"%d",&dim2);
	fclose(P);

	F=fopen("historique.bin","rb");

	if( F!=NULL )
    do
    {
		fread(&tmp,sizeof(int),1,F);
		fread(&p.nom,1,tmp,F);
		fread(&p.code,sizeof(int),1,F);
		fread(&quan,sizeof(int),1,F);
		fread(&p.prixTTC,sizeof(float),1,F);

		fread(&tmp,sizeof(int),1,F);
		fread(&R.login,1,tmp,F);

		fread(&tmp,sizeof(int),1,F);
		fread(&tim,1,tmp,F);
		fread(N,1,1,F);

		templive(tim2);

		if( !strncmp(tim,tim2,10) )
		{
			s+=(p.prixTTC*quan);
			j++;
		}
		i++;
	}while( !feof(F) && !!(i<=dim2) );

	fclose(F);

	if( j==0 ) return 0; else return (s/j);

}

float maxLyoum(char boxx[]) //fonction qui permet d'afficher le Max des prix des produits vendus en journée courante .
{
	char tim2[26];
	produit p;
	float max=0;
	test=0; j=0;
	int quan;

	P = fopen("dimhisto.txt","r");
	if( P!=NULL ) fscanf(P,"%d",&dim2);
	fclose(P);

	F=fopen("historique.bin","rb");

	if( F!=NULL )
    do
    {
		fread(&tmp,sizeof(int),1,F);
		fread(&p.nom,1,tmp,F);
		fread(&p.code,sizeof(int),1,F);
		fread(&quan,sizeof(int),1,F);
		fread(&p.prixTTC,sizeof(float),1,F);

		fread(&tmp,sizeof(int),1,F);
		fread(&R.login,1,tmp,F);

		fread(&tmp,sizeof(int),1,F);
		fread(&tim,1,tmp,F);
		fread(N,1,1,F);

		templive(tim2);

		if( !strncmp(tim,tim2,10) )
		{
			if( max<p.prixTTC*quan )
			{
				max=p.prixTTC*quan;
				strcpy(boxx,R.login);
			}
	    }
	    j++;
	}while( !feof(F) && !(j>dim2) );
	else printf("\n\t AUCUN PRODUIT VENDU AUJOURD'HUI !");

	fclose(F);
	
	return max;
}

float minLyoum(char boxx[]) //fonction qui permet d'afficher le Min des prix des produits vendus en journée courante .
{
	char tim2[26];
	produit p;
	float min=maxLyoum(box2);
	test=0; j=0;
	int quan;

	P = fopen("dimhisto.txt","r");
	if( P!=NULL ) fscanf(P,"%d",&dim2);
	fclose(P);

	F=fopen("historique.bin","rb");

	if( F!=NULL )
    do
    {
		fread(&tmp,sizeof(int),1,F);
		fread(&p.nom,1,tmp,F);
		fread(&p.code,sizeof(int),1,F);
		fread(&quan,sizeof(int),1,F);
		fread(&p.prixTTC,sizeof(float),1,F);

		fread(&tmp,sizeof(int),1,F);
		fread(&R.login,1,tmp,F);

		fread(&tmp,sizeof(int),1,F);
		fread(&tim,1,tmp,F);
		fread(N,1,1,F);

		templive(tim2);

		if( !strncmp(tim,tim2,10) )
		{

			if( min>p.prixTTC )
			{
				min=p.prixTTC;
				strcpy(boxx,R.login);
			}
	    }

	    j++;

	}while( (!feof(F) && !(j>dim2)) );
	else printf("\n\t AUCUN PRODUIT VENDU AUJOURD'HUI !");

	fclose(F);

	return min;
}


int main()
{

	//SetConsoleCP(437);
    //SetConsoleOutputCP(437);

	F = fopen("dim.txt","r");
	fscanf(F,"%d",&dim);
	fclose(F);

	//produit *p=(produit*)malloc(sizeof(produit)*dim);
	produit p[100];
	welcom();
	RestaurerProduit(p);
	int choix=menu();

	do
	{
		switch( choix )
		{
			case 0 :
			{	
				welcom();
				sleep(1);
				exit(1);
				break;
			}
			case 1 :
			{
				
				system("cls");
				Logo();

				//p=(produit*)realloc(p,dim+1);
				ajouterProduit((p+dim));


				remove("produit.bin");
				EngistrerProduit(p);
				
				RestaurerProduit(p);

				sleep(1);
				tmp=menu2();
				if ( tmp==1 ) choix=menu();
				break;
			}
			case 2 :
			{
				system("cls");
				Logo();
				int DIM,D; k=0;

				F = fopen("dim.txt","r");
				fscanf(F,"%d",&D);
				fclose(F);

				printf("\n\n\t\t VEUILLER ENTRER LE NOMBRE DES ELEMENT QUE VOULER VOUS AJOUTER :");
				scanf("%d",&DIM);

				//p=(produit*)realloc(p,(dim+tmp));

				for(k=0 ; k<DIM ; k++)
				{
					system("cls");
					Logo();
					printf("\n  \t %c ENTRER LES INFORMATION DE PRODUIT N(%d): ",5,k+1);
					ajouterProduit((p+k+D));
				} 

				remove("produit.bin");
				EngistrerProduit(p);
				
				RestaurerProduit(p);

				sleep(1);
				tmp=menu2();
				if ( tmp==1 ) choix=menu();
				break;
			}
			case 3 :
			{
				system("cls");
				Logo();

				F = fopen("dim.txt","r");
				fscanf(F,"%d",&dim);
				fclose(F);

				if (dim==0) printf("\n\t AUCUN PRODUIT AU STOCK !! ");
				
				
				do
				{
				test=1;
				printf("\n\n\t\t\t\t\t\t  %c ------------------------------------------------------ %c\n",17,16);
				printf("\t\t\t\t\t\t%c                                                           %c\n",30,30);
				printf("\t\t\t\t\t\t|   POUR AFFICHER PAR ORDRE ALPHABETIQUE CROISSANT -- (1)   |\n");
				printf("\t\t\t\t\t\t|                                                           |\n");
				printf("\t\t\t\t\t\t|   POUR AFFICHER PAR ORDRE DES PRIX DECROISANT ----- (2)   |\n");
				printf("\t\t\t\t\t\t%c                                                           %c\n",31,31);
				printf("\t\t\t\t\t\t  %c ------------------------------------------------------ %c\n",17,16);

				printf("\n  \t\t\t\t\t\t %c Taper votre choix: ",5);
				fflush(stdin);
				gets(box);
				fflush(stdin);

				sscanf(box, "%d", &tmp);
				fflush(stdin);

				for(i=0; i<strlen(box) ; i++) if( !isdigit(*(box+i)) ) test=0;

				if(tmp<1 || tmp>2 || test==0 )
				{
	    			system("cls");
					printf("\n\n\t\t\t\t\a VEUILLER ENTRER UN CHOIX VALABLE !!! \n");
				}

				}while(tmp<1 || tmp>2 || test==0 ) ;
				
				if( tmp==1 )   triParAlphabet(p);
				
				if( tmp==2 )   triParPrix(p);
				
				system("cls");
				Logo();
				
				for (int i=0; i<dim; i++) afficherProduit(*(p+i),i);

				//historique();
				//vendeLyoum();

				sleep(1);
				tmp=menu2();
				if ( tmp==1 ) choix=menu();
				break;
			}
			case 4 :
			{
				system("cls");
				Logo();
				
				int rec;
				Price=0;


				acheterProduit(p,0,&rec);
				
				remove("produit.bin");
				EngistrerProduit(p);
				
				aGain : 
				do
				{
				test=1;
				printf("\n\n\t\t\t\t AJOUTER DES PRODUIT POUR CE CLIEN ? [oui (1) / non (2)] : ");
				printf("\n\n  \t\t\t\t\t\t %c Taper votre choix: ",5);
				fflush(stdin);
				gets(box);
				fflush(stdin);

				sscanf(box,"%d", &tmp);
				fflush(stdin);

				for(i=0; i<strlen(box); i++) if( !isdigit(*(box+i)) ) test=0;

				if(tmp<0 || tmp>2 || test==0 )
				{
	    			system("cls");
	    			Logo();
					printf("\n\n\t\t\t\t\a VEUILLER ENTRER UN CHOIX VALABLE !!! \n");
				}

				}while(tmp<0 || tmp>2 || test==0 );


				if( tmp==1 )
				{
					if(rec==0) acheterProduit(p,1,&rec);
					else if(rec==1) acheterProduit(p,0,&rec);
					remove("produit.bin");
					EngistrerProduit(p);
					goto aGain;
				}
				else if( tmp==2 ) acheterProduit(p,2,&rec);
			
				remove("produit.bin");
				EngistrerProduit(p);
				
				Price=0;

//				opendir("recu.txt");

				sleep(1);
				j=menu2();
				if ( j==1 ) choix=menu();
				break;
			}
			case 5:
			{
				system("cls");
				Logo();
				
				do
				{
				test=1;
				printf("\n\n\t\t\t\t\t\t  %c -------------------------------------- %c\n",17,16);
				printf("\t\t\t\t\t\t%c                                            %c\n",30,30);
				printf("\t\t\t\t\t\t|   POUR CHERCHER PAR CODE  TAPER ---- (1)   |\n");
				printf("\t\t\t\t\t\t|                                            |\n");
				printf("\t\t\t\t\t\t|   POUR CHERCHER PAR QUANTITE TAPER - (2)   |\n");
				printf("\t\t\t\t\t\t%c                                            %c\n",31,31);
				printf("\t\t\t\t\t\t  %c -------------------------------------- %c\n",17,16);

				printf("\n  \t\t\t\t\t\t %c Taper votre choix: ",5);
				fflush(stdin);
				gets(box);
				fflush(stdin);

				sscanf(box, "%d", &tmp);
				fflush(stdin);

				for(i=0; i<strlen(box) ; i++) if( !isdigit(*(box+i)) ) test=0;

				if(tmp<0 || tmp>2 || test==0 )
				{
	    			system("cls");
					printf("\n\n\t\t\t\t\a VEUILLER ENTRER UN CHOIX VALABLE !!! \n");
				}

				}while(tmp<1 || tmp>2 || test==0 ) ;

				switch(tmp)
				{
					case 1 :
					{
						system("cls");
						Logo();
						
						printf("\n  \t\t\t\t    %c ENTRER LE CODE : ",5);
						scanf("%d",&tmp);
						rechercheParCode(p,tmp);
						break;
					}
					case 2 :
					{	
						system("cls");
						Logo();
						printf("\n  \t\t\t\t    %c ENTRER LA QUANTITE : ",5);
						scanf("%d",&tmp);
						rechercherParQuantite(p,tmp);
						break;
					}
				}
				sleep(1);
				j=menu2();
				if ( j==1 ) choix=menu();
				break;
			}
			case 6 :
			{
				system("cls");
				Logo();
				
				RestaurerProduit(p);
				
				printf("\n\n  \t\t\t %c ENTRER LE CODE : ",5);
				scanf("%d",&tmp);

				suprimerProduit(p,tmp);

				remove("produit.bin");
				EngistrerProduit(p);

				sleep(1);
				tmp=menu2();
				if ( tmp==1 ) choix=menu();
				break;
			}
			case 7 :
			{
				system("cls");
				Logo();
				
				RestaurerProduit(p);

				etatDuStock(p);

				remove("produit.bin");
				EngistrerProduit(p);

				sleep(1);
				tmp=menu2();
				if ( tmp==1 ) choix=menu();
				break;
			}
			case 8 :
			{
				RestaurerProduit(p);

				alimenterLeStock(p);

				remove("produit.bin");
				EngistrerProduit(p);

				sleep(1);
				tmp=menu2();
				if ( tmp==1 ) choix=menu();
				break;
			}
			case 9 :
			{
				system("cls");
				Logo();
				
				float temps;
				
				RestaurerProduit(p);
				
				do
				{
				test=1;
				printf("\n\n\t\t\t\t\t  %c ----------------------------------------------------------------- %c\n",17,16);
				printf("\t\t\t\t\t%c                                                                      %c\n",30,30);
				printf("\t\t\t\t\t|  Le total des prix des produits vendus en journee courante --- (1)   |\n");
				printf("\t\t\t\t\t|                                                                      |\n");
				printf("\t\t\t\t\t|  La moyenne des prix des produits vendus en journee courante - (2)   |\n");
				printf("\t\t\t\t\t|                                                                      |\n");
				printf("\t\t\t\t\t|  Le Max des prix des produits vendus en journee courante ----- (3)   |\n");
				printf("\t\t\t\t\t|                                                                      |\n");
				printf("\t\t\t\t\t|  Le Min des prix des produits vendus en journee courante ----- (4)   |\n");
				printf("\t\t\t\t\t%c                                                                      %c\n",31,31);
				printf("\t\t\t\t\t  %c ----------------------------------------------------------------- %c\n",17,16);

				printf("\n  \t\t\t\t\t\t %c Taper votre choix: ",5);
				fflush(stdin);
				gets(box);
				fflush(stdin);

				sscanf(box, "%d", &tmp);
				fflush(stdin);

				for(i=0; i<strlen(box) ; i++) if( !isdigit(*(box+i)) ) test=0;

				if(tmp<0 || tmp>4 || test==0 )
				{
	    			system("cls");
					printf("\n\n\t\t\t\t\a VEUILLER ENTRER UN CHOIX VALABLE !!! \n");
				}

				}while(tmp<1 || tmp>4 || test==0 ) ;

				switch(tmp)
				{
					case 1 :
					{
						system("cls");
						Logo();

						vendeLyoum();

						sleep(1);
						tmp=menu2();
						if ( tmp==1 ) choix=menu();
						break;
					}
					case 2 :
					{
						printf("\n  \t\t\t\t\t\t %c La moyenne des prix des produits vendus en journee courante : %.4f DH ",5,moyenLyoum());

						sleep(1);
						tmp=menu2();
						if ( tmp==1 ) choix=menu();
						break;
					}
					case 3 :
					{
						//triParPrix();
						temps=maxLyoum(box2);

						printf("\n  \t\t\t\t\t\t %c Le MAX des prix des produits vendus en journee courante : %.4f DH \n",5,temps);
						printf("\n  \t\t\t\t\t\t                              %c  Vendu  par   :    -%s-",5,box2);

						sleep(1);
						tmp=menu2();
						if ( tmp==1 ) choix=menu();
						break;
					}
					case 4 :
					{
						triParPrix(p);

						printf("\n  \t\t\t\t\t\t %c Le MIN des prix des produits vendus en journee courante : %.4f DH ",5,minLyoum(box2));
						printf("\n  \t\t\t\t\t\t                              %c  Vendu  par   :    -%s-",5,box2);

						sleep(1);
						tmp=menu2();
						if ( tmp==1 ) choix=menu();
						break;
					}

				break;
				}
			}


		}











	}while( choix!=0 );

     welcom();
	 sleep(1);
	 exit(1);












//	for (int i=dim; i<dim+2; i++)	ajouterProduit(&p[i]);


//   EngistrerProduit(p);

//	system("cls");

//	menu();

//	for (int i=0; i<dim; i++) afficherProduit(p[i],i);
//	suprimerProduit(p,100);
	//alimenterLeStock(p);


	//rechercherParQuantite(p,98);

//	acheterProduit(p,15);//200
//	printf("\n quant   %d\n",p[2].quantite);
//	for (int i=0; i<dim; i++) afficherProduit(p[i],i);
  //  remove("produit.bin");
	//EngistrerProduit(p);
//    triParAlphabet(p);
//	vendeLyoum( );
//	for (int i=0; i<2; i++) afficherProduit(p[i],i);

	//sleep(1);



	//triParPrix();
	//afficherProduit();
	//menu();

}

