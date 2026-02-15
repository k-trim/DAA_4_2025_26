#include <bits/stdc++.h>
using namespace std;

vector<int> longestSubset(vector<vector<int>>& dp, vector<int>& nums, int n, int target)
{
    vector<int> subset;
    if(dp[n][target] == -1) return subset;

    while(n >0 && target > 0)
    {
        if (dp[n][target] == dp[n - 1][target])
        {
            n--;
        }
        else
        {
            subset.push_back(nums[n - 1]);
            target -= nums[n - 1];
            n--;
        }
    }
    return subset;
}


int main()
{
    vector<int> nums = {3, 4, 1, 2, 5};
    int n = nums.size();
    int target = 8;

    vector<vector<int>> dp(n + 1, vector<int> (target + 1, -1));
    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= target; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if(nums[i - 1] <= j && dp[i - 1][j - nums[i - 1]] != -1)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - nums[i- 1]] + 1);
            }
        }
    }
    
    if(dp[n][target] == -1)
    {
        cout << "No subset found\n";
        return 0;
    }

    cout<<"Length of the longest subset: "<<dp[n][target]<<endl;
    vector<int> subset = longestSubset(dp, nums, n, target);

    for(int x : subset)
    {
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}
