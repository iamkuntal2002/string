#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/top-k-frequent-words/description/
class Solution {
public:
    bool static comp(pair<int,string> &p1, pair<int,string> &p2){
        if(p1.first == p2.first) return p1.second <p2.second;
        return p1.first > p2.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        vector<string> res;
        for(string s : words) mp[s]++;
        vector<pair<int,string>> vp;
        for(auto pr : mp){
            vp.push_back({pr.second,pr.first});
        }
        sort(vp.begin(),vp.end(),comp);
        for(int i =0;i<k;i++){
            res.push_back(vp[i].second);
        }
        return res;
    }
};