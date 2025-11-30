int reverseBits(int n) {

    //oh wait it means reverse in terms of splitting down the middle and replaceing each side

    int first_half;

    int second_half;

    first_half = (0xFFFF0000 & n) >> 16;

    printf("first_half = %x\n",first_half);

    second_half = (0x0000FFFF & n); //<< 16;

    printf("second_half = %x\n",second_half);

//oh wait we'd need multiple different halfs because the binary is not 

//or maybe something else like go through each bit in a for loop and save it in a different int with a 0x80000000

    return 0;
}