//AndreaTansella 4H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

int main()
{
	char nomeFileIN[MAX+1]="nomi.txt";// ASSEGNAZIONE DEL FILE CHE VIENE COPIATO
	char nomeFileOUT[MAX+1]="Cnomi.txt";// ASSEGNAZIONE DEL FILE CHE COPIA
	char c;
	FILE *fileIn,*fileOut;      // puntatori 
	int err;
	
//	printf("nome del file da leggere\t");
//	scanf("%s",nomeFileIN);
//	printf("nome del file destinazione\t");
//	scanf("%s",nomeFileOUT);
	
	
	fileIn=fopen(nomeFileIN,"r");// APERTURA FILE IN LETTURA
	fileOut=fopen(nomeFileOUT,"w");// APERTURA FILE IN SOVRASCRITTURA
	if(fileIn!=0 && fileOut!=0)
	{
		while(!feof(fileIn))
			{
				c=fgetc(fileIn);
				fputc(c,fileOut);
			}
			fclose(fileIn);
			err=fclose(fileOut);// COTROLLO SE LA CHIUSURA VIENE FATTA CORRETAMENTE 
			if(err!=0)
			{
				printf("Errore in chiusura del file");	
			} else
			{
				printf(" file chiuso corretamente");
			}
	}
		else
		printf("\nErrore in apertura file");// CONTROLLA SE L'APERTURA VIENE FATTA CORRETAMENTE
		printf("\n");
		system("pause");

}	
