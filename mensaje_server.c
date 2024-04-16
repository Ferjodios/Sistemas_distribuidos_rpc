/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "mensaje.h"
#include "claves.h"
#include "structs_handler"

bool_t
init_1_svc(int *result, struct svc_req *rqstp)
{
	*result = init();
	return TRUE;
}

bool_t
set_value_1_svc(struct request peticion, int *result,  struct svc_req *rqstp)
{
	
	*result = set_value(peticion.key, peticion.v1, peticion.N, peticion.v2);
	return TRUE;
}

bool_t
get_value_1_svc(int key, struct response *result,  struct svc_req *rqstp)
{
	result->error = get_value(key, result->v1, &(result->N), result->v2);
	return TRUE;
}

bool_t
modify_value_1_svc(struct request peticion, int *result,  struct svc_req *rqstp)
{
	bool_t retval;

	/*
	 * insert server code here
	 */

	return retval;
}

bool_t
delete_key_1_svc(int key, int *result,  struct svc_req *rqstp)
{
	bool_t retval;

	/*
	 * insert server code here
	 */

	return retval;
}

bool_t
exist_1_svc(int key, int *result,  struct svc_req *rqstp)
{
	bool_t retval;

	/*
	 * insert server code here
	 */

	return retval;
}

int
list_service_1_freeresult (SVCXPRT *transp, xdrproc_t xdr_result, caddr_t result)
{
	xdr_free (xdr_result, result);

	/*
	 * Insert additional freeing code here, if needed
	 */

	return 1;
}
