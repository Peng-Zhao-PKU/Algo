class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if ((n1 + n2) % 2) {
            return helper(nums1, nums2, n1 - 1, n2 - 1, (n1 + n2) / 2);
        } else {
            return (helper(nums1, nums2, n1 - 1, n2 - 1, (n1 + n2) / 2) +
                    helper(nums1, nums2, n1 - 1, n2 - 1, (n1 + n2) / 2 - 1)) * 1.0 / 2;
        }
    }
    
    int helper(vector<int>& nums1, vector<int>& nums2, int n1, int n2, int k) {
        int len1 = n1 + 1, len2 = n2 + 1;
        if (len1 == 0) {
            return nums2[k];
        }
        if (n1 > n2) {
            return helper(nums2, nums1, n2, n1, k);
        }
        if (len1 + len2 == k + 1) {
            return max(nums1[n1], nums2[n2]);
        }
        int ia = min(n1, k / 2);
        int ib = k - ia;
        if (nums1[ia] == nums2[ib]) {
            return nums1[ia];
        } else if (nums1[ia] < nums2[ib]) {
            return helper(nums1, nums2, n1, ib - 1, k);
        }
        return helper(nums1, nums2, ia - 1, n2, k);
    }
};
