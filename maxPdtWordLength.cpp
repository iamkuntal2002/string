#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-product-of-word-lengths/description/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<unordered_set<char>> st;
        int res =0;
        for(string s : words){
            unordered_set<char> temp;
            for(char c : s){
                temp.insert(c);
            }
            st.push_back(temp);
        }
        for(int i = 0;i<words.size();i++){
            for(int j =0;j<i;j++){
                bool flag = false;
                for(auto val : st[i]){
                    if(st[j].find(val) != st[j].end()){
                        flag = true;
                        break;
                    }
                }
                if(flag == false) {
                    int prd = words[i].length() * words[j].length();
                    res =max(res, prd);
                }
            }
        }
        return res;
    }
};


 bool valid(vector<vector<int>> &st,int i,int j){
        for(int k =0;k<26;k++){
            if(st[i][k]>0 && st[j][k]>0) return false;
        }
        return true;
    }
    int maxProduct(vector<string>& words) {
        vector<vector<int>> st(words.size(),vector<int>(26,0));
        for(int i=0;i<words.size();i++){
            string s = words[i];
            for(auto ch : s){
                st[i][ch-'a']++;
            }
        }
        int ans = 0;
        for(int i =0;i<words.size();i++){
            for(int j = i+1;j<words.size();j++){
                if(valid(st,i,j)){
                    int pdt = (int)words[i].size() * words[j].size();
                    ans = max(ans,pdt);
                }
            }
        }
        return ans;
    }