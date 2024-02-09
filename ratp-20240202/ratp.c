

static const float Price = 1.2;

#define Q6

#ifndef Q6
float computePrice(int age, int tourist)
{
    if (age>12)
    {
        if (tourist)
            return Price*2;
        return Price;
    }
    else 
    {
        if (tourist)
            return Price;
        return Price/2;
    }
}
#endif



#ifdef Q6
#include "age.h"




float computePrice(int age, int tourist)
{
    int limitAge;
    int *plimit = &limitAge;
    recupAge(plimit);
    if (age>limitAge)
    {
        if (tourist)
            return Price*2;
        return Price;
    }
    else 
    {
        if (tourist)
            return Price;
        return Price/2;
    }
}

#endif