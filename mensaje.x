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
		int init_rpc() = 0;
		int set_value_rpc(struct request peticion) = 1;
		struct response get_value_rpc(int key) = 2;
		int modify_value_rpc(struct request peticion) = 3;
		int delete_key_rpc(int key) = 4;
		int exist_rpc(int key) = 5;
	} = 1;
} = 99;