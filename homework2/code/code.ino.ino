
int in_byte =0;

void setup() {
 Serial.begin(9600);
 
}

void loop() {
  if(Serial.available()>0){
    in_byte = Serial.read();
    Serial.print("This is what I read: ");
    Serial.println(in_byte);
  }

}
