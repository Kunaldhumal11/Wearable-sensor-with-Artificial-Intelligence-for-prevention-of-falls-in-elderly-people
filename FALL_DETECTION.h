#ifndef FALL_DETECTION_H
#define FALL_DETECTION_H
// THIS SET OF CODE IS MADE FOR THE THRESHOLDING OF THE DATA FOR DETECTION OF THE FALL

void detect_the_fall() {
  eject = (sqrt(ax * ax + ay * ay + az * az) > accceleration_thresh) ? 1 : 0;
  if (eject == 1) {
    buzzer();
  }
}

#endif