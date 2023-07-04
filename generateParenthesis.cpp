#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/generate-parentheses/
// https://www.codingninjas.com/studio/problems/generate-all-parenthesis_571?leftPanelTab=1
void helper(int open,int close,int n,string curr){
    if(open == 0 && close == 0){
        cout<<curr<<endl;
        return;
    }
    if(open>0){
        curr.push_back('(');
        helper(open-1,close,n,curr);
        curr.pop_back();
    }
    if(close>open){
        curr.push_back(')');
        helper(open,close-1,n,curr);
        curr.pop_back();
    }
}
void printWellFormedParanthesis(int n){
    // Write your code here
    string curr = "";
    helper(n,n,n,curr);
}
