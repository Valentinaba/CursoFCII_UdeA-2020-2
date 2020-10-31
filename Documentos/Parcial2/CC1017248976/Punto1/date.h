#ifndef DATE_H
#define DATE_H

// definición de la clase Fecha
class Date
{
 public:
  Date( int = 1, int = 1, int = 2000); // constructor predeterminado
  
  int SetDate(); //establecer la fecha despues de su verificacion
  
  int diaSig(); //funcion para aumentar en un dia la fecha
  
  void PrintDate();// imprime la fecha
  
  
 private:
  //declaración variables relevantes
  int month; //mes
  int day; //dia
  int year; //año
  bool leap_year; // es o no año bisiesto
  
  
  //Funciones para verificar que los valores ingresados tengan sentido y sean validos
  int VerifyDate(int, int, int); //Se valida día, mes y año en conjunto
  int VerifyDay(int); //Verifica que el valor proporcionado para día tenga sentido
  int VerifyMonth(int); //Verifica que el valor proporcionado para el mes tenga sentido
  int VerifyYear(int); //Verifica que el valor proporcionado para el año tenga sentido
  
};

#endif


