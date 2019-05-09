void swap(int* first, int* second){
    *first ^= *second;
    *second ^= *first;
    *first ^= *second;
}
void booblesort(int* rawarr, int size){      

    for(register int i = 0; i < size; ++i){
        for(register int j = 0; j < (size - i); ++j){
            if (*(rawarr + j) > *(rawarr + j + 1)){
                swap((rawarr + j), (rawarr + j + 1));
            }
        }
    }    
}
