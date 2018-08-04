#ifndef sensors_h
#define sensors_h

#include <Arduino.h>
#include <PID_v1.h>

#include "config_schema.h" 
#include "user_config.h"

#if SENSOR == MLX
  #include <Adafruit_MLX90614.h>

#elif SENSOR == NTC
  #include "thermistor.h"
  // Init Thermistor object

#endif


//init PID
PID myPID(&tempDiff, &fan_pwm, &config.temp_offset,kp,ki,kd, REVERSE);



#if SENSOR == MLX
  Adafruit_MLX90614 mlx = Adafruit_MLX90614();
#elif SENSOR == NTC
  THERMISTOR thermistor(NTC_PIN,        // Analog pin
                        100000,          // Nominal resistance at 25 ºC
                        3950,           // thermistor's beta coefficient
                        97500);         // Value of the series resistor
#endif


/** Temperature handler
  * Compages current temp with desired temp every 5 seconds 
  * (Configure via INTERVAL variable in header)
  * taking the max allowed offset into account.
  * generate a proper PID calculated PWM fan speed value
  */
void handleTempLoop(){
  if (millis() - lastReadTemp >= INTERVAL){  // if INTERVAL has passed
    lastReadTemp = millis(); 
    #if SENSOR == NTC
      //this loop is a trick to get a more stable temp by averaging over 5 readings (avgLoop in header)
      avgInt = 0;
      for(int i=0; i < avgLoop; i++) {
        double tInt = thermistor.read() / 10.0;
        avgInt += tInt;
        delay(100);
      }
      tempInt = avgInt/avgLoop;
    #elif SENSOR == MLX
      tempInt = mlx.readObjectTempC();
    #endif

    //calculate setpoint (tempDiff)
    tempDiff = tempInt - config.desired_temp;
    if(tempDiff < 0) {
      tempDiff = 0;
    }

  Serial.print("tObject = "); Serial.print(tempInt); Serial.println("*C");

    //process PID
    myPID.Compute();
    Serial.println(fan_pwm);
   // connectMqtt();
    //apply PID processed fan_pwm
   // publishMessage("/fishtank/temperature", String(tempInt));
    //publishMessage("/fishtank/fan_pwm", String(fan_pwm/250*100));
    analogWrite(FAN_PIN, fan_pwm);
  }
}


void handleWaterLevel() {
  if (millis() - lastReadLevel >= INTERVAL){  // if INTERVAL has passed
    lastReadLevel = millis(); 
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    duration = pulseIn(ECHO_PIN, HIGH);
    distance = duration*0.034/2;
    if (distance >= 200 || distance <= 0){
      Serial.println("Distance Out of range");
    }
    Serial.println(distance);
  }
}

#endif