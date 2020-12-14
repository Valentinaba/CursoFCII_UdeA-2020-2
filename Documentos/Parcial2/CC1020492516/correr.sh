
#!/bin/bash
# -*- ENCODING: UTF-8 -*-
printf "COMPILANDO PUNTO 1...\n \n"
g++ Punto1/P1.cpp Punto1/P1main.cpp
./a.out

printf "\nFIN DEL PUNTO 1 \n"
read -n 1 -s -r -p "Presione cualquier tecla para continuar"

printf "\nCOMPILANDO EL PUNTO 2... \n"
g++ Punto2/*.cpp
./a.out

printf "\nFIN DEL PUNTO 2 \n"
read -n 1 -s -r -p "Presione cualquier tecla para continuar"

printf "\nCOMPILANDO EL PUNTO 3... \n \n"
cd Punto3/
g++ P3main.cpp
./a.out
cd ..
printf "\nFIN. GRCIAS. \n"
