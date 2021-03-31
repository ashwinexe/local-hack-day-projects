#include<bits/stdc++.h>
#define ll long long
using namespace std;

tuple <int,int> partition(int arr[], int low, int high)
{
    int i=low; //all elment left to this if smaller
    int j=low; //its the mid element that wee want to place at its position
    int k = high ; //all elemnt right to this is larger
    int pivot=arr[j];
    while (j<=k){
        if (arr[j]<pivot){
            swap(arr[i],arr[j]);
            i++;
            j++; 
        }
        else if(arr[j]>pivot){
            swap(arr[j],arr[k]);
            k--;
        }
        else{
            j++;
        }
    }
    return make_tuple(i,k);
}

void quick_sort(int arr[], int low, int high)
{
    if(low < high)
    {int left;
    int right;
    tie(left,right)  = partition(arr, low, high);//left to right all all same pivot element
    quick_sort(arr, low, left-1);
    quick_sort(arr, right+1, high);
    }
}
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
    cout << "\nUNsorted Array\n";
    for(auto i:arr)cout<<i<<" ";
    quick_sort(arr, 0, 9);
    cout << "Sorted Array\n";
    for(auto i:arr)cout<<i<<" ";
    }
}

