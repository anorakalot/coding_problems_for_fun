int reverseBits(int n) {
    //ok so the first thing is how to convert to binary
    int counter = 0;

    //have something that goes from 2^n to 2^n-1 to 2^n-2 all the way to 2^0

    printf("n= %i \n",n);
    //then in here we would make it so that just convert it to not? 

    //or maybe we don't need to convert to binary


    // int result = 
    // return ~(n);//this doesn't work just returns negative value

    //oh wait it means reverse in terms of splitting down the middle and replaceing each side

    int first_half;

    int second_half;

    first_half = (0xFFFF0000 & n) >> 16;

    second_half = (0x0000FFFF) & n << 16;

    
    return 0;
}