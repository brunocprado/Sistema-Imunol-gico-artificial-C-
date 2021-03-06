#ifndef COMPOSTOQUIMICO_H
#define COMPOSTOQUIMICO_H

#include "celulas/celula.h"

class CompostoQuimico{
public:
    enum TIPO_COMPOSTO {PAMP,HISTAMINA,CITOCINA,IL2,INTERLEUCINA1,TNFA};

    CompostoQuimico(TIPO_COMPOSTO,int quantidade,Celula* emissor);

    void aumentaRaio(short tam);

    TIPO_COMPOSTO getTipo();
    int getRaio();
    int getId();
    Celula* getEmissor();

    int x,y;  //CENTRO
private:
    int id;

    TIPO_COMPOSTO tipo;
    Celula* emissor;
    short concentracao;
    int raio;


};

#endif // COMPOSTOQUIMICO_H
