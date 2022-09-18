class Solution {
public:
    bool possible(vector<int> v, int rate, int total)
    {   
        int t = 0;
        for (unsigned long long int i :  v)
        {
            t += ceil((double)i / rate);
        }
        return (t <= total);
    }
    
    int minEatingSpeed(vector<int>& v, int h) 
    {
        int l = 1;
	    int r = *max_element(v.begin(),v.end());
        
        while (l < r)
        {
            unsigned long long int mid = (l + r) / 2;
            if (possible(v, mid, h))
                r = mid;
            else
                l = mid + 1; 
        }
        return l;
    }
    
    // doesnt work because imagine [2,3] and 3 is answer
    // we wont shrink hi here and it goes in infinite loop
    // our mid choice is such a way that if 2 ele's are there -> we pick hi
    // when this is choice of mid we need to make sure, hi shrinks when we have 2 eles
    // so you need to have hi = hi-1 if you choose this way of picking mid
    // since if you do this way, you'll loose actual possible ans we'll try not to reduce hi
    // we'll try incremennting lo. & ofc choose a logic for mid where lo gets changed when array has only 2 eles
    
//     int minEatingSpeed(vector<int>& v, int h) 
//     {
//         int lo = 1;
//         int hi = *max_element(v.begin(),v.end());
        
//         while(hi > lo)
//         {
//             long long mid = (lo+hi+1)/2;
//             cout<<lo<<" "<<mid<<" "<<hi<<endl;
//             if(possible(v, mid, h))
//             {
//                hi = mid; 
//             }
//             else
//             {
//                 lo = mid + 1;
//             }
//         }
//         return lo;
//     }
    
     //Other way is to not worry about choosing mid but reducing both lo and hi
    // int mid = (lo+hi)/2;
    // if(valid(..)) { ans = mid; hi = mid-1;}
    // else {lo = mid+1}
    // return ans
    
    
    
};