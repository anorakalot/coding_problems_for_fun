int reverseBits(int n) {

//oh wait we'd need multiple different halfs because the binary is not 

//or maybe something else like go through each bit in a for loop and save it in a different int with a 0x80000000

    int return_val = 0x00000000;
    int mask = 0x00000001;
    bool bit_val_n = 0;

    for (int x = 0; x < 32: x++){
        //first get the first 2^0 bit value of n
        bit_val_n = mask & n;

        //then move the bit_val_n to return_val 0x80000000 position 
        //so maybe left shift it by a ton?
        // return_val
    }
    return 0;
}