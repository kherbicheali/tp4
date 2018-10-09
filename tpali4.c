#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include "bibliotheque.h"

void echantillon_regulier (double min,double max,float n,double* echantillon);
void calcul_fonction (float n,double* ech_x,double* ech_y);
void polynom (double x, polynome* p);
void calcul_polynome(float n, double* ech_x,double* ech_p,polynome *p);
double f(double x);

int main ()
{
    double x[100],y[100];
    //int i;
    float n;
    polynome p;
    printf("n=");
    scanf("%f",&n);
    double max=1,min=-1;
    echantillon_regulier (min,max,n,x);
    calcul_fonction (n,x,y);
    polynom (*x, &p);
    /*x[0]=(min+1/n);
    for(i=0;i<n;i++)
    {
        x[i]=x[0]+2*i/n;
        y[i]=f(x[i]);
        printf("\nx[%d]=%f\ty[%d]=%f",i,x[i],i,y[i]);
    }*/
}

double f(double x)
{
	double y;
	y = 1/(1+25*x*x);
	return(y);
}

void echantillon_regulier (double min,double max,float n,double* echantillon)
{
    double pas=(max-min)/n;
    int i;
    echantillon [0]= (min+min+pas)/2;
    for(i=0;i<n;i++)
        echantillon[i]=echantillon [0]+2*i/n;
}

void calcul_fonction (float n,double* ech_x,double* ech_y)
{

    int i;
    for(i=0;i<n;i++)
    {
        *(ech_y+i)=f(*(ech_x+i));
        printf("\nx[%d]=%f\ty[%d]=%f",i,*(ech_x+i),i,*(ech_y+i));
    }
}

void polynom (double x, polynome* p)
{
    int a,i=0;
    float coeff;
    printf("\n saisir le degre du polynome:");
    scanf("%d",&a);
    p->degre=a;
    p->coef=malloc((a+1)*sizeof(float));
    for(i=0;i<a+1;i++)
    {
        printf("saisir la valeur du coef[%d]=",i);
        scanf("%f",&coeff);
        p->coef[i]=coeff;
    }
    for (i=0;i<a+1;i++)
        printf("%fx^%d \t",p->coef[i],i);

    double b = 0;
    printf("\nEntrez une valeur de x : ");
    scanf("%lf", &x);
    for(i=0;i<p->degre+1;i++)
        b += p->coef[i]*pow(x,i);
    printf("Pour x = %.2lf, on trouve P(x) = %.2lf\n", x, b);
}

void calcul_polynome(float n, double* ech_x,double* ech_p,polynome *p)
{
    int i;
    for(i=0;i<n;i++)
    {

    }

}
