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

//otherwise loading in a route all digitally ups the complexity a lot.
//And I think it leads to easier debugging since if something's going wrong it's likely due to the floor type messing with the sensors so maybe sensor fusion with a computer vision system?

//rj's response
//Then the competitors will know what the robot is going to do
//The idea is that they need to react on the fly to a moving opponent
//It would definitely make the movement programming easier but take away the fun of a chaotic target


//so no line following
//so maybe combination of imu, and ir sensors, and dc motor encoders (and maybe computer vision?)
// and maybe have it be inside a cage of some sort?
// but ir sensors are finicky
//maybe laser (Lidar)? that seems good
// the space would just have

// but how would that be effected with the person standing right by it? 
// have a thing in the code that takes the distance measurement of the other hopefully 3 unobstructed measurements

// need to find a way to also
// use ros? (micro ros) and simulate robot in gazebo.
////////////////////////////////


/*In this basic free RTOS tutorial will use xTaskCreatePinnedToCore() . 
in order to enable us to select which ESP32 core (core 0 or core 1) will run the particular task.*/

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED 15

//dont really need this since in the freertos documentation only is used for xtask_delete and I don't plan on deleting any of these tasks
TaskHandle_t LEDBlinking = NULL;  ///  Task handler fot the LED Task
TaskHandle_t lidar_task_handle = NULL;  ///  Task handler fot the LED Task
TaskHandle_t pwm_motor_task_handle = NULL;

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

//maybe use this lidar https://www.adafruit.com/product/4058?srsltid=AfmBOoraJ1yOCzjVNKmKuj9RDAwVqnrjyV47eyn-3niBIialN0mUVo1qP0w
//it has code examples and how to connect it already
//also it already has a library to use!
//https://github.com/garmin/LIDARLite_Arduino_Library
void lidar_task(void * arg){

    //get_distance_pwm from all sides not 

    //need to figure out a way to tell if it's a human vs ? no I don't see comment below

    //also technically only need the 3 unobstructed lidar readings since that would be enough to tell position because I could tell position based
    //on the other 3 unobstructed measurements

// vTaskDelay blocks a task for a relative, fixed duration from the current time, making it ideal for simple, non-critical delays.
// Conversely, vTaskDelayUntil blocks until an absolute tick count, ensuring consistent, periodic execution (e.g., sensor sampling) by accounting for execution time. 
// need to use vTaskDelayUntil for sensors

//also will need to use it for the pwm motors as well

}
//from me:
// oh fudge there needs to be a way to tell if it's a human blocking the sensor or the wall
// oh wait if it's the wall is only at a certain heigh just add another lidar at the height where a person would be
// but there can be issues with if they cover both
// nvm I think I have a solution
//from rj:
//😂 it should able to drive right at the competitor who's cutting
//from me:
//oh you don't want it to stop?
// 🙂
// yay


//ok so now also need to take into account how this is going to work with 2 seperate motors on each side
//maybe seoerate iut by forward and side?
void pwm_motor_task(void * arg){


}


//what other things would we need


//maybe a task at the beginning to read in the movements that are needed
void read_in_pattern_task(void * arg){

  VTaskSuspend();
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

  
  // vTaskDelayUntil() this is what sets the period of each task it's not when the task is created
  
  //maybe only have below priorities be form 0 to 10 
  xTaskCreatePinnedToCore(BlinkingLED, "BlinkingLED",3000, NULL, 10, &LEDBlinking, 0);

  //maybe keep both of them
  xTaskCreatePinnedToCore(lidar_task, "lidar_task",3000, NULL, 10, &lidar_task_handle, 0);

  xTaskCreatePinnedToCore(pwm_motor_task, "pwm_motor_task",3000, NULL, 10, &pwm_motor_task_handle, 0);


  //have this task be highest priority but since it'll get suspended it'll only run once (set at 11 since no other task should be set higher)
  //also set it as a task in case it needs to be re-read? or maybe just put it in setup?
  xTaskCreatePinnedToCore(read_in_pattern_task, "read-in_pattern_task",3000, NULL, 11, NULL, 0);


}
