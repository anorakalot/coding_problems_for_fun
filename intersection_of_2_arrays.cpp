class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> return_arr;

        // return_arr.push_back();

        //probably do a hash table
        unordered_map<int, int> unique_val_map;

        //so maybe solution is to do 2 for loops 1 adding all of them to the unordmered map
        //then for the next vector checking if it contains it already and if it does add to the return_arr
        // maybe the second int is how many times it shows up? 

        for (int x = 0; x < nums1.size(); x++){
            if (unique_val_map.count(nums1[x]) == 0){
                unique_val_map[nums1[x]] = 0;
            }
        }

        for (int x = 0; x < nums2.size(); x++){
            if (unique_val_map.count(nums2[x]) >=1){
                if ((unique_val_map[nums2[x]]) == 0){
                    return_arr.push_back(nums2[x]);
                }
                //to stop repeat values
                unique_val_map[nums2[x]] += 1;  
            }
        }

        //need to do something with the unique_val  
        return return_arr;

        
    }
};


//c version below
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
// int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    
//     //due to malloc being dependent on the final answer maybe don't allocate it until the very end?
//     //or maybe allocate it with nums1size + nums2size?
//     int *return_array;
//     return_array = malloc((the size of the array) * sizeof(*return_array));

//     //so anything that shows up in both

//     //the simplest soln is to do 0n^2 loopfor each one in the smallest array loop through the 
//     //other array checking if any of the values in it are equal then add that to the return array
//     // probably don't want to do that


// }