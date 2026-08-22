class Solution {
public:
    bool checkDivisibility(int n) {
        

        int prodSum = 1,digitSum = 0;
        int temp = n;

        while(n>0){
            int rem = n%10;
            digitSum += rem;
            prodSum *= rem;
            n = n/10;
        }

        int totalSum = digitSum + prodSum;
        return (temp % totalSum) == 0;
    }
};