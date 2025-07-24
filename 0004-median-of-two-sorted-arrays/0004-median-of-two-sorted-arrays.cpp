class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;

        if (total == 0) return 0.0; 

        if (m == 0) {
            if (n % 2 == 1) return nums2[n / 2];
            else return (nums2[n / 2 - 1] + nums2[n / 2]) / 2.0;
        }

        if (n == 0) {
            if (m % 2 == 1) return nums1[m / 2];
            else return (nums1[m / 2 - 1] + nums1[m / 2]) / 2.0;
        }

        int i = 0, j = 0;
        int prev = 0, curr = 0;

        for (int k = 0; k <= total / 2; k++) {
            prev = curr;
            if (i < m && (j >= n || nums1[i] <= nums2[j])) {
                curr = nums1[i++];
            } else {
                curr = nums2[j++];
            }
        }

        if (total % 2 == 0) {
            return (prev + curr) / 2.0;
        } else {
            return curr;
        }
    }
};
