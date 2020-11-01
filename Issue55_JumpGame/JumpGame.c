int checkOverZero(int* nums, int numsSize, int Start, int End, int *BiggestStep)
{
    int JumpEnd = 0;
    //Hit Last index
    if(Start == numsSize-1)
    {
        return 2;
    }
    else if(Start == End)
    {
        return 0;
    }
    else
    {
        for(int i=Start; i<End; i++)
        {
            if(nums[i]+i >= numsSize-1)
            {
                //Find the ans already
                return 2;
            }
            else if(nums[i]+i > End)
            {
                if(nums[i]+i > *BiggestStep)
                {
                    //update the farest index been touched
                    *BiggestStep = nums[i]+i;
                }
                JumpEnd = 1;
            }
        }
    }
    return JumpEnd;
}

bool canJump(int* nums, int numsSize){
    int *ZeroIndex;
    int *StartIndex;
    int Zerocount = 0;
    int TempStart = -1;
    int CanJump =1;
    int BiggestStep=0;
    
    ZeroIndex = malloc(numsSize * sizeof(int));
    StartIndex = malloc(numsSize * sizeof(int));
    //initial arr
    for(int i=0; i<numsSize; i++)
    {
        ZeroIndex[i] = -1;
        StartIndex[i] = -1;
    }
    //search for zero
    for(int i=0; i<numsSize; i++)
    {
        if(TempStart == -1)
        {
            StartIndex[Zerocount] = i;
            TempStart =0;
        }
        if(nums[i]==0)
        {
            ZeroIndex[Zerocount] = i;
            //printf("Start=%d, End=%d\n",StartIndex[Zerocount],ZeroIndex[Zerocount]);
            Zerocount++;
            TempStart = -1;
        }
    }
    for(int i=0; i<Zerocount && CanJump==1; i++)
    {
        if(BiggestStep > ZeroIndex[i])
        {
            //Already over the zero window
            continue;
        }
        CanJump = checkOverZero(nums, numsSize, StartIndex[i],ZeroIndex[i], &BiggestStep);
        if(CanJump == 2)
        {
            //Find the Answer
            CanJump = 1;
            break;
        }
    }
    //printf("Next\n");
    return CanJump;
}
