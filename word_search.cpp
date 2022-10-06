class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        //have it go through each possible neighbor to see if word can be done
        std::cout<<word[0]<< " " << std::endl;
        printf("print out board for debug\n");
        for (int x = 0; x < board.size(); x++){
            for (int y = 0; y < board[x].size(); y++){
                printf("%c ",board[x][y]);
            }
            printf("\n");
        }
        int x_save_space =0;
        int y_save_space = 0;
        

        
        int word_index = 0;
        int found_first_letter =0;
        int valid_word = 0;
        printf("going through board to \n");
        for (int x = 0; x < board.size(); x++){
            for (int y = 0; y < board[x].size(); y++){
                if (board[x][y] == word[0]){//if it finds the first letter in the word sequence
                    x_save_space = x;
                    y_save_space = y;

                    
                    found_first_letter =1;
                    word_index = 1;
                    valid_word = 1;
                    while (valid_word == 1){//meaning while ongoing word is valid keep going if not go back to 
                                            //x_save_space and y_save_space
                        if (board[x][y+1] == word[word_index]){
                            if(word_index == word.size()-1){//meaning at last part of the word
                               return 1; 
                            }
                            //x stays the same
                            y +=1;
                            
                            word_index +=1;
                            
                        }//end of y+1 
                        else if (board[x][y-1] == word[word_index]){
                            if(word_index == word.size()-1){//meaning at last part of the word
                               return 1; 
                            }
                            //x stays the same
                            y -=1;
                            word_index +=1;  
                        }
                        else if (board[x+1][y] == word[word_index]){
                            if(word_index == word.size()-1){//meaning at last part of the word
                               return 1; 
                            }
                            x = x+1;
                            //y stays the same
                            word_index +=1;  
                        }
                        else if (board[x-1][y] == word[word_index]){
                            if(word_index == word.size()-1){//meaning at last part of the word
                               return 1; 
                            }
                            x = x-1;
                            //y stays the same
                            word_index +=1;  
                        }
                        else{
                            //meaning none of the adjacent match to next letter in word
                            //reset all variables and get out of while loop
                            word_index = 0;
                            //backtrack to beginning x and y spot
                            x = x_save_space;
                            y = y_save_space;
                            
                            valid_word = 0;
                        }             
                    }//end of while valid word loop
                }//end of if board[x][y] == word[0] matching letter to first letter in word
                
                
            }//end of for loop y part
            printf("\n");
        }//end of outer for loop x part
        
        
        return 0; //placeholder 
                  //also this might be good because if doesn't return0
    }
};