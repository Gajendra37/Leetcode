/*
Description:

Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

Example 1:
Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:
Input: grid = [[3,2],[1,0]]
Output: 0
*/

//Solution:

int countNegatives(int** grid, int gridSize, int* gridColSize) {
    
    int neg=0;
    for(int i=0;i<gridSize;i++)
    {
        for(int j=0;j<gridColSize[i];j++)
        {
            if(grid[i][j]<0)
                neg++;
        }
    }
    return neg;
}
