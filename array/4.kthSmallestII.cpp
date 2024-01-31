
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r)
{
    int x = arr[r];
    int i = l;
    int j;
    for (j = l; j < r; j++)
    {
        if (arr[j] <= x)
        {
            swap(arr[j], arr[i]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}
int randomPartition(int arr[], int l, int r)
{
    int n = r - l + 1;
    int pivot = rand() % n;
    swap(arr[l + pivot], arr[r]);
    return partition(arr, l, r);
}
int kthSmallest(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int pos = randomPartition(arr, l, r);
        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1)
            return kthSmallest(arr, l, pos - 1, k);
        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }
    return 99999999;
}
void print(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int n = 0;

    cout << "Enter Size Of the Array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter elements of Array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    print(arr, n);
    cout << endl;
    cout << "Enter the value of k";
    int k;
    cin >> k;

    int l = 0;
    cout << "Enter left end";
    cin >> l;

    int r = n - 1;
    cout << "Enter right end";
    cin >> r;

    int kthSmallestnum = kthSmallest(arr, l, r, k);
    cout << kthSmallestnum << endl;

    return 0;
}