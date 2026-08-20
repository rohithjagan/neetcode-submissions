class Solution {
public:
    vector<vector<int>> demo;
    void func(vector<int>& empty,vector<int>& nums,int index){
        demo.push_back(empty);
        for(int i=index;i<nums.size();i++){
            empty.push_back(nums[i]);
            func(empty,nums,i+1);
            empty.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> empty;
        func(empty,nums,0);
        return demo;
    }
};
