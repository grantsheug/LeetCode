bool NextStepCheck(int* nums, int numsSize, int x, int *PassArray)
{
    if(x >=numsSize || PassArray[x] == 0)
    {
        return 0;
    }
    else if(x == numsSize-1 || PassArray[x] ==1 )
    {
        PassArray[x]=1;
        return 1;
    }
    else
    {
        bool Pass = 0;
        for(int i =1; i<= nums[x]; i++)
        {
            if(x+i <numsSize && PassArray[x+i] == -1)
            {
                Pass = NextStepCheck(nums, numsSize, x+i,PassArray);
            }
            if(Pass == 0)
            {
                PassArray[x+i] = 0;
            }
            else
            {
                PassArray[x+i] = 1;
                break;
            }
        }
        return Pass;
    }
}

bool canJump(int* nums, int numsSize){
    int *PassArray;
    PassArray = malloc(numsSize*sizeof(int));
    for(int i=0; i < numsSize;i++)
    {
        PassArray[i] = -1;
    }
    NextStepCheck(nums, numsSize, 0,PassArray);
    for(int i=0; i < numsSize;i++)
    {
        if(PassArray[i] == 1)
            return 1;
    }
    return 0;
}
