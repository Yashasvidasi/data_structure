# include <stdio.h>
# include <stdlib.h>


int miner(int ptr_array[], int n){
    int *walker, *end, *min;
    walker = ptr_array;
    min = walker;
    end = &ptr_array[n-1];
    while (1){

        if (*walker<=*min){
            min = walker;
        }
        if (walker == end){
            return min;
        }
    walker++;
    }



}





int main(){
    int n;
    printf("enter:");
    scanf("%d", &n);



    int *ptr_array = (int*) calloc(n, sizeof(int));
    for (int a = 0; a<n; a++){
        scanf("%d", &ptr_array[a]);
    }


    int *final;
    final = miner(ptr_array, n);

    //free(ptr_array);
    printf("%d", *final);



    return 0;
}



#include<stdio.h>
#include<stdlib.h>

void modify(int *valPtr)
{
    (*valPtr)++;
}

int *createArray(int size)
{
    int *arr = (int *)calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
    return arr;
}

void modifyPtrToPtr(int **ptr)
{
    int newValue = 420;
    *ptr = &newValue;
}


int main()
{
    //a) To Demonstrate passing pointers to a function.
    int val = 5;
    printf("Original Value = %d\n", val);
    modify(&val);
    printf("Modified value = %d\n", val);

    //b) Demonstrate Returning pointer from a function.
    int size = 5;
    int *array = createArray(size);
    printf("Array created using function:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    //c) Using pointer to pointer.

    int x = 69;
    int *ptr = &x;
    printf("Original value of x: %d\n", *ptr);
    modifyPtrToPtr(&ptr);
    printf("Modified value of x: %d\n", *ptr);

    return 0;
}
