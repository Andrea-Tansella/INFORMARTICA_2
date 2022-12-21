/** ****************************************************************************************
* \mainpage esercizi Andrea_filebinari.cpp
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
int numeroRecord(char []);

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
			case 6:
			a=numeroRecord(nomefile);
			printf("nel file ci sono %d record\n",a);	
		}

	}while(s!=0);
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

/** ****************************************************************************************
* @brief <inserimento degli elementi in un file di record>
* @param  (char fileName[], int numRecord)
* @retval <nessuna>
* @see 
*
* @author Andrea Tansella
* @data<01/12/2022> 
*/
void inserisciRecord(char filename[], int numRecord)
{
	int i,j;
	alunno buffer;						// dichiarazione interi ,puntatori,apertura del file e struct buffer
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
			fwrite(&buffer,sizeof(alunno),1,pf);// scrive dopra il record esistente
		}	
		fclose(pf);
	}
	else
		printf("il file non puo esere aperto");
}

/** ****************************************************************************************
* @brief stampa delle informazioni di un file di record>
* @param  (char fileName[])
* @author Andrea Tansella
* @data<01/12/2022> 
*/	
void stampaFile(char fileName[])
{
	int j,n;
	alunno buffer; 
	FILE*pf;						// dichiarazione interi ,puntatori,apertura del file e struct buffer
	pf=fopen(fileName,"rb");
	if(pf!=0)
	{
		while(!feof(pf))
		{
			n=fread(&buffer,sizeof(alunno),1,pf);//tira fuori il record dal file per lavorarci sopra 
			if(n>0)
			{
			printf("\n\nmatricola\n:%d\n", buffer.matricola);
			printf("\ncognome:%s\n", buffer.cognome);
			printf("\ngiorno di nascita:%d\n", buffer.nascita.giorno);	// stampa degli elementi all'interno dell'struct
			printf("\nmese di nascita:%s\n", buffer.nascita.mese);    
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

/** ****************************************************************************************
* @brief cerca il cognome richiesto dall'utente e ne stampa il cognome l'eta' e la media dei voti
* @param char fileName[], char cognaome)
*
* @author Andrea Tansella
* @data 01/12/22
*/
int ricercaRecord(char fileName[], char cognome[])
{
		int i,j, eta, media=0,n,a,b;
		alunno buffer;
		FILE*pf;						// dichiarazione interi ,puntatori,apertura del file e struct buffer
		pf=fopen(fileName,"rb");
		if(pf!=0)
		{
				while(!feof(pf))
				{
					b=0;
					n=fread(&buffer,sizeof(alunno),1,pf);//tira fuori il record dal file per lavorarci sopra 
					if(n>0)
					{
					
				    	if(strcmp(cognome,buffer.cognome)==0) //confronto cognome da cercare con il dato dello struct
				     	{
							printf("%s",buffer.cognome);
							printf("\t");
							eta=2022-buffer.nascita.anno;//calcolo data di nascita 
							printf("eta'alunno:%d",eta);
							for(j=0;j<V;j++)
								{
									b=media+buffer.voti[j];
								}
								media=b/V;
								printf("\tla media:%d",media);
						}
					    printf("\n");
					 }	
				}
				fclose (pf);
		}
		else
			printf("errore in apertura file");
}

/** ****************************************************************************************
* @brief stampa i dati del record che viene chiesto all'utente
* @param (char fileName[], int posizione)
*
* @author Andrea Tansella
* @data 01/12/22                                                           //il secondo non viene stampato correttamente
*/
int stampaRecord(char nomeFile[],int posizione)
{
	int i,media,j,n,f;
	FILE *pf;
	alunno buffer;					// dichiarazione interi ,puntatori,apertura del file e struct buffer
	pf=fopen(nomeFile,"rb");
	
	if(pf!=0)
	{
	
		f=fseek(pf,posizione*sizeof(alunno),SEEK_SET);//posiziona il puntatore all'inizio grazie al SEEK_SET
			n=fread(&buffer,sizeof(alunno),1,pf);		//tira fuori il record dal file per lavorarci sopra 

			printf("%d",buffer.matricola);
			for(j=0;j<V;j++)
			{
				media+=buffer.voti[j];
			}
			media=media/V;
			printf("\nMedia dello studente: %d\n",media);						//inserimento dati dello struct
			printf("\nCognome dello studente: %s\n",buffer.cognome );
			printf("\nData di nascita dello studente:%d %s %d", buffer.nascita.giorno, buffer.nascita.mese, buffer.nascita.anno);
			f=fseek(pf,posizione*sizeof(alunno),SEEK_SET);
		fclose(pf);
		return 0;
	}
	else
	{
		printf("\nIL FILE NON PUO' ESSERE APERTO!");
	}
}
/** ****************************************************************************************
* @brief <controlla la posizione del record chiesto all'utente e modifica gli errori
* @param (char fileName[], int posizione)
*																							NON FUNZIONA permette di modificare ma non salva
* @author Andrea Tansella
* @data 01/12/22
*/
int correggiRecord(char nomefile[], int posizione)
{
									
	alunno buffer;										//dichiarazione di un record
	int n,f,b,j,a;											//interi utilizzato per funzionare di funzioni di file
	FILE* pf;											
	pf=fopen(nomefile,"wb");									
	if(pf!=NULL)									
	{
		n=fseek(pf,posizione*sizeof(buffer),SEEK_SET);	//posiziona il puntatore all'inizio grazie al SEEK_SET
		if(n!=-1)							
		{
			f=fread(&buffer,sizeof(buffer),1,pf);		//tira fuori il record dal file per lavorarci sopra 
			if(f!=0)
			{
				a=stampaRecord(nomefile,posizione);
				printf("\ninserisci cognome:");
				scanf("%s", buffer.cognome);
				printf("inserisci data di nascita:\n");
				printf("giorno:");
				scanf("%d",&buffer.nascita.giorno);		//inserimento dati degli struct
				printf("mese:");
				scanf("%s",buffer.nascita.mese);
				printf("anno:");
				scanf("%d",&buffer.nascita.anno);
				printf("inserisci 8 voti:");
				for(int j=0;j<V;j++)
				{
					printf("voto:");
					scanf("%d",&buffer.voti[j]);			
				}                              
				printf("\n");
				n=fwrite(&buffer,sizeof(buffer),1,pf);//sovrascrive il record esistente con il record corretto
				fclose(pf);							//chude il file
				return b;
			}
				else														
				{
				printf("\nil file non puo'essere aperto\n");
				}
		}

	}
}
/** ****************************************************************************************
* @brief restituisce il numero di record
* @param (char fileName[])
*
* @author Andrea Tansella
* @data 01/12/22
*/
	int numeroRecord(char nomefile[])
{
	alunno buffer;										//dichiarazione di un record
	int a,r,b,record,y;									//dichiarazioni interi utilizzati								//grandezza del record		
	FILE* pf;	
	 y=sizeof(buffer);								
	pf=fopen(nomefile,"rb");							
	if(pf!=NULL)									
	{
		a=fseek(pf,0,SEEK_END);							//mette puntatore alla fine del file per poi calcolare la lunghezza 
		b=ftell(pf);									//restituisce la posizione corrente del file in byte
		record=b/y;									 	//divido b con la dimenzione di buffer per trovare il numero di record presenti
		fclose(pf);									
		return record;							
	}
	else														
	{
		printf("\nil file non puo'essere aperto\n");
	}
}
