#include <iostream>
#include <cstdlib>
#include <locale.h>

using namespace std;
/*
    En este archivo:
     * MAIN FILE
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
    menuPrincipal();
    system("pause");
    return 0;
}
