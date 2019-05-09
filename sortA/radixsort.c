int max(int* arr, int size){
    int max = arr[0], length = 0;
    //select max
    for(int i = 1; i < size; ++i){
        if(arr[i] > max) max = arr[i];
    }

    return max;
}
void countSort(int* arr, int size, int exp){
    int count[10] = {0};
    int lsd, index, i;
    int result[size];
    for(i = 0; i < size; ++i){
        lsd = (arr[i] / exp) % 10;
        count[lsd] = count[lsd]++;
    }
    for(i = 1; i < size; ++i){
        count[i] += count[i - 1];
    }
    for(i = size - 1; i >= 0; --i){
        lsd = (arr[i] / exp) % 10;
        index = count[lsd] - 1;
        result[index] =  arr[i];
    }
    for(i = 0; i < size; ++i){
        arr[i] = result[i];
    }

}

void radixsort(int* rawarr, int size){
    int maximum = max(rawarr, size);
    
    for(int i = 1; maximum / i > 0; i *= 10) {
        countSort(rawarr, size, i);
    }
}
