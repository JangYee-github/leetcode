class Solution {
public:
    int have_three_zero = 0;
    int removeDuplicates(vector<int>& nums) {
        int nums_size = nums.size();
        if (nums_size == 0) {
            return 0;
        }
        int fast, slow;
        int overint = nums[0] - 1;
        for (fast = 1; fast < nums_size; fast++) {
            if (nums[fast] == nums[fast-1]) {
                slow = fast + 1;
                while (slow < nums_size) {
                    if (nums[fast] != nums[slow])
                        break;
                    if (nums[slow] == 0)
                        have_three_zero = 1;
                    nums[slow] = overint;
                    slow++;
                }
            }
        }
        for (slow = 0; slow < nums_size && nums[slow] != overint; slow++) ;
        for (fast = slow + 1; fast < nums_size; fast++) {
            if (nums[fast] == overint)
                continue;
            nums[slow] = nums[fast];
            slow++;
                
        }
        return slow;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int size, first, second, three, re_find;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        size = removeDuplicates(nums);
        if (have_three_zero)
            res.push_back(vector<int> {0, 0, 0});
        for (second = 1; second < size; second++) {
            first = 0;
            three = size - 1;
            while (first < second && second < three) {
                if (nums[first] + nums[second] + nums[three] == 0) {
                    re_find = 0;
                    for (auto i = res.begin(); i < res.end(); i++) {
                        if ((*i)[0] == nums[first] && (*i)[1] == nums[second]) {
                            re_find = 1;
                            break;
                        }
                    }
                    if (!re_find)
                        res.push_back(vector<int> {nums[first], nums[second], nums[three]});
                    first++;
                    three--;
                }
                else if (nums[first] + nums[second] + nums[three] > 0) {
                    three--;
                }
                else {
                    first++;
                }
            }
        }
        return res;
    }
};
