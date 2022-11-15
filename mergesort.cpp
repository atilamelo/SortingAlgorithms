#include <iostream>
#include<cstdlib>

/* Segunda parte do algoritmo mergesort, nessa parte, une-se duas listas    *
 * (subArrayLeft e subArrayRight) de forma que estejam ordenadas, para isso *
 * se compara o topo de cada pilha até criar um array que esteja ordenado   */
void merge(int array[], int inicio, int meio, int fim){
    int tamanho_direita = fim-meio;         // Quantidade de elementos no array da direita 
    int tamanho_esquerda = meio-inicio;     // Quantidade de elementos no array da esquerda
    int subArrayLeft[tamanho_esquerda];     
    int subArrayRight[tamanho_direita];
    int top_left, top_right;                // Topo de cada pilha

    // Inicialmente, o topo de cada pilha é definido como 0 
    top_right = top_left = 0;

    // Cópia da parte esquerda 
    for(auto i = 0; i < tamanho_esquerda; i++){
        subArrayLeft[i] = array[i+inicio];
    }
    // Cópia da parte direita  
    for(auto i = 0; i < tamanho_direita; i++){
        subArrayRight[i] = array[i+meio];
    }

    for(auto i = inicio; i < fim; i++){
        if(top_left >= tamanho_esquerda){    // Checa se o topo da pilha direita está fora dos endereços do array
            array[i] = subArrayRight[top_right];
            top_right++; 
        }
        else if(top_right >= tamanho_direita){     // Checa se o topo da pilha esquerda está fora dos endereços do array
            array[i] = subArrayLeft[top_left]; 
            top_left++; 
        }
        else if(subArrayLeft[top_left] <= subArrayRight[top_right]){   // Compara o topo de cada array 
            array[i] = subArrayLeft[top_left];
            top_left++; 
        }else{ 
            array[i] = subArrayRight[top_right]; 
            top_right++; 
        }

    }

}

// Função recursiva para implementar o mergesort
void mergesort(int * array,  int inicio, int fim){
    if(fim - inicio > 1){
        int meio = (fim + inicio) / 2; 
        mergesort(array, inicio, meio);
        mergesort(array, meio, fim);
        merge(array, inicio, meio, fim); 
    }

}


int main(){
    int lista_invertida[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1}; 
    int lista_aleatoria[15], i; 

    /* Usa o horário do sistema como semente para a geração de números, evita números
     * repetidos a cada execução */
    srand((unsigned) time(NULL)); 

    std::cout << "Lista aleatória desordenada: "; 
    // Preenche a lista com números aleatórios
    for(i = 0; i < 15; i++){
        lista_aleatoria[i] = rand() % 10; // Gera um número aleatório entre 1 e 9 
        std::cout << lista_aleatoria[i] << " "; 
    } 

    mergesort(lista_aleatoria, 0, 15); 

    std::cout << std::endl << "Lista aleatória ordenada: "; 
    // Escreve a lista aleatória  
    for(i = 0; i < 15; i++){
        std::cout << lista_aleatoria[i] << " "; 
    } 

    std::cout << "\n\nLista invertida: "; 
    // Escreve a lista invertida 
    for(i = 0; i < 9; i++){
        std::cout << lista_invertida[i] << " "; 
    }

    mergesort(lista_invertida, 0, 9); 

    std::cout << "\nLista invertida ordenada: "; 
    // Escreve a lista invertida
    for(i = 0; i < 9; i++){
        std::cout << lista_invertida[i] << " "; 
    } 

}
