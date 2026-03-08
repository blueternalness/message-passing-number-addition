#!/bin/bash
#SBATCH --job-name=p2_2
#SBATCH --time=01:00:00
#SBATCH --ntasks=4
#SBATCH --output=p2_2_result.out

make p2_2
srun ./p2_2