#include <windows.h>
#include <iostream>
#include <string.h>
#include "Polynomial.hpp"


int main()
{
std::cout<<"Marculescu Octavian-George                                                                         06.11.2018\n";
std::cout<<"Anul II, Grupa 254\n\n\n";
std::cout<<"                                   Project1-Polynomial with real coefficients\n\n\n";
std::cout<<"Checking the polynomial_array";
Sleep(1000);
std::cout<<".";
Sleep(1000);
std::cout<<".";
Sleep(1000);
std::cout<<".";
Sleep(1000);
std::cout<<".";
Sleep(1000);
std::cout<<"\nCheck complete!\n";
Sleep(1000);

double polynomial_array[]={9,4,6};
Polynomial p1(polynomial_array, 3);
Polynomial p2(p1);
std::cout<<"Polynomial 1:"<<p1<<"\n";
std::cout<<"Polynomial 2:"<< p2 << "\n";
Polynomial p3;
std::cin>>p3;
std::cout<<"Polynomial 3:"<<p3<<"\n";
Polynomial p4;
std::cin>>p4;
std::cout<<"Polynomial 4:"<<p4<<"\n";
std::cout<<"Polynomial 1 + Polynomial 2=" <<p1+p2<<"\n";
std::cout<<"Polynomial 2+ 1=" <<p2+1<<"\n";
-p4;
Polynomial p5;
p5=p3-p4;
std::cout<<"Polynomial 3-Polynomial 4="<<p5<<"\n";
std::cout<<"Polynomial 4 - 5=" <<p4-5<< "\n";
Polynomial p6;
std::cin>>p6;
std::cout<<"Polynomial 6:"<<p6<<"\n";
std::cout<<"Polynomial 2*Polynomial 4="<<p2*p4<<"\n";
std::cout<<"Polynomial 4*5="<<p4*2<<"\n";
std::cout<<"Polynomial 3/2="<<p3/2<<"\n";
p5=p5^2;
std::cout<<"Polynomial p5^3:"<<p5<<"\n";
Polynomial p7,p8;
std::cin>>p7;
std::cin>>p8;
if (p7==p8)
{
    std::cout<<"Polynomials match"<<"\n";
}
else
{
    std::cout<<"Polynomials don't match"<<"\n";
}
return 0;
}
