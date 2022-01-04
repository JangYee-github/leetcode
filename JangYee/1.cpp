/*
 * =====================================================================================
 *
 *       Filename:  1.cpp
 *
 *    Description:  two-sum
 *
 *        Version:  1.0
 *        Created:  01/04/2022 10:15:25 PM
 *       Revision:  None
 *       Compiler:  gcc
 *
 *         Author:  JangYee
 *   Organization:  None
 *
 * =====================================================================================
 */
#include <stdlib.h>

namespace JangYee {
    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int len = nums.size(), i, j;
            for (i=0; i<len; i++) {
                for (j=i+1; j<len; j++) {
                    if (nums[i] + nums[j] == target) {
                        return vector<int> {nums[i], nums[j]}
                    }
                }
            }
        }
        return vector<int> {0, 0}
    };
}
