#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"

static int cli_buscarIndiceVacio(Cliente* pBuffer,int limite,int*indice);
int cli_inicializarArray(Cliente* pBuffer,int limite){
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
int cli_alta(Cliente* pBuffer,int id,int limite,char* direccion,char* localidad,char* nombre,char*cuit){
    int indice;
    int retorno=-1;
    if(pBuffer!=NULL && limite>0 && direccion!=NULL && localidad!=NULL && nombre !=NULL && cuit != NULL){
        retorno=0;
        if(cli_buscarIndiceVacio(pBuffer,limite,&indice)==0){
            pBuffer[indice].id=id;
            pBuffer[indice].isEmpty=0;
            strcpy(pBuffer[indice].direccion,direccion);
            strcpy(pBuffer[indice].localidad,localidad);
            strcpy(pBuffer[indice].nombre,nombre);
            strcpy(pBuffer[indice].cuit,cuit);
        }
    }
    return retorno;
}
static int cli_buscarIndiceVacio(Cliente* pBuffer,int limite,int*indice){
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
int cli_obtenerID(){
    static int ID=0;
    return ID++;
}
int cli_modificarbyId(Cliente* pBuffer,int limite,int id){
    int i;
    char auxDireccion[50];
    char auxLocalidad[50];
    int retorno=-1;
    if(pBuffer!=NULL&&limite>0){
        for (i=0;i<limite;i++){
            if(pBuffer[i].id==id&& pBuffer[i].isEmpty==0){
                if(!utn_getLetrasYNumeros(auxDireccion,50,"\nIngrese la direccion del cliente:")&&
                   !utn_getLetras(auxLocalidad,50,3,"\nIngrese la nueva localidad: ","\nError. Ingrese la localidad"))
                   {
                        strcpy(pBuffer[i].direccion,auxDireccion);
                        strcpy(pBuffer[i].localidad,auxLocalidad);
                        printf("Modificacion satisfactoria ");
                        getchar();
                        retorno=0;
                }
            }
        }
    }
    return retorno;
}
int cli_eliminarbyId(Cliente* pBuffer,int limite,int id){
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
int cli_existeId(Cliente* pBuffer,int limite,int id){
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
int cli_impById(Cliente* pBuffer,int limite,int idCliente){
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
int cli_cantidadClientes(Cliente* pBuffer,int limite){
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
int cli_listar(Cliente* pBuffer,int limite){
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
                printf("\nNombre cliente: %s",pBuffer[i].nombre);
                printf("\nLocalidad cliente: %s",pBuffer[i].localidad);
                printf("\nDireccion cliente: %s",pBuffer[i].direccion);
                printf("\nCuit cliente: %s\n",pBuffer[i].cuit);

            }
        }
    }
    return retorno;

}

