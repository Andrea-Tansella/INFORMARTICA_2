

/** ****************************************************************************************
* \mainpage esercizi Filestruct_AndreaTansella
*
* @brief esecitazione su file binari
* 
* @author Andrea Tansella
* @date <01/12/22> 
*/
#include <stdio.h>//utilizzato per imput e output
#include <string.h>//utilizzo funzioni stringhe

#define V 8
#define C 20

struct s_data
{
	int giorno;
	char mese [C];
	int anno;
} typedef data;

struct s_alunno
{
	int matricola;  // n° matricola alunno
	char cognome[C];// cognome dell'alunno
	data nascita;   // giorno,mese,anno dell'alunno
	int voti [V];   // voti dell'alunno
} typedef alunno;

void menu(void);
void inserisciRecord(char [], int );
void stampaFile(char []);
void ricercaCogn(char [],char []);
int ricercaRecord(char [], char []);
int stampaRecord(char [],int );
int correggiRecord(char [], int );


int main()
{
	int  nRecord,a,s,f,c,pos,pos2;
	char nomefile[]="dati.dat";
	char cogn[C];
	
	do
{
		menu();
		scanf("%d",&s);
	
		switch(s)
		{
			
			case 1:
				printf("Inserisci quanti record vuoi scrivere\n");
				scanf("\n%d",&nRecord);
			 	inserisciRecord(nomefile,nRecord);
				break;	
				
			case 2:
				stampaFile(nomefile);
				break;
				
			case 3:
				printf("Quale cognome vuoi cercare?\n");
				scanf("%s",cogn);
				a=ricercaRecord(nomefile, cogn);	
					break;
				
			case 4:
				printf("Quale posizione del record vuoi stampare?\n");
				scanf("%d",&pos);
				f=stampaRecord(nomefile,pos);
				break;
				
			case 5:
				printf("Quale posizione del record vuoi correggere?\n");
				scanf("%d",&pos2);
				c=correggiRecord(nomefile,pos2);
				break;	
		
	/*	scanf("%d",&s);
		switch(s)
		{
		case 1:
			printf("Su quanti record vuoi lavorare? ");
			scanf("%d",&nRecord);
			inserisciRecord(nomeFile,numRecord);
		break;
		
		case 2:
			stampaFile(nomeFile);
		break
		;
		case 3:
			printf("Inserisci il cognome dello studente da cercare");
			scanf("%s",cognome);
			ricercaRecord(nomeFile,cognome);
		break;
	
		case 4:
			printf("Quale posizione del record vuoi stampare?");
			scanf("%d",&posizione);
			f1=stampaRecord(nomeFile,posizione);
		break;
		
		case 5:
			printf("Quale posizione del record vuoi correggere?");
			scanf("%d",&posizione2);
			f2=correggiRecord(nomeFile,posizione2);
		break;
		
		case 6:
			f3=numeroRecord(nomeFile);
		break;
		}*/
		}

	}
	while(s!=0);
}




void menu(void)
{

	printf("\n1:InserisciRecord");
	printf("\n2:StampaFile");
	printf("\n3:ricercaRecord:");
	printf("\n4:stampaRecord");
	printf("\n5:correggiRecord");
	printf("\n6:numeroRecord\n");
	printf("0:chiudi il programma\n");
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
	int j,n;
	alunno buffer; 
	FILE*pf;
	pf=fopen(fileName,"rb");
	if(pf!=0)
	{
		while(!feof(pf))
		{
			n=fread(&buffer,sizeof(alunno),1,pf);
			if(n>0)
			{
			printf("\n\nmatricola\n:%d\n", buffer.matricola);
			printf("\ncognome:%s\n", buffer.cognome);
			printf("\ngiorno di nascita:%d\n", buffer.nascita.giorno);	// stampa degli elementi all'interno dell'struct
			printf("\nmese di nascita:%s\n", buffer.nascita.mese);    // uguale pe la media
			printf("\nanno di nascita:%d\n", buffer.nascita.anno);
			for(j=0;j<V;j++)
				{
					printf("voti:%d\t",buffer.voti[j]);
				}
			printf("\n");
			}
		}
		fclose(pf);
	}
		else
	printf("il file non puo esere aperto");
}


int ricercaRecord(char fileName[], char cognome[])
{
		int i,j, eta, media=0,n,a;
		alunno buffer;
		FILE*pf;
		pf=fopen(fileName,"rb");
		if(pf!=0)
		{
				while(!feof(pf))
				{
					n=fread(&buffer,sizeof(alunno),1,pf);
					if(strcmp(cognome,buffer.cognome)==0)
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
							printf("\tla media:%d",media);
					}
				}
				fclose (pf);
		}
		else
			printf("errore in apertura file");
}


int stampaRecord(char nomeFile[],int posizione)
{
	int i,media,j,n,f;
	FILE *pf;
	alunno buffer;
	pf=fopen(nomeFile,"rb");
	
	if(pf!=0)
	{
	
		f=fseek(pf,posizione*sizeof(alunno),SEEK_SET);// posiziono sullo struct richiesto
			n=fread(&buffer,sizeof(alunno),1,pf);

			printf("%d",buffer.matricola);
			for(j=0;j<V;j++)
			{
				media+=j;
			}
			media=media/V;
			printf("Media dello studente:%d\n",media);
			printf("\nCognome dello studente:%s\n",buffer.cognome );
			printf("\nData di nascita dello studente:%d %s %d", &buffer.nascita.giorno, buffer.nascita.mese, &buffer.nascita.anno);
			printf("%d %s %d", &buffer.nascita.giorno, buffer.nascita.mese, &buffer.nascita.anno);
			f=fseek(pf,posizione*sizeof(alunno),SEEK_SET);
		fclose(pf);
		return 0;
	}
	else
	{
		return -1;
		printf("\nIL FILE NON PUO' ESSERE APERTO!");
	}
}

int correggiRecord(char nomeFile[], int posizione)
{
    int a,f,i;                          
	FILE *pf;
	alunno buffer;
	pf=fopen(nomeFile,"rb");
	
    if(pf!=0)                         
    {   
        f=fseek(pf,posizione*sizeof(alunno),SEEK_SET);

        if(f==0)
        {
            a=stampaRecord(nomeFile,posizione);
            printf("\n INSERISCI LE CORREZZIONI: \n");
            printf("Inserisci il numero di matricola: ");
			scanf("%d",&buffer.matricola);
			printf("Inserisci 5 voti dello studente: ");
				printf("\nInserisci il cognome dello studente: ");
			scanf("%s",buffer.cognome); 
			printf("\nInserisci il giorno di nascita dello studente: ");
			scanf("%d",&buffer.nascita.giorno); 
			printf("\nInserisci il mese di nascita dello studente: ");
			scanf("%s",buffer.nascita.mese);
			printf("\nInserisci l'anno di nascita dello studente: ");
			scanf("%d",&buffer.nascita.anno);
			for(i=0;i<V;i++) // ciclo inserimento voti
			{
				scanf("%d",&buffer.voti[i]);
			}
		
            f=fseek(pf,posizione*sizeof(alunno),SEEK_SET);   
            fwrite(&buffer,sizeof(alunno),1,pf); 
        }
        fclose(pf);
    }
    else
		printf("\nIL FILE NON PUO' ESSERE APERTO!");
}
	
	