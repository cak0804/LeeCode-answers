class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        l = nums1+nums2
        l.sort()
        count = len(nums1)+len(nums2)
        if count%2==1:
            return (l[int((count+1)/2)-1])
        else:
            return (((l[int(count/2)]+l[int(count/2)-1])/2))
        
