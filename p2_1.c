#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(void) {
    int rank, size;
    int array[64];
    int partial_sum = 0;
    int total_sum = 0;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    FILE *file = fopen("number.txt", "r");
    for (int i = 0; i < 64; i++) {
        fscanf(file, "%d", &array[i]);
    }
    fclose(file);

    int start_idx = rank * 16;
    int end_idx = start_idx + 16;
    for (int i = start_idx; i < end_idx; i++) {
        partial_sum += array[i];
    }

    if (rank != 0) {
        MPI_Send(&partial_sum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    } 
    else {
        total_sum = partial_sum;
        int received_sum;
        for (int i = 1; i < 4; i++) {
            MPI_Recv(&received_sum, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            total_sum += received_sum;
        }
        printf("Problem 2_1 Total Sum: %d\n", total_sum);
    }

    MPI_Finalize();
    return 0;
}