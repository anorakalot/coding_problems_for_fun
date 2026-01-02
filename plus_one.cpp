class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //oh so something like get the size then multiply by the power of 10 that's needed
        //then do O(N) to go through the loop adding each value then get the int value then add one to it

        //or maybe there's a simpler way doing it without converting the array itself.

        //because the other way is to do 2 conversions seems like a lot

        //maybe there's a pattern always up the last index up but if it's 9 add 1 to the previous index and so forth

        //start at the last and work way up to the msb
        int curr_index = digits.size() - 1;
        while(true){
            if (digits[curr_index] < 9){
                digits[curr_index] += 1;
                break;    
            }
            else{

                digits[curr_index] = 0;

                if(curr_index > 0){
                    curr_index -= 1;
                }

                //need to add a test case where I add another index to the front if the curr_index is 0
                else if (curr_index == 0){
                     digits.insert(digits.begin(), 0);
                     
                }
            }
        }

        return digits;

    }
};