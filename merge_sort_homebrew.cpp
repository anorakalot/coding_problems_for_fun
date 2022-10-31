#include "stdio.h"
#include <cmath>
#include <vector>
#include <algorithm>

// //homebrew merge_sort with psudeo-code help
std::vector<int> merge(std::vector<int>, std::vector<int>);
// int test_func();
//int num_of_candies = 0;
std::vector<int> merge_sort(std::vector<int> array_input, int n_input)
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
    if (n_input % 2 == 0)
    {
        m = (n_input / 2);
    }
    else
    {
        m = (n_input  / 2) + 1;
    }
    // m = (n_input / 2);

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
    left_array = merge_sort(left_array, m); // m rounds down so when odd it makes mistakes of where stuff is (fix that for odd inputs)
    printf("MERGE SORT RIGHT ARRAY\n");
    right_array = merge_sort(right_array, m); // I think making left_array and right_array = merge_sort fixed it

    std::vector<int> merged_array;

    merged_array = merge(left_array, right_array);

    printf("merged ARRAY\n");
    for (int i = 0; i < merged_array.size(); i++)
    {
        printf("array at %i: %i \n", i, merged_array[i]);
    }

    return merged_array;
}

std::vector<int> merge(std::vector<int> left_input, std::vector<int> right_input)
{
    //int total_sum;
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
        merged_array.push_back(left_input[left_input_index]);
        left_input_index += 1;
    }//end of while left_input_index

    printf("While right_input_index <= right_input_end only\n");
    while (right_input_index <= right_input_end)
    {

        printf("adding %i at index %i to merged_array right_input\n", right_input[right_input_index], right_input_index);
        merged_array.push_back(right_input[right_input_index]);
        right_input_index += 1;

    } //end of while right_input_index


    printf("merged ARRAY IN FUCT\n");
//    printf("left_input_end %i\n", left_input_end);

    for (int i = 0; i < merged_array.size(); i++)
    {
        printf("array at %i: %i \n", i, merged_array[i]);
    }

    return merged_array;
}


int main(){

    int n=0; //n is number of inputs
    scanf("%i", &n);
    printf("n_value:%i \n", n);
    int input;
    std::vector<int> array(n);
    
    for (int i = 0; i < n; i++)
    {
        //std::cin >> input;
        printf("INside input loop\n");
        scanf("%i", &input);
        //cin >> array[i];
        array[i] = input;
    }    

    printf("UNSORTED ARRAY \n");
    for (int i = 0; i < n; i++)
    {
        ////std::cout << "array at: " << i << " " << array[i] << std::endl;
        printf("array at %i: %i \n", i, array[i]);
    }

    array = merge_sort(array,n);
    
    printf("UNSORTED ARRAY \n");
    for (int i = 0; i < n; i++)
    {
        ////std::cout << "array at: " << i << " " << array[i] << std::endl;
        printf("array at %i: %i \n", i, array[i]);
    }
}