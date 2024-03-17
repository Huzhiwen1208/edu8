#include <stdio.h>
int main()
{
    int ar[100] = {0};
    int k;
    int i;
    scanf("%d", &k);
    printf("%d", ar[k - 1]);
    for (int i = 0; i < 100; i++)
    {
        printf("%d ", ar[i]);
    }

    return 0;
}