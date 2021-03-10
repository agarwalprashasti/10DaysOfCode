// https://practice.geeksforgeeks.org/problems/subset-sums2234/1

//Time Complexity: O(2^n +  2^n log(2^n) --> for sorting the array since we hve 2^n elements)
//Space Complexity: O(2^n)

class Solution
{
public:
    vector<int> subsetSums(vector<int> a, int n)
    {
        vector<int> ans;
        func(a, n, ans, 0, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
    void func(vector<int> a, int n, vector<int> &ans, int sum, int i)
    {
        if (i == n)
        {
            ans.push_back(sum);
            return;
        }
        func(a, n, ans, sum + a[i], i + 1);
        func(a, n, ans, sum, i + 1);
    }
};