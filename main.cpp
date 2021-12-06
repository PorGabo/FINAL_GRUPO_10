//INTEGRANTES
//Gabriel Rodriguez Postigo
//Alvaro Patiño Delgado

#include <iostream>
#include <fstream> //libreria para archivos txt --> f de file
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctime> //para fecha automatica

//archivos
#include "registro.h"
#include "transaccion.h"
#include "compra.h"
#include "venta.h"
#include "cliente.h"
#include "menu.h"


/*

clase registro
		-id (boleta/factura)
		-fecha (de ingreso del registro)
	clase compra
	clase venta
		-otros datos
		*descuento --> tipos de producto de precio negativo (en relacion al original)
			-10%
			-20%
			-cupon
	clase usuario

clase producto (podria ser subclase de venta?)
	*ingresar producto en general
    *kit

*/

using namespace std;

int main()
{
	
	Menu inicio;
	inicio.MenuPrincipal(); 
	
    return 0;
}