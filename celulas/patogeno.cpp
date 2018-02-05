#include <QTimer>

#include "patogeno.h"
#include "quimica/compostoquimico.h"
#include "sistemaimunologico.h"

Patogeno::Patogeno() : Celula(PATOGENO){
    this->virus = new Virus("TESTE");
    this->inicia();
}

Patogeno::Patogeno(Virus *virus) : Celula(PATOGENO){
    this->virus = virus;
    this->inicia();
}

void Patogeno::inicia(){
    virus->add();
    emiteQuimica(CompostoQuimico::PAMP,10);
}

void Patogeno::clona(){
    Patogeno *tmp = new Patogeno(virus);
    SistemaImunologico::getInstancia()->renderizaCelula(tmp);
}

void Patogeno::loop(){

    if(prox != nullptr){
        if(calculaDistancia(prox) < 6){
            processando = true;
            //printf("FIM (x,y) = %d %d \n",x,y);
        } else {
            move(prox);
        }
        return;
    }

    double maisProx = INT16_MAX;
    double dist = 0;

    QList<Celula*>::iterator i = SistemaImunologico::getInstancia()->getCelulas()->begin();
    for (; i != SistemaImunologico::getInstancia()->getCelulas()->end(); ++i){
        if((*i)->getTipo() == PATOGENO) continue;
        dist = calculaDistancia(*i);
        if(maisProx > dist){
            maisProx = dist;
            prox = *i;
        }
    }

    //printf("PATOGENO (x,y) = %d %d \n",x,y);
    //printf("ALVO (x,y) = %d %d \n",prox->x,prox->y);

    move(prox);
}
