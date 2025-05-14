#include <stdio.h>
#include <stdlib.h>

int verificacao(int i, int n, int linha, int coluna, char **mat){
    
    for(i = 0; i < linha; i++){
        
        if(mat[i][coluna] == 'Q'){
            return 0;
        }
        
        if(coluna - (linha - i) >= 0 && mat[i][coluna - (linha - i)] == 'Q'){
            return 0;
        }
        
        if(coluna + (linha - i) < n && mat[i][coluna + (linha - i)] == 'Q'){
            return 0;
        }
        
    }
    
    return 1;
}

int solucao(int i, int n, int linha, int coluna, char **mat){
    
    if (linha >= n){
        return 1;
    }
    
    for(coluna = 0; coluna < n; coluna++){
        
        if (verificacao(i, n, linha, coluna, mat)){
            
            mat[linha][coluna] = 'Q';
            
            if (solucao(i, n, linha + 1, coluna, mat)){
                return 1;
            }
            
            mat[linha][coluna] = '.';
        }
    }
    
    return 0;
}
  
void imprimir(int i, int j, int n, char **mat){
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
    
}

int main(){
    
    int n, i, j;
    char **mat;
    
    
    printf("Digite o tamanho do tabuleiro: ");
    scanf("%d", &n);
    
    mat = calloc(n, sizeof(char*));
    
    for(i = 0; i < n; i++){
        mat[i] = calloc(n, sizeof(char));
    }
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            mat[i][j] = '.';
        }
    }
    
    if (solucao(i, n, 0, 0, mat)){
        
        imprimir(i, j, n, mat); 
        
    } 
    
    else {
        printf("Nao foi possivel encontrar uma solucao.\n");
    }

    system("pause");
    
    return 0;
}