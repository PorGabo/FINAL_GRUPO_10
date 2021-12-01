#include <string>

using namespace std;

void pausa();
void pausaFin();

//atoy?

class Menu{
    public:
    compra **com;
    venta **ven;
	cliente **clien;
	int num_compras,num_ventas,num_clientes, n_elements;
	
	//referentes para funciones lectura
	string l_id,l_fecha,l_producto,l_proveedor,l_g_remitente,l_g_transportista,l_cantidad,l_valor_u,l_igv,l_precio,l_nombre,l_telefono,l_domicilio,l_espacio,nulo = "";
	
	//constructor
	Menu();
	//destructor
	~Menu();
	
	//menus
	void MenuPrincipal();
	void MenuAdministrador();
	void MenuVendedor();
	void MenuRegistroGeneral();
	void MenuRegistroEspecifico();
	
	//guardar: memoria --> txt y delete memoria
	void guardar_compras();
	void guardar_ventas();
	void guardar_clientes();
	void guardar_datos();
	
	//ingresa a memoria , if memoria llena guarda
	void escribir_registro_compras();
	void escribir_registro_ventas();
	void escribir_registro_clientes();
	
	void leer_registro_compras();
	void leer_registro_ventas();
	void leer_registro_clientes();
	
	void registro_especifico_compra();
	void registro_especifico_venta();
	void registro_especifico_cliente();
	
};

//constructor de Menu 
Menu::Menu()
{
	n_elements = 20; //cantidad de elementos para tener en memoria (aplicable para las 3 memorias)
    //contadores para cada arreglo
	num_compras=0;
	num_ventas=0;
	num_clientes=0;
	
	//declaramos los arreglos
	com = new compra *[n_elements];  // *{ * , *, * ,*};
	ven = new venta *[n_elements];
	clien = new cliente *[n_elements];
	
}

//destructor
Menu::~Menu(){
	for(int i=0; i<num_compras; i++){
		delete com[i];
	}
	for(int i=0; i<num_ventas; i++){
		delete ven[i];
	}
	for(int i=0; i<num_clientes; i++){
		delete clien[i];
	}
	delete []com;
	delete []ven;
	delete []clien;
}




//MENUS

void Menu::MenuPrincipal()
{
	system("CLS");
	cout<<"\n----------------------Bienvenido al Sistema----------------------\n\n\n";
	cout<<"Menu Principal\n\n";
	
	string opcion;
	cout<<"1. Modo administrador \n";
	cout<<"2. Modo vendedor \n";
	cout<<"3. Salir \n\n";
	cout<<"Opcion: ";
	cin>>opcion;//cambiar
	cout<<"\n\n\n";
	
	if (opcion=="1")
	{
		cout<<"Selecciono opcion 1 \n\n\n";
		MenuAdministrador();
	}
	
	else if (opcion=="2")
	{
		cout<<"Selecciono opcion 2 \n\n\n";
		MenuVendedor();
	}
	
	else if (opcion=="3")
	{
		cout<<"Saliendo ... \n\n\n";
		guardar_datos();
		//cada vez que guardo creo un espacio nuevo, asi que...
		delete []com;
		delete []ven;
		delete []clien;
		//cerrar programa
		exit(0);
	}
	
	else
	{
		cout<<"Comando no valido ... \n\n\n";
		pausa();
		MenuPrincipal();
	}
}

void Menu::MenuAdministrador()        
{
	system("CLS");
	cout<<"Menu Principal < Menu Administrador \n\n";
	
	string opcion;
	cout<<"1. Ingresar Compra \n";
	cout<<"2. Visualizar Registros Generales\n";
	cout<<"3. Visualizar Registros Especificos\n";
	cout<<"4. Retroceder\n\n";
	cout<<"Opcion: ";
	cin>>opcion;
	cout<<"\n\n\n";
	
	
	if (opcion=="1")
	{
		cout<<"Selecciono opcion 1 \n\n\n";
		//funcion modo administrador
		system("CLS");
		cout<<"Menu Principal < Menu Administrador < Ingresar Compra\n\n";
		
		escribir_registro_compras();
		MenuAdministrador();
	}
	
	else if (opcion=="2")
	{
		cout<<"Selecciono opcion 2 \n\n\n";
		//funcion visualizar historial de compras
		
		MenuRegistroGeneral();
		MenuAdministrador();
	}
	
	else if (opcion=="3")
	{
		cout<<"Selecciono opcion 3 \n\n\n";
		//menu de registros específicos
		
		MenuRegistroEspecifico();
		MenuAdministrador();
	}
	
	else if (opcion=="4")
	{
		cout<<"Retrocediendo ...\n\n\n";
		MenuPrincipal();
	}
	
	else{
		cout<<"Comando no valido ... \n\n\n";
		pausa();
		MenuAdministrador();
	}
}

