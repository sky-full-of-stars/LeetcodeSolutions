typedef pair<int, int> pi;
#define ff first
#define ss second

class StockSpanner 
{
    public:
        stack<pi> s;
        StockSpanner() {

        }

        int next(int price) {
            int ans = 1;

            while(!s.empty() and s.top().ff <= price)
            {
                ans += s.top().ss;
                s.pop();
            }

            s.push({price, ans});
            return ans;
        }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */