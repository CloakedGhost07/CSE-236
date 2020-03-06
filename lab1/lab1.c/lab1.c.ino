#define DDRD_reg (*((*volatile uint8_t*) 0x2A))
#define DDRD_IO (*((volatile uint8_t*) 0x0A))
#define uint8_t red 5
#define uint8_t green 6
#define uint8_t blue 7
#define uint8_t button 3





void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  /*
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  */
}

void lights(){
  //set DDRD ports to OUTPUT.
  DDRD_reg |= (1 << blue);
  DDRD_reg |= (1 << green);
  DDRD_reg |= (1 << red);

  DDRD_IO |= (1 << red); //red on
  delay(500);
  DDRD_IO |= (1 << green);//red and green on
  delay(500);
  DDRD_IO &= ~(1 << red); // green on
  delay(500);
  DDRD_IO |= (1 << blue); //green and blue on
  delay(500);
  DDRD_IO &= ~(1 << green); // blue on
  delay(500);
  DDRD_IO |= (1 << red); // red and blue on
  delay(500);
  DDRD_IO &= ~(7 << red); // all off

  //sets back to INPUT for Power Management
  DDRD_reg |= ~(1 << blue);
  DDRD_reg |= ~(1 << green);
  DDRD_reg |= ~(1 << red);
  
}

void button(){
  DDRD_reg |= ~(1 << button);
  if(DDRD_IO & (1 << button) == HIGH){
    lights();
  }
  return;
}

void loop() {
  button();
  // put your main code here, to run repeatedly:
  /*
  digitalWrite(red,HIGH);
  delay(500);
  digitalWrite(green,HIGH);
  delay(500);
  digitalWrite(red,LOW);
  delay(500);
  digitalWrite(blue,HIGH);
  delay(500);
  digitalWrite(green,LOW);
  delay(500);
  digitalWrite(red,HIGH);
  delay(500);
  digitalWrite(red,LOW);
  digitalWrite(blue,LOW);
  delay(500);
  */
}
