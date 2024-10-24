#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(){
    // ---- input and malloc A, F ----
    int NA, NF;
    scanf("%d %d", &NA, &NF);
    int *A = malloc(sizeof(int) * NA);
    int *F = malloc(sizeof(int) * NF);

    for(int i = 0; i < NA; i++){
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < NF; i++){
        scanf("%d", &F[i]);
    }
    // ---- end input and malloc----

    // implement here
    // double tic, toc;
    int NANS = NA-NF+1;
    int *IF = malloc(sizeof(int) * NF);
    int *ANS = malloc(sizeof(int) * NANS);

    // tic = omp_get_wtime();

    for(int i = 0; i < NF; i++){
        IF[NF-1-i] = F[i];
    }

    for(int i = 0; i < NANS; i++){
        int ans = 0;
        int k = 0;
        int pnf = NF;

        for(int j = i; j < i+pnf; j++){
            int tem = A[j]*IF[k];
            ans += tem;
            k++;
        }
        ANS[i] = ans;
    }

    // toc = omp_get_wtime() - tic;

    for(int i = 0; i < NANS; i++){
        printf("%d\n", ANS[i]);
    }

    // printf("Time Taken: %g\n", toc);

    // ---- free memory ----
    free(F);
    free(A);
    free(IF);
    free(ANS);
    // ---- end free ----
    return 0;
}
