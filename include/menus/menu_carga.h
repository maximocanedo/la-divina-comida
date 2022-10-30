#ifndef MENU_CARGA_H_INCLUDED
#define MENU_CARGA_H_INCLUDED

int menuArchivos();

int menuArchivos() {
    Item opciones[] = {
        Item{1, "Cargar mozos", cargarMozos},
        Item{10,"Mostrar mozos", mostrarMozos},
        Item{-1, ""},
        Item{2, "Cargar platos", cargarComidas},
        Item{20,"Mostrar platos", mostrarPlatos},
        Item{-1, ""},
        Item{3, "Cargar bebidas", cargarBebidas},
        Item{30,"Mostrar bebidas", mostrarBebidas},
        Item{-1, ""},
        Item{4, "Cargar clientes", cargarClientes},
        Item{40,"Mostrar clientes", mostrarClientes},
        Item{-1, ""},
        Item{5, "Cargar ventas", cargarVentas},
        Item{50,"Mostrar ventas", mostrarVentas},
        Item{-1, ""},
        Item{6, "Cargar sucursales", cargarSucursales},
        Item{60,"Mostrar sucursales", mostrarSucursales},
        Item{-1, ""},
        Item{0, "Volver al menú anterior", menuPrincipal}
    };
    int _opciones = sizeof opciones / sizeof(Item);
    Menu cargas("Carga de datos", 1, opciones, _opciones);
    cargas.graph();
    return 0;
}

#endif // MENU_CARGA_H_INCLUDED
