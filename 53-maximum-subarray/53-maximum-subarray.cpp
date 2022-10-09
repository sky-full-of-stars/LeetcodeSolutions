class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int sum = 0, mxSum = 0, mxEle = INT_MIN;
        for(int num: nums)
        {
            sum += num;
            mxEle = max(mxEle, num);
            mxSum = max(mxSum, sum);
            if(sum < 0)
                sum = 0;
        }
        
        if(mxSum == 0) 
            mxSum = mxEle;
        
        return mxSum;
    }
};