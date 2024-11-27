#include <bits/stdc++.h>
using namespace std;
int Linear_search(int a[], int n, int x);
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x;
    cin >> x;
    int r = Linear_search(a, n, x);
    cout << r << endl;
    return 0;
}

int Linear_search(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            return i;
        }
    }
    return -1;
}
