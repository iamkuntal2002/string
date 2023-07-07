#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char,int> mp;
        for(auto ch : s) mp[ch]++;
        int a = 0;
        int end = 0;
        int b = 0;
        while(end < s.size() && mp[s[end]]>=k) end++;
        if(end == s.size()) return end;
        a = longestSubstring(s.substr(0,end),k);
        if(end<s.size()-1) b = longestSubstring(s.substr(end+1),k);
        return max(a,b);
    }
};
// ababbc
// a- > 2
// b -> 3
// c -> 1
