class Solution {
public:
    bool backspaceCompare(string S, string T) {
        bool yeah = true;
        int i = S.length();
        int j = T.length();
        int j1 = 0, j2 = 0;
        while(i >= 0 && j >= 0){            
            while(i >= 0 && (S[i] == '#' || j1 > 0)){
                if(S[i] == '#'){
                    j1++;
                }else{
                    j1--;
                }
                i--;
            }
            while(j >= 0 && (T[j] == '#' || j2 > 0)){
                if(T[j] == '#'){
                    j2++;
                }else{
                    j2--;
                }
                j--;
            }
            if(i >= 0 && j >= 0){
                if(S[i] != T[j]){
                    yeah = false;
                    break;
                }
            }
            i--; j--;
        }
        
        while(i >= 0 && (S[i] == '#' || j1 > 0)){
                if(S[i] == '#'){
                    j1++;
                }else{
                    j1--;
                }
                i--;
            }
            while(j >= 0 && (T[j] == '#' || j2 > 0)){
                if(T[j] == '#'){
                    j2++;
                }else{
                    j2--;
                }
                j--;
            }
        
        if(i != j && yeah){
            yeah = false;
        }
        return yeah;
    }
};
