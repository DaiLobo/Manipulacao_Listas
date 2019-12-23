#include <iostream>

using namespace std;

struct no {
    int info;
    struct no *ant;
    struct no *prox;
};
typedef struct no *noPtr;

struct no2{
	int info;
	struct no2 *prox;
};
typedef struct no2 *noPtr2;

int total = 0;
noPtr2 inicio3 = NULL, fim;

    int inserir(noPtr *, int);
    void retirar(noPtr *);
    void listar(noPtr);
    bool listaVazia(noPtr);
    void somar(noPtr, noPtr);
    void maiorElemento(noPtr, noPtr);
    void Maior(noPtr, noPtr);
    void intercala(noPtr, noPtr, noPtr2 *);
    void listar3();

    main()
{
    int op;
    int qtde1 = 0, qtde2 = 0;
    noPtr inicio = NULL;
    noPtr inicio2 = NULL;

 do {
    cout << endl
         <<"\n--------------MENU-------------------" <<endl
         <<"\n--->1: Inserir elemento na lista 1"
         <<"\n---->2: Inserir elemento na lista 2" <<endl
         <<"\n--->3: Retirar elemento da lista 1"
         <<"\n---->4: Retirar elemento da lista 2" <<endl
         <<"\n--->5: Listar elementos da lista 1"
         <<"\n---->6: Listar elementos da lista 2" <<endl
         <<"\n--->7: Somar valores da lista 1 e 2"
         <<"\n---->8: Somar valores da lista 2" <<endl
         <<"\n--->9: Verificar qual o maior elemento"
         <<"\n--->10: Ver qual lista eh maior"<<endl
         <<"\n--->11: Intercalar listas"
         <<"\n--->12: Listar a Lista intercalada"
         <<"\n--->0: Sair"
         <<"\n\nDigite a opcao (0 - 3): ";
    cin >> op;
switch (op)
{
    case 1: qtde1 = inserir(&inicio, qtde1); cout << qtde1; break;
    case 2: qtde2 = inserir(&inicio2, qtde2); cout << qtde2; break;
    case 3: retirar(&inicio); break;
    case 4: retirar(&inicio2); break;
    case 5: listar(inicio); break;
    case 6: listar(inicio2); break;
    case 7: somar(inicio, inicio2); break;
//    case 8: somar(&inicio2); break;
    case 9: maiorElemento(inicio, inicio2); break;
    case 10: Maior(inicio, inicio2); break;
    case 11: intercala(inicio, inicio2, &fim);
                    cout << "lista criada!"; break;
    case 12: listar3(); break;

}
 } while (op != 0);
}
    bool listaVazia(noPtr inicio){

        if(inicio == NULL){
            return true;
        }
        else{
            return false;
        }
    }

    int inserir (noPtr * i, int q) {

    noPtr p = new no;

    cout << "\nDigite o valor do elemento: ";
    cin >> p->info;

    if (listaVazia(*i))
   {
    *i = p;
    p->prox = NULL;
    p->ant = NULL;
   }

    else {
    p->ant= NULL;
    p->prox = *i;
    (*i)->ant = p;
    *i = p;
    }

 total++;

    q++;
    return q;

}

void retirar (noPtr * i)
{
    noPtr p = *i;

    if (!listaVazia(*i))
 {
    if (p->prox == NULL)
    *i = NULL;
    else
 {
    *i = p->prox; // *i = *i->prox
    (*i)->ant = NULL; //p->prox->ant
 }
    delete(p);
    cout << "\nO elemento foi retirado da lista!\n";
 }
    else cout << "\n\nLista esta Vazia!\n";

    total--;
}

void listar(noPtr p)
{
    if (!listaVazia(p))
 {
    cout << "\nElementos da lista : \n";
    cout << "INICIO"<<endl;

    while (p != NULL)
{
    cout << " --> " << p->info;
    p = p->prox;
 }
    cout << " -- > NULL"<<endl;
}
    else
    cout << "\n\nLista esta Vazia!\n";
}

void somar(noPtr l1, noPtr l2){

    int soma = 0;

    while (l1 != NULL || l2 != NULL){
        if (l1 != NULL){
            soma = soma + l1->info;
            l1 = l1->prox;
        }
        if (l2 != NULL){
            soma = soma + l2->info;
            l2 = l2->prox;
        }
    }

    cout << "\n\nSoma dos valores de L1 e L2 " << soma <<endl;
}

void Maior(noPtr l1, noPtr l2){

    int x = 0;
    int y = 0;

    while (l1 !=NULL){
        x++;
        l1 = l1->prox;
    }
    while (l2 != NULL){
        y++;
        l2 = l2->prox;
    }

    if (x > y){
        cout << "\nLista 1 tem mais elemento que lista 2"<<endl;
    }
    else if (y > x){
        cout << "\nLista 2 tem mais elemento que lista 1"<<endl;
    }
    else if ( x == y){
        cout << "\nAs listas tem o mesmo tamanho" <<endl;
    }
}

void maiorElemento(noPtr l1, noPtr l2){

    int x = l1->info;
    int y = l2->info;

    while (l1->prox != NULL){

        if (x < l1->info){
            x = l1->info;
        }

        l1 = l1->prox;

    }
    if(l1->prox == NULL){
		if(x < l1->info){
			x = l1->info;
		}
	}


     while (l2->prox != NULL){

        if (y < l2->info){
            y = l2->info;
        }
        l2 = l2->prox;
    }

    if(l2->prox == NULL){
		if(y < l2->info){
			y = l2->info;
		}
    }
  

    if (x > y){
        cout << "\nMaior elemento e o "<< x <<" e esta na Lista 1";
    }
    else if (y > x){
        cout << "\nMaior elemento e o "<<y<<" e esta na lista 2";
    }
    else if (x == y){
        cout << "\nO maior elemento da lista L1 e L2 sao iguais "<< x << " = " << y;
    }
}


void intercala(noPtr l1, noPtr l2, noPtr2 *f){

    while(l1 != NULL || l2 != NULL){
     if(inicio3 == NULL){
        noPtr2 p = new no2;
		p->info = l1->info;
		inicio3 = p;
		*f = p;
		p->prox = *f;
		l1 = l1->prox;
		}
     else{
		if(l2 != NULL){
            noPtr2 p = new no2;
			p->prox = inicio3;
			p->info = l2->info;
			inicio3 = p;
			(*f)->prox = p;
			l2 = l2->prox;
			}
        if(l1 != NULL){
            noPtr2 p = new no2;
            p->prox = inicio3;
            p->info = l1->info;
            inicio3 = p;
            (*f)->prox = p;
            l1 = l1->prox;
			}
		}
	}
}

void listar3(){

	noPtr2 aux = inicio3;

	cout << "\nElementos da lista 3:\n";
	cout << "INICIO";
	for(int i = 0; i < total; i++){
		cout << "-->" << aux->info;
		aux = aux->prox;
	}
	cout << "--> NULL";
}

