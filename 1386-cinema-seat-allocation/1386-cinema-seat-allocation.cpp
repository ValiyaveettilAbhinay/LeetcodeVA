class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int,vector<int>>mp;
        unordered_set<int>st;

        for(const auto &seats : reservedSeats){
            
            int r = seats[0],s = seats[1];

            if(!mp.contains(r)){
                vector<int>rows(11,0);

                mp[r] = rows;
                mp[r][s]++;

                st.insert(r);
            }
            else{
                mp[r][s]++;
            }
        }

        int rem = n - mp.size();
        int seats = rem * 2;

        for(int num : st){

            vector<int>f = mp[num];

            if((f[2] == 0 && f[3] == 0 && f[4] == 0 && f[5] == 0) && (f[6] == 0 && f[7] == 0 && f[8] == 0 && f[9] == 0)){
                seats+=2;
            }
            else if(f[2] == 0 && f[3] == 0 && f[4] == 0 && f[5] == 0){
                seats+=1;
            }
            else if(f[6] == 0 && f[7] == 0 && f[8] == 0 && f[9] == 0){
                seats+=1;
            }
            else if((f[4] == 0 && f[5] == 0 && f[6] == 0 && f[7] == 0)){
                seats+=1;
            }

        }

        return seats;


    }
};