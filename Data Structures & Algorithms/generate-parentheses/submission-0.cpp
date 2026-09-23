class Solution {
public:
    vector<string> output;
    void rec(int ln, int rn, int n, string temp){
        if(ln==rn && ln+rn == 2*n){
            output.push_back(temp);
            return;
        }
        if(ln<n){
            rec(ln+1,rn,n,temp+"(");
        }
        if(rn<ln){
            rec(ln,rn+1,n,temp+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        int ln = 0, rn = 0;
        string temp = "";
        rec(0,0,n,temp);
        return output;
    }
};
