int getMaxLen(int* nums, int numsSize){
    long int i;
    long int MaxLength = 0;
    long int End = 0;
    long int Start = 0;
    long int j;
    long int NegativeNum = 0;
    long int FirstNega = -1;
    long int LastNega = -1;
    if(numsSize ==1)
    {
        if(nums[0]>0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    for(i =0; i<numsSize;i++)
    {
        End = i;
        if(nums[i] <0)
        {
            if(FirstNega == -1)
            {
                FirstNega = i;
            }
            LastNega = i;
            NegativeNum++;
        }
        if(nums[i]==0 || i==numsSize-1)
        {
            //setup check boundary
            if(nums[i]==0)
            {
                if(End != Start)
                {
                    End = i-1;
                }
            }  
            else if(i==numsSize-1)
            {
                End = numsSize-1;
            }
                
            long int TempAns = 0;
            while(End != Start)
            {
                if(NegativeNum %2 == 0)
                {
                    //printf("End = %d, Start=%d\n",End,Start);
                    TempAns = End - Start+1;
                    if(TempAns>MaxLength)
                    {
                        MaxLength = TempAns;
                    }
                    break;
                }
                else
                {
                    //printf("End = %d, Start=%d\n",End,Start);
                    //printf("FirstNega = %d, LastNega=%d\n",FirstNega,LastNega);
                    if((End-FirstNega+1) > (LastNega-Start+1))
                    {
                        TempAns = (End-(FirstNega+1)+1);
                    }
                    else
                    {
                        TempAns = ((LastNega-1)-Start+1);
                    }
                    
                    if(TempAns>MaxLength)
                    {
                        MaxLength = TempAns;
                    }
                    break;
                }
            }
            Start = i+1;
            NegativeNum = 0;
            FirstNega = -1;
            LastNega=-1;
        }
    }
    return MaxLength;
}
