#ifndef MENU_REPORTES_H_INCLUDED
#define MENU_REPORTES_H_INCLUDED

int menuReportes();

int menuReportes() {
    Item opciones[] = {
        Item{1, "Recaudación en bebidas alcohólicas", recaudacionEnBebidasAlcoholicas},
        Item{2, "Recaudación de impuestos (Todas las sucursales)", recaudacionAFIPTodasSucursales},
        Item{3, "Recaudación de clientes casados", recaudacionCasados},
        Item{4, "Sucursales que recaudaron efectivo por alcohol en la década 2010-2020", sucursalesQueRecaudaronCashPorVentaDeAlcoholEnLaDecada2010},
        Item{5, "Cantidad de mozos que atendieron a clientes solteros un jueves", cantMozosQueAtendieronAClientesSolterosEnJueves},
        Item{-1, ""},
        Item{0, "Volver al menú anterior", menuPrincipal}
    };
    int _opciones = sizeof opciones / sizeof(Item);
    Menu reportes("Reportes", 1, opciones, _opciones);
    reportes.graph();
    return 0;
}

#endif // MENU_REPORTES_H_INCLUDED
