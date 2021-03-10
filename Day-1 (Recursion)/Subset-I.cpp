// https://leetcode.com/problems/subsets/

//Solution-1

//Time Complexity: O(2^n *n)
//Space Complexity: O(2^n)

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> subset;
        int n = nums.size();
        helper(nums, n, subset, ans);
        return ans;
    }
    void helper(vector<int> &nums, int n, vector<int> subset, vector<vector<int>> &ans)
    {
        //base case
        if (n == 0)
        {
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[n - 1]);
        helper(nums, n - 1, subset, ans);
        subset.pop_back();

        helper(nums, n - 1, subset, ans);
    }
};

//Solution-2

//Time Complexity: O(2^n *n)
//Space Complexity: O(2^n)

class Solution
{
public:
    vector<vector<int>> m;
    void solve(vector<int> nums, vector<int> op)
    {
        if (nums.size() == 0)
        {
            m.push_back(op);
            return;
        }
        vector<int> op1 = op, op2 = op;
        op1.push_back(nums[0]);
        nums.erase(nums.begin() + 0);
        solve(nums, op1);
        solve(nums, op2);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> op;
        solve(nums, op);
        return m;
    }
};