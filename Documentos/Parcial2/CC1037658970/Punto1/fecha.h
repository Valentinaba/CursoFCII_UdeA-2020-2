/**
 * @author Valentina Roquemen Echeverry
 * @brief Clase recibe una fecha en formato mm/dd/yyyy,
 *        la valida y tiene la posibilidad de evolucionar.
 */

class Fecha
{  
public:

  /**
  * @param m : mes.
  * @param d : dia.
  * @param y : anio.
  */ 
  Fecha(int, int, int);

  /**
  * @brief Se establecen los parametros
  * @param m : mes.
  * @param d : dia.
  * @param y : anio.
  */ 
  void setParameters(int,int,int);

  /**
  * @brief Se valida la fecha cambiando el valor
  *        de la instancia validez 
  */ 
  void fechaValida();

  /**
  * @brief Metodo usado por el metodo fechaValida()
  *        para validar que el dia perteneza al mes
  *        ingresado.
  * @return True si el dia es valido
  */ 
  bool diaValido();

  /**
  * @brief Estima si el anio es bisiesto o no
  * @return True si el anio es bisiesto
  */ 
  bool anioBisiesto();

  /**
  * @brief Actualiza las instancias mes, dia y anio
  *        con el dia siguiente
  */
  void diaSig();

  /**
  * @brief Imprime la fecha en formato mm/dd/yyyy
  */
  void imprimir() const;

private:     

  int mes; //Mes
  int dia; // Dia
  int anio; //Anio
  bool validez = true; //true = Si la fecha es valida 
  bool bisiesto = false; // true = Si el anio es bisiesto

};