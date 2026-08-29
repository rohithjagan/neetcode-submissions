class Solution {
public:
    vector<vector<int>> output;
    void func(vector<int> nums,vector<int> empty,int index,int sum,int target){
        if(sum>target){
            return;
        }
        if(sum==target){
            output.push_back(empty);
        }
        for(int i=index;i<nums.size();i++){
            empty.push_back(nums[i]);
            func(nums,empty,i,sum+nums[i],target);
            empty.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> empty;
        func(nums,empty,0,0,target);
        return output;
    }
};
