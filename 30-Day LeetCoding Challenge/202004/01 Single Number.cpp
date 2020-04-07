#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution1 {
   public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hmap;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (hmap.count(nums[i]))
                ans -= nums[i];
            else
                ans += nums[i];

            hmap[nums[i]] = i;
        }

        return ans;
    }
};

class Solution {
   public: 
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     ans ^= nums[i];
        // }
        for (const int i : nums) {
            ans ^= i;
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    Solution solution;
    vector<int> a1 = {2, 2, 1};
    vector<int> a2 = {4, 1, 2, 1, 2};

    int ans = solution.singleNumber(a1);
    cout << "Input: [2, 2, 1]" << endl;
    cout << "Output: " << ans << endl;

    ans = solution.singleNumber(a2);
    cout << "Input: [4, 1, 2, 1, 2]" << endl;
    cout << "Output: " << ans << endl;

    return 0;
}