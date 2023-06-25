#include <bits/stdc++.h>

using namespace std;// namespace name


class Solution {
public:
    int solve(int n,vector<int> nums,vector<int> &dp,int i)
    {
        //step 1 base case
        //Top-down approach
        if(i==n-1 || i==n-2)
            return nums[i];

        //In case we reach out of bounds
        if(i>n)
            return 0;
        
        //Step 2
        //Memoraization return
        if(dp[i]!=-1)
        {
            return dp[i];
        }

        for(int j = i+2 ; j < n+1 ; j++)
        {
            //here I have called the houses that are not adjacent that's 
            //why I have called for the houses that "i+2" while returing
            //It will make sure I got the answer right
            int ans = nums[i] + solve(n,nums,dp,j);
            if(dp[i] < ans)
            {
                dp[i] = ans;
            }
        }

        return dp[i];
        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);

        int ans = max(solve(n,nums,dp,0),solve(n,nums,dp,1));
        
        return ans;
        
    }
};