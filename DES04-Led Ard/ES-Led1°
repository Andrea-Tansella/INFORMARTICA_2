
// Classe LED
class LED {
  private:
    int pin; // Pin del LED
	int statoLed;//tiene traccia dello stato del led
  
  public:
    // Costruttore: imposta la modalità del pin del LED come output
    LED(int p) {
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
    {	spegni();
  		delay(500);
  		inverti();
    }
       }
  void ledTest(int numeroTest){//testare le funzionalità della classe LED
  
  Lampeggio(numeroTest);
  }
};

// Crea un oggetto LED sulla porta 11
LED led(11);

void setup() {
    
 led.accendi();
  
}

void loop() {
  // Accendi il LED
 /* led.accendi();
  // Aspetta per un secondo
  delay(1000);
  // Spegni il LED
  led.spegni();
  // Aspetta per un secondo*/
//  delay(1000);
 //  led.inverti();
  //led.Lampeggio(5);
  led.ledTest(3);
}

