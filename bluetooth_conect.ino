#include "BluetoothSerial.h" // заголовочный файл для последовательного Bluetooth будет добавлен по умолчанию в Arduino
#include <DHT.h>

# define DHTPIN 4 // Пин, к которому подключен датчик DHT11
# define DHTTYPE DHT11 // Используемый тип датчика D HT11
DHT dht (DHTPIN, DHTTYPE);

BluetoothSerial ESP_BT; // Объект для Bluetooth


float humidity = 0;
float temperature = 0;
void setup() {
  Serial.begin(9600); // Запускаем последовательный монитор со скоростью 9600
  ESP_BT.begin("ESP32_LED_Control"); // Задаем имя вашего устройства Bluetooth
  Serial.println("Bluetooth Device is Ready to Pair");  // По готовности сообщаем, что устройство готово к сопряжению
}

void loop() {
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  if(ESP_BT.read() == 1){
    Serial.println(temperature);
    ESP_BT.println(temperature);
  }
  delay(500);
}
