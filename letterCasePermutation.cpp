#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/letter-case-permutation/
class Solution {
public:
    void backtrack(string& s, int i,vector<string> &ans) {
        if (i == s.size()) {
            ans.push_back(s);
            return;
        }        
        backtrack(s, i + 1,ans);        
        if (isalpha(s[i])) {
            char original = s[i]; 
            if(islower(original)) s[i] = toupper(original);
            else s[i] = tolower(original); 
            backtrack(s, i + 1,ans);
            s[i] = original; 
        }
    }    
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        backtrack(s,0,ans);
        return ans;
    }
};