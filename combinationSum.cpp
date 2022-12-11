class Solution {
public:

    void findSum(int idx, vector<int> &nums, int target, vector<vector<int>>&ans, vector<int>&ds)
    {
        //base case
        if(idx == nums.size())
        {
            if(target == 0)
            {
                // you got one more subset with target sum
                ans.push_back(ds);
            }
            return;
        }
        //if not the base case
            //while picking the element
            if(nums[idx] <= target)
            {
                //then pick it
                ds.push_back(nums[idx]);
                //don't increase the index cause you may have to pick that element again
                findSum(idx, nums, target-nums[idx], ans, ds);
                //remove the last element you entered into the ds
                ds.pop_back();
            }
            //if you don't pick the element than leave it and move forward
            findSum(idx+1, nums, target, ans, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findSum(0, candidates, target, ans, ds);
    }
};