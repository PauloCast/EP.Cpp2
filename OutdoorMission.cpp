#include "classes.h"

int main(){

    //Representação da área como uma matriz de caracteres:
    int linhas, colunas;
    linhas = 21;
    colunas = 21;

    char matriz[linhas][colunas];
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            matriz[i][j] = '-';
        }
    }

    int x, y, xAnterior, yAnterior;
    int mapearAtual = 0;
    int mapearTotal = 4;
    Bateria bateria(2000);
    Outdoor droneOutdoor(100, 50, bateria);
    droneOutdoor.SetPosicao(10, 10);

    bool continuar = true;
    string decisao;
    int n;

    int pontosMapear[4][2] = {{5,10}, {15,3}, {12, 2}, {2, 18}};

    cout << "Bem vindo ao desafio outdoor. Seu objetivo é alcançar todos os pontos" << endl;
    cout << "e mapear a área. Lembre-se: o drone só poderá carregar sua bateria na origem." << endl;


    while(continuar){

        for(int i = 0; i < (end(pontosMapear) - begin(pontosMapear)); i++){
            matriz[pontosMapear[i][0]][pontosMapear[i][1]] = 'M';
        }

        matriz[(int)linhas/2][(int)colunas/2] = 'H';

        matriz[droneOutdoor.GetPosicaoX()][droneOutdoor.GetPosicaoY()] = 'D';

        for (int i = 0; i < linhas; i++){
            for (int j = 0; j < colunas; j++){
                cout << matriz[i][j] << "  ";
            }
            cout << i << endl;
        }

        for (int i = 0; i < linhas; i++){
            if(i < 10){
                cout << i << "  ";
            }
            else{ cout << i << " "; }
            
        }
        cout << endl;

        cout << "Qual a sua escolha?" << endl;
        cout << "1. Levantar voo." << endl;
        cout << "2. Pousar drone." << endl;
        cout << "3. Voar para uma posição." << endl;
        cout << "4. Mapear área." << endl;
        cout << "5. Ver bateria restante." << endl;
        cout << "6. Carregar bateria." << endl;
        cout << "7. Desistir." << endl;
        
        cin >> decisao;
        
        n = stoi(decisao);

        switch (n)
        {
        case 1:
        if(droneOutdoor.Takeoff()){
            cout << "Drone decolou!" << endl;
        }
        else { 
            cout << "Não é possível decolar o drone." << endl; 
        }
        break;
        
        case 2:
        if(droneOutdoor.Pousar()){
            cout << "Drone pousou." << endl;
        }
        else { 
            cout << "O drone não está voando!"; 
        }
        break;

        case 3:
        cout << "Voar para qual posição?" << endl << "x: ";
        cin >> x;
        cout << endl << "y: ";
        cin >> y;
        cout << endl;

        xAnterior = droneOutdoor.GetPosicaoX();
        yAnterior = droneOutdoor.GetPosicaoY();
        if(droneOutdoor.Voar(y, x)){
            matriz[xAnterior][yAnterior] = '-';
            cout << "O drone voou para: (" << x << "," << y << ")" << endl;
        }
        else{
            cout << "Não é possível voar para essa posição." << endl;
        }

        break;

        case 4:

        if(droneOutdoor.Mapear()){
            if(droneOutdoor.GetPosicaoX() == linhas/2 and droneOutdoor.GetPosicaoY() == colunas/2 and !droneOutdoor.GetDecolado()){
                break;
            }
            for(int i = 0; i < (end(pontosMapear) - begin(pontosMapear)); i++){

                if(droneOutdoor.GetPosicaoX() == pontosMapear[i][0] and droneOutdoor.GetPosicaoY() == pontosMapear[i][1]){
                    mapearAtual++;
                    cout << "Áreas mapeadas:" << mapearAtual << "/" << mapearTotal << endl;
                    if (mapearAtual == mapearTotal){
                        cout << "Você ganhou!" << endl;
                        continuar = false;
                    }
                    break;
                    }
                    
                }
            }
        else{
            break;
        }

        case 5:
        cout << "Bateria restante:" << droneOutdoor.bateria.Porcentagem() << "%" << endl;
        break;

        case 6:
        if(droneOutdoor.GetPosicaoX() == linhas/2 and droneOutdoor.GetPosicaoY() == colunas/2 and !droneOutdoor.GetDecolado()){
            droneOutdoor.bateria.Carregar();
            droneOutdoor.bateria.Porcentagem();
            cout << "Bateria carregada!" << endl;
        }
        else{
            cout << "Impossível carregar." << endl;
        }

        break;

        case 7:
        cout << "Boa sorte na próxima vez :(" << endl;
        continuar = false;

        break;

        default:
        cout << "Opção inválida!" << endl;
        
    }
    }

    return 0;
}