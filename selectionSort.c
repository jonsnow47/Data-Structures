//Selection sort

void selectionSort(int *a, int n){
    int i, maxi, t;

    for(i = n; i>1; i = i-1) {
        maxi = findIndexOfMax(a, i);
        //t = a[maxi]; a[maxi] = a[n-1]; a[n-1] = t;
        swap(&a[maxi], &a[i-1]); //swaps them both
    
    }
}

void selectionSort2(int *a, int n){
    for(int * current = a + n -1; current!=a; current = current -1) {
        swap( findAddressOfMax(a,current), current); //swap( a+maxi, a+i-1)
    }
}


void insertionSort(){
    //2 lists
}


int findIndexOfMax(int *a, int n){
    int maxi; //Largest element's address
    int i;
    if(n < 1) {
        return -1;
    }

    maxi = 0; 
    for(i=1; i<n, i++) {
        if (a[i] > a[maxi]){
            maxi = i;
        }
    }

    return maxi;

}

int main(int argc, char **argv){
    int *a;
    int n = 10;
    int maxIndex;
    int p, q;
    NodeAddress list;

    srand(time(NULL));

    a = generateArray(n)
    list = linkedListfromArray
    

    p = 5;
    q = 10;
    swap(&p, &q)
    printf("%d\n", p);
}
    
    
int findAddressOfMax(int *a, int n){
    int* amax = NULL;
    if(n>=1) {
        amax = a;
        for (int i = 1; i < n; i++){
            if (*(a+i) > *(a + amax)){
                amax = i;
            }
        }

    }
    return amax;
}



void swap(int *x, int *y){
    int t;
    t = *x;
    *x = *y
    *y = t;
}
