#include <stdio.h>
#include <stdlib.h>

int solution(int a[], int n)
{
    if (n == 0)
        return 0;

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int unico = 1;

        for (int j = 0; j < i; j++)
        {
            if (a[i] == a[j])
            {
                unico = 0;
                break;
            }
        }

        if (unico)
            count++;
    }

    return count;
}

int main()
{

    int vetor[6] = {2, 1, 1, 2, 3, 1};

    int res = solution(vetor, 6);

    printf("res %d\n", res);
}