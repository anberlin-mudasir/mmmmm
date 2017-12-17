class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int size = nums.size();
        
        sort(nums.begin(), nums.end());
        for(int i=0; i<size; i++){
            if(i>0){
                while(nums[i] == nums[i-1]) i++;
                if(i>=size) break;
            }
            
            for(int j=i+1; j<size; j++){
                if(j>i+1){
                    while(nums[j] == nums[j-1]) j++;
                    if(j>=size) break;
                }
                
                int k=j+1, l=size-1, t=target-nums[i]-nums[j];
                while(k<l){
                    int sum=nums[k] + nums[l];
                    if(sum == t){
                        ret.push_back({nums[i], nums[j], nums[k], nums[l]});
                        do{
                            k++;
                        }while(k<size && nums[k]==nums[k-1]);
                        do{
                            l--;
                        }while(l>=0 && nums[l]==nums[l+1]);
                    }
                    else if(sum < t){
                        do{
                            k++;
                        }
                        while(k<size && nums[k]==nums[k-1]);
                    } 
                    else{
                        do{
                            l--;
                        }
                        while(l>=0 && nums[l]==nums[l+1]);
                    };
                }
            }
        }
        return ret;
    }
};