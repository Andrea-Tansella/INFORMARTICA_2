
/** ****************************************************************************************
* \mainpage esercizi File_struct>
*
* @brief inserire una breve descrizione del progetto
* 
* @author Andrea Tansella
* @date <01/12/22> 
*/


#include <stdio.h>//utilizzato per imput e output
#include<string.h>//utilizzo funzioni stringhe

#define V 5
#define C 20

struct s_data
{
	int giorno;
	char mese [C];
	int anno;
}typedef data;

struct s_alunno
{
	int matricola; // n° matricola alunno
	char cognome[C];// cognome dell'alunno
	data nascita; // giorno,mese,anno dell'alunno
	int voti [V];// voti dell'alunno
}typedef alunno;

void inserisciRecord(char [], int );
void stampaFile(char []);
void ricercaCogn(char [],char []);
int ricercaRecord(char [], char []);
int main()
{
	int  nRecord,a;
	char nomefile[]="structT.txt ";
	char cogn[C];
	
	
	
	printf("inserisci quanti record vuoi scrivere\n");
	scanf("\n%d",&nRecord);
	
 	inserisciRecord(nomefile,nRecord);
	 	
//	stampaFile(nomefile);
	
	printf("\nquale cognome vuoi cercare?\n");
	scanf("%s",cogn);
	a=ricercaRecord(nomefile,cogn);
	
	
	
	
	
	
	
	
	
	
	
}


 void inserisciRecord(char filename[], int numRecord)
{
		int i,j;
		alunno buffer;
		FILE*pf;
		pf=fopen(filename,"ab");
		if(pf!=0)
		{
			for(i=0;i<numRecord;i++)
			{
				printf("inserisci la matricola\n");
				scanf("\n%d",&buffer.matricola);
				printf("\ninserisci il cognome\n");				// inserimento degli elementi all'interno dello struct
				scanf("\n%s",buffer.cognome);
				printf("\ninserisci il giorno,il mese e anno di nascita\n");
				scanf("%d %s %d",&buffer.nascita.giorno,buffer.nascita.mese,&buffer.nascita.anno);
				
				for(j=0;j<V;j++)
				{
					printf("\ninserisci i voti\n");
					scanf("%d",&buffer.voti[j]);	
				}
				fwrite(&buffer,sizeof(alunno),1,pf);
			}	
				fclose(pf);
		}
		else
			printf("il file non puo esere aperto");
}
		
void stampaFile(char fileName[])
{
		int j;
		alunno buffer; 
		FILE*pf;
		pf=fopen(fileName,"rb");
		if(pf!=0)
		{
			while(!feof(pf))
			{
				printf("\n\nmatricola\n:%d\n", buffer.matricola);
				printf("\ncognome:%s\n", buffer.cognome);
				printf("\ngiorno di nascita%d\n", buffer.nascita.giorno);	// stampa degli elementi all'interno dell'struct
				printf("\nmese di nascita:%s\n", buffer.nascita.mese);
				printf("\nanno di nascita:%d\n", buffer.nascita.anno);
				for(j=0;j<V;j++)
					{
						printf("\nvoti:%d\t",buffer.voti[j]);
					}
				fread(&buffer,sizeof(alunno),1,pf);
			}
			fclose(pf);
		}
			else
		printf("il file non puo esere aperto");
}


int ricercaRecord(char fileName[], char cognome[])
{
		int i,j, eta, media=0,n;
		alunno buffer;
		FILE*pf;
		pf=fopen(fileName,"rb");
		if(pf!=0)
		{
				while(!feof(pf))
				{
					n=fread(&buffer,sizeof(alunno),1,pf);
					n=strcmp(cognome,buffer.cognome);
					if(n==0)
					{
						printf("%s",buffer.cognome);
						printf("\t");
						eta=2022-buffer.nascita.anno;
						printf("eta'alunno:%d",eta);
						for(j=0;j<V;j++)
							{
								media+=j;
							}
							media=media/V;
							printf("la media:",media);
					}
				}fclose (pf);
		}
		else
			printf("errore in apertura file");
}
