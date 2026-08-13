class Solution {
public:
    std::string decodeString(std::string s) {
        std::stack<int> countStack;
        std::stack<std::string> stringStack;
        
        std::string currStr = "";
        int k = 0;

        for (char ch : s) {
            if (std::isdigit(ch)) {
                // Build the multiplier (handles multi-digit numbers like "100[a]")
                k = k * 10 + (ch - '0');
            } 
            else if (ch == '[') {
                // Push current state to stacks before entering inner bracket
                countStack.push(k);
                stringStack.push(currStr);
                
                // Reset state for inner contents
                k = 0;
                currStr = "";
            } 
            else if (ch == ']') {
                // Decode the bracket block
                std::string prevStr = stringStack.top();
                stringStack.pop();
                
                int count = countStack.top();
                countStack.pop();

                // Repeat currStr 'count' times and attach to prevStr
                std::string repeated = "";
                while (count--) {
                    repeated += currStr;
                }
                
                currStr = prevStr + repeated;
            } 
            else {
                // Regular character
                currStr += ch;
            }
        }

        return currStr;
    }
};