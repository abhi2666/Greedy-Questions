/*
find all unique subsets with sum equal to target
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8

Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]]

*/

class Solution {
public:
  void getSum(int idx, vector<int>&nums, int target, vector<vector<int>>&ans, vector<int>&ds)
    {
        //base case
        if(target = 0)
        {
            //means your data structure is ready
            ans.push_back(ds);
        }
        //remember not to pick any duplicate elements 
        for(int i = idx; i < nums.size(); i++)
        {
            //check for repeated element
            if(i > idx && nums[i] == nums[i - 1])
            {
                //means a element which is already present in the top of ds has appeared
                //again..do not pick it and move to other element
                continue;
            }
            // if element is not duplicate then add it to the data structure
            // if element is not bigger that target itself then only pick it else break
            // out of the for loop
            if(nums[i] > target) break;//fuck it
            ds.push_back(nums[i]);
            getSum(i+1, nums, target-nums[i], ans, ds);
            ds.pop_back();
        }   
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidate.begin(), candidate.end()); ///to get all the subsets in sorted order
        set<vector<int>>ans;
        vector<int>ds;
        getSum(0, candidates, target, ans, ds);
        return ans;
    }
};