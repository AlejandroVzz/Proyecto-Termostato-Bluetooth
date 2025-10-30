const int pinTemp = A0;
const int pinPot = A1;
const int pinBoton = 2;

const int rojo = 9;
const int azul = 10;
const int verde = 11;
const int ventilador = 7;
const int calefactor = 6;

int modo = 0; // 0 = automático, 1 = ajustable
bool estadoBotonAnterior = HIGH;
String estadoAnterior = "";
String buffer = "";
float tempDeseada = 25.0; // Valor inicial por defecto

void setup() {
  Serial.begin(9600); // Comunicación con ESP8266
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(ventilador, OUTPUT);
  pinMode(calefactor, OUTPUT);
  pinMode(pinBoton, INPUT_PULLUP);

  Serial.println("Sistema iniciado en modo AUTOMATICO");
}

void loop() {
  // Leer pulsador para cambiar de modo
  bool estadoBoton = digitalRead(pinBoton);
  if (estadoBoton == LOW && estadoBotonAnterior == HIGH) {
    modo = !modo;
    Serial.println(modo == 0 ? "Modo cambiado a AUTOMATICO" : "Modo cambiado a AJUSTABLE");
    delay(300);
  }
  estadoBotonAnterior = estadoBoton;

  // Leer temperatura ambiente
  int lectura = analogRead(pinTemp);
  float voltaje = lectura * (5.0 / 1023.0);
  float temperatura = (voltaje - 0.5) * 100.0;

  String estadoActual = "";

  // Leer datos del ESP8266 si hay disponibles
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {
      tempDeseada = buffer.toFloat();
      tempDeseada = constrain(tempDeseada, 15.0, 35.0); // Validar rango
      buffer = "";
      Serial.print("Temperatura deseada recibida por Wi-Fi: ");
      Serial.println(tempDeseada, 1);
    } else {
      buffer += c;
    }
  }

  if (modo == 0) {
    if (temperatura < 18) {
      estadoActual = "Frio";
      setColor(0, 0, 255);
      digitalWrite(calefactor, HIGH);
      digitalWrite(ventilador, LOW);
    } else if (temperatura > 30) {
      estadoActual = "Caluroso";
      setColor(255, 0, 0);
      digitalWrite(calefactor, LOW);
      digitalWrite(ventilador, HIGH);
    } else {
      estadoActual = "Templado";
      setColor(0, 255, 0);
      digitalWrite(calefactor, LOW);
      digitalWrite(ventilador, LOW);
    }
  } else {
    // Si no se recibió dato por Wi-Fi, usar potenciómetro
    if (buffer == "") {
      int lecturaPot = analogRead(pinPot);
      tempDeseada = map(lecturaPot, 0, 1023, 15, 35);
    }

    Serial.print("Temp actual: ");
    Serial.print(temperatura, 1);
    Serial.print(" C — Deseada: ");
    Serial.print(tempDeseada, 1);
    Serial.println(" C");

    if (temperatura > tempDeseada + 1) {
      estadoActual = "Alto";
      setColor(255, 0, 0);
      digitalWrite(calefactor, LOW);
      digitalWrite(ventilador, HIGH);
    } else if (temperatura < tempDeseada - 1) {
      estadoActual = "Bajo";
      setColor(0, 0, 255);
      digitalWrite(calefactor, HIGH);
      digitalWrite(ventilador, LOW);
    } else {
      estadoActual = "Estable";
      setColor(0, 255, 0);
      digitalWrite(calefactor, LOW);
      digitalWrite(ventilador, LOW);
    }
  }

  if (estadoActual != estadoAnterior) {
    Serial.println("Estado: " + estadoActual);
    if (estadoActual == "Frio" || estadoActual == "Bajo") {
      Serial.println("Accion: Se encendera el Calefactor");
    } else if (estadoActual == "Caluroso" || estadoActual == "Alto") {
      Serial.println("Accion: Se encendera el Ventilador");
    } else {
      Serial.println("Accion: No se encendera ningun dispositivo");
    }
    estadoAnterior = estadoActual;
  }

  delay(1000);
}

void setColor(int r, int g, int b) {
  analogWrite(rojo, 0);
  analogWrite(verde, 0);
  analogWrite(azul, 0);

  analogWrite(rojo, r);
  analogWrite(verde, g);
  analogWrite(azul, b);
}