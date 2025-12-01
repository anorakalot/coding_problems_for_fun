int reverseBits(int n) {

//oh wait we'd need multiple different halfs because the binary is not 

//or maybe something else like go through each bit in a for loop and save it in a different int with a 0x80000000

    int return_val = 0x00000000;
    int mask_for_return_val = 0x00000000;
    int mask_for_n = 0x00000001;
    bool bit_val_n = 0;

    int left_shift_for_return_val = 31;

    for (int x = 0; x < 32; x++){
        //first get the first 2^0 bit value of n
        bit_val_n = mask_for_n & n;
        printf("bit_val = %i\n",bit_val_n);
        printf("mask = %x\n",mask_for_n);
        mask_for_n <<= 1;

        return_val |= (bit_val_n << left_shift_for_return_val);

        printf("return_val = %x\n",return_val);
        // return_val |= (bit_val_n << 32);


        left_shift_for_return_val -=1;

        //then move the bit_val_n to return_val 0x80000000 position 
        //so maybe left shift it by a ton?
        // return_val
    }
    return 0;
}