class Solution {
public:

    string encode(vector<string>& strs) {
        string st="";for(string s:strs){st+=to_string(s.length());st+='!';st+=s;}return st;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int i=0;
        while(i<s.length()){
            string num = "";
            while (isdigit(s[i])) {
                num += s[i];
                i++;
            }
            int len = stoi(num);
            i++;   
            string new_st="";
            for(int j=0;j<len;j++)new_st+=s[i+j];
            ans.push_back(new_st);
            i+=len;
        }
        return ans;
    }
};
