const int PIR_SENSOR_OUTPUT_PIN = 13;  /* PIR sensor O/P pin */
int warm_up;
int CAM = 8;
void setup() {
  pinMode(PIR_SENSOR_OUTPUT_PIN, INPUT);
  pinMode(CAM, OUTPUT);
  Serial.begin(115200); /* Define baud rate for serial communication */
  delay(20000); /* Power On Warm Up Delay */
}

void loop() {
  int sensor_output;
  sensor_output = digitalRead(PIR_SENSOR_OUTPUT_PIN);
  if( sensor_output == LOW )
  {
    digitalWrite(CAM,LOW);
//    if( warm_up == 1 )
//     {
//      Serial.print("Warming Up\n\n");
//      warm_up = 0;
//      delay(2000);
//    }
    Serial.print("No object in sight\n\n");
    delay(1000);
  }
  else
  {
    Serial.print("Object detected\n\n");  
    digitalWrite(CAM,HIGH);
    delay(1000);
    digitalWrite(CAM,LOW);  
    delay(10000);
//    warm_up = 1;
//    delay(8000);
  }  
}
