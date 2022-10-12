class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int n= gas.size();
        int gasRemainingAtExit = 0;
        //finding out if its possible to go around circle. (feasible with fuel)
        for(int i=0; i<n;i++)
        {
            gasRemainingAtExit += (gas[i]- cost[i]);
        }
        if(gasRemainingAtExit < 0)
        {
            return -1;
        }
        
        //finding starting point where answer is valid
        int start = 0;
        gasRemainingAtExit = 0;
        for(int i=0; i<n; i++)
        {
            gasRemainingAtExit += (gas[i] - cost[i]);
            
            if(gasRemainingAtExit < 0)
            {
                start = i+1;
                gasRemainingAtExit = 0;    
            }
        }
        return start;
    }
};