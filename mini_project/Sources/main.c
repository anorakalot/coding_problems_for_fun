/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include<stdio.h>
#include<stdlib.h>


#include "fsl_device_registers.h"

//static int i = 0;
int a = 16807;
int m = 2147483647;
int seed = 6;
int random =5;


void software_delay(unsigned long delay)
{
	while (delay > 0) delay--;
}

unsigned short ADC_read10bits_0(void){
//	ADC0_SC1A
	//ADC0_SC1A = 0x1A; //Write to SC1A to start conversion from ADC_0
	//ADC0_SC1A = 0x00;
	//ADC0_SC1A = 0x00;
	//ADC0_SC1A= 0 & ADC_SC1_ADCH_MASK;
	ADC0_SC1A = 0x00;
	while(ADC0_SC2 & ADC_SC2_ADACT_MASK); // Conversion in progress
	while(!(ADC0_SC1A & ADC_SC1_COCO_MASK)); // Until conversion complete
	return ADC0_RA;



	//return 0;//placeholder
}

unsigned short ADC_read10bits_1(void){
//	ADC0_SC1A
	//ADC0_SC1A = 0x1A; //Write to SC1A to start conversion from ADC_0
	//ADC0_SC1A = 0x00;
	//ADC0_SC1A = 0x00;
	//ADC0_SC1A= 0 & ADC_SC1_ADCH_MASK;
	ADC1_SC1A = 0x00;
	while(ADC1_SC2 & ADC_SC2_ADACT_MASK); // Conversion in progress
	while(!(ADC1_SC1A & ADC_SC1_COCO_MASK)); // Until conversion complete
	return ADC1_RA;



	//return 0;//placeholder
}
unsigned short ADC_read10bits_2(void){
//	ADC0_SC1A
	//ADC0_SC1A = 0x1A; //Write to SC1A to start conversion from ADC_0
	//ADC0_SC1A = 0x00;
	//ADC0_SC1A = 0x00;
	//ADC0_SC1A= 0 & ADC_SC1_ADCH_MASK;
	ADC0_SC1A = 0x01;
	while(ADC0_SC2 & ADC_SC2_ADACT_MASK); // Conversion in progress
	while(!(ADC0_SC1A & ADC_SC1_COCO_MASK)); // Until conversion complete
	return ADC0_RA;



	//return 0;//placeholder
}

int generate_random_num (void){


//	seed = (a * seed) % m;
//
//	//random = seed / m;
//
//	random = seed % 4;
//	//random = random % 4;
//	//seed >> 5;
//	seed += 3;

	random = (rand() % (3-0+1)) + 0;
	//random = (rand() % (1-0+1)) + 0;//only does first 2 led's
	return random;

}
// void game_init(){
//  //motor_state = MOTOR_INIT;
//  game_state = GAME_INIT;
// }


