#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string text1, text2;
    cout<<"String 1: ";
    cin>>text1;
    cout<<"String 2: ";
    cin>>text2;
    
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m ; j++)
        {
            if(text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j -1]);
            }
        }
    }

    cout<<"Length of longest common subsequence: "<<dp[n][m]<<endl;
    return 0;
}