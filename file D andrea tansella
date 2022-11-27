// Andrea Tansella 4H
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char nomeFile1[]={"numeri.txt"};
	char nomeFile2[]={"Npari.txt"};
	char nomeFile3[]={"Ndispari.txt"};
	char s;

	FILE *pFile1,*pFile2,*pFile3;
	
	pFile1=fopen(nomeFile1,"r"); // apertura file in read
	pFile2=fopen(nomeFile2,"w"); // apertura file in write
	pFile3=fopen(nomeFile3,"w"); // apertura file in write
	
	if(pFile1!=0)
	{
		do // controllo se il file si apre senza problemi
		{
			s=fgetc(pFile1); 	
			if(s%2==0)
			{
				fputc(s,pFile2); // copia numero pari in "numeri.txt"
				fputc(' ',pFile2);	
			}	
			else
			{
				fputc(s,pFile3); // copia numero dispari in "numeri.txt"
				fputc(' ',pFile3);	
		    }
			s=fgetc(pFile1);	
		}while(!feof(pFile1));
		
		fclose(pFile1); 			// chiusura file "numeri.txt"
		fclose(pFile2); 			// chiusura file "pari.txt"
		fclose(pFile3); 			// chiusura file "dispari.txt"
	}
	else 
	printf("errore di apertura");//errore di apertura
}
