#include <iostream>
#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> array, int n){
    vector<int> a = array;
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
    return a;
}

vector<int> mergeSort(vector<int> array, int n){
    vector<int> a = array;
}

int main(){
    vector<int> array = {1,5,2,7,4,2,8,3,8,2,8,4};
    int size = array.size();

    cout<<"unsorted array: ";
    for(int i=0; i < size; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;

    vector<int> insersionSortedArray = insertionSort(array,size);

    cout<<"inersion sorted array: ";
    for(int i=0; i < size; i++){
        cout<<insersionSortedArray[i]<<" ";
    }
    cout<<endl;
}