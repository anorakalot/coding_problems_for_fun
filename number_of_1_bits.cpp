class Solution {
public:
    int hammingWeight(int n) {
        
        //so to go through have a mask at 0x01 then left shift it
        //then add up if anding both equals more than 0


        
        
        int mask = 0x01;
        int counter = 0;

    while(mask < n){
        if (mask & n > 0){
            counter += 1;
        }
        mask <<= 1;
    }

        // for (int x = 0; x < n; x ++){
            
        // }

    return counter;
    }
};