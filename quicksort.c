#include <stdio.h>
#include <stdlib.h>

void quicksort(int vector[], int left, int right);

int partition(int vector[],int left,int right);

int main(){

    int n = 10;
    int vector[10] = {27,56,31,10,53,46,12,6,2,93};

    printf("Before:\nvector[10] = "); 
    for(int i = 0; i<n; i++){
        printf("%d ", vector[i]);
    }

    quicksort(vector, 0, n-1);

    printf("\nAfter:\nvector[10] = ");
    for(int i = 0; i<n; i++){
        printf("%d ", vector[i]);
    }
    
    return 0;
}

void quicksort(int vector[], int left, int right){
    if(left < right){
        int pivot = partition(vector, left, right);
        quicksort(vector, left, pivot);
        quicksort(vector, pivot + 1, right);
    }
}

int partition(int vector[],int left,int right){
    int i = left;
    int j = right;
    int pivot = vector[(left+right)/2];

    while(i <= j){
        while(vector[i] < pivot)
            i++;
        while(vector[j] > pivot)
            j--;
        
        if(i<j){
            int aux;
            aux = vector[i];
            vector[i] = vector[j];
            vector[j] = aux;
            i++;
            j--;
        }
        else
            break;
    }
    return j;
}