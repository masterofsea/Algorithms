#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define RANGE 100000
#define Q 3.0f
#define SPACE printf("\n\n")


void booblesort(int* rawarr, int size);
void selectionsort(int* rawarr, int size);
void shellsort(int* rawarr, int size);
void radixsort(int* rawarr, int size);


int main(char* argv, int argc){ 
    int arr[SIZE];
    for(int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % RANGE;
        printf("%d ", arr[i]);
    }
    SPACE;
    selectionsort(arr, SIZE);
    for(int i = 0; i < SIZE; ++i) {        
        printf("%d ", arr[i]);
    }

    return 0;
}

void timetest(){
    clock_t t;
    srand(time(NULL));
    int arr[SIZE];

    double avgTimeSh = 0;
    double avgTimeB = 0;
    double avgTimeSel = 0;
    printf("Quantity of elements: %d\nRange of elements: [0,%d]\nQuantity of iterations: %d\n", SIZE, RANGE, (int)Q);

    for(int k = 0; k < (int)Q; ++k){
        for(register int i = 0; i < SIZE; ++i){
            *(arr + i) = rand() % RANGE;            
        }        
    
        t = clock();
        shellsort(arr, SIZE);         
        t = clock() - t;
        
        avgTimeSh += ((double)t/CLOCKS_PER_SEC)/Q;
       
     
        for(register int i = 0; i < SIZE; ++i){
            *(arr + i) = rand() % RANGE;            
        }   

        t = clock();         
        booblesort(arr, SIZE);
        t = clock() - t;
        avgTimeB += ((double)t/CLOCKS_PER_SEC)/Q;

        for(register int i = 0; i < SIZE; ++i){
            *(arr + i) = rand() % RANGE;            
        } 

        t = clock();         
        selectionsort(arr, SIZE);
        t = clock() - t;
        avgTimeSel += ((double)t/CLOCKS_PER_SEC)/Q;        
    }
    
    printf("Average time of shellsort: %0.2fms\n", avgTimeSh * 1000.0);
    printf("Average time of booblesort: %0.2fms\n", avgTimeB * 1000.0);
    printf("Average time of selectionsort: %0.2fms\n", avgTimeSel * 1000.0);
}