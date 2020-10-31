//Librerias
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//incluir la clase
#include "date.h"

Date::Date( int d, int m, int y ){
  month = m; //set mes
  day = d; //set dia
  year = y; //set año
  }

// imprime la Fecha en el formato dd/mm/aaaa
void Date::PrintDate()
{ 
  cout<<"La fecha introducida es: " << setfill('0') << setw(2) <<day << '/' << setfill('0') << setw(2) <<  month << '/' << year <<"\n";
}

//Verifica valores válidos para el año
int Date::VerifyYear(int y){  //este calendario será válido del año 1582 al 2100
    year=(y>=1582 && y<2100) ? y : 0;
    return year;
    };

//Verifica valores válidos para el mes
int Date::VerifyMonth(int m){
    month=(m>=1 && m<=12) ? m : 0; //solo existen 12 meses en el calendario Gregoriano
    return month;
    };

//Verifica valores válidos para el día 
int Date::VerifyDay(int d){
    day=(d>=1 && d<=31) ? d : 0; //en principio los días pueden ir del 1 al 31
    return day;
    }; 

//Establece valores válidos para la fecha
int Date::VerifyDate(int d, int m, int y){// con esta función verificaremos que algunos meses solo tengan 30 dias, 28 o 29 según sea el caso
    
    //determina si el año es bisiesto o no
    if(y % 4 == 0){leap_year=true;} 
    else{leap_year=false;}

    //Se establecen valores válidos para el dia mes y año 
    VerifyDay(d);
    VerifyMonth(m);
    VerifyYear(y);

    //la siguiente parte se encarga de verificar las diferencias en el fianl de los meses (algunos son de 30 o 31 o 28 y 29)
    if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){ //verifica que solo los meses 1 3 5 7 8 10 y 12 tengan 31 dias
        year=y;
        month=m;
        day=d;
    }
    else if ( m==4  || m==6 || m==9 || m==11){ //verifica que los meses 4 6 9 y 11 tengan 30 dias
        year=y;
        month=m;
        day=(d>=1 && d<=30) ? d : 0;
    }
    else{//
        year=y;
        month=m;
        if(leap_year){day=(d>=1 && d<=29) ? d : 0;} //si es año bisiesto entonces febrero puede tener hasta 29 días
        else{day=(d>=1 && d<=28) ? d : 0;} //si no es año bisiesto entonces febrero solo puede tener hasta 28 días
        
    }
    
    return day, month, year;
    
};


// función para asignar la fecha verificada
int Date::SetDate(){
    //se verifican las fechas proporcionadas
    VerifyDate(day, month, year);
    VerifyDay(day);
    VerifyMonth(month);
    VerifyYear(year);
    
    if( day==0 ){//anuncia que la fecha ingresada no es valida
        cout<<"La fecha ingresada no es válida"<<"\n";
        return 0;
        }

    else if( month==0 ){//anuncia que la fecha ingresada no es valida
        cout<<"La fecha ingresada no es válida"<<"\n";
        return 0;
        }
    else if( year==0 ){//anuncia que la fecha ingresada no es valida
        cout<<"La fecha ingresada no es válida"<<"\n";
        return 0;
        }
    else{//si la fecha ingresada tiene sentido retorna el valor suministrado
        cout<<"La fecha es: "<< setfill('0') << setw(2) <<day << '/' << setfill('0') << setw(2) <<  month << '/' << year <<"\n";
    
        return day, month, year;}
}


//funcion para aumentar un dia a la fecha

int Date::diaSig(){
    VerifyDate(day, month, year); //verifica que la fecha ingresada sea coherente "es mejor la seguridad que la policia"
    if(day==31 && month==12){//indica el paso de año
        day=1;
        year=year+1;
        
    }
    else if(day==31 && (month==1 || month==3 || month==5 || month==7 || month==8 || month==10)){//paso de mes para los meses con 31 dias
        day=1;
        month=month+1;
    }
    else if(day==30 && (month==4 || month==6 || month==9 || month==11 )){//paso de mes para los meses con 30 dias
        day=1;
        month=month+1;
    }
    else if(day==29 && month==2 && leap_year==true){//paso de mes para febrero si es bisiesto el año
        day=1;
        month=1+month;
    }
    else if(day==28 && month==2 && leap_year==false){//paso de mes para febrero si no es bisiesto el año
        day=1;
        month=1+month;
    }
    else{day=day+1;} // paratodos los dias convencionales basta con sumar un dia
    SetDate();//se establece el valor de la fecha resultante como nueva fecha
    return day, month, year;
    
}


