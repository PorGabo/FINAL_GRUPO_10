#include <string>
using namespace std;

class transaccion : public registro
{
	public:
	//atributos
	string producto;
	
	//constructor
	transaccion(int,string,string);
	
	//destructor
	~transaccion();
	
	void mostrarTransaccion();
	
	//Gets
    string getProducto(){return producto;}

	//sets
    void setProducto(string _Producto){producto = _Producto;}

};

//constructor de compra 
transaccion::transaccion(int _identificador,string _fecha,string _producto) : registro(_identificador,_fecha)
{
    producto = _producto;
}

//destructor
transaccion::~transaccion(){
}



