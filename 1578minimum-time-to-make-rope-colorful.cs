public class Solution {
    public int MinCost(string colors, int[] neededTime) {
        int cost =0;
        int prev =0;
        for(int i=1;i<colors.Length;++i){
            if(colors[prev] == colors[i]){
                if(neededTime[i]<neededTime[prev]){
                    cost+=neededTime[i];
                }else{
                    cost+=neededTime[prev];
                    prev=i;
                }
            }else{
                prev=i;
            }
        }
        return cost;
    }
}
