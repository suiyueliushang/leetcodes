class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        :date:2019/9/22
        """
        m=len(nums1)
        n=len(nums2)
        if n==0:#判断两个数组是否为空
            if m%2==0:
                return (nums1[int((m-1)/2)]+nums1[int((m-1)/2+1)])/2
            else:
                return nums1[int(m/2)]
        elif m==0:
            if n%2==0:
                return (nums2[int((n-1)/2)]+nums2[int((n-1)/2+1)])/2
            else:
                return nums2[int(n/2)]
        #数组不为空时，使用二叉搜索找到合适的划分方法
        iMin=0
        iMax=m
        while iMin<=iMax:
            i=int((iMin+iMax)/2)
            j=int((m+n+1)/2)-i
            if j<0:#判断j的值是否越界
                iMax=i-1
                continue
            elif j>n:
                iMin=i+1
                continue
            #对可能的情况进行分析
            if 0<i<m and 0<j<n:
                if nums1[i-1]<=nums2[j] and nums1[i]>=nums2[j-1]:
                    if (m+n)%2==0:
                        return (max([nums1[i-1],nums2[j-1]])+min([nums1[i],nums2[j]]))/2
                    else:
                        return max([nums1[i-1],nums2[j-1]])
                elif nums1[i-1]>nums2[j]:
                    iMax=i-1
                else:
                    iMin=i+1
            elif 0<i<m and j==0:#上中下0分
                if nums1[i-1]<=nums2[0]:
                    if (n+m)%2==0:
                        return (min([nums1[i],nums2[0]])+nums1[i-1])/2
                    else:
                        return nums1[i-1]
                else:
                    iMax=i-1
            
            elif 0<i<m and j==n:#上中下满分
                if nums2[n-1]<=nums1[i]:
                    if (n+m)%2==0:
                        return (max([nums1[i-1],nums2[n-1]])+nums1[i])/2
                    else:
                        return max([nums1[i-1],nums2[n-1]])
                else:
                    iMin=i+1

            elif i==0:
                if j==n:
                    if nums1[0]>=nums2[n-1]:
                        if (n+m)%2==0:
                            return (nums1[0]+nums2[n-1])/2
                        else:
                            return nums2[n-1]
                    else:
                        iMin=i+1
                elif 0<j<n:#上0下中分
                    if nums1[0]>=nums2[j-1]:
                        if (n+m)%2==0:
                            return (min([nums1[0],nums2[j]])+nums2[j-1])/2
                        else:
                            return nums2[j-1]
                    else:
                        iMin=i+1


            elif i==m:
                if j==0:
                    if (n+m)%2==0:
                        return (nums1[m-1]+nums2[0])/2
                    else:
                        return nums1[m-1]
                elif 0<j<n:
                    if (n+m)%2==0:
                        return (max([nums1[m-1],nums2[j-1]])+nums2[j])/2
                    else:
                        return max([nums1[m-1],nums2[j-1]])