
#include "claves.h"
#include <mqueue.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "mensaje.h"


CLIENT *clnt;

static int create_client()
{
	char	*host;

	host = getenv("IP_TUPLAS");
	
	clnt = clnt_create (host, LIST_SERVICE, LIST_SERVICE_V1, "udp");
	if (clnt == NULL)
	{
		clnt_pcreateerror (host);
		exit (1);
	}
	return (0);
}

static int check_value(char *value1, int N_value2, double *V_value2)
{
	if (strlen(value1) >= 256)
		return (-1);
	if (N_value2 < 1 || N_value2 > 32)
		return (-1);
	return (0);
}
int init()
{
	int result_1;	
	enum clnt_stat retval_1;
	if (create_client() == -1)
	{
		printf("Error initialiting rpc\n");
		return (-1);
	}

	retval_1 = init_rpc_1(&result_1, clnt);
	if (retval_1 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
	clnt_destroy (clnt);
	if (result_1 != 0)
	{
		printf("Error in init\n");
		return (-1);
	}		
	else
	{
		printf("Linked list emptied\n");
		return (0);
	}
}

int set_value(int key, char *value1, int N_value2, double *V_value2)
{
	enum clnt_stat retval_2;
	int result_2;
	struct request set_value_rpc_1_peticion;

	if (create_client() == -1)
	{
		printf("Error initialiting rpc\n");
		return (-1);
	}
	if (check_value(value1, N_value2, V_value2) == -1)
	{
		printf("Not the right values\n");
		return (-1);
	}

	set_value_rpc_1_peticion.v1.v1_val = malloc(strlen(value1) + 1);
    if (set_value_rpc_1_peticion.v1.v1_val == NULL) {
        printf("Error allocating memory\n");
        return (-1);
    }
	set_value_rpc_1_peticion.v2.v2_val = malloc(N_value2 * sizeof(double));
	if (set_value_rpc_1_peticion.v2.v2_val == NULL) {
		free(set_value_rpc_1_peticion.v1.v1_val);
		printf("Error allocating memory for v2_val\n");
		return (-1);
	}
	set_value_rpc_1_peticion.key = key;
	set_value_rpc_1_peticion.N = N_value2;
	strcpy(set_value_rpc_1_peticion.v1.v1_val, value1);
	set_value_rpc_1_peticion.v1.v1_len = strlen(value1); // Asigna la longitud de la cadena value1 a v1_len
	for (int i = 0; i < N_value2; i++)
	{
    	set_value_rpc_1_peticion.v2.v2_val[i] = V_value2[i];
	}
	set_value_rpc_1_peticion.v2.v2_len = N_value2;
	retval_2 = set_value_rpc_1(set_value_rpc_1_peticion, &result_2, clnt);
	if (retval_2 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
	clnt_destroy (clnt);

	    // Liberar memoria asignada
    free(set_value_rpc_1_peticion.v1.v1_val);
	free(set_value_rpc_1_peticion.v2.v2_val);
	if (result_2 != 0)
	{
		printf("Error in set_value\n");
		return (-1);
	}
	else
	{
		printf("Value set\n");
		return (0);
	}
}

int get_value(int key, char *value1, int *N_value2, double *V_value2)
{
	enum clnt_stat retval_3;
	struct response result_3;
	int get_value_rpc_1_key;
	// No se si necesito añadirle memerio dinamica
	// result_3.v1 = (char *)malloc(sizeof(char) * 256);
	// result_3.v2 = (double *)malloc(sizeof(dobule) * 32);
	if (create_client() == -1)
	{
		printf("Error initialiting rpc\n");
		return (-1);
	}
	get_value_rpc_1_key = key;
	retval_3 = get_value_rpc_1(get_value_rpc_1_key, &result_3, clnt);
	if (retval_3 != RPC_SUCCESS)
	{
		clnt_perror (clnt, "call failed");
	}
	clnt_destroy (clnt);

	if (result_3.error != 0)
	{
		printf("Error in get_value\n");
		// free(result_3.v1);
		// free(result_3.v2);
		return (-1);
	}
	else
	{
		printf("Your values: v1: %s, N2: %d\n", result_3.v1.v1_val, result_3.N);
		strcpy(value1, result_3.v1.v1_val);
		*N_value2 = result_3.N;
		printf("Contenido de v2:\n");
    	for(int i = 0; i < result_3.N; i++)
		{
        	printf("%f ", result_3.v2.v2_val[i]);
			V_value2[i] = result_3.v2.v2_val[i];
		}
		printf("\n");
		// free(result_3.v1);
		// free(result_3.v2);
		return (0);
	}
}

int modify_value(int key, char *value1, int N_value2, double *V_value2)
{
	enum clnt_stat retval_4;
	int result_4;
	struct request modify_value_rpc_1_peticion;
	if (create_client() == -1)
	{
		printf("Error initialiting rpc\n");
		return (-1);
	}
	if (check_value(value1, N_value2, V_value2) == -1)
	{
		printf("Not the right values\n");
		return (-1);
	}

	modify_value_rpc_1_peticion.v1.v1_val = malloc(strlen(value1) + 1);
    if (modify_value_rpc_1_peticion.v1.v1_val == NULL) {
        printf("Error allocating memory\n");
        return (-1);
    }
	modify_value_rpc_1_peticion.v2.v2_val = malloc(N_value2 * sizeof(double));
    if (modify_value_rpc_1_peticion.v2.v2_val == NULL) {
        printf("Error allocating memory for v2_val\n");
        free(modify_value_rpc_1_peticion.v1.v1_val); // Liberar memoria previamente asignada
        return (-1);
    }
	modify_value_rpc_1_peticion.key = key;
	modify_value_rpc_1_peticion.N = N_value2;
	strcpy(modify_value_rpc_1_peticion.v1.v1_val, value1);
	modify_value_rpc_1_peticion.v1.v1_len = strlen(value1);
	memcpy(modify_value_rpc_1_peticion.v2.v2_val, V_value2, N_value2 * sizeof(double));
	// No se si deberia meter esto
	// for (int i = 0; i < N_value2; i++)
    // 	modify_value_rpc_1_peticion.v2[i] = V_value2[i];
	retval_4 = modify_value_rpc_1(modify_value_rpc_1_peticion, &result_4, clnt);
	if (retval_4 != RPC_SUCCESS)
	{
		clnt_perror (clnt, "call failed");
	}
	clnt_destroy (clnt);

    free(modify_value_rpc_1_peticion.v1.v1_val);
    free(modify_value_rpc_1_peticion.v2.v2_val);
	if (result_4 != 0)
	{
		printf("Error in modify_value\n");
		return (-1);
	}
	else
	{
		printf("Modify succesful\n");
		return (0);
	}
}

int delete_key(int key)
{
	enum clnt_stat retval_5;
	int result_5;
	int delete_key_rpc_1_key;
	if (create_client() == -1)
	{
		printf("Error initialiting rpc\n");
		return (-1);
	}

	delete_key_rpc_1_key = key;
	retval_5 = delete_key_rpc_1(delete_key_rpc_1_key, &result_5, clnt);
	if (retval_5 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
	clnt_destroy (clnt);
	if (result_5 != 0)
	{
		printf("Error in delete\n");
		return (-1);
	}
	else
	{
		printf("deleted sucessful\n");
		return (0);
	}
}

int exist_proxy(int key)
{
	enum clnt_stat retval_6;
	int result_6;
	int exist_rpc_1_key;

	if (create_client() == -1)
	{
		printf("Error initialiting rpc\n");
		return (-1);
	}
	exist_rpc_1_key = key;
	retval_6 = exist_rpc_1(exist_rpc_1_key, &result_6, clnt);
	if (retval_6 != RPC_SUCCESS)
	{
		clnt_perror (clnt, "call failed");
	}
	clnt_destroy (clnt);
	if (result_6 == 0)
	{
		printf("No existe\n");
		return (0);
	}
	else if (result_6 == 1)
	{
		printf("Existe\n");
		return (1);
	}	
	else 
	{
		printf("Error en la función\n");
		return (-1);
	}
}
