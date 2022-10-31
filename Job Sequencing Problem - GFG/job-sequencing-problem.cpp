//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    private:
    bool static comp(Job a, Job b)
    {
        return a.profit > b.profit;
    }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, comp);
        
        int mxDeadLine = 0;
        for(int idx=0; idx<n; idx++)
        {
            Job i = arr[idx];
            mxDeadLine = max(mxDeadLine, i.dead);
        }
        vector<int> times(mxDeadLine+1, -1);
        
        int jobs = 0, profit = 0;
        for(int idx=0; idx<n; idx++)
        {
            Job i = arr[idx];
            if(times[i.dead] == -1)
            {
                times[i.dead] = i.profit;
                profit += i.profit;
                jobs++;
                //cout<<"assigned "<<i.profit<<" to "<<i.dead<<endl;
                continue;
            }
            int desiredTime = i.dead;
            while(desiredTime > 0)
            {
                if(times[desiredTime] == -1)
                {
                    times[desiredTime] = i.profit;
                    profit += i.profit;
                    jobs++;
                    //cout<<"assigned "<<i.profit<<" to "<<i.dead<<endl;
                    break;
                }
                else
                {
                    desiredTime--;
                }
            }
        }
        
        return {jobs, profit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends