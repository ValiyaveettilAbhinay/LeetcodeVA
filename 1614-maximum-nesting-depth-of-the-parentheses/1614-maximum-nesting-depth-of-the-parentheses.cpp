class Solution {
public:
    int maxDepth(string s) {

        int par = 0,maxi = 0;

        for(char &ch : s){

            maxi = max(maxi,par);
            if(ch == '(') par++;
            else if(ch == ')')par--;
        }
        return maxi;
    }
};