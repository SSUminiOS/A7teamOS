#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "basic_include.h"


void schedular(unsigned char *memory ,Paging_return result) {

    round_robin(result.processes, result.process_count, TIME_QUANTUM, &result.queue, memory);

    print_process_info(result.processes, result.process_count);

    for (int i = 0; i < result.process_count; i++) {
        free_process(result.processes[i]);
    }
    free(result.processes);

   
}
