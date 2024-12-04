#include <iostream>
using namespace std;
template <class T> class Lista{
    private:
        template <class G> class Celula{
            public:
            Celula<G> *Prox;
            T Valor;
            Celula(const G &v){
                this->Valor=v;
                Prox = nullptr;
            }
        };
        int Tamanho;
        Celula<T> *Fim;
        Celula<T> *Inicio;
    public: 
        Lista(){
            Inicio = Fim = nullptr;
            Tamanho = 0;
        }
        ~Lista(){
            Celula<T> *x;
            while(Inicio!=nullptr){
                x = Inicio;
                Inicio = Inicio->Prox;
                delete x;
            }
        }
        bool AdicionarNoFim(const T &Valor){
            if(Fim == nullptr){
                Inicio = Fim = new Celula<T>(Valor);
                Tamanho++;
            }else{
                this->Fim->Prox = new Celula<T>(Valor);
                this->Fim = Fim->Prox;
                Tamanho++;
            }
            return 1;
        }
        bool AdicionarNoComeco(const T &Valor){
            if(Inicio == nullptr){
                Inicio = Fim = new Celula<T>(Valor);
                Tamanho++;
            }else{
                Celula<T> *x = new Celula<T>(Valor);
                x->Prox = Inicio;
                Tamanho++;
                Inicio = x;
            }
            return true;
        }
        bool AdicionarNoMeio(const T &item, const int &posicao){
            Celula<T> *nValor, *x;
            x = this->Inicio;
            for(int i = 0; i < posicao-1; i++){
                x = x->Prox;
            }
            nValor =new Celula<T>(item);
            nValor->Prox = x->Prox;
            x->Prox = nValor;
            this->Tamanho++;
            return true;
        }
        bool RemoverDoFim(){
        if(this->Inicio == nullptr) { 
            return false; 
        } else { 
            if(this->Inicio->Prox == nullptr) {//só tem um elemento! 
                delete this->Inicio; 
                this->Inicio = this->Fim = nullptr; 
            } else { 
                Celula<T> *x=this->Inicio, *x1; 
                while(x->Prox->Prox!= nullptr){  
                    x=x->Prox; 
                }
                x1 = x;
                delete Fim;
                this->Fim = x1;
                x->Prox = nullptr;
            } 
            this->Tamanho--; 
            return true; 
        }
        }
        bool RemoverDoInicio(){
            if(this->Inicio==nullptr){
                return false;
            }else{
                Celula<T> *x;
                x = this->Inicio;
                this->Inicio = this->Inicio->Prox;
                delete x;
                Tamanho--;
                return true;
            }
            
        }
        bool RemoverDoMeio(int const &pos){
            if(pos<=Tamanho){
                Celula<T> *x = this->Inicio, *proc;
                for(int i = 0; i < pos-1; i++){
                    x = x->Prox;
                    cout<<x->Prox<<endl;
                }
                proc = x->Prox;
                x->Prox = x->Prox->Prox; 
                if(x->Prox == nullptr){
                    this->Fim = x;
                    delete proc;
                    this->Tamanho--;  
                }
                return true;
            }else{
                return false;
            }
        }        
        void Mostrar(){
            Celula<T> *x = this->Inicio;
            cout<<"[ ";
            while(x != nullptr){
                cout<<x->Valor<<" ";
                x=x->Prox;
            }
            cout<<"]"<<endl;
        }
        T MostrarNoMeio(int const &pos){
            if(pos<=Tamanho && pos >= 0){
                Celula<T> *x;
                x = this->Inicio;
                for(int i = 0; i < pos; i++){
                    x=x->Prox;
                }
                return x->Valor;
            }else{
                cout<<"Erro: a posicao escolhida nao existe na lista!"<<endl;
                return 0;
            }
            
        }
        int RetornarTamanho(){
            return Tamanho;
        }
};


int main(){
    Lista<int> L;
    for(int i = 0; i<100; i++){
        L.AdicionarNoFim(i);
    }
    cout<<L.RetornarTamanho()<<endl;
    L.Mostrar();
    L.RemoverDoMeio(69);
    L.RemoverDoInicio();
    L.MostrarNoMeio(0);
    L.Mostrar();
    return 0;
}