void Menu::MenuVendedor()
{
	system("CLS");
	
	cout<<"Menu Principal < Menu Vendedor \n\n";
	string opcion;
	cout<<"1. Ingresar Venta \n";
	cout<<"2. Ingresar Cliente \n";
	cout<<"3. Retroceder \n\n";
	cout<<"Opcion: ";
	cin>>opcion;
	cout<<"\n\n\n";
	
	if (opcion=="1")
	{
		cout<<"Selecciono opcion 1 \n\n\n"; 
		system("CLS");
		cout<<"Menu Principal < Menu Vendedor < Ingresar Venta\n\n";
		escribir_registro_ventas();
		MenuVendedor();
	}
	
	else if (opcion=="2")
	{
		cout<<"Selecciono opcion 2 \n\n\n";
		system("CLS");
		cout<<"Menu Principal < Menu Vendedor < Ingresar Cliente\n\n";
		escribir_registro_clientes();
		MenuVendedor();
	}
	
	else if (opcion=="3")
	{
		cout<<"Retrocediendo ...\n\n\n";
		MenuPrincipal();
	}
	
	else{
		cout<<"Comando no valido ... \n\n\n";
		pausa();
		MenuVendedor();
	}
}

void Menu::MenuRegistroEspecifico()        
{
	system("CLS");
	cout<<"Menu Principal < Menu Administrador < Visualizar Registros Especificos\n\n";
	
	string opcion;
	cout<<"1. Registro especifico de Compra\n";
	cout<<"2. Registro especifico de Venta\n";
	cout<<"3. Registro especifico de Cliente\n";
	cout<<"4. Retroceder\n\n";
	cout<<"Opcion: ";
	cin>>opcion;
	cout<<"\n\n\n";
	
	
	if (opcion=="1")
	{
		cout<<"Selecciono opcion 1 \n\n\n";
		//funcion visualizar registro especifico de compra
		system("CLS");
		cout<<"Menu Principal < Menu Administrador < Visualizar Registros Especificos < compra\n\n";
		registro_especifico_compra();
		MenuRegistroEspecifico();
	}
	
	else if (opcion=="2")
	{
		cout<<"Selecciono opcion 2 \n\n\n";
		//funcion visualizar registro especifico de venta
		system("CLS");
		cout<<"Menu Principal < Menu Administrador < Visualizar Registros Especificos < venta\n\n";
		registro_especifico_venta();
		MenuRegistroEspecifico();
	}
	
	else if (opcion=="3")
	{
		cout<<"Selecciono opcion 3 \n\n\n";
		//funcion visualizar registro especifico de cliente
		system("CLS");
		cout<<"Menu Principal < Menu Administrador < Visualizar Registros Especificos < cliente\n\n";
		registro_especifico_cliente();
		MenuRegistroEspecifico();
	}
	
	else if (opcion=="4")
	{
		cout<<"Retrocediendo ...\n\n\n";
		MenuAdministrador();
	}
	
	else{
		cout<<"Comando no valido ... \n\n\n";
		pausa();
		MenuRegistroEspecifico();
	}
}

