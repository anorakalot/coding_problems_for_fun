//ok so this will be the starting file for the tatami robot i'll speeprate it into seperate files as I work on it
////////////////////////////////
//DESIGN
//can't use stepper motors due to size and weight of tatami
////have to use dc encoders code can take that from my senior design project in order to go straight but even then I knew that was fully straight
//
//
//need to figure out ways to keep it straight design wise
//seems to just need to
// maybe a line follower robot is best because you'd just have to lay doenw the line ahead of time
// maybe make it like a certain material so it's easy to lay down and works with a lot of different floor colors
////////////////////////////////


/*In this basic free RTOS tutorial will use xTaskCreatePinnedToCore() . 
in order to enable us to select which ESP32 core (core 0 or core 1) will run the particular task.*/

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED 15

TaskHandle_t LEDBlinking = NULL;  ///  Task handler fot the LED Task

//==============================================================================================//
// Function to be implemented the LED task is called 
void BlinkingLED(void *arg){
  for(;;){
    Serial.println("LED_Task To Core0");
    digitalWrite(LED, HIGH);
    vTaskDelay(250/ portTICK_RATE_MS);
    digitalWrite(LED, LOW);
    vTaskDelay(250/ portTICK_RATE_MS);
  }
}
//===========================================================================================//
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  Serial.println("Hello, ESP32 with FreeRTOS !");
}

void loop() {
  // put your main code here, to run repeatedly:

                        // TaskFunction_t pvTaskCode,
                        //  const char * const pcName,
                        //  const configSTACK_DEPTH_TYPE uxStackDepth,
                        //  void *pvParameters,
                        //  UBaseType_t uxPriority,
                        //  TaskHandle_t *pxCreatedTask
                        //last is core which is specific to esp32

  xTaskCreatePinnedToCore(BlinkingLED, "BlinkingLED",3000, NULL, 10, &LEDBlinking, 0);
}
