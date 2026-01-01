#pragma GCC optimize("O3, unroll-loops")
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    *returnSize=digitsSize;
    for(int i=digitsSize-1;i>=0;--i){
        digits[i]++;
        if(digits[i]<10) return digits;
        digits[i]=0;
    }
    (*returnSize)++;
    digits=(int*)realloc(digits,sizeof(int)*(digitsSize+1));
    memset(digits,0,(digitsSize+1)*sizeof(int));
    digits[0]=1;
    return digits;
}
