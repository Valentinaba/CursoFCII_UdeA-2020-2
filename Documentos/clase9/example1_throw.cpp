
#include <iostream> 
using namespace std; 


int main() 
{ 
   int x = -1; 
  
   // instruciones preliminares.....

   cout << "antes del try \n"; 
   try { 
      cout << "dentro del try \n"; 
      if (x < 0) 
      { 
	throw x; // el tipo de escepcion sera un entero
         cout << "despues del throw (NO se debe ejecutar) \n"; 
      } 
   } 
   catch (int x ) { 
      cout << "Exception Caught \n"; 
   } 
  
   cout << "despues del catch (esto seguira ejecutandose) \n"; 

   cout << endl;
   cout << "aca una excepcion general. \n"; 

   try  { 
       throw 10; 
    } 
    catch (char excp)  { 
        cout << "Caught " << excp; 
    } 
    catch (...)  { 
        cout << "por default \n"; 
    } 

   return 0; 
} 
/* 
**************** NOTA ****************************************************************************
Debe hacerse una advertencia cuando se lancen literales de cadena en lugar de valores numéricos. 
Siempre que se lance un literal de cadena, se trata de una cadena C, no un objeto de clase string. 
Esto significa que la instrucción catch debe declarar el argumento recibido como una cadena C, 
la cual es un arreglo de caracteres, en vez de una cadena.
Un intento de declarar la excepción como una variable de clase string producirá un error de compilador.
**************************************************************************************************
*/
