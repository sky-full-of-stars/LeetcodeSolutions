class Solution {
public:
    int trap(vector<int>& height) 
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
};


//.    what amount of water can be stored in idx 4? 
//     1320134
//             .
//         .   .
//         ..  .
//        ... ..
        
//         for every ele:
//             ans +=  curEleHeight- min(maxInLeft, maxInRight)
        
        
        