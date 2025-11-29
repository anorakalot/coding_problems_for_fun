int searchInsert(int* nums, int numsSize, int target) {
    //binary search? 
    //check if the middle position is 

    //test case 1 is solved at least
    int low = 0;
    int high = numsSize - 1;
    int middle = 0;

    int counter = 0;

    while( nums[middle] != target ) { 
    
    printf("counter = %i\n",counter);

    middle = (high + low) / 2;
    printf("middle = %i\n ",middle);

    printf("nums[middle] = %i\n ",nums[middle]);

    if (nums[middle] > target && !(middle >=numsSize-1)){
    printf("nums[middle] > target\n");
    high = middle;
    }

    else if( nums[middle] < target && middle != 0){
    printf("nums[middle] < target\n");
    low = middle;
    }

    else if (middle == 0){
        middle += 1;
        return middle;
    }

    else if (middle >= (numsSize-1)){
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