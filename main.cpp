#include <iostream>
#include <cstdlib>
using namespace std;
#include "funciones.h"
#include "rlutil.h"
#include "funciones de diego.h"
#include <ctime>

using namespace rlutil;



int main()
{

    srand (time(0));

    setBackgroundColor(GREEN);
    system("cls");
    setColor(YELLOW);
    gotoxy(50,11);
    cout<<"---------------------";
    gotoxy(50,12);
    cout<<"Bienvenido a 20";
    gotoxy(50,13);
    cout<<"Diego Rodrigo Etchart";
    gotoxy(50,14);
    cout<<"Legajo: 21252";
    gotoxy(50,15);
    cout<<"---------------------"<<endl;
    system("pause");
    int maximopuntaje=-999999;
    char nombreganador[25];

    int modo;
    while(true)
    {
    setBackgroundColor(GREEN);
    system("cls");
    gotoxy(40,2);
    cout<<"Ingrese el modo de juego deseado";
    gotoxy(20,5);
    cout<<"1) 1 jugador";
    gotoxy(20,6);
    cout<<"2) 2 jugadores";
    gotoxy(20,7);
    cout<<"3) Modo simulado";
    gotoxy(20,8);
    cout<<"4) Puntuaciones mas altas";
    gotoxy(20,9);
    cout<<"5) Reglas de juego";
    gotoxy(20,10);
    cout<<"6) Salir";
    gotoxy(20,11);
    cout<<"Numero de modo elegido: ";
    cin>>modo;
    system("cls");
    switch(modo){
    case 1:
            setBackgroundColor(RED);
            system("cls");
            cout<<"Bienvenido a 20 en modo 1 jugador!!"<<endl<<"Ingrese su nombre: ";
            char nombre[25];
            cin>>nombre;
            cout<<"Ingrese la cantidad de rondas que quiere jugar: ";
            int rondasajugar;
            cin>>rondasajugar;
            int v[5];
            int v2[5];
            int puntosfinales;
            puntosfinales=0;
            int a[5];
            int rondasceropuntos;
            rondasceropuntos=0;
            int rondasperdidas;
            rondasperdidas=0;
            for (int i=1; i<=rondasajugar; i++){
            int sumadados=0;
            cout<<"Intrese los puntos que desea apostar en la ronda "<<i<<":";
            int puntosapostados;
            cin>>puntosapostados;
            system("cls");

            //Forma actual:

            for (int k=1; k<=5; k++){
            cout<<"Turno de: "<<nombre<<endl;
            cout<<"Numero de ronda: "<<i<<endl;
            dados(6-k,k,v);
            system("cls");}

            /* Forma anterior:

            cout<<"Turno de: "<<nombre<<endl;
            cout<<"Numero de ronda: "<<i<<endl;
            dados(5,1,v);
            system("cls");
            cout<<"Turno de: "<<nombre<<endl;
            cout<<"Numero de ronda: "<<i<<endl;
            dados(4,2,v);
            system("cls");
            cout<<"Turno de: "<<nombre<<endl;
            cout<<"Numero de ronda: "<<i<<endl;
            dados(3,3,v);
            system("cls");
            cout<<"Turno de: "<<nombre<<endl;
            cout<<"Numero de ronda: "<<i<<endl;
            dados(2,4,v);
            system("cls");
            cout<<"Turno de: "<<nombre<<endl;
            cout<<"Numero de ronda: "<<i<<endl;
            dados(1,5,v);
            */

            for (int l=1; l<=5; l++){
            sumadados+=v[l-1];
            }
            cout<<"La suma de los dados es: "<<sumadados<<endl;
            system("pause");

            int numerogenerador;

            if (sumadados>25)

            {
                numerogenerador=6;
            }

            else {

                if (sumadados<20)

                {
                    numerogenerador=0;

                }

                else {

                    numerogenerador=sumadados-19;
                }

            }
            system("cls");
            cout<<"Su numero generador de puntos es: "<<numerogenerador<<endl;
            system("pause");
            if (numerogenerador>0){
            cout<<"El valor de su tirada de puntaje es:"<<endl;

            tirada(v2,numerogenerador,puntosapostados, a, rondasajugar);
            puntosfinales+=a[rondasajugar-1];
            if(a[rondasajugar-1]==0){
               rondasceropuntos+=1;
            }
            system("pause");

            }
            else {
                cout<<"Usted pierde todos los puntos apostados."<<endl;
            puntosfinales-=puntosapostados;
            rondasperdidas+=1;
                 system("pause");

            }
            }
            cout<<endl<<"FELICIDADES "<<nombre<<" Usted logro acumular en su totalidad: "<<puntosfinales<<endl;
            cout<<"Usted gano 0 puntos en " <<rondasceropuntos<<" rondas y perdio puntos en "<<rondasperdidas<<" rondas!!"<<endl;

            if(puntosfinales>maximopuntaje){

            maximopuntaje=puntosfinales;

            for (int i=1;i<=25;i++){

            nombreganador[i-1]=nombre[i-1];
            }
            }
        break;
    case 2:{

        setBackgroundColor(BLUE);
        system("cls");
        int aa[1], bb[1];
        char nombre1[25],nombre2[25];
        cout<<"Bienvenido a 20 en modo 2 jugadores!!";
        dosjugadores(aa, bb,nombre1,nombre2);

        /*
        La funcion dos jugadores ahora intercala entre personas.
        */

        system("pause");
        system("cls");
        if (aa[0]>bb[0])
        {
            cout<<"El ganador es "<<nombre1<<" que consiguio la siguiente cantidad de puntos: "<< aa[0]<<endl;
        }
        else{
            cout<<"El ganador es "<<nombre2<<" que consiguio la siguiente cantidad de puntos: "<< bb[0]<<endl;
        }
        if (aa[0]>bb[0])
        {
            if (aa[0]>maximopuntaje)
            maximopuntaje=aa[0];

            for (int i=0;i<=24;i++){

            nombreganador[i]=nombre1[i];}

        }
        else {
            if (bb[0]>maximopuntaje)
            maximopuntaje=bb[0];

            for (int i=0;i<=24;i++){

            nombreganador[i]=nombre2[i];}

        }

         break;}

    case 3:
          cout<<"Bienvenido a 20 en modo simulado!!"<<endl<<"Ingrese su nombre: ";
            char nombresimulado[25];
            cin>>nombre;
            cout<<"Ingrese la cantidad de rondas que quiere jugar: ";
            int rondasajugarsimulado;
            cin>>rondasajugarsimulado;
            int vsimulado[5];
            int v2simulado[5];
            int puntosfinalessimulado;
            puntosfinalessimulado=0;
            int asimulado;
            asimulado=0;
            for (int i=1; i<=rondasajugarsimulado; i++){
            int sumadados=0;
            cout<<"Intrese los puntos que desea apostar en la ronda "<<i<<":";
            int puntosapostados;
            cin>>puntosapostados;
            system("cls");
            for (int k=1; k<=5; k++){
            cout<<"Turno de: "<<nombre<<endl;
            cout<<"Numero de ronda: "<<i<<endl;

            //Forma actual:

            dadossimulados(6-k,k,vsimulado);
            system("cls");}
            for (int i=1; i<=5; i++){
            sumadados+=vsimulado[i-1];
            }

            /*
            Forma anterior:
            dadossimulados(5,1,vsimulado);
            system("cls");
            cout<<"Turno de: "<<nombre<<endl;
            cout<<"Numero de ronda: "<<i<<endl;
            dadossimulados(4,2,vsimulado);
            system("cls");
            cout<<"Turno de: "<<nombre<<endl;
            cout<<"Numero de ronda: "<<i<<endl;
            dadossimulados(3,3,vsimulado);
            system("cls");
            cout<<"Turno de: "<<nombre<<endl;
            cout<<"Numero de ronda: "<<i<<endl;
            dadossimulados(2,4,vsimulado);
            system("cls");
            cout<<"Turno de: "<<nombre<<endl;
            cout<<"Numero de ronda: "<<i<<endl;
            dadossimulados(1,5,vsimulado);
            */
            cout<<"La suma de los dados es: "<<sumadados<<endl;
            system("pause");

            int numerogenerador;

            if (sumadados>25)

            {
                numerogenerador=6;
            }

            else {

                if (sumadados<20)

                {
                    numerogenerador=0;

                }

                else {

                    numerogenerador=sumadados-19;
                }

            }
            system("cls");
            cout<<"Su numero generador de puntos es: "<<numerogenerador<<endl;
            system("pause");
            if (numerogenerador>0){
            cout<<"El valor de su tirada de puntaje es:"<<endl;

            int tiradasimulada[5];
            for(int i=1; i<=5; i++)
            {
                cin>>tiradasimulada[i-1];

            }

            for (int i=1; i<=5; i++){

                if(tiradasimulada[i-1]==numerogenerador)
                asimulado+=1;

            }

            puntosfinalessimulado+=asimulado*puntosapostados;
            cout<<"Usted gano los siguientes puntos: "<<puntosfinalessimulado<<endl;
            system("pause");

            }
            else {
                cout<<"Usted pierde todos los puntos apostados."<<endl;
            puntosfinalessimulado-=puntosapostados;
                 system("pause");

            }
            }
            cout<<endl<<"Usted logro acumular en su totalidad: "<<puntosfinalessimulado<<endl;

        break;
    case 4:
        setBackgroundColor(CYAN);
        system("cls");
        if (maximopuntaje==-999999)
        {
            cout<<"No hubo puntuacion mas alta registrada."<<endl;
        }
        else
        {
         cout<<maximopuntaje<<" fue el puntaje maximo obtenido en esta ejecicion logrado por: "<<nombreganador<<endl;
        }

        break;

        /*
        REGLAS DE JUEGO AGREGADAS
        */

    case 5:
        setBackgroundColor(BLACK);
        system("cls");
        cout<<"Reglas de juego:"<<endl;
        cout<<"20 es un juego que utiliza 5 dados, y que puede ser jugado por uno o varios jugadores. Nuestra versi�n ser� para 1 � 2 jugadores."<<endl;
        cout<<"El juego consiste en un conjunto de rondas en las que se analizan los valores obtenidos al tirar los dados. En la versi�n que se"<<endl;
        cout<<"propone la cantidad de rondas se establece cuando el juego empieza(se ingresa por teclado). Al inicio de cada ronda, y cuando le"<<endl;
        cout<<"toca el turno, cada jugador debe indicar cu�ntos puntos quiere apostar en esa ronda. De acuerdo a los valores que obtenga en las"<<endl;
        cout<<"tiradas de dados, esos puntos apostados podr�n sumarse o restarse a su puntaje total."<<endl<<endl;
        cout<<"Cada ronda consiste en 5 tiradas de dados de la siguiente manera:"<<endl;
        cout<<"Tirada 1: se tiran los 5 dados. Se analiza el valor de cada dado y se retira el que tiene mayor puntaje."<<endl;
        cout<<"Tirada 2: se tiran 4 dados. Se analiza el valor de cada dado y se retira el que tiene mayor puntaje."<<endl;
        cout<<"Tirada 3: se tiran 3 dados. Se analiza el valor de cada dado y se retira el que tiene mayor puntaje."<<endl;
        cout<<"Tirada 4: se tiran 2 dados. Se analiza el valor de cada dado y se retira el que tiene mayor puntaje."<<endl;
        cout<<"Tirada 5: se tira el dado restante."<<endl;
        cout<<"Luego de las 5 tiradas se suman los valores de los 5 dados con los puntajes m�ximos de cada tirada. Si la suma es mayor o igual a"<<endl;
        cout<<"20 el jugador contin�a. Si la suma es menor a 20 el jugador pierde los puntos apostados para esa ronda, que se restan al puntaje total que ten�a hasta ese momento."<<endl;
        cout<<"Si la suma es mayor o igual a 20, el jugador tiene derecho a un nuevo tiro de los 5 dados. Este tiro se denomina Tiro de Puntaje, y puede permitirle"<<endl;
        cout<<"sumar puntos. La cantidad de puntos surge de multiplicar los puntos apostados al empezar la ronda por la cantidad de dados con un valor igual al n�mero generador de puntos."<<endl;


        break;


    case 6:
        setBackgroundColor(MAGENTA);
        system("cls");
        cout<<"Cerrando programa."<<endl<<"Gracias por jugar!"<<endl;
         return 0;
         break;

    default:
        setBackgroundColor(BLACK);
        system("cls");
        cout<<"Ingrese una opcion valida"<<endl;
        break;
     }
    system("pause");
    system("cls");
    }
    return 0;
}