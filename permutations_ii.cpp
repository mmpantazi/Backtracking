class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>> result;
        vector<int> currentPermutation;
        vector<bool> used(nums.size(), false);

        sort(nums.begin(), nums.end()); // Sort to handle the duplicates

        backtrack(nums, used, currentPermutation, result);
        return result;
    }

    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& currentPermutation, vector<vector<int>>& result)
    {
        if (currentPermutation.size() == nums.size())
        {
            result.push_back(currentPermutation);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]))
            {
                continue;  // Handle duplicates
            }
            used[i] = true;
            currentPermutation.push_back(nums[i]);
            backtrack(nums, used, currentPermutation, result);
            currentPermutation.pop_back();
            used[i] = false;
        }
    }
};