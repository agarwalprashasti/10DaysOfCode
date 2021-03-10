// https://leetcode.com/problems/subsets-ii/

//Solution-1

//Time Complexity: O(2^n *n)
//Space Complexity: O(2^n)

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<vector<int>>ans; 
         vector<int>subset;
        sort(nums.begin(),nums.end());
       
        helper(nums,subset,ans,0);
        return ans;
    }
    void helper( vector<int>& nums, vector<int>subset,vector<vector<int>>&ans, int index)
    {
        ans.push_back(subset);
        for(int i=index;i<nums.size();i++)
        {
            if(i!=index && nums[i]==nums[i-1])
                continue;
            subset.push_back(nums[i]);
            helper(nums,subset,ans,i+1);
            subset.pop_back();
        }
    }
};

//Solution-2

//Time Complexity: O(2^n *n)
//Space Complexity: O(2^n)

class Solution {
public:
    set<vector<int>>s;
    void solve(vector<int>&nums,vector<int>temp,int i)
    {
      s.insert(temp);
      for(int j=i;j<nums.size();j++)
      {
          temp.push_back(nums[j]);
          solve(nums,temp,j+1);
          temp.pop_back();
      }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
      sort(nums.begin(),nums.end());
      vector<vector<int>>res;
      vector<int>temp;
      solve(nums,temp,0);
      for(auto it:s)
          res.push_back(it);
       s.clear();
      return res;
    }
};