void Menu::MenuRegistroGeneral()
{
	system("CLS");
	cout<<"Menu Principal < Menu Administrador < Visualizar Registros Generales\n\n";
	
	string opcion;
	cout<<"1. Registro General de Compra\n";
	cout<<"2. Registro General de Venta\n";
	cout<<"3. Registro General de Cliente\n";
	cout<<"4. Retroceder\n\n";
	cout<<"Opcion: ";
	cin>>opcion;
	cout<<"\n\n\n";
	
	
	if (opcion=="1")
	{
		cout<<"Selecciono opcion 1 \n\n\n";
		//funcion visualizar registro especifico de compra
		system("CLS");
		cout<<"Menu Principal < Menu Administrador < Visualizar Registros Generales < compras\n\n";
		leer_registro_compras();
		MenuRegistroGeneral();
	}
	
	else if (opcion=="2")
	{
		cout<<"Selecciono opcion 2 \n\n\n";
		//funcion visualizar registro especifico de venta
		system("CLS");
		cout<<"Menu Principal < Menu Administrador < Visualizar Registros Generales < ventas\n\n";
		leer_registro_ventas();
		MenuRegistroGeneral();
	}
	
	else if (opcion=="3")
	{
		cout<<"Selecciono opcion 3 \n\n\n";
		//funcion visualizar registro especifico de cliente
		system("CLS");
		cout<<"Menu Principal < Menu Administrador < Visualizar Registros Generales < clientes\n\n";
		leer_registro_clientes();
		MenuRegistroGeneral();
	}
	
	else if (opcion=="4")
	{
		cout<<"Retrocediendo ...\n\n\n";
		MenuAdministrador();
	}
	
	else{
		cout<<"Comando no valido ... \n\n\n";
		pausa();
		MenuRegistroGeneral();
	}
}



	
void Menu::guardar_compras()
{	
	if (num_compras != 0)
	{
		//abrimos archivo de texto
		ofstream registro_compras;
		//lo abrimos en modo "añadir" (app)
		registro_compras.open("registro_compras.txt",ios::app); 
		//en caso de fallo con el archivo
		if(registro_compras.fail()) 
		{
			guardar_ventas();
			guardar_clientes();
			cout<<"No se pudo abrir el archivo\n";
			
			pausaFin();
		}
		
		//escribiendo en el archivo de texto del registro de compras
		//como un cout<< pero usando la variable del archivo
		
		compra *compraNueva;
		
		for(int i=0; i<num_compras; i++){
			compraNueva = com[i];
			
			registro_compras<<compraNueva->getIdentificador();
			registro_compras<<"\n";
			
			registro_compras<<compraNueva->getFecha();
			registro_compras<<"\n";
			
			registro_compras<<compraNueva->getProveedor();
			registro_compras<<"\n";
			
			registro_compras<<compraNueva->getGuiaRemitente();
			registro_compras<<"\n";
			
			registro_compras<<compraNueva->getGuiaTransportista();
			registro_compras<<"\n";
			
			registro_compras<<compraNueva->getProducto();
			registro_compras<<"\n";
			
			registro_compras<<compraNueva->getCantidadCompra();
			registro_compras<<"\n";
			
			registro_compras<<compraNueva->getPrecioCompra();
			registro_compras<<"\n";
			
			registro_compras<<"\n";
		}
		
		//cierra el archivo txt
		registro_compras.close();
		
		for(int i=0; i<num_compras; i++)
		{

			delete com[i];
			//x{x,x,x,x,x,x}
		}
		delete []com;
		com = new compra *[n_elements];
		num_compras = 0;
	}
	
}

void Menu::guardar_ventas()
{	
	if (num_ventas != 0)
	{
		//abrimos archivo de texto
		ofstream registro_ventas;
		
		//lo abrimos en modo "añadir" (app)
		registro_ventas.open("registro_ventas.txt",ios::app); 
		
		//en caso de fallo con el archivo
		if(registro_ventas.fail()) 
		{
			guardar_compras();
			guardar_clientes();
			cout<<"No se pudo abrir el archivo\n";
			pausaFin();
		}
		
		//escribiendo en el archivo de texto del registro de compras
		
		venta *ventaNueva;
		
		for(int i=0; i<num_ventas; i++)
		{
			ventaNueva = ven[i];
			
			registro_ventas<<ventaNueva->getIdentificador();
			registro_ventas<<"\n";

			registro_ventas<<ventaNueva->getFecha();
			registro_ventas<<"\n";

			registro_ventas<<ventaNueva->getProducto();
			registro_ventas<<"\n";
			
			registro_ventas<<ventaNueva->getCantidadVenta();
			registro_ventas<<"\n";
			
			registro_ventas<<ventaNueva->getValorU();
			registro_ventas<<"\n";
			
			registro_ventas<<ventaNueva->getIgv();
			registro_ventas<<"\n";
			
			registro_ventas<<ventaNueva->getPrecioVenta();
			registro_ventas<<"\n";
			
			registro_ventas<<"\n";
		}
		//cierra el archivo txt
		registro_ventas.close(); 
			
		for(int i=0; i<num_ventas; i++)
		{
			delete ven[i];
		}
		delete []ven;
		ven = new venta *[n_elements];
		num_ventas = 0;
	}
	
}

