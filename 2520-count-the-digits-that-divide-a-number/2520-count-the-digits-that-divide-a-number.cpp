class Solution {
public:
    int countDigits(int num) {
        vector<int> ans;
        int anss=num;
        while(num>0){
            int digit=num%10;
            ans.push_back(digit);
            num=num/10;
        }

        int count=0;
        for(int i=0;i<ans.size();i++){
            if((anss)%ans[i]==0) count++;
        }

        return count;
    }
};