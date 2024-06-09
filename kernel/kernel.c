#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "basic_include.h"

void print_minios(char* str);

int main() {
    print_minios("[MiniOS SSU] Hello, World!");
    //메인 메모리 함수 넣기
    unsigned char memory[PHYSICAL_MEMORY_SIZE];

    char *input;
    Paging_return result;

    while(1) {
        // readline을 사용하여 입력 받기
        input = readline("커맨드를 입력하세요(종료:exit) : ");

        if (strcmp(input, "process") == 0) {
            result = paging(memory);
            schedular(memory,result);

        }

        else if (strcmp(input, "exit") == 0) {
           break;
        }

        else system(input);
    }

    // 메모리 해제
    free(input);
    print_minios("[MiniOS SSU] MiniOS Shutdown........");

    return 1;
}

void print_minios(char* str) {
    printf("%s\n", str);
}

