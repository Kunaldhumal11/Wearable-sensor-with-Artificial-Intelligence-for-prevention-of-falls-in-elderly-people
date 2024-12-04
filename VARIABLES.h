#ifndef VARIABLE_H
#define VARIABLE_H
// I2C CONNECTION ESTABLISH
MPU6050 mpu1(0x68);  // First MPU6050 at default address 0x68
MPU6050 mpu2(0x69);  // Second MPU6050 at address 0x69 (AD0 pin connected to VCC)

//mpu objects
MPU6050 accelgyro2(0x69);

// required variables

int16_t ax, ay, az;
int16_t gx, gy, gz;

unsigned long timer = 0;   // WE USE THIS TIMER MATE FOR THE SAMPALING
unsigned long timer2 = 0;  // SAME AS ABHOVE

#define WIFI_SSID "Prajwal_28"                                                                // WIFI CONNECTION
#define WIFI_PASSWORD "praj_2004"                                                             // WIFII PASSWORD
#define FIREBASE_HOST "elderly-care-10d09-default-rtdb.asia-southeast1.firebasedatabase.app"  // FIREBAE HOST ID
#define FIREBASE_AUTH "SjzXTeQZPbwKDQmipHYn3SjCITvF9qYsZgixSpTG"                              // FIREBASE HOST AUTHENTICATION


//REQUIRED OBJECTS
FirebaseData firebaseData;
FirebaseConfig firebaseConfig;
FirebaseAuth firebaseAuth;


//REQUIRED VARIABLES
float angle_x1 = 0;
float angle_y1 = 0;
float angle_z1 = 0;
float angle_x2 = 0;
float angle_y2 = 0;
float angle_z2 = 0;

//GETACCELERATION

float accel_x1 = 0;
float accel_y1 = 0;
float accel_z1 = 0;

float accel_x2 = 0;
float accel_y2 = 0;
float accel_z2 = 0;

// thresholding  data
int accceleration_thresh = 17000;  // change as per the data of dataset
int gyroscopic_tresh = 0;          // change as per the data of dataset

// acceleration along xyz
int16_t ax1, ay1, az1, ax2, az2, ay2;

// prevention variables
bool eject = 0;
int BOS = 0;

// bos threshold
int BOS_SETPOINT = 0;
int BOS_THRESH_1 = 17600;   // SET THEM AS PER THE DATA SET
int BOS_THRESH_2 = 18000;  // SET THEM AS PER THE DATA SET

// gyro threshold
float gyro_thres_x = 0;
float gyro_thres_y = 0;
float gyro_thres_z = 0;

//G-FORCE VARIABLES (ASSUMING)
float ax1_g = 0;  // Assuming ±2g scale
float ay1_g = 0;
float az1_g = 0;

// acceleration in mpsq
float accel_x1_mps2 = 0;
float accel_y1_mps2 = 0;
float accel_z1_mps2 = 0;

float accel_x2_mps2 = 0;
float accel_y2_mps2 = 0;
float accel_z2_mps2 = 0;

float ax2_g = 0;  // Assuming ±2g scale
float ay2_g = 0;
float az2_g = 0;

// required pins
#define buzz D0

#endif