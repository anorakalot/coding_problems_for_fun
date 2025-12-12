/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    
    //due to malloc being dependent on the final answer maybe don't allocate it until the very end?
    //or maybe allocate it with nums1size + nums2size?
    int *return_array;
    return_array = malloc((the size of the array) * sizeof(*return_array));

    //so anything that shows up in both

    //the simplest soln is to do 0n^2 loopfor each one in the smallest array loop through the 
    //other array checking if any of the values in it are equal then add that to the return array
    // probably don't want to do that


}