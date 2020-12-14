//##Main

#include "P3namespace.cpp"

using namespace Ahorcado;
using namespace std;

int main()
{
string pal = Palabra("PalabrasP3.txt");
char j = 'y';
while(j == 'y'){
	ahorcado(pal);
	cout<<"Desea volver a jugar? (y o n): \n";
	cin>>j;}

  return 0; 
}  
