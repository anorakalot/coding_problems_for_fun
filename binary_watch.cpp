class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        //so the hours are a nibble 8 4 2 1 (values valid are 0-11)
        //and the minutes are a nibble and a half 32 16 8 4 2 1 (values valid 0-59)
        
        uint8_t hours = 0;
        uint8_t minutes = 0;
        
        //bit counts

        vector<string> return_string;

        if (turnedOn >= 9){
            //return empty string
            return return_string;
        }

        // lets' just do a test case then turnedOn 1 would just be loop through each one in binary

        // but I'm still not sure how the 2 would work?

        //like how to randomly do each possible variation for 2 

        //because then you would check it's in the valid value ranges


        return return_string;
    }
};