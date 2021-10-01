#include "stdio.h"
#include <vector>

int main()
{

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

    //just to test what array is set up properly
    for (int i = 0; i < n; i++)
    {
        //std::cout << "array at: " << i << " " << array[i] << std::endl;
        printf("array at %i: %i \n", i, array[i]);
    }
    int index_1;
    int index_2;

    int swap;

  

    int num_of_swaps_total=0;
    int num_of_swaps_iter = 1;

    //bubble sort
    while (num_of_swaps_iter > 0)
    {
        num_of_swaps_iter = 0;
        index_1 = 0;
        index_2 = 1;
        for (int i = 0; i < n; i++)
        {
            if (index_2 >= n)
            {
                break;
            }
            
            if (array[index_1] > array[index_2])
            {
                printf("Swapping %i with %i: \n",array[index_1], array[index_2]);
                swap = array[index_1];
                array[index_1] = array[index_2];
                array[index_2] = swap;
                num_of_swaps_iter += 1;
                num_of_swaps_total += 1;
            }
            index_1+=1;
            index_2+=1;

        }//end of for loop
        printf("num_of_swaps_iter %i" , num_of_swaps_iter);
    } //end of while loop


    printf("SORTED ARRAY BUBBLE SORT \n");
    for (int i = 0; i < n; i++)
    {
        ////std::cout << "array at: " << i << " " << array[i] << std::endl;
        printf("array at %i: %i \n", i, array[i]);
    };

    printf("num_of_swaps_total %i",num_of_swaps_total);

}