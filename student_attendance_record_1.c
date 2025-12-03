bool checkRecord(char* s) {
    int s_index = 0;

    int absent_count = 0;
    int late_consecutive_count = 0;

    while (s[s_index] != '\0'){
        if (s[s_index] == 'A'){
            absent_count += 1;
        }

        if (s[s_index] == 'L'){
            printf("L\n");
            late_consecutive_count += 1; 
            printf("late_consecutive_count = %i",late_consecutive_count);
            if(late_consecutive_count >= 3){
                return 0;
            }
        }
        else{
            printf("L else\n");
            late_consecutive_count = 0;
        }
        s_index ++;
        
    }

    if (absent_count  >= 2){
        return 0;
    }

    return 1;

    

}