#include <iostream>
#include <cstdlib>
#include <locale.h>

using namespace std;
/*
    En este archivo:
     * MAIN FILE
    Pendiente:
     * Vincular clases Venta y Mozo con Sucursal.
        * Al cargar Venta verificar que la sucursal ingresada coincida con la sucursal en la que trabaja el Mozo ingresado.
     * Cambiar pasaporte por DNI en Persona.
*/

int menuPrincipal();

#include "include/librerias/Basics.h"
#include "include/librerias/errores.h"
#include "include/librerias/Fecha.h"
#include "include/librerias/Menu.h"

#include "include/clases/personas.h"
#include "include/clases/sucursales.h"
#include "include/clases/mozos.h"
#include "include/clases/comidas.h"
#include "include/clases/bebidas.h"
#include "include/clases/clientes.h"
#include "include/clases/ventas.h"

#include "include/fun/a.h"
#include "include/fun/cargar.h"
#include "include/fun/mostrar.h"
#include "include/fun/reportes.h"

#include "include/menus/menu_carga.h"
#include "include/menus/menu_muestra.h"
#include "include/menus/menu_reportes.h"
#include "include/menus/menu_registros.h"
#include "include/menus/menu_principal.h"

int main() {
    setlocale(LC_ALL, "");
    //msuc();
    menuPrincipal();
    system("pause");
    return 0;
}
