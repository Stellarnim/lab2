#include <stdio.h>
#include <stdlib.h>

void main(){
    int co, ro;

    printf("행렬의 행과 열 크기 입력\n");
    scanf("%d %d", &ro, &co);
    printf("행렬의 크기 : [%d][%d]\n", ro, co);

    int **mat1, **mat2, **result;
    int x, y;

    result = (int **)malloc(ro * sizeof(int *));
    mat1 = (int **)malloc(ro * sizeof(int *));
    mat2 = (int **)malloc(ro * sizeof(int *));

    for (x = 0; x < ro; x++){
        mat1[x] = (int *)malloc(co * sizeof(int));
        mat2[x] = (int *)malloc(co * sizeof(int));
        result[x] = (int *)malloc(co * sizeof(int));
    }

    srand(0);
    printf("\n");
    printf("행렬 1\n");
    for (x = 0; x < ro; x++){
        for (y = 0; y < co; y++){
            mat1[x][y] = rand() % 10;
            printf("%d ", mat1[x][y]);
        }
        printf("\n");
    }

    printf("\n");
    printf("행렬 2\n");
    for (x = 0; x < ro; x++){
        for (y = 0; y < co; y++){
            mat2[x][y] = rand() % 10;
            printf("%d ", mat2[x][y]);
        }
        printf("\n");
    }

    printf("\n");
    printf("행렬 1 + 행렬 2\n");
    for (x = 0; x < ro; x++){
        for (y = 0; y < co; y++){
            result[x][y] = mat1[x][y] + mat2[x][y];
            printf("%d ", result[x][y]);
        }
        printf("\n");
    }

    for (x = 0; x < ro; x++){
        free(mat1[x]);
        free(mat2[x]);
        free(result[x]);
    }

    free(mat1);
    free(mat2);
    free(result);
}