#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "cliente.h"
#include "residuo.h"
#define CANTIDADCLIENTES 10
#define CANTIDADRESIDUOS 3

int menu(int*opcion);
int main()
{

    Cliente clientes[CANTIDADCLIENTES];
    Residuo residuos[CANTIDADRESIDUOS];
   // Afiche afiches[CANTIDADAFICHES];
    int opcion;
    int auxid,auxCantidadAfiches,auxZona;
    char auxNombre [50];
    int auxKgResiduo;
    char auxDireccion[50];
    char auxLocalidad[50];
    char auxCuit[50];
    char auxNombreAfiche[50];
    int confirmar;
    int i;
    cli_inicializarArray(clientes,CANTIDADCLIENTES);

    cli_alta(clientes,cli_obtenerID(),CANTIDADCLIENTES,"Paraiso 2003","caba","Santiago","285154226");
    cli_alta(clientes,cli_obtenerID(),CANTIDADCLIENTES,"Yerbal 5992","caba","Guillermo","023596826");
    cli_alta(clientes,cli_obtenerID(),CANTIDADCLIENTES,"9 DE 10","ezeiza","Marco","036554226");
    cli_alta(clientes,cli_obtenerID(),CANTIDADCLIENTES,"Rombal 012","caba","Juan","001154226");
    cli_alta(clientes,cli_obtenerID(),CANTIDADCLIENTES,"General Paz","avellaneda","Nico","011154226");

    res_alta(residuos,res_obtenerID(),CANTIDADRESIDUOS,"1","201kg","2","Pendiente");
    do{
        menu(&opcion);
        switch (opcion){
            case 1:
                if(!utn_getLetras(auxNombre,50,3,"\nIngrese el nombre: ","\nError! El nombre debe contener solo letras")&&
                    !utn_getLetrasYNumeros(auxDireccion,50,"\nIngrese la direccion del cliente:")&&
                    !utn_getLetrasYNumeros(auxLocalidad,50,"\nIngrese la localidad del cliente:")&&
                    !utn_getCuit(auxCuit,50,3,"\nIngrese el cuit: ","Error Ingrese el cuit, deben ingresarse los 11 numeros")){
                        auxid=cli_obtenerID();
                        cli_alta(clientes,auxid,CANTIDADCLIENTES,auxDireccion,auxLocalidad,auxNombre,auxCuit);
                        printf("Alta satisfactoria numero de ID: %d",auxid);
                        getchar();
                    }
                break;
            case 2:
                if(!utn_getEntero(&auxid,3,"\nIngrese el ID: ","\nError! Ingrese un ID valido ",-1,999)&&
                    !cli_existeId(clientes,CANTIDADCLIENTES,auxid)){
                    cli_modificarbyId(clientes,CANTIDADCLIENTES,auxid);
                }else{
                        printf("\nEl ID no existe.  VuauxDireccionelva a intentarlo");
                        getchar();
                    }
                break;
            case 3:
                if(!utn_getEntero(&auxid,3,"\nIngrese el ID: ","\nError! Ingrese un ID valido ",-1,999)&&
                    !cli_existeId(clientes,CANTIDADCLIENTES,auxid)&&
                    !utn_getEntero(&confirmar,3,"\nEsta seguro que desea eliminarlo? 0- SI 1- NO ","Error! Elija una opcion valida",0,1)&&
                    !confirmar){
                    cli_eliminarbyId(clientes,CANTIDADCLIENTES,auxid);
                    //afi_eliminarbyId(afiches,CANTIDADAFICHES,auxid);
                }else{
                        printf("\nEl ID no existe.  Vuelva a intentarlo");
                        getchar();
                    }

                break;
            case 4:
                    cli_listar(clientes,CANTIDADCLIENTES);

                    /*if(!utn_getEntero(&auxid,3,"\nIngrese el ID: ","\nError! Ingrese un ID valido ",-1,999)&&
                    !cli_existeId(clientes,CANTIDADCLIENTES,auxid)&&
                    !utn_getEntero(&auxKgResiduo,3,"\Cuantos kilogramos de residuos se recolectaran del cliente ","Error! Elija un numero entero",0,1000)&&
                    !confirmar) //FINALIZAR

                    //afi_eliminarbyId(afiches,CANTIDADAFICHES,auxid);
                    }else{
                        printf("\nEl ID no existe.  Vuelva a intentarlo");*/
                        getchar();


                break;
            case 5:
                 res_listar(residuos,CANTIDADRESIDUOS);
               // afi_listar(afiches,CANTIDADAFICHES);
                //if(!utn_getEntero(&auxid,3,"\nIngrese el ID de venta: ","\nError Ingrese un ID valido ",-1,999)&&
                   // !afi_existeId(afiches,CANTIDADAFICHES,auxid)&&
                  //  !utn_get    cli_alta(clientes,cli_obtenerID(),CANTIDADCLIENTES,"Rombal 012","caba","juan","001154226");
                //Entero(&auxCantidadAfiches,3,"\nIngrese la cantidad de afiches :","\nError Ingrese un numero valido",0,9999)&&
                   // !utn_getEntero(&auxZona,3,"\nIngrese la zona: 1- CABA 2-ZONA SUR 3-ZONA OESTE :","\nError Ingrese una opcion valida",1,3)){
                     //   afi_editar(afiches,auxid,CANTIDADAFICHES,auxCantidadAfiches,auxZona);
               /* }else{
                        printf("\nERROR..Vuelva A Intentarlo");
                        getchar();
                }*/
                break;
            case 6:
                cli_listar(clientes,CANTIDADCLIENTES);
                break;
            case 7:
           //     inf_impClientesAcobrar(clientes,CANTIDADCLIENTES,afiches,CANTIDADAFICHES);
                //inf_impCliByMayorOrMenorCanAfiches(afiches,CANTIDADAFICHES,clientes,CANTIDADCLIENTES,1,"\nEl que tiene menos afiches es: ");
                getchar();
                break;
           case 8:
               /*  printf("\na)");
                inf_clienteMasACobrar(afiches,CANTIDADAFICHES,clientes,CANTIDADCLIENTES);
                printf("\nb)");
                inf_clienteMasCobradas(afiches,CANTIDADAFICHES,clientes,CANTIDADAFICHES);
                printf("\nc)");
                inf_clienteMasventas(afiches,CANTIDADAFICHES,clientes,CANTIDADCLIENTES);
                printf("\nd)");
                inf_impCliByMayorAfichesACobrar(afiches,CANTIDADAFICHES,clientes,CANTIDADCLIENTES,"\nEl cliente con mas a cobrar es: ");
                printf("\ne)");
                inf_impCliByMayorOrMenorCanAfiches(afiches,CANTIDADAFICHES,clientes,CANTIDADCLIENTES,0,"\nEl que mas compro es: ");
                printf("\nf)");
                inf_zonaMenosAfiVendidos(afiches,CANTIDADAFICHES);
                printf("\ng)");
                inf_cantidadConMenos100Afi(afiches,CANTIDADAFICHES,clientes,CANTIDADCLIENTES);
                printf("\nh)");
                inf_cantidadAfiByZona(afiches,CANTIDADAFICHES);
                printf("\ni)");
                inf_ordenarAfiByZona(afiches,CANTIDADAFICHES,0);
                afi_listar(afiches,CANTIDADAFICHES);
                printf("\nj)");
             opcion   inf_promedioAfichesByCliente(afiches,CANTIDADAFICHES,clientes,CANTIDADCLIENTES);*/
                getchar();
        }
    }while(opcion!=9);
    return 0;
}
int menu(int*opcion){
    printf("\n1-ALTAS\n2-MODIFICAR\n3-BAJA\n4-CREAR PEDIDO DE RECOLECCION\n5-PROCESAR RESIDUO \n6-IMPRIMIR CLIENTES\n7-IMPRIMIR PENDIENTES\n8-IMPRIMIR PROCESADOS\n9-SALIR");
    utn_getEntero(opcion,2,"\nIngrese una opcion: ","\nError. Ingrese una opcion valida.",1,9);
    return 0;

}
