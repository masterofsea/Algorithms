int increment(int* interval, int size){
    int multiplier1, multiplier2, multiplier3; 
    multiplier1 = multiplier2 = multiplier3 = 1;
    int counter = -1; 
    do{
        if(++counter % 2){
            multiplier2 *= 2;
            interval[counter] = 8 * multiplier1 - 6 * multiplier2 + 1;
        } else {
            interval[counter] = 9 * multiplier1 - 9 * multiplier3 + 1;
            multiplier3 *= 2;
        }
        multiplier1 *= 2;
    } while(3 * interval[counter] < size);
    return(counter > 0 ? --counter : 0);
}
void shellsort(int* rawarr, int size){
    int interval;
    int j;
    int interval_arr[50];
    int counter;
    counter = increment(interval_arr, size);

    while(counter >= 0){
        interval = interval_arr[counter--];
        for(int i = interval; i < size; ++i){
            int temp = rawarr[i];

            for(j = i - interval; (j >= 0) && (rawarr[j] > temp); j -= interval) rawarr[j + interval] = rawarr[j];
            rawarr[j + interval] = temp;
        }
    }    
}
