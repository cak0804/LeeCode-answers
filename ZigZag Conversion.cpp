/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        int index = 0;
        int length = s.length();
        if(numRows==1)
            return s;
        else{
            for(int i=0;i<numRows;i++)
        {
            index =  i;
            int num1 = 2*numRows-2*(i+1);
            int num2 = 2*i;
            int count = (num1*num2==0)?0:1;
            if(count)
            {

                while(index<length)
                {
                    if(count==1)
                    { 
                        ans+=s[index];
                        //cout<<ans<<' ';
                        index+=num1;
                        count=0;
                    }
                    else
                    {
                        ans+=s[index];
                        //cout<<ans<<' ';
                        index+=num2;
                        count=1;
                    }
                }
            }
            else
            {
                num1 = (num1==0)?num2:num1;
                while(index<length)
                { 
                    ans+=s[index];
                    //cout<<ans<<' ';
                    index+=num1;
                }
            }
        }
        //cout<<ans<<endl;
        return ans;
        }
        
    }
};

int main()
{
    Solution sol;
    cout<<endl<<sol.convert("a",1);
}