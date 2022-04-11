#include "Estudiante.cpp"
#include <iostream>
#include <string.h>

using namespace std;

class Archivo:Estudiante {
	
	Estudiante estudiante = Estudiante();
		
	public:
		
	FILE* archivo;
	
		void crear(){
			
		char continuar;
		archivo = fopen("Archivo.dat", "ab");
		int codigo, telefono;
		string nombre, apellido, direccion;
		
		do {
		fflush(stdin);
				
		cout<<"\n\tINGRESE ESTUDIANTE\n"<<endl;
			cout<<"\n\t\tIngrese Codigo: ";
				cin>>estudiante.codigo;
					cin.ignore();
		cout<<"\n\t\tIngrese Nombre: ";
			getline(cin,nombre);
				strcpy(estudiante.nombre, nombre.c_str());
		cout<<"\n\t\tIngrese Apellidos: ";
			getline(cin, apellido);
				strcpy(estudiante.apellido, apellido.c_str());
		cout<<"\n\t\tIngrese Direccion: ";
			getline(cin,direccion);
				strcpy(estudiante.direccion, direccion.c_str());
		cout<<"\n\t\tIngrese Telefono: ";
			cin>>estudiante.telefono;
				cin.ignore();
		
		fwrite(&estudiante, sizeof(Estudiante),1,archivo);
		
		cout<<"\n\t\tDesea agregar otro dato(s/n)?: ";
		cin>>continuar;
		
	}while (continuar == 's' || continuar == 'S');
	fclose(archivo);
				
	}
	void leer(){
	system("cls");
	archivo= fopen("Archivo.dat", "rb");
	if(!archivo){	
		archivo= fopen("Archivo.dat", "a+w");
	}
	int id=0;
	fread(&estudiante, sizeof(Estudiante),1,archivo);
		cout<<"_______________________________________________________________________"<<endl;
		cout<<"Id"<<"|"<<"Codigo"<<"|"<<"Nombres"<<"|"<<"Apellidos"<<"|"<<"Direccion"<<"|"<<"Telefono"<<endl;
		do{
		cout<<"_______________________________________________________________________"<<endl;
		cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombre<<"|"<<estudiante.apellido<<"|"<<estudiante.direccion<<"|"<<estudiante.telefono<<endl;
		fread(&estudiante, sizeof (Estudiante),1,archivo);
		id++;
		}while (feof(archivo)==0);
		fclose(archivo);
		cout<<endl;	
}
void actualizar (){
	archivo= fopen("Archivo.dat", "r+b");
	int id;
	string nombre, apellido, direccion;
	cout<<"\n\t\tIngrese Id del estudiante que desea modificar: ";
	cin>>id;
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
	fflush(stdin);
	cout<<"\n\t\tDatos a Modificar\n";
	cout<<"\n\t\tIngrese Codigo: ";
	cin>>estudiante.codigo;
	cin.ignore();
	cout<<"\n\t\tIngrese Nombres: ";
	getline(cin, nombre);
	strcpy(estudiante.nombre, nombre.c_str());
	cout<<"\n\t\tIngrese Apellidos: ";
	getline(cin,apellido);
	strcpy(estudiante.apellido, apellido.c_str());
	cout<<"\n\t\tIngrese Direccion: ";
	getline(cin, direccion);
	strcpy(estudiante.direccion, direccion.c_str());
	cout<<"\n\t\tIngrese Telefono: ";
	cin>>estudiante.telefono;
	cin.ignore();
	fwrite(&estudiante, sizeof(Estudiante),1,archivo);
	fclose(archivo);
	system("cls");
	leer();
	cout<<"\n\t\t_________________________________________________________________________"<<endl;
	cout<<"\n\t\t--------------------Modificacion Exitosa--------------------"<<endl;
	system("pause");
}
void eliminar(){
		FILE* archivo_temp=fopen("Temporal.dat","w+b"); 
		archivo=fopen("Archivo.dat","rb"); 	 
		int codigo; 
		Estudiante estudiante;               				                
		cout<<"\n\t\tIngrese codigo de estudiante que desea eliminar: "; 
		cin>>codigo;                                                                     
		while(fread(&estudiante,sizeof(Estudiante),1,archivo)){		
			if (codigo != estudiante.codigo) {
			fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp); 
			}
			else{
				cout<<"\n\t\tArchivo Eliminado\n";
				system("pause");
			}
			}        
		fclose(archivo_temp); 
		fclose(archivo); 
	remove("Archivo.dat");
	rename("Temporal.dat", "Archivo.dat");
	}
};
