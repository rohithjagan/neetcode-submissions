class Solution {
public:
    vector<vector<int>> output;
    void permute(vector<int>& empty,vector<int>& nums,vector<bool>& used){
        if(empty.size()==nums.size()){
            output.push_back(empty);
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]){
                continue;
            }
            used[i] = true;
            empty.push_back(nums[i]);
            permute(empty,nums,used);
            empty.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> used(n,false);
        vector<int> empty;
        permute(empty,nums,used);
        return output;
    }
};
