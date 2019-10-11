#ifndef RESIDUO_H_INCLUDED
#define RESIDUO_H_INCLUDED
#include "utn.h"
#include "cliente.h"
typedef struct{
    int id;
    int idPedido;
    int kgResiduo;
    int tipoResiduo;
    int estado;
    int isEmpty;
}Residuo;


int res_listar(Residuo* pBuffer,int limite);
int res_inicializarArray(Residuo* pBuffer,int limite);
int res_alta(Residuo* pBuffer,int id,int limite,int idPedido,int kgResiduo,int tipoResiduo,int estado);
static int res_buscarIndiceVacio(Residuo* pBuffer,int limite,int*indice);
int res_obtenerID();
int res_modificarbyId(Residuo* pBuffer,int limite,int id);
#endif // RESIDUO_H_INCLUDED
