#ifndef FILTER_h
#define FILTER_h

// Kalman Filter class
class KalmanFilter {
public:
  KalmanFilter(float processNoise, float measurementNoise, float estimationError)
    : Q(processNoise), R(measurementNoise), P(estimationError), X(0), K(0) {}

  float update(float measurement) {
    // Prediction step
    P = P + Q;

    // Measurement update step
    K = P / (P + R);
    X = X + K * (measurement - X);
    P = (1 - K) * P;

    return X;
  }

private:
  float Q; // Process noise covariance
  float R; // Measurement noise covariance
  float P; // Estimation error covariance
  float K; // Kalman gain
  float X; // State estimate
};

// Create an instance of the KalmanFilter class






#endif 
