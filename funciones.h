

void registro::mostrarRegistro()
{
	cout<<"Identificador: "<<identificador<<endl;
	cout<<"Fecha: "<<fecha<<endl;
}

void transaccion::mostrarTransaccion()
{
	mostrarRegistro();
	cout<<"Producto: "<<producto<<endl;
}

void compra::mostrarCompra()
{
	cout<<"Factura: "<<identificador<<endl;
	cout<<"Fecha: "<<fecha<<endl;
	cout<<"Proveedor: "<<proveedor<<endl;
	cout<<"Guia de Remitente: "<<guia_remitente<<endl;
	cout<<"Guia de Transportista: "<<guia_transportista<<endl;
	cout<<"Producto: "<<producto<<endl;
	cout<<"Cantidad (unitario/kg): "<<cantidad_compra<<endl;
	cout<<"Precio Total: "<<precio_compra<<endl;
}

void venta::mostrarVenta()
{
	cout<<"Boleta: "<<identificador<<endl;
	cout<<"Fecha: "<<fecha<<endl;
	cout<<"Producto: "<<producto<<endl;
	cout<<"Valor Unitario: "<<cantidad_venta<<endl;
	cout<<"Igv: "<<igv<<endl;
	cout<<"Precio Total: "<<precio_venta<<endl;
}

void cliente::mostrarCliente()
{
	cout<<"Dni: "<<identificador<<endl;
	cout<<"Fecha de Registro: "<<fecha<<endl;
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Telefono: "<<telefono<<endl;
	cout<<"Domicilio: "<<domicilio<<endl;
}

