#include <string>
using namespace std;


//clases

class registro
{
    public:
	
	//atributos
	string identificador; //se usa en otras clases          //num
	string fecha; //FECHA AUTOMATICA
	
	//constructor
    registro(string,string); 
	//destructor
	~registro();
	
	void mostrarRegistro();

	
	//gets
    string getIdentificador(){return identificador;}
	string getFecha(){return fecha;}

	//sets
    void setIdentificador(string _identificador){identificador = _identificador;}
    void setFecha(string _fecha){fecha = _fecha;}

};


//constructor clase registro -abuelo-
registro::registro(string _identificador,string _fecha)
{	
	identificador = _identificador;
	fecha = _fecha;
}

//destructor
registro::~registro(){
}

void registro::mostrarRegistro()
{
	cout<<"Identificador: "<<identificador<<endl;
	cout<<"Fecha: "<<fecha<<endl;
}