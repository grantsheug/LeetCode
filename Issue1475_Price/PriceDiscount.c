/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize){
    *returnSize = pricesSize;
    for(int ItemIdx =0; ItemIdx < pricesSize; ItemIdx++)
    {
        for(int FollowItemIdx=ItemIdx+1; FollowItemIdx < pricesSize; FollowItemIdx++)
        {
            if(prices[ItemIdx] >= prices[FollowItemIdx])
            {
                prices[ItemIdx] -= prices[FollowItemIdx];
                break;
            }
        }
    }
    return prices;
}
