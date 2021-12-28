class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int smallest_size;
        
        smallest_size=-1; 
        
        
        for (int x = 0; x < strs.size(); x++){
            //if smallest_size has not been set 
            if(smallest_size ==-1){
                smallest_size = strs[x].size();
            }
            
            //if strs[x].size is smaller
            else if (strs[x].size() < smallest_size){
                smallest_size = strs[x].size();
                
            }
            
    
        }
        std::cout<< "Smallest str size " << smallest_size << std::endl;
        
        bool matching_still=1;
        
        
        int index = 0;
        std::cout << "strs[0][0]" <<strs[0][0] << endl;
        std::cout << "strs[0][4]" <<strs[0][3] << endl;
        //string matching_str[200]; 
        string matching_str;         
        string indexed_character;
        
        while(matching_still){
            if (index >= smallest_size){
                break; //if index is greater than the str with smallest size break out of loop
            }
            
            //for each strs go through the smallest length size and check if char 
            //at index matches 
            //string indexed_character[10]= strs[0][index]
            //indexed_character.assign(); //get first string in vector and get the first indexed character
            indexed_character = strs[0][index];
            std::cout << "indexed character " << indexed_character << endl; 
            
            for (int x = 0; x < strs.size(); x++){
                std::cout<< "strs[" << x << "][" << index << "]  "  << strs[x][index] << std::endl;
                if (strs[x][index] != indexed_character[0]){
                    std::cout << "str at index does not match starting indexed_character" << endl;
                   matching_still = 0;
                   break; 
                   //break outside of loop if indexed_character does not match the current string index character
                    
                }
                
                //index
            }//end of for loop 
            
            if (matching_still == 0){
                break;
            }
            
            matching_str= matching_str + indexed_character;
            std::cout << "matching_str " << matching_str << endl; 
            
            //std::strcat(matching_str,indexed_character);
            
            
            index ++;// have index value go up by 1 to get to the next character in string
            
            
         }//end of while loop 
        
        
        std::cout << "matching_str (at end)" << matching_str << endl; 
        
        //return "0";//just placeholder until get correct output
        
        return matching_str;
    }//end of longest common prefix function
};