//  static bool wait = false;
//
//  Serial.print("connecting to ");
//  Serial.print(host);
//  Serial.print(':');
//  Serial.println(port);
//
//  // Use WiFiClient class to create a TCP connection
//  WiFiClient client;
//  if (client.connect(host, port)) {
//    Serial.println("connection succeeded");
//  } else {
//    Serial.println("connection failed");
//    delay(5000);
//    return;
//  }
//  
//  client.print(String("GET ") + "/get_data" + " HTTP/1.1\r\n");   // Requête to server
//
//  // Wait for receiving data during 10 seconds
//  unsigned long timeout = millis();
//  while (client.available() == 0) {
//    if (millis() - timeout > 10000) { 
//      Serial.println("Client timeout!");
//      client.stop();
//      delay(10000);
//      return;
//    }
//  }
//
//  while (client.available()) { 
//    String line = client.readStringUntil('\r'); 
//    Serial.print(line);
//} 
//
//  // Data are received
//  while(client.available()) {
//    int ecFlex_data = client.read();
//    Serial.print(ecFlex_data);
//  }
//
//  // Serial receive buffer
//  Serial.setTimeout(1000);            // ParseInt() wait 1 sec before reading, instead of reading in each byte as it arrives
//  while (Serial.available() > 0) {
//    int ecFlex_data = Serial.parseInt();
//    Serial.print(ecFlex_data);
//  }
//
//  // Serial receive buffer 
//  Serial.setTimeout(1000);            // ParseInt() wait 1 sec before reading, instead of reading in each byte as it arrives
//  while (Serial.available() > 0) {
//    byte ecFlex_data = Serial.parseInt();
//    Serial.print(ecFlex_data);
//  }
////////////////////////////////////////////////////////////////////////////////

    // Data intepretation
    // Try 1
//    Stream.readBytes(buffer, length);
//    // Serial.readBytes(buffer, length);
//    int id                      = ((ecFlex_data[1] << 8) + data[0]);
//    int timer                   = ((ecFlex_data[3] << 8) + data[2]);
//    int temperature             = ((ecFlex_data[5] << 8) + data[4]);
//    float glucose concentration = ((ecFlex_data[7] << 8) + data[6]);
//    Serial.print(ecFlex_data);
//}
    
    // Try 2
    
//    int id                      = convert_hex_to_decimal(char ecFlex_data[1] + char ecFlex_data[2]);   // ToDo: find convert_hex_to_decimal
//    int timer                   = convert_hex_to_decimal(char ecFlex_data[3] + char ecFlex_data[4]);  //
//    int temperature             = convert_hex_to_decimal(char ecFlex_data[5] + char ecFlex_data[6]);  
//    float glucose_concentration = convert_hex_to_decimal(char ecFlex_data[7] + char ecFlex_data[8]);  

    
//    // Try 3     extracting a 32 bit int into a int8_t
//    if (!PassTwo) {
//            rx_frame.FIR.B.FF = CAN_frame_std;
//            rx_frame.MsgID = 1;
//            rx_frame.FIR.B.DLC = 8;
//            rx_frame.data.u8[0] = *item & 0xFF;
//            rx_frame.data.u8[1] = (*item >> 8) & 0xFF;
//            rx_frame.data.u8[2] = (*item >> 16) & 0xFF;
//            rx_frame.data.u8[3] = (*item >> 24) & 0xFF;
//            PassTwo = true;
//          } else {
//            rx_frame.data.u8[4] = *item & 0xFF;;
//            rx_frame.data.u8[5] = (*item >> 8) & 0xFF;
//            rx_frame.data.u8[6] = (*item >> 16) & 0xFF;
//            rx_frame.data.u8[7] = (*item >> 24) & 0xFF;
//            ESP32Can.CANWriteFrame(&rx_frame); // send items over CAN buss
//            PassTwo = false;
//          }

  
//    // Try 4
//    void HexToColor(const char* hex, byte *container)
//  {
//      char str[3] = {};
//      //get r
//      str[0] = hex[1];
//      str[1] = hex[2];
//      container[0] = (byte)strtol(str, NULL, 16);
//  
//      //get b
//      str[0] = hex[3];
//      str[1] = hex[4];
//      container[1] = (byte)strtol(str, NULL, 16);
//  
//      //get g
//      str[0] = hex[5];
//      str[1] = hex[6];
//      container[2] = (byte)strtol(str, NULL, 16);
//  }
//  
//  //usage
//  {
//     ...
//     char *hex = (char *)onoffbutton.lastread;
//     byte color[3] = {};
//     HexToColor(hex, color);
//  }


    // Try 5
  
  //(TIBLERawSampleModel *) rawSamplevalue {
  //  TIBLERawSampleModel value nil;
  //  if(self.data I- nil && self.data.length TIBLE PAYLOAD DATA_SIZE_8_BYTES) {
  //    value [[TIBLERawSampleModel alloc] init];
  //    
  //    int arraySize = TIBLE_PAYLOAD DATA_SIZE_8_BYTES/2;
  //    uint16 t losesensorData[arraySize];
  //    [self.data getaBytes:losensorData length:sizeof(losensorData)];
  //    
  //    value.uintValuel - loSensorData[0];
  //    value.uintValue = losensorData[1];
  //    value.uintValue3 - losensorData[2];
  //    value.uintValue4 loSensorData[3];
  //    
  //    [TIBLELogger detail:e"TIBLEUtilities - Printing measurement value: ... \n"];
  //    [TIBLELogger detail:e"\t counter: Xu\n", value.uintValuel];
  //    [TIBLELogger detail:@"\t time: Xu\n", value.uintValue2];
  //    [TIBLELogger detail:@"\t temp: Xu\n", value.uintValue3];
  //    [TIBLELogger detail:@"\t adc value: Xu\n", value.uintValue4];
  //  }
  //}

////////////////////////////////////////////////////////////////////////////////

//  // Close the connection
//  Serial.println();
//  Serial.println("closing connection");
//  client.stop();
//
//  delay(30000);  // Execute every 30 secondes

