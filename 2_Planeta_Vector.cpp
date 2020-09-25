/*Algoritmo que realiza la simulacion  de un planeta girando alrededor de otro utilzando una fuerza central

2_Planeta_Vector.cpp
*/

#include<iostream>
#include<cmath>
#include "Vector.h"

//---------------Se definen constantes-------------

const double G=1.0;
const double M1=1.0;

//--------------- Clases  -------------

class Planeta{
private:
    vector3D r,V,F;
    double M2,R;
public:
    void Inicie(double x0,double y0,double Vx0,double Vy0,double m0,double R0);
    void CalculeFuerza(void);
    void Muevase(double dt);
    double Getx(void){return r.x();};
    double Gety(void){return r.y();};
};

void Planeta::Inicie(double x0,double y0,double Vx0,double Vy0,double m0,double R0){
    r.cargue(x0,y0,0);
    V.cargue(Vx0,Vy0,0);
    M2=m0;
    R=R0;
}

void Planeta::CalculeFuerza(void){
    double aux=G*M1*M2*pow(norma(r),-3.0);
    F=-aux*r;
}

void Planeta::Muevase(double dt){
    r+=V*dt;
    V+=F*(dt/M2);
}

//--------------- Cuerpo (main)  -------------


int main(void){
    Planeta P1;
    double t,tf,r0,Vx0,Vy0,m0,R0,dt;
    double Omega,T;

//--------------- Condiciones inicieale  -------------
    r0=10.0;
    Omega=pow(G*M1/(r0*r0*r0),0.5);
    T=2*M_PI/Omega;
    Vx0=0.0;  Vy0=Omega*r0;
    
    m0=10.0; R0=1.0;
    
    t=0.0; tf=T*19.0;
    dt=0.01;

    P1.Inicie(   r0,   0.0,   Vx0,  1.0*Vy0, m0, R0);

     for(;t<tf;t+=dt){
	 P1.CalculeFuerza();
	 P1.Muevase(dt);
	 cout<<t<<" "<<P1.Getx()<<" "<<P1.Gety()<<endl;
     } 

    return 0;
}


