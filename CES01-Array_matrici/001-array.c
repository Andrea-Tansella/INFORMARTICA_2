/**************************************
 *		Andrea Tansella 4H 15/09/22	  *
 *	Gestione matrici tramite vettori  *
 **************************************/
 
//LIBRERIE e COSTANTI
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define R 10
#define C 10
#define MAX 100
#define MIN 0
#define N 10
//DICHIARAZIONE FUNZIONI

void menu();
void caricaVettoreM(int [] ,int );
void caricaVettoreR(int [],int );
void caricaMatriceM(int [][C],int );
void caricaMatriceR(int [][C],int );
void stampaVettore(int [],int );
void stampaMatrice(int [][C],int );
void ordinamentovett_cresc(int [],int );
void ordinamento_righe(int [] ,int );
void ordinamento_bubblesort(int v[]);
int cercamin(int [][C],int ,int );
int cercamax(int [][C],int ,int );
int ricercaingenua(int[],int ,int );

//MAIN
int main()
{
	int v[N],m[R][C],s,b,a,r;
	
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
		
		case 7:
			printf("inserisci la riga/n");
			scanf("%d",&a);
			printf("inserisci il numero da cercare\n");
			r=ricercaingenua(m[a],R ,b );
		
			
		break;
		
		case 8:
			ordinamento_bubblesort(v);
			
		break;
		
		case 9:
			printf("inserisci la riga/n");
			scanf("%d",&a);
			 ordinamento_righe(m[a],C);
			
		break;
		
		case 10:
			r=cercamax(m, R, C);
			printf(" il maggiore:%d\n",r);
			
		break;
		
			
		case 11:
			r=cercamin(m, R, C);
			printf(" il minore:%d\n",r);
			
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
	printf("7: ricerca ingenua\n");
	printf("8: ordinamento bubblesort\n");
	printf("9: ordinamento_righe\n");
	printf("10: trova maggiore\n");
	printf("11: trova minore\n");
}


//carica il vettore di dimensione x manualmente
void caricaVettoreM( int v[],int x)
{
	int i,a;
	for(i=0;i<x;i++)
	{ 
		scanf("%d", &a);
		v[i]=a;
	}
}
//carica il vettore di dimensione x in modo casuale
void caricaVettoreR(int v[],int x)
{
	int i;
	for(i=0;i<x;i++)
	{ 
		v[i]=rand()%100;
	}
}
//caica matrice manualmente
void caricaMatriceM(int m[][C],int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		caricaVettoreM(m[i],N);	
	}
}
//carica matrice in modo casuale
void caricaMatriceR(int m[][C],int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		caricaVettoreR(m[i],N);	
	}
}
// stampa il vettore
void stampaVettore(int v[],int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		printf(" %d,",v[i]);	
	}
	printf("\n");
}
//stampa il vettore
void stampaMatrice(int m[][C],int x)
{
	int i;
	for(i=0;i<N;i++)
	{
		stampaVettore(m[i],N);	
	}
}

//ordinamento del vettore dal minore al maggiore
void ordinamento_bubblesort(int v[])
{
	int temp,scambio=0,i;
	do{
		scambio=0;
		for(i=0;i<N-1;i++)
		{
			if(v[i]>v[i+1])
			{
				temp=v[i];
				v[i]=v[i+1];
				v[i+1]=temp;
				scambio=1;
			}
			
		}
		
	  }while(scambio==1);
	
	
}
//ordinamento della riga(vettore) di una matrice
void ordinamento_righe(int m[] ,int c)
{
	int i;
	for(i=0;i<c;i++)
	{
		ordinamento_bubblesort(m);
	}
	
}


//ricerca dell'elmento piu grande all'interno della matrice
int max(int mat[][C],int riga,int colonne)
{
	int i,j,m=INT_MIN;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			if(mat[i][j]>m)
			{
				m=mat[i][j];
			}
		}
	}
	
	return m;
}


//ricerca dell'elemento piu piccolo dela matrice
int min(int mat[][C],int riga,int colonne)
{
	int i,j,m=INT_MAX;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			if(mat[i][j]<m)
			{
				m=mat[i][j];
			}
		}
	}
	
	return m;
}
