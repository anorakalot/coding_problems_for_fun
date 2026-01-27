class Solution {
public:
    int minOperations(vector<string>& logs) {
        //ok so read it in until we get to at least a /
        //keep track of the current level?

        int curr_level = 0;
//oh wait ti's already sepereated
    for (int x = 0; x < logs.size(); x++){
        //check if first 2 are ..
        if(logs[x][0] == '.'){
            if(logs[x][1] == '.'){
                if(curr_level > 0){
                    curr_level -= 1;
                }
            }//end of ../ if

        }
        else{
            curr_level += 1;
        }
    }

    //     string curr_str = "";
    //     for(int x = 0; x < logs.size(); x++){
            
    //         curr_str.push_back(logs[x]);
    //         if(logs[x] == '/'){
    //             if(curr_str == "../"){
    //                 if(curr_level > 0){
    //                     curr_level -=1;
    //                 }
    //             }
    //             else if (curr_str = "./"){
    //                 //nothing
    //             }
    //             //means it's the move to child folder one
    //             else{
    //                 curr_level += 1;
    //             }
            
    //             //empty curr_str
    //             curr_str = "";
    //         }//end of logs[x]
    //     }
        return curr_level;
    }//end of function
};