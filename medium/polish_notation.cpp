class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> buf;
        
        int ans;

        for (auto x : tokens) {
            if (x[0] >= '0' && x[0] <= '9' || (x[0] == '-' && x.size() > 1)) {
                int sum = 0;
                for (auto s : x) {
                    if (s == '-') continue;
                    sum = sum * 10 + s - '0';
                }

                if (x[0] == '-') sum *= -1;
                buf.push(sum);
            } else {
                int op1 = buf.top();
                buf.pop();
                int op2 = buf.top();
                buf.pop();
                
                if (x[0] == '+')
                    buf.push(op2 + op1);
                else if (x[0] == '-')
                    buf.push(op2 - op1);
                else if (x[0] == '*')
                    buf.push(op2 * op1);
                else
                    buf.push(op2 / op1);
            }
        }
        
        return buf.top();
    }
};