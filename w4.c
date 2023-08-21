# include <stdio.h>




int* returner(int *p){
    int x, *patrick, **per;
    x=1;
    patrick = &x;
    for (int a= 1; a<=*p; a++){
        *patrick = (*patrick) * a;
    }
    per = &patrick;
    return per;



}


int main(){
    int p, **pat;
    printf("enter:");
    scanf("%d", &p);
    pat = returner(&p);

    printf("%d", **pat);


    return 0;
}
