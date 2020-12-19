
//Biblioteca utilizada para escrever nas linhas do display LCD
#include <LiquidCrystal.h>

//Biblioteca dos micro servos
#include <Servo.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int PINO_TEMPS = A0;
const int PINO_TEMPP = A1;
const int PINO_CO2P = A2;
const int PINO_TIME = A3;
const int PINO_CO2S = A4;


const int PINO_DC = 7;
const int PINO_SERVO = 10;
unsigned int PINO_PIEZO = 13;
const int pinoBotao = 8;
int lidopen = 0;

int TEMPS = 0;
int TEMPP = 0;

int CO2S = 0;
int CO2P = 0;

int frequencia =0;
const int tempo = 10; 

Servo valv;
Servo stove;

int flag = 0;

void setup(){

    Serial.begin(9600);
  	lcd.begin(16, 2);
  	pinMode(pinoBotao, INPUT_PULLUP);
  	valv.attach(10);
  	stove.attach(9);
  	pinMode(PINO_PIEZO, OUTPUT);
  	stove.write(0);
  	valv.write(0);
}

void loop(){
  	
  	TEMPS = readtemps(TEMPS);
    CO2S = readco2s(CO2S);
  	
  	delay(500);
  	lcd.clear();
  
  	//Inicio do processo de fermentação
  	if(digitalRead(pinoBotao) == 0){
		TEMPP = settemp(TEMPP);
  		CO2P = setco2(CO2P);
      	flag = 1;
	} 
  	
  	if(flag == 1){
    	// Chama o método para verificar temperatura
  		checktemp(TEMPS,TEMPP);
  	
  		// Chama o método para verificar nivel de CO2
  		checkCO2(CO2S,CO2P);
      
    	playbuzzer(TEMPS,TEMPP);
      
    	activatemixer();
    }
  	
  	// Chama o método para atualizar a tela LCD
  	refreshLCD(TEMPP, CO2P, TEMPS, CO2S);
}

//Funções auxiliares
int readtemps(int ts){
  	ts = analogRead(PINO_TEMPS);
  	ts = map(ts, 20, 358, -40, 125);
	return ts;
  
}
  
int readco2s(int cs){
  	cs = analogRead(PINO_CO2S);
  	cs = map(cs, 306, 756, 0, 100);
  	return cs;
  	
}
int settemp(int tp){
  	lcd.setCursor(8,0);
  	lcd.print("STemp:");
  	lcd.setCursor(14,0);
	tp = analogRead(PINO_TEMPP);
   	tp = map(tp, 1023, 1, 0, 99);
 	lcd.print(tp);
    return tp;
}

int setco2(int co2){
  	lcd.setCursor(0,1);
  	lcd.print("SCO2:");
  	lcd.setCursor(8,1);
  	co2 = analogRead(PINO_CO2P);
 	co2 = map(co2, 1023, 1, 0, 100);
 	lcd.print(co2);
    return co2;
}

void checktemp(float ts, float tp){
  	if(ts != tp){
    	float abertura = (ts/tp)*100;
    	float commandstove = map(abertura, 0, 100, 90, 1);
  		stove.write(commandstove);
    } else{
    	stove.write(0);
    }
}

void checkCO2(float cs, float cp){ 
  	if(cs >= cp){
    	float abertura2 = (cp/cs)*100;
    	float commandvalv = map(abertura2, 0, 100, 90, 1);
  		valv.write(commandvalv);
    } else{
  		valv.write(0);
  	}  
}

void playbuzzer(int ts, int tp){
	if(ts <= tp - 15 || ts >= tp +15  ){
      digitalWrite(PINO_PIEZO, HIGH);
    }
  else{
    	digitalWrite(PINO_PIEZO, LOW);
  	}
}

void refreshLCD(int tp, int cp, int ts, int cs) {
	lcd.setCursor(0,0);
	lcd.print("Temp:");
  	lcd.setCursor(5,0);
	lcd.print(ts);
  	lcd.setCursor(8,0);
	lcd.print("STemp:");
  	lcd.setCursor(14,0);
	lcd.print(tp);
  
  	lcd.setCursor(0,1);
	lcd.print("CO2:");
  	lcd.setCursor(4,1);
	lcd.print(cs);
 	lcd.setCursor(8,1);
	lcd.print("SCO2:");
  	lcd.setCursor(13,1);
	lcd.print(cp);
}

void activatemixer(){
	digitalWrite(PINO_DC, HIGH);

}