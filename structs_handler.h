#ifndef STRUCTS_HANDLER_H
#define STRUCTS_HANDLER_H
#include "list.h"
#define MAX_MSG_SIZE 1024
#define MAX_QUEUE_NAME 50
struct request{ 
    int         op;
	char 	v1[MAX_VALUE_LENGTH]; // MAx Value = 256
	int 	key;
	int 	N;
	double	v2[MAX_N]; // Max N = 32
    char        queue[MAX_QUEUE_NAME];
};

struct response{ 
    int         op;
	char 	v1[MAX_VALUE_LENGTH];
	int 	key;
	int 	N;
	double	v2[MAX_N];
    char        queue[MAX_QUEUE_NAME];
	int error;
};

#endif