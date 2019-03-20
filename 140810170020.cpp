/*
     Nama : Mohamad Achun Armando
     NPM  : 140810170020
*/
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if (l < r){
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size){
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    cout<<endl;
}

void masukanData(int (&arr)[100], int& n){
     cout << "Masukan banyak data : "; cin >> n;
     cout << "Masukan data cth[1 2 3 4 5] : ";
     for(int i = 0; i < n; i++){
          cin >> arr[i];
     }
}

int main(){
     int arr[100];
     int n;
     masukanData(arr,n);
     printArray(arr, n);
     auto start =  high_resolution_clock::now();
     mergeSort(arr, 0, n - 1);
     auto stop = high_resolution_clock::now();
     auto duration = duration_cast<microseconds>(stop-start);
     cout << "\nHasil Array yang diSort :\n";
     printArray(arr, n);
     cout << "Runtime merge sort function : " << duration.count() << " microseconds" << endl;
     return 0;
}
