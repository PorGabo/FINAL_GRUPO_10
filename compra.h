#include <string>
using namespace std;

class compra : public transaccion
{
	private: //no hay clases hijas que usen variables
	//atributos
	string proveedor;
	string guia_remitente; //num
	string guia_transportista; //num
	double cantidad_compra;
	double precio_compra;
	
	public:
	//constructor
	compra(string,string,string,string,string,string,double,double);
	//destructor
	~compra();
	
	void mostrarCompra();
	
	//Gets
    string getProveedor(){return proveedor;}
    string getGuiaRemitente(){return guia_remitente;}
    string getGuiaTransportista(){return guia_transportista;}
    double getCantidadCompra(){return cantidad_compra;}
    double getPrecioCompra(){return precio_compra;}
	
	//sets

    void setProveedor(string _Proveedor){proveedor = _Proveedor;}
    void setGuiaRemitente(string _GuiaRemitente){guia_remitente = _GuiaRemitente;}
    void setGuiaTransportista(string _GuiaTransportista){guia_transportista = _GuiaTransportista;}
    void setCantidadCompra(double _CantidadCompra){cantidad_compra = _CantidadCompra;}
    void setPrecioCompra(double _PrecioCompra){precio_compra = _PrecioCompra;}
};

//constructor de compra 
compra::compra(string _identificador,string _fecha,string _producto,string _proveedor,string _guia_remitente,string _guia_transportista,double _cantidad_compra,double _precio_compra) : transaccion(_identificador,_fecha,_producto)
{
	proveedor = _proveedor;
    guia_remitente = _guia_remitente;
    guia_transportista = _guia_transportista;
    cantidad_compra = _cantidad_compra;
    precio_compra = _precio_compra;
}

//destructor
compra::~compra(){
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