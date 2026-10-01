class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int>seen(arr.begin(),arr.end());

        int i = 1;
        int cnt = 0;
        while(true){
            if(!seen.contains(i)){
                cnt++;
            }
            if(cnt == k){   
                return i;
            }
            i++;
        }

        return -1;
    }
};