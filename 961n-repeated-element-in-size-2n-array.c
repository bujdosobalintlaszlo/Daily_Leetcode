int repeatedNTimes(int* nums, int n) {
    int curr;
    for(int i=0;i<n;++i){
        curr=nums[i];
        for(int j=i+1;j<n;++j){
            if(curr==nums[j]){
                return curr;
            }
        }
    }
    return nums[n-1];
}
