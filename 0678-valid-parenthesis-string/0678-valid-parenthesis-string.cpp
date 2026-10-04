class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0,maxi = 0;

        for(char ch : s){
            if(ch == '('){
                maxi++;
                mini++;
            }
            else if(ch == ')'){
                mini--;
                maxi--;
            }
            else{
                maxi++;
                mini--;
            }

            if(mini < 0) mini = 0;
            if(maxi < 0) return false;
        }
        return mini == 0;
    }
};