void Menu::guardar_clientes()
{	
	if (num_clientes != 0)
	{	
		//abrimos archivo de texto
		ofstream registro_clientes;
		
		//lo abrimos en modo "añadir" (app)
		registro_clientes.open("registro_clientes.txt",ios::app); 
		
		//en caso de fallo con el archivo
		if(registro_clientes.fail()) 
		{
			guardar_compras();
			guardar_ventas();
			cout<<"No se pudo abrir el archivo\n";
			pausaFin();
		}
		
		//escribiendo en el archivo de texto del registro de compras
		
		cliente *clienteNuevo;
		
		for(int i=0; i<num_clientes; i++){
			clienteNuevo = clien[i];
			
			registro_clientes<<clienteNuevo->getIdentificador();
			registro_clientes<<"\n";
			
			registro_clientes<<clienteNuevo->getFecha();
			registro_clientes<<"\n";

			registro_clientes<<clienteNuevo->getNombre();
			registro_clientes<<"\n";
			
			registro_clientes<<clienteNuevo->getTelefono();
			registro_clientes<<"\n";
			
			registro_clientes<<clienteNuevo->getDomicilio();
			registro_clientes<<"\n";
			
			registro_clientes<<"\n"; //espacio entre registros
		}
		//cierra el archivo txt
		registro_clientes.close(); 
		
		
		for(int i=0; i<num_clientes; i++)
		{
			delete clien[i];
		}
		delete []ven;
		clien = new cliente *[n_elements]; 
		num_clientes = 0;
		
	}
}


void Menu::guardar_datos() //todos
{
	guardar_compras();
	guardar_ventas();
	guardar_clientes();
}


//lo lleva a memoria
void Menu::escribir_registro_compras()
{
	//aqui metodo del mono
	int identificador;
	string fecha; 
	string proveedor;
	int guia_remitente;
	int guia_transportista;
	string producto;
	double cantidad_compra;
	double precio_compra;
	
	cout<<"Ingresando datos de nueva compra...\n\n";
	
	cout<<"Num Factura: ";
	cin>>identificador;

	cout<<"Fecha: ";
	fflush(stdin); 
	getline(cin,fecha);
	fflush(stdin);
	
	cout<<"Proveedor: ";
	fflush(stdin);
	getline(cin,proveedor);
	fflush(stdin);
	
	cout<<"Num Guia de Remitente: ";
	cin>>guia_remitente;
	
	cout<<"Num Guia de Transportista: ";
	cin>>guia_transportista;

	cout<<"Nombre del producto: ";
	fflush(stdin); 
	getline(cin,producto);
	fflush(stdin);
	
	cout<<"Cantidad (unidad/kilo): ";
	cin>>cantidad_compra;
	
	cout<<"Precio Total (S/.): ";
	cin>>precio_compra;
	
	cout<<"\n";
	
	
	//pregunta de confirmacion
	string opcion;
    while(opcion!="1")
    {
		cout << " \nLos datos ingresados son correctos? \n";
		cout << " 1. Si \n";
		cout << " 2. No \n";
		cout << " 3. Cancelar \n\n";
		cout << " Opcion: ";
		
		fflush(stdin);
		getline(cin,opcion);
		fflush(stdin);
        
		if(opcion=="2")
		{
			system("CLS");
			cout<<"Menu Principal < Menu Administrador < Ingresar Compra\n\n";
            escribir_registro_compras(); //se vuelve a llamar
		}
		
		else if(opcion=="3")
		{
			system("CLS");
			cout<<"Menu Principal < Menu Administrador\n\n";
			MenuAdministrador(); //cancelar es regresar al menu administrador
		}
        
		else if(opcion!="1")
		{
            cout<<"Ha ingresado una opcion no valida\n\n"; //si escribe algo que no va
		}
		
    }
    
	
	com[num_compras] = new compra(identificador,fecha,producto,proveedor,guia_remitente,guia_transportista,cantidad_compra,precio_compra);
	
	num_compras++;
	
	//si nuestro espacio de memoria se llena, guardamos los registros en el archivo de texto y limpiamos el espacio
	if(num_compras >= n_elements)
	{
		guardar_compras();
	}
	
	cout<<"\nDatos ingresados correctamente\n\n";
	
	pausa();
	
}

