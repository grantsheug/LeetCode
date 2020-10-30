
int FindLargestLand(int** Sgrid, int x, int y, int GroupIdx)
{
    int Size = 0;
    int UpSize = 0, RightSize = 0, DownSize = 0, LeftSize = 0;
    if(Sgrid[x][y] == 0)
    {
        //printf("(%d,%d) Return 0\n",x,y);
        return 0;
    }
    else if(Sgrid[x][y] == 1)
    {
        Sgrid[x][y] = GroupIdx;
        //up direction
        UpSize = FindLargestLand(Sgrid, x-1, y, GroupIdx);
        //Right direction
        RightSize = FindLargestLand(Sgrid, x, y+1, GroupIdx);
        //Down direction
        DownSize = FindLargestLand(Sgrid, x+1, y, GroupIdx);
        //Left direction
        LeftSize = FindLargestLand(Sgrid, x, y-1, GroupIdx);
        //printf("(%d,%d) Return 1, size=%d\n",x,y,(1+UpSize+RightSize+DownSize+LeftSize));
        return (1+UpSize+RightSize+DownSize+LeftSize);
    }
    else
    {
        //printf("(%d,%d) Return 0\n",x,y);
        return 0;    
    }
}

int Check4DirToSum(int** Sgrid, int *Ans, int x, int y)
{
    int UpIdx=0, DownIdx=0, RightIdx=0, LeftIdx=0;
    UpIdx = Sgrid[x-1][y];
    DownIdx = Sgrid[x+1][y];
    RightIdx = Sgrid[x][y+1];
    LeftIdx = Sgrid[x][y-1];
    if(UpIdx == DownIdx)
    {
        DownIdx = 0;
    }
    if(UpIdx == RightIdx)
    {
        RightIdx = 0;
    }
    if(UpIdx == LeftIdx)
    {
        LeftIdx = 0;
    }
    if(DownIdx == RightIdx)
    {
        RightIdx = 0;
    }
    if(DownIdx == LeftIdx)
    {
        LeftIdx = 0;
    }
    if(RightIdx == LeftIdx)
    {
        RightIdx = 0;
    }
    return 1+Ans[UpIdx]+Ans[DownIdx]+Ans[RightIdx]+Ans[LeftIdx];
}

int largestIsland(int** grid, int gridSize, int* gridColSize){
    //Boundary check
    if(gridSize==0)
    {
        return NULL;
    }

    int **SearchGrid;
    int SGridRow = gridSize+2, SGridCol = (*gridColSize)+2;
    //int Ans = 0;
    //printf("gridSize = %d , gridColSize = %d\n", SGridRow, SGridCol);
    //claim a array which size is (gridSize+1) * (gridColSize+1)
    SearchGrid = malloc((SGridRow*SGridCol) * sizeof(int));

    
    //SearchGrid
    for(int RowSize = 0; RowSize < SGridRow; RowSize++)
    {
        SearchGrid[RowSize] = malloc(SGridCol * sizeof(int));
    }
    /*for(int RowSize = 0; RowSize < SGridRow; RowSize++)
    {
        printf("&grid = %d , Grid[] = %d\n", &SearchGrid[RowSize], SearchGrid[RowSize]);
    }*/
    //Initial A Grid which fill all 0s to boundary
    for(int RowSize=0; RowSize < gridSize; RowSize++)
    {
        for(int ColSize=0; ColSize < (*gridColSize); ColSize++)
        {
            SearchGrid[RowSize+1][ColSize+1] = grid[RowSize][ColSize];
        }
    }
    
    for(int RowSize=0; RowSize < SGridRow; RowSize++)
    {
        for(int ColSize=0; ColSize < SGridCol; ColSize++)
        {
            if(RowSize ==0 || RowSize == SGridRow-1 || ColSize ==0 || ColSize == SGridCol-1)
                SearchGrid[RowSize][ColSize] = 0;
        }
    }
    
    /*for(int RowSize=0; RowSize < SGridRow; RowSize++)
    {
        for(int ColSize=0; ColSize < SGridCol; ColSize++)
        {
            printf("SGrid[%d][%d] = %d\n", RowSize, ColSize, SearchGrid[RowSize][ColSize]);
        }
    }*/
    
    //Finish Initialize
    
    //Start Recursive
    int *Ans = malloc((SGridRow*SGridCol)/2*sizeof(int));
    for(int i=0; i<(SGridRow*SGridCol)/2;i++)
    {
        Ans[i] = 0;
    }
    int GroupIdx = 2;
    for(int RowIdx=0; RowIdx< SGridRow; RowIdx++)
    {
        for(int ColIdx=0; ColIdx < SGridCol; ColIdx++)
        {
            if(SearchGrid[RowIdx][ColIdx] == 1)
            {
                Ans[GroupIdx] = FindLargestLand(SearchGrid,RowIdx,ColIdx,GroupIdx); 
                GroupIdx++;
            }
        }
    }
    /*for(int i=0; i<gridSize*SGridCol;i++)
    {
        if(Ans[i]!=0)
            printf("GroupIdx = %d, Ans = %d\n", i, Ans[i]);
    }*/

    int FinalAns = 0;
    if(Ans[2])
        FinalAns = Ans[2];
    int TempAns = 0;
    for(int RowIdx=0; RowIdx < SGridRow; RowIdx++)
    {
        for(int ColIdx=0; ColIdx < SGridCol; ColIdx++)
        {
            if(SearchGrid[RowIdx][ColIdx] == 0 && !(RowIdx ==0 || RowIdx == SGridRow-1 || ColIdx ==0 || ColIdx == SGridCol-1))
            {
                TempAns = Check4DirToSum(SearchGrid,Ans,RowIdx,ColIdx);
                if(TempAns > FinalAns)
                {
                    FinalAns = TempAns;
                }
            }
        }
    }
    free(SearchGrid);
    return FinalAns;
}
