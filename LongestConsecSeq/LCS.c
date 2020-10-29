int cmp( const void *a , const void *b ) 
{ 
//這兩種方式都是可以的
//return *(int *)a > *(int *)b;//當a>b成立，返回true，否則返回false
return *(int *)a - *(int *)b; 
}

int longestConsecutive(int* nums, int numsSize){
    //exception handler
    if(numsSize ==0)
    {
        return 0;
    }
    else if(numsSize == 1)
    {
        return 1;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int AnsSize =0;
    int Start = -1, End=-1;
    int AnsStart, AnsEnd;
    int repeatCount =0;
    
    for(int i=0; i+1<numsSize; i++)
    {
        //printf("%d ", nums[i]);
        if(Start==-1)
        {
            Start = i;
            //printf("Start = %d", Start);
        }
        if(nums[i] == nums[i+1] && i+1 != numsSize-1)
        {
            repeatCount++;
            continue;
        }
        else if(nums[i]+1 == nums[i+1])
        {
            //consecutive
            End = i+1;
            //printf("End = %d", End);
            if(i+1 == numsSize-1)
            {
                //last Entry
                if((End - Start+1-repeatCount) > AnsSize)
                {
                    AnsSize = End-Start+1-repeatCount;
                }
            }
        }
        else
        {
            End = i;
            if((End - Start+1-repeatCount) > AnsSize)
            {
                AnsStart = Start;
                AnsEnd = End;
                AnsSize = End-Start+1-repeatCount;
            }
            
            End = -1;
            Start = -1;
            repeatCount =0;
        }
    }
    if(AnsSize)
    {
        return AnsSize;
    }
    else
    {
        return 1;
    }
}
