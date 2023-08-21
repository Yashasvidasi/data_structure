# include <stdio.h>
# include <stdlib.h>


int main(){

    int row1, col1,row2, col2;

    printf("enter row 1: ");
    scanf("%d", &row1);
    printf("enter col 1: ");
    scanf("%d", &col1);
    printf("\nenter row 2: ");
    scanf("%d", &row2);
    printf("enter col 2: ");
    scanf("%d", &col2);

    int* mat1 = malloc((row1 * col1) * sizeof(int));
    int* mat2 = malloc((row2 * col2) * sizeof(int));
    int* mat3 = malloc((row2 * col1) * sizeof(int));

    if (col1 != row2){
        printf("not possible");
        return 0;
    }

    printf("\n\nMatrix 1 enter: \n\n");

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++){
                printf("");
            scanf("%d", &mat1[i * col1 + j]);
        }
        printf("\n");
    }

    printf("Matrix 2 enter: \n\n");

    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++){
                printf("");
            scanf("%d", &mat2[i * col2 + j]);

        }
        printf("\n");
    }

    printf("Matrix 1: \n\n");

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++)
            printf("%d ", *(mat1+(i * col1 + j)));
        printf("\n");
    }

    printf("\n\nMatrix 2: \n\n");

    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++)
            printf("%d ", *(mat2+(i * col2 + j)));
        printf("\n");
    }
    int sum;
    for (int a1 = 0; a1< row1; a1++){
        for(int a2 = 0; a2<col2; a2++){
            sum = 0;

            for(int a3 = 0; a3<col1; a3++){
                sum = sum + (*(mat1+(a1*col1+a3)))*(*(mat2+(a3*col2+a2)));
            }
            mat3[a1*col1+ a2] = sum;
        }
    }


    printf("\n\nMultiplied matrix:\n\n");

    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col1; j++)
            printf("%d ", *(mat3+(i * col1 + j)));
        printf("\n");
    }

    return 0;
}
