#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/longest-string-chain/
class Solution {
public:
    bool match(string &s1, string &s2)    {
        int sz1=s1.size();
        int sz2=s2.size();
        if(sz2-sz1 != 1) return false;
        int first=0;
        int second=0;
        while(second<sz2)
        {
            if(s1[first]==s2[second])
            {
                first++;
                second++;
            }
            else
            {
                second++;
            }
        }
        if(first==sz1 && second==sz2) return true;
        return false;
    }
    static bool cmp(string &s1, string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& arr) {
        sort(arr.begin(),arr.end(),cmp);     
        int n=arr.size();
        int maxi=1;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(match(arr[prev],arr[i]) && 1+dp[prev]>dp[i])
                {
                    dp[i]=1+dp[prev];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
            
    }
};