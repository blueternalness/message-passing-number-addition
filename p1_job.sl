#!/bin/bash
#SBATCH --job-name=mpi_ring
#SBATCH --time=01:00:00
#SBATCH --ntasks=4
#SBATCH --output=p1_result.out

make p1
srun ./p1