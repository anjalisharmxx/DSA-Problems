class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tg=0,tc=0,currg=0;
        for(int i:gas){
            tg+=i;
        }
        for(int i:cost){
            tc+=i;
        }
        
        if(tg<tc) return -1;
        
        int start=0;
        for(int i=0;i<gas.size();i++){
            currg+=(gas[i]-cost[i]);
            if(currg<0){
                start=i+1;
                currg=0;
            }
        }
        return start;
    }
};