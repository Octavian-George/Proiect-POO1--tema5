#include <iostream>
#include <string.h>

class Polynomial
{
public:

Polynomial();
Polynomial(double coeffs[], int nr);
Polynomial(const Polynomial &pol);
Polynomial(double term);
~Polynomial();
int degree() const
{
    return size-1;
}
Polynomial& operator=(const Polynomial &p);
Polynomial& operator+=(const Polynomial &p);
Polynomial& operator+=(double p);
Polynomial& operator*=(double p);
Polynomial& operator*=(const Polynomial &p);
Polynomial& operator-=(const Polynomial &p);
Polynomial& operator-=(double p);
Polynomial& operator/=(const Polynomial p);
Polynomial& operator/=(double p);
friend Polynomial operator-(const Polynomial &p);
friend Polynomial operator+(const Polynomial &p);
friend Polynomial operator+(const Polynomial & p1, const Polynomial & p);
friend Polynomial operator+(double p1, const Polynomial &p);
friend Polynomial operator+(const Polynomial &p1, double p);
friend Polynomial operator-(const Polynomial &p1, const Polynomial &p);
friend Polynomial operator-(double p1, const Polynomial &p);
friend Polynomial operator-(Polynomial &p1, double p);
friend Polynomial operator*(const Polynomial &p1, const Polynomial &p);
friend Polynomial operator*(const Polynomial &p1, double p);
friend Polynomial operator*(double p1, const Polynomial &p);
friend Polynomial operator/(const Polynomial &p1, const Polynomial &p);
friend Polynomial operator/(double p1, const Polynomial &p);
friend Polynomial operator/(const Polynomial &p1, double p);
friend Polynomial operator^(const Polynomial &p1, int p);
friend bool operator==(const Polynomial &p1, const Polynomial &p);
friend bool operator!=(const Polynomial &p1, const Polynomial &p);
friend std::ostream& operator<<(std::ostream &out, const Polynomial & p);
friend std::istream& operator>>(std::istream &in, Polynomial & p);
void output(std::ostream& out=std::cout)const;
void input(std::istream& in);
private:
    int size;
    double *coefs;
};

