#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/longest-repeating-character-replacement/
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int ans=0;
        int n=s.size();
        for(auto it: mp){
            char curr = it.first;
            // cout<<ch<<endl;
            int i=0,j=0;
            int count=k;
            while(j<n){
                if(curr == s[j]){
                    j++;
                }
                else if(curr !=s[j] && count>0){
                    j++;
                    count--;
                }
                else{
                    ans=max(ans,j-i);
                    while(s[i]==curr){
                        i++;
                    }
                    i++;
                    count++;
                }
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};