#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/letter-tile-possibilities/description/
class Solution {
public:
    void helper(string &tiles,string curr,set<string> &st, vector<bool> &vis){
        if(curr.length()>tiles.length()) return;
        st.insert(curr);
        for(int i =0;i<tiles.length();i++){
            if(vis[i]) continue;
            curr += tiles[i];
            vis[i] = true;
            helper(tiles,curr,st,vis);
            curr.pop_back();
            vis[i] = false;
        }
    }
    int numTilePossibilities(string tiles) {
        set<string> st;
        vector<bool> vis(tiles.size(),false);
        string curr = "";
        helper(tiles,curr,st,vis);
        return st.size()-1; //as there is a empty string
    }
};