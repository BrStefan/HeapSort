#include<cstdio>
#include<algorithm>
using namespace std;
int v[100],n;
void heapify(int v[], int n, int i)
{
    int maxim = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && v[l] > v[maxim])maxim = l;
    if (r < n && v[r] > v[maxim])maxim = r;
    if (maxim != i)
    {
        swap(v[i], v[maxim]);
        heapify(v, n, maxim);
    }
}
void heapSort(int v[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)heapify(v, n, i);
    for (int i=n-1; i>=0; i--)
    {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    heapSort(v, n);
    for(int i=0;i<n;i++)printf("%d ",v[i]);
}
