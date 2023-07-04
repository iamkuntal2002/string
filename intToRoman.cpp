#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/integer-to-roman/
class Solution {
public:
    string intToRoman(int num) {
        int value[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string symbol[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        string ans = "";
        int index = 12;
        while(num)
        {
            int quo = num / value[index];
            num = num % value[index];
            while(quo)
            {
                ans += symbol[index];
                quo--;
            }
            index--;
        }
        return ans;
    }
};
// 58 
// 58/1000 = 0, 58%1000 = 58
// 58/50 = 1, 58%50 = 8;
// 8/5 = 1, 8%5 = 3
// 3/1 = 3,