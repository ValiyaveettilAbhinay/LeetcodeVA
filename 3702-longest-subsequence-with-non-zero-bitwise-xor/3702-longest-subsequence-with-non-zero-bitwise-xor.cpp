class Solution {
public:
    int longestSubsequence(vector<int>& nums){

        int xr = 0;
        bool hasNonZero = false;

        int n = nums.size();
        for(int num : nums){
            xr ^= num;
            if(xr != 0) hasNonZero = true;
        }

        if(xr != 0) return n;
        if(hasNonZero) return n-1;
        return 0;
    }
};