//AndreaTansella 4H

#include<stdio.h>
#include<stdlib.h> 								// dichiarazione  deglle librerie utilizzate 
  
int main()
{
	char nomeFileIN[] ={"nomi.txt"};			//file di testo da copiare  
	char nomeFileOUT[]={"nomi2.txt"};			//file che verra creato
	char c;										//variabile
	
	FILE *FileIn,*FileOut;						// dichiarazione di puntatori del file
	
	FileIn=fopen(nomeFileIN,"r");				//apertura del file in modalita lettura
	FileOut=fopen(nomeFileOUT,"w");				//apertura del file in modalita scrittura posizionandosi all'inizio
	
	if(	FileIn!=0&&FileOut!=0)					// controlla se i file possono essere aperti senza problemi
	{
		while(!feof(FileIn))                    // va avanti finche il file non e finito
		{
			c=fgetc(FileIn);					//preliva si posiziona sul primo carattere e avanza di 1
			if(c>='a'&&c<='z')					//controlla se il carattere prelevato e compreso tra a minuscola e z minuscola 
			c-=32;    							//cambia il carattere minuscolo sottraendo 32 diventando maiuscola
			fputc(c,FileOut);                   //scrive i caratteri nella varibile indicata
		}
			fclose(FileIn);						//chisura dei file dopo il ciclo
			fclose(FileOut);
	}
			else      							// non puo essere aperto 
			
			printf("\nil file non puo'essere aperto!"); 	
			
			printf("\n");
			system("pause");					//fine del programma
}
