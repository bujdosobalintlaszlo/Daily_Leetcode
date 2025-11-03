class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int prev=0;
        int cost=0;
        int colorsL = colors.length();
        for(int i=1;i<colorsL;++i){
            if(colors[i]==colors[prev]){
                int ithCost=neededTime[i];
                int prevthCost=neededTime[prev];
                if(ithCost<prevthCost){
                    cost+=ithCost;
                }else{
                    cost+=prevthCost;
                    prev=i;
                }
            }else{
                prev=i;
            }
        }
        return cost;
    }
};
