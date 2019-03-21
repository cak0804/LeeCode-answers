/*Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
Example 1:

Input: "42"
Output: 42
Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.*/

#include<iostream>
#include<ctype.h>
#include<string>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        const int MAX =  2147483647;
        const int MIN = -2147483648;
        unsigned long long temp;
        string mark=" ",sub;
        int ans=0;
        for(int i = 0;i<str.length();i++)
        {
            if(str[i]!=' ')
            {
                sub = str.substr(i,-1);
                break;
            }
        }
        cout<<sub<<endl;
        if(!isdigit(sub[0])&&sub[0]!='-'&&sub[0]!='+') 
            return 0;
        else{
            int i=0;
            if(sub[0]=='+'||sub[0]=='-')
            {
                mark = sub[0];
                i = 1;
            }
            for(;i<sub.length();i++)
        {
            if(isdigit(sub[i]))
            {
                temp = ans;
                temp=(temp*10+int(sub[i]-'0'));
                cout<<temp<<endl;
                if(temp<=MAX)
                {
                    ans=temp;
                    //cout<<ans<<endl;
                }
                    
                else return (mark=="-")?MIN:MAX;             
            }
                
            else break;
        }
        }
        if(mark=="-")
        {
            ans = -ans;
        } 
        return ans;
    }
};
int main()
{
    Solution sol;
    cout<<sol.myAtoi("-91283472332");
}