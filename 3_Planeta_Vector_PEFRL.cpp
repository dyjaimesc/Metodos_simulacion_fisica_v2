/*Algoritmo que realiza la simulacion  de un planeta girando alrededor de otro utilzando una fuerza central

3_Planeta_Vector_PEFRL.cpp
*/

#include<iostream>
#include<cmath>
#include "Vector.h"

//---------------Se definen constantes-------------

const double G=1.0;
const double M1=1.0;

//--------------- constantes PEFRL-------------

const double Zeta=0.1786178958448091e00;
const double Lamnda=-0.2123418310626054e00;
const double Chi=-0.662645826698189e-01;
const double Coeficiente1=(1-2*Lamnda)/2;
const double Coeficiente2=1-2*(Chi*Lamnda);

//--------------- Clases  -------------

class Planeta{
private:
    vector3D r,V,F;
    double M2,R;
public:
    void Inicie(double x0,double y0,double Vx0,double Vy0,double m0,double R0);
    void CalculeFuerza(void);
    void Mueva_r(double dt,double Coeficiente);
    void Mueva_V(double dt,double Coeficiente);
    void Dibujese(void);
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

void Planeta::Mueva_r(double dt, double Coeficiente){
    r+=V*(dt*Coeficiente);
}
void Planeta::Mueva_V(double dt, double Coeficiente){
    V+=F*(dt*Coeficiente/M2);
}

void Planeta::Dibujese(void){//dibuja el balon
  cout<<" , "<<r.x()<<"+"<<R<<"*cos(t),"<<r.y()<<"+"<<R<<"*sin(t)";
}

//--------------- Animacion  -------------

void InicieAnimacion(void){
  cout<<"set terminal gif animate"<<endl;
  cout<<"set output 'Planeta.gif'"<<endl;
  cout<<"unset key"<<endl;
  cout<<"set xrange[-20:20]"<<endl;
  cout<<"set yrange[-20:20]"<<endl;
  cout<<"set size ratio -1"<<endl;
  cout<<"set parametric"<<endl;
  cout<<"set trange [0:7]"<<endl;
  cout<<"set isosamples 12"<<endl;
  cout<<"set grid"<<endl;
}
void InicieCuadro(void){
  cout<<"plot 0,0";
}
void TermineCuadro(void){
  cout<<endl;
}


//--------------- Cuerpo (main)  -------------


int main(void){
    Planeta P1;
    double r0,Vx0,Vy0,m0,R0;
    double t,tdibujo,tmax,tcuadro,dt=0.1;
    double Omega,T;

//--------------- Condiciones iniciales  -------------
    r0=10.0;
    Omega=pow(G*M1/(r0*r0*r0),0.5);
    T=2*M_PI/Omega;
    Vx0=0.0;  Vy0=Omega*r0;
    
    m0=10.0; R0=1.0;

    tmax=19.0*T; tcuadro=T/40; dt=0.1;
    t=0.0; //tmax=T*19.0;

    P1.Inicie(   r0,   0.0,   Vx0,  1.0*Vy0, m0, R0);
    
    InicieAnimacion();
    
    for(t=0,tdibujo=0;t<tmax;t+=dt,tdibujo+=dt){
	//dibujar

	if(tdibujo>tcuadro){
	    /*  InicieCuadro();
	    P1.Dibujese();
	    TermineCuadro();

	    tdibujo=0;// */
	       cout<<t<<" "<<P1.Getx()<<" "<<P1.Gety()<<endl;
	}
	 P1.Mueva_r(dt,Zeta);
	 P1.CalculeFuerza(); P1.Mueva_V(dt,Coeficiente1);
	 P1.Mueva_r(dt,Chi);
	 P1.CalculeFuerza(); P1.Mueva_V(dt,Lamnda);
	 P1.Mueva_r(dt,Coeficiente2);
	 P1.CalculeFuerza(); P1.Mueva_V(dt,Lamnda);
	 P1.Mueva_r(dt,Chi);
	 P1.CalculeFuerza(); P1.Mueva_V(dt,Coeficiente1);
	 P1.Mueva_r(dt,Zeta);

	 
     } 

    return 0;
}


