class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        

        unordered_map<int,int>freq;

        int n = nums.size();
        for(int i = 0;i<=n-k;i++){
            
            unordered_map<int,int>f1;
            for(int j = i;j<i+k;j++){
                if(f1.contains(nums[j]) && f1[nums[j]] == 1) continue;
                f1[nums[j]]++;
            }

            for(auto &p : f1){
                freq[p.first]++;
            }
        }

        int maxi = -1;
        for(const auto &p : freq){
            if(p.second == 1) maxi = max(maxi,p.first);
        }

        return maxi;
    }
};