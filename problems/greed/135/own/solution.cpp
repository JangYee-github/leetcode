class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candys = {1};
        int i, size = ratings.size(), counter, min_candy = 1;
        for (i = 1; i < size; i++) {
            if (ratings[i-1] >= ratings[i])
                candys.push_back(1);
            else if (ratings[i-1] < ratings[i])
                candys.push_back(candys[i-1] + 1);
            else
                candys.push_back(candys[i-1]);
        }
        counter = candys[size - 1];
        for (i = size - 2; i > -1; i--) {
            if (candys[i] <= candys[i+1] && ratings[i] > ratings[i+1])
                candys[i] = candys[i+1] + 1;
            counter += candys[i];
        }

        // for (i = 0; i < size; i++) {
        //     cout << candys[i] << " ";
        // }
        // cout << endl;

        return counter;
    }
};