void Menu::escribir_registro_ventas()
{
	
	
	int identificador;
	string fecha;
	string producto;
	double cantidad_venta;
	double valor_u;
	double igv;
	double precio_venta;
	
	cout<<"Ingresando datos de nueva venta...\n\n";
	
	cout<<"Num Boleta: ";
	cin>>identificador;
	
	cout<<"Fecha: ";
	fflush(stdin); 
	getline(cin,fecha);
	fflush(stdin);
	
	cout<<"Producto: "; 
	fflush(stdin);
	getline(cin,producto);
	fflush(stdin);
	
	cout<<"Cant Venta: ";
	cin>>cantidad_venta;
	
	cout<<"Valor de Venta x Unidad (S/.): ";
	cin>>valor_u;
	
	cout<<"Valor IGV (18%): ";
	igv = (valor_u * cantidad_venta) / 100 * 18;
	cout<<igv;
	cout<<"\n";
	
	cout<<"Valor de Venta Total: ";
	precio_venta = (valor_u * cantidad_venta) + igv;
	cout<<precio_venta;
	cout<<"\n";
	
	cout<<"\n";
	
	//pregunta de confirmacion
	string opcion;
    while(opcion!="1")
    {
		cout << " \nLos datos ingresados son correctos? \n";
		cout << " 1. Si \n";
		cout << " 2. No \n";
		cout << " 3. Cancelar \n\n";
		cout << " Opcion: ";
		
		fflush(stdin);
		getline(cin,opcion);
		fflush(stdin);
        
		if(opcion=="2")
		{
			system("CLS");
			cout<<"Menu Principal < Menu Vendedor < Ingresar Venta\n\n";
            escribir_registro_ventas(); //se vuelve a llamar
		}
		
		else if(opcion=="3")
		{
			system("CLS");
			cout<<"Menu Principal < Menu Vendedor\n\n";
			MenuVendedor(); //cancelar es regresar al menu administrador
		}
        
		else if(opcion!="1")
		{
            cout<<"Ha ingresado una opcion no valida\n\n"; //si escribe algo que no va
		}
		
    }	
	
	ven[num_ventas] = new venta(identificador,fecha,producto,cantidad_venta,valor_u,igv,precio_venta);
	
	num_ventas++;
	
	//si nuestro espacio de memoria se llena, guardamos los registros en el archivo de texto y limpiamos el espacio
	if(num_ventas >= n_elements)
	{
		guardar_ventas();
	}
	
	cout<<"\nDatos ingresados correctamente\n\n";
	
	pausa();
	
}

void Menu::escribir_registro_clientes()
{
	//valores para usar 
	int identificador; 
	string fecha;
	string nombre;
	string telefono;
	string domicilio;
	
	cout<<"Ingresando datos de nuevo usuario...\n\n";
	
	cout<<"Dni: ";
	cin>>identificador;
	
	cout<<"Fecha de Registro: ";
	fflush(stdin);
	getline(cin,fecha);
	fflush(stdin);
	
	cout<<"Nombre: "; 
	fflush(stdin);
	getline(cin,nombre);
	fflush(stdin);
	
	cout<<"Numero Telefonico: ";
	fflush(stdin);
	getline(cin,telefono);
	fflush(stdin);
	
	cout<<"Domicilio: ";
	fflush(stdin);
	getline(cin,domicilio);
	fflush(stdin);
	
	cout<<"\n";
	
	//pregunta de confirmacion
	string opcion;
    while(opcion!="1")
    {
		cout << " \nLos datos ingresados son correctos? \n";
		cout << " 1. Si \n";
		cout << " 2. No \n";
		cout << " 3. Cancelar \n\n";
		cout << " Opcion: ";
		
		fflush(stdin);
		getline(cin,opcion);
		fflush(stdin);
        
		if(opcion=="2")
		{
			system("CLS");
			cout<<"Menu Principal < Menu Vendedor < Ingresar Cliente\n\n";
            escribir_registro_clientes();
		}
		
		else if(opcion=="3")
		{
			system("CLS");
			cout<<"Menu Principal < Menu Vendedor\n\n";
			MenuVendedor(); //cancelar es regresar al menu administrador
		}
        
		else if(opcion!="1")
		{
            cout<<"Ha ingresado una opcion no valida\n\n"; //si escribe algo que no va
		}
		
    }

	
	clien[num_clientes] = new cliente(identificador,fecha,nombre,telefono,domicilio);
	num_clientes++;
	
	if(num_clientes >= n_elements)
	{
		guardar_clientes();
	}
	
	cout<<"\nDatos ingresados correctamente\n\n";
	pausa();
	
}


