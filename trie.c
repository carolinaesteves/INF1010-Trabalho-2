#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
#include "trie.h"

#define TAM 26
// calcula o indice do hash
#define CHAR_PARA_INDICE(c) ((int)c - (int)'a')

Trie *criaNo(char v)
{
    Trie * no = (Trie*)malloc(sizeof(Trie));
    
    // problema na alocação
    if(no == NULL)
        exit(1);
    
    no->letra = v;
    no->termino = 0;
    
    int i;
    for (i = 0; i < TAM; i++)
        no->filhos[i] = NULL; 
    
    no->ocupacao = 0;
    
    return no;
}

Trie *criaTrie()
{
    Trie *t = criaNo(' ');
    t->termino = 1;
    
    return t;
}


void inserePalavra(Trie *t, char *palavra)
{
    Trie* raiz = t;
    int i, indice;
    
    for (i = 0; i < strlen(palavra); i++)
    {
        // converte o char da palavra para o indice do vetor
        indice = CHAR_PARA_INDICE(tolower(palavra[i]));
        
        // criando novo nó pois caminho nao existe na trie
        if(raiz->filhos[indice] == NULL)
        {
            raiz->filhos[indice] = criaNo(tolower(palavra[i]));
            raiz->ocupacao ++;
        }
        raiz = raiz->filhos[indice];
    }
        raiz->termino = 1;
}


int buscarPalavra(Trie* t, char* palavra){   
    //i vai percorrer a palavra
    int tam, i, indice;
    tam = strlen(palavra);
    Trie* aux = t;
    
    for(i=0; i < tam; i++){
        //transformar a string em um inteiro
        indice = CHAR_PARA_INDICE(tolower(palavra[i])); 
        
        if(aux->filhos[indice] == NULL)
            return 0;
            
        aux = aux->filhos[indice];
    }
    return aux->termino;
}


Trie* buscarPrefixo(Trie *t, char *palavra)
{
    //i vai percorrer a palavra
    int tam, i, indice; 
    tam = strlen(palavra);
    Trie* aux = t;
    
    for(i=0; i < tam; i++){
        //transformar a string em um inteiro
        indice = CHAR_PARA_INDICE(tolower(palavra[i])); 
        if(aux->filhos[indice] == NULL)
            return 0;
        aux = aux->filhos[indice];
    }

    return aux;
}

int verificaVazia(Trie* t){ 
    for (int i = 0; i < TAM; i++) 
        if (t->ocupacao != 0) 
            return 0; 
            
    return 1; 
} 

int VerificaNoTerminal(Trie* p){
    return p->termino == 1;
}

int removeAux(Trie* t,char* palavra, int posicao, int tamanho){
    int i;
    
    if(t!=NULL){
        if(posicao==tamanho){
            //checa se a palavra esta na arvore
            //o nó não é mais o fim da palavra após a remoção
            if(t->termino ==1){
                t->termino = 0;
                
                //Verifica se a chave é única
                if(verificaVazia(t)){
                    return 1;
                }
                return 0;
            }
        }
        else
        {
            i = CHAR_PARA_INDICE(tolower(palavra[posicao]));
            if(removeAux(t->filhos[i], palavra, posicao+1, tamanho))
            {
                free(t->filhos[i]);
                t->filhos[i] = NULL;
                //checa se é o nó é um nó com palavra unica. Case 2 e 4 podem gerar nós com palavras únicas.
                    if(VerificaNoTerminal(t) == 0 && verificaVazia(t) == 1){
                        return 1;
                    }
                return 0;
            }
        }
    }   
    return 0;
}

void removerPalavra(Trie* t, char* palavra)
{
   //4 casos
   //1 - palavra não existe na trie
   //2 - palavra não é parte da outra, ela é única
   //3 - palavra existe como prefixo de outra palavra maior
   //4 - parte da palavra é parte da outra
    
    int tam = strlen(palavra);
    if(t>0){
        //checar se a palavra é unica na trie
        if(removeAux(t, palavra, 0, tam))
        free(t);
    }
}

void alphabetize2(Trie* t, char prefixo[])
{
    int i;
    
    // quando a palavra terminar, a imprime
    if (t->termino == 1){
        printf("%s\n", prefixo); 
    }

    for (i = 0; i < TAM; ++i)
    {
        if (t->filhos[i] != NULL)
        {
            char ch = t->filhos[i]->letra;
            
            int l = strlen(prefixo);
            if(l > 0){
                char novo_prefixo[l];
                // printf("%s\n",prefixo);
                strcpy(novo_prefixo, prefixo);
                strncat(novo_prefixo, &ch, 1); 
                alphabetize2(t->filhos[i], novo_prefixo);
            }
            else{
                char novo_prefixo[] = {ch, '\0'};
                alphabetize2(t->filhos[i], novo_prefixo);
            }
        }
    }
}

void alphabetize(Trie* t){
    char prefixo[] = "";
    alphabetize2(t, prefixo);
}

void liberar(Trie *t){
    
    int i;
    for (i = 0; i < TAM; ++i)
        if (t->filhos[i] != NULL)
            liberar(t->filhos[i]);
    
    free(t);
}

