#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //1st sort it
        //sort(nums.begin(),nums.end());
        //initial->

        //approach->1

        /*set<vector<int>> st;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            set<int> hashset;
            for(int j = i+1 ; j<nums.size() ;j++)
            {
                int third = -(nums[i]+nums[j]);
                if(hashset.find(third)!=hashset.end())
                {
                    vector<int> temp = {nums[i],nums[j],third};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());

        return ans;*/
        vector<vector<int>> ans;
        int n = nums.size();
        //APPROACH 2
        //1st sort it
        sort(nums.begin(),nums.end());
        //initial->
        for(int i = 0 ; i < n ; i++)
        {
            int j = i+1;
            int k = n-1;
            if(i>0 && nums[i]==nums[i-1])continue;
            //if the adjacent are similar continue
            while(j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum<0)
                {
                    j++;
                }
                else if(sum>0)
                {
                    k--;
                }
                else{
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1])j++;
                    while(j<k && nums[k]==nums[k+1])k--;

                    //these two while loops makes the jth element and kth element move until the prev
                    //forward respectively are not similar
                }
            }
        }
        return ans;

    }
};