// 暴力查询法
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        int len = nums.size();
//        for (int i = 0; i < len; i++) {
//            for (int j = i+1; j < len; j++) {
//                if (nums[i] + nums[j] == target)
//                    return {i, j};
//            }
//        }
//        return {};
//    }
//};

// 哈希表法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        unordered_map<int, int> num_map;
        for (int i = 0; i < len; i++) {
            auto p = num_map.find(target - nums[i]);
            if (p != num_map.end()) {
                return {num_map.find(target - nums[i])->second, i};
            }
            num_map[nums[i]] = i;
        }
        return {};
    }
};
