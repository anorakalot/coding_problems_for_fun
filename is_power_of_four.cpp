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
            std::cout<<" in n%2 and n != 1"<<std::endl;
            return 0;
        }
        if (n == 1 || n == 4){
            std::cout<<" in n== 1 and n == 4"<<std::endl;
            return 1;
        }
        if (n % 4 != 0 ){
            std::cout<<" in n%4"<<std::endl;
            return 0;
        }


        //0110
        int return_val = 0;

        while ( n > 0){
        
            if (n == 1){
                std::cout<<"n is now at 1" << std::endl;
                return_val = 1;
                break;
            }
            n >>= 3;
            std::cout<< n << std::endl;
        
        }

        return return_val;
    }
};