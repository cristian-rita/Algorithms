class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> hash;
        vector<int> sol;


        for(int i = 0;i<nums.size();i++) {
            auto it = hash.find(target-nums[i]);
            if(it != hash.end()) {
                sol.push_back(it->second);
                sol.push_back(i);
                return sol;
            }
            hash.insert(std::make_pair(nums[i],i));
        }
        return sol;
    }
};
