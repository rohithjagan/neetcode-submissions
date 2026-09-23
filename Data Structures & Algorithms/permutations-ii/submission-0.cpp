class Solution {
public:
    vector<vector<int>> output;
    void rec(vector<int>& nums,vector<int>& temp,vector<bool>& used){
        if(temp.size()==nums.size()){
            output.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]){
                continue;
            }
            if(i>0 && nums[i] == nums[i-1] && !used[i-1]){
                continue;
            }
            
            temp.push_back(nums[i]);
            used[i]=true;
            rec(nums,temp,used);
            temp.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp;
        vector<bool> used(nums.size(),false);
        sort(nums.begin(),nums.end());
        rec(nums,temp,used);
        return output;
    }
};