

// Classe LED
class Led {
  private:
    int pin; // Pin del LED
	int statoLed;//tiene traccia dello stato del led
  
  public:
    // Costruttore: imposta la modalità del pin del LED come output
    Led(int p) {
      pin = p;
      pinMode(pin, OUTPUT);
    }

    // Metodo per accendere il LED
    void accendi() {
      digitalWrite(pin, HIGH);
      statoLed=HIGH;
    }

    // Metodo per spegnere il LED
    void spegni() {
      digitalWrite(pin, LOW);
      statoLed=LOW;
    }
  void inverti(){//che accende o spegne il led in base allo stato attuale del led

    if(statoLed==LOW)
      accendi();
   else
     spegni();
 	 }
  
  void Lampeggio(int nrLampeggi){
    for(int i=0;i<nrLampeggi;i++)
    {	
      	spegni();
  		delay(200);
  		inverti();
  		delay(200);
    }
  }
  
  void test(int numeroTest){
  	Lampeggio(numeroTest);
  }
};


class Pulsante{ 
   private:
    int pin; // Pin del pulsante
  
  public:
    // Costruttore: imposta la modalità del pin del LED come output
    Pulsante(int p) {
      pin = p;
      pinMode(pin, INPUT_PULLUP);
    }
  
 	int press(){
		return ! digitalRead(pin);  
  	}
    
    
  	int click(){
      if(press())
      {
        while(press());
        return 1;
      }
      else
      {
        return 0;
      }
    }
};


// Crea un oggetto LED sulla porta 12 e 13
Led ledrosso(12);
Led ledblu(13);
Pulsante button(2);

void setup() { // Inizializzazione 
 	ledrosso.Lampeggio(2);
 	ledblu.Lampeggio(3);
	ledrosso.accendi();
    ledblu.spegni();
}

//Loop infinito
void loop() { 
 
  if(button.click())
  {
    ledrosso.inverti();
    ledblu.inverti();
  }
}   

