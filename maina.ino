#include <LiquidCrystal.h>

// LCD ekranını tanımla
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// pH sensörünün pinlerini tanımla
const int sensorPin = A0;

void setup() {
  // LCD ekranını başlat
  lcd.begin(16, 2);

  // Serial iletişimini başlat
  Serial.begin(9600);
}

void loop() {
  // pH sensöründen değeri oku
  int sensorValue = analogRead(sensorPin);

  // pH değerini hesapla
  float pH = map(sensorValue, 0, 1023, 0, 14.00);

  // Sonucu ekrana yazdır
  lcd.clear();
  lcd.setCursor(0, 0);

  if (pH >= 6.5 && pH <= 8.5) {
    lcd.print("Afiyet olsun");
    lcd.setCursor(0, 1);
    lcd.print(":)");
  } else {
    lcd.print("İçme!");
    lcd.setCursor(0, 1);
    lcd.print(":(");
  }

  // pH değerini seri port üzerinden görüntüle
  Serial.print("pH: ");
  Serial.println(pH);

  // Biraz bekle
  delay(1000);
}