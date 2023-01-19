
/*** ****************************************************************************************
* mainpage esercizi Tansella_classeRettangolo.cpp
*
* @brief esercitazione con classe Rettangolo e metodi calcola Area, calcola Perimetro e calcola digonale
* 
* @author Andrea Tansella
* @date <19/01/23> 
*/

#include<cstdlib>
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

class Rettangolo{						//inizio classe con attributi e metodi della classe 
private:
	
	double base;
	double altezza;				// definizione di attributi di classe
	
public:  
         
	Rettangolo(){};					//costruttore default
		
	Rettangolo(double x,double y)				//2 costruttore
	{ 	
		base=x;
		altezza=y;
	}
						
	//metodi pubblici
	void setBase(double n)
	
	{	base=n;}	
									//avvalora il parametro corrispondente all'attributo
	void setAltezza(double n)
	
	{	altezza=n;}
	
	double getBase()
									//restituisce l'attributo
	{	return base;}
	
		double getAltezza()
		
	{	return 	altezza;}

	double calcolaArea()
	{
		return base*altezza;
	}
	double calcolaPerimetro()
	{
		return (base+altezza)*2;
	}
	double calcoloDiagonale()
	{
		return sqrt(pow(base,2)+pow(altezza,2));
	}
		
	void stampa()					//stampa a video la frazione
	{
		double s;
		cout<<endl;
		
		s=getBase();
		cout<<"la base:"<<s<<endl;
		
		s=getAltezza();
		cout<<"l'altezza:"<<s<<endl;
		
			s=calcolaArea();
		cout<<"l'area:"<<s<<endl;
		
			s=calcolaPerimetro();
		cout<<"il perimetro:"<<s<<endl;
	
			s=calcoloDiagonale();
		cout<<"la diagonale:"<<s<<endl;
	
	}
	
	
};	
int main(){
	Rettangolo f1;
	Rettangolo f2(2,5);					//creazione di un oggetto appartenente alla classe frazione
	
	// chiamate del metodo su oggetto
	cout<<"Primo Oggetto:"<<endl;
	f1.setBase(3);
	f1.setAltezza(5);
	f1.stampa();
	cout<<endl;
	cout<<"Secondo Oggetto:"<<endl;
	f2.stampa();
	system("pause");
}