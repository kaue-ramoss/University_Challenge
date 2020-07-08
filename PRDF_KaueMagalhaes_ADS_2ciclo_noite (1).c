#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct dados {
        int qa;
        int q;
        char dv[11];
        char nome[40];
        char codigo[9];};

int main(){
        struct dados a;
        struct dados *b;
        int op;
        int i;
        int tam;
        b = & a;
        tam = sizeof(a);
while(1){
printf(" 1 -Adicionar Produto  \n");
printf(" 2 -Lista de Produtos  \n");
printf(" 3 -Pesquisa de nome  \n");
printf(" 4 -Pesquisar de letra  \n");
printf(" 5 -Pesquisar data de validade  \n");
printf(" 6 -Pesquisar nomes nao disponiveis  \n");
printf(" 7 -Movimento quantidade em estoque  \n");
printf(" 8 -Alterar produto\n");
printf(" 9 -Excluir produto  \n");
printf(" 10 -Sair  \n");
printf("\n Digite a opcao desejada: ");
scanf("%d", &op);
getchar();
    switch(op){
                case 1 : inclui(b, tam);
                break;
                case 2: lista(b, tam);
                break;
                case 3: pnome(b, tam);
                break;
                case 4: pletra(b, tam);
                break;
                case 5: pvalidade(b, tam);
                break;
                case 6: nomdisp(b, tam);
                break;
                case 7: movq(b, tam);
                break;
                case 8: alterar(b, tam);
                break;
                case 9: excluir(b, tam);
                break;
                case 10: exit(0);
                break;
                default:
                printf("\n Opção invalida\n\n\n");
                system("pause");
                break;}}}
void inclui(struct dados *b, int tam){
    FILE *p, *p1;
    int cont = 0;
    int i;
    p1 = fopen("cont.txt", "r");
    fscanf(p1,"%d",&cont);
    printf("contador antes %d\n",cont);
    fclose(p1);
    for(i=0;i<tam;i++){
        b -> nome[i]=0;
        b -> dv[i]=0;
        b -> codigo[i]=0;}
    p = fopen("dados.txt", "a");
    if( p == NULL){
        printf("\nERRO");
        exit(0);}
    printf("Insira o codigo numerico:\n ");
    gets(b->codigo);
    printf("Insira a descricao:\n");
    gets(b->nome );
    printf("Insira q quantidade numerica:\n");
    scanf("%d",&b->qa);
    printf("Insere a quantidade minima:\n");
    scanf("%d",&b->q);
    printf("Insere a data de validade:\n ");
    getchar();
    gets(b->dv);
    system("pause");
    fwrite(b, tam,1,p);
    fclose(p);
    cont++;
    p1 = fopen("cont.txt", "w");
    fprintf(p1,"%d",cont);
    printf("contador depois %d\n",cont);
    fclose(p1);}
void lista(struct dados *b, int tam){
    FILE *p, *p1;
    int i;
    int cont,comp;
    p1 = fopen("cont.txt", "r");
    fscanf(p1,"%d",&cont);
    printf("%d\n",cont);
    fclose(p1);
    p = fopen("dados.txt", "r");
    if( p== NULL){
        printf("\nERRO\n");
        exit(0);}
    for(i=0;i<cont; i++){
    comp = i*tam;
    fseek(p,comp,0);
    fread(b,tam,1,p);
        printf("codigo %s\n",b->codigo);
        printf("descricao: %s\n",b->nome);
        printf("quantidade atual %d\n",b->qa);
        printf("quantidade minima %d\n",b->q);
        printf("data de validade %s\n\n",b->dv);
        printf("\n");
        system("pause");
        printf("\n");}
        return i;
        fclose(p);}
int pnome(struct dados *b, int tam){
    FILE *p,*p1;
    char nome1[40];
    int y, x;
    int cont;
    printf("Informe um nome para pesquisa: ");
    gets(nome1);
    p = fopen("dados.txt", "r");
    p1 = fopen("cont.txt", "r");
    fscanf(p1,"%d",&cont);
    fclose(p1);
    printf("%d\n",cont);
    for(y=0;y<cont;y++){
        fread(b,tam,1,p);
        for(x = 0; nome1[x] != '\0';x++){
            if(nome1[x] != b -> nome[x]){
                break;}}
    if(nome1[x] == '\0' && b -> nome[x] == '\0'){
        printf("n. do reg.: %d\n",y);
        return y;}}
    printf("reg. nao existe\n");
    system("Pause");
    fclose(p);}
