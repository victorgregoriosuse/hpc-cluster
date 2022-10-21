#include <mpi.h>
#include <stdio.h>

// https://github.com/mpitutorial/mpitutorial

int main(int argc, char** argv) {
    // init
    MPI_Init(NULL, NULL);

    // num processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // mpi rank
    int mpi_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &mpi_rank);

    // proc name
    char proc_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(proc_name, &name_len);

    // print
    printf("name:%s rank:%d out of %d processors\n", proc_name, mpi_rank, world_size);
    
    // finalize
    MPI_Finalize();
}
