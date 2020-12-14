//Definiciones de funciones del Parcial2 punto 1

//############# DEFINICIÓN DE FUNCIONES ####################

#include "P1.h"
#include <iostream>

using namespace std;

// Constructor. Fija la fecha:
Fecha::Fecha( int m, int d, int y )
{
  anio = y;		//El año no tiene restricción

  if(m>12 or m<=0){cout<<"Mes inválido, se tomará el valor por defecto (Enero)"<<endl; 
	mes = 1;}	//Si el mes es inválido lo fija en 1, de lo contrario escoge el ingresado.
  else {mes = m;}

  if( d<=0 or d > diasDelMes( mes, anio) ){ //El día también tiene que ser válido, o lo asignará en 1
	cout<< "El mes "<< nombremes( mes) << " tiene "<< diasDelMes( mes, anio) << " días"<<endl;
	cout<< "Se tomará el valor por defecto (1)"<<endl;
	dia = 1;}

  else if(d>0 and d <= diasDelMes( mes, anio)){
	  dia = d ;}
}

//Asigna el nombre del mes respecto al numero correspondiente:
string Fecha::nombremes(int mes){ 
	if(mes>12){ mes = mes%12; }
    string NombreMeses[] = {"No hay mes cero","Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre","Diciembre"};

	if(  mes > 0 and mes < 13){
		return (NombreMeses[mes]);
				  }

	else{ cout<<"Algo pasó, el mes no es válido, fijando en 1..."<<endl;
		int mes = 1;
		return (NombreMeses[mes]);}
}

// imprime la Fecha en el formato mm/dd/aaaa
void Fecha::imprimir()
{
  cout << dia << " de " << nombremes(mes) << " del " << anio << endl;
}

//Da los días de cada mes dependiendo del año: 
int Fecha::diasDelMes(int mes, int anio) 
{ 
    // Enero, Marzo, Mayo, Julio, Agosto, Octubre, Diciembre
    if (mes == 1 or mes == 3 or mes == 5 or mes == 7 or mes == 8 or mes == 10 or mes == 12) 
        return (31); 
  
    // Febrero teniendo en cuenta si el año es biciesto o no 
    if (mes == 2) 
    {
        if (anio % 400 == 0 || (anio % 4 == 0 && anio % 100 != 0)) 
            return (29); 
        else
            return (28); 
    } 
  
    // Abri, Junio, Septiembre, Noviembre
    if (mes == 4 or mes == 6 or mes == 9 or mes == 11) 
        return (30); 
} 

void Fecha::diaSig()
{	dia = dia + 1;
	if (dia > diasDelMes(mes, anio) ){
		dia = 1;
		mes = mes + 1;
		if(mes > 12){
			anio = anio + 1;
			    }
						}
	cout<<"Día siguiente: ";
    cout << dia << " de " << nombremes(mes) << " del " << anio << endl;
}

