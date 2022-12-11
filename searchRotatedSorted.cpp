class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low, mid, high;
        int size = nums.size();
        int diff = nums[0] - 0;
        low = diff;
        high = size - diff;
        while (low < high)
        {
            mid = (low + high) % size;
            if (mid == target)
            {
                return (low + high) % size;
            }
            else if (mid > target)
            {
                // target is lesser..move high
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
};