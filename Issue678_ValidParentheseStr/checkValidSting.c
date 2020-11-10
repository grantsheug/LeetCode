
bool checkValidString(char * s){
    int *LeftParStack;
    int *StarStack;
    int length = strlen(s);
    //printf("length = %d\n",length);
    LeftParStack = malloc(length*sizeof(int));
    StarStack = malloc(length*sizeof(int));
    int LeftStackPtr = 0;
    int StarStackPtr = 0;
    if(length == 0)
    {
        return true;
    }
    else
    {
        for(int i = 0; i < length; i++)
        {
            if(s[i] == '(')
            {
                // push to stack
                LeftParStack[LeftStackPtr++] = i;
                //printf("left = %d\n",LeftStackPtr);
            }
            else if(s[i] == '*')
            {
                StarStack[StarStackPtr++] = i;
                //printf("Start = %d\n",StarStackPtr);
            }
            else if(s[i] == ')')
            {
                if(LeftStackPtr ==0 && StarStackPtr==0)
                {
                    //printf("false,  %d %d\n",LeftStackPtr,StarStackPtr);
                    //both stack are empty
                    return false;
                }
                else if(LeftStackPtr)
                {
                    if(LeftParStack[LeftStackPtr] < i)
                    {
                        //printf("##, %d %d\n",LeftStackPtr,StarStackPtr);
                        LeftStackPtr--;
                    }
                    //printf("2,%d %d %d\n",LeftParStack[LeftStackPtr],LeftStackPtr,StarStackPtr);
                }
                else if(StarStackPtr)
                {
                    if(StarStack[StarStackPtr] < i)
                    {
                        //printf("###, %d %d\n",LeftStackPtr,StarStackPtr);
                        StarStackPtr--;
                    }
                    //printf("3,%d %d %d\n",StarStack[StarStackPtr],LeftStackPtr,StarStackPtr);
                }
            }
        }
        if(LeftStackPtr)
        {
            int LeftStackPtrBK = LeftStackPtr;
            for(int i=0; i < LeftStackPtrBK;i++)
            {
                int Idx = 0;
                while(Idx < StarStackPtr)
                {
                    if(LeftParStack[i] < StarStack[Idx])
                    {
                        StarStack[Idx] = -1;
                        LeftStackPtr --;
                        break;
                    }
                    Idx++;
                }
            }
        }
        //printf("%d %d\n\n",LeftStackPtr,StarStackPtr);
        if(LeftStackPtr == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
