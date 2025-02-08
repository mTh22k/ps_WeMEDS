#include <stdio.h>
#include <stdlib.h>

int solution(int a[], int n)
{

    for (int i = 0; i <= n; i++)
    {
        int cont = 0;

        for (int j = 0; j <= n; j++)
        {
            if (a[i] == a[j])
            {
                cont++;
            }
        }

        if (cont % 2 != 0)
        {
            return a[i];
        }
    }
}

int main()
{

    int vetor[7] = {9, 3, 9, 3, 9, 7, 9};

    int res = solution(vetor, 7);

    printf("res %d\n", res);
}