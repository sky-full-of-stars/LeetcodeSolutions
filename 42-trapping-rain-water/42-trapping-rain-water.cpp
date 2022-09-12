class Solution {
public:
    int trapBrute(vector<int>& height) 
    {
        int n = height.size();
        int ans = 0;
        
        vector<int> maxSoFar(n,0);
        maxSoFar[0] = -1;
        for(int i=1;i<n;i++)
        {
            maxSoFar[i] = max(height[i-1], maxSoFar[i-1]);
        }
        
        vector<int> maxAhead(n,0);
        maxAhead[n-1] = -1;
        for(int i=n-2;i>=0;i--)
        {
            maxAhead[i] = max(height[i+1], maxAhead[i+1]);
        }
        
        for(int i=0;i<n;i++)
        {
            int curHeight = height[i];
            int leftMax = maxSoFar[i];
            int rightMax = maxAhead[i];
    
            // If no taller block exists, not possible to store water.
            if(leftMax >= curHeight and rightMax >= curHeight)
            {
                int waterOnCurBlock = min(leftMax,rightMax) - curHeight;
                ans += waterOnCurBlock;
            }
        }
        
        return ans;  
    }
    
    int trap(vector<int>& height) 
    {
        int n = height.size();
        int ans = 0;
        int lo=0, hi= n-1;
        int leftMx = 0, rightMx = 0;
        
        while(lo<hi)
        {
            //[3 1 5 2 4]
            //At 3, what amount of water is stored?
            //water will be stored to right and left.
            //maxSoFarInLeft will be known
            //that is less than height[right]
            //so min of those 2 will get trapped
            // ie leftMax amount will be trapped on top
            
            //next iteration at 1,
            // 3 will be leftMx and 4>3
            // so (3-1) amount of water gets stored
            if(height[lo] < height[hi]) 
            {
                leftMx = max(leftMx, height[lo]);
                ans += (leftMx - height[lo]);
                lo++;
            }
            //at 5,
            //left = 5, right=4
            // calculate amt of water gets stored on 4
            // since 5>4 -> this is leftMax
            // rightMax we know already
            // since rightMax < 5(leftMax), this much of water get trapped.
            else
            {
                rightMx = max(rightMx, height[hi]);
                ans += (rightMx - height[hi]);
                hi--;
            }
        }
        
        return ans;
    }
};


//.    what amount of water can be stored in idx 4? 
//        132014
//             .
//         .   .
//         ..  .
//        ... ..
        
//         for every ele:
//             ans +=  curEleHeight- min(maxInLeft, maxInRight)
        
        
        