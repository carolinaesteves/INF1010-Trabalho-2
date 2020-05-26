# INF1010 - Trabalho 2 - Sugestão de sufixos - Dicionário


O  Trabalho 2 consiste  em  implementar uma  árvore  de  prefixo(Trie) que  pode  ser utilizada  para  sugerir  palavras de  um  dicionário.  A  implementação  é  semelhante  a utilizada em programas editores de texto, ambientes de programação, sites de busca ou sugestões  de  palavras  na  digitação  em  celulares. Também  pode  ser  utilizado  em processadores de linguagem natural ou na identificação de substrings em uma string.
\
\
Há  um  projeto  criado  como  mesmo  código  apresentado  nos  slide se  contém  um programa  de  teste.  O  programa  pode  ser  modificado  para  incluir  outras  palavras  e  já inclui   as   seguintes:   {Bola,   Bolao,   Careca,   Carro,   Carroca,   Carruagem,   Homen, Homenagem, Joana, Joao}

### Deve incluir:
* main.c–Implementa um programa teste com o dicionário previamente fornecido
* trie.h–Interface para Árvores Trie
* trie.c–Implementação das funções 
\
\
Em trie.c devem ser implementadas as funções:
  * Trie *criaNo(char v)–Cria nó da árvore
  * void inserePalavra(Trie *t, char *palavra)–Insere palavra
  * int buscarPalavra(Trie *t, char *palavra)–Busca por palavra (completa)
  * Trie* buscarPrefixo(Trie *t, char *palavra)–Busca por prefixo (palavra completa ou parte inicial)
  * void removerPalavra(Trie *t, char *palavra)–Remove palavraDeve-se tomar cuidado para não remover outras palavras que compartilhem o mesmo prefixo.
\
\
Em trie.c as seguintes funções já estão implementadas:
  * Trie *criaTrie()–Cria a árvore Trie
  * void alphabetize(Trie * t)–mostra todas as possibilidades a partir do nó t(que pode ser a raiz ou um nó intermediário)
  * void alphabetize2(Trie * t, char prefixo[])–mesmo que alphabetizeporém adiciona a string fornecida no parâmetro“prefixo”antes da sequências de t
  * void liberar(Trie *t)–libera a árvore trie da memória
