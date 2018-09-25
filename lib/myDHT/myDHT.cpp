#include <dht.h>
dht DHT;
#define DHT11_PIN 2

int DHTreadTemprature() {
  int chk = DHT.read11(DHT11_PIN);
  if (chk == -1) {
  return  DHT.temperature;
  }
}
/**
 * Retunrs an INT containing the humidity off the DHT11
 * @method DHTreadHumidity
 */
int DHTreadHumidity() {
  int chk = DHT.read11(DHT11_PIN);
  if (chk == -1) {
  return DHT.humidity;
  }
}
