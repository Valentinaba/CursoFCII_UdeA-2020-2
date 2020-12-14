#ifndef FECHA_H
#define FECHA_H

class Fecha
{

	public:
	//constructor
	Fecha(int = 1,int = 1,int = 0);

	//funciones "set"
	void setFecha(int,int,int);
	void setDia(int); 
	void setMes(int); 
	void setAnio(int);
 
	//funciones "get"
	int getDia() const; 
	int getMes() const;
	int getAnio() const;
 
	//funciones "imprimir"
	void imprimirFecha() const;

	//funcion diaSig
	void diaSig();
 
	private:
	int dia;
	int mes;
	int anio;
 
};

#endif
