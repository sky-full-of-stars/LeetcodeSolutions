class Solution {
private: 
    double getMedian(vector<int> &v)
    {
        int lo=0, hi=v.size()-1;
        if(v.size()%2 != 0)
        {
            return v[v.size()/2 ];
        }
        else
        {
            return (v[v.size()/2 ] + v[v.size()/2  -1])/2.0;
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        //dont really want to think if existing code works already for this corner case
        //hence, having a seperate logic for this.
        if(nums1.size() == 0)
        {
           return getMedian(nums2); 
        }
        if(nums2.size() == 0)
        {
            return getMedian(nums1);
        }
        
        
        if(nums1.size() > nums2.size())
            swap(nums1,nums2);
        
        int n = nums1.size();
        int m = nums2.size();
        int median = (n+m+1)/2; 
        
        double ans = -1;
        int lo = 0, hi = n;
        /*
        I wanted to make it work with hi = n-1;
        and with mid as index upto with I select my left array.
        and when I get mid, my left section includes a[mid] as well
        but the problem with this when I select 0 elements from num1
        mid should become -1 & still stay valid(hi>=lo)
        it really complicates logic if I go ahead with this approach
        
        hence lets redefine mid as number of elements selected in nums1
        min 0 elements can be selected & max of all elemenst(size) (not size-1)
        can be selected
        and when I get mid, my left section is [0, mid-1]
        this wont complicate logic as mid == 0 means, I'm selecting no elements
        and in this situation of mid, hi>=lo
        */
        
        while(hi >= lo)
        {
            int mid = (lo+hi)/2;
            //cout<<lo<<" "<<mid<<" "<<hi<<endl;
            
            int nums1LEnd = (mid-1 <= -1)? INT_MIN: nums1[mid-1];
            int nums1RStart = ((mid) >= n)? INT_MAX : nums1[(mid)];
            
            int nums2LEnd = ((median- mid-1) <= -1)? INT_MIN: nums2[(median- mid-1)];
            int nums2RStart = ((median-mid) >= m)? INT_MAX: nums2[(median-mid)];
            
            if(nums1LEnd <= nums2RStart and nums2LEnd <= nums1RStart)
            {
               if((n+m)%2 == 0)
               {
                   double lMedian = max(nums1LEnd, nums2LEnd);
                   double rMedian = min(nums1RStart, nums2RStart);
                   //cout<<lMedian<<" "<<rMedian<<endl;
                   ans = (lMedian + rMedian)/2.0;
               }
               else
               {
                   ans = max(nums1LEnd, nums2LEnd);
               } 
               break; 
            }
            
            if(nums1LEnd > nums2RStart)
            {
                hi = mid-1;
            }
            else
            {
                lo = mid+1;
            }
        }
        
        
        return ans;
    }
};



