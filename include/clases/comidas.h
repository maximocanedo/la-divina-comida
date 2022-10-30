/*
    En este archivo:
     * Clase Plato
*/
#ifndef COMIDAS_H_INCLUDED
#define COMIDAS_H_INCLUDED

class Plato {
private:
    int codigo;
    char nombre[72];
    int nacionalidad;
    float precio;
    int tipo; /// 0 => Desayuno, 1 => Almuerzo, 2 => Snacks, 3 => Cena, 4 => Postre
    bool tieneGluten;
    bool tieneCarne;
    bool tieneHuevo;
    bool tieneAzucar;
    bool tieneMani;
    bool tieneChocolate;
    bool estado = false;
public:
    /* Gets */
    int getCodigo() { return codigo;}
    const char * getNombre() {return nombre;}
    int getNacionalidad() {return nacionalidad;}
    float getPrecio() {return precio;}
    int getTipo() {return tipo;}
    void printTipo(bool e = false) {
        const char t[5][24] = {"Desayuno", "Almuerzo", "Snack", "Cena", "Postre"};
        cout<<t[tipo];
    }
    bool contieneGluten() {return tieneGluten;}
    bool contieneCarne() {return tieneCarne;}
    bool contieneHuevo() {return tieneHuevo;}
    bool contieneAzucar() {return tieneAzucar;}
    bool contieneMani() {return tieneMani;}
    bool contieneChocolate() {return tieneChocolate;}
    bool contieneAlgo() {
        return (tieneGluten || tieneCarne || tieneHuevo || tieneAzucar || tieneMani ||tieneChocolate);
    }
    bool getEstado() {return estado;}
    /* Sets */
    void setCodigo(int n) {codigo=n;}
    void setNombre(const char * n) {strcpy(nombre,n);}
    void setNacionalidad(int n) {nacionalidad=n;}
    bool setPrecio(float p) {
        if(p > 0) {
            precio = p;
            return true;
        }
        return false;
    }
    bool setTipo(int t) {
        if(t >= 0 && t <= 4) {
            tipo = t;
            return true;
        }
        return false;
    }
    void setGluten(bool e) {tieneGluten=e;}
    void setCarne(bool e) {tieneCarne=e;}
    void setHuevo(bool e) {tieneHuevo=e;}
    void setAzucar(bool e) {tieneAzucar=e;}
    void setMani(bool e) {tieneMani=e;}
    void setChocolate(bool e) {tieneChocolate=e;}
    void setEstado(bool e) {estado=e;}
    /* Cargar y Mostrar */
    void Cargar(int cod = -1)
    {
        if(cod==-1)
        {
            cout<< "Ingrese codigo de Plato: ";
            cin>>codigo;
        }else
            codigo=cod;
        cout<< "Ingrese el nombre del plato: ";
        cargarCadena(nombre,71);
        cout<< "Ingrese la nacionalidad: ";
        cin>>nacionalidad;
        cout<< "Ingrese el precio: $";
        cin>>precio;
        cout<< "Ingrese el tipo: (0 => Desayuno, 1 => Almuerzo, 2 => Snacks, 3 => Cena, 4 => Postre): ";
        cin>>tipo;
        char glu;
        cout<<"¿Contiene Gluten? (S/N): ";
        cin>>glu;
        tieneGluten = (glu=='S'|| glu=='s');
        char car;
        cout<<"¿Contiene Carne? (S/N): ";
        cin>>car;
        tieneCarne = (car=='S' || car=='s');
        char hue;
        cout<<"¿Contiene Huevo? (S/N): ";
        cin>>hue;
        tieneHuevo = ( hue=='S'|| hue=='s');
        char azu;
        cout<<"¿Contiene Azucar? (S/N): ";
        cin>>azu;
        tieneAzucar = ( azu=='S'|| azu=='s');
        char cho;
        cout<<"¿Contiene Chocolate? (S/N): ";
        cin>>cho;
        tieneChocolate = ( cho=='S'|| cho=='s');
        char man;
        cout<<"¿Contiene Mani? (S/N): ";
        cin>>man;
        tieneMani = ( azu=='S'|| azu=='s');

        estado=true;


    }
    void Mostrar()
    {
        if(getEstado())
        {
            cout<<"\tCodigo de Plato: ";
            cout<<codigo<<endl;
            cout<<"\tNombre: ";
            cout<<nombre<<endl;
            cout<<"\tNacionalidad: ";
            cout<<nacionalidad<<endl;
            cout<<"\tPrecio: ";
            cout<<precio<<endl;
            cout<< "\tTipo: ";
            printTipo(); cout<<endl;
            if(contieneAlgo())
                cout<<"\tContiene: "<<(tieneGluten?"Gluten; ":"")<<(tieneCarne?"Carne; ":"")<<(tieneHuevo?"Huevo; ":"")<<(tieneAzucar?"Azúcar; ":"")<<(tieneMani?"Maní; ":"")<<(tieneChocolate?"Chocolate; ":"")<<endl;
            cout<<"--------------------------------------------------"<<endl;
            /*
            if(tieneGluten==true)
            {
                cout<<"El Plato tiene Gluten"<<endl;
            }else
                cout<<"El Plato no tiene Gluten"<<endl;
            if(tieneCarne==true)
            {
                cout<<"El Plato tiene Carne"<<endl;
            }else
                cout<<"El Plato no tiene Carne"<<endl;
            if(tieneHuevo==true)
            {
                cout<<"El Plato tiene Huevo"<<endl;
            }else
                cout<<"El Plato no tiene Huevo"<<endl;
            if(tieneAzucar==true)
            {
                cout<<"El Plato tiene Azucar"<<endl;
            }else
                cout<<"El Plato no tiene Azucar"<<endl;
            if(tieneMani==true)
            {
                cout<<"El Plato tiene Mani"<<endl;
            }else
                cout<<"El Plato no tiene Mani"<<endl;
            if(tieneChocolate==true)
            {
                cout<<"El Plato tiene Chocolate"<<endl;
            }else
                cout<<"El Plato no tiene Chocolate"<<endl;
            */
        }
    }
    void Imprimir() {
        if(getEstado()) {
            cout<<"\t * $"<<precio<<" · "<<nombre<<" #"<<codigo<<endl;
        }
    }
    /* Constructores */
    Plato() {}
///    Plato() {}
    /* Destructor */
    ~Plato() {}
    /* Lectura y escritura de archivos */
    bool leerDeArchivo(int pos, const char * filename = "comidas.dat") {
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
    bool escribirEnArchivo(const char * filename = "comidas.dat") {
        FILE * archivo = fopen(filename, "ab");
        if(archivo == NULL) {
            Error(2).print();
            return false;
        }
        bool res = fwrite(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return res;
    }
    bool modificarDelArchivo(int pos, const char * filename = "comidas.dat") {
        FILE * archivo;
        archivo = fopen(filename, "rb+");
        if(archivo == NULL) return false;
        fseek(archivo, (sizeof * this) * --pos, 0);
        bool escribio = fwrite(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return escribio;
    }
    /* Gets especiales */
    int getByCodigo(int codigoABuscar, const char * filename = "comidas.dat") {
        int pos = 0;
        while(leerDeArchivo(pos++, filename)) {
            if(getEstado() && getCodigo() == codigoABuscar) return pos;
        }
        return -1;
    }
    int getByName(const char * name, const char * filename = "comidas.dat") {
        int pos = 0;
        while(leerDeArchivo(pos++, filename)) {
            if(getEstado() && strcmp(getNombre(), name) == 0) return pos;
        }
        return -1;
    }
    int getNextIndex(const char * filename = "comidas.dat") {
        int pos = 0, e = 1;
        while(leerDeArchivo(pos++, filename))
            e++;
        return e;
    }
    /* Sobrecarga de operaciones */
    void operator=(Plato aux) {
        codigo = aux.codigo;
        strcpy(nombre, aux.nombre);
        nacionalidad = aux.nacionalidad;
        precio = aux.precio;
        tipo = aux.tipo;
        tieneGluten = aux.tieneGluten;
        tieneCarne = aux.tieneCarne;
        tieneHuevo = aux.tieneHuevo;
        tieneAzucar = aux.tieneAzucar;
        tieneMani = aux.tieneMani;
        tieneChocolate = aux.tieneChocolate;
        estado = aux.estado;
    }
    void Manage(int posicion) {
        int c = getCodigo();
        Mostrar();
        cout<<"\n\t1. Cambiar nombre";
        cout<<"\n\t2. Cambiar nacionalidad";
        cout<<"\n\t3. Cambiar precio";
        cout<<"\n\t4. Cambiar tipo de plato";
        cout<<"\n\t5. Alternar Gluten ["<<(tieneGluten?"ON":"OFF")<<"]";
        cout<<"\n\t6. Alternar Carne ["<<(tieneCarne?"ON":"OFF")<<"]";
        cout<<"\n\t7. Alternar Huevo ["<<(tieneHuevo?"ON":"OFF")<<"]";
        cout<<"\n\t8. Alternar Azúcar ["<<(tieneAzucar?"ON":"OFF")<<"]";
        cout<<"\n\t9. Alternar Maní ["<<(tieneMani?"ON":"OFF")<<"]";
        cout<<"\n\t10. Alternar Chocolate ["<<(tieneChocolate?"ON":"OFF")<<"]";
        cout<<"\n\t11. Eliminar de los registros";
        cout<<endl;
        int opc = UserChoose(false);
        cout<<endl;
        bool esNecesarioModificarElArchivo = false;
        switch(opc) {
        case 1: {
            cout<<"Ingrese nombre: ";
            cargarCadena(nombre, 71);
            esNecesarioModificarElArchivo = true;
            break;
        }
        case 2: {
            cout<<"Ingrese nueva nacionalidad: "; int n; cin>>n;
            setNacionalidad(n);
            esNecesarioModificarElArchivo = true;
            break;
        }
        case 3: {
            cout<<"Ingrese nuevo precio: $"; float p; cin>>p;
            if(setPrecio(p)) {
                esNecesarioModificarElArchivo = true;
            } else {
                cout<<"El precio ingresado es inadmisible. "<<endl;
            }
            break;
        }
        case 4: {
            cout<<"Ingrese tipo de plato: "; int y; cin>>y;
            if(setTipo(y)) esNecesarioModificarElArchivo = true;
            else Error(0).print();
            break;
        }
        case 5: {
            tieneGluten = !tieneGluten;
            esNecesarioModificarElArchivo = true;
            break;
        }
        case 6: {
            tieneCarne = !tieneCarne;
            esNecesarioModificarElArchivo = true;
            break;
        }
        case 7: {
            tieneHuevo = !tieneHuevo;
            esNecesarioModificarElArchivo = true;
            break;
        }
        case 8: {
            tieneAzucar = !tieneAzucar;
            esNecesarioModificarElArchivo = true;
            break;
        }
        case 9: {
            tieneMani = !tieneMani;
            esNecesarioModificarElArchivo = true;
            break;
        }
        case 10:{
            tieneChocolate = !tieneChocolate;
            esNecesarioModificarElArchivo = true;
            break;
        }
        case 11:{
            cout<<"Para confirmar ingrese el código del plato: "; int e; cin>>e;
            if(e == getCodigo()) {
                setEstado(false);
                esNecesarioModificarElArchivo = true;
            }
            break;
        }
        default: {break;}
        }
        if(esNecesarioModificarElArchivo) {
            if(modificarDelArchivo(posicion)) {
                cout<<"Los cambios se modificaron exitosamente en el archivo. "<<endl;
            } else Error(0).print();
        }
    }
};

#endif // COMIDAS_H_INCLUDED