void pletra(struct dados*b, int tam){
FILE *p , *p1;
char l;
int cont,x;
printf("\n Primeira letra a ser pesquisada: ");
scanf("%c",&l);
    p = fopen("dados.txt", "r");
    p1 = fopen("cont.txt", "r");
    fscanf(p1,"%d",&cont);
    fclose(p1);
    printf("%d\n",cont);
for(x=0;x<cont;x++){
    fread(b,tam,1,p);
    if(l==b->codigo[0]){
        printf("\n Nome registrado em %d\n",x+1);
        printf("\n O produto e %s",b->codigo);
        system("pause");}
    printf("\n Letra nao encontrada ");
    system("pause");}
    fclose(p);}
void pvalidade(struct dados*b, int tam){
FILE *p , *p1;
char dval[11];
int cont,x,y;

printf("\n Procure pela data de validade: ");
scanf("%s",&dval);
    p = fopen("dados.txt", "r");
    p1 = fopen("cont.txt", "r");
    fscanf(p1,"%d",&cont);
    fclose(p1);
    printf("%d\n",cont);
for(y=0;y<cont;y++){
    fread(b,tam,1,p);
    for(x=0;dval[x]!='\0';x++){
        if(dval[x]!=b->dv[x])
        break;}
        if(dval[x]=='\0' && b->dv[x]=='\0'){
        printf("\n Validade no registro %d\n\n",y+1);
        printf("\n O produto e: %s\n\n",b->nome);
        system("pause");
        break;}
        printf("\n\n Nao encontrado\n\n");
        system("pause");
        break;}
        fclose(p);}
void nomdisp(struct dados *b, int tam){
    FILE *p , *p1;
    int cont,y;
    p = fopen("dados.txt", "r");
    p1 = fopen("cont.txt", "r");
    fscanf(p1,"%d",&cont);
    fclose(p1);
    printf("%d\n",cont);
    for(y=0;y<cont;y++){
    fread(b,tam,1,p);
    if(b->qa==0);
    printf("\n\n PRODUTO INDISPONIVEL\n\n");
    system("PAUSE");}
    fclose(p);}

void movq(struct dados *b, int tam){
    FILE *p , *p1;
    int cont,y,comp;
    p = fopen("dados.txt", "r+");
    p1 = fopen("cont.txt", "r");
    fscanf(p1,"%d",&cont);
    fclose(p1);
    printf("%d\n",cont);
    y=pnome(b,tam);
    comp=y*tam;
    fseek(p,comp,0);
    fread(b,tam,1,p);
    printf("\n missing\n\n");
    system("PAUSE");}
void alterar(struct dados *b, int tam){
    FILE *p,*p1;
    int cont,x,y;
    p = fopen("dados.txt", "r+");
    p1 = fopen("cont.txt", "r");
    fscanf(p1,"%d",&cont);
    fclose(p1);
    printf("%d\n",cont);
    x=pnome,tam;
    y= x*tam;
    fseek(p,y,0);
    fread(b,tam,1,p);
    printf("Insira o codigo numerico:\n ");
    gets(b->codigo);
    printf("Insira a descricao:\n");
    gets(b->nome );
    printf("Insira a quantidade numerica:\n");
    scanf("%d",&b->qa);
    printf("Insere a quantidade minima:\n");
    scanf("%d",&b->q);
    printf("Insere a data de validade:\n ");
    getchar();
    gets(b->dv);
    y=x*tam;
    fseek(p,y,0);
    fwrite(b,tam,1,p);
    system("PAUSE");
    fclose(p);}
void excluir(struct dados *b, int tam){
    FILE *p,*p1;
    int cont,x,y;
    p = fopen("dados.txt", "r+");
    p1 = fopen("cont.txt", "r");
    fscanf(p1,"%d",&cont);
    fclose(p1);
    printf("%d\n",cont);
    x=pnome(b,tam);
    y= x*tam;
    fseek(p,y,0);
    fread(b,tam,1,p);
    printf("\n Digite um char nos campos: Codigo numerico, Descricao e Validade");
    printf("\n Digite um inteiro nos campos: Quantidade Numerica e Quantidade Minima");
    printf("Insira o codigo numerico:\n\n ");
    gets(b->codigo);
    printf("Insira a descricao:\n\n");
    gets(b->nome );
    printf("Insira a quantidade numerica:\n\n");
    scanf("%d",&b->qa);
    printf("Insere a quantidade minima:\n\n");
    scanf("%d",&b->q);
    printf("Insere a data de validade:\n\n ");
    getchar();
    gets(b->dv);
    y=x*tam;
    fseek(p,y,0);
    fwrite(b,tam,1,p);
    system("PAUSE");}
