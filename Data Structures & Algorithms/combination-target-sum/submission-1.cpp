class Solution {
public:
    vector<vector<int>> output;
    void rec(vector<int>& nums,int target,int index,int expected,vector<int>& temp){
        if(target == expected){
            output.push_back(temp);
            return;
        }
        else if(target < expected){
            return;
        }
        for(int i=index;i<nums.size();i++){
            expected+=nums[i];
            temp.push_back(nums[i]);
            rec(nums,target,i,expected,temp);
            expected-=nums[i];
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        rec(nums,target,0,0,temp);
        return output;
    }
};
