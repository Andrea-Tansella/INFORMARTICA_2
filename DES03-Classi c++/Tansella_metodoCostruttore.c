
/*** ****************************************************************************************
* mainpage esercizi Tansella_metodocostruttore.cpp
*
* @brief introduzione al c++ esercitazione sul metodo costruttore, cin e cout,e metodi set e get 
* 
* @author Andrea Tansella
* @date <12/01/23> 
*/

#include<cstdlib>
#include<iostream>
#include<iomanip>
using namespace std;				//per scrivere funioni cout e cin
	
	//definizione di una classe

class Frazione{						//inizio classe con attributi e metodi della classe 
private:
	
	int numeratore;
	int denominatore;				// definizione di attributi di classe
	
public:           
	
	Frazione(){};					//costruttore default
	//metodi pubblici
	void setNumeratore(int n)
	
	{	numeratore=n;}	
									//avvalora il parametro corrispondente all'attributo
	void setDenominatore(int n)
	
	{	denominatore=n;}
	
	int getNumeratore()
									//restituisce l'attributo
	{	return numeratore;}
	
		int getDenominatoe()
		
	{	return denominatore;}
	
	void stampa()					//stampa a video la frazione
	{
		cout<<"il numeratore:"<<numeratore,
		cout<<endl<<"il denominatore:"<<denominatore<<endl;
		cout<<numeratore<<"/"<<denominatore<<endl;
	}
};

int main(){
	Frazione f1;					//creazione di un oggetto appartenente alla classe frazione
	
	// chiamate del metodo su oggetto
	f1.setNumeratore(12);
	f1.setDenominatore(5);
	f1.stampa();
	system("pause");
}