//#include <iostream>
//using namespace std;
//#include <vector>
#include "stdio.h"
#include <cmath>
#include <vector>
#include <algorithm>

// //homebrew merge_sort with psudeo-code help
 std::vector<int> merge(std::vector<int>, std::vector<int>,int *);
// int test_func();
int num_of_candies = 0;
std::vector<int> merge_sort(std::vector<int> array_input, int n_input,int *num_of_candies_merge_sort_input)
{
    // if (n_input <= 1)
    // {
    //     printf("N_INPUT <=1\n");
    //     //return array_input
    //     //return array_input;
    // }

    //do low + ((high-low)/2)

    int end = array_input.size() - 1;
    int start = 0;
    int m;
    // if (n_input % 2 == 0)
    // {
    //     m = (n_input / 2);
    // }
    // else
    // {
    //     m = (n_input + 1) / 2;
    // }
    m = (n_input / 2);

    if (n_input <= 1)
    {
        printf("n_input is %i just returning %i value of array_input[0]\n", n_input, array_input[0]);
        return array_input;
    }
    //if (n_input >1){
    printf("array_input.begin() + m) = %i \n", array_input.begin() + m);
    std::vector<int> left_array(array_input.begin(),
                                array_input.begin() + m); //array_input.end() - (n_input/2))//array_input.begin() + (n_input/2));

    printf("LEFT ARRAY\n");
    for (int i = 0; i < left_array.size(); i++)
    {
        printf("array at %i: %i \n", i, left_array[i]);
    }

    //printf("array_input.begin() + (n_input/2)) = %i \n", array_input.begin() + (n_input / 2));
    std::vector<int> right_array(array_input.begin() + (m), array_input.end());

    printf("RIGHT ARRAY\n");
    for (int i = 0; i < right_array.size(); i++)
    {
        printf("array at %i: %i \n", i, right_array[i]);
    }
    printf("MERGE SORT LEFT ARRAY\n");
    left_array = merge_sort(left_array, m,num_of_candies_merge_sort_input);
    printf("MERGE SORT RIGHT ARRAY\n");
    right_array = merge_sort(right_array, m,num_of_candies_merge_sort_input); // I think making left_array and right_array = merge_sort fixed it

    std::vector<int> merged_array;

    merged_array = merge(left_array, right_array,num_of_candies_merge_sort_input);

    printf("merged ARRAY\n");
    for (int i = 0; i < merged_array.size(); i++)
    {
        printf("array at %i: %i \n", i, merged_array[i]);
    }

    return merged_array;
}

