#include <stdio.h>

// Definição da estrutura Voluntario
struct Voluntario {
    float peso;
    float altura;
    int idade;
    float IMC; // Adicionando campo para armazenar o IMC
};

// Função para calcular o IMC de um voluntário
void calcularIMC(struct Voluntario *voluntario) {
    voluntario->altura /= 100; // Convertendo altura de cm para m
    float altura_quadrado = voluntario->altura * voluntario->altura;
    voluntario->IMC = voluntario->peso / altura_quadrado;
}

// Função para calcular a média do IMC dos voluntários
float calcularMediaIMC(struct Voluntario *voluntarios, int tamanho) {
    float soma_IMC = 0;
    for (int i = 0; i < tamanho; i++) {
        soma_IMC += voluntarios[i].IMC;
    }
    return soma_IMC / tamanho;
}

int main() {
    // Exemplo de utilização das funções
    struct Voluntario voluntarios[5] = {
        {70, 170, 25},  // Peso = 70 kg, Altura = 170 cm, Idade = 25 anos
        {65, 165, 30},  // Peso = 65 kg, Altura = 165 cm, Idade = 30 anos
        {80, 180, 35},  // Peso = 80 kg, Altura = 180 cm, Idade = 35 anos
        {75, 175, 40},  // Peso = 75 kg, Altura = 175 cm, Idade = 40 anos
        {85, 185, 45}   // Peso = 85 kg, Altura = 185 cm, Idade = 45 anos
    };

    // Calcula o IMC de cada voluntário
    for (int i = 0; i < 5; i++) {
        calcularIMC(&voluntarios[i]);
    }

    // Calcula a média do IMC dos voluntários
    float media_IMC = calcularMediaIMC(voluntarios, 5);

    // Exibe os resultados
    printf("IMC dos voluntários:\n");
    for (int i = 0; i < 5; i++) {
        printf("Voluntário %d: %.2f\n", i+1, voluntarios[i].IMC);
    }
    printf("Média do IMC: %.2f\n", media_IMC);

    return 0;
}