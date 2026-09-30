class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {

        int n = seq.size();
        stack<char>st;
        vector<int>ans(n,0);

        for(int i = 0;i<n;i++){
            char ch = seq[i];

            if(!st.empty() && st.top() == '(' && ch == ')') st.pop();
            int size = st.size();

            ans[i] = size % 2;
            if(ch == '(') st.push(ch);
        }

        return ans;
    }
};