typedef pair<int,int> pi;
typedef pair<pi,char> type;
class Solution 
{

public:
    class Compare
    {
        public:
        bool operator()(const type a, const type b)
        {
            if(a.first.first > b.first.first)
                return true;
            if(a.first.first == b.first.first)
                return (a.first.second < b.first.second);
            return false;
        }
    };
    
    priority_queue<type, vector<type>, Compare> mnHeap;
    
    int leastInterval(vector<char>& tasks, int n) 
    {
        // find {least nxt execution time, max repeated} element
        
        map<char, int> count;
        for(char i: tasks)
            count[i]++;
        
        for(auto i: count)
            mnHeap.push({ {0, i.second},i.first });
        
        int curTime = 0;
        
        while(!mnHeap.empty())
        {
            int nextBestTaskTime = mnHeap.top().first.first;
            
            if(curTime < nextBestTaskTime)
            {
                curTime++;
            }
            else
            {
                char curTask = mnHeap.top().second;
                
                int curFreq = mnHeap.top().first.second;
                curFreq--;
                
                int curExecutionTime = mnHeap.top().first.first;
                int nxtExecutionTime = curExecutionTime + n + 1;
                
                mnHeap.pop();
                if(curFreq > 0)
                    mnHeap.push({ {nxtExecutionTime, curFreq}, curTask});
                
                curTime++;
            }
        }
        
        return curTime;
    }
};