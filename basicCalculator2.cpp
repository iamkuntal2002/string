#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/basic-calculator-ii/
int calculate(string s)
{
    long int res = 0;
    int len = s.length();
    if (s == "" || (len == 0))
        return 0;
    stack<int> stack;
    long int num = 0;
    char sign = '+';
    for (int i = 0; i < len; i++)
    {
        if (isdigit(s[i]))
        {
            num = num * 10 + s[i] - '0';
        }
        if (((!isdigit(s[i]) && s[i] != ' ') || i == len - 1))
        {
            if (sign == '-')
            {
                stack.push(-num);
            }
            if (sign == '+')
            {
                stack.push(num);
            }
            if (sign == '*')
            {
                int topval = stack.top();
                stack.pop();
                stack.push(topval * num);
            }
            if (sign == '/')
            {
                int topval = stack.top();
                stack.pop();
                stack.push(topval / num);
            }
            sign = s[i];
            num = 0;
        }
    }
    while (!stack.empty())
    {
        cout<<stack.top()<<endl;
        res += stack.top();
        stack.pop();
    }
    return res;
}
int main()
{
    cout<<calculate("3+2*2")<<endl;
}