#include <stdio.h>

int solution(int n, int m)
{
    int count = 0;
    int atual = 0;
    int visitado = 0;

    while (visitado < n)
    {
        count++;
        visitado++;
        atual = (atual + m) % n;

        if (atual == 0)
            break;
    }

    return count;
}

int main()
{
    int n = 10;
    int m = 4;

    int res = solution(n, m);
    printf("res %d\n", res);

    return 0;
}
