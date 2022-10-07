class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        //have it go through each possible neighbor to see if word can be done
        std::cout<<word[0]<< " " << std::endl;
        printf("print out board for debug\n");
        for (int y = 0; y < board.size(); y++){
            for (int x = 0; x < board[y].size(); x++){
                printf("%c ",board[y][x]);
            }
            printf("\n");
        }
        int x_save_space =0;
        int y_save_space = 0;
        

        
        int word_index = 0;
        int found_first_letter =0;
        int valid_word = 0;
        printf("going through board to \n");
        for (int y = 0; y < board.size(); y++){
            for (int x = 0; x < board[y].size(); x++){
                if (board[y][x] == word[0]){//if it finds the first letter in the word sequence
                    printf("Found first letter\n");
                    x_save_space = x;
                    y_save_space = y;

                    
                    found_first_letter =1;
                    word_index = 1;
                    valid_word = 1;
                    while (valid_word == 1){//meaning while ongoing word is valid keep going if not go back to 
                                            //x_save_space and y_save_space
                        if (x+1 <board[y].size()){
                        if (board[y][x+1] == word[word_index]){
                            
                            if(word_index == word.size()-1){//meaning at last part of the word
                               return 1; 
                            }
                            //y stays the same
                            x +=1;
                            
                            word_index +=1;
                            continue; //to avoid going into the other if statements below
                        }//end of y+1 
                        }
                        if (x-1 >=0){
                        if (board[y][x-1] == word[word_index]){
                            if(word_index == word.size()-1){//meaning at last part of the word
                               return 1; 
                            }
                            //y stays the same
                            x -=1;
                            word_index +=1;  
                            continue; //to avoid going into the other if statements below
                        }
                        }
                        if (y+1 < board.size()){
                        if (board[y+1][x] == word[word_index]){
                            if(word_index == word.size()-1){//meaning at last part of the word
                               return 1; 
                            }
                            y+=1;
                            //x stays the same
                            word_index +=1;  
                            continue; //to avoid going into the other if statements below
                        }
                        }
                        if (y-1 >=0){
                        if (board[y-1][x] == word[word_index]){
                            if(word_index == word.size()-1){//meaning at last part of the word
                               return 1; 
                            }
                            y -=1;
                            //x stays the same
                            word_index +=1;
                            continue; //to avoid going into the other if statements below
                        }
                        }
                        
                        
                        //else{//probably is this else statement because it could be y-1 >=0 and still find no
                             //other neighbors
                            
                            //now that I think about it it should just auto go here since every other if 
                            //there is a neighbor should be continued already
                            
                            //meaning none of the adjacent match to next letter in word
                            //reset all variables and get out of while loop
                            word_index = 0;
                            //backtrack to beginning x and y spot
                            x = x_save_space;
                            y = y_save_space;
                            
                            valid_word = 0;
                        //}             
                    }//end of while valid word loop
                }//end of if board[x][y] == word[0] matching letter to first letter in word
                
                
            }//end of for loop x part
            printf("\n");
        }//end of outer for loop y part
        
        
        return 0; //placeholder 
                  //also this might be good because if doesn't return0
    }
};
//next issue is I have to take into account can't use the same letter cell more than once 
//possible have a map that checks if a ceertain y,x value has been used already.