/*
//antiguo que recorre caracter por caracter (+operaciones)
void Menu::leer_registro_compras() 
{
	//guardamos lo de memoria y limpiamos para tener todo listo y se lea el archivo txt
	guardar_compras();
		
	//abrimos archivo
	ifstream registro_compras;
	//variable que almacenara todo el texto del archivo
	string texto;
	//lo abrimos en modo "lectura" (in)
	registro_compras.open("registro_compras.txt",ios::in);
	//en caso de fallo
	if(registro_compras.fail())
	{
		cout<<"No se pudo abrir el archivo";
		exit(1); //cerrar con error
	}
	//seguir imprimiendo hasta que sea el final del archivo
	//while it's not end of file --- eof end of file
	while(!registro_compras.eof())
	{
		getline(registro_compras,texto);
		cout<<texto<<endl;
	}
	//cerramos archivo
	registro_compras.close(); 
	
	pausa(); //para dar tiempo a leer
}
*/

void Menu::leer_registro_compras()
{
	//si hay para guardar, lo hace y limpia memoria
	guardar_compras();
	
	//contador
	int n;
	
	//abrimos archivo
	ifstream mostrar;
	
	//lo abrimos en modo "lectura" (in)
	mostrar.open("registro_compras.txt",ios::in);
	
	//en caso de fallo
	if(mostrar.fail())
	{
		
		guardar_ventas();
		guardar_clientes();
		//error con el archivo registro_clientes.txt
        cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
		cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
		cout<<"registro_compras.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
		pausaFin();
	}
	
	while(!mostrar.eof())
	{
		getline(mostrar,l_id);
		getline(mostrar,l_fecha);
		getline(mostrar,l_proveedor);
		getline(mostrar,l_g_remitente);
		getline(mostrar,l_g_transportista);
		getline(mostrar,l_producto);
		getline(mostrar,l_cantidad);
		getline(mostrar,l_precio);
		getline(mostrar,l_espacio);
		
		if (l_id != nulo)
		{
			n = n + 1;
			cout<<"Num Factura: "<<l_id<<endl;
			cout<<"Fecha: "<<l_fecha<<endl;
			cout<<"Proveedor: "<<l_proveedor<<endl;
			cout<<"Num Guia de Remitente: "<<l_g_remitente<<endl;
			cout<<"Num Guia de Transportista: "<<l_g_transportista<<endl;
			cout<<"Nombre del producto: "<<l_producto<<endl;
			cout<<"Cantidad (unidad/kilo): "<<l_cantidad<<endl;
			cout<<"Precio Total (S/.): "<<l_precio<<endl;
			cout<<l_espacio<<endl;
		}
		
	}
	//cerramos archivo
	mostrar.close(); 
	
	cout<<"Registros de compra encontrados: "<<n<<endl<<endl;
	
	if (n==0)
	{
		cout<<"Es posible que no hallas guardado ningun registro anteriormente, si no es"<<endl;
		cout<<"el caso entonces revisa que el archivo 'registro_compras.txt' este en el"<<endl;
		cout<<"mismo lugar que el programa y que tenga el nombre antes mencionado"<<endl<<endl;
	}
	
	pausa(); //para dar tiempo a leer
	
	
}

