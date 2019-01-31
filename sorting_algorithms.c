
#include "sorting_algorithms.h"
static void Swap(int *i, int *j)
{
    int const tmp = *i;
    *i = *j;
    *j = tmp;
}

void bubbleSort(int *list,const int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
            if (list[j] > list[j + 1])
            {
                Swap(&list[j], &list[j + 1]);
            }
    }
}

void insertionSort(int *list, const int length)
{
    int i, key, j;
    for (i = 1; i < length; i++)
    {
        key = list[i];
        j = i - 1;
        while (j >= 0 && list[j] > key)
        {
            list[j + 1] = list[j];
            j = j - 1;
        }
        list[j + 1] = key;
    }
}

static void merge(int *list, int l,int m, int r){
    int i,j,k;
    int n1 = m-l+1;
    int n2 = r-m;

    int *L = (int*)malloc(sizeof(int)*n1);
    int *R = (int*)malloc(sizeof(int)*n2);

    for(int i = 0; i<n1;i++){
        L[i] = list[l+i];
    }

    for(int i = 0; i<n2;i++){
        R[i] = list[i+m+1];
    }

    i=0;
    j=0;
    k=0;
    while(i<n1 && j <n2){
        if(L[i]<= R[j]){
            list[k] = L[i];
            i++;
        }
        else{
            list[k] = L[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        list[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        list[k] = L[j];
        j++;
        k++;
    }
}

void mergeSort(int *list, int l, int r){
    if(l<r){
        int m = l+(r-l)/2;

        mergeSort(list,l,m);
        mergeSort(list,m+1,r);

        merge(list,l,m,r);
    }
}

static int partition(int *list, int low, int high){
    int pivot = list[high];

    int i = low;
    for(int j = low; j <= high-1; j++){
        if(list[j]< pivot){
            i++;
            Swap(&list[i],&list[j]);
        }
    }
    Swap(&list[i],&list[high]);
    return i;

}

void quickSort(int *list, int low, int high){
    if(low < high){
        int pi = partition(list,low,high);

        quickSort(list,low, pi-1);
        quickSort(list,pi+1, high);
    }
}

