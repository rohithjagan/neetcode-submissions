class Solution {
public:
    vector<vector<int>> output;
    void func(vector<int> candidates, int target, vector<int> empty, int index, int sum){
        if(sum>target){
            return;
        }
        if(target == sum){
            output.push_back(empty);
        }
        for(int i=index;i<candidates.size();i++){
            if (i > index && candidates[i] == candidates[i - 1]){
                continue;
            }
            empty.push_back(candidates[i]);
            func(candidates,target,empty,i+1,sum+candidates[i]);
            empty.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> empty;
        sort(candidates.begin(),candidates.end());
        func(candidates,target,empty,0,0);
        return output;
    }
};
