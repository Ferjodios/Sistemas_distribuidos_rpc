#ifndef STRUCTS_HANDLER_H
#define STRUCTS_HANDLER_H
#include "list.h"
#define MAX_MSG_SIZE 1024
#define MAX_QUEUE_NAME 50

struct response{ 
	char 	v1[256];
	int 	N;
	double	v2[32];
	int error;
};

struct request{
	int 	key;
	char 	v1[256];
	int 	N;
	double	v2[32];
};

#endif