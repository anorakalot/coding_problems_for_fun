class Solution {
public:
    bool isPowerOfFour(int n) {
        //how to represetn this in binary? 
        //maybe right shift by 2 and see if it's 1
        //1 0000  >> 2 0 0100 >> 2 0001

        // 0101

        //not even
        if (n % 2 != 0 && n != 1){
            return 0;
        }

        while ( n > 0){
            if (n == 1){
                return 1;
            }
            n >>= 2;
            std::cout<< n << std::endl;
        }

        return 0;
    }
};