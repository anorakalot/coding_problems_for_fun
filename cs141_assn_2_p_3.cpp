//#include <iostream>
//using namespace std;
//#include <vector>
#include "stdio.h"
#include <cmath>
#include <vector>
#include <algorithm>
//maximise number of digits vs highest number
//1first maximis number of digits
void get_output_candles(int * input_money,std::vector<int> & array , std::vector<int> & num_for_output,int offset,int *last_value_added){
    for (int i = array.size()-1; i >= 0 ; i--){
        printf("array at %i: %i \n", i, array[i]);
        *input_money -= array[i];
        printf("input_money: %i\n",*input_money);
        if(*input_money > 0){
            num_for_output.push_back(i+1);
            printf("pushing back value i+1:%i\n ",(i+1));
            *last_value_added = array[i];
            i+=1;
        }
        else if(*input_money <0){
            *input_money+= array[i];
            printf("current array[i] value to high go to next one\n");
        }




    }    
    //if 

}
int main()
{
    //gonna use for starting length of array
    //unsigned int n;
    int input_money; //n is number of inputs
           //std::cin >> n;
    scanf("%i",&input_money);
    printf("input_money %i\n",input_money);
    //std::vector<int> array(n);
    std::vector<int> array(9);
    unsigned int input;

    for (int i = 0; i < 9; i++)
    {
        //std::cin >> input;

        scanf("%u", &input);
        //cin >> array[i];
        array[i] = input;
    }

    //just to test what array is set up properly
    for (int i = 0; i < 9; i++){
        //std::cout << "array at: " << i << " " << array[i] << std::endl;
        printf("array at %i: %i \n", i, array[i]);
    }

    //MERGE SORT
    //array = merge_sort(array, n,&num_of_candies);
    //std::sort(array.rbegin(),array.rend());
    //std::sort(array.begin(), array.end());

    std::vector<int> num_for_output;
    int output;
    int last_value_added;
    int offset=0;

    printf("\n\n");
    //just to test what array is set up properly
    
    while(1){    
    get_output_candles(&input_money,array,num_for_output,offset,&last_value_added);
    printf("input_money_outside_function %i\n" , input_money);
    break;
    }

    
    printf("Outside of pushing to num_for_output for loop \n");
    printf("num_for_output.size()%i\n",num_for_output.size() );
    
    for (int i = 0; i < num_for_output.size(); ++i){
        printf("num_for_output at %i: %i \n", i, num_for_output[i]);
        printf("i:%i\n" ,i);
    }
    printf("outside_loop\n");
    printf("num_for_output at %i: %i \n", 1, num_for_output[1]);
    //printf("%i")
    


    return 0;
}