int main(void)
{
	unsigned short photo_res_0 = 0;
	unsigned short photo_res_1 = 0;
	unsigned short photo_res_2 = 0;
	unsigned short photo_res_3 = 0;

	srand((unsigned)time());

	//SETTING UP PORTS
	//clock gating
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK; //Port C clock gating
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK; //Port D clock gating

	//ADC
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;//enable ADC clock
	//SIM_SCGC6 |= SIM_SCGC6_ADC1_MASK;//enable ADC1 clock


	ADC0_CFG1 =0x08;
	//ADC1_CFG1 =0x08;

	//above is set adc to 10-bit conversion 0-1023 values

	//ADC0_CFG1 =0x0C;

	//0000 1000
	ADC0_SC1A =0x1F;
	//ADC1_SC1A =0x1F;

	//gpio
	//0100 at start is just conf first 4 is actual setup
	PORTC_GPCLR = 0x01BF0100;//sets up 0-5 & 7-8
	PORTD_GPCLR = 0x00FF0100;//sets up 0-7

	//input/output
	GPIOC_PDDR = 0x0000000F;//sets 4-5 & 7-8 as input 0-3 as output
	GPIOD_PDDR = 0x000000FF;//sets 0-7 as output

	//setting global variables
	int mole_array[8];//4 indexes for 1 led on state
	//1 for all led's on and 1 for all led's off
    //1 for success , 1 for failure went from (6-8)
	mole_array[0] = 0x1;
	mole_array[1] = 0x2;
	mole_array[2] = 0x4;
	mole_array[3] = 0x8;
	mole_array[4] = 0x0;//all off
	mole_array[5] = 0xF;//all on
    mole_array[6] = 0xC;//successs
    mole_array[7] = 0x3;//failure
	int mole_index = 0;


	int seg_array[10];
	seg_array[0] =0x7E;
	seg_array[1] =0x30;
	seg_array[2] =0x6D;
	seg_array[3] =0x79;
	seg_array[4] =0x33;
	seg_array[5] =0x5B;
	seg_array[6] =0x5F;
	seg_array[7] =0x70;
	seg_array[8] =0x7F;
	seg_array[9] =0x7B;
	int seg_index = 0;

	unsigned long delay = 0x100000; /*Delay Value*/
    unsigned long delay_fsm = 0x100000;
	//initial output
    unsigned short res_0_result=0;
    unsigned short res_2_result=0;
    unsigned short num_of_moles = 10;
    unsigned short score=0;
    unsigned short high_score = 0;
	GPIOC_PDOR = 0x1;
    enum GAME_STATES {GAME_INIT,LED_LIGHT ,PHOTORESISTOR_CHECK,SUCCESS_CHECK,FAILURE_CHECK, END_GAME_SCORE,RESET } game_state;

    game_state = GAME_INIT;

    GPIOD_PDOR = seg_array[0];
    software_delay(delay);

    GPIOC_PDOR = mole_array[5];
    software_delay(delay);

    GPIOC_PDOR = mole_array[4];
    software_delay(delay);

    /* This for loop should be replaced. By default this loop allows a single stepping. */
	for (;;) {


//void game_tick(){
	switch(game_state){
    case GAME_INIT:
        game_state = LED_LIGHT;
        break;
    case LED_LIGHT:
        game_state = PHOTORESISTOR_CHECK;
        break;
    case PHOTORESISTOR_CHECK:
        // game_state = LED_LIGHT;
        if (res_0_result == 1 || res_2_result == 1){
            game_state = SUCCESS_CHECK;
        }
        else{
            game_state = FAILURE_CHECK;
        }
        break;
    case SUCCESS_CHECK:
        if (num_of_moles <=0){//handle num of moles in success and failure states
            game_state = END_GAME_SCORE;
        }
        else{
            game_state = LED_LIGHT;
        }
        break;
    case FAILURE_CHECK:
        if (num_of_moles <=0){
            game_state = END_GAME_SCORE;
        }
        else{
            game_state = LED_LIGHT;
        }
        break;
    case END_GAME_SCORE:
        //game_state = END_GAME_SCORE;
        //put reset option here later
        //software_delay(delay);
        //software_delay(delay);
        photo_res_0 = ADC_read10bits_0();
        //photo_res_2 = ADC_read10bits_2();
         if (photo_res_0< 200){
             game_state = RESET;
         }
         else{
        	 game_state = END_GAME_SCORE;
         }
        break;
    case RESET:
        game_state = GAME_INIT;
        //should just go right back to game init if game is reset
        break;

	default:
		game_state = LED_LIGHT;
        break;
	}//end of transitions
//     void software_delay(unsigned long delay)//delay for reference
// {
// 	while (delay > 0) delay--;
// }
	switch(game_state){//actions
    case GAME_INIT:
        //nothing should happen
        GPIOC_PDOR = mole_array[5];
        software_delay(delay);

        GPIOC_PDOR = mole_array[4];
        software_delay(delay);
        break;
    case LED_LIGHT:
        mole_index = generate_random_num();
        GPIOC_PDOR = mole_array[mole_index];

        break;
    case PHOTORESISTOR_CHECK:
        //delay_fsm = 0x100000;
        delay_fsm = 0x30000;//0xA0000,A0000,0x80000,7,4
    	res_0_result = 0;
        res_2_result = 0;

        if (mole_index == 0 || mole_index == 1){//if index 0 or 1
            while(delay_fsm>0){
                delay_fsm--;
                photo_res_0 = ADC_read10bits_0();
                photo_res_2 = ADC_read10bits_2();

                if (photo_res_0 < 200 && photo_res_2<200){
                	//nothing
					res_0_result = 0;
					break;
                }
                else if (photo_res_2<200){
                	res_0_result = 0;
                	break;
                }
                else if (photo_res_0< 200){
                //if (photo_res_1<200){
                	res_0_result = 1;
                    break;
                }

            }//end of while delay loop
        }//end of if mole 0 1

        else {//mole 2 3

            while(delay_fsm>0){
                delay_fsm--;
                photo_res_0 = ADC_read10bits_0();
                photo_res_2 = ADC_read10bits_2();
                if (photo_res_0 < 200 && photo_res_2<200){
                	//nothing
					res_2_result = 0;
					break;
                }
                else if (photo_res_0<200){
				res_2_result = 0;
				break;
                }

                if (photo_res_2< 200){
                    res_2_result = 1;
                    break;
                }

            }//end of while delay loop

        }//end of else

        break;
    case SUCCESS_CHECK://TBF
        score += 1;
        GPIOC_PDOR = mole_array[6];
        software_delay(delay);
        software_delay(delay);

        GPIOC_PDOR= mole_array[4];
        software_delay(delay);

        num_of_moles-=1;
        break;
    case FAILURE_CHECK://TBF
        //score = score; //score stays the same
        GPIOC_PDOR = mole_array[7];
        software_delay(delay);
        software_delay(delay);
        GPIOC_PDOR= mole_array[4];
        software_delay(delay);

        num_of_moles-=1;
        break;
    case END_GAME_SCORE:
    	if (high_score > score){
    		//nothing
    		seg_array[score];
    		software_delay(delay);
    		software_delay(delay);
    		if (high_score <=10){
    			seg_array[high_score];
    			software_delay(delay);
    		}

    	}
    	else if (score==10){
            seg_index = 9;
        }
        else{
            seg_index = score;
        }

        GPIOD_PDOR = seg_array[seg_index];
        //software_delay(delay);
        break;
    case RESET:
        num_of_moles = 10;//reset moles back up
        mole_index = 0;
        seg_index = 0;
        //GPIOD_PDOR = 0x00;//reset outputs
        //GPIOD_PDOR = seg_array[0];
        GPIOC_PDOR = mole_array[5];
        score = 0;
        res_0_result = 0;
        res_2_result = 0;
        break;


	}//end of actions
//}

	}//end of infinite for loop
	/* Never leave main */
	return 0;
}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////

