/*
    En este archivo:
     * Clase Sucursal
     * Encargado de la clase: Máximo Canedo, Legajo N.º: 25.839
*/
#ifndef SUCURSALES_H_INCLUDED
#define SUCURSALES_H_INCLUDED

class Sucursal {
private:
    int codigo;
    char nombre[48];
    bool estado;
public:
    /* Gets */
    int getCodigo() {return codigo;}
    const char * getNombre() {return nombre;}
    bool getEstado() {return estado;}
    /* Sets */
    void setCodigo(int c) {codigo = c;}
    void setNombre(const char * n) {strcpy(nombre, n);}
    void setEstado(bool e) {estado = e;}
    /* Cargar y Mostrar */
    void Cargar(int _cod = -1) {
        if(_cod == -1) {
            cout<<"Ingrese código de sucursal: ";
            cin>>codigo;
        } else {
            codigo = _cod;
        }
        cout<<"Ingrese nombre de la sucursal: ";
        cargarCadena(nombre, 47);
        estado = true;
    }
    void Mostrar() {
        if(getEstado()) {
            cout<<"\tDetalles de la sucursal #"<<codigo<<": "<<endl;
            cout<<"\tNombre: "<<nombre<<". "<<endl;
        }
    }
    /* Constructor */
    Sucursal() {}
    Sucursal(int cod, bool est) {
        codigo = cod;
        estado = est;
    }
    /* Destructor */
    ~Sucursal() {}
    /* Lectura y escritura de archivos */
    bool leerDeArchivo(int pos, const char * filename = "sucursales.dat") {
        FILE * archivo = fopen(filename, "rb");
        if(archivo == NULL) {
            Error(2).print();
            return false;
        }
        fseek(archivo, (sizeof * this) * pos, 0);
        bool res = fread(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return res;
    }
    bool escribirEnArchivo(const char * filename = "sucursales.dat") {
        FILE * archivo = fopen(filename, "ab");
        if(archivo == NULL) {
            Error(2).print();
            return false;
        }
        bool res = fwrite(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return res;
    }
    bool modificarDelArchivo(int pos, const char * filename = "sucursales.dat") {
        FILE * archivo;
        archivo = fopen(filename, "rb+");
        if(archivo == NULL) return false;
        fseek(archivo, (sizeof * this) * --pos, 0);
        bool escribio = fwrite(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return escribio;
    }
    /* Gets especiales */
    int getByCodigo(int codigoABuscar, const char * filename = "sucursales.dat") {
        int pos = 0;
        while(leerDeArchivo(pos++, filename)) {
            if(getEstado() && getCodigo() == codigoABuscar) return pos;
        }
        return -1;
    }
    int getNextIndex(const char * filename = "sucursales.dat") {
        int pos = 0, i = 1;
        while(leerDeArchivo(pos++, filename)) i++;
        return i;
    }
    /* Managing del objeto */
    void Manage(int c) { // Por alguna razón no funciona
        int posicion = getByCodigo(c);
        Mostrar();
        cout<<"\n";
        cout<<"\t 1. Modificar nombre de sucursal"<<endl;
        cout<<"\t 2. Eliminar"<<endl;
        cout<<"\t 0. Salir."<<endl;
        int opc = UserChoose(false);
        switch(opc) {
        case 1:
            cout<<"Ingrese nuevo nombre de sucursal: ";
            cargarCadena(nombre, 47);
            if(modificarDelArchivo(posicion)) cout<<"\n Se modificó correctamente. "<<endl;
            break;
        case 2:
            cout<<"Para confirmar el borrado, vuelva a ingresar el código del registro: ";
            int g; cin>>g;
            if(g == c) {
                estado = false;
                bool b = (modificarDelArchivo(posicion));
                if(b) cout<<"\n Se ha borrado correctamente el registro. "<<endl;
            }
            break;
        default:
            break;
        }
    }
};

#endif // SUCURSALES_H_INCLUDED
