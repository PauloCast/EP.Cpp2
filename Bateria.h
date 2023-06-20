#include <iostream>

using namespace std;

class Bateria {

    private:
        float cargaAtual, cargaTotal;

    public: 
        Bateria(float carga){
            cargaTotal = carga;
        }

    void setCargaTotal(float carga){
        cargaTotal = carga;
    }

    void setCargaAtual(float carga){
        cargaAtual = carga;
    }

    float getCargaTotal(){
        return cargaTotal;
    }

    float getCargaAtual(){
        return cargaAtual;
    }

    float Porcentagem(){ 
        return (cargaAtual/cargaTotal);
    }

    void Carregar(){
        cargaAtual = cargaTotal;
    }
}