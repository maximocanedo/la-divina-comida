/*
    En este archivo:
     * Clase Persona
*/
#ifndef PERSONAS_H_INCLUDED
#define PERSONAS_H_INCLUDED

class Persona {
private:
    char nombre[48];
    char apellido[48];
    int DNI;
    Date fechaDeNacimiento;
    char nacionalidad[4]; // ARG, URY, BRA, ...
    char numeroTelefono[24]; // Se usa chars porque puede darse el caso que el teléfono comience con ceros.
    int estadoCivil; // 0: Soltero, 1: Casado, 2: Relación
    bool estado;
public:
    /* Gets */
    const char * getNombre() {return nombre;}
    const char * getApellido() {return apellido;}
    int getDNI() {return DNI;}
    Date getFechaDeNacimiento() {return fechaDeNacimiento;}
    const char * getNacionalidad() {return nacionalidad;}
    const char * getNumeroTelefono() {return numeroTelefono;}
    int getEstadoCivil() {return estadoCivil;}
    void printEstadoCivil(bool e = false) {
        char estados[3][24] = {"Soltero", "Casado", "Relación"};
        cout<<estados[estadoCivil];
    }
    bool getEstado() {return estado;}
    /* Sets */
    void setNombre(const char * n) {strcpy(nombre, n);}
    void setApellido(const char * n) {strcpy(apellido, n);}
    void setDNI(int n) {DNI = n;}
    void setFechaDeNacimiento(Date n) {fechaDeNacimiento.copyFrom(n);}
    void setNacionalidad(const char * n) {strcpy(nacionalidad, n);}
    void setNumeroTelefono(const char * n) {strcpy(numeroTelefono, n);}
    void setEstadoCivil(int n) {estadoCivil = n;}
    void setEstado(bool n) {estado = n;}
    /* Cargar y Mostrar */
    void Cargar() {
        cout<<"Ingrese nombre: "; cargarCadena(nombre, 47);
        cout<<"Ingrese apellido: "; cargarCadena(apellido, 47);
        cout<<"Ingrese N.º de DNI: "; cin>>DNI;
        cout<<"Ingrese fecha de nacimiento: "; fechaDeNacimiento.load(false);
        cout<<"Ingrese código de nacionalidad: "; cargarCadena(nacionalidad, 3);
        cout<<"Ingrese número de teléfono: "; cargarCadena(numeroTelefono, 23);
        cout<<"Ingrese estado civil. 0 => Soltero, 1 => Casado, 2 => Relación.: "; cin>>estadoCivil;
        estado = true;
    }
    void Mostrar() {
        if(getEstado()) {
            cout<<"\t"<<apellido<<", "<<nombre<<endl;
            cout<<"\tN.º de DNI: "<<DNI<<". "<<endl;
            cout<<"\tFecha de nacimiento: "; fechaDeNacimiento.print(fechaDeNacimiento.SP_FULL, false, false); cout<<endl;
            cout<<"\tNacionalidad: "<<nacionalidad<<endl;
            cout<<"\tNúmero de teléfono: "<<numeroTelefono<<endl;
            cout<<"\tEstado civil: "; printEstadoCivil(); cout<<endl;
        }
    }
    /* Constructores */
    Persona() {}
    Persona(const char * a, const char * n, int p, Date fn, const char * pe, const char * t, int e, bool es) {
        strcpy(apellido, a);
        strcpy(nombre, n);
        DNI = p;
        fechaDeNacimiento.copyFrom(fn);
        strcpy(nacionalidad, pe);
        strcpy(numeroTelefono, t);
        estadoCivil = e;
        estado = es;
    }
    /* Destructores */
    ~Persona() {}
    /*
       Atención:
       Se omitieron los métodos .leerDeArchivo(int[, const char *]) y .escribirEnArchivo([const char *]) porque no son necesarios.
    */


};

#endif // PERSONAS_H_INCLUDED
