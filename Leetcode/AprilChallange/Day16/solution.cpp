class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st;
        stack<int> ss;
        int i = 0;
        for(auto c : s){
            if(c == '*'){
                ss.push(i);
            }else if(c == '('){
                st.push(i);
            }else{
                if(!st.empty()){
                    st.pop();
                }else if(!ss.empty()){
                    ss.pop();
                }else{
                    return false;
                }
            }
            i++;
        }
        if(ss.size() < st.size()){
            return false;
        }else{
            while(!st.empty()){
                if(ss.top() < st.top()){
                    return false;
                }else{
                    ss.pop(); st.pop();
                }
            }
        }
        return st.empty();
    }
};