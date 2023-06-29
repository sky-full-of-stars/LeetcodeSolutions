class Solution {
public:
    typedef pair<double, int> pdi; //prob, node
    
    const static int maxN = 1e4+4;
    vector<pair<int, double>> gp[maxN];
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int s, int e) 
    {
        vector<double> prob(n, 0.0);
        prob[s] = 1.0;
            
        for(int i=0;i<edges.size(); i++)
        {
            vector<int> edge = edges[i];
            int from = edge[0];
            int to = edge[1];
            double prob = succProb[i];
            
            gp[from].push_back({to, prob});
            gp[to].push_back({from, prob});
        }
        
        priority_queue<pdi> q;
        q.push({prob[s], s});
        while(!q.empty())
        {
            pdi top = q.top();
            q.pop();
            
            double curProb = top.first;
            int curNode = top.second;
            
            if(curNode == e)
            {
                return curProb;
            }
            
            for(auto i: gp[curNode])
            {
                int nxtNode = i.first;
                double nxtProb = i.second;
                //cout<<curNode<<" "<<nxtNode<<" "<<prob[nxtNode]<<" "<<(curProb*nxtProb)<<endl;
                if(prob[nxtNode] < curProb*nxtProb)
                {
                    prob[nxtNode] = curProb*nxtProb;
                    q.push({prob[nxtNode], nxtNode});
                }
            }
        }
        return prob[e];
    }   
};