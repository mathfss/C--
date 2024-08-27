#include <iostream>

using namespace std;

struct Aluno {
    float* notas;
};

int main() {
    int n;
    cin >> n;

    Aluno* alunos = new Aluno[n];

    for (int i = 0; i < n; i++) {
        alunos[i].notas = new float[3];
        cin >> alunos[i].notas[0] >> alunos[i].notas[1] >> alunos[i].notas[2];
    }

    float media = 0;
    for (int i = 0; i < n; i++) {
        float soma = 0;
        for (int j = 0; j < 3; j++) {
            soma += alunos[i].notas[j];
        }
        media += soma / 3;
    }
    media /= n;

    cout << media << endl;

    for (int i = 0; i < n; i++) {
        delete[] alunos[i].notas;
    }
    delete[] alunos;

    return 0;
}
