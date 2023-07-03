#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/custom-sort-string
class Solution {
public:
    string customSortString(string order, string s) {
        if(order.size() == 0) return s;
        unordered_map<char,int> mp;
        for(auto ch : s) mp[ch]++;
        string res = "";
        for(auto ch : order){
            while(mp[ch]>0){
                res += ch;
                mp[ch]--;
            }
        }
        for(auto pr : mp){
            int count = pr.second;
            while(count>0){
                res += pr.first;
                count--;
            }
        }
        return res;
    }
};