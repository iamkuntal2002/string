#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-and-replace-pattern/description/
class Solution {
public:
    bool check(string &p, string &s){
        unordered_map< char,char > mp;
        vector<bool> visited (26,false);        
        for(int i = 0; i < p.length(); i++){
            char c1 = p[i],c2 = s[i];            
            if( mp[c1] && mp[c1]!=c2)
                return false;
            if( !mp[c1] && visited[c2-'a'])
                return false;            
            mp[c1] = c2;
            visited[ c2-'a' ] = true;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(string s : words){
            if(check(pattern,s)) res.push_back(s);
        }
        return res;
    }
};