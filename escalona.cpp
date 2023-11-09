#include <bits/stdc++.h>
using namespace std;

std::vector<int> geraValores() {
    srand(static_cast<unsigned>(time(nullptr)));
    vector<int> valores;
    set<int> valoresExistentes;

    while (valores.size() < 10) {
        int valor = 1 + rand() % 99;
        if (valoresExistentes.find(valor) == valoresExistentes.end()) {
            valores.push_back(valor);
            valoresExistentes.insert(valor);
        }
    }
    return valores;
}

// First in First Out
void fcfs(vector<int> values, int posicaoInicial) {
    cout << "Posicao inicial da cabeca de leitura e gravacao "<< posicaoInicial << endl;
    cout << "Original [";
    for (size_t i = 0; i < values.size(); i++) { 
        cout << values[i];
        if (i != values.size() - 1)
            cout << " - ";
    }
    cout << "]" << endl << endl;
    cout << "========== Algoritmo FCFS! ==========" << endl;

    size_t l = 0;
    size_t r;
    size_t voltas = values.size();
    int deslocamento = 0;

    while (l < voltas) {
        cout << "Acessou " << values[l] << "[";
        if (l == 0) deslocamento = abs(posicaoInicial - values[l]);
        else deslocamento += abs(values[l-1] - values[l]);
        r = l + 1;
        while (r < voltas) {
            cout << values[r];
            if (r != voltas - 1)
                cout << " - ";
            r++;
        }
        cout << "] Ja deslocou " << deslocamento << " vezes" << endl;
        l++;
    }
    cout << "FCFS - Quantidade total de deslocamentos: " << deslocamento << endl << endl;
}

// Maior para a menor
void sstf(vector<int> values, int posicaoInicial){
    cout << "Posicao inicial da cabeca de leitura e gravacao "<< posicaoInicial << endl;
    cout << "Original [";
    for (size_t i = 0; i < values.size(); i++) { 
        cout << values[i];
        if (i != values.size() - 1)
            cout << " - ";
    }
    
    vector<int> sortedValues = values;
    sort(sortedValues.begin(), sortedValues.end(), greater<int>());
    int ptr; //Position To Remove
    int deslocamento = 0;
    int temp;
    cout << "]" << endl << endl;
    cout << "========== Algoritmo FCFS! ==========" << endl;
    for (int i = 0; i < 10; i++){
        if (i == 0) deslocamento = abs(posicaoInicial - sortedValues[0]);
        else deslocamento += abs(temp - sortedValues[0]);

        cout << "Acessou " << sortedValues[0] << "[";
        for(size_t i = 0; i<values.size(); i++){
            if (values[i] == sortedValues[0]){
                ptr = i; 
                break;
            }
        }
        
        values.erase(values.begin() + ptr);

        for(size_t i = 0; i<values.size(); i++){
            cout<< values[i];
            if(i != values.size()-1) cout<< " - ";
        }
        cout << "] Ja deslocou " << deslocamento << " vezes" << endl;
        temp = sortedValues[0];
        sortedValues.erase(sortedValues.begin());
    }
    cout << "SSTF - Quantidade total de deslocamentos: " << deslocamento << endl << endl;

}

int main(){
    // vector<int> values = geraValores();
    vector<int> values = {30, 70, 54, 59, 29, 64, 87, 38, 05, 40};
    cout << "===== Gerenciador de escalonamento de acesso a disco =====" << endl << endl;
    // int inicial = 1 + rand() % 99;
    int inicial = 88;


    // fcfs(values, inicial);
    // sstf(values, inicial);
    
    return 1;
}