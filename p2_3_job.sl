#!/bin/bash
#SBATCH --job-name=p2_3
#SBATCH --time=01:00:00
#SBATCH --ntasks=4
#SBATCH --output=p2_3_result.out

make p2_3
srun ./p2_3