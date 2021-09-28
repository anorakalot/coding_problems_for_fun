//#include <iostream> 
//using namespace std;
//#include <vector>
#include "stdio.h" 
#include <vector>

int main(){
	//gonna use for starting length of array 
    //unsigned int n;
	int n;
	//std::cin >> n; 
    scanf("%i", &n);
   
    //std::vector<int> array(n);
    int array[n]; 
    unsigned int input;
    
    for (int i = 0; i < n; i++){
        //std::cin >> input; 
        
        scanf("%u", &input);
        array[i] = input;
    }

    //just to test what array is set up properly
    for (int i = 0; i < n; i++){
        //std::cout << "array at: " << i << " " << array[i] << std::endl;
        printf("array at %i: %i \n", i, array[i]);
    }

    //need to change selection sort from min to max
    //selection sort
    int sorted_min = 0;
    int swap = 0;
    int sorted_min_index = 0;
    //int curr_item = 0;
    //y is curr item
    int unsorted_min = -4000;
    int unsorted_min_index =0;
    //int y;
    for (int x = 0; x < n; x++){
        sorted_min = array[x];
        sorted_min_index = x;
        //curr_item = x+1;
        //y = x
        unsorted_min = -4000;//if its' this give it value
        //of first array[y] value
        for (int y = x; y < n; y++){
            if(unsorted_min == -4000){
                unsorted_min = array[y];
                unsorted_min_index = y;
            }
            if (array[y] > unsorted_min){
                unsorted_min = array[y];
                unsorted_min_index = y;
            }
        //   if (array[curr_min] > array[y]){
        //     swap = array[curr_min];
        //     array[curr_min] = array[y];
        //     array[y] = swap;
        //   }  
        } // end of inner for loop 
        if (unsorted_min > sorted_min){
            swap = array[sorted_min_index];
            array[sorted_min_index] = array[unsorted_min_index];
            array[unsorted_min_index] = swap;

            // //swap values 
            // swap = sorted_min;
            // sorted_min = unsorted_min;
            // unsorted_min = swap;

            // //swap indexes
            // swap = sorted_min_index; 
            // swap 

        }
    } // end of outer for loop

    //just to test what array is set up properly
     printf("SORTED ARRAY HIGHEST FIRST \n");
    for (int i = 0; i < n; i++){
        //std::cout << "array at: " << i << " " << array[i] << std::endl;
        printf("array at %i: %i \n", i, array[i]);
    }
    //;
    int num_outputs;
    
    scanf("%i",&num_outputs);
    
    printf("num_output: %i \n", num_outputs);
    int placing[n];
    //int curr_placing;

    for (int m = 0; m < num_outputs; m++){
        scanf("%i",&placing[m] ); // scan for input again
        printf("placing: %i ", placing[m]);
        placing[m] -= 1;//value is just -1 of what placing is 
        //ex. placing 5 is array[4] placing 1 is array[0] etc

        //printf("placing_value %i: %i \n", placing[m], array[placing]); // do printifn in other loop because it first gets input and the outputs
    }
    
    //outputs placing
    for (int m = 0; m < num_outputs; m++){
        printf("placing_value %i: %i \n", placing[m], array[placing[m]]);
    }

    
    
	return 0;
}

