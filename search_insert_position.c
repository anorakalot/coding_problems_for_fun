int searchInsert(int* nums, int numsSize, int target) {
    //binary search? 
    //check if the middle position is 

    //test case 1 is solved at least
    int low = 0;
    int high = numsSize - 1;
    int middle = 0;

    // if (low ==)
    while( nums[middle] != target ) { 

    middle = (high + low) / 2;
    printf("middle = %i\n ",middle);

    printf("nums[middle] = %i\n ",nums[middle]);

    if (nums[middle] > target){
    printf("nums[middle] > target\n");
    high = middle;
    }

    else if( nums[middle] < target){
    printf("nums[middle] < target\n");
    low = middle;
    }

    else if (middle == 0){
        middle += 1;
        return middle;
    }

    else if (middle == numsSize-1){
        middle +=1;
        return middle;
    }

    else{
        return middle;
    }

    }
    return 0;
}