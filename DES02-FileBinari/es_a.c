

/*** ****************************************************************************************
* mainpage esercizi Tansella_fileBinari.cpp
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
				if(a!=-1) {
					printf("nel file ci sono %d record\n",a);
				}	
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
			scanf("%d",&buffer.matricola);
			printf("\ninserisci il cognome\n");				// inserimento degli elementi all'interno dello struct
			scanf("%s",buffer.cognome);
			printf("\ninserisci il giorno,il mese e anno di nascita\n");
			scanf("%d%s%d",&buffer.nascita.giorno,buffer.nascita.mese,&buffer.nascita.anno);
			
			for(j=0;j<V;j++)
			{
				printf("\ninserisci i voti\n");
				scanf("%d",&buffer.voti[j]);	
			}
			fwrite(&buffer,sizeof(alunno),1,pf);// scrive sopra il record esistente
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
* @author Andrea Tansella							//tutto funzionante tranne calcolo della media
* @data 01/12/22
*/
int ricercaRecord(char fileName[], char cognome[])
{
		int i,j, eta,n,a;
		float media;
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
					
				    	if(strcmp(cognome,buffer.cognome)==0) //confronto cognome da cercare con il dato dello struct
				     	{
							printf("\n%s",buffer.cognome);
							printf("\t");
							eta=2022-buffer.nascita.anno;//calcolo data di nascita 
							printf("eta'alunno:%d",eta);
							for(j=0;j<V;j++)
								{
									
									media+=buffer.voti[j];
								}
								media=media/8.0;                   //per far diventare il valore media float(calcola con numeri decimale)
								printf("\tla media:%.1f",media);
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
* @data 01/12/22                                                           //tutto funzionante tranne calcolo media
*/
int stampaRecord(char nomeFile[],int posizione)
{
	int i,j,n,f;
	float media;
	FILE *pf;
	alunno buffer;					// dichiarazione interi ,puntatori,apertura del file e struct buffer
	pf=fopen(nomeFile,"rb");
	
	if(pf!=0)
	{
		f=fseek(pf,posizione*sizeof(alunno),SEEK_SET);//posiziona il puntatore all'inizio grazie al SEEK_SET
			n=fread(&buffer,sizeof(alunno),1,pf);		//tira fuori il record dal file per lavorarci sopra 

			printf("\nla matricola: %d",buffer.matricola);
			for(j=0;j<V;j++)
			{
				media+=buffer.voti[j];
			}
			media=media/8.0;					//per far diventare il valore media float(calcola con numeri decimale)
			printf("\nMedia dello studente: %.1f\n",media);						//inserimento dati dello struct
			printf("Cognome dello studente: %s",buffer.cognome );
			printf("\nData di nascita dello studente:%d %s %d\n", buffer.nascita.giorno, buffer.nascita.mese, buffer.nascita.anno);
			f=fseek(pf,posizione*sizeof(alunno),SEEK_SET);
		fclose(pf);
		return 0;
	}
	else
	{
		return -1;
	}
}
/** ****************************************************************************************
* @brief <controlla la posizione del record chiesto all'utente e modifica gli errori
* @param (char fileName[], int posizione)
*																						// non corregge il record.
* @author Andrea Tansella
* @data 01/12/22
*/
int correggiRecord(char nomefile[], int posizione)
{
	alunno buffer;										//dichiarazione di un record
	int n,f,b,j,a;
	a=stampaRecord(nomefile,posizione);	
	if(a==-1){									//se il record non esiste, usciamo restituendo -1
		return -1;
	}										//interi utilizzato per funzionare di funzioni di file
	FILE* pf;											
	pf=fopen(nomefile,"rb+");									
	if(pf!=0)									
	{
		n=fseek(pf,posizione*sizeof(buffer),SEEK_SET);	//posiziona il puntatore sul record da correggere
									
		printf("inserisci le correzioni");
		printf("inserisci la matricola\n");
		scanf("%d",&buffer.matricola);
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
			
	}
	else														
	{
		printf("\nil file non puo'essere aperto\n");
		return -1;
	}
	return 0;
}
/** ****************************************************************************************
* @brief restituisce il numero di record
* @param char fileName[] - nome del file da aprire
*
* @author Andrea Tansella
* @data 01/12/22
*/
int numeroRecord(char nomefile[])
{
	alunno buffer;
	int a,r,b,record,y;
	FILE* pf;	
	y=sizeof(buffer);								
	
	pf=fopen(nomefile,"rb");							
	if(pf!=NULL)									
	{
		//individuo la posizione corrente (b)
		//e determino il numero di record presenti (record) 
		a=fseek(pf,0,SEEK_END);	//mette puntatore alla fine del file per poi calcolare la lunghezza 
		b=ftell(pf);			//restituisce la posizione corrente del file in byte
		record=b/y;				//divido b con la dimenzione di buffer per trovare il numero di record presenti
		fclose(pf);									
		return record;							
	}
	else														
	{
		printf("\nil file non puo'essere aperto\n");
		return -1;
	}
}