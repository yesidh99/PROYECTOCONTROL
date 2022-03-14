//Declaración de variables globales
float temperatura; //Variable para almacenar el valor obtenido del sensor (0 a 1023)
int pinLM35 = A0; //Variable del pin de entrada del sensor (A0)
unsigned long tiempo = 0;

void setup(){
  Serial.begin(9600);
  Serial.println("CLEARDATA");
  Serial.println("CLEARSHEET");
  Serial.println("Temperatura");
    pinMode(9,OUTPUT);
  }

void loop(){
  tiempo=millis();
  temperatura=analogRead(pinLM35);
  temperatura=(5.0 * temperatura * 100.0)/1024.0;;
  if(tiempo>=20000 && tiempo<400000){
    digitalWrite(9,LOW);}
  else{
    digitalWrite(9,HIGH);}
  //Serial.print("DATA,TIEMPO,TEMPERATURA,");
  //Serial.print(tiempo);
    //Serial.print(",");
  Serial.println(temperatura);
  delay(100);
  //Esperamos un tiempo para repetir el loop
}
  
  
  