void Menu::leer_registro_ventas()
{
	//si hay para guardar, lo hace y limpia memoria
	guardar_ventas();
	
	//contador
	int n;
	
	//abrimos archivo
	ifstream mostrar;
	
	//lo abrimos en modo "lectura" (in)
	mostrar.open("registro_ventas.txt",ios::in);
	
	//en caso de fallo
	if(mostrar.fail())
	{		
		guardar_compras();
		guardar_clientes();
		//error con el archivo registro_ventas.txt
        cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
		cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
		cout<<"registro_ventas.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
		pausaFin();
	}
	
	while(!mostrar.eof())
	{
		getline(mostrar,l_id);
		getline(mostrar,l_fecha);
		getline(mostrar,l_producto);
		getline(mostrar,l_cantidad);
		getline(mostrar,l_valor_u);
		getline(mostrar,l_igv);
		getline(mostrar,l_precio);
		getline(mostrar,l_espacio);
		
		if (l_id != nulo)
		{
			n = n + 1;
			cout<<"Num Boleta: "<<l_id<<endl;
			cout<<"Fecha: "<<l_fecha<<endl;
			cout<<"Producto: "<<l_producto<<endl;
			cout<<"Cant Venta: "<<l_cantidad<<endl;
			cout<<"Valor de Venta x Unidad (S/.): "<<l_valor_u<<endl;
			cout<<"Valor IGV (18%): "<<l_igv<<endl;
			cout<<"Valor de Venta Total: "<<l_precio<<endl;
			cout<<l_espacio<<endl;
		}
	}
	
	//cerramos archivo
	mostrar.close(); 
	
	cout<<"Registros de compra encontrados: "<<n<<endl<<endl;
	
	if (n==0)
	{
		cout<<"Es posible que no hallas guardado ningun registro anteriormente, si no es"<<endl;
		cout<<"el caso entonces revisa que el archivo 'registro_ventas.txt' este en el"<<endl;
		cout<<"mismo lugar que el programa y que tenga el nombre antes mencionado"<<endl<<endl;
	}
	
	pausa(); //para dar tiempo a leer
	

}

void Menu::leer_registro_clientes()
{
	//si hay para guardar, lo hace y limpia memoria
	guardar_clientes();
	
	//contador
	int n;
	
	//abrimos archivo
	ifstream mostrar;
	
	//lo abrimos en modo "lectura" (in)
	mostrar.open("registro_clientes.txt",ios::in);
	
	//en caso de fallo
	if(mostrar.fail())
	{
		
		guardar_compras();
		guardar_clientes();
		//error con el archivo registro_clientes.txt
        cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
		cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
		cout<<"registro_clientes.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
		pausaFin();
	}
	
	while(!mostrar.eof())
	{
		getline(mostrar,l_id);
		getline(mostrar,l_fecha);
		getline(mostrar,l_nombre);
		getline(mostrar,l_telefono);
		getline(mostrar,l_domicilio);
		getline(mostrar,l_espacio);
		
		if (l_id != nulo)
		{
			n = n + 1;
			cout<<"Dni: "<<l_id<<endl;
			cout<<"Fecha de Registro: "<<l_fecha<<endl;
			cout<<"Nombre: "<<l_nombre<<endl;
			cout<<"Numero Telefonico: "<<l_telefono<<endl;
			cout<<"Domicilio: "<<l_domicilio<<endl;
			cout<<l_espacio<<endl;
		}
	}
	
	//cerramos archivo
	mostrar.close(); 
	
	cout<<"Registros de compra encontrados: "<<n<<endl<<endl;
	
	if (n==0)
	{
		cout<<"Es posible que no hallas guardado ningun registro anteriormente, si no es"<<endl;
		cout<<"el caso entonces revisa que el archivo 'registro_clientes.txt' este en el"<<endl;
		cout<<"mismo lugar que el programa y que tenga el nombre antes mencionado"<<endl<<endl;
	}
	
	pausa(); //para dar tiempo a leer
	
}





void Menu::registro_especifico_compra() 
{
	guardar_compras();
	
	//variables que almacenaran la lineas del .txt (constantemente hasta coincidencia)

	string var_coincidencia;
	bool encontrado=false;
	
    ifstream mostrar;
    mostrar.open("registro_compras.txt",ios::in);
	
    if(mostrar.is_open())
    {
        fflush(stdin);		
        cout<<"Ingresa la factura del registro de compra que deseas consultar: ";
        getline(cin,var_coincidencia); //tiene el numero
				
        getline(mostrar,l_id);
		
        while(!mostrar.eof())
        {			
            getline(mostrar,l_fecha);
            getline(mostrar,l_proveedor);
            getline(mostrar,l_g_remitente);
            getline(mostrar,l_g_transportista);
			getline(mostrar,l_producto);
			getline(mostrar,l_cantidad);
			getline(mostrar,l_precio);
			getline(mostrar,l_espacio);

			//cout la lineas donde se encontro registro coincidiente
            if(var_coincidencia==l_id)
            {
                encontrado=true;
				
                cout<<"\n\nRegistro Encontrado\n\n";
						
				cout<<"Num Factura: "<<l_id<<endl;
				cout<<"Fecha: "<<l_fecha<<endl;
				cout<<"Proveedor: "<<l_proveedor<<endl;
				cout<<"Num Guia de Remitente: "<<l_g_remitente<<endl;
				cout<<"Num Guia de Transportista: "<<l_g_transportista<<endl;
				cout<<"Nombre del producto: "<<l_producto<<endl;
				cout<<"Cantidad (unidad/kilo): "<<l_cantidad<<endl;
				cout<<"Precio Total (S/.): "<<l_precio<<endl;
				cout<<l_espacio<<endl;
            }

            getline(mostrar,l_id);
        }

        if(encontrado==false)
        {
            cout<<"\nNo se encontro el numero de factura\n\n";
        }
    }

    else
    {
		//error con el archivo registro_compras.txt
        cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
		cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
		cout<<"registro_compras.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
    }
    mostrar.close();
    pausa();
}


