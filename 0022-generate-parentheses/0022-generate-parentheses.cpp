class Solution {
public:
    bool valid(string s){

        stack<char>st;
        for(char ch : s){

            if(!st.empty() && st.top() == '(' && ch == ')'){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        return st.empty();
    }
    void fun(int n,string s,vector<string>&sol){
        if(s.size() == 2*n){
            if(valid(s)){
                sol.push_back(s);
                return;
            }
            return;
        }

        s += '(';
        fun(n,s,sol);
        s.pop_back();
        s += ')';
        fun(n,s,sol);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>sol;
        string s = "";

        fun(n,s,sol);
        return sol;
    }
};