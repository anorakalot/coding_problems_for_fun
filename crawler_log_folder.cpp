class Solution {
public:
    int minOperations(vector<string>& logs) {
        //ok so read it in until we get to at least a /
        //keep track of the current level?

        int curr_level = 0;
        string curr_str = "";
        for(int x = 0; x < logs.size(); x++){
            
            curr_str.push_back(logs[x])
            if(logs[x] == '/'){
                if(curr_str == "../"){
                    if(curr_level > 0){
                        curr_level -=1;
                    }
                }
                else if (curr_str = "./"){
                    //nothing
                }
                //means it's the move to child folder one
                else{
                    curr_level += 1;
                }
            
                //empty curr_str
                curr_str = "";
            }//end of logs[x]
        }
        return current_level;
    }//end of function
};