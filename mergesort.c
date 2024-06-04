#include <stdio.h>
#include <stdlib.h>

void merge(int vector[], int begin, int mid, int end);

void mergeSort(int vector[], int begin, int end);

int main(){

    int n = 10;
    int vector[10] = {27,56,31,10,53,46,12,6,2,93};

    printf("Before:\nvector[10] = "); 
    for(int i = 0; i<n; i++){
        printf("%d ", vector[i]);
    }

    mergeSort(vector, 0, n-1);

    printf("\nAfter:\nvector[10] = ");
    for(int i = 0; i<n; i++){
        printf("%d ", vector[i]);
    }

    return 0;
}

void mergeSort(int vector[], int begin, int end){
    if(begin < end){
        int mid = (begin + end)/2;
        mergeSort(vector, begin, mid);
        mergeSort(vector, mid+1, end);
        merge(vector, begin, mid, end);
    }
}

void merge(int vector[], int begin, int mid, int end){
    int size_left = mid - begin + 1;
    int size_right = end - mid;
    int left[size_left];
    int right[size_right];
    int left_aux= 0;
    int right_aux = 0;

    for (int i = 0; i < size_left; i++)
        left[i] = vector[begin+i];
    
    for(int i = 0; i < size_right; i++)
        right[i] = vector[mid + 1 + i];

    for(int i = begin; i <= end; i++){
        if(left_aux < size_left){
            if(right_aux < size_right){
                if(left[left_aux] < right[right_aux])
                    vector[i] = left[left_aux++];
                else
                    vector[i] = right[right_aux++];
            }
            else
                vector[i] = left[left_aux++];
        }
        else
            vector[i] = right[right_aux++];        
    }
}
