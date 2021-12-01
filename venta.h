#include <string>
using namespace std;

class venta : public transaccion
{
	public:
	//atributos
	
	double cantidad_venta;
	double valor_u;
	double igv;
	double precio_venta;
	
	//constructor
	venta(int,string,string,double,double,double,double);
	//destructor
	~venta();
	
	void mostrarVenta();
	
	//Gets

    double getCantidadVenta(){return cantidad_venta;}
    double getValorU(){return valor_u;}
    double getIgv(){return igv;}
    double getPrecioVenta(){return precio_venta;}
	
	//sets

    void setCantidadVenta(double _cantidad_venta){cantidad_venta = _cantidad_venta;}
    void setValorU(double _valor_u){valor_u = _valor_u;}
    void setIgv(double _igv){igv = _igv;}
    void setPrecioVenta(double _precio_venta){precio_venta = _precio_venta;}
	
};



//constructor de venta 
venta::venta(int _identificador,string _fecha,string _producto,double _cantidad_venta,double _valor_u,double _igv,double _precio_venta) : transaccion(_identificador,_fecha,_producto)
{

    cantidad_venta = _cantidad_venta;
    valor_u = _valor_u;
    igv = _igv;
    precio_venta = _precio_venta;
}


//destructor
venta::~venta(){
}