//#include <iostream>
//using namespace std;
//#include <vector>
#include "stdio.h"
#include <vector>

//homebrew merge_sort with psudeo-code help
std::vector<int> merge(std::vector<int> , std::vector<int> );
int test_func();

std::vector<int> merge_sort(std::vector<int> array_input, int n_input)
{
    // if (n_input <= 1)
    // {
    //     printf("N_INPUT <=1\n");
    //     //return array_input
    //     //return array_input;
    // }

    
    //do low + ((high-low)/2)
    
    if (n_input == 1){
        return array_input;
    }
    //if (n_input >1){
    
    std::vector<int> left_array(array_input.begin(),
                                array_input.begin() + (n_input/2));
    printf("LEFT ARRAY\n");
    for (int i = 0; i < left_array.size(); i++){
        ////std::cout << "array at: " << i << " " << array[i] << std::endl;
        printf("array at %i: %i \n", i, left_array[i]);
    }

    
    std::vector<int> right_array(array_input.begin() + ((n_input/2)+1), array_input.end());

    printf("RIGHT ARRAY\n");
    for (int i = 0; i < right_array.size(); i++){
        ////std::cout << "array at: " << i << " " << array[i] << std::endl;
        printf("array at %i: %i \n", i, right_array[i]);
    }
    
    merge_sort(left_array, (n_input / 2));
    merge_sort(right_array, (n_input / 2));
    
    std::vector<int> merged_array;
    
    return merge(left_array, right_array);
 
    
}

std::vector<int> merge(std::vector<int> left_input, std::vector<int> right_input)
{
    int left_input_index = 0;
    int right_input_index = 0;
    std::vector<int> merged_array;
    int swap;
    int left_input_end = left_input.size() - 1;
    int right_input_end = right_input.size() - 1;
    // int left_input_active=0;
    // int right_input_active=0;
    while (left_input_index > left_input_end && right_input_index > right_input_end)
    {
        if (left_input[left_input_index] > right_input[right_input_index])
        {
            printf("SWAPPING IN MERGE\n");
            swap = left_input[left_input_index];
            left_input[left_input_index] = right_input[right_input_index];
            right_input[right_input_index] = swap;

        } //enf of if statement swap for merge
        if (left_input_index > left_input_end)
        {
            merged_array.push_back(left_input[left_input_index]);
            left_input_index += 1;
            
        }
        if (right_input_index > right_input_end)
        {
            merged_array.push_back(right_input[right_input_index]);
            right_input_index+=1;
        }
    }
    return merged_array;
}

int test_func()
{
    printf("I LIKE APPLES \n");
    return -1;
}
int main()
{
    //gonna use for starting length of array
    //unsigned int n;
    int n; //n is number of inputs
           //std::cin >> n;
    scanf("%i", &n);

    //std::vector<int> array(n);
    std::vector<int> array(n);
    unsigned int input;

    for (int i = 0; i < n; i++)
    {
        //std::cin >> input;

        scanf("%u", &input);
        array[i] = input;
    }

    // //just to test what array is set up properly
    // for (int i = 0; i < n; i++){
    //     //std::cout << "array at: " << i << " " << array[i] << std::endl;
    //     printf("array at %i: %i \n", i, array[i]);
    // }

    //MERGE SORT
    array = merge_sort(array,n);

    //just to test what array is set up properly
    printf("SORTED ARRAY HIGHEST FIRST \n");
    for (int i = 0; i < n; i++){
        ////std::cout << "array at: " << i << " " << array[i] << std::endl;
        printf("array at %i: %i \n", i, array[i]);
    }

    int num_outputs;

    scanf("%i", &num_outputs);

    //printf("num_output: %i \n", num_outputs);
    std::vector<int> placing(n);
    //int curr_placing;
    int placing_input;

    // printf("SORTED ARRAY before getting placing value \n");
    // for (int i = 0; i < n; i++){
    //     ////std::cout << "array at: " << i << " " << array[i] << std::endl;
    //     //printf("array at %i: %i \n", i, array[i]);
    // }

    for (int m = 0; m < num_outputs; m++)
    {
        scanf("%i", &placing_input); // scan for input again and put it into placing array
        placing[m] = placing_input;
        //printf("placing: %i ", placing[m]);
        placing[m] -= 1; //value is just -1 of what placing is
        //ex. placing 5 is array[4] placing 1 is array[0] etc
        //printf("placing[m]: %i,\n",placing[m]);
        //printf("placing_value_before %i: array_placing: %i \n", placing[m], array[placing[m]]); // do printifn in other loop because it first gets input and the outputs
    }

    // printf("SORTED ARRAY after getting placing value \n");
    // for (int i = 0; i < n; i++){
    //     ////std::cout << "array at: " << i << " " << array[i] << std::endl;
    //     printf("array at %i: %i \n", i, array[i]);
    // }
    //printf("placing_value,0 %i: array[0]%i \n", placing[0], array[placing[0]]);

    //outputs placing
    for (int m = 0; m < num_outputs; m++)
    {
        //printf("placing_value %i: array_placing: %i \n", placing[m], array[placing[m]]);
        //printf("%i \n", array[placing[m]]);
        printf("%i\n", array[placing[m]]);
    }

    // //
    // printf("SORTED ARRAY RIGHT BEFORE END \n");
    // for (int i = 0; i < n; i++){
    //     ////std::cout << "array at: " << i << " " << array[i] << std::endl;
    //     printf("array at %i: %i \n", i, array[i]);
    // }

    return 0;
}