std::vector<int> merge(std::vector<int> left_input, std::vector<int> right_input,int *num_of_candies_merge_input)
{
    int left_input_index = 0;
    int right_input_index = 0;
    std::vector<int> merged_array;
    int swap;
    int left_input_end = left_input.size() - 1;
    int right_input_end = right_input.size() - 1;
    // int left_input_active=0;
    // int right_input_active=0;
    printf("While left_input_index <= left_input_end && right_input_index <= right_input_end\n");
    while (left_input_index <= left_input_end && right_input_index <= right_input_end)
    {
        //pretty sure this means the lowest one gets added to merged array first
        printf("left_input: %i, Right_input: %i\n", left_input[left_input_index], right_input[right_input_index]);
        if (left_input[left_input_index] < right_input[right_input_index])
        {
            printf("adding %i at index %i to merged_array left_input\n", left_input[left_input_index], left_input_index);
            merged_array.push_back(left_input[left_input_index]);
            left_input_index += 1;
        } //end of if statement swap for merge
        else
        {
            //this means right_input is less than left_input meaning
            printf("adding %i at index %i to merged_array right_input\n", right_input[right_input_index], right_input_index);
            merged_array.push_back(right_input[right_input_index]);
            right_input_index += 1;
        }
    }
    printf("While left_input_index <= left_input_end only\n");
    while (left_input_index <= left_input_end)
    {
        printf("adding %i at index %i to merged_array left_input\n", left_input[left_input_index], left_input_index);
        // int index_1 = left_input_index;
        // int index_2 = left_input_index + 1;
        // for (int i = 0; i < right_input.size(); i++)
        // {
        //     if (index_2 >= left_input_end)
                
        //     {
        //         break;
        //     }

        //     if (left_input[index_1] < left_input[index_2])
        //     {
        //         //printf("Swapping %i with %i: \n",array[index_1], array[index_2]);
        //         swap = left_input[index_1];
        //         left_input[index_1] = left_input[index_2];
        //         left_input[index_2] = swap;
        //     }
        //     index_1 += 1;
        //     index_2 += 1;

        // } //end of for loop for bubble sort in mergesort unsorted arrays
        merged_array.push_back(left_input[left_input_index]);
        left_input_index += 1;
    }//end of while left_input_index

    printf("While right_input_index <= right_input_end only\n");
    while (right_input_index <= right_input_end)
    {

        printf("adding %i at index %i to merged_array right_input\n", right_input[right_input_index], right_input_index);
        // int index_1 = right_input_index;
        // int index_2 = right_input_index + 1;
        // for (int i = 0; i < right_input.size(); i++)
        // {
        //     if (index_2 >= right_input_end)
        //         ;
        //     {
        //         break;
        //     }

        //     if (right_input[index_1] < right_input[index_2])
        //     {
        //         //printf("Swapping %i with %i: \n",array[index_1], array[index_2]);
        //         swap = right_input[index_1];
        //         right_input[index_1] = right_input[index_2];
        //         right_input[index_2] = swap;
        //     }
        //     index_1 += 1;
        //     index_2 += 1;

        // } //end of for loop for bubble sort in mergesort unsorted arrays
        merged_array.push_back(right_input[right_input_index]);
        right_input_index += 1;

    } //end of while right_input_index


    // //gonna do one last bubble sort with whole merged_array
    // int index_1 = 0;
    // int index_2 = 1;
    //     for (int i = 0; i < merged_array.size(); i++)
    //     {
    //         if (index_2 >= merged_array.size())
                
    //         {
    //             break;
    //         }

    //         if (merged_array[index_1] < merged_array[index_2])
    //         {
    //             //printf("Swapping %i with %i: \n",array[index_1], array[index_2]);
    //             swap = merged_array[index_1];
    //             merged_array[index_1] = merged_array[index_2];
    //             merged_array[index_2] = swap;
    //         }
    //         index_1 += 1;
    //         index_2 += 1;

    //     } //end of for loop for bubble sort in mergesort unsorted arrays
    printf("merged ARRAY IN FUCT\n");
//    printf("left_input_end %i\n", left_input_end);

    for (int i = 0; i < merged_array.size(); i++)
    {
        printf("array at %i: %i \n", i, merged_array[i]);
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
        //cin >> array[i];
        array[i] = input;
    }

    // //just to test what array is set up properly
    // for (int i = 0; i < n; i++){
    //     //std::cout << "array at: " << i << " " << array[i] << std::endl;
    //     printf("array at %i: %i \n", i, array[i]);
    // }

    //MERGE SORT
    //array = merge_sort(array, n,&num_of_candies);
    //std::sort(array.rbegin(),array.rend());
    std::sort(array.begin(), array.end());

    //just to test what array is set up properly
    printf("SORTED ARRAY \n");
    for (int i = 0; i < n; i++)
    {
        ////std::cout << "array at: " << i << " " << array[i] << std::endl;
        printf("array at %i: %i \n", i, array[i]);
    }

    int number_of_things_to_add;
    int output=0;
    number_of_things_to_add = n /2;
    printf("n value %i\n" , n);
    
    if (n % 2 == 1){
        printf("n value is odd! adding 1 to value\n");
        number_of_things_to_add += 1;
    }

    
    printf("number_of_things_to_add %i\n" , number_of_things_to_add);


    for (int i = 0; i < number_of_things_to_add; i++){
        printf("array[i]: %i\n", array[i]);
        if (array[i] % 2 == 1){
            printf("array[i] is odd! so I'm adding 1 to the array[i] / 2\n");
            printf("array[i]/2 %i\n", (array[i]/2 + 1));
            output += (array[i]/2 + 1);

        }
        else{
            array[i] += (array[i]/2);
        }
        

    }
    //printf("%i")
    
    printf("FINAL_OUTPUT %i",output);
    // int lowest_val;
    // int second_lowest_val;

    // lowest_val = array[0];
    // second_lowest_val = array[1];

    // printf("lowest_val in array: %i\n", lowest_val);
    // printf("second_lowest_val in array: %i\n",second_lowest_val);

    

    // int num_outputs;

    // scanf("%i", &num_outputs);

    // //printf("num_output: %i \n", num_outputs);
    // std::vector<int> placing(num_outputs);
    // //int curr_placing;
    // int placing_input;

    // printf("SORTED ARRAY before getting placing value \n");
    // for (int i = 0; i < n; i++){
    //     ////std::cout << "array at: " << i << " " << array[i] << std::endl;
    //     //printf("array at %i: %i \n", i, array[i]);
    // }

    // for (int m = 0; m < num_outputs; m++)
    // {
    //     scanf("%i", &placing_input); // scan for input again and put it into placing array
    //     placing[m] = placing_input;
    //     //printf("placing: %i ", placing[m]);
    //     placing[m] -= 1; //value is just -1 of what placing is
    //     //ex. placing 5 is array[4] placing 1 is array[0] etc
    //     //printf("placing[m]: %i,\n",placing[m]);
    //     //printf("placing_value_before %i: array_placing: %i \n", placing[m], array[placing[m]]); // do printifn in other loop because it first gets input and the outputs
    // }

    // printf("SORTED ARRAY after getting placing value \n");
    // for (int i = 0; i < n; i++){
    //     ////std::cout << "array at: " << i << " " << array[i] << std::endl;
    //     printf("array at %i: %i \n", i, array[i]);
    // }
    //printf("placing_value,0 %i: array[0]%i \n", placing[0], array[placing[0]]);

    // //outputs placing
    // for (int m = 0; m < num_outputs; m++)
    // {
    //     //printf("placing_value %i: array_placing: %i \n", placing[m], array[placing[m]]);
    //     //printf("%i \n", array[placing[m]]);
    //     printf("%i\n", array[placing[m]]);
    // }

    // //
    // printf("SORTED ARRAY RIGHT BEFORE END \n");
    // for (int i = 0; i < n; i++){
    //     ////std::cout << "array at: " << i << " " << array[i] << std::endl;
    //     printf("array at %i: %i \n", i, array[i]);
    // }

    return 0;
}
