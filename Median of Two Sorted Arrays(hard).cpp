/*There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5*/


#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        for(auto i = nums1.begin();i!=nums1.end();i++)
        {
            nums3.push_back(*i);
        }
        for(auto i = nums2.begin();i!=nums2.end();i++)
        {
            nums3.push_back(*i);
        }
         for(auto i = nums3.begin();i!=nums3.end();i++)
        {
            cout<<*i<<' ';
        }
        cout<<endl;
        for(auto i = nums3.begin();i!=nums3.end();i++)
        {
            for(auto j = i+1;j<nums3.end();j++)
            {
                if((*i)>*(j))
                {
                    int temp;
                    temp = *j;
                    *j = *i;
                    *i = temp;
                }
            }
        }
        for(auto i = nums3.begin();i!=nums3.end();i++)
        {
            cout<<*i<<' ';
        }
        cout<<endl;
        int num = nums3.size();
        if(num%2==1)
        {
            return nums3[(num+1)/2-1];
        }
        else
        {
            return double(nums3[int(num/2)]+nums3[int(num/2-1)])/2;
        }
    }
};