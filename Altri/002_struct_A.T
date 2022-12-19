#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 20
#define V 5
//record per l data di nascita dell alunno
struct s_nascita
{
	int giorno;
	char mese;
	int anno;	
		
}typedef s_nascita

//record informazioni dell'alunno
struct s_alunno
{
	int matricola;
	char cognome[N];
	int voti[V];
	s_nascita data;

}typedef s_alunno

void inserimento(s_alunno*st1);
void stampa(s_alunno st1);


int main()
{
	srand(time(NULL))
	s_alunno st1;
	
	inserimento(&s_alunno);
	stampa(s_alunno);
	
	
		
	
}


void inserimento(s_alunno*st1)
{
	int i;
	printf("inserisci la matricola:");
	scanf("%d",&st1->matricola);
	printf("inserisci il cognome:");
	scanf("%s",st1->cognome);
	printf("voti alunno:")//inserimento dei voti dell alunno in modoi casuale
	for(i=0;i<N;i++)
		{
			st1->voti[i]=rand()%10+1;
		}
	printf("inserisci nascita:");
	scanf("%d",&st1->nascita.giorno);//inserimento della nascita dell'alunno
	scanf("%d",&st1->nascita.mese);
	scanf("%d",&st1->nascita.anno);
	
}

void stampa(s_alunno st1)
{
	printf("matricola:%d",st1.matricola);
	printf("cognome:%s",st1.cognome);
	printf("giorno di nascita:%d",st1.giorno);	
	printf("mese di nascita:%d",st1.mese);	
	printf("anno di nascita:%d",st1.anno);
	printf("voti");
	for(i=0;i<V;i++)
		printf("%d",st1.voti[i]);
}
