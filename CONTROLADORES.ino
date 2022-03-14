float temp; // temperatura
int LM35 = A1; // pin analgico para hacer la lectura del sensor
float error;
int REF; // Temperatura de referencia
float e1,e2,u1= 0; 
int RELED6 = 6;

void setup() {
  Serial.begin(115200); // Iniciar el puerto serialz
  REF = 50;
  delay(5000);
}

void loop() {

  while(!Serial){} 
  
  temp = (analogRead(LM35)*500.0) / 1024;
  error = REF - temp;
  //float accontrol = constrain(11*error - 9.13*e1 + u1,0,255);//PI
  float accontrol = constrain(10*error - 9.49*e1 + 0.8*e2 + u1,0,255);//PID
  //float accontrol = constrain(37.13*error - 32.68*e1+0.3*u1,0,255);//ADELANTO
  analogWrite(RELED6,accontrol);

  Serial.print(temp);
  Serial.print(",");
  Serial.print(error);
  Serial.print(",");
  Serial.println(accontrol);


  e1 = error;
  u1 = accontrol;
  e2 = e1;
  

  delay(500);
  
}
