//Biblioteca utilizada para escrever nas linhas do display LCD
#include <LiquidCrystal.h>

//Biblioteca dos micro servos
#include <Servo.h>

// Define as variaveis 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Pinos dos potenciometros, sensores e atuadores
const int PINO_TEMPS = A0;
const int PINO_TEMPP = A1;
const int PINO_CO2P = A2;
const int PINO_TIME = A3;
const int PINO_CO2S = A4;

const int PINO_DC = 7;
const int PINO_SERVO = 10;
unsigned int PINO_PIEZO = 13;
const int pinoBotao = 8;

//Variáveis de Temperatura e CO2 aferidos e setados pelo usuário
int TEMPS = 0;
int TEMPP = 0;

int CO2S = 0;
int CO2P = 0;

//Variáveis de buzzer e tempo
int frequencia =0;
const int tempo = 10; 

// Atuadores da válvula de escape de CO2 e de combustível para o forno
Servo valv;
Servo stove;

//Flag de ativação do sistema
int flag = 0;
unsigned long stime = 0; // the time the delay started
unsigned long dtime = 1000; // delay time


// Começo do código: 

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
  	
  	//Leitura de sensores de temperatura e CO2
  	TEMPS = readtemps(TEMPS);
    CO2S = readco2s(CO2S);
  	
  	delay(500);
  	lcd.clear();
  
  	//Inicio do processo de fermentação
  	if(digitalRead(pinoBotao) == 0){
      
		TEMPP = settemp(TEMPP);
  		CO2P = setco2(CO2P);
      	flag = 1;
      	// Chama o método para verificar o tempo pedido
      	dtime = dtime*settime();
      	// Começa a contar o tempo com stime
      	stime = millis();
      	Serial.print("Tempo pedido \n");
      	Serial.print(dtime/1e3);
      	Serial.print("\n");
      	
      	lcd.clear();
      	lcd.setCursor(0,0);
		lcd.print("Tempo pedido:");
  		lcd.setCursor(5,1);
		lcd.print(dtime/1e3);
  		lcd.setCursor(10,1);
      	lcd.print("s");
      	delay(1000);
	} 
  	
  	if(flag == 1){
  		  	      		
      		// Chama o método para verificar temperatura
  			checktemp(TEMPS,TEMPP);
  	
  			// Chama o método para verificar nivel de CO2
  			checkCO2(CO2S,CO2P);
      
    		playbuzzer(TEMPS,TEMPP);
      
    		activatemixer(true);
      		//Serial.print("Mexendo \n");
   	 }
  	  	
  	// Verifica se o tempo utilizado já foi ultrapassado
  	if(flag && (millis() - stime >= dtime) ){
  		//Serial.print("Parada \n");
        flag = 0; // zera a flag do botão
      	activatemixer(false); // desliga o motor      	
      	valv.write(0);
      	digitalWrite(PINO_PIEZO, LOW);
      	stove.write(0);
      	dtime = 1000; // reseta o delay para 1000 ms
      	
      	lcd.clear();
      	lcd.setCursor(0,0);
		lcd.print("Finalizado");
      	delay(1000);
  	}
  
  	// Chama o método para atualizar a tela LCD
  	refreshLCD(TEMPP, CO2P, TEMPS, CO2S, dtime, stime);
  	
  	//Serial.print("Tempo restante:\n");
  	//Serial.print(dtime - millis() + stime);
  	//Serial.print("\n");
}

//Funções auxiliares

//Leitura de Temperatura do Sensor
int readtemps(int ts){
  	ts = analogRead(PINO_TEMPS);
  	ts = map(ts, 20, 358, -40, 125);
	return ts;
  
}

//Leitura de CO2 do Sensor
int readco2s(int cs){
  	cs = analogRead(PINO_CO2S);
  	cs = map(cs, 306, 756, 0, 100);
  	return cs;
  	
}

//Escolher a Temperatura do processo de fermentação 
int settemp(int tp){
  	lcd.setCursor(8,0);
  	lcd.print("STemp:");
  	lcd.setCursor(14,0);
	tp = analogRead(PINO_TEMPP);
   	tp = map(tp, 1023, 1, 0, 99);
 	lcd.print(tp);
    return tp;
}

//Escolher a porcentagem de CO2 do processo de fermentação
int setco2(int co2){
  	lcd.setCursor(0,1);
  	lcd.print("SCO2:");
  	lcd.setCursor(8,1);
  	co2 = analogRead(PINO_CO2P);
 	co2 = map(co2, 1023, 1, 0, 100);
 	lcd.print(co2);
    return co2;
}

//Verifica a igualdade das tempertaturas do sensor e setada
//caso a primeira esteja menor, mais conbustível é levado
//para aquecer o forno até que a temperatura esteja adequada 
void checktemp(float ts, float tp){
  	if(ts != tp){
    	float abertura = (ts/tp)*100;
    	float commandstove = map(abertura, 0, 100, 90, 1);
  		stove.write(commandstove);
    } else{
    	stove.write(0);
    }
}

//Verifica a igualdade das porcentagens de CO2 do sensor e setada
//caso a primeira esteja maior, a válvula de escape é acionada
//para liberar o excesso de CO2 
void checkCO2(float cs, float cp){ 
  	if(cs >= cp){
    	float abertura2 = (cp/cs)*100;
    	float commandvalv = map(abertura2, 0, 100, 90, 1);
  		valv.write(commandvalv);
    } else{
  		valv.write(0);
  	}  
}

//Buzzer é acionado caso a temperatura aferida pelo sensor se 
//encontra fora do intervalo aceitável do processo de fermentação
void playbuzzer(int ts, int tp){
	if(ts <= tp - 15 || ts >= tp +15  ){
    	digitalWrite(PINO_PIEZO, HIGH);
    }
  	else{
    	digitalWrite(PINO_PIEZO, LOW);
  }
}

//LCD exibe as informações de temperatura e CO2 aferidos e setados
//pelo usuário e o tempo restante do processo
void refreshLCD(int tp, int cp, int ts, int cs, unsigned long dt, unsigned long st) {
  	lcd.clear();
  	
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
  
  	delay(3000);
  
  	if((dt - millis() + st)/1000 < 120){
      	lcd.clear();
  		lcd.setCursor(0,0);
		lcd.print("Tempo Restante:");
  		lcd.setCursor(0,1);
		lcd.print((dt - millis() + st)/1000);
      	delay(2000);
  	}
}

//Escolher o tempo do processo de fermentação
int settime(){
  	int t = analogRead(PINO_TIME);
  	t = map(t, 1023, 1, 10, 100);
  	return t;  	
}

//Acionamento das pás misturadoras
void activatemixer(bool state){
	digitalWrite(PINO_DC, state);
}