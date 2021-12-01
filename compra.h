#include <string>
using namespace std;

class compra : public transaccion
{
	public:
	//atributos

	string proveedor;
	int guia_remitente;
	int guia_transportista;
	double cantidad_compra;
	double precio_compra;
	
	//constructor
	compra(int,string,string,string,int,int,double,double);
	//destructor
	~compra();
	
	void mostrarCompra();
	
	
	//Gets
	
    string getProveedor(){return proveedor;}
    int getGuiaRemitente(){return guia_remitente;}
    int getGuiaTransportista(){return guia_transportista;}
    double getCantidadCompra(){return cantidad_compra;}
    double getPrecioCompra(){return precio_compra;}
	
	//sets

    void setProveedor(string _Proveedor){proveedor = _Proveedor;}
    void setGuiaRemitente(int _GuiaRemitente){guia_remitente = _GuiaRemitente;}
    void setGuiaTransportista(int _GuiaTransportista){guia_transportista = _GuiaTransportista;}
    void setCantidadCompra(double _CantidadCompra){cantidad_compra = _CantidadCompra;}
    void setPrecioCompra(double _PrecioCompra){precio_compra = _PrecioCompra;}
};

//constructor de compra 
compra::compra(int _identificador,string _fecha,string _producto,string _proveedor,int _guia_remitente,int _guia_transportista,double _cantidad_compra,double _precio_compra) : transaccion(_identificador,_fecha,_producto)
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