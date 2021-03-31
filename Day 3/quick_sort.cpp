#include<bits/stdc++.h>
#define ll long long
using namespace std;
int MOD = 1e9 + 7;

void quick_sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int t;
    cout << "Enter number of test cases : ";
    cin >> t;
    while(t--) {
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    cout << "Enter " << n << " elements : ";

    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    quick_sort(arr, 0, n-1);

    cout << "Sorted Array\n";
    for(int i=0; i<n; i++)
        cout << arr[i] << ' ';
    
        cout << '\n';
    }
}

void quick_sort(int arr[], int low, int high)
{
    if(low < high)
    {
       int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j=low; j<=high-1; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[i+1], &arr[high]);

    return (i+1);

}
