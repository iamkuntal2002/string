#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
class Solution {
public:
    int helper(vector<string>& arr, string str = "", int index = 0) {
        unordered_set<char> st(str.begin(), str.end());
        if (st.size() != ((int)str.length())) 
            return 0;
        
        int ret = str.length();
        for (int i = index; i < arr.size(); i++)
            ret = max(ret, helper(arr, str+arr[i], i+1));

        return ret;
    }
    int maxLength(vector<string>& arr) {
        return helper(arr,"",0);   
    }
};