#include <stdio.h>
#include <stdlib.h>

void shellsort(int vector[], int n);

int main(){

    int n = 10;
    int vector[10] = {27,56,31,10,53,46,12,6,2,93};

    printf("Before:\nvector[10] = "); 
    for(int i = 0; i<n; i++){
        printf("%d ", vector[i]);
    }

    shellsort(vector, n);

    printf("\nAfter:\nvector[10] = ");
    for(int i = 0; i<n; i++){
        printf("%d ", vector[i]);
    }
    
    return 0;
}

void shellsort(int vector[], int n){
    int jump = n/2;

    while(jump > 0){
        for(int i = jump; i < n; i++){
            int aux = vector[i];
            int j = i;
            while(j >= jump && vector[j-jump] > aux){
                vector[j] = vector[j-jump];
                j = j-jump;
            }
            vector[j] = aux;
        }
          jump = jump/2;
    }
}