#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void man() {
	printf("\npush <N> - to push N to stack\n");
	printf("pop- to pop from stack\n");
	printf("empty - to check if stack is empty\n");
	printf("delete - delete stack\n");
	printf("help - to show this man\n");
	printf("exit - to finish execution of program\n");
}

int main() {
	stack* s = s_create();
	int value;
	char* cmd;
	cmd = (char*)malloc(sizeof(char) * 20);
	man();
	while(1) {
		scanf("%s", cmd);
		if (strcmp(cmd, "push") == 0) {
			scanf("%d", &value);
			s_push(s, value);
		}  else if (strcmp(cmd, "pop") == 0) {
			if (s_empty(s)) {
				printf("stack is empty\n");
				continue;
			}
			printf("%d", s_pop(s));
		} else if (strcmp(cmd, "print") == 0) {
			s_print(s);

		} else if (strcmp(cmd, "delete") == 0) {
			s_destroy(s);
		} else if (strcmp(cmd, "empty") == 0) {
			if (!s_empty(s)) {
				printf("not empty\n");
			} else {
				printf("empty\n");
			}
		} else if (strcmp(cmd, "help") == 0) {
			man();
		} else if (strcmp(cmd, "exit") == 0) {
			break;
		} else {
			printf("wrong comand, enter help to show man\n");
		}
	}
	free(cmd);
	s_destroy(s);
}