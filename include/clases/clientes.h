#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

class Cliente:public Persona {
private:
    int numeroCliente;
    bool estado;
public:
    /* Gets */
    int getNumeroCliente() {return numeroCliente;}
    bool getEstado() {return estado;}
    /* Sets */
    void setNumeroCliente(int n) {numeroCliente=n;}
    void setEstado(bool e) {estado=e;}
    /* Cargar y Mostrar */
    void Cargar(int n = -1)
    {
        if(n==-1)
        {
            cout<< "Ingrese numero de Cliente: ";
            cin>> numeroCliente;
        } else {
            cout<<"Número de cliente asignado: "<<n<<". "<<endl;
            numeroCliente = n;
        }
        Persona::Cargar();
        estado=true;
    }
    void Mostrar()
    {
        if(getEstado())
        {
        cout<< "\tNumero de Cliente: "<<numeroCliente<<endl;
        Persona::Mostrar();
        cout<<"--------------------------------------------------"<<endl;
        }
    }
    /* Constructores */
    Cliente(int n=0)
    {
            numeroCliente = n;
    }
///    Cliente():Persona() {}
    /* Destructor */
    ~Cliente() {}
    /* Lectura y escritura de archivos */
    bool leerDeArchivo(int pos, const char * filename = "clientes.dat") {
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
    bool escribirEnArchivo(const char * filename = "clientes.dat") {
        FILE * archivo = fopen(filename, "ab");
        if(archivo == NULL) {
            Error(2).print();
            return false;
        }
        bool res = fwrite(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return res;
    }
    bool modificarDelArchivo(int pos, const char * filename = "clientes.dat") {
        FILE * archivo;
        archivo = fopen(filename, "rb+");
        if(archivo == NULL) return false;
        fseek(archivo, (sizeof * this) * --pos, 0);
        bool escribio = fwrite(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return escribio;
    }
    /* Gets especiales */
    int getByNumeroCliente(int codigoABuscar, const char * filename = "clientes.dat") {
        int pos = 0;
        while(leerDeArchivo(pos++, filename)) {
            if(getEstado() && getNumeroCliente() == codigoABuscar) return pos;
        }
        return -1;
    }
    int getByDNI(int numeroDNIABuscar, const char * filename = "clientes.dat") {
        int pos = 0;
        while(leerDeArchivo(pos++, filename)) {
            if(getEstado() && getDNI() == numeroDNIABuscar) return pos;
        }
        return -1;
    }
    int getNextIndex(const char * filename = "clientes.dat") {
        int pos = 0, e = 1;
        while(leerDeArchivo(pos++, filename)) e++;
        return e;
    }

    void Manage(int posicion) {
        int c = getNumeroCliente();
        Mostrar();
        cout<<"\n\t1. Eliminar ";
        cout<<"\n\t0. Salir ";
        cout<<endl;
        int opc = UserChoose();
        cout<<endl;
        switch(opc) {
        case 1: {
            cout<<"Para confirmar ingrese de nuevo el número de cliente: "; int y; cin>>y;
            if(y == c) {
                if(modificarDelArchivo(posicion)) cout<<"Se eliminó correctamente del archivo. "<<endl;
                else Error(5).print();
            }
            break;
        default: break;
        }
        }
    }
};

#endif // CLIENTES_H_INCLUDED
