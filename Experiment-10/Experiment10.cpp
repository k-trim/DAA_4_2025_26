// Time Complexity: O(n * m), where n and m are lengths of input strings
// Space Complexity: O(n * m)

class Solution {
public:
    int solve(string & s, string & t, int i, int j, vector<vector<long long>>& dp)
    {
        if(j == t.size()) return 1;
        if(i >= s.size()) return 0;
        if(dp[i][j] != -1) 
        {
            return dp[i][j];
        }

        int count = 0;
        if(s[i] == t[j])
        {
            count += solve(s, t, i + 1, j + 1, dp);
        }
        count += solve(s, t, i + 1, j, dp);
        return dp[i][j] = count;
    }
    int numDistinct(string s, string t) {
        vector<vector<long long>> dp(s.size() + 1, vector<long long> (t.size() + 1, -1));
        return solve(s, t, 0, 0, dp);
    }
};