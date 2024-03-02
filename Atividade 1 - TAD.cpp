
#include<stdio.h>
#define N 500

struct Livro {
    char titulo[100];
    char autor[100];
    int numeroDepaginas;


};

struct Biblioteca {
    Livro livros[10];
    int qtdLivros;

    Biblioteca() {
        qtdLivros = 0;
    }

    void lerLivro() {
        if (qtdLivros >= 10) {
            printf("Limite não permitido.\n");
            return;
        }

    }

    void imprimirTodos() {
        if (qtdLivros == 0) {
            printf("Contém nenhum livro.\n");
            return;
        }
        printf("Livros na biblioteca:\n");
        for (int i = 0; i < qtdLivros; i++) {
            printf("%s - %s - %d páginas.\n", livros[i].titulo, livros[i].autor, livros[i].numeroDepaginas);
        }
    }

    void imprimirMaiorLivro() {
        if (qtdLivros == 0) {
            printf("Contém nenhum livro.\n");
            return;
        }
        int maiornumeroDepaginas = livros[0].numeroDepaginas;
        int indiceMaior = 0;
        for (int i = 1; i < qtdLivros; i++) {
            if (livros[i].numeroDepaginas > maiornumeroDepaginas) {
                maiornumeroDepaginas = livros[i].numeroDepaginas;
                indiceMaior = i;
            }
        }
        printf("Livro com mais páginas:\n");
        printf("%s - %s - %d páginas.\n", livros[indiceMaior].titulo, livros[indiceMaior].autor, livros[indiceMaior].numeroDepaginas);
    }
};


       void lerLivro(Biblioteca &b) {
       b.lerLivro();
}

       void imprimirTodos(Biblioteca &b) {
       b.imprimirTodos();
}

       void imprimirMaiorLivro(Biblioteca &b) {
       b.imprimirMaiorLivro();
}

int main() {

    Biblioteca b;

      void (*funcoesMenu[])(Biblioteca &) = {lerLivro, imprimirTodos, imprimirMaiorLivro};

      int opcao;

      do {
        printf("\n1. Inserir livro\n");
        printf("2. Imprimir todos\n");
        printf("3. Imprimir maior\n");
        printf("0. Sair\n");
        scanf("%d%*c", &opcao);
        if (opcao >= 1 && opcao <= 3) {
            funcoesMenu[opcao - 1](b);
        } else if (opcao != 0) {

        }
    } while (opcao != 0);

return 0;
}
