#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/number-of-matching-subsequences/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int match =0;
        int i =0;
        int j = 0;
        while(i<s.length() && j <t.length()){
            if(s[i] == t[j]){
                match++;
                i++;
                j++;
            }
            else j++;
        }
        if(match == s.length()) return true;
        return false;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        unordered_map<string,int> mp;
        for(auto &str : words) mp[str]++;
        for(auto &pr : mp){
            if(isSubsequence(pr.first,s)) count+= pr.second;
        }   
        return count;
    }
};