/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "RPC.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

enum clnt_stat 
init_rpc_1(struct response *clnt_res, CLIENT *clnt)
{
	 return (clnt_call (clnt, init_rpc, (xdrproc_t) xdr_void, (caddr_t) NULL,
		(xdrproc_t) xdr_response, (caddr_t) clnt_res,
		TIMEOUT));

}

enum clnt_stat 
set_value_rpc_1(int key, char *value1, int value2, double value3, struct response *clnt_res,  CLIENT *clnt)
{
	set_value_rpc_1_argument arg;
	arg.key = key;
	arg.value1 = value1;
	arg.value2 = value2;
	arg.value3 = value3;
	return (clnt_call (clnt, set_value_rpc, (xdrproc_t) xdr_set_value_rpc_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_response, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
get_value_rpc_1(int key, struct response *clnt_res,  CLIENT *clnt)
{
	return (clnt_call(clnt, get_value_rpc,
		(xdrproc_t) xdr_int, (caddr_t) &key,
		(xdrproc_t) xdr_response, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
modify_value_rpc_1(int key, char *value1, int value2, double value3, struct response *clnt_res,  CLIENT *clnt)
{
	modify_value_rpc_1_argument arg;
	arg.key = key;
	arg.value1 = value1;
	arg.value2 = value2;
	arg.value3 = value3;
	return (clnt_call (clnt, modify_value_rpc, (xdrproc_t) xdr_modify_value_rpc_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_response, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
delete_key_rpc_1(int key, struct response *clnt_res,  CLIENT *clnt)
{
	return (clnt_call(clnt, delete_key_rpc,
		(xdrproc_t) xdr_int, (caddr_t) &key,
		(xdrproc_t) xdr_response, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
exist_rpc_1(int key, struct response *clnt_res,  CLIENT *clnt)
{
	return (clnt_call(clnt, exist_rpc,
		(xdrproc_t) xdr_int, (caddr_t) &key,
		(xdrproc_t) xdr_response, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
copy_key_rpc_1(int key1, int key2, struct response *clnt_res,  CLIENT *clnt)
{
	copy_key_rpc_1_argument arg;
	arg.key1 = key1;
	arg.key2 = key2;
	return (clnt_call (clnt, copy_key_rpc, (xdrproc_t) xdr_copy_key_rpc_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_response, (caddr_t) clnt_res,
		TIMEOUT));
}
