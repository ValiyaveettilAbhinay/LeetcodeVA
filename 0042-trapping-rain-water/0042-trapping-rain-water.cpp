class Solution {
public:
    int trap(vector<int>& height) {
        

        stack<int>st;

        int n = height.size();
        int trap = 0;

        for(int i = 0;i<n;i++){

            while(!st.empty() && height[st.top()] < height[i]){

                int top = st.top();
                st.pop();

                if(st.empty()){
                    break;
                }

                int h = min(height[st.top()],height[i]) - height[top];
                int w = i - st.top() - 1;


                trap += (h * w);
            } 

            st.push(i);
        }

        return trap;
    }
};