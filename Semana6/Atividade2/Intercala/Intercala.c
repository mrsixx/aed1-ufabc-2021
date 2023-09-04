#include <stdio.h>
#include <stdlib.h>

int *intercala(int*,int, int*,int);
int main()
{
    int m,n;
    int *vm, *vn, *vr;
    scanf("%d %d", &m, &n);

    vm = (int*)malloc(sizeof(int)*m);
    vn = (int*)malloc(sizeof(int)*n);

    for(int i = 0; i < m; i++)
        scanf("%d", &vm[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &vn[i]);
    //intercalo
    vr = intercala(vm, m, vn, n);
    //
    for(int i = 0; i < m+n; i++)
        printf("%d\n", vr[i]);

    free(vm);
    free(vn);
    free(vr);
    return 0;
}


int *intercala(int *v1,int n1, int *v2,int n2)
{
    int n = n1+n2, k, i, j;

    int *res = (int*)malloc(sizeof(int)*n);
    for(k = 0, i = 0, j = 0; i < n1 && j < n2; k++)
    {
        if(v1[i] < v2[j])
        {
            res[k] = v1[i];
            i++;
        }
        else
        {
            res[k] = v2[j];
            j++;
        }
    }
    for(;i<n1; k++, i++)
    {
        res[k] = v1[i];
    }
    for(;j<n2; k++, j++)
    {
        res[k] = v2[j];
    }


    return res;
}