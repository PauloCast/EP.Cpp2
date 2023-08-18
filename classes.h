#include <iostream>
#include <math.h>
using namespace std;

class Bateria{
    private:
    float cargaAtual;
    float cargaTotal;

    public:

    Bateria(){}

    Bateria(float c) {
        this->cargaTotal = c;
    };
    
    void SetCargaAtual(float carga){
        this->cargaAtual = carga;
    }

    void SetCargaTotal(float carga){
        this->cargaTotal = carga;
    }

    float GetCargaAtual(){
        return cargaAtual;
    }

    float GetCargaTotal(){
        return cargaTotal;
    }

    float Porcentagem(){
        return cargaAtual/cargaTotal;
    }

    void Carregar(){
        cargaAtual = cargaTotal;
    }
};

class Drone{

    protected:
    float eficiencia;
    bool decolado = false;
    int posicao[2] = {0, 0};
    public:

    Bateria bateria;

    Drone(){
        
    }

    void SetEficiencia(float f){ eficiencia = f; }

    void SetPosicao(int x, int y){
        this->posicao[0] = x;
        this->posicao[1] = y;
    }

    void SetDecolado(bool d){
        this->decolado = d;
    }

    float GetEficiencia(){
        return this->eficiencia;
    }

    int GetPosicaoX(){
        return this->posicao[0];
    }

    int GetPosicaoY(){
        return this->posicao[1];
    }

    bool GetDecolado(){
        return this->decolado;
    }

    bool Takeoff(){
        if((this->decolado == false) && (this->bateria.GetCargaAtual() != 0)){
            this->decolado = true;
            return true;
        }
        else{
            return false;
        }
    }

    bool Pousar(){
        if(this->decolado == true){
            this->decolado = false;
            return true;
        }
        else{return false;}
    }

    bool Voar(int x, int y){
        float distancia = sqrt((GetPosicaoX() - x)*(GetPosicaoX() - x) + (GetPosicaoY()-y)*(GetPosicaoY()-y));
        cout<<distancia<<endl;
        if(this->bateria.GetCargaAtual() > distancia * GetEficiencia()){
            this->bateria.SetCargaAtual(this->bateria.GetCargaAtual() - (GetEficiencia()*distancia));
            SetPosicao(x, y);
            return true;
        }
        else{
            return false;
        }
    }
};

class Outdoor:public Drone{
    private:
    float cargaMapear;

    public:
    Outdoor(float cM, float e, Bateria b){
        this->cargaMapear = cM;
        SetEficiencia(e);
        bateria = b;
    };

    bool Mapear(){
        if(GetDecolado() == true && cargaMapear <= bateria.GetCargaAtual()){
            bateria.SetCargaAtual(bateria.GetCargaAtual() - this->cargaMapear);
            cout<<"Mapeamento concluido!"<<endl;
            return true;
        }
        else{
            cout<<"Impossivel completar o mapeamento."<<endl;
            return false;
        }
    }
};