class Solution {
public:
    vector<vector<int>> output;
    void back(vector<int> empty,int n,int k,int index){
        if(empty.size()==k){
            output.push_back(empty);
            return;
        }
        for(int i=index;i<=n;i++){
            empty.push_back(i);
            back(empty,n,k,i+1);
            empty.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> empty;
        back(empty,n,k,1);
        return output;
    }
};