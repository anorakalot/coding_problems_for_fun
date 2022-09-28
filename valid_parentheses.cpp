class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        // printf("%i\n\n",s.size());
        if (s.size() %2 ==1){
            return 0;
        }
        // if (s[0] == ')' || s[0] == ']' || s[0] == '}'){
        //     return 0;
        // }
        int open =0;
        for (int x =0; x<s.size();x++){
            if (s[x] == '(' || s[x] == '[' || s[x] == '{' ){
                st.push(s[x]);
                open+=1;
            }
            if (open == 0 && (s[x] == ')' || s[x] == ']' || s[x] == '}')){
                return 0;
            }
            else{
                if(s[x] == ')'){
                    if (st.top() != '('){
                        return 0;
                    }
                    st.pop();
                    open -=1;
                }//
                else if (s[x]== ']'){
                    if (st.top() != '['){
                        return 0;
                    }
                    st.pop();
                    open -=1;
                }
                else if (s[x] == '}'){
                    if (st.top() != '{'){
                        return 0;
                    }
                    st.pop();
                    open -=1;
                }
            }//end of else 
        }
  
        if (open > 0){
            return 0;
        }
        // p
        
        return 1;
    }
};
// st.push('c');
// st.push('a');
// printf("%c\n",st.top());
// st.pop();
// printf("%c\n",st.top());
        