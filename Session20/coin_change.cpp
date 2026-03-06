#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int amount, n;
    cout<<"Amount: ";
    cin>>amount;
    cout<<"Enter number of coins: ";
    cin>>n;
    vector<int> coins(n);
    cout<<"Coins: ";
    for(int i = 0; i < n; i++)
    {
        cin>>coins[i];
    }

    int INF = INT_MAX - 1;
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INF));

    for(int i = 0; i <= n; i++) dp[i][0] = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= amount; j++)
        {
            if(coins[i - 1] <= j)
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    if(dp[n][amount] == INF)
    {
        cout<<"Not possible"<<endl;
    }
    else
    {
        cout<<"Minimum number of coins required: "<<dp[n][amount]<<endl;
    }

    return 0;
}