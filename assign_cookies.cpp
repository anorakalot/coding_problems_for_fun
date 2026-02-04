class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //ok so 2 pointers?
        // is the arrays already ordered?

        //if so
        //if content move to the next cookie in the index

        int g_index = 0;
        int s_index = 0;

        int num_of_hpy_chs =  0;

        int size_of_g = g.size();
        int size_of_s = s.size();

        //0 is normal 1 is backward
        bool g_dir = 0;

        if(g[0] > g[size_of_g-1]){
            g_index = size_of_g - 1;
            g_dir = 1;
        }
        

        while(s_index < size_of_s && g_index < size_of_g && s_index >=0 && g_index >= 0){
            if(s[s_index] >= g[g_index]){
                num_of_hpy_chs += 1;
                s_index += 1;
                if(g_dir == 1){
                    g_index -= 1;
                }
                else{
                    g_index += 1;
                } 
            }
            else if (s[s_index] < g[g_index]){
                s_index += 1;
            }
        }
        
    
        return num_of_hpy_chs;
    }
};