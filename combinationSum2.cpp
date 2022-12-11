//find all unique subsets with sum equal to target

class Solution {
public:
    void getSum(int idx, vector<int>&nums, int target, set<vector<int>>&ans, vector<int>&ds, map<int, int>&mp)
    {
        if(idx == nums.size())
        {
            if(target == 0) ans.push_back(nums[idx]);
            return;
        }
        //pick the element 
        if(nums[i] <= target)
        {
            //pick the element
            ds.push_back(nums[i]);
            getSum(idx+1, nums, target-nums[idx], ans, ds);
            ds.pop_back();
        }
        //not pick the element
        getSum(idx+1, nums, target, ans, ds);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        map<int, int> mp;
        set<vector<int>>ans;
        vector<int>ds;
        getSum(0, candidates, target, ans, ds, mp);
        return ans;
    }
};