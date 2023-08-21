# include <stdio.h>
# include <stdlib.h>

void reverse(int array[], int n){
    int temp;
    for (int a = 0; a< n/2; a++){
        temp = array[a];
        array[a] = array[n-a-1];
        array[n-a-1] = temp;

    }


}


int main(){

int n;
printf("Enter n:");
scanf("%d", &n);
int array[n];

for (int a = 0; a<n ;a++){
    scanf("%d", &array[a]);
}

reverse(array, n);

for (int a = 0; a<n ;a++){
    printf("%d\n", array[a]);
}

return 0;
}
