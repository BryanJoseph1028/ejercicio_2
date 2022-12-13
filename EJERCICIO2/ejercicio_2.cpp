strea
#include <stdlib.h>
#include <fstream>
using namespace std;
 
 
 const char *nombe_archivo = "archivo.txt";
 void ingresar_nombre();
 
int main(){
	ingresar_nombre();
	return 0;	
}
void abrir_archivo(){
	ifstream archivo;
	string contenido;
	archivo.open(nombe_archivo,ios::in);
	
	
	if (archivo.fail()){
	cout<<"No se pudo abrir el archivo";
	exit(1);
	}else{
		cout<<endl;
		do{
			getline(archivo,contenido);
			cout<<contenido<<endl;
		} while(archivo.eof()==false);
	}
	
	archivo.close();
}

void ingresar_nombre(){
	
	ofstream archivo;
	char continuar;
	archivo.open(nombe_archivo,ios::app);
	
	if (archivo.fail()){
		cout<<"No es posible abrir el archivo";
		exit(1);
	}else{
		string nombre;
		do{
			fflush(stdin);
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
		archivo<<nombre<<endl;
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	}
	archivo.close();
	abrir_archivo();
}


