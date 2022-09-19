/**************************************
 *		Andrea Tansella 4H 15/09/22	  *
 *	Gestione matrici tramite vettori  *
 **************************************/
 
//LIBRERIE e COSTANTI
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 10
#define C 10
#define N 10

//DICHIARAZIONE FUNZIONI

void menu();
void caricaVettoreM(int [] ,int );
void caricaVettoreR(int [],int );
void caricaMatriceM(int [][C],int );
void caricaMatriceR(int [][C],int );
void stampaVettore(int [],int );
void stampaMatrice(int [][C],int );

//MAIN
int main()
{
	int v[N],m[R][C],s;
	
	srand(time(NULL));
	
	menu();
do
{
	printf("\nInserisci un numero: ");
	scanf("%d",&s);
	switch(s)
	{
		case 0:
			printf("Termina il programma");	
		break;
		
		case 1:
			caricaVettoreR(v,N);	
		break;
		
		case 2:
			caricaVettoreM(v,N);	
		break;
		
		case 3:
			caricaMatriceR(m,R);
		break;
		
		case 4:
			caricaMatriceM(m,R);
		break;
		
		case 5:
			printf("Vettore:");
			stampaVettore(v,N);
		break;
		
		case 6:
			printf("Matrice:\n");
			stampaMatrice(m,R);
		break;
		
		default:
			printf("INSERISCI UN NUMERO VALIDO");
	}
}while(s!=0);

	return 0;
}

//FUNZIONI 

void menu()
{
	printf("1: Carica vettore random\n");
	printf("2: Carica vettore manualmente\n");
	printf("3: Carica matrice random\n");
	printf("4: Carica matrice manualmente\n");	
	printf("5: Stampa vettore\n");	
	printf("6: Stampa matrice\n");
}

void caricaVettoreM( int v[],int x)
{
	int i,a;
	for(i=0;i<x;i++)
	{ 
		scanf("%d", &a);
		v[i]=a;
	}
}

void caricaVettoreR(int v[],int x)
{
	int i;
	for(i=0;i<x;i++)
	{ 
		v[i]=rand()%100;
	}
}

void caricaMatriceM(int m[][C],int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		caricaVettoreM(m[i],N);	
	}
}

void caricaMatriceR(int m[][C],int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		caricaVettoreR(m[i],N);	
	}
}

void stampaVettore(int v[],int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		printf(" %d,",v[i]);	
	}
	printf("\n");
}

void stampaMatrice(int m[][C],int x)
{
	int i;
	for(i=0;i<N;i++)
	{
		stampaVettore(m[i],N);	
	}
}
