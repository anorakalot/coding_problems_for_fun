bool isIsomorphic(char* s, char* t) {
    //ok so isIsomorphic
    //means 

    //for loop
    // isomorphic check if

    //what's the non case for this maybe do that
    //it seems to be if they're not the same size
    //and if there's any two repeating numbers in input s?


    //ok so maybe for loops check until it's '\0' string?

    int index_s = 0;
    int index_t_ = 0;

    int s_size = 0;
    int t_size = 0;

    while(s[index_s] != '\0'){
        
        index_s += 1;
        s_size +=1;
    }
    while(t[index_t_] != '\0'){
        index_t_ += 1;
        t_size +=1;
    }

    printf("s_size = %i\n",s_size);
    printf("t_size = %i\n",t_size);


    return 0;

}
