#include <dht.h>
dht DHT;
#define DHT11_PIN 2

int DHTreadTemprature() {
  int chk = DHT.read11(DHT11_PIN);
  int temps;
  if (chk == -1) {
  int temps = int(DHT.temperature);
  }

  return temps;
}
/**
 * Retunrs an INT containing the humidity off the DHT11
 * @method DHTreadHumidity
 */
int DHTreadHumidity() {
  int chk = DHT.read11(DHT11_PIN);
  int hums;
  if (chk == -1) {
  int hums = int(DHT.humidity);
  }


  return hums;
}
