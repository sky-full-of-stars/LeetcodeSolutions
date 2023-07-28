class Solution {
public:
    int recur(int l, int r, vector<int>& nums)
    {
        //l...r
        if(l==r)
        {
            return nums[l];
        }
        
        if(l>r)
        {
            return 0;
        }
        //l....r
        //l   (l+1...r)
        int pickFirst = nums[l] + 
                        min(recur(l+2, r,nums), recur(l+1, r-1,nums));
        //l....r
        //(l....r-1)    r
        int pickLast = nums[r] +
                        min(recur(l,r-2,nums), recur(l+1, r-1,nums));
        
        return max(pickFirst, pickLast);
    }
    bool PredictTheWinner(vector<int>& nums) 
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(),0);
        //1,5,233,7
        //1 + bestFrom(5,233,7) -> min(5,233) and (233,7)
        //7 + (1,5,233)
        
        int person1Profit = recur(0, n-1, nums);
        int person2Profit = sum-person1Profit;
        cout<<person1Profit<<" "<<person2Profit<<endl;
        
        return (person1Profit >= person2Profit);
    }
};


   //[2,4,55,6,8]
   //          1
   //        2
   //      1
   //    2
   // 1             