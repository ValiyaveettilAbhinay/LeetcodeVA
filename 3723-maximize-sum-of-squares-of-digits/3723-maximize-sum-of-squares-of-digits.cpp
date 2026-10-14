class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        
        string ans = "";

        if(num*9 < sum) return "";

        int cnt = sum/9;
        int len = 0;

        while(cnt--) {
            ans += '9';
            len++;
        }

        sum = sum % 9;

        int rem = num - len;
        while(rem--){
            if(sum > 0){
                ans += to_string(sum);
                sum -= 9;
            }
            else{
                ans += '0';
            }
        }

        return ans;


    }
};