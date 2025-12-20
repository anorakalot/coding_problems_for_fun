class Solution {
public:
    bool isPowerOfFour(int n) {
        //how to represetn this in binary? 
        //maybe right shift by 2 and see if it's 1
        //1 0000  >> 2 0 0100 >> 2 0001

        // 0101
        //0
        //not even
        if ((n % 2 != 0 && n != 1 )){// && n % 4 == 0 ){
            return 0;
        }

        else if (n == 1 || n == 4){
            return 1;
        }

        //0110

        while ( n > 0){
        
            if (n == 1){
                return 1;
            }
            n >>= 4;
            std::cout<< n << std::endl;
        
        }

        return 0;
    }
};