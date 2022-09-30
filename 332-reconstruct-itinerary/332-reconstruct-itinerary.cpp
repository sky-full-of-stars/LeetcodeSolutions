typedef priority_queue< string, vector<string>, greater<string> > minHeap;

class Solution 
{ 
private:
    void createGraph(vector<vector<string>>& tickets)
    {
       for(auto ticket: tickets)
        {
            string from = ticket[0];
            string to = ticket[1];
            graph[from].push(to);
        } 
    }
    
    void dfs(string from)
    {
        auto &edges = graph[from];
        while(!edges.empty())
        {
            string to = edges.top();
            edges.pop();
            dfs(to);
        }
        reversePath.push_back(from);
    }
    
public:
    map<string, minHeap> graph;
    vector<string> reversePath;
    
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        createGraph(tickets);
        
        string start = "JFK";
        dfs(start); 
        
        reverse(reversePath.begin(), reversePath.end());
        return reversePath;
    }
};