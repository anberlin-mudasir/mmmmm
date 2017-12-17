class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        map<int, int>::iterator it;
        for(int i=0; i < nums.size(); i++){
            it = mp.find(target - nums[i]);
            // match success
            if(it != mp.end()){
                return {it->second, i};
            }
            // no match
            else{
                mp.insert(pair<int, int>(nums[i], i));
            }
        }
        // This won't happen
        return {8, 8};
    }
};
