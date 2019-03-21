/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].*/


#include<vector>
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
       for(int i=0;i<nums.size();i++)
       {
           for(int j = i+1;j<nums.size();j++)
           {
               if(nums[i]+nums[j]==target){
                   ans.push_back(nums[i]);
                   ans.push_back(nums[j]);
               }
           }
       }
       return ans;
    }
};

int main(){
    vector<int> nums,ans;
    int num=0,value,flag=10;
    char ch;
    string str;
    getline(cin,str);
    cin>>value;
    for(auto i=0;i<str.size();i++){
       
        if(str[i]>='0'&&str[i]<='9'){
            num=int(str[i]-'0');
            while((i+1)<str.size()&&(str[i+1]>='0'&&str[i+1]<='9')){
                num=num*flag+int(str[i+1])-'0';
                i++;
            }
            nums.push_back(num);
        }
    }
    Solution s;
    ans = s.twoSum(nums,value);
    if(!ans.empty()){
        cout<<'[';
    for(auto i = ans.begin();i!=ans.end();i++){
        cout<<(*i);
        if(i!=(ans.end()-1))
                cout<<',';
    }
    cout<<']';
    }
    
}
