//#include <iostream> 
//using namespace std;
//#include <vector>
#include "stdio.h" 
#include <vector>
 
int main(){
	//gonna use for starting length of array 
    //unsigned int n;
	int n;//n is number of inputs
	//std::cin >> n; 
    scanf("%i", &n);
   
    //std::vector<int> array(n);
    std::vector<float> array(n); 

    float input;
    for (int i = 0; i < n; i++){
        //std::cin >> input; 
        
        scanf("%f", &input);
        array[i] = input;
    }
 
    printf("INPUTTED ARRAY  \n");

    for (int i = 0; i < n; i++){
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
                    array[key_index] = array[x];

                    array[x] = key_value;
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

    for (int i = 0; i < n; i++){
        printf("array at %i: %f \n", i, array[i]);
    }
    

 
    

	return 0;
}