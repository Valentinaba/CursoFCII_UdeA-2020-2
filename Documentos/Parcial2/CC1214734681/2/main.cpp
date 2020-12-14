// Johan Alexis Carrillo Toro - 1214734681
// aqui se prueba que todo funcione correctamente
#include "CuentaCheques.h"
#include "CuentaAhorros.h"
//#include "cuenta.h"


// funcion principal del programa
int main(){

	// ------------------------------se prueba primero la clase Cuenta---------------------------------
	cout << "Probando la clase Cuenta" << endl;
	Cuenta try_cuenta(50000, "JohanCarrillo");  // se crea el elemento de la clase
	cout << "El saldo de la cuenta es: " << try_cuenta.getSaldo();
	cout << "\nEl propietario de la cuenta es: " << try_cuenta.getNombre();
	try_cuenta.abonar(20000);  // se abona a la cuenta
	cout << "\nEl saldo nuevo de la cuenta es: " << try_cuenta.getSaldo();
	try_cuenta.cargar(30000);  // se retira de la cuenta
	cout << "\nEl saldo nuevo de la cuenta es: " << try_cuenta.getSaldo();
	cout << "\nSe intenta sacar mas dinero del disponible" << endl;
	try_cuenta.cargar(50000);

	// ------------------------------se prueba la subclase CuentaAhorros-------------------------------
	cout << "\nProbando la subclase CuentaAhorros" << endl;
	CuentaAhorros try_cuentaG("MiGato", 500000, 0.5);
	cout << "El saldo de la cuenta es: "  << try_cuentaG.getSaldo();
	cout << "\nEl propietario de la cuenta es: " << try_cuentaG.getNombre();
	cout << "\nEl interes de la cuenta es: " << try_cuentaG.calcularInteres();
	try_cuentaG.abonar(try_cuentaG.calcularInteres());
	cout << "\nSe agrego el interes, el nuevo saldo es: " << try_cuentaG.getSaldo() << endl;

	// ------------------------------se prueba la subclase CuentaCheques--------------------------------
	cout << "\nProbando la subclase CuentaCheques" << endl;
	CuentaCheques try_cuentaP("MiPerrita", 5000, 10000);
	cout << "El saldo de la cuenta es: " << try_cuentaP.getSaldo();
	cout << "\nEl propietario de la cuenta es: " << try_cuentaP.getNombre();
	cout << "\nSe abona 2000$ a la cuenta\n"; 
	try_cuentaP.abonar(2000);
	cout << "Se abona 20000$ a la cuenta\n";
	try_cuentaP.abonar(20000);
	cout << "El saldo de la cuenta es: " << try_cuentaP.getSaldo() << endl;



	return 0;
}