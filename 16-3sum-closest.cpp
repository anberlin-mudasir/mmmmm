class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Sort first!
        sort(nums.begin(), nums.end());
        int ret = nums[0] + nums[1] + nums[2];
        for(int i=0; i<nums.size(); i++){
            int j=i+1, k=nums.size()-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(sum - target) < abs(ret - target)){
                    ret = sum;
                }
                if(sum < target){
                    j++;
                }
                else if(sum > target){
                    k--;
                }
                // handle all conditions, in order to terminate
                else{
                    return target;
                }
            }
        }
        return ret;
    }
};
