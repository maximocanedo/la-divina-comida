#ifndef FILTRAR_MOZOS_H_INCLUDED
#define FILTRAR_MOZOS_H_INCLUDED

int filtrarMozosPorNacionalidad();

int filtrarMozosPorNacionalidad() {
    Mozo obj; int pos = 0, fltrd = 0, total = 0;
    cout<<"Ingrese nacionalidad por la que desea filtrar: "; int n; cin>>n;
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado()) {
            if(obj.getNacionalidad() == n) {
                obj.Mostrar();
                fltrd++;
            }
            total++;
        }
    }
    informarCantRegistros(fltrd, total);
    return 0;
}

#endif // FILTRAR_MOZOS_H_INCLUDED
