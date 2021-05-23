void setup() {   
  Serial.begin(9600);
  dht.begin();
  while (!Serial);
 if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);