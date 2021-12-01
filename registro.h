#include <string>
using namespace std;


//clases

class registro
{
    public:
	
	//atributos
	int identificador; //protected?
	string fecha; //protected?
	
	//constructor
    registro(int,string); 
	//destructor
	~registro();
	
	void mostrarRegistro();

	
	//gets
    int getIdentificador(){return identificador;}
	string getFecha(){return fecha;}

	//sets
    void setIdentificador(int _identificador){identificador = _identificador;}
    void setFecha(string _fecha){fecha = _fecha;}

};


//constructor clase registro -padre-
registro::registro(int _identificador,string _fecha)
{	
	identificador = _identificador;
	fecha = _fecha;
}

//destructor
registro::~registro(){
}

