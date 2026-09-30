class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>stk;
        int ans;
        for(string s:tokens){
            if(s=="+" || s=="/" || s=="*" || s=="-"){
                int val1=stoi(stk.top());stk.pop();
                int val2=stoi(stk.top());stk.pop();
                if(s=="+")stk.push(to_string(val2+val1));
                else if(s=="-")stk.push(to_string(val2-val1));
                else if(s=="/")stk.push(to_string(val2/val1));
                else stk.push(to_string(val2*val1));
            }
            else stk.push(s);
        }
        return stoi(stk.top());
    }
};
