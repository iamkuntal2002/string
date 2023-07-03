#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int ans = 0;
        int start = 0;
        int end =0;
        while(end < s.size() && start < s.size()){
            if(st.find(s[start]) == st.end()){
                ans = max(ans,start-end+1);
                st.insert(s[start]);
                start++;
            }
            else{
                st.erase(s[end]);
                end++;
            }
            // start++;
        }
        return ans;
    }
};