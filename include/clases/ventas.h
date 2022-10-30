/*
    En este archivo:
     * Clase Venta
     * Responsable: M�ximo Canedo
*/
#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED



class Venta {
private:
    int codigo;
    Plato platos[48];
    Bebida bebidas[48];
    int cantidadPlatos;
    int cantidadBebidas;
    int codCliente;
    int codSucursal;
    int codMozo;
    float neto = 0;
    float impuestos = 0;
    float total = 0;
    int medioDePago; // 0 => Efectivo, 1 => Tarjeta de cr�dito/d�bito, 2 => Transferencia bancaria, 3 => Cheque, 4 => Pagar�
    Date fechaDeLaOperacion;
    bool estado;
public:
    /* C�lculos internos */
    void calcularNeto() {
        for(int i = 0; i < cantidadPlatos; i++) {
            neto += (platos[i].getEstado() ? platos[i].getPrecio() : 0);
            if(platos[i].getEstado()) {
                cout<<"Precio plato #"<<i<<": $"<<platos[i].getPrecio()<<endl;
                cout<<"+> $"<<neto<<". "<<endl;
            } //*/
        }
        for(int i = 0; i < cantidadBebidas; i++) {
            neto += (bebidas[i].getEstado() ? bebidas[i].getPrecio() : 0);
            if(bebidas[i].getEstado()) {
                cout<<"Precio bebida #"<<i<<": $"<<bebidas[i].getPrecio()<<endl;
                cout<<"+> $"<<neto<<". "<<endl;
            } //*/
        }
    }
    void aplicarImpuesto(float porcentaje) { // Porcentajes del 0 al 100 (y m�s all�)
        impuestos = (neto * (porcentaje / 100));
    }
    void calcularTotal() {
        total = neto + impuestos;
    }
    /* Gets */
    int getCodigo() {return codigo;}
    Plato * getPlatos() {return platos;}
    Bebida * getBebidas() {return bebidas;}
    int getCantidadDePlatos() {return cantidadPlatos;}
    int getCantidadDeBebidas() {return cantidadBebidas;}
    int getNumeroCliente() {return codCliente;}
    int getCodigoSucursal() {return codSucursal;}
    int getCodigoMozo() {return codMozo;}
    Cliente getCliente() {
        Cliente aux;
        aux.getByNumeroCliente(codCliente);
        return aux;
    }
    Sucursal getSucursal() {
        Sucursal aux;
        aux.getByCodigo(codSucursal);
        return aux;
    }
    Mozo getMozo() {
        Mozo aux;
        aux.getByCodigo(codMozo);
        return aux;
    }
    float getNeto() {return neto;}
    float getImpuestos() {return impuestos;}
    float getTotal() {return total;}
    int getMedioDePago() {return medioDePago;}
    void printMedioDePago() {
        char mediosDePago[5][24] = {
            "Efectivo", "Tarjeta", "Transferencia", "Cheque", "Pagar�"
        };
        cout<<mediosDePago[medioDePago];
    }
    Date getFechaOperacion() {return fechaDeLaOperacion;}
    bool getEstado() {return estado;}
    /* Sets */
    void setCodigo(int n) {codigo = n;}
    void setPlatos(Plato * n) {
        for(int i = 0; i < 48; i++) {
            Plato aux;
            aux.getByCodigo(n[i].getCodigo());
            if(aux.getEstado()) {
                cantidadPlatos++;
                platos[i] = n[i];
            }
        }
    }
    void setBebidas(Bebida * n) {
        for(int i = 0; i < 48; i++) {
            Bebida aux;
            aux.getByCodigo(n[i].getCodigo());
            if(n[i].getEstado()) {
                cantidadBebidas++;
                bebidas[i] = n[i];
            }
        }
    }
    bool setCliente(int c) {
        Cliente aux;
        int y = aux.getByNumeroCliente(c);
        if(y != -1) {
            codCliente = c;
            return true;
        } else return false;
    }
    bool setSucursal(int c) {
        Sucursal aux;
        int y = aux.getByCodigo(c);
        if(y != -1) {
            codSucursal = c;
            return true;
        } else return false;
    }
    bool setMozo(int c) {
        Mozo aux;
        int y = aux.getByCodigo(c);
        if(y != -1) {
            codMozo = c;
            return true;
        } else return false;
    }
    void setNeto(float n) {neto = n;}
    void setImpuestos(float n) {impuestos = n;}
    void setTotal(float n) {total = n;}
    void setMedioDePago(int t) {medioDePago = t % 5;}
    void setFechaOperacion(Date n) {fechaDeLaOperacion.copyFrom(n);}
    void setEstado(bool n) {estado = n;}
    /* Cargar y Mostrar */
    void Cargar(int n = -1) {

        // Ingreso c�digo de venta
        if(n == -1) {
            cout<<"Ingrese c�digo de venta: "; cin>>codigo;
        } else {
            codigo = n;
            cout<<"(C�digo de venta: "<<n<<"). "<<endl;
        }

        // Ingreso de los platos
        int c; Plato aux; int i = 0; cantidadPlatos = 0;
        cout<<endl<<"[PLATOS]"<<endl;
        cout<<"Ingrese c�digo de comida (0 para finalizar carga de comidas): "; cin>>c;
        while(c > 0 && i < 48) {
            int p = aux.getByCodigo(c);
            if(p != -1) {
                platos[i] = aux;
                cantidadPlatos++;
                platos[i].Imprimir();
                cout<<endl;
                i++;
            }
            cout<<"Ingrese c�digo de comida (0 para finalizar carga de comidas): "; cin>>c;
        }

        // Ingreso de las bebidas
        int bb; Bebida x; i = 0; cantidadBebidas = 0;
        cout<<endl<<"[BEBIDAS]"<<endl;
        cout<<"Ingrese c�digo de bebida (0 para finalizar carga de bebidas): "; cin>>bb;
        while(bb > 0 && i < 48) {
            int p = x.getByCodigo(bb);
            if(p != -1) {
                bebidas[i] = x;
                cantidadBebidas++;
                bebidas[i].Imprimir();
                cout<<endl;
                i++;
            }
            cout<<"Ingrese c�digo de bebida (0 para finalizar carga de bebidas): "; cin>>bb;
        }

        // Ingreso del cliente que realiz� la compra
        bool clienteIncorrecto = true;
        while(clienteIncorrecto) {
            cout<<"Ingrese n�mero de cliente: "; int c; cin>>c;
            Cliente aux;
            if(aux.getByNumeroCliente(c) == -1) {
                cout<<"El c�digo ingresado no corresponde con ning�n registro. Intente de nuevo. "<<endl;
            } else {
                cout<<endl<<"El c�digo corresponde al cliente "<<aux.getApellido()<<", "<<aux.getNombre()<<". "<<endl;
                codCliente = c;
                clienteIncorrecto = false;
            }
        }

        // Ingreso de la sucursal d�nde se realiz� la compra e informar qui�nes son los mozos que trabajan all�.
        bool sucursalIncorrecta = true;
        while(sucursalIncorrecta) {
            cout<<"Ingrese n�mero de sucursal: "; int sc; cin>>sc;
            if(setSucursal(sc)) {
                sucursalIncorrecta = false;
                cout<<"Sucursal correcta. Mozos que trabajan ac�: ";
                int pd = 0; Mozo au;
                while(au.leerDeArchivo(pd++)) {
                    if(au.getEstado() && au.getCodigoSucursal() == sc) cout<<"#"<<au.getCodigo()<<"; ";
                }
                cout<<endl;
            } else {
                cout<<"La sucursal ingresada no existe en los registros. "<<endl;
            }
        }

        // Ingreso del mozo que atendi� al cliente
        bool mozoIncorrecto = true;
        while(mozoIncorrecto) {
            cout<<"Ingrese c�digo del mozo que atendi�: "; int c; cin>>c;
            Mozo aux;
            if(aux.getByCodigo(c) == -1)
                cout<<"El c�digo ingresado no corresponde con ning�n registro. Intente de nuevo. "<<endl;
            else {
                if(aux.getCodigoSucursal() == codSucursal) {
                    cout<<endl<<"El c�digo corresponde al mozo "<<aux.getApellido()<<", "<<aux.getNombre()<<". "<<endl;
                    mozoIncorrecto = false;
                    codMozo = c;
                } else {
                    cout<<"El mozo ingresado no coincide con la sucursal de la venta. "<<endl;
                }
            }
        }

        cout<<endl<<cantidadPlatos<<" plato"<<(cantidadPlatos==1?"":"s")<<". "<<endl;
        cout<<cantidadBebidas<<" bebida"<<(cantidadBebidas == 1 ?"":"s")<<". "<<endl;

        // Se calcula el valor neto
        calcularNeto();
        cout<<endl<<"(El neto es de $"<<neto<<".)"<<endl;

        // Ingreso del % de impuestos a aplicar
        float prc;
        cout<<"Ingrese el % de impuestos a aplicar: "; cin>>prc;
        aplicarImpuesto(prc);

        // Se calcula el total
        calcularTotal();
        cout<<"(Total: $"<<total<<".)"<<endl;

        // Ingreso del medio de pago utilizado.
        cout<<"Ingrese el medio de pago utilizado: (0 = Efectivo, 1 = Tarjeta, 2 = Transferencia, 3 = Cheque, 4 = Pagar�): ";
        cin>>medioDePago;
        medioDePago %= 5;

        // Ingreso de la fecha de la operaci�n.
        cout<<"Ingrese la fecha de la operaci�n: "<<endl;
        fechaDeLaOperacion.load(true);
        estado = true;
    }
    void Mostrar() {
        if(getEstado()) {
            cout<<"\n\tC�digo de venta: "<<codigo<<". "<<endl<<endl;
            cout<<"\tPlatos: "<<endl;
            for(int i = 0; i < cantidadPlatos; i++) {
                platos[i].Imprimir();
            }
            cout<<"\tBebidas: "<<endl;
            for(int i = 0; i < cantidadBebidas; i++) {
                bebidas[i].Imprimir();
            }
            Cliente cl = getCliente();
            cout<<endl<<"\tCliente: "<<cl.getApellido()<<", "<<cl.getNombre()<<". "<<endl;
            Sucursal sc = getSucursal();
            cout<<endl<<"\tSucursal: "<<sc.getNombre()<<" (#"<<sc.getCodigo()<<"). ";
            Mozo mz = getMozo();
            cout<<"\tMozo: "<<mz.getApellido()<<", "<<mz.getNombre()<<". (#"<<codMozo<<"). "<<endl;
            cout<<endl<<"\tNeto: $"<<neto<<". "<<endl;
            cout<<"\tImpuestos: $"<<impuestos<<". "<<endl;
            cout<<"\tTotal: $"<<total<<". "<<endl;
            cout<<"\tMedio de pago utilizado: "; printMedioDePago(); cout<<". "<<endl;
            cout<<"\tFecha de operaci�n: "; fechaDeLaOperacion.print(fechaDeLaOperacion.SP_FULL, true, false); cout<<endl;
            cout<<endl<<"-------------------------------------------------------------"<<endl;
        }
    }
    /* Constructores */
    Venta() {}
    Venta(int cod, Plato * pls, Bebida * bbs, int cc, int sc, int cmz, float porcentaje_impuestos, Date fechaOperacion) {
        codigo = cod;
        setPlatos(pls);
        setBebidas(bbs);
        setCliente(cc);
        setSucursal(sc);
        setMozo(cmz);
        calcularNeto();
        aplicarImpuesto(porcentaje_impuestos);
        fechaDeLaOperacion.copyFrom(fechaOperacion);
        estado = true;
    }
    /* Destructor */
    ~Venta() {}
    /* Lectura y escritura de archivos */
    bool leerDeArchivo(int pos, const char * filename = "ventas.dat") {
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
    bool escribirEnArchivo(const char * filename = "ventas.dat") {
        FILE * archivo = fopen(filename, "ab");
        if(archivo == NULL) {
            Error(2).print();
            return false;
        }
        bool res = fwrite(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return res;
    }
    bool modificarDelArchivo(int pos, const char * filename = "ventas.dat") {
        FILE * archivo;
        archivo = fopen(filename, "rb+");
        if(archivo == NULL) return false;
        fseek(archivo, (sizeof * this) * --pos, 0);
        bool escribio = fwrite(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return escribio;
    }
    /* Gets especiales */
    int getByCodigo(int codigoABuscar, const char * filename = "ventas.dat") {
        int pos = 0;
        while(leerDeArchivo(pos++, filename)) {
            if(getEstado() && getCodigo() == codigoABuscar) return pos;
        }
        return -1;
    }
    int getNextIndex(const char * filename = "ventas.dat") {
        int pos = 0, e = 1;
        while(leerDeArchivo(pos++, filename))
            e++;
        return e;
    }
};

#endif // VENTAS_H_INCLUDED
