#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/reverse-words-in-a-string/
class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp = "";
        for(int i =0;i<s.size();i++){
            if(s[i] == ' '){
                if(temp.size()>0) st.push(temp);
                temp = "";
            }
            else temp += s[i];
        }
        if(temp.size()>0) st.push(temp);
        string ans = "";
        while(!st.empty()){
            ans += st.top()+ " ";
            st.pop();
        }
        return ans.substr(0,ans.size()-1);
    }
};