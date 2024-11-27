#include<bits/stdc++.h>
using namespace std;
void Selection_Sort(int a[],int n);
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>n;
    }
    Selection_sort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
void Selection_Sort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        int index_min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[index_min])
                index_min=j;
        }
        if(index_min !=i)
        {
            int temp=a[i];
            a[i]=a[index_min];
            a[index_min]=temp;
        }
    }
}
