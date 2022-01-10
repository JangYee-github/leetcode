class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> numsAll;
        int size1 = nums1.size(), size2 = nums2.size();
        int sizeSum = size1 + size2;
        int sizeNeed = sizeSum / 2 + 1;
        // cout << "sizeNeed is : " << sizeNeed << endl;
        int i = 0, j = 0, n = 0;
        while (n < sizeNeed) {
            n++;
            if (i >= size1) {
                numsAll.push_back(nums2[j]);
                j++;
                continue;
            }
            if (j >= size2) {
                numsAll.push_back(nums1[i]);
                i++;
                continue;
            }
            if (nums1[i] < nums2[j]) {
                numsAll.push_back(nums1[i]);
                i++;
            }
            else {
                numsAll.push_back(nums2[j]);
                j++;
            }
        }
        if (sizeSum % 2 == 0) {
            return ((double)numsAll[n-1] + (double)numsAll[n-2]) / 2.0;
        }
        else {
            return numsAll[n-1];
        }
    }
};
