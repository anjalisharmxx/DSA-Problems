class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=INT_MAX;
        int sale=INT_MIN;

        for(int i=0;i<prices.size();i++){
            buy=min(buy,prices[i]);
            sale=max(sale,prices[i]-buy);
        }
        return sale;
    }
};