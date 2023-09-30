void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length) {
  switch (type) {
    case WStype_DISCONNECTED:
      Serial.println("Client " + String(num) + " disconnected");
      break;
    case WStype_CONNECTED:
      Serial.println("Client " + String(num) + " connected");
      break;
    case WStype_TEXT:
      String message = (char *)payload;
      if (message == "ChangeColor") {
        changeLEDColor();
      } else if (message.startsWith("SliderAction1:")) {
        int value = message.substring(14).toInt();
        sliderAction(1, value);
      } else if (message.startsWith("SliderAction2:")) {
        int value = message.substring(14).toInt();
        sliderAction(2, value);
      }
      break;
  }
}