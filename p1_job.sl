#!/bin/bash
#SBATCH --job-name=mpi_ring
#SBATCH --time=01:00:00
#SBATCH --ntasks=4
#SBATCH --output=p1_result.out

# Compile the program
make p1

# Run the MPI program
srun ./p1