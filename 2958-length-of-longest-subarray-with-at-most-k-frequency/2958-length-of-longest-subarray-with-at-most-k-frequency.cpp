class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        

        int n = nums.size();
        int left = 0;
        int ans = 0;

        unordered_map<int,int>mp;

        for(int right = 0;right<n;right++){

            int num = nums[right];
            mp[num]++;

            while(mp[num] > k){
                int lf = nums[left];
                mp[lf]--;

                if(mp[lf] == 0){
                    mp.erase(lf);
                }

                left++;
            }

            ans = max(ans,right - left + 1);

        }

        return ans;
    }
};