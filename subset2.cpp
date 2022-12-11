// Similar to power set but you are supposed not to include dulicates.
/*
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
*/
class Solution {
public:

    void findSubsets(int idx, vector<int> nums , vector<int>&ds, vector<vector<int>> &ans)
    {
        //put whatever you have into your data structure
        ans.push_back(ds);
        for(int i = idx; i < nums.size(); i++)
        {
            //now check if you can pick the current element
            if(i != idx && nums[i] == nums[i - 1])
            {
                //if true..means there is an repeating element
                // leave it and move for the next element
                continue;
            }
            //if element can be picked then store it inside ds
            ds.push_back(nums[i]);
            //make recursive call for the next element
            findSubsets(i+1, nums, ans, ds);
            //remove element from ds
            ds.pop_back(); //removes the latest element
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds; // to store intermediate subsets
        sort(nums.begin(), nums.end());
        findSubsets(0, nums, ds, ans);
        return ans;

    }
};