void Menu::registro_especifico_venta()
{
	guardar_ventas();
	
	//variables que almacenaran la lineas (constantemente hasta coincidencia)

	
	string var_coincidencia;
	
    ifstream mostrar;
    bool encontrado=false;
    mostrar.open("registro_ventas.txt",ios::in);
    if(mostrar.is_open())
    {
        fflush(stdin);
		cout<<"Ingresa la boleta del registro de venta que deseas consultar: ";
        getline(cin,var_coincidencia);
		
        getline(mostrar,l_id);
		
        while(!mostrar.eof())
        {
            getline(mostrar,l_fecha);
			getline(mostrar,l_producto);
			getline(mostrar,l_cantidad);
			getline(mostrar,l_valor_u);
			getline(mostrar,l_igv);
			getline(mostrar,l_precio);
			getline(mostrar,l_espacio); //literal

            if(var_coincidencia==l_id)
            {
                encontrado=true;
				
                cout<<"\n\nRegistro Encontrado\n\n";
				
				cout<<"Num Boleta: "<<l_id<<endl;
				cout<<"Fecha: "<<l_fecha<<endl;
				cout<<"Producto: "<<l_producto<<endl;
				cout<<"Cant Venta: "<<l_cantidad<<endl;
				cout<<"Valor de Venta x Unidad (S/.): "<<l_valor_u<<endl;
				cout<<"Valor IGV (18%): "<<l_igv<<endl;
				cout<<"Valor de Venta Total: "<<l_precio<<endl;
				cout<<l_espacio<<endl;
            }

            getline(mostrar,l_id);
        }

        if(encontrado==false)
        {
            cout<<"\nNo se encontro el numero de boleta\n\n";
        }
		
    }

    else
    {
		//error con el archivo registro_ventas.txt
        cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
		cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
		cout<<"registro_ventas.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
    }

    mostrar.close();
	
    pausa();
}


void Menu::registro_especifico_cliente()
{
	guardar_clientes();
	
	string var_coincidencia;
	bool encontrado=false;
	
    ifstream mostrar;
    mostrar.open("registro_clientes.txt",ios::in);
    if(mostrar.is_open())
    {
        fflush(stdin);
        cout<<"Ingrese el Dni del cliente que deseas consultar: ";
        getline(cin,var_coincidencia);
		
        getline(mostrar,l_id);
		
        while(!mostrar.eof())
        {
            getline(mostrar,l_fecha);
			getline(mostrar,l_nombre);
			getline(mostrar,l_telefono);
			getline(mostrar,l_domicilio);
			getline(mostrar,l_espacio); //literal

            if(var_coincidencia==l_id)
            {
                encontrado=true;
				
                cout<<"\n\nRegistro Encontrado\n\n";
				
				cout<<"Dni: "<<l_id<<endl;
				cout<<"Fecha de Registro: "<<l_fecha<<endl;
				cout<<"Nombre: "<<l_nombre<<endl;
				cout<<"Numero Telefonico: "<<l_telefono<<endl;
				cout<<"Domicilio: "<<l_domicilio<<endl;
				cout<<l_espacio<<endl;
            }

            getline(mostrar,l_id);
        }

        if(encontrado==false)
        {
            cout<<"\nNo se encontro el numero de Dni\n\n";
        }
		
    }

    else
    {
		//error con el archivo registro_compras.txt
        cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
		cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
		cout<<"registro_clientes.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
    }

    mostrar.close();
	
    pausa();
}



void pausa()
{
    cout<<"Presione ENTER para continuar ... ";
    getch();
    system("CLS");
}


void pausaFin()
{	
	cout<<"Datos posibles guardados"<<endl;
    cout<<"Presione ENTER para cerrar ... ";
    getch();
    exit(1);
}