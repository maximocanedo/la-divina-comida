#ifndef MENU_REGISTROS_H_INCLUDED
#define MENU_REGISTROS_H_INCLUDED

int menuRegistros();
// Administrar sucursales
int msucCOD();
int msuc();
// Administrar mozos
int mmozCOD();
int mmozDNI();
int mmoz();
// Administrar clientes
int mcliCOD();
int mcliDNI();
int mcli();
// Administrar platos
int mplaCOD();
int mplaNOM();
int mpla();
// Administrar bebidas
int mbebCOD();
int mbebNOM();
int mbeb();
// Administrar ventas
int mvenCOD();
int mven();

/* Trabajar con registros Sucursal */
int msucCOD() {
    Sucursal obj; int c, finalPos = -1;
    bool sucursalCorrecta = false;
    while(!sucursalCorrecta) {
        cout<<"Ingrese código de sucursal (0 para salir): ";
        cin>>c;
        if(c <= 0) return 0;
        finalPos = obj.getByCodigo(c);
        if(finalPos == -1) Error(6).print();
        else sucursalCorrecta = true;
    }
    obj.Manage(finalPos);
    return 0;
}
int msuc() {
    Item opciones[] = {
        Item{1, "Seleccionar por código de sucursal", msucCOD},
        Item{-1, ""},
        Item{0, "Volver al menú anterior", menuRegistros}
    };
    int _opciones = sizeof opciones / sizeof(Item);
    Menu sucursales("Elija cómo buscar el registro: ", 1, opciones, _opciones);
    sucursales.graph();
    return 0;
}

/* Trabajar con registros Mozo */
int mmozCOD() {
    Mozo obj; int c, finalPos = -1;
    bool mozoCorrecto = false;
    while(!mozoCorrecto) {
        cout<<"Ingrese código de mozo (0 para salir): ";
        cin>>c;
        if(c <= 0) return 0;
        finalPos = obj.getByCodigo(c);
        if(finalPos == -1) Error(6).print();
        else mozoCorrecto = true;
    }
    obj.Manage(finalPos);
    return 0;
}
int mmozDNI() {
    Mozo obj; int dni, finalPos = -1;
    bool mozoCorrecto = false;
    while(!mozoCorrecto) {
        cout<<"Ingrese D.N.I. del mozo (0 para salir): ";
        cin>>dni;
        if(dni <= 0) return 0;
        finalPos = obj.getByDNI(dni);
        if(finalPos == -1) Error(6).print();
        else mozoCorrecto = true;
    }
    obj.Manage(finalPos);
    return 0;
}
int mmoz() {
    Item opciones[] = {
        Item{1, "Seleccionar por código de mozo", mmozCOD},
        Item{2, "Seleccionar por número de D.N.I.", mmozDNI},
        Item{-1, ""},
        Item{0, "Volver al menú anterior", menuRegistros}
    };
    int _opciones = sizeof opciones / sizeof(Item);
    Menu mozos("Elija cómo buscar el registro: ", 1, opciones, _opciones);
    mozos.graph();
    return 0;
}

/* Trabajar con registros Bebida */
int mbebCOD() {  // Seleccionar registro Bebida por código
    Bebida obj; int c, finalPos = -1;
    bool bebidaCorrecta = false;
    while(!bebidaCorrecta) {
        cout<<"Ingrese código de bebida: ";
        cin>>c;
        finalPos = obj.getByCodigo(c);
        if(finalPos == -1) Error(6).print();
        else bebidaCorrecta = true;
    }
    obj.Manage(finalPos);
    return 0;
}
int mbebNOM() {  // Seleccionar registro Bebida por nombre
    Bebida obj;
    char nom[40];
    int finalPos = -1;
    bool bebidaCorrecta = false;
    while(!bebidaCorrecta) {
        cout<<"Ingrese nombre de la bebida: ";
        cargarCadena(nom, 39);
        finalPos = obj.getByName(nom);
        if(finalPos == -1) Error(6).print();
        else bebidaCorrecta = true;
    }
    obj.Manage(finalPos);
    return 0;
}
int mbeb() {     // Menú que pregunta al usuario de qué forma seleccionar registro Bebida
    Item opciones[] = {
        Item{1, "Seleccionar por código de bebida", mbebCOD},
        Item{2, "Seleccionar por nombre", mbebNOM},
        Item{-1, ""},
        Item{0, "Volver al menú anterior", menuRegistros}
    };
    int _opciones = sizeof opciones / sizeof(Item);
    Menu bebidas("Elija cómo desea buscar el registro: ", 1, opciones, _opciones);
    bebidas.graph();
    return 0;
}

