class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        // no median for empty array, ensures k >= 1
        if(n == 0) return -1;
        
        return n % 2 
            // odd
            ? findKthValue(nums1, nums2, 0, 0, n/2 + 1)
            // even
            : (findKthValue(nums1, nums2, 0, 0, n/2) + findKthValue(nums1, nums2, 0, 0, n/2+1))/2;
    }
    double findKthValue(vector<int>& nums1, vector<int>& nums2, int begin1, int begin2, int k){
        // ensure nums1 is smaller
        if(nums1.size() - begin1 > nums2.size() - begin2){
            return findKthValue(nums2, nums1, begin2, begin1, k);
        }
        // nums1 empty
        if(nums1.size() <= begin1) return nums2[begin2 + k-1];
        
        // when k/2 - 1 < 0, k is always >= 1
        if(k == 1) {
            return min(nums1[begin1], nums2[begin2]);
        }
        
        // get k elements in total
        int pa = min(k/2, nums1.size() - begin1);
        int pb = k - pa;
        if(nums1[begin1 + pa - 1] == nums2[begin2 + pb - 1]){
            return nums1[begin1 + pa - 1];
        }
        // discard all <= pa
        else if(nums1[begin1 + pa - 1] < nums2[begin2 + pb - 1]){
            return findKthValue(nums1, nums2, begin1 + pa, begin2, k - pa);
        }
        else{
            return findKthValue(nums1, nums2, begin1, begin2 + pb, k - pb);
        }
    }
    int min(int lhs, int rhs){
        return lhs < rhs ? lhs : rhs;
    }
};
