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

    if (rank == 0) {
        FILE *file = fopen("number.txt", "r");
        for (int i = 0; i < 64; i++) {
            fscanf(file, "%d", &array[i]);
        }
        fclose(file);
    }
    MPI_Bcast(array, 64, MPI_INT, 0, MPI_COMM_WORLD);
    int start_idx = rank * 16;
    int end_idx = start_idx + 16;
    for (int i = start_idx; i < end_idx; i++) {
        partial_sum += array[i];
    }
    MPI_Reduce(&partial_sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Problem 2_2 Total Sum: %d\n", total_sum);
    }
    MPI_Finalize();
    return 0;
}