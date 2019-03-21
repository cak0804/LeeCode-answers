/*Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

*/

#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x/10==0)
            return x;
        else if(x>2147483647||x<-2147483648)
            return 0;
        else{
            string max1 = "2147483647";
            string max2 = "2147483648";
            if(x>0)
            {
                string s = to_string(x);
                string reverse_ = "";
                for(auto i=s.end()-1;i>=s.begin();i--)
                    reverse_ += *i;
                 if(reverse_.length()==10)
                 {
                     if(reverse_>max1)
                        return 0;
                     else{return atoi(reverse_.c_str());}
                 }
                else return atoi(reverse_.c_str());
            }
            else
            {
                string s = to_string(x);
                cout<<s<<endl;
                string reverse_ = "";
                for(auto i=s.end()-1;i>=s.begin();i--)
                    reverse_ += *i;
                reverse_.pop_back();
                if(reverse_.length()==10)
                 {
                     if(reverse_>max2)
                        return 0;
                     else return -atoi(reverse_.c_str());
                 }
                else
                {
                    cout<<reverse_<<' '<<atoi(reverse_.c_str());
                    return -atoi(reverse_.c_str());
                } 
            }
            
        }
        

    }
};
 int main()
 {
     Solution sol;
     int num;
     cin>>num;
     cout<<sol.reverse(num);
 }