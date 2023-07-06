#ifndef FUNCIONES_DE_DIEGO_H_INCLUDED
#define FUNCIONES_DE_DIEGO_H_INCLUDED

#include <windows.h>
#include <ctime>







int dados (int NumeroTiradas, int maximos, int v[5])
{{int Valor, maximosdados[NumeroTiradas]={0}, maximo=0, cantidaddemaximos[5];



cout<<"Estos son los valores obtenidos en la tirada: "<<6-NumeroTiradas<<endl;

for (int i=1; i<=NumeroTiradas; i++){


Valor=(rand() % 6)+ 1;
maximosdados[i-1]=Valor;

cout<<Valor<<",";
}


maximo=maximosdados[0];

for (int j=2; j<=NumeroTiradas; j++)
    {

if (maximosdados[j-1]>=maximo)

    maximo=maximosdados[j-1];
    }

cout<<endl<<"El maximo actual es: "<<maximo<<endl;

if (true)

    v[maximos-1]=maximo;


for (int m=1;m<=maximos;m++)
{


    cout<<"Los maximos anteriores son: "<<v[m-1]<<endl;}

};


system ("pause");

}

void tirada (int v2[5], int numerogenerador, int puntosapostados, int a[5], int rondasajugar)
{int Valor, maximosdados[5]={0}, multiplicadortiradafinal=0;

a[rondasajugar-1]=0;

for (int i=1; i<=5; i++){


Valor=(rand() % 6)+ 1;
maximosdados[i-1]=Valor;

cout<<Valor<<",";
}
 for (int i=1;i<=5;i++){

if (maximosdados[i-1]==numerogenerador){

    multiplicadortiradafinal+=1;
}}

a[rondasajugar-1]=multiplicadortiradafinal*puntosapostados;
cout<<endl<<"Usted gana "<<a[rondasajugar-1]<<" puntos!!";


cout<<endl;

}

int dosjugadores(int aa[1], int bb[1],char n1[25],char n2[25])
{

            cout<<endl<<"Ingrese su nombre jugador 1: ";
            char nombrejugador1[25];
            cin>>nombrejugador1;
            cout<<"Ingrese su nombre jugador 2: ";
            char nombrejugador2[25];
            cin>>nombrejugador2;
            int puntosfinales1=0,puntosfinales2=0;
            cout<<"Ingrese la cantidad de rondas que quieren jugar: ";
            int rondasajugar;
            cin>>rondasajugar;
            int v1[5];
            int v2[5];
            int a[5];
            int a2[5];
            for (int i=1; i<=rondasajugar; i++){
            system("cls");
            int y=1, r=1;
            int sumadadosj1=0, sumadadosj2=0;
            cout<<"Intrese los puntos que desea apostar "<<nombrejugador1<<" en la ronda "<<i<<":";
            int puntosapostados1;
            cin>>puntosapostados1;
            cout<<"Intrese los puntos que desea apostar "<<nombrejugador2<<" en la ronda "<<i<<":";
            int puntosapostados2;
            cin>>puntosapostados2;
            system("cls");

            //Forma actual:

            for (int k=1; k<=10; k++){
            if (k%2==0){
            cout<<"Turno de: "<<nombrejugador2<<endl;
            cout<<"Numero de ronda: "<<i<<endl;
            cout<<"Puntos actuales: "<<puntosfinales2<<endl;
            dados(6-y,y,v1);
            y=y+1;
            }
            else{
            cout<<"Turno de: "<<nombrejugador1<<endl;
            cout<<"Numero de ronda: "<<i<<endl;
            cout<<"Puntos actuales: "<<puntosfinales1<<endl;
            dados(6-r,r,v2);
            r=r+1;
            }

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


            for (int i=1; i<=5; i++){
            sumadadosj1+=v1[i-1];
            sumadadosj2+=v2[i-1];
            }
            cout<<"La suma de los dados para "<<nombrejugador1<<" es: "<<sumadadosj1<<endl;
            cout<<"La suma de los dados para "<<nombrejugador2<<" es: "<<sumadadosj2<<endl;
            system("pause");

            int numerogenerador1, numerogenerador2;

            if (sumadadosj1>25)

            {
                numerogenerador1=6;
            }

            else {

                if (sumadadosj1<20)

                {
                    numerogenerador1=0;

                }

                else {

                    numerogenerador1=sumadadosj1-19;
                }

            }

            if (sumadadosj2>25)

            {
                numerogenerador2=6;
            }

            else {

                if (sumadadosj2<20)

                {
                    numerogenerador2=0;

                }

                else {

                    numerogenerador2=sumadadosj2-19;
                }

            }

            system("cls");
            cout<<"Su numero generador de puntos " << nombrejugador1 <<" es: "<<numerogenerador1<<endl;
            cout<<"Su numero generador de puntos " << nombrejugador2 <<" es: "<<numerogenerador2<<endl;
            system("pause");
            if (numerogenerador1>0){
            cout<<"El valor de su tirada de puntaje "<<nombrejugador1<<" es:"<<endl;

            tirada(v2,numerogenerador1,puntosapostados1, a, rondasajugar);

            puntosfinales1+=a[rondasajugar-1];
            system("pause");

            }
            else {
                cout<<"Usted pierde todos los puntos apostados."<<endl;
            puntosfinales1-=puntosapostados1;
                 system("pause");

            }
            if (numerogenerador2>0){

            cout<<"El valor de su tirada de puntaje "<<nombrejugador2<<" es:"<<endl;

            tirada(v2,numerogenerador2,puntosapostados2, a2, rondasajugar);
            puntosfinales2+=a2[rondasajugar-1];
            system("pause");}
            else {
                cout<<"Usted pierde todos los puntos apostados."<<endl;
            puntosfinales2-=puntosapostados2;
                 system("pause");

            }}
            cout<<endl<<nombrejugador1<<" logro acumular en su totalidad: "<<puntosfinales1<<endl;
            cout<<endl<<nombrejugador2<<" logro acumular en su totalidad: "<<puntosfinales2<<endl;

            aa[0]=puntosfinales1;
            bb[0]=puntosfinales2;

            for (int i=1;i<=25;i++)
            {
                n1[i-1]=nombrejugador1[i-1];
            }
            for (int i=1;i<=25;i++)
            {
                n2[i-1]=nombrejugador2[i-1];
            }

            system ("pause");

}

int dadossimulados (int NumeroTiradas, int maximos, int v[5])
{{int Valor, maximosdados[NumeroTiradas]={0}, maximo=0, cantidaddemaximos[5], x;



cout<<"Ingrese los dados de la primera tirada: "<<6-NumeroTiradas<<endl;

for (int i=1; i<=NumeroTiradas; i++){

cin>>x;
Valor= x;
maximosdados[i-1]=Valor;

cout<<",";
}


maximo=maximosdados[0];

for (int j=2; j<=NumeroTiradas; j++)
    {

if (maximosdados[j-1]>=maximo)

    maximo=maximosdados[j-1];
    }

cout<<endl<<"El maximo actual es: "<<maximo<<endl;

if (true)

    v[maximos-1]=maximo;


for (int m=1;m<=maximos;m++)
{


    cout<<"Los maximos anteriores son: "<<v[m-1]<<endl;}

};


system ("pause");

}







#endif // FUNCIONES_DE_DIEGO_H_INCLUDED
