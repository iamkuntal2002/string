#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
public:
    void helper(string &digits,vector<string> &res, unordered_map<char,string>&mp, string &curr, int index){
        if(index == digits.length()){
            res.push_back(curr);
            return;
        }
        string dg = mp[digits[index]];
        for(int i =0;i<dg.length();i++){
            curr+=dg[i];
            helper(digits,res,mp,curr,index+1);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.length() ==0) return res;
        unordered_map<char,string> mp;
        mp['2'] = "abc"; mp['3'] = "def"; mp['4'] = "ghi";
        mp['5'] = "jkl"; mp['6'] = "mno"; mp['7'] = "pqrs";
        mp['8'] = "tuv"; mp['9'] = "wxyz";
        string curr = "";
        helper(digits,res,mp,curr,0);
        return res;        
    }
};
