#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/repeated-dna-sequences/description/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if(s.length() <=10)
            return res;
        unordered_map<string, int> mp;
        for(int i = 0; i<=s.length() - 10;i++){
            string st = s.substr(i,10);
            mp[st]++;
        }
        for(auto p : mp){
            if(p.second >1)
                res.push_back(p.first);
        }
        return res;
    }
};