// Time Complexity: O(n * Sum), where n is the length of the input array, Sum is the sum of all elements of the input array
// Space Complexity: O(n * Sum)

class Solution {
  public:
    int solve(vector<vector<int>>& dp, vector<int>& arr, int curr, int totalSum, int i)
    {
        if(i == arr.size()) 
        {
            return abs(totalSum - (2*curr));
        }
        if(dp[i][curr] != -1) return dp[i][curr];
        int pick = solve(dp, arr, curr + arr[i], totalSum, i + 1);
        int notPick = solve(dp, arr, curr, totalSum, i + 1);
        return dp[i][curr] = min(pick, notPick);
    }
    
    int minDifference(vector<int>& arr) {
        int totalSum = 0;
        for(int x : arr) totalSum+= x;
        
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int> (totalSum + 1, -1));
        
        return solve(dp, arr, 0, totalSum, 0);
    }
};