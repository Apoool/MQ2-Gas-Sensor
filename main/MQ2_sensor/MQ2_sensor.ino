  #include <Wire.h> 
  #include <LiquidCrystal_I2C.h>
  //I2C pins declaration
  LiquidCrystal_I2C lcd(0x27, 20, 4);
  int mq2 = A0;

void setup(){
  Serial.begin(9600);
  pinMode(mq2, INPUT);
  lcd.begin();//Defining 16 columns and 2 rows of lcd display
  lcd.backlight();
}
void loop(){
  double mq2Read = analogRead(mq2);
  
  Serial.print("Measure: ");
  Serial.println(mq2Read);
  lcd.print("Measure: ");
  lcd.setCursor(0,1);
  lcd.print(mq2Read);
  delay(1000);
  lcd.clear();
}
