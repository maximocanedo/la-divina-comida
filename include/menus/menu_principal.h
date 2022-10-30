#ifndef MENU_PRINCIPAL_H_INCLUDED
#define MENU_PRINCIPAL_H_INCLUDED

int exitProgram(); // Sale del programa

int exitProgram() {
    exit(0);
    return 0;
}
int menuPrincipal() {
    Item opciones[] = {
        Item{1, "Administrar archivos", menuArchivos},
        Item{2, "Trabajar con un registro individual", menuRegistros},
        Item{3, "Reportes", menuReportes},
        Item{-1, ""},
        Item{0, "Salir del programa", exitProgram}
    };
    const int cantidadOpciones = sizeof opciones / sizeof(Item);
    Menu principal("Restaurante", 1, opciones, cantidadOpciones);
    principal.graph();
    return 0;
}

#endif // MENU_PRINCIPAL_H_INCLUDED
