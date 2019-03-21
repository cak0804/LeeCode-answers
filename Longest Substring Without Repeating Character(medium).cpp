/*Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.*/

class Solution{
    public:
    int lengthOfLongestSubstring(string s)
    {
        string ans = "";
        string last = "";
        int j;
        for(int i = 0;i<s.length();i++)
        {
            ans+=s[i];
            for( j=i+1;j<s.length();j++)
            {
                if(ans.find(s[j])==string::npos)
                {
                    ans+=s[j];
                }
                else
                {
                    if(ans.length()>last.length())
                    {
                        last = ans;
                    }
                    ans = "";
                    break;
                }
            }
            if(j==s.length()-1)
                break;
            else
            {
                if(ans.length()>last.length())
                    {
                        last = ans;
                    }
                    ans = "";
            }
        }
        cout<<last<<endl;
        return last.length();
    }
};