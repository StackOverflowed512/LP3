
#include<bits/stdc++.h>
using namespace std;

// Partition function
int partition(vector<int>&a, int low, int high){
    int pivot = a[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(a[j] < pivot){
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i+1], a[high]);
    return i+1;
}

// Normal Quick Sort
void quickSort(vector<int>&a, int low, int high){
    if(low < high){
        int p = partition(a, low, high);

        quickSort(a, low, p-1);
        quickSort(a, p+1, high);
    }
}

// Random Partition
int randomPartition(vector<int>&a, int low, int high){
    int randomIndex = low + rand() % (high - low + 1);

    swap(a[randomIndex], a[high]);

    return partition(a, low, high);
}

// Randomized Quick Sort
void randomQuickSort(vector<int>&a, int low, int high){
    if(low < high){
        int p = randomPartition(a, low, high);

        randomQuickSort(a, low, p-1);
        randomQuickSort(a, p+1, high);
    }
}

// Main function
int main(){
    srand(time(0));

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> b = a;
    quickSort(b, 0, n-1);

    cout << "\nSorted array using Quick Sort: ";
    for(int x : b){
        cout << x << " ";
    }

    vector<int> c = a;
    randomQuickSort(c, 0, n-1);

    cout << "\nSorted array using Randomized Quick Sort: ";
    for(int x : c){
        cout << x << " ";
    }

    return 0;
}
