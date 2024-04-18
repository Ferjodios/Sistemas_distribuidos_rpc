/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "mensaje.h"

/*mensaje_xdr.c: In function ‘xdr_response’:
mensaje_xdr.c:11:27: error: unused variable ‘buf’ [-Werror=unused-variable]
   11 |         register int32_t *buf;
      |                           ^~~
mensaje_xdr.c: In function ‘xdr_request’:
mensaje_xdr.c:29:27: error: unused variable ‘buf’ [-Werror=unused-variable]
   29 |         register int32_t *buf;
      |                           ^~~
cc1: all warnings being treated as errors*/
bool_t
xdr_response (XDR *xdrs, response *objp)
{
	//register int32_t *buf;

	 if (!xdr_array (xdrs, (char **)&objp->v1.v1_val, (u_int *) &objp->v1.v1_len, 256,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->N))
		 return FALSE;
	 if (!xdr_array (xdrs, (char **)&objp->v2.v2_val, (u_int *) &objp->v2.v2_len, 32,
		sizeof (double), (xdrproc_t) xdr_double))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->error))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_request (XDR *xdrs, request *objp)
{
	//register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->key))
		 return FALSE;
	 if (!xdr_array (xdrs, (char **)&objp->v1.v1_val, (u_int *) &objp->v1.v1_len, 256,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->N))
		 return FALSE;
	 if (!xdr_array (xdrs, (char **)&objp->v2.v2_val, (u_int *) &objp->v2.v2_len, 32,
		sizeof (double), (xdrproc_t) xdr_double))
		 return FALSE;
	return TRUE;
}
