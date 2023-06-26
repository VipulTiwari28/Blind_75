#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int i,int n,vector<int> nums,vector<int> &dp)
    {
        if(i==n-1)
        {
            return nums[i];
        }
        if(i>=n)
        {
            return 0;
        }

        if(dp[i]!=-1)
        {
            return dp[i];
        }

        int include = nums[i] + solve(i+2,n,nums,dp);
        int exclude = 0 + solve(i+1,n,nums,dp);

        dp[i] = max(include,exclude);

        return dp[i];
        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);

        if(n==1)
            return nums[0];

        int ans1 = solve(0,n-1,nums,dp1);
        int ans2 = solve(1,n,nums,dp2);

        return max(ans1,ans2);
        
    }
};