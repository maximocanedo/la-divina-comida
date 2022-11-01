#ifndef FILTRAR_MOZOS_H_INCLUDED
#define FILTRAR_MOZOS_H_INCLUDED

int filtrarMozosPorNacionalidad();
int filtrarMozosPorEstadoCivil();
int filtrarMozosPorAAAANacimiento();
int filtrarMozosPorMMNacimiento();
int filtrarMozosPorDDNacimiento();
int filtrarMozosPorDiaDeNacimiento();

int filtrarClientesPorNacionalidad();
int filtrarClientesPorEstadoCivil();
int filtrarClientesPorAAAANacimiento();
int filtrarClientesPorMMNacimiento();
int filtrarClientesPorDDNacimiento();
int filtrarClientesPorDiaDeNacimiento();

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
int filtrarMozosPorEstadoCivil() {
    Mozo obj; int pos = 0, fltrd = 0, total = 0;
    int n = -1; bool e = false;
    while(!e) {
        cout<<"Ingrese estado civil por el cual filtrar (0-2): ";
        cin>>n;
        e = (n>=0&&n<=2);
    }
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado()) {
            if(obj.getEstadoCivil() == n) {
                obj.Mostrar();
                fltrd++;
            }
            total++;
        }
    }
    informarCantRegistros(fltrd, total);
    return 0;
}
int filtrarMozosPorAAAANacimiento() {
    Mozo obj; int pos = 0, fltrd = 0, total = 0, n;
    cout<<"Ingrese año de nacimiento por el cual filtrar: ";
    cin>>n;
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado()) {
            if(obj.getFechaDeNacimiento().getFullYear() == n) {
                obj.Mostrar();
                fltrd++;
            }
            total++;
        }
    }
    informarCantRegistros(fltrd, total);
    return 0;
}
int filtrarMozosPorMMNacimiento() {
    Mozo obj; int pos = 0, fltrd = 0, total = 0, n = 0;
    bool e = false;
    while(!e) {
        cout<<"Ingrese mes de nacimiento por el cual filtrar (1-12): ";
        cin>>n;
        e = (n > 0 && n < 13);
    }
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado()) {
            if(obj.getFechaDeNacimiento().getMonth() == n) {
                obj.Mostrar();
                fltrd++;
            }
            total++;
        }
    }
    informarCantRegistros(fltrd, total);
    return 0;
}
int filtrarMozosPorDDNacimiento() {
    Mozo obj; int pos = 0, fltrd = 0, total = 0, n = 0;
    bool e = false;
    while(!e) {
        cout<<"Ingrese día (fecha) de nacimiento por el cual filtrar (1-31): ";
        cin>>n;
        e = (n > 0 && n < 32);
    }
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado()) {
            if(obj.getFechaDeNacimiento().getDate() == n) {
                obj.Mostrar();
                fltrd++;
            }
            total++;
        }
    }
    informarCantRegistros(fltrd, total);
    return 0;
}
int filtrarMozosPorDiaDeNacimiento() {
    Mozo obj; int pos = 0, fltrd = 0, total = 0, n = 0;
    bool e = false;
    while(!e) {
        cout<<"(0: Domingo, 1: Lunes, 2: Martes, 3: Miércoles, 4: Jueves, 5: Viernes, 6: Sábado)"<<endl<<endl;
        cout<<"Ingrese día de nacimiento por el cual filtrar (0-6): ";
        cin>>n;
        e = (n >= 0 && n < 7);
    }
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado()) {
            if(obj.getFechaDeNacimiento().getDay() == n) {
                obj.Mostrar();
                fltrd++;
            }
            total++;
        }
    }
    informarCantRegistros(fltrd, total);
    return 0;
}

int filtrarClientesPorNacionalidad() {
    Cliente obj; int pos = 0, fltrd = 0, total = 0;
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
int filtrarClientesPorEstadoCivil() {
    Cliente obj; int pos = 0, fltrd = 0, total = 0;
    int n = -1; bool e = false;
    while(!e) {
        cout<<"Ingrese estado civil por el cual filtrar (0-2): ";
        cin>>n;
        e = (n>=0&&n<=2);
    }
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado()) {
            if(obj.getEstadoCivil() == n) {
                obj.Mostrar();
                fltrd++;
            }
            total++;
        }
    }
    informarCantRegistros(fltrd, total);
    return 0;
}
int filtrarClientesPorAAAANacimiento() {
    Cliente obj; int pos = 0, fltrd = 0, total = 0, n;
    cout<<"Ingrese año de nacimiento por el cual filtrar: ";
    cin>>n;
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado()) {
            if(obj.getFechaDeNacimiento().getFullYear() == n) {
                obj.Mostrar();
                fltrd++;
            }
            total++;
        }
    }
    informarCantRegistros(fltrd, total);
    return 0;
}
int filtrarClientesPorMMNacimiento() {
    Cliente obj; int pos = 0, fltrd = 0, total = 0, n = 0;
    bool e = false;
    while(!e) {
        cout<<"Ingrese mes de nacimiento por el cual filtrar (1-12): ";
        cin>>n;
        e = (n > 0 && n < 13);
    }
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado()) {
            if(obj.getFechaDeNacimiento().getMonth() == n) {
                obj.Mostrar();
                fltrd++;
            }
            total++;
        }
    }
    informarCantRegistros(fltrd, total);
    return 0;
}
int filtrarClientesPorDDNacimiento() {
    Cliente obj; int pos = 0, fltrd = 0, total = 0, n = 0;
    bool e = false;
    while(!e) {
        cout<<"Ingrese día (fecha) de nacimiento por el cual filtrar (1-31): ";
        cin>>n;
        e = (n > 0 && n < 32);
    }
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado()) {
            if(obj.getFechaDeNacimiento().getDate() == n) {
                obj.Mostrar();
                fltrd++;
            }
            total++;
        }
    }
    informarCantRegistros(fltrd, total);
    return 0;
}
int filtrarClientesPorDiaDeNacimiento() {
    Cliente obj; int pos = 0, fltrd = 0, total = 0, n = 0;
    bool e = false;
    while(!e) {
        cout<<"(0: Domingo, 1: Lunes, 2: Martes, 3: Miércoles, 4: Jueves, 5: Viernes, 6: Sábado)"<<endl<<endl;
        cout<<"Ingrese día de nacimiento por el cual filtrar (0-6): ";
        cin>>n;
        e = (n >= 0 && n < 7);
    }
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado()) {
            if(obj.getFechaDeNacimiento().getDay() == n) {
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
