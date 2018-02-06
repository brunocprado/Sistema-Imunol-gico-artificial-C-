#ifndef SISTEMAIMUNOLOGICO_H
#define SISTEMAIMUNOLOGICO_H

#include <QDateTime>
#include <QThread>
#include <QMutex>
#include <QString>
#include <QColor>
#include <QList>
#include <QMap>

#include "quimica/camadaquimica.h"
#include "celulas/celula.h"

#define INTERVALO_PROCESSAMENTO 30

class SistemaImunologico : public QThread{
    Q_OBJECT
public:
    explicit SistemaImunologico();

    ~SistemaImunologico();

    double velocidade = 1;
    bool pausado = false;

    void inicia();

    void geraPrimeiraGeracao();
    void renderizaCelula(Celula* celula);
    void eliminaCelula(Celula* celula);

    void log(QString texto);
    void log(QString cor,QString texto);

    Q_INVOKABLE void pausar();
    Q_INVOKABLE void resumir();
    Q_INVOKABLE void encerra();
    Q_INVOKABLE void addPatogeno(); //DEBUG

    Q_INVOKABLE void mudaParametro(QString parametro,double valor);

    static SistemaImunologico* getInstancia();
    static QList<CompostoQuimico*>* getCompostos();

    double getParametro(std::string parametro);
    QList<Celula*>* getCelulas();
    CamadaQuimica* getQuimica();

    void setGerador(int g);

private:
    static SistemaImunologico* INSTANCIA; //SINGLETON

    unsigned int GERADOR;

    QDateTime INICIO_SISTEMA;

    QMutex* mutex;

    QList<Celula*>* celulas;
    CamadaQuimica* quimica;
    QMap<std::string,double>* parametros;

    void carregaParametros();
    void run(); //Loop do QThread

signals:
    void adicionaCelula(int id,int tipo,short x,short y);
    void movimentaCelula(int id,short mx,short my);
    void adicionaComposto(int id,int tipo,int raio,int x,int y);
    void mudaComposto(short id,short varRaio,short concentracao);
    void eliminaComposto(short id);
    void escreveLog(QString cor,QString texto);

public slots:
};

#endif // SISTEMAIMUNOLOGICO_H
