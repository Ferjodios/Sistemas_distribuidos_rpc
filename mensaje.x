struct response{ 
	char 	v1<256>;
	int 	N;
	double	v2<32>;
	int error;
};

struct request{
	int 	key;
	char 	v1<256>;
	int 	N;
	double	v2<32>;
};

program LIST_SERVICE{
	version LIST_SERVICE_V1{
		int init() = 0;
		int set_value(struct request peticion) = 1;
		struct response get_value(int key) = 2;
		int modify_value(struct request peticion) = 3;
		int delete_key(int key) = 4;
		int exist(int key) = 5;
	} = 1;
} = 99;