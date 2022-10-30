#ifndef BEBIDAS_H_INCLUDED
#define BEBIDAS_H_INCLUDED

class Bebida {
private:
    int codigo;
    char nombre[40];
    float precio;
    bool tieneAlcohol;
    bool tieneAzucar;
    bool estado = false;
public:
    /* Gets */
    int getCodigo() {return codigo;}
    const char * getNombre() {return nombre;}
    float getPrecio() {return precio;}
    bool contieneAlcohol() {return tieneAlcohol;}
    bool contieneAzucar() {return tieneAzucar;}
    bool contieneAlgo() {return (tieneAlcohol || tieneAzucar);}
    bool getEstado() {return estado;}
    /* Sets */
    void setCodigo(int c){codigo = c;}
    void setNombre(const char *n){strcpy(nombre, n);}
    bool setPrecio(float p)
    {
        if(p>0)
        {
            precio = p;
            return true;
        }
        return false;
    }
    void setAlcohol(bool a) {tieneAlcohol=a;}
    void setAzucar(bool az) {tieneAzucar=az;}
    void setEstado(bool e) {estado=e;}
    /* Cargar y Mostrar */
    void Cargar(int cod = -1)
    {
    /// Ingreso código de venta
      if(cod == -1) {
            cout<<"Ingrese código de Bebida: ";
            cin>>codigo;
        } else {
            codigo = cod;
        }
    /// Ingreso nombre de la bebida
        cout<<"Ingrese el nombre de la bebida: ";
        cargarCadena(nombre,39);
    /// Ingreso precio
        float p;
        cout<<"Ingresar el precio: ";
        cin>>p;
        if(!setPrecio(p))
        {
            cout<< "No se puede agregar un precion negativo o cero"<<endl;
            system("pause");
            return;
        }
    /// Ingreso si tiene alcohol
        char con;
        cout<<"¿Contiene Alcohol? (S/N): ";
        cin>>con;
        tieneAlcohol = ( con=='S'|| con=='s');
    /// Ingreso si tiene azucar
        char azu;
        cout<<"¿Contiene Azucar? (S/N): ";
        cin>>azu;
        tieneAzucar = ( azu=='S'|| azu=='s');
        estado=true;
    }
    void Mostrar()
    {
        if(getEstado())
        {
            cout<<"\tCodigo de Bebida: ";
            cout<<codigo<<endl;
            cout<<"\tNombre: ";
            cout<<nombre<<endl;
            cout<<"\tPrecio: ";
            cout<<precio<<endl;
            if(contieneAlgo())
                cout<<"\tContiene: "<<(tieneAlcohol?"Alcohol; ":"")<<(tieneAzucar?"Azúcar; ":"")<<endl;
            cout<<"--------------------------------------------------"<<endl;
        }
    }
    void Imprimir() {
        cout<<"\t * $"<<precio<<" · "<<nombre<<" #"<<codigo<<endl;
    }
    /* Constructores */
    Bebida(int c, const char *n="vacio", float p=0, bool t=true, bool ta=true)
    {
        codigo=c;
        strcpy(nombre,n);
        precio=p;
        tieneAlcohol=t;
        tieneAzucar=ta;
    }
    Bebida() {}
    /* Destructores */
    ~Bebida() {}
    /* Lectura y escritura de archivos */
    bool leerDeArchivo(int pos, const char * filename = "bebidas.dat") {
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
    bool escribirEnArchivo(const char * filename = "bebidas.dat") {
        FILE * archivo = fopen(filename, "ab");
        if(archivo == NULL) {
            Error(2).print();
            return false;
        }
        bool res = fwrite(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return res;
    }
    bool modificarDelArchivo(int pos, const char * filename = "bebidas.dat") {
        FILE * archivo;
        archivo = fopen(filename, "rb+");
        if(archivo == NULL) return false;
        fseek(archivo, (sizeof * this) * --pos, 0);
        bool escribio = fwrite(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return escribio;
    }
    /* Gets especiales */
    int getByCodigo(int codigoABuscar, const char * filename = "bebidas.dat") {
        int pos = 0;
        while(leerDeArchivo(pos++, filename)) {
            if(getCodigo() == codigoABuscar) return pos;
        }
        return -1;
    }
    int getByName(const char * name, const char * filename = "bebidas.dat") {
        int pos = 0;
        while(leerDeArchivo(pos++, filename)) {
            if(strcmp(getNombre(), name) == 0) return pos;
        }
        return -1;
    }
    int getNextIndex(const char * filename = "bebidas.dat") {
        int pos = 0, i = 1;
        while(leerDeArchivo(pos++, filename)) i++;
        return i;
    }
    /**/
    void Manage(int posicion) {
        Mostrar();
        cout<<"\n\t1. Cambiar nombre de la bebida.";
        cout<<"\n\t2. Cambiar precio. ";
        cout<<"\n\t3. Alternar 'Tiene Alcohol' ["<<(tieneAlcohol?"ON":"OFF")<<"]";
        cout<<"\n\t4. Alternar 'Tiene azúcar' ["<<(tieneAzucar?"ON":"OFF")<<"]";
        cout<<"\n\t5. Eliminar.";
        cout<<"\n\t0. Salir.";
        cout<<endl;
        int opc = UserChoose(false);
        cout<<endl;
        switch(opc) {
        case 1: {
                cout<<"Ingrese nuevo nombre de bebida: ";
                cargarCadena(nombre, 39);
                if(modificarDelArchivo(posicion))
                    cout<<"Los cambios se guardaron exitosamente. "<<endl;
                else cout<<"No se guardaron los cambios. "<<endl;
            break;
        }
        case 2: {
            cout<<"Ingrese el nuevo precio: $"; float tmp; cin>>tmp;
            if(setPrecio(tmp) && modificarDelArchivo(posicion)) cout<<"Los cambios se guardaron exitosamente. "<<endl;
            else cout<<"Hubo un problema. Quizá se recibió un precio menor o igual a $0 o hubo un error al intentar guardar los cambios. "<<endl;
            break;
        }
        case 3: {
            tieneAlcohol = !tieneAlcohol;
            if(modificarDelArchivo(posicion)) cout<<"Se han guardado los cambios. "<<endl;
            else Error(4).print();
            break;
        }
        case 4: {
            tieneAzucar = !tieneAzucar;
            if(modificarDelArchivo(posicion)) cout<<"Se han guardado los cambios. "<<endl;
            else Error(4).print();
            break;
        }
        case 5: {
            cout<<"Para confirmar el borrado, vuelva a ingresar el código del registro: ";
            int g; cin>>g;
            if(g == getCodigo()) {
                estado = false;
                bool b = (modificarDelArchivo(posicion));
                if(b) cout<<"\n Se ha borrado correctamente el registro. "<<endl;
            }
            break;
        }
        default: break;
        }
    }
    /* Sobrecarga de operaciones */
    void operator=(Bebida aux) {
        setCodigo(aux.codigo);
        setNombre(aux.nombre);
        setPrecio(aux.precio);
        setAlcohol(aux.tieneAlcohol);
        setAzucar(aux.tieneAzucar);
        setEstado(aux.estado);
    }
};

#endif // BEBIDAS_H_INCLUDED
