/*
    En este archivo:
     * Clase Mozo
     * Responsable de la clase: Gabriel Baigorria
*/
#ifndef MOZOS_H_INCLUDED
#define MOZOS_H_INCLUDED

class Mozo:public Persona {
private:
    int codigo;
    int codigoSucursal;
    bool estado;
public:
    /* Gets */
    int getCodigo() { return codigo;}
    int getCodigoSucursal() {return codigoSucursal;}
    Sucursal getSucursal() {
        Sucursal aux;
        aux.getByCodigo(codigoSucursal);
        return aux;
    }
    bool getEstado() {return estado;}
    /* Sets */
    void setCodigo(int c) {codigo=c;}
    bool setSucursal(int c) {
        Sucursal aux;
        bool res = aux.getByCodigo(c);
        if(res) codigoSucursal = c;
        return res;
    }
    void setEstado(bool e) {estado=e;}
    /* Cargar y Mostrar */
    void Cargar(int cod = -1)
    {
        Persona::Cargar();
        if(cod==-1)
        {
            cout<< "Ingrese codigo de Mozo: ";
            cin>>codigo;
        }else
            codigo=cod;
        bool sucursalCargada = false;
        while(!sucursalCargada) {
            cout<<"Ingrese código de sucursal: ";
            int c; cin>>c;
            if(!setSucursal(c)) {
                cout<<"Sucursal incorrecta. \n";
            } else {
                cout<<"Sucursal correcta. \n";
                sucursalCargada = true;
            }
        }
        estado=true;
    }
    void Mostrar()
    {
        if(getEstado())
        {
            Persona::Mostrar();
            cout<<"\tCodigo de Mozo: ";
            cout<<codigo<<endl;
            cout<<"\tCódigo de sucursal: ";
            cout<<codigoSucursal<<endl;
            cout<<"--------------------------------------------------"<<endl;
        }
    }
    /* Constructores */
    Mozo() {}
///    Mozo():Persona() {}
    /* Destructor */
    ~Mozo() {}
    /* Lectura y escritura de archivos */
    bool leerDeArchivo(int pos, const char * filename = "mozos.dat") {
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
    bool escribirEnArchivo(const char * filename = "mozos.dat") {
        FILE * archivo = fopen(filename, "ab");
        if(archivo == NULL) {
            Error(2).print();
            return false;
        }
        bool res = fwrite(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return res;
    }
    bool modificarDelArchivo(int pos, const char * filename = "mozos.dat") {
        FILE * archivo;
        archivo = fopen(filename, "rb+");
        if(archivo == NULL) return false;
        fseek(archivo, (sizeof * this) * --pos, 0);
        bool escribio = fwrite(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return escribio;
    }
    /* Gets especiales */
    int getByCodigo(int codigoABuscar, const char * filename = "mozos.dat") {
        int pos = 0;
        while(leerDeArchivo(pos++, filename)) {
            if(getEstado() && getCodigo() == codigoABuscar) return pos;
        }
        return -1;
    }
    int getByDNI(int DNIABuscar, const char * filename = "mozos.dat") {
        int pos = 0;
        while(leerDeArchivo(pos++, filename)) {
            if(getEstado() && getDNI() == DNIABuscar) return pos;
        }
        return -1;
    }
    int getNextIndex(const char * filename = "mozos.dat") {
        int pos = 0, p = 1;
        while(leerDeArchivo(pos++, filename)) p++;
        return p;
    }

    void Manage(int posicion) {
        int c = getCodigo();
        Mostrar();
        cout<<"\n\t1. Cambiar código de sucursal dónde trabaja.";
        cout<<"\n\t2. Despedir (Borrar de los registros de mozo).";
        cout<<"\n\t0. Salir."<<endl;
        int opc = UserChoose(false);
        switch(opc) {
        case 1: {
            bool sucursalCargada = false;
            while(!sucursalCargada) {
                cout<<"Ingrese código de sucursal: ";
                int c; cin>>c;
                if(!setSucursal(c)) cout<<"Sucursal incorrecta. \n";
                else {
                    bool y = modificarDelArchivo(posicion);
                    if(y) cout<<"Se modificó exitosamente el registro. \n";
                    sucursalCargada = true;
                }
            }
            break;
        }
        case 2: {
            cout<<"Para confirmar el borrado, vuelva a ingresar el código del registro: ";
            int g; cin>>g;
            if(g == c) {
                estado = false;
                bool b = (modificarDelArchivo(posicion));
                if(b) cout<<"\n Se ha borrado correctamente el registro. "<<endl;
            }
            break;
        }
        default: break;
        }
    }
};

#endif // MOZOS_H_INCLUDED

