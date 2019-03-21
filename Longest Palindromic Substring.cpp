#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool is_palindrome(string s)
    {
        auto begin = s.begin();
        auto end = s.end()-1;
        //cout<<*begin<<' '<<*end<<endl;
        while(begin<end)
        {
            if((*begin)!=(*end))
            {
                return false; 
            }
            else{
                begin++;end--;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans = "";
        ans+=s[0];
        int length = s.length(),pos;
        int max_length = 1;
        for(int i=0;i<length;i++)
        {
            string str = s.substr(i,length-i);
            pos = str.rfind(s[i]);
            if(pos==string::npos)
                break;
            else
            {
                while(true)
                {
                    str = str.substr(0,pos+1);
                    //cout<<str<<endl;
                    if(is_palindrome(str))
                 {
                     if(str.length()>max_length)
                     {
                         max_length = str.length();
                         ans = str;
                     }
                     break;
                 } 
                    else
                    {
                        str = str.substr(0,str.length()-1);
                        pos = str.rfind(s[i]);
                        if(pos==string::npos)
                            break;
                    }
                }
               

            }
        }
        return ans;   
        }
    
};
int main()
{
    Solution s;
    string str;
    cin>>str;
    //cout<<s.is_palindrome("abac");
    cout<<s.longestPalindrome(str)<<endl;
}