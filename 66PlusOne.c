/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//compiler optimization
#pragma GCC optimize("O3, unroll-loops")
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    //We assume that the return size will be the same as the original input. 
    //By that we assume we wont have an overflow.
    *returnSize=digitsSize;
    //We are iterating from the end, like we would in case of a addition on paper.
    //If the incremented value of digits[n-1] is < 10 means we can return.
    //If we have a carry we need to iterate further.
    for(int i=digitsSize-1;i>=0;--i){
        digits[i]++;
        if(digits[i]<10) return digits;
        digits[i]=0;
    }
    //extra digit
    (*returnSize)++;
    //modifying the size
    digits=(int*)realloc(digits,sizeof(int)*(digitsSize+1));
    //reseting the arr
    memset(digits,0,(digitsSize+1)*sizeof(int));
    //inserting leading one examp.: [9,9,9] -> [1,0,0,0]
    digits[0]=1;
    return digits;
}
