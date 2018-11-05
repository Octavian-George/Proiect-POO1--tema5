#include <iostream>
#include <string.h>
#include <cmath>
#include "Polynomial.hpp"

Polynomial::Polynomial():size(1),coefs(new double[1])
{
    coefs[0] = 0.0;
}
Polynomial::Polynomial(double coeffs[],int nr) :
    size(nr),coefs(new double[nr])
{
    for (int i=0; i<size; i++)
    {
        coefs[i]=coeffs[i];
    }
}
Polynomial::Polynomial(const Polynomial &p) :
    size(p.size),coefs(new double[p.size])
{
    for (int i=0; i<size; i++)
    {
        coefs[i]=p.coefs[i];
    }
}
Polynomial::Polynomial(double term):size(1),coefs(new double[1])
{
    coefs[0]=term;
}
Polynomial::~Polynomial()
{
    delete[] coefs;
}
void Polynomial::output(std::ostream &out) const
{
    if (size==0)
    {
        return;
    }

    for (int i=size-1; i>0; i--)
        out<<coefs[i]<<"x^"<<i<<"+";
    out<<coefs[0];
}
void Polynomial::input(std::istream& in)
{
    std::cout<<"\nEnter the degree of another polynomial:";
    in>>size;
    delete[] coefs;
    coefs=new double[size];

    for (int i=size-1; i>=0; i--)
    {
        std::cout<<"Enter the coeff for x^"<<i<<":";
        in>>coefs[i];
    }
}
Polynomial& Polynomial::operator=(const Polynomial &p)
{
    if (this==&p)
    {
        return *this;
    }

    else
    {
        delete[] coefs;
        coefs=new double[p.size];
        size=p.size;
        for (int i=0;i<size;i++)
        {
            coefs[i]=p.coefs[i];
        }
    }
    return *this;
}
Polynomial & Polynomial::operator+=(const Polynomial &p)
{
    int newSize=(p.size>size)? p.size: size;
    double *newCoef=new double[newSize];

    for (int i=0;i<newSize;i++)
    {
        newCoef[i]=0;
    }
    for (int i=0;i<p.size;i++)
    {
        newCoef[i]+=p.coefs[i];
    }
    for (int i=0;i<size;i++)
    {
        newCoef[i]+=coefs[i];
    }
    delete[] coefs;
    coefs=newCoef;
    size=newSize;
    return *this;
}
Polynomial& Polynomial::operator+=(double p)
{
    for (int i=0;i<size;i++)
    {
        if (i==0)
        {
            coefs[i]+= p;
        }
    }
    return *this;
}
Polynomial& Polynomial::operator*=(double p)
{
    for (int i=0;i<size;i++)
    {
        coefs[i]*= p;
    }
    return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial &p)
{
    int newSize=p.size+size-1;
    double *newCoef =new double[newSize];

    for (int i=0;i<newSize;i++)
        newCoef[i]=0;

    for (int i=0;i<size;i++)
    {
        for (int j=0;j<p.size;j++)

            newCoef[i+j]+=coefs[i]*p.coefs[j];
    }
    delete[] coefs;
    coefs =newCoef;
    size =newSize;
    return *this;
}
Polynomial & Polynomial::operator-=(const Polynomial &p)
{
    int newSize=(p.size < size) ? p.size : size;
    double *newCoef =new double[newSize];
    for (int i=0;i<newSize;i++)
    {
        newCoef[i] = 0;
    }
    for (int i=0;i< p.size;i++)
    {
        newCoef[i]-=p.coefs[i];
    }
    for (int i=0;i<size;i++)
    {
        newCoef[i]-=coefs[i];
    }
    delete[] coefs;
    coefs=newCoef;
    size=newSize;
    return *this;
}
Polynomial& Polynomial::operator-=(double p)
{
    for (int i=0;i<size;i++)
    {
        if (i==0)
        {
            coefs[i]-= p;
        }
    }
    return *this;
}
Polynomial& Polynomial::operator/=(double p)
{
    for (int i=0;i<size;i++)
    {
        coefs[i]/=p;
    }
    return *this;
}
Polynomial operator+(const Polynomial &p1, const Polynomial &p)
{
    Polynomial result(p1);
    result+=p;
    return result;
}
Polynomial operator+(const Polynomial &p1, double p)
{
    Polynomial result(p1);
    result+=p;
    return result;
}
Polynomial operator+(double p1, const Polynomial &p)
{
    Polynomial result(p);
    result+=p1;
    return result;
}
Polynomial operator-(const Polynomial &p1, const Polynomial &p)
{
    Polynomial result(p1);
    result-=p;
    return result;
}
Polynomial operator-(double p1, const Polynomial &p)
{
    Polynomial result(p);
    result-=p1;
    return result;
}
Polynomial operator-(Polynomial &p1, double p)
{
    Polynomial result(p1);
    result-=p;
    return result;

}
Polynomial operator*(const Polynomial &p1, const Polynomial &p)
{
    Polynomial result(p1);
    result*=p;
    return result;
}
Polynomial operator*(const Polynomial &p1, double p)
{
    Polynomial result(p1);
    result*=p;
    return result;
}
Polynomial operator*(double p1, const Polynomial &p)
{
    Polynomial result(p);
    result*=p1;
    return result;
}
Polynomial operator/(double p1, const Polynomial &p)
{
    Polynomial result(p);
    result/=p1;
    return result;
}
Polynomial operator/(const Polynomial &p1, double p)
{
    Polynomial result(p1);
    result/=p;
    return result;
}
Polynomial operator^(const Polynomial &p1, int p)
{
    Polynomial result(p1);
    Polynomial r=result;
    int i=1;
    while (i<p)
    {
        result=result*r;
        i++;
    }
    return result ;

}
Polynomial operator-(const Polynomial &p)
{
    for (int i=0;i<p.size;i++)
    {
        p.coefs[i]*=(-1);
    }
    return p;
}
Polynomial operator+(const Polynomial &p)
{
    return p;
}
bool operator==(const Polynomial &p1, const Polynomial &p)
{
    if (p1.size!=p.size)
    {
        return false;
    }

    for (int i=0;i<p1.size;i++)
    {
        if (p1.coefs[i]!=p.coefs[i])
        {
            return false;
        }
    }
    return true;
}
bool operator!=(const Polynomial &p1, const Polynomial &p)
{
    if (p1.size!=p.size)
    {
        return true;
    }
    for (int i=0;i<p1.size;i++)
    {
        if (p1.coefs[i]!=p.coefs[i])
        {
            return true;
        }
    }
    return false;
}
std::ostream& operator<<(std::ostream &out,const Polynomial &p)
{
    p.output(out);
    return out;
}
std::istream& operator>>(std::istream &in,Polynomial &p)
{
    p.input(in);
    return in;

}
