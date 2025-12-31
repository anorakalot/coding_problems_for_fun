class Solution {
public:
    int binaryGap(int n) {
        //ok so a preliminary solution is to do just a bit loop over each bit (masking with and to get only the value we're looking at right now)
        // then left shift that bit mask by 1

        int mask = 0x01;

        int highest_counter = 0;
        int curr_counter = 0;

        //first check that it starts at a 1 then keep track of the times it shows up a 1 then 2 different cases based if 
        //there already was a one or not
        for (int x = 0; x < 10; x++){
            
        }

    }
};