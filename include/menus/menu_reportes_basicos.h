#ifndef MENU_REPORTES_BASICOS_H_INCLUDED
#define MENU_REPORTES_BASICOS_H_INCLUDED

// int reportesSimples(); // Definido en otro lado

int reportesSimples() {
    Item opciones[] = {
        Item{-1, "Mozos"},
        Item{11, "\tFiltrar mozos por nacionalidad", filtrarMozosPorNacionalidad},
        Item{12, "\tFiltrar mozos seg�n su estado civil"},
        Item{13, "\tFiltrar mozos seg�n su a�o de nacimiento"},
        Item{14, "\tFiltrar mozos seg�n su mes de nacimiento"},
        Item{15, "\tFiltrar mozos seg�n su fecha (d�a) de nacimiento"},
        Item{16, "\tFiltrar mozos seg�n su d�a de nacimiento"},
        Item{-1, "Clientes"},
        Item{20, "\tFiltrar clientes por nacionalidad"},
        Item{21, "\tFiltrar clientes seg�n su estado civil"},
        Item{22, "\tFiltrar clientes seg�n su a�o de nacimiento"},
        Item{23, "\tFiltrar clientes seg�n su mes de nacimiento"},
        Item{24, "\tFiltrar clientes seg�n su fecha (d�a) de nacimiento"},
        Item{25, "\tFiltrar clientes seg�n su d�a de nacimiento"},
        Item{-1, "Platos"},
        Item{30, "\tFiltrar platos por nacionalidad"},
        Item{31, "\tFiltrar platos por tipo de plato"},
        Item{32, "\tFiltrar platos con precio menor al dado"},
        Item{33, "\tFiltrar platos con precio mayor al dado"},
        Item{34, "\tFiltrar platos por precio dado"},
        Item{35, "\tFiltrar platos con gluten"},
        Item{36, "\tFiltrar platos con carne"},
        Item{37, "\tFiltrar platos con huevo"},
        Item{38, "\tFiltrar platos con az�car"},
        Item{39, "\tFiltrar platos con man�"},
        Item{40, "\tFiltrar platos con chocolate"},
        Item{-1, ""},
        Item{0, "Volver al men� anterior", menuReportes}
    };
    int _opciones = sizeof opciones / sizeof(Item);
    Menu reportesBasicos("Reportes b�sicos", 1, opciones, _opciones);
    reportesBasicos.graph();
    return 0;
}

#endif // MENU_REPORTES_BASICOS_H_INCLUDED
