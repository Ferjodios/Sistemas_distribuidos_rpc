/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "mensaje.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

enum clnt_stat 
init_rpc_1(int *clnt_res, CLIENT *clnt)
{
	 return (clnt_call (clnt, init_rpc, (xdrproc_t) xdr_void, (caddr_t) NULL,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));

}

enum clnt_stat 
set_value_rpc_1(struct request peticion, int *clnt_res,  CLIENT *clnt)
{
	return (clnt_call(clnt, set_value_rpc,
		(xdrproc_t) xdr_request, (caddr_t) &peticion,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
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
modify_value_rpc_1(struct request peticion, int *clnt_res,  CLIENT *clnt)
{
	return (clnt_call(clnt, modify_value_rpc,
		(xdrproc_t) xdr_request, (caddr_t) &peticion,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
delete_key_rpc_1(int key, int *clnt_res,  CLIENT *clnt)
{
	return (clnt_call(clnt, delete_key_rpc,
		(xdrproc_t) xdr_int, (caddr_t) &key,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
exist_rpc_1(int key, int *clnt_res,  CLIENT *clnt)
{
	return (clnt_call(clnt, exist_rpc,
		(xdrproc_t) xdr_int, (caddr_t) &key,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));
}
