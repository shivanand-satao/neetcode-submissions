class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for(char ch:s){
            if(stk.empty() && (ch==']' || ch==')' || ch=='}'))return 0;
            else if(ch=='[' || ch=='(' || ch=='{')stk.push(ch);
            else if(ch==')'){if(stk.top()=='(')stk.pop();else break;}
            else if(ch=='}'){if(stk.top()=='{')stk.pop();else break;}
            else if(ch==']'){if(stk.top()=='[')stk.pop();else break;}
        }return stk.empty();
    }
};
