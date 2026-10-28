class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        function<void(int,int)> dfs = [&](int op,int cl) {
            if(s.size()==2*n){
                ans.push_back(s);
                return;
            }
            if(op<n){
                s+='(';
                dfs(op+1,cl);
                s.pop_back();
            }
            if(cl<op){
                s+=')';
                dfs(op,cl+1);
                s.pop_back();
            }
        };
        dfs(0,0);
        return ans;
    }
};