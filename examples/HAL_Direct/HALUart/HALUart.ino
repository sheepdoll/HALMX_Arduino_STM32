void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t wakeywakey[10] = "wakeup.\r\n";

  HAL_UART_Transmit(&huart3, wakeywakey, 9, 0xFFFF); 
  delay(100);


}
