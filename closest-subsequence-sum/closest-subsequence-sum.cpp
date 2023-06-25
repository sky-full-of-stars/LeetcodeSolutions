class Solution {
public:
    vector<int> generate(vector<int>& nums, int lo, int hi)
    {
        int n = hi-lo+1;
        vector<int> subsetSums;
        for(int i=0; i<(1<<n); i++)
        {
            int curSum =0;
            for(int j=0; j<n; j++)
            {
                if(i&(1<<j))
                {
                    curSum += nums[j+lo];
                }
            }
            subsetSums.push_back(curSum);
        }
        return subsetSums;
    }

    int minAbsDifference(vector<int>& nums, int goal) 
    {
        int n = nums.size();
        if(n == 1)
        {
            return min(abs(0-goal), abs(nums[0]-goal));
        }

        vector<int> sumsFromFirstHalf =  generate(nums, 0, n/2-1);
        
        vector<int> sumsFromSecondHalf = generate(nums, n/2 ,n-1);
        sort(sumsFromSecondHalf.begin(), sumsFromSecondHalf.end());

        int minDifference = INT_MAX;
        for(int firstNum: sumsFromFirstHalf)
        {
            int secondNumNeeded = goal-firstNum;
            
            int sz = sumsFromSecondHalf.size();
            int pos = lower_bound(sumsFromSecondHalf.begin(), sumsFromSecondHalf.end(),secondNumNeeded)
                       - sumsFromSecondHalf.begin();

            if(pos<sz and sumsFromSecondHalf[pos] == secondNumNeeded)
            {
                int secondNum = sumsFromSecondHalf[pos];
                minDifference = min(minDifference, abs(goal - (firstNum + secondNum)));  
            }   
            else
            {
                int secondNum = (pos < sz)? sumsFromSecondHalf[pos] : 0;
                minDifference = min(minDifference, abs(goal - (firstNum + secondNum)));

                secondNum = (pos-1>=0)? sumsFromSecondHalf[pos-1] : 0;
                minDifference = min(minDifference, abs(goal - (firstNum + secondNum)));
            }
        }

        return minDifference;
    }
    //https://youtu.be/naz_9njI0I0
};