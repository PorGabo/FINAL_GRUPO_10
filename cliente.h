#include <string>
using namespace std;

class cliente : public registro
{
	private:
	//atributos
	string nombre;
	string telefono; //num (x el momento)
	string domicilio;	
	
	public:
	//constructor
	cliente(string,string,string,string,string);
	//destructor
	~cliente();
	
	void mostrarCliente();
	
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
cliente::cliente(string _identificador,string _fecha,string _nombre,string _telefono,string _domicilio) : registro(_identificador,_fecha)
{
    nombre = _nombre;
    telefono = _telefono;
    domicilio = _domicilio;
}



//destructor
cliente::~cliente(){
}


void cliente::mostrarCliente()
{
	cout<<"Dni: "<<identificador<<endl;
	cout<<"Fecha de Registro: "<<fecha<<endl;
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Telefono: "<<telefono<<endl;
	cout<<"Domicilio: "<<domicilio<<endl;
}