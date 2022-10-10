0  #include <Wire.h> 
  #include <LiquidCrystal_I2C.h>
  //I2C pins declaration
  LiquidCrystal_I2C lcd(0x27, 20, 4);
  int mq2 = A0;
  int red = 13;
  int grn = 12;
  int bzr = 11;

void setup(){
  Serial.begin(9600);
  pinMode(mq2, INPUT);
  pinMode(red, OUTPUT);
  pinMode(grn, OUTPUT);
  pinMode(bzr, OUTPUT);
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0,6);
  lcd.print("Starting");
  
}
void loop(){
  double mq2Read = analogRead(mq2);
  
  Serial.print("Gas Level: ");
  Serial.println(mq2Read);
  lcd.print("Gas Level: ");
  lcd.print(mq2Read);
  
  lcd.setCursor(0,1);
  lcd.print("Status: ");
  if(mq2Read < 300){
    lcd.print("Stable");
    digitalWrite(red, LOW);
    digitalWrite(grn, HIGH);
  }else if((mq2Read > 299) && (mq2Read < 500)) {
    lcd.print("Warning");
    digitalWrite(red, HIGH);
    digitalWrite(grn, HIGH);
    digitalWrite(bzr, HIGH);
  } else {
    digitalWrite(red, HIGH);
    digitalWrite(grn, LOW);
    lcd.print("Danger");
  }
  delay(1000);
  lcd.clear();
}
