#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int rank, size, Msg;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        Msg = 451;
        printf("Process 0: Initially Msg = %d\n", Msg);
        MPI_Send(&Msg, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(&Msg, 1, MPI_INT, 3, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 0: Received Msg = %d. Done!\n", Msg);
    } else {
        MPI_Recv(&Msg, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        
        Msg += 1;
        printf("Process %d: Msg = %d\n", rank, Msg);
        
        int dest = (rank + 1) % size;
        MPI_Send(&Msg, 1, MPI_INT, dest, 0, MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}
