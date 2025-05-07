#include <stdio.h>
#include <string.h>

// Function to find the length of LCS
int lcs(char *X, char *Y)
{
    int m = strlen(X);
    int n = strlen(Y);
    int L[m + 1][n + 1];

    // Build the LCS table in bottom-up manner
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    // Optional: Print LCS string
    int index = L[m][n];
    char lcsStr[index + 1];
    lcsStr[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcsStr[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    printf("LCS: %s\n", lcsStr);
    return L[m][n];
}

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int length = lcs(X, Y);
    printf("Length of LCS: %d\n", length);
    return 0;
}
