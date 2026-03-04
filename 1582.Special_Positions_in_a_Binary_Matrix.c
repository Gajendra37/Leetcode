/*
Description:

Given an m x n binary matrix mat, return the number of special positions in mat.
A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

Example 1:
Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
Output: 1
Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
  
Example 2:
Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
Explanation: (0, 0), (1, 1) and (2, 2) are special positions.
*/

//Solution:

int row(int r,int c,int size,int **mat)
{
    int rc=0;
    for(int i=0;i<size;i++)
    {
        if(mat[r][i]==1)
            rc++;
    }
    return rc;
}

int col(int r,int c,int size,int **mat)
{
    int cc=0;
    for(int i=0;i<size;i++)
    {
        if(mat[i][c]==1)
            cc++;
    }
    return cc;
}

int numSpecial(int** mat, int matSize, int* matColSize) {
    
    int count=0;
    for(int i=0;i<matSize;i++)
    {
        int rc=0,cc=0;
        for(int j=0;j<matColSize[i];j++)
        {
            if(mat[i][j]==1)
            {
                rc=row(i,j,matColSize[i],mat);
                cc=col(i,j,matSize,mat);
            }
        }
        if(rc==1 && cc==1)
            count++;
    }
    return count;

}
