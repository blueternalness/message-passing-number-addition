#!/bin/bash
#SBATCH --job-name=p2_1
#SBATCH --time=01:00:00
#SBATCH --ntasks=4
#SBATCH --output=p2_1_result.out

make p2_1
srun ./p2_1