#ifndef function_h
#define function_h


void MPU_SETUP() {  // THIS SET OF CODE  HELP IN MPU SETUP IF  THE STATUS IS 0 THEN YOU ARE GOOD TO GO BUT IF TIS BETNN 1-6 MEAND THERE IS SOME ERROR

  Wire.begin();

  accelgyro2.initialize();
  // Initialize the first MPU6050
  mpu1.initialize();
  mpu1.setFullScaleAccelRange(MPU6050_ACCEL_FS_2);

  // Initialize the second MPU6050
  mpu2.initialize();
  mpu2.setFullScaleAccelRange(MPU6050_ACCEL_FS_2);
}


void WIFI_SETUP() {  // THIS SET OF CODE HELP IN SETTING WIFI CONNECTION HELP TO PUSH DATA TO THE FREBASE

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("TRYING TO CONNET TO WIFI MATE");
  }
  Serial.println("Connected to Wi-Fi");
}


void SETUP() {  // REQUIRED SETUP TO RUN YOUR CODE

  Serial.begin(115200);
  pinMode(buzz, OUTPUT);
}


void fire_base_connection() {  // THIS SET OF CODE SETS THE CONNECTION OF ESP8266 TO THE FIREBSE

  firebaseConfig.host = FIREBASE_HOST;
  firebaseConfig.signer.tokens.legacy_token = FIREBASE_AUTH;

  Firebase.begin(&firebaseConfig, &firebaseAuth);
  Firebase.reconnectWiFi(true);

  if (!Firebase.ready()) {
    Serial.println("Failed to connect to Firebase");
    while (true) {
      Serial.print(" unable to connect mate ;( ");
      Serial.println(".");
    }
  } else {
    Serial.println("Connected to Firebase");
  }
}


void push_data() {  //THIS SET OFCODE PUSSES THE CODE DATA TO THE FIRE BASE
  if (millis() - timer2 > 10) {
    if (Firebase.setFloat(firebaseData, "/sensor_data/Ax1", ax1)) {

    } else {
      Serial.print("Failed to send x1 axis: ");
      Serial.println(firebaseData.errorReason());
    }

    if (Firebase.setFloat(firebaseData, "/sensor_data/Ay1", ay1)) {
    } else {
      Serial.print("Failed to send y1_axis: ");
      Serial.println(firebaseData.errorReason());
    }

    if (Firebase.setFloat(firebaseData, "/sensor_data/Az1", az1)) {

    } else {
      Serial.print("Failed to send  z1_axis : ");
      Serial.println(firebaseData.errorReason());
    }
    if (Firebase.setFloat(firebaseData, "/sensor_data/Ax2", ax2)) {

    } else {
      Serial.print("Failed to send x2 axis: ");
      Serial.println(firebaseData.errorReason());
    }

    if (Firebase.setFloat(firebaseData, "/sensor_data/Ay2", ay2)) {
    } else {
      Serial.print("Failed to send y2_axis: ");
      Serial.println(firebaseData.errorReason());
    }

    if (Firebase.setFloat(firebaseData, "/sensor_data/Az2", az2)) {

    } else {
      Serial.print("Failed to send  z2_axis : ");
      Serial.println(firebaseData.errorReason());
    }
    Serial.print(ax1);
    Serial.print(" ");
    Serial.print(ay1);
    Serial.print(" ");
    Serial.print(az1);
    Serial.print(" ");
    Serial.print(ax2);
    Serial.print(" ");
    Serial.print(ay2);
    Serial.print(" ");
    Serial.print(az2);
    Serial.println();

    timer2 = millis();
  }
}

void buzzer() {
  if (BOS > BOS_THRESH_1 && BOS < BOS_THRESH_2) {
    digitalWrite(buzz, 1);
    delay(100);
    digitalWrite(buzz, 0);
    delay(100);
  } else if (BOS > BOS_THRESH_2) {
    digitalWrite(buzz, 1);
  } else {
    digitalWrite(buzz, 0);
  }
}


#endif