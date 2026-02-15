#include <bits/stdc++.h>
using namespace std;

void printSubset(vector<vector<int>>& dp, vector<int>& nums, vector<int>& current, int n, int target)
{
    if(target == 0)
    {
        for(int x : current) cout<<x<<" ";
        cout<<endl;
        return;
    }
    if(n == 0) return;

    if (dp[n-1][target] > 0) printSubset(dp, nums, current, n-1, target);

    if (target >= nums[n-1] && dp[n-1][target - nums[n-1]] > 0) 
    {
        current.push_back(nums[n-1]);
        printSubset(dp, nums, current, n-1, target - nums[n-1]);
        current.pop_back();
    }
}


int main()
{
    vector<int> nums = {3, 4, 1, 2, 5};
    int n = nums.size();
    int target = 8;

    vector<vector<int>> dp(n + 1, vector<int> (target + 1, 0));
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= target; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if(nums[i - 1] <= j)
            {
                dp[i][j] += dp[i -1][j - nums[i - 1]];
            }
        }
    }
    
    cout<<"Total Subsets: "<<dp[n][target]<<endl;
    vector<int> current;
    printSubset(dp, nums, current, n, target);


    return 0;
}
