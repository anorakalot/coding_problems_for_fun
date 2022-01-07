//#include <iostream> 
//using namespace std;
//#include <vector>
#include "stdio.h" 
#include <vector>
 
int main(){
	//gonna use for starting length of array 
    //unsigned int n;
	//int n;//n is number of inputs
	//std::cin >> n; 
    //scanf("%i", &n);
   
    //std::vector<int> array(n);
    std::vector<float> array; 

    float input;
    char exit_code;
    //int input_index = 0;
    while(exit_code != 'z'){
    //for (int i = 0; i < n; i++){
        //std::cin >> input; 

        scanf("%f", &input);
        printf("\ninputting: %f",input);
        //array[input_index] = input;
        array.push_back(input);  
        //input_index +=1;
        
        scanf("%c",&exit_code);
        printf("exit_code: %c\n",exit_code);
    }
    array.pop_back();
    printf("INPUTTED ARRAY  \n");

    for (int i = 0; i < array.size(); i++){
        printf("array at %i: %f \n", i, array[i]);
    }
    
    printf("\n");
    
    //insertion sorting part

    //int key = 1;

    float key_value; 
    int key_index;
    for (int i = 1; i < array.size(); i++){

        key_value = array[i];
        printf("keyvalue: %f \n",key_value);
        key_index = i;
            int i_copy;
            for (int x = i-1; x >= 0; x--){
                printf("array[x]: %f \n",array[x]);
                if (key_value < array[x]){
                    printf("key value less than array[x]\n");

                    //sets key_index value to current array[x] value to move up the array[x] value
                    array[key_index] = array[x];
                    //insert key value in new spot if array[x] is biggger than key
                    array[x] = key_value;
                    //set the new key_index to the correct spot
                    key_index = x; 
                }
                // else{
                //     array[x] = key_value;
                // }
            }

        // if (array[i] < array[i-1]){
        //     //save key value 
        //     key_value = array[key];
        //     //move up 
        //     array[i] = array[i-1];
        //     array[i-1] = key_value;
        //     for (int x = i-2; x > 0; x--){
        //         if (key_value < array[x]){
                
        //         }
        //     }
    }
    

    printf("\n");
    printf("After Sorting  \n");

    for (int i = 0; i < array.size(); i++){
        printf("array at %i: %f \n", i, array[i]);
    }
    

 
    

	return 0;
}