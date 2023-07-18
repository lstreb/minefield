#ifndef QUADRADO_H_INCLUDED
#define QUADRADO_H_INCLUDED

class quadrado
{
    public:
        //construtores
        quadrado(void);
        quadrado(bool temMina);

        //getters e setters
        void setMina(bool temMina);
        bool getMina();

        void setFlag(bool flag);
        bool getFlag();

        void setCoordenadaClicada(bool coordenadaClicada);
        bool getCoordenadaClicada();

        void setNum(int num);
        int getNum();

    protected:

    private:
        bool mina;
        bool coordenadaClicada=0;
        bool flag;
        int num;
};

#endif // QUADRADO_H_INCLUDED
