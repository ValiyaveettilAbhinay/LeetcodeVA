class Solution {
public:
    int scoreOfParentheses(string s) {

        stack<int>st;
        st.push(0);


        for(char ch : s){
            if(ch == '('){
                st.push(0);
            }
            else{
                int v = st.top();st.pop();
                int w = st.top();st.pop();

                st.push(max(1,2 * v) + w);
            }
        }

        return st.top();
    }
};