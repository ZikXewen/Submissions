/* Space optimized C++ implementation of LCS problem */
#include<bits/stdc++.h>
using namespace std;
 
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs(string &X, string &Y)
{
    // Find lengths of two strings
    int m = X.length(), n = Y.length();
 
    int L[2][n+1];
 
    // Binary index, used to index current row and
    // previous row.
    bool bi;
 
    for (int i=0; i<=m; i++)
    {
        // Compute current binary index
        bi = i&1;
 
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                L[bi][j] = 0;
 
            else if (X[i] == Y[j-1])
                L[bi][j] = L[1-bi][j-1] + 1;
 
            else
                L[bi][j] = max(L[1-bi][j], L[bi][j-1]);
        }
    }
 
    /* Last filled entry contains length of LCS
       for X[0..n-1] and Y[0..m-1] */
    return L[bi][n];
}
 
/* Driver program to test above function */
int main()
{
    string X = "AGGTAB";
    string Y = "AXTXAYB";
 
    printf("Length of LCS is %d\n", lcs(X, Y));
 
    return 0;
}

