class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<char,int>mp;

        int l = 0,n = s.size();
        int cnt = 0;
        unordered_map<string,int>hs;

        for(int r = 0;r<n;r++){

            char ch = s[r];
            mp[ch]++;

            while(mp.size() > maxLetters || r - l + 1 > minSize){
                char lc = s[l];
                mp[lc]--;
                if(mp[lc] == 0) mp.erase(lc);
                l++;
            }
            int len = r - l + 1;
            if(mp.size() <= maxLetters && len == minSize){
                string sub = s.substr(l,len);
                hs[sub]++;

                cnt = max(cnt,hs[sub]);
            }
        }

        return cnt;
    }
};