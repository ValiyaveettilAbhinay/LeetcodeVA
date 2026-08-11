class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        unordered_set<int>st(nums.begin(),nums.end());
        int n = nums.size();

        int sum = nums[0];
        int prev = nums[0];
        for(int i = 1;i<n;i++){
            if(prev + 1 == nums[i]){
                prev = nums[i];
                sum += nums[i];
            }
            else{
                break;
            }
        }



        while(st.contains(sum)){
            sum++;
        }
        return sum;
    }
};