#include "quadrado.h"

quadrado::quadrado()
{
    mina = false;
    num = ' ';
    flag = false;
}

quadrado::quadrado(bool temMina)
{
    mina = temMina;
    num = ' ';
    flag = false;
}

void quadrado::setMina(bool temMina)
{
    mina = temMina;
}

bool quadrado::getMina()
{
    return mina;
}

void quadrado::setFlag(bool flag)
{
    this->flag = flag;
}

bool quadrado::getFlag()
{
    return flag;
}

void quadrado::setNum(int num)
{
    this->num = num;
}

int quadrado::getNum()
{
    return num;
}

void quadrado::setCoordenadaClicada(bool coordenadaClicada)
{
    this->coordenadaClicada = coordenadaClicada;
}

bool quadrado::getCoordenadaClicada()
{
    return coordenadaClicada;
}
