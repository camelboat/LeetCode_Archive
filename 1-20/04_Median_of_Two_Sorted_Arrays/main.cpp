#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        unsigned long m = nums1.size();
        unsigned long n = nums2.size();

        if (m > n)
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        unsigned long total = m+n;
        int parity = total%2;

        int lo = 0;
        int hi = m;

        // lo and hi are the range of partition
        while (lo <= hi)
        {
            int i = lo + floor((hi-lo)/2);
            int j = floor((m+n+1)/2) - i;

            int maxLeftA = i == 0 ? INT_MIN : nums1[i-1];
            int minRightA = i == m ? INT_MAX : nums1[i];
            int maxLeftB = j == 0 ? INT_MIN : nums2[j-1];
            int minRightB = j == n ? INT_MAX : nums2[j];

            if (maxLeftA <= minRightB && maxLeftB <= minRightA)
            {
                if (parity == 1)
                {
                    return(max(maxLeftA, maxLeftB));
                }
                else
                {
                    return((double)(max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2);
                }
            } else{
                if (maxLeftA > minRightB)
                {
                    hi = i-1;
                } else{
                    lo = i+1;
                }
            }
        }
        return 0;
    }
};