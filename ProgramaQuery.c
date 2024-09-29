//programa en C para consultar los datos de la base de datos
//Incluir esta libreria para poder hacer las llamadas en shiva2.upc.es
//#include <my_global.h>
#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	MYSQL *conn;
	int err;
	// Estructura especial para almacenar resultados de consultas
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	char consulta [120] = "SELECT players.name FROM players, juego WHERE players.playerid = juego.winnerid;";
	//Creamos una conexion al servidor MYSQL
	conn = mysql_init(NULL);
	if (conn==NULL) {
		printf ("Error al crear la conexi\uffc3\uffb3n: %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//inicializar la conexion
	conn = mysql_real_connect (conn, "localhost","root", "mysql", NULL, 0, NULL, 0); 
	if (conn==NULL) {
		printf ("Error al inicializar la conexi\uffc3\uffb3n: %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	err=mysql_query (conn, consulta);
	if(err!=0){
		printf("Error al consultar");
		exit(1);
	}
	
	resultado = mysql_store_result (conn);
	row = mysql_fetch_row (resultado);
	if (row == NULL){
		printf("NO se han obtenido datos de la consulta");
	}
	else{
		while (row != NULL){
			printf("Nombre: %s\n", row[0]);
			row =mysql_fetch_row (resultado);
		}
	}
	return 0;
}
