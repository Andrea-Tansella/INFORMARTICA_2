/** ****************************************************************************************
* \mainpage cryptdec
*
* @brief criptazione decriptazione con metodo cesarecript chiave di criptaggio = 3 
* @author Andrea Tansella
* @date 28/11/22 
* @classe 4H
* 
*/
#include <stdio.h>

#define KEY_CRIPT 3 //chiave di criptaggio
#define ALFABETO 26

void cryptCes(char testo []);//funzone criptaggio
void decryptCes(char testo []);//funzione decriptaggio

int main()
{
	
	char fileImput[]={"nomi.txt"};//percoso file lettura
	char fileOutput[]={"crypt.txt"};
	cryptCes(fileImput);
	decryptCes(fileOutput);
	
}


void cryptCes(char testo [])
{
	char r;
	FILE *Fimput,*Fcript;				//puntatori file
	Fimput=fopen(testo,"r"); 		//apertura primo file in modalità read
	Fcript=fopen("crypt.txt","w");	//apertura file crypt in modalità write
	
	if(Fimput!=0&&Fcript!=0)            //controllo  file apertura senza problemi
	{
		while(!feof(Fimput))		//ciclo fino a quando non finisce il file
		{
			r=fgetc(Fimput);  
		
			if(r>='a'&&r<='w'||r>='A'&&r<='W')		//controllo se il carattere faccia parte del alfabeto a cui abbiamo sottratto la chiave di criptaggio
			{
				r+= KEY_CRIPT;    // si aumenta del valore della KEY_CRIPT
				fputc(r,Fcript);	//inserisce carattere nel nuovo file di output		
			}
			else 
			{
				if(r>='x'&&r<='z'||r>='X'&&r<='Z')	// controlla se il carattere che appartiene all'alfabeto faccia parte delle lettere che vengono sotratte a seconda della KEY_CRIPT
				
				{
					r-=ALFABETO;       // si parte dalla prima lettera dell'alfabeto e si aumenta di KEY_CRIPT se fa parte delle ultime lettere del alfabeto
					r+=KEY_CRIPT;
				}
				
			
			
				
				fputc(r,Fcript);//inserisce carattere nel file di output	
			}	
		}
	}
	else 
	{
		printf("errore"); // errore in apertura
	}
	
	fclose(Fimput);
	fclose(Fcript);// chiusura dei file
}

void decryptCes(char testo [])
{
	char r;
	FILE *Fimput,*Fdecript;					//puntatori ai file
	Fimput=fopen(testo,"r");				//apertura primo file in modalità read
	Fdecript=fopen("decrypt.txt","w");	//apertura file crypt in modalità write
	
	if(Fimput!=0&&Fdecript!=0)					//controllo se i file si sono aperti senza problemi
	{
		while(!feof(Fimput))				//esegue ciclo fino a quando non finisce il file
		{
			r=fgetc(Fimput);
							 
			if((r>='d'&&r<='z')||(r>='D'&&r<='Z'))	//controllo  carattere faccia parte del alfabeto partendo dall'inizio e sottraendo la chiave di criptaggio
			{
				r-=KEY_CRIPT;				//Sottrae la KEY_CRIPT per decriptarlo 
				fputc(r,Fdecript);	//ineserisce carattere nel file di output		
			}
			else 
			{	
				if(r>='a'&&r>='c'||r>='A'&&r>='C')
					{
							r+=ALFABETO;
							r-=KEY_CRIPT;  //somma al carattere all'interno di r 26 e gli sottrae la KEY_CRIPT	
					}	
				
				fputc(r,Fdecript);		//inserisce carattere nel file di output	
			}	
		}
	}
	else 
	{
		printf("errore");	
	}

	fclose(Fimput);
	fclose(Fdecript);// chiusure dei file
}
