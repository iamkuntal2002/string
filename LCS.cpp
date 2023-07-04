#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/longest-common-subsequence/
class Solution {
public:
    int dp[1001][1001];
    int helper(string &s1, string &s2, int i, int j){
        if(s1.length() ==i || s2.length() == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = 1+helper(s1,s2,i+1,j+1);
        else return dp[i][j] = max(helper(s1,s2,i+1,j),helper(s1,s2,i,j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return helper(text1,text2,0,0);
    }
};  
