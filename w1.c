
# include <stdio.h>
# include <stdlib.h>

void reverse(int array[], int n){
    int *p1, *p2;
    p1 = array;
    p2 = &array[n-1];
    for (int a = 0; a< n, a++){
        array[a] = p2;
        array[n-a-1] = p1;
        p2--;
        p1++;

    }
    return 0;




}


void stalker(int array[], int len){
    int *pwalk, *plast;
        pwalk = array;

        plast = &array[len];

        int stat_first;
        stat_first = *pwalk;
        int index1, index2;
        index1= 0;
        index2 = 0;
        int stat_last = 0;
        int c =0;
        while(1){
                 if (pwalk == plast){
                    if(c==0){
                        printf("no profit");
                    }
                    return;
                }

                if (*pwalk < *(pwalk+1)){
                    stat_last = *(pwalk+1);
                    index2++;
                    c = 1;
                    pwalk++;
                    continue;
                }

                else{
                    if (c == 0){
                        pwalk++;
                        continue;
                    }
                    printf("\n%d -> %d", index1, index2);
                    stat_first = *(pwalk+1);
                    index1 = index2+1;
                    index2 = index1;
                    stat_last = 0;
                }

                pwalk++;
        }


}

int main(){
    int *p, n;
    printf("enter cases:");
    scanf("%d", &n);
    for (int a = 0; a<n ; a++){
        int len;
        printf("Enter array length:");
        scanf("%d", &len);
        int array[len+1];
        int n;
        for (int a1 = 0; a1<len; a1++){
            scanf("%d", &n);
            array[a1] = n;
        }
        array[len] = -1;
        stalker(array, len);
    }

    return 0;
}
