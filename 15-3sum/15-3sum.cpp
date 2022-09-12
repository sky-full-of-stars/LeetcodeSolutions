class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        int n = nums.size();
        int target = 0;
        sort(nums.begin(), nums.end());
        for(int i: nums) cout<<i<<" ";
        cout<<endl;
        for(int firstIdx =0; firstIdx<n; firstIdx++)
        {
            if(nums[firstIdx] > 0)
            {
                break; //lowestNum itself is >0 and hence cant find other pairs
            }
            
            if(firstIdx!=0 and nums[firstIdx]== nums[firstIdx-1])
            {
                continue; //dont process duplicate lowestNums(firstNum) again 
            }
            
            int lo = firstIdx+1; //secondNumIdx
            int hi = n-1; //thirdNumIdx
            while(lo<hi)
            {
                int sum = nums[firstIdx]+nums[lo]+nums[hi];
                
                if(sum == target)
                {
                    ans.push_back({nums[firstIdx],nums[lo],nums[hi]});
                    
                    int prevSecondEle = nums[lo];
                    int prevThirdEle = nums[hi];
                    while(lo<hi and nums[lo] == prevSecondEle) lo++; // dont want duplicate secondElements again
                    while(lo<hi and nums[hi] == prevThirdEle) hi--; // dont want duplicate thirdElements again
                }
                else if(sum> target)
                {
                    hi--;
                }
                else
                {
                    lo++;
                }
                
            }
        }
        
        return ans;
    }
};