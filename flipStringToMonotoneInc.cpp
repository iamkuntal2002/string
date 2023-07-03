#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/flip-string-to-monotone-increasing/
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        int ans=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                count++;
            }
        }
        ans=count;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                count--;
            }
            else{
                count++;
            }
            ans=min(ans,count);
        }
        return ans;
    }
};