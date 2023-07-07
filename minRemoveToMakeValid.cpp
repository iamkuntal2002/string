#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        string res = "";
        for(int i =0;i<s.length();i++){
            if(s[i] == ')' && st.empty()) s[i] = ' ';   //suppose the closing bracket occurs first then make it a white-space
            if(s[i] == '(') st.push(s[i]);  //if opening bracket then push it to the stack
            else if(s[i] ==')' && !st.empty()) st.pop();    //if closing bracket then pop out from the stack 
        }
        // cout<<"s = "<<s<<endl;
        for(int i =s.length()-1;i>=0;i--){
            if(s[i] == ' ') continue;   //white space means there was a extra closing bracket so ignore this char
            if(s[i] == '(' && !st.empty()){ //if two opening bracket occurs frequently
                st.pop();
                continue;
            }
            else res += s[i];
        }
        reverse(res.begin(),res.end());
        return res;
    }
};