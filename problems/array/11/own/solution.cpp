class Solution {
public:
    int maxArea(vector<int>& height) {
        int hei_size = height.size();
        int headp = 0, tailp = hei_size - 1;
        int max_area = 0, cur_area;
        while ( headp < tailp) {
            if (height[headp] > height[tailp]) {
                cur_area = (tailp - headp) * height[tailp];
                tailp--;
            }
            else {
                cur_area = (tailp - headp) * height[headp];
                headp++;
            }
            max_area = max_area > cur_area ? max_area : cur_area;
        }
        return max_area;
    }
};