/* Trabajar con registros Cliente */
int mcliCOD() {
    Cliente obj; int cod, finalPos = -1;
    bool clienteCorrecto = false;
    while(!clienteCorrecto) {
        cout<<"Ingrese número de cliente: #";
        cin>>cod;
        if(cod <= 0) return 0;
        finalPos = obj.getByNumeroCliente(cod);
        if(finalPos == -1) Error(6).print();
        else clienteCorrecto = true;
    }
    obj.Manage(finalPos);
    return 0;
}
int mcliDNI() {
    Cliente obj; int dni, finalPos = -1;
    bool clienteCorrecto = false;
    while(!clienteCorrecto) {
        cout<<"Ingrese número de D.N.I.: ";
        cin>>dni;
        if(dni <= 0) return 0;
        finalPos = obj.getByDNI(dni);
        if(finalPos == -1) Error(6).print();
        else clienteCorrecto = true;
    }
    obj.Manage(finalPos);
    return 0;
}
int mcli() {
    Item opciones[] = {
        Item{1, "Seleccionar por código de cliente", mcliCOD},
        Item{2, "Seleccionar por D.N.I.", mcliDNI},
        Item{-1, ""},
        Item{0, "Volver al menú anterior", menuRegistros}
    };
    int _opciones = sizeof opciones / sizeof(Item);
    Menu clientes("Elija cómo desea buscar el registro: ", 1, opciones, _opciones);
    clientes.graph();
    return 0;
}

/* Trabajar con registros Plato */
int mplaCOD() {
    Plato obj; int cod, finalPos = -1;
    bool platoCorrecto = false;
    while(!platoCorrecto) {
        cout<<"Ingrese código de plato: ";
        cin>>cod;
        if(cod <= 0) return 0;
        finalPos = obj.getByCodigo(cod);
        if(finalPos == -1) Error(6).print();
        else platoCorrecto = true;
    }
    obj.Manage(finalPos);
    return 0;
}
int mplaNOM() {
    Plato obj; int finalPos = -1; char n[72];
    bool platoCorrecto = false;
    while(!platoCorrecto) {
        cout<<"Ingrese nombre de plato: ";
        cargarCadena(n, 71);
        finalPos = obj.getByName(n);
        if(finalPos == -1) Error(6).print();
        else platoCorrecto = true;
    }
    obj.Manage(finalPos);
    return 0;
}
int mpla() {
    Item opciones[] = {
        Item{1, "Seleccionar por código de plato", mplaCOD},
        Item{2, "Seleccionar por nombre de plato", mplaNOM},
        Item{-1, ""},
        Item{0, "Volver al menú anterior", menuRegistros}
    };
    int _opciones = sizeof opciones / sizeof(Item);
    Menu platos("Elija cómo desea buscar el registro: ", 1, opciones, _opciones);
    platos.graph();
    return 0;
}

/* Menú Administrar Registros */
int menuRegistros() {
    Item opciones[] = {
        Item{1, "Seleccionar Sucursal", msuc},
        Item{2, "Seleccionar Mozo", mmoz},
        Item{3, "Seleccionar Cliente", mcli},
        Item{4, "Seleccionar Plato", mpla},
        Item{5, "Seleccionar Bebida", mbeb},
        Item{6, "Seleccionar Venta"},
        Item{-1, ""},
        Item{0, "Volver al menú anterior", menuPrincipal}
    };
    int _opciones = sizeof opciones / sizeof(Item);
    Menu registros("Administrar registros", 1, opciones, _opciones);
    registros.graph();
    return 0;
}

#endif // MENU_REGISTROS_H_INCLUDED
