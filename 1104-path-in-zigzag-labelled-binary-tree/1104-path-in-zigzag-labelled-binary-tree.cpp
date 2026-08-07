class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int>ans;

        int lvl = 1;

        if(label == 1) return {1};

        vector<vector<int>>elements;
        int num = 1;
        int even = true;

        while(num <= label){

            vector<int>vec;

            int pow = lvl;
            while(pow--){
                vec.push_back(num);
                num++;
            }

            if(!even){
                reverse(vec.begin(),vec.end());
            }
            even = !even;
            elements.push_back(vec);


            lvl*= 2;
        }

        int ind = -1,n = elements.size(),m = elements[n-1].size();

        for(int i =0;i<m;i++){
            if(label == elements[n-1][i]){
                ind = i;
                break;
            }
        }

        int i = n-1,j = ind;
        while(i>=0){
            ans.push_back(elements[i][j]);
            i--;
            j/=2;
        }

        reverse(ans.begin(),ans.end());


        return ans;



         

        



    }
};