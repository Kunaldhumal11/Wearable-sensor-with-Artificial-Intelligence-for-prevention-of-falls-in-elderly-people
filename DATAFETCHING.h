#ifndef datafetching_h
#define datafetching_h


void get_anglexyz() {  // THIS SET OF COD EHELPS TO GET ANGLE X Y Z OF THE GYROSCOPE XD

  accelgyro2.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  // Serial.print("a/g:\t");
  // Serial.print(ax);
  // Serial.print("\t");
  // Serial.print(ay);
  // Serial.print("\t");
  // Serial.print(az);
  // Serial.print("\t");
  // Serial.print(gx);
  // Serial.print("\t");
  // Serial.print(gy);
  // Serial.print("\t");
  // Serial.print(gz);
  // Serial.print("\t");
  // Serial.println(sqrt(ax * ax + ay * ay + az * az));
}


void get_accexyz() {  //THIS SET OF CODE HELPS TO GET THE ACCELERATION OF AN OBJ IN  X Y AND Z AXIS :)
  mpu1.getAcceleration(&ax1, &ay1, &az1);
  accel_x1 = ax1 / 16384.0 * 9.81;
  accel_y1 = ay1 / 16384.0 * 9.81;
  accel_z1 = az1 / 16384.0 * 9.81;

  mpu2.getAcceleration(&ax2, &ay2, &az2);
  accel_x2 = ax2 / 16384.0 * 9.81;
  accel_y2 = ay2 / 16384.0 * 9.81;
  accel_z2 = az2 / 16384.0 * 9.81;



  // Repeat for second MPU6050
}


void calculating_BOS() {

  get_anglexyz();

  // Calculate the magnitude of acceleration
  BOS = sqrt(ax * ax + ay * ay + az * az);
  Serial.print("BOS: ");
  Serial.println(BOS);
}

#endif