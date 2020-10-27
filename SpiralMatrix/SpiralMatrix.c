/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){

    //printf("matrixsize = %d\n",matrixSize);
    //printf("matrixColSize = %d\n",*matrixColSize);

	int row = 0, col = 0;
	row = matrixSize;
    if(matrixSize && *matrixColSize==0)
    {
        *returnSize = 0;
        return NULL;
    }
    if(!matrixSize)
    {
        *returnSize = 0;
        matrixColSize =NULL;
	    return NULL;
    }
	col = *matrixColSize;
    *returnSize = col*row;

	long int Max= row*col+1;
    //printf("size = %d\n",Max);
    //printf("RowSize = %d\n",row);
    //printf("ColSize = %d\n",col);
	int *AnsMatrix;
	AnsMatrix = malloc((row*col)*sizeof(int));


	
	int AnsMatrixIdx = 0;
	int RowIdx=0, ColIdx=0;
	int ToggleBit=0;		//0 = right, 1 = down, 2 = left, 3 = up
	while(AnsMatrixIdx != *returnSize)
	{
		AnsMatrix[AnsMatrixIdx++] = matrix[RowIdx][ColIdx];
		matrix[RowIdx][ColIdx] = Max;
		if(ToggleBit ==0)	//right
		{
			//change direction check
			if((ColIdx+1 == col && (AnsMatrixIdx!= *returnSize)) || matrix[RowIdx][ColIdx+1] == Max)	//Boundary case
			{
				ToggleBit += 1;
				ToggleBit %= 4;	
                RowIdx+=1;
                //printf("change dir\n");
			}
			else
			{
				ColIdx+=1;
                //printf("move right\n");
			}
            
		}
		else if(ToggleBit ==1)	//down
		{
			//change direction check
			if((RowIdx+1 == row && (AnsMatrixIdx!= *returnSize)) || matrix[RowIdx+1][ColIdx] == Max)	//Boundary case
			{
				ToggleBit += 1;
				ToggleBit %= 4;	
                ColIdx-=1;
                //printf("change dir\n");
			}
			else
			{
				RowIdx+=1;
                //printf("move down\n");
			}
		}
		else if(ToggleBit ==2)	//left
		{
			//change direction check
			if((ColIdx-1 < 0 && (AnsMatrixIdx!= *returnSize)) || matrix[RowIdx][ColIdx-1] == Max)	//Boundary case
			{
				ToggleBit += 1;
				ToggleBit %= 4;
                RowIdx-=1;
                //printf("change dir\n");
			}
			else
			{
				ColIdx-=1;
                //printf("move left\n");
			}
		}
		else if(ToggleBit ==3)	//up
		{
			//change direction check
			if((RowIdx-1 < 0 && (AnsMatrixIdx!= *returnSize)) || matrix[RowIdx-1][ColIdx] == Max)	//Boundary case
			{
				ToggleBit += 1;
				ToggleBit %= 4;	
                ColIdx+=1;
                //printf("change dir\n");
			}
			else
			{
				RowIdx-=1;
                //printf("move up\n");
			}
		}
	}
    //*matrixColSize=col;
    //*returnSize = col*row;
	return AnsMatrix;
}
