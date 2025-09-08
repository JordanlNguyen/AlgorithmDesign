#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

void insertionSort(vector<int>& a, int n){
    for (int i = 0; i < n; i++){
        for(int j = i-1; j >= 0; j--){
            if(a[j] > a[j+1]){
                //swap numbers
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
            else{break;}
        }
    }
}

void merge(vector<int>& a, int left, int mid, int right){
    int a1 = mid - left + 1;
    int a2 = right - mid;

    vector<int> L(a1); vector<int> R(a2);
    for(int i = 0; i < a1; i++){
        L[i] = a[left + i];
    }
    for(int i = 0; i < a2; i++){
        R[i] = a[mid + 1 + i];
    }

    int i = 0; int j = 0; int k = left;

    while(i < a1 && j < a2){
        if(L[i] <= R[j]){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < a1){
        a[k] = L[i];
        i++;
        k++;
    }

    while(j < a2){

        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& a, int left, int right){
    if(left >= right){return;}
    int mid = left + (right - left) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
}

int partition(vector<int>& a, int low, int high){
    int pivot = a[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++){
        if(a[j] < pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[high]);
    return i + 1;
}

void quickSort(vector<int>& a, int low, int high){
    if(low < high){
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main(){

    bool doSorted = true;

    int arraySize;
    cout << "enter array size: ";
    cin >> arraySize;

    vector<int> array;
    
    if(doSorted){
        for(int i = 0; i < arraySize; i++){
            array.push_back(i);
        }
    }
    else{
        for(int i = 0; i < arraySize; i++){
            array.push_back(rand());
        }
    }

    int size = array.size();

    // cout<<"unsorted array: ";
    // for(int i=0; i < size; i++){
    //     cout<<array[i]<<" ";
    // }
    // cout<<'\n'<<endl;

    //insertion sort
    vector<int> insersionSortedArray = array;
    clock_t start = clock();
    insertionSort(insersionSortedArray,size);
    clock_t end = clock();
    cout<<"inersion sorted array: \n";
    // for(int i=0; i < size; i++){
    //     cout<<insersionSortedArray[i]<<" ";
    // }
    double time = double(end - start)/CLOCKS_PER_SEC;
    cout<<"execution time: "<< time << " seconds" <<endl;;
    cout<<'\n'<<endl;


    //merge sort
    vector<int> mergeSortedArray = array;
    start = clock();
    mergeSort(mergeSortedArray, 0, array.size()-1);
    end = clock();
    cout<<"merge sorted array: \n";
    // for(int i=0; i < size; i++){
    //     cout<<mergeSortedArray[i]<<" ";
    // }
     time = double(end - start)/CLOCKS_PER_SEC;
    cout<<"execution time: "<< time << " seconds" << endl;;
    cout<<'\n'<<endl;


    //merge sort
    vector<int> quickSortedArray = array;
    start = clock();
    quickSort(quickSortedArray, 0, size - 1);
    end = clock();
    cout<<"quick sorted array: \n";
    // for(int i = 0; i < size; i++){
    //     cout<<quickSortedArray[i]<<" ";
    // }
     time = double(end - start)/CLOCKS_PER_SEC;
    cout<<"execution time: "<< time << " seconds" <<endl;;
    cout<<'\n'<<endl;
    return 0;
}