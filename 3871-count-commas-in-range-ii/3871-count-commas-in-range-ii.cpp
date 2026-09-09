class Solution {
public:
    long long countCommas(long long n) {
        

        if(n < 1e3) return 0;

        else if(n >= 1e3 && n < 1e6) return n - 1e3 + 1;

        else if(n >= 1e6 && n < 1e9){
            long long k = n - 1e3 + 1;
            long long z = n - 1e6 + 1;
            return k + z;
        }
        else if(n >= 1e9 && n < 1e12){
            long long l = n - 1e3 + 1;
            long long k = n - 1e6 + 1;
            long long v = n - 1e9 + 1;
            return l + k + v;
        }
        else if(n >= 1e12 && n < 1e15){
            long long l = n - 1e3 + 1;
            long long k = n - 1e6 + 1;
            long long v = n - 1e9 + 1;
            long long h = n - 1e12+ 1;
            return l + k + v + h;
        }
        long long l = n - 1e3 + 1;
        long long k = n - 1e6 + 1;
        long long v = n - 1e9 + 1;
        long long h = n - 1e12+ 1;
        long long t = n - 1e15+ 1;
        return l + k + v + h + t;
        
    }
};