#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
 
 const char *nombre_archivo = "regristro.txt";
 void ingresar_nombre();
 void ingresar_apellidos();
 void ingresar_sueldos();
 void ingresar_profesion();
 
int main(){
	ingresar_nombre();
	ingresar_apellidos();
	ingresar_sueldos();
	ingresar_profesion();	
		
}
void abrir_archivo(){
	ifstream archivo;
	string contenido;
	archivo.open(nombre_archivo,ios::in);
	
	if (archivo.fail()){
	cout<<"No se pudo abrir el archivo"<<endl;
	}else{
		cout<<endl;
		do{
			getline(archivo,contenido);
			cout<<contenido<<endl;
		} while(archivo.eof()==false);
	}
	

}
void ingresar_nombre(){
	
	ofstream archivo;
	char continuar;
	archivo.open(nombre_archivo,ios::app);
	
	if (archivo.fail()){
		cout<<"No es posible abrir el archivo";
		exit(1);
	}else{
		string nombre;
		string apellidos;
		string profesion;
		string sueldo;

		do{
		fflush(stdin);
		cout<<"Ingrese el Nombre del empleado:";
		getline(cin,nombre);
		archivo<<nombre<<endl;
		cout<<"Ingrese los apellidos del empleado:";
		getline(cin,apellidos);
		archivo<<apellidos<<endl;
		cout<<"Ingrese la profesion del empleado:";
		getline(cin,profesion);
		archivo<<profesion<<endl;
		cout<<"Ingrese el sueldo del empleado:";
		getline(cin,sueldo);
		archivo<<sueldo<<endl;
		
		cout<<"Desea Agregar otro Nombre, apellido sueldo y profesion s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	}
	archivo.close();
	abrir_archivo();
}


