class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int n = arr.size();
        vector<int>pref(n),suff(n);

        pref[0] = arr[0];
        suff[n-1] = arr[n-1];

        int totalXor = arr[0];

        for(int i = 1;i<n;i++){
            pref[i] = pref[i-1] ^ arr[i];
            suff[n-i-1] = suff[n-i] ^ arr[n-i-1];
            totalXor ^= arr[i];
        }

        vector<int>ans;

        for(auto &q : queries){
            int l = q[0],r = q[1];

            if(l == 0 && r == n-1){
                ans.push_back(totalXor);
            }
            else if(l == 0){
                ans.push_back(totalXor ^ suff[r+1]);
            }
            else if(r == n-1){
                ans.push_back(totalXor ^ pref[l-1]);
            }
            else{
                ans.push_back(totalXor ^ pref[l-1] ^ suff[r+1]);
            }

        }
        return ans;

    }
};