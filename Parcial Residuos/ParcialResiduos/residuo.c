#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "residuo.h"
#include "utn.h"

static int res_buscarIndiceVacio(Residuo* pBuffer,int limite,int*indice);
int res_inicializarArray(Residuo* pBuffer,int limite){
    int i;
    int retorno=-1;
    if(pBuffer!=NULL && limite>0){
        retorno=0;
        for(i=0;i<limite;i++){
            pBuffer[i].isEmpty=1;
        }
    }
    return retorno;
}
int res_alta(Residuo* pBuffer,int id,int limite,int idPedido,int kgResiduo,int tipoResiduo,int estado){
    int indice;limite;
    int retorno=-1;
    if(pBuffer!=NULL && limite>0 && idPedido!=NULL && kgResiduo!=NULL && tipoResiduo !=NULL && estado != NULL){
        retorno=0;
        if(res_buscarIndiceVacio(pBuffer,limite,&indice)==0){
            pBuffer[indice].id=id;
            pBuffer[indice].isEmpty=0;
            pBuffer[indice].idPedido,idPedido;
            pBuffer[indice].kgResiduo,kgResiduo;
            pBuffer[indice].tipoResiduo,tipoResiduo;
            pBuffer[indice].estado,estado;
        }
    }
    return retorno;
}
static int res_buscarIndiceVacio(Residuo* pBuffer,int limite,int*indice){
    int i;
    int retorno=-1;
    if(pBuffer!=NULL && limite>0 && indice!=NULL){
        for(i=0;i<limite;i++){
            if(pBuffer[i].isEmpty==1){
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
int res_obtenerID(){
    static int ID=0;
    return ID++;
}
int res_modificarbyId(Residuo* pBuffer,int limite,int id){
    int i;
    int auxKg,auxTipoResiduo,auxEstado;
    int retorno=-1;
    if(pBuffer!=NULL&&limite>0){
        for (i=0;i<limite;i++){
            if(pBuffer[i].id==id&& pBuffer[i].isEmpty==0){
                if(!utn_getEntero(auxKg,3,"Ingrese la cantidad de kg de residuo del cliente","Ingrese una cantidad entera",0,1000)&&
                   !utn_getEntero(auxTipoResiduo,3,"Ingrese el tipo de residuo del cliente \n 0-HDPE\n 1-LDPE\n 2-PP","Ingrese una de las opciones",-1,3)&&
                   !utn_getEntero(auxEstado,3,"Ingrese el estado del pedido \n 0- Pendiente \n 1- Completado","Ingrese una de las opciones",-1,2)
                   )
                {
                       ( pBuffer[i].kgResiduo,auxKg);
                       ( pBuffer[i].tipoResiduo,auxTipoResiduo);
                       ( pBuffer[i].estado,auxEstado);
                        printf("Modificacion satisfactoria ");
                        getchar();
                        retorno=0;
                }
            }
        }
    }
    return retorno;}

int res_eliminarbyId(Cliente* pBuffer,int limite,int id){
    int i;
    int retorno=-1;
    if(pBuffer!=NULL && limite>0){
        for(i=0;i<limite;i++){
            if(pBuffer[i].isEmpty==0&& pBuffer[i].id==id){
                pBuffer[i].isEmpty=1;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
int res_existeId(Cliente* pBuffer,int limite,int id){
    int i;
    int retorno=-1;
    if(pBuffer!=NULL && limite>0){
        for(i=0;i<limite;i++){
            if(pBuffer[i].id==id && !pBuffer[i].isEmpty){
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
int res_impById(Cliente* pBuffer,int limite,int idCliente){
    int i;
    int retorno=-1;
    if(pBuffer!=NULL && limite>0){
        for(i=0;i<limite;i++){
            if(pBuffer[i].id==idCliente){
                printf("\nId: %d",pBuffer[i].id);
                printf("\t Nombre: %s",pBuffer[i].nombre);
                printf("\t Direccion: %s",pBuffer[i].direccion);
                printf("\t Cuit: %s",pBuffer[i].cuit);
                getchar();
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
int res_cantidadClientes(Cliente* pBuffer,int limite){
    int i;
    int cantidad=0;
    if(pBuffer!=NULL && limite>0){
        for(i=0;i<limite;i++){
            if(!pBuffer[i].isEmpty){
            cantidad++;
            }
        }
    }
    return cantidad;
}
int res_listar(Residuo* pBuffer,int limite){
    int i;
    int retorno=-1;
    if(pBuffer!=NULL&&limite>0)
    {
        for(i=0;i<limite;i++)
        {
            if(pBuffer[i].isEmpty==0)
            {
                retorno=0;
                printf("\n\nId: %d",pBuffer[i].id);
                printf("\nId del pedido: %d",pBuffer[i].idPedido);
                printf("\nKilogramos de residuo: %d",pBuffer[i].kgResiduo);
                printf("\nTipo de residuo: %d",pBuffer[i].tipoResiduo);
                printf("\nEstado del pedido: %d\n",pBuffer[i].estado);

            }
        }
    }
    return retorno;

}
