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
    
    if(no==NULL)
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
        //raiz->termino = 0;
 
        indice = CHAR_PARA_INDICE(tolower(palavra[i]));
        
        // criando novo nó pois caminho nao existe
        if(raiz->filhos[indice] == NULL)
        {
            raiz->filhos[indice] = criaNo(tolower(palavra[i]));
            raiz->ocupacao ++;
            // print para checar cada letra nova
            // printf("%c\n",raiz->filhos[indice]->letra);
        }
        
        raiz = raiz->filhos[indice];
    }
        raiz->termino = 1;
}


int buscarPalavra(Trie *t, char *palavra){   
    int tam,i,indice; //i vai percorrer a palavra
    tam = strlen(palavra);
    Trie* aux = t;
    
    for(i=0; i < tam; i++){
        indice = CHAR_PARA_INDICE(tolower(palavra[i])); //transformar a string em um inteiro
        if(aux->filhos[indice] == NULL)
            return 0;
        aux = aux->filhos[indice];
    }

    return 1;
}


Trie* buscarPrefixo(Trie *t, char *palavra)
{
  /* implementar busca por prefixo */
}

void removerPalavra(Trie *t, char *palavra)
{
 /* implementar remoca de palavras */
}


void alphabetize2(Trie * t, char prefixo[])
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

void alphabetize(Trie * t){
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