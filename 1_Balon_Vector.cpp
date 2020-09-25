/*Programa que simula el movimiento de un balon, utilizando POO (Objetos), se utiliza la libreria Vector3D

1_Balon_Vector.cpp
*/

#include<iostream>
#include<cmath>
#include "Vector.h"

//----------------Define constantes--------------

const double g=9.8;

//----------------Definen Clases-----------------
class Balon{
private:
  vector3D r,V,F;
  double m, R;
public:
  void Inicie(double x0,double y0,double Vx0,double Vy0, double m0, double R0);
  void CalculeFuerza(void);
  void Muevase(double dt);
  double Getx(void){return r.x();};
  double Gety(void){return r.y();};
};

//------------------------Se definen metodos------------
void Balon::Inicie(double x0,double y0,double Vx0,double Vy0, double m0, double R0){
  r.cargue(x0,y0,0);
  V.cargue(Vx0,Vy0,0);
  m=m0;
  R=R0;
}

void Balon::CalculeFuerza(void){
  F.cargue(0,-m*g,0);
}

void Balon::Muevase(double dt){
  r+=V*dt;
  V+=F*(dt/m);
}

//-----------------------Cuerpo principal del programa---------------
int main(void){

  Balon B1;
  double t,tf,x0,y0,Vx0,Vy0,m0,R0,dt;

  //---------------Condiciones iniciales
  x0=0.0;  y0=0.0;  Vx0=10.0;  Vy0=50.0;
  m0=10.0; R0=1.0;
  t=0.0; tf=10.0;
  dt=0.01;

  B1.Inicie(x0,y0, Vx0, Vy0, m0, R0);

  for(;t<tf;t+=dt){
    B1.CalculeFuerza();
    B1.Muevase(dt);
    cout<<t<<" "<<B1.Getx()<<" "<<B1.Gety()<<endl;
  } 

  
  
  
  return 0;
}
