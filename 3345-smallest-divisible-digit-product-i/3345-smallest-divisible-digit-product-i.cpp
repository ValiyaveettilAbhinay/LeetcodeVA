class Solution {
public:

    int product(int i){
        
        int p = 1;
        while(i>0){
            int rem = i%10;
            p = p * rem;
            i /= 10;
        }
        return p;
    }
    int smallestNumber(int n, int t) {

        int i = n;
        while(true){
            int prd = product(i);

            if(prd % t == 0){
                return i;
            }

            i+=1;
        }

        return -1;
    }
};