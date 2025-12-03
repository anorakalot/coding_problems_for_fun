int searchInsert(int* nums, int numsSize, int target) {
    //binary search? 
    //check if the middle position is 

    //test case 1 is solved at least
    int low = 0;
    int high = numsSize - 1;
    int middle = 0;

    printf("numsSize = %i\n",numsSize);

    int counter = 0;

    while( nums[middle] != target ) { 
    
        printf("counter = %i\n",counter);

        printf("low = %i\n", low);
        printf("high = %i\n", high);
        middle = (high + low) / 2;
        printf("middle = %i\n ",middle);

        printf("nums[middle] = %i\n",nums[middle]);

        if (nums[middle] > target && !(middle >=numsSize-1) && low < high && low != high){
        printf("nums[middle] > target\n\n");
        high = middle - 1;
        }

        else if( nums[middle] < target && middle != 0 && low < high && low != high ){
        printf("nums[middle] < target\n\n");
        low = middle + 1;
        }

        else if (middle == 0){
            printf("middle == 0 case \n\n");
            if (target > nums[middle]){
                middle += 1;
            }
            

            return middle;
        }

        else if (middle >= (numsSize-1)){
            printf("middle >= numsSize-1 case\n\n");
            middle +=1;
            return middle;
        }

        else{
            return middle;
        }

        counter += 1;
    }
    return 0;
}