
// CD74HC4067 mux reading to arduino uno

const int out_pins[4] = {
  7, 8, 12, 13,
};

const int in_pin = 4;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(out_pins[i], OUTPUT);
  }
  pinMode(in_pin, INPUT);
  Serial.begin(115200);
}
void loop() {
  unsigned short counterverisi = 0;
  /*  Serial.print("sifirlanmis hali: ");
    Serial.println(counterverisi, BIN);
    Serial.println("");*/
  for (unsigned char i = 0; i < 16; i++) {
    for (unsigned char j = 0; j < 4; j++) {
      int voltage = (i & (1 << j)) >> j;
      digitalWrite(out_pins[j], voltage);


      /*Serial.print("out pin ");
        Serial.print(j + 1);
        Serial.print(": ");
        Serial.println(voltage);
      */
    }

    unsigned int buf = digitalRead(in_pin);
    /*  Serial.print("buffer: ");
      Serial.println(buf, BIN);
      Serial.println("");*/

    counterverisi = counterverisi | ((buf << i) & (1 << i));
  }
  delay(45);
  Serial.print(counterverisi, BIN);
  Serial.print(" ");
  Serial.println(counterverisi);
  Serial.flush();
}

/*void loop() {

  yeniZaman = millis();
    if(yeniZaman-eskiZaman > gecikme){
             eskiZaman = yeniZaman;
              digitalWrite(clk,!digitalRead(clk));}

  unsigned short counterverisi = 0;
  for (unsigned char i = 0; i < 16; i++) {
    for (unsigned char j = 0; j < 4; j++) {
        int voltage = (i & (1 << j)) >> j;
              digitalWrite(out_pins[j], voltage);
              delay(50);

    unsigned int buf = digitalRead(in_pin);
    counterverisi = counterverisi | ((buf << i) & (1 << i));
    }
    Serial.println(counterverisi,BIN);
  }*/
