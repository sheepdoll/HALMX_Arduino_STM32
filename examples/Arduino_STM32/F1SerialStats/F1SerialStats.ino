/*
  from http://www.stm32duino.com/viewtopic.php?t=245 may only work with F1xxx processor variants
*/

#include <stdint.h>

  uint16_t *flashSize = (uint16_t *) (0x1FFFF7E0);
  uint16_t *idBase0 =  (uint16_t *) (0x1FFFF7E8);
  uint16_t *idBase1 =  (uint16_t *) (0x1FFFF7E8+0x02);
  uint32_t *idBase2 =  (uint32_t *) (0x1FFFF7E8+0x04);
  uint32_t *idBase3 =  (uint32_t *) (0x1FFFF7E8+0x08);


void setup() {
  Serial.begin(9600);
}

void loop() {
  
  Serial.print("Flash size is ");
  Serial.print(*flashSize );
  Serial.println("k");
  
  Serial.print("Unique ID is ");
  Serial.print(*(idBase0),HEX);
  Serial.print(*(idBase1),HEX);
  Serial.print(*(idBase2),HEX);
  Serial.println(*(idBase3),HEX);  

  delay(500);
}

