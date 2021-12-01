#include <string>
using namespace std;

class cliente : public registro
{
	public:
	//atributos
	string nombre;
	string telefono;
	string domicilio;
	
	//constructor
	cliente(int,string,string,string,string);
	//destructor
	~cliente();
	
	void mostrarCliente();
	
	//void escribir_registro_clientes();
	//void leer_registro_clientes();
	//void registro_especifico_cliente();
	
	// void MenuVendedor();
	// void MenuRegistroEspecifico();
	// void MenuRegistroGeneral();
	
	//Gets
    string getNombre(){return nombre;}
    string getTelefono(){return telefono;}
    string getDomicilio(){return domicilio;}
	
	//sets
    void setProductoVenta(string _nombre){nombre = _nombre;}
    void setCantidadVenta(string _telefono){telefono = _telefono;}
    void setValorU(string _domicilio){domicilio = _domicilio;}

};


//constructor de cliente 
cliente::cliente(int _identificador,string _fecha,string _nombre,string _telefono,string _domicilio) : registro(_identificador,_fecha)
{
    nombre = _nombre;
    telefono = _telefono;
    domicilio = _domicilio;
}



//destructor
cliente::~cliente(){
}