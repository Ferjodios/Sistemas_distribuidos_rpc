struct response{ 
	char 	v1<256>;
	int 	N;
	double	v2<32>;
	int error;
};

program SERVER_FUNC{
	version SERVER_FUNC_VERSION{
		int init_rpc() = 1;
		int set_value_rpc(int key,  string value1<256>,  int value2,  double value3) = 2;
		struct response get_value_rpc(int key) = 3;
		int modify_value_rpc(int key, string value1<256>, int value2, double value3) = 4;
		int delete_key_rpc(int key) = 5;
		int exist_rpc(int key) = 6;
		int copy_key_rpc(int key1, int key2) = 7;
	} = 1;
} = 99;