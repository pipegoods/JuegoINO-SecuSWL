const int vector_leds[4] = {2,3,4,5};
int vector_secuencia[4];
int vector_secuencia_user[4];
int niveles = 0;
void setup()
{
	pinMode(vector_leds[0], OUTPUT);
	pinMode(vector_leds[1], OUTPUT);
	pinMode(vector_leds[2], OUTPUT);
	pinMode(vector_leds[3], OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(A0, INPUT);
	pinMode(A1, INPUT);
	pinMode(A2, INPUT);
	pinMode(A3, INPUT);
	pinMode(A4, INPUT);
}

void loop()
{
	for(int i = 0; i < 20; i++){
		generarSecuencia();
		viewSecuencia();
		leerSecuencia();
		delay(1500);
	}
	
}

void generarSecuencia() {
	randomSeed(millis());
	boolean bandera = true;
	while (bandera) {
		for(int i = 0; i<4; i++) {
			vector_secuencia[i] = random(1,50);
			if(vector_secuencia[i]%2==0){
				bandera = false;
			}
		}
	}
}

void viewSecuencia() {
	for(int i = 0; i<4; i++) {
		digitalWrite(vector_leds[i],LOW); // Apago todos los LEDS
	}
	for(int i = 0; i<4; i++) {
		if(vector_secuencia[i]%2 == 0) {
			digitalWrite(vector_leds[i],HIGH); // Se encienden solo los que al azar
			// obtuvieron un numero par
			delay(2000);
			digitalWrite(vector_leds[i],LOW); // Se apaga para simular la secuencia
		}
	}
}

void leerSecuencia() {
	boolean bandera = true;
	for (int i = 0; i < 4; i++) {
		vector_secuencia_user[i] = 1;
	}
	while (bandera) {
		if(digitalRead(A4) == LOW) {
			bandera = false;
		}
		if(digitalRead(A0) == LOW) {
			vector_secuencia_user[0] = 2;
			digitalWrite(vector_leds[0],HIGH); 
			delay(1000);
			digitalWrite(vector_leds[0],LOW); 
		}
		if(digitalRead(A1) == LOW) {
			vector_secuencia_user[1] = 2;
			digitalWrite(vector_leds[1],HIGH); 
			delay(1000);
			digitalWrite(vector_leds[1],LOW); 
		}
		if(digitalRead(A2) == LOW) {
			vector_secuencia_user[2] = 2;
			digitalWrite(vector_leds[2],HIGH); 
			delay(1000);
			digitalWrite(vector_leds[2],LOW); 
		}
		if(digitalRead(A3) == LOW) {
			vector_secuencia_user[3] = 2;
			digitalWrite(vector_leds[3],HIGH); 
			delay(1000);
			digitalWrite(vector_leds[3],LOW); 
		}
	}
	int contador = 0;
	for (int i = 0; i < 4; i++) {
		if(vector_secuencia_user[i]%2==0 && vector_secuencia[i]%2==0){
			contador++;
		} else if (vector_secuencia_user[i]%2!=0 && vector_secuencia[i]%2!=0){
			contador++;
		}
	}
	
	if(contador == 4) {
		digitalWrite(6,HIGH);
		delay(200);
		digitalWrite(6,LOW);
		delay(200);
		digitalWrite(6,HIGH);
		delay(200);
		digitalWrite(6,LOW);
		delay(200);
		digitalWrite(6,HIGH);
		delay(200);
		digitalWrite(6,LOW);
		delay(200);
		digitalWrite(6,HIGH);
		delay(200);
		digitalWrite(6,LOW);
	} else {
		digitalWrite(6,HIGH);
		delay(1000);
		digitalWrite(6,LOW);
		delay(1000);
		digitalWrite(6,HIGH);
		delay(1000);
		digitalWrite(6,LOW);
	}
}