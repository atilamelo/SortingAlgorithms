#include <iostream>
#include<cstdlib>


void merge(int array[], int inicio, int meio, int fim){
    int length_right = fim-meio; 
    int length_left = meio-inicio;  
    int subArrayLeft[length_left]; 
    int subArrayRight[length_right];
    int top_left, top_right;

    top_right = top_left = 0;

    // Deep copy of left part
    for(auto i = 0; i < length_left; i++){
        subArrayLeft[i] = array[i+inicio];
    }
    // Deep copy of right part
    for(auto i = 0; i < length_right; i++){
        subArrayRight[i] = array[i+meio];
    }

    for(auto i = inicio; i < fim; i++){
        if(top_left >= length_left){    // Check if the top right is out of range
            array[i] = subArrayRight[top_right];
            top_right++;
        }
        else if(top_right >= length_right){     // Check if the top left is out of range
            array[i] = subArrayLeft[top_left]; 
            top_left++; 
        }
        else if(subArrayLeft[top_left] < subArrayRight[top_right]){   // Compare the top of each array
            array[i] = subArrayLeft[top_left];
            top_left++; 
        }else{ 
            array[i] = subArrayRight[top_right]; 
            top_right++; 
        }

    }

}

// Recursive function to implement mergesort
void mergesort(int * array,  int inicio, int fim){
    if(fim - inicio > 1){
        int meio = (fim + inicio) / 2; 
        mergesort(array, inicio, meio);
        mergesort(array, meio, fim);
        merge(array, inicio, meio, fim); 
    }

}


int main(){
    int inverted_list[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1}; 
    int random_list[15], i; 

    srand((unsigned) time(NULL)); //Using time system as seed 

    std::cout << "Random list unordered: "; 
    // Fill the random list 
    for(i = 0; i < 15; i++){
        random_list[i] = rand() % 10; // Generate random number between 1 and 9 
        std::cout << random_list[i] << " "; 
    } 

    mergesort(random_list, 0, 15); 

    std::cout << std::endl << "Random list ordered: "; 
    // Print Random List  
    for(i = 0; i < 15; i++){
        std::cout << random_list[i] << " "; 
    } 

    std::cout << "\n\nInverted list: "; 
    // Fill the random list 
    for(i = 0; i < 9; i++){
        std::cout << inverted_list[i] << " "; 
    }

    mergesort(inverted_list, 0, 9); 

    std::cout << "\nInverted list ordered: "; 
    // Fill the random list 
    for(i = 0; i < 9; i++){
        std::cout << inverted_list[i] << " "; 
    } 

}
