#include "Archivo.cpp"
#include <iostream>
#include <string.h>
using namespace std; 
int main(){
	Archivo arc= Archivo();	
	int op;
	do{
	system("cls");
	arc.leer();
	cout<<"\n\t__________________________________"<<endl;
	cout<<"\n                      MENU\n";
	cout<<"\n\t__________________________________"<<endl;
		cout<<"\n\t 1. Ingresar Estudiante"<<endl;
		cout<<"\n\t 2. Actualizar Datos De Estudiante"<<endl;
		cout<<"\n\t 3. Eliminar Estudiante"<<endl;
		cout<<"\n\t 0. SALIR"<<endl;
	cout<<"\n\tIngresa la opcion que deseas realizar: ";
	cin>>op;
	if (op==1){
		arc.crear();}
		
	else if (op==2){
		arc.actualizar();}
		
	else if (op==3){
		arc.eliminar();}
		
	}while (op!=0);	
	return 0;
}
