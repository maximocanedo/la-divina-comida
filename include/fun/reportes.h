#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED


// Máximo Canedo
int recaudacionEnBebidasAlcoholicas();
int recaudacionAFIPTodasSucursales();
int recaudacionCasados();
int sucursalesQueRecaudaronCashPorVentaDeAlcoholEnLaDecada2010();
int cantMozosQueAtendieronAClientesSolterosEnJueves();
// Juan Ríos

// Gabriel Baigorria




int recaudacionEnBebidasAlcoholicas() {
    Venta obj; int pos = 0; float rec = 0;
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado()) {
            Bebida * bbs = obj.getBebidas();
            for(int i = 0; i < obj.getCantidadDeBebidas(); i++) {
                if(bbs[i].getEstado() && bbs[i].contieneAlcohol()) rec += bbs[i].getPrecio();
            }
        }
    }
    cout<<"La recaudación total en bebidas con alcohol es de $"<<rec<<". "<<endl;
    return 0;
}
int recaudacionAFIPTodasSucursales() {
    Venta obj; int pos = 0; float rec = 0;
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado()) {
            rec += obj.getImpuestos();
        }
    }
    cout<<"\n Los impuestos recaudados en total por todas las sucursales son: $"<<rec<<". "<<endl;
    return 0;
}
int recaudacionCasados() {
    Venta obj; int pos = 0; float rec = 0;
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado()) {
            Cliente aux = obj.getCliente();
            if(aux.getEstadoCivil() == 1) rec += obj.getTotal();
        }
    }
    cout<<"\n La recaudación entre clientes casados fue de $"<<rec<<". "<<endl;
    return 0;
}
int sucursalesQueRecaudaronCashPorVentaDeAlcoholEnLaDecada2010() {
    Venta obj; int pos = 0, cuentaSucursales = 0;
    while(obj.leerDeArchivo(pos++)) {
        bool esActivo = obj.getEstado()
           , pagoEnEfectivo = (obj.getMedioDePago() == 0)
           , ocurrioEnDecada2010 = (obj.getFechaOperacion()).happensBetween(Date{1, 1, 2010}, Date{31, 12, 2019, 23, 59});
        bool esElegible = esActivo && pagoEnEfectivo && ocurrioEnDecada2010;
        if(esElegible) {
            bool vendioAlcohol = false;
            Bebida * bbs = obj.getBebidas();
            for(int i = 0; i < 48; i++) {
                if(bbs[i].contieneAlcohol())
                    vendioAlcohol = true;
            }
            if(vendioAlcohol) {
                Sucursal ob;
                ob = obj.getSucursal();
                ob.Mostrar();
                cuentaSucursales++;
            }
        }
    }
    cout<<"Mostrando "<<cuentaSucursales<<" registros... "<<endl;
    return 0;
}
int cantMozosQueAtendieronAClientesSolterosEnJueves() {
    int mozosResultado = 0, pos = 0;
    Mozo o;
    int maxlength = o.getNextIndex();
    bool * mozos;
    mozos = new bool[maxlength];
    if(mozos == NULL) {
        cout<<"Error asignando memoria. "<<endl;
        return 0;
    }
    for(int i = 0; i < maxlength; i++) mozos[i] = false;
    Venta obj;
    while(obj.leerDeArchivo(pos++)) {
        bool estaActivo = obj.getEstado()
           , ocurrioEnJueves = ((obj.getFechaOperacion()).getDay() == 4)
           , elClienteEsSoltero = ((obj.getCliente()).getEstadoCivil() == 0);

        if(estaActivo && ocurrioEnJueves && elClienteEsSoltero) {
            mozos[obj.getCodigoMozo() - 1] = true;
            // obj.Mostrar(); (obj.getCliente()).Mostrar(); // Para fines de verificación.
        }

    }
    for(int i = 0; i < maxlength; i++) {
        if(mozos[i]) mozosResultado++;
    }
    cout<<"En total, "<<mozosResultado<<" mozos atendieron a clientes solteros un jueves. "<<endl;
    return 0;
}


#endif // REPORTES_H_INCLUDED
