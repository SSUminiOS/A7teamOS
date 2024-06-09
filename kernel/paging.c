#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "basic_include.h"

Paging_return paging (unsigned char *memory) {
    Paging_return result;
    CircularQueue queue;
    initialize_queue(&queue);
    int process_count;
    Process** processes = initialize_processes(&process_count, &queue, memory);

    printf("\n");

    for (int i = 0; i < process_count; i++) {
        print_page_table(processes[i]);
        printf("\n");
    }

    // 큐의 내용을 출력
    print_queue(&queue);

    // 각 프로세스의 페이지 테이블 출력

    result.process_count = process_count;
    result.processes = processes;
    result.queue = queue;

    return result;
}

