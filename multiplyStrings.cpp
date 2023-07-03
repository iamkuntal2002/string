#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/multiply-strings/
// class Solution {
// public:
//     string multiply(string num1, string num2) {
//         if(num1 == "0" || num2 == "0") return "0";
//         vector<int>mult(num1.size() + num2.size(),0);
//         for(int i = num1.size() - 1; i>= 0; --i)
//         {
//             for(int j = num2.size() -1; j>= 0; --j){
//                 mult[i+j+1] += (num1[i] - '0')*(num2[j] - '0');
//                 mult[j+i] += mult[i+j+1]/10;
//                 mult[i+j+1] %= 10;
//             }
//         }
//         int i = 0;
//         while(i<mult.size() && mult[i] == 0) ++i;
//         string res = "";
//         while(i<mult.size())
//             res.push_back(mult[i++] +'0');
//         return res;
//     }
// };

//gfg version
string multiplyStrings(string num1, string num2) {
       //Your code here
        if(num1 == "0" || num2 == "0") return "0";
        vector<int>mult(num1.size() + num2.size(),0);
        int sign1 = num1[0] == '-' ? 1 : 0;
        int sign2 = num2[0] == '-' ? 1 : 0;
        for(int i = num1.size() - 1; i>= sign1; --i)
        {
            for(int j = num2.size() -1; j>= sign2; --j){
                mult[i+j+1] += (num1[i] - '0')*(num2[j] - '0');
                mult[j+i] += mult[i+j+1]/10;
                mult[i+j+1] %= 10;
            }
        }
        int i = 0;
        while(i<mult.size() && mult[i] == 0) ++i;
        string res = "";
        while(i<mult.size())
            res.push_back(mult[i++] +'0');
        if(sign1 == 1 && sign2 == 0) return "-"+res;
        else if(sign1 == 0 && sign2 == 1) return "-"+res;
        else return res;
    }
    int main(){
        cout<<multiplyStrings("232","2")<<endl;
    }