#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(void) {
    int rank, size;
    int array[64];
    int local_array[16];
    int partial_sum = 0;
    int gathered_sums[4];

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

    MPI_Scatter(array, 16, MPI_INT, local_array, 16, MPI_INT, 0, MPI_COMM_WORLD);
    for (int i = 0; i < 16; i++) {
        partial_sum += local_array[i];
    }
    MPI_Gather(&partial_sum, 1, MPI_INT, gathered_sums, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        int total_sum = 0;
        for (int i = 0; i < 4; i++) {
            total_sum += gathered_sums[i];
        }
        printf("Problem 2_3 Total Sum: %d\n", total_sum);
    }
    MPI_Finalize();
    return 0;
}