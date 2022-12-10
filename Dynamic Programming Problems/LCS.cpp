/*
Program to find the Longest Common Subsequence in two strings.

Appraoch -->
1. Brute Force -- TC = O(2^n)
2. DP --> using an extra data structre we can store the result of overlapping
subproblems and then can use them to get the result directly resulting in an 
efficient algorithm.

Steps -->
1. starts from the end of both the strings
2. If characters matches then add then you got a part of common subsequence.
3. If chars doesn't match then check for other possibilities and getting the max
result out of them.
*/

//NOT WORKING
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lcs(int i, string &s1, int j, string &s2, vector<vector<int>>&dp)
    {
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j])
        {
            //you got a common pair.. store it in dp
            return dp[i][j] = 1 + lcs(i - 1, s1, j-1, s2, dp);
        }
        else
        {
            //if elements doesn't match
            // then explore both the strings one by one and return the max result
            return dp[i][j] = max(lcs(i-1, s1, j, s2, dp), lcs(i, s2, j-1, s2, dp));
        }

    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int idx1 = text1.size() - 1, idx2 = text2.size() - 1;
        vector<vector<int>> dp(idx1, vector<int>(idx2, -1));
        return lcs(idx1, text1, idx2, text2, dp);
    
    }
};

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    Solution obj;
    cout<<obj.longestCommonSubsequence(s1, s2)<<endl;
}