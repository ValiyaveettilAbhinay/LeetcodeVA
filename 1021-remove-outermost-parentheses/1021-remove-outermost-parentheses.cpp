class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = -1;

        string ans = "";

        for(char ch : s){
            if(ch == '('){
                cnt++;

                if(cnt > 0){
                    ans += ch;
                }
            }
            else{
                cnt--;

                if(cnt > -1){
                    ans += ch;
                }
            }
        }


        return ans;
    }
};