class Solution {
public:
    bool isPalindrome(string s, int l, int r)
    {
        while(l < r)
        {
            if(s[l] != s[r])
            {
                return false;
            }
            else
            {
                l++;
                r--;
            }
        }
        return true;
    }
    void solve(string s, int i, vector<string>& curr, vector<vector<string>>& ans)
    {
        if(i == s.size())
        {
            ans.push_back(curr);
             return;
        }

        for(int j = i; j < s.size(); j++)
        {
            if(isPalindrome(s, i, j))
            {
                curr.push_back(s.substr(i, j - i + 1));
                solve(s, j + 1, curr, ans);
                
                curr.pop_back();
            }

        }


    }


    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> curr;
        solve(s, 0 , curr, ans);
        return ans;

    }
};