////proto FSM
//void game_init(){
//  //motor_state = MOTOR_INIT;
//  motor_state = GAME_INIT;
//}
//
//enum GAME_STATES {GAME_INIT,LED ,PHOTORESISTOR , END_GAME_SCORE } game_state;
//
//void game_tick(){
//	switch(game_state){
//
//	default:
//		game_state = LED;
//	}//end of transitions
//	switch(game_state){
//
//
//	}//end of actions
//}


//	   software_delay(delay);
//	   GPIOC_PDOR = 0x3;
	   //software_delay(delay);
	   //GPIOC_PDOR = 0xF;
	   //software_delay(delay);
	   //GPIOC_PDOR = 0x1;
//	   software_delay(delay);
//	   GPIOC_PDOR = 0x0;


//part of random testing if out of bounds
//printf("apples\n");
//		if (mole_index > 3){
//			mole_index = 3;
//		}
//		else if (mole_index < 0){
//			mole_index = 0;
//		}


//FORMER FOR LOOP
//		//7 seg testing
		// software_delay(delay);
		// GPIOD_PDOR = seg_array[seg_index];
		// seg_index +=1;
		// if (seg_index >9){
		// 	seg_index = 0;
		// }
//

		//GPIOD_PDOR = seg_array[0];


//		software_delay(delay);
//		GPIOC_PDOR = mole_array[mole_index];
//		mole_index +=1;
//		if (mole_index >=4){
//			mole_index = 0;
//		}

		//test random led
//		software_delay(delay);
//		mole_index = generate_random_num();
//		GPIOC_PDOR = mole_array[mole_index];
		//software_delay(delay);
//		photo_res_0 = ADC_read10bits_0();//WORKS
		//photo_res_1 = ADC_read10bits_1();
//		photo_res_2 = ADC_read10bits_2();
		//photo_res_3 = ADC_read10bits_3();
		//printf("photo_res_1\n");
		// if (photo_res_2 < 200){//ACTUALLY this should be cuttoff
		// 	GPIOC_PDOR = mole_array[0];
		// }
		// else if (photo_res_2 < 400){//CUT OFF POINT
		// 	GPIOC_PDOR = mole_array[1];
		// }
		// else if (photo_res_2 < 600){
		// 	GPIOC_PDOR = mole_array[2];
		// }
		// else if (photo_res_2 < 800){
		// 	GPIOC_PDOR = mole_array[3];
		// }
		// else if (photo_res_0 <=1023){
		// 	GPIOC_PDOR = mole_array[4];
		// }
//		if (photo_res_1 < 2000){//500
//			GPIOC_PDOR = mole_array[0];//first led
//		}
//		else if (photo_res_1 >9000){
//			GPIOC_PDOR = mole_array[3];//fourth led
//		}

//		else{
//			GPIOC_PDOR = mole_array[1];//second led
//		}

