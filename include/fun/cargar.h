/*
    En este archivo:
     * Funciones de carga de datos manual
*/
#ifndef CARGAR_H_INCLUDED
#define CARGAR_H_INCLUDED

int cargarMozos();
int cargarComidas();
int cargarBebidas();
int cargarClientes();
int cargarVentas();

int cargarMozos() {
    int regs = aCargar();
    for(int i = 0; i < regs; i++) {
        Mozo miMozo, aux;
        int n = aux.getNextIndex();
        miMozo.Cargar(n);
        if(miMozo.escribirEnArchivo()) {
            cout<<"Se escribió correctamente en el archivo. "<<endl;
        }
        cout<<endl;
    }
    return 0;
}
int cargarSucursales() {
    int regs = aCargar();
    for(int i = 0; i < regs; i++) {
        Sucursal miSucu, aux;
        int n = aux.getNextIndex();
        miSucu.Cargar(n);
        if(miSucu.escribirEnArchivo()) {
            cout<<"Se escribió correctamente en el archivo. "<<endl;
        }
        cout<<endl;
    }
    return 0;
}
int cargarComidas() {
    int regs = aCargar();
    for(int i = 0; i < regs; i++) {
        Plato miPlato, aux;
        int n = aux.getNextIndex();
        miPlato.Cargar(n);
        if(miPlato.escribirEnArchivo()) {
            cout<<"Se escribió correctamente en el archivo. "<<endl;
        }
        cout<<endl;
    }
    return 0;
}
int cargarBebidas() {
    int regs = aCargar();
    for(int i = 0; i < regs; i++) {
        Bebida miBebida, aux;
        int n = aux.getNextIndex();
        miBebida.Cargar(n);
        if(miBebida.escribirEnArchivo())
            cout<<"Se escribió correctamente en el archivo. "<<endl;
        cout<<endl;
    }
    return 0;
}
int cargarClientes() {
    int regs = aCargar();
    for(int i = 0; i < regs; i++) {
        Cliente miCliente, aux;
        int n = aux.getNextIndex();
        miCliente.Cargar(n);
        if(miCliente.escribirEnArchivo()) {
            cout<<"Se escribió correctamente en el archivo. "<<endl;
        }
        cout<<endl;
    }
    return 0;
}
int cargarVentas() {
    int regs = aCargar();
    for(int i = 0; i < regs; i++) {
        Venta miVenta, aux;
        int id = aux.getNextIndex();
        miVenta.Cargar(id);
        if(miVenta.escribirEnArchivo()) {
            cout<<"Se escribió correctamente en el archivo. "<<endl;
        }
        cout<<endl;
    }
    return 0;
}

#endif // CARGAR_H_INCLUDED
