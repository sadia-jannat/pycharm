#include<bits/stdc++.h>
#define M 16
using namespace std;
int ld[30] = { 0 },rd[30] = { 0 },cl[30] = { 0 },N;
void printSolution(int board[M][M])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}
bool solveNQUtil(int board[M][M], int col)
{
    if (col >= N)
        return true;
    for (int i = 0; i < N; i++)
    {
        if ((ld[i - col + N - 1] != 1 &&rd[i + col] != 1) && cl[i] != 1)
        {
            board[i][col] = 1;
            ld[i - col + N - 1] =rd[i + col] = cl[i] = 1;
            if (solveNQUtil(board, col + 1))
                return true;
            board[i][col] = 0;
            ld[i - col + N - 1] =rd[i + col] = cl[i] = 0;
        }
    }
    return false;
}
bool solveNQ()
{
    int board[M][M];
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
            cin>>board[i][j];
    }
    if (solveNQUtil(board, 0) == false)
    {
        printf("Solution does not exist");
        return false;
    }

    printSolution(board);
    return true;
}
int main()
{
    cout<<"Input board size : ";
    cin>>N;
    solveNQ();
    return 0;
}

