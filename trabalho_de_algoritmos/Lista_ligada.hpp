#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__
class Lista_ligada {
private:
struct int_node {
        int value;
        int_node* next;
        int_node* prev; // usar para criar novo ponteiro
};
    int_node* head;
    int_node* tail;
    unsigned int size_;
public:
    Lista_ligada() {
        this->head = nullptr;
        this->tail = nullptr;
        this->size_ = 0;
    }
    ~Lista_ligada() {
        int_node *atual = this->head;
        int_node *i;
        while (atual != nullptr){
        i = atual;
        atual = atual->next;
        delete  i;
        }
    }
    unsigned int size() { // Retorna a quantidade de elementos armazenados
        return this->size_;
    }
    bool insert_at(unsigned int index, int value) {} // Insere elemento no índice index
    bool remove_at(unsigned int index) {} // Remove elemento do índice index
    int get_at(unsigned int index) { // Retorna elemento no índice index, −1 se índice inválido
        int retorno;
        if (index >= size_) retorno =  -1;
        else {
        int_node *atual = this->head;
        for (int i = 0; i < index ;i++) atual = atual->next;    // atual + 1 
        retorno =  atual->value; // retorne o atual valor 
        }
        return retorno;
    } 

    void clear() { // Remove todos os elementos, deixando o vetor no estado inicial
        int_node *atual = this->head;
        int_node *i;
        while (atual != nullptr){
        i = atual;
        atual = atual->next;
        delete  i;
        }
    } 
    void push_back(int value) { // Adiciona um elemento no ``final'' do vetor
        int_node *novo_no = new int_node;
        novo_no->value = value;
        novo_no->next = nullptr;
        novo_no->prev = this->tail;
        if (this->head == nullptr) this->head = novo_no;
        else this->tail->next = novo_no;
        this->tail = novo_no;
        size_++;
    } 

    void push_front(int value) { // Adiciona um elemento no ``início'' do vetor
        int_node *novo_no = new int_node;
        novo_no->value = value;
        novo_no->next = head;
        novo_no->prev = nullptr;
        if (this->head == nullptr) this->tail = novo_no;
        else this->head->prev = novo_no;
        this->head = novo_no;
        size_++;
    } 
    bool pop_back() { // Remove um elemento do ``final'' do vetor
     int retorno = true;
        if (this->tail == nullptr) retorno = false;
        int_node *atual = this->tail;
        this->tail = this->tail->prev;
        atual = atual->prev;
        size_--;
        return retorno;
    } 
    bool pop_front() { // Remove um elemento do ``início'' do vetor
       int retorno = true;
        if (this->tail == nullptr) retorno = false;
        int_node *atual = this->head;
        this->head = this->head->next;
        atual = atual->next;
        size_--;
        return retorno;
    } 
    int back(){ // Retorna o elemento do ``final'' do vetor
            if (this->head == nullptr) return -1;
            return this->head->value;
    } 
    int front(){ // Retorna o elemento do ``início'' do vetor
            if (this->tail == nullptr) return -1;
            return this->tail->value;
    } 
    bool remove(int value) {} // Remove value do vetor caso esteja presente
    int find(int value) { // Retorna o índice de value, −1 caso value não esteja presente
        int encontrou = -1, pos = 0;
        int_node *atual =  this->tail;
        while (atual != nullptr){
            if (atual->value == value) {
                encontrou = pos;
                break;
            }
        atual = atual->next; // isso server para andar pela lista
        pos++;
        }
        return encontrou;
    } 
    int count(int value) { // Retorna quantas vezes value occorre no vetor
        int cont = 0;
        int_node *atual = this->head;
        while (atual != nullptr){
            if (atual->value == value) cont++;
        atual = atual->next;  // isso server para andar pela lista
        }
        return cont;
    } 
    int sum() { // Retorna a soma dos elementos do vetor
        int soma = 0;
        int_node *atual = this->head;
        while(atual != nullptr){
            soma = soma + atual->value; // isso serve para dizer o valor de atual
            atual = atual->next; // isso serve para andar pela lista
        }
        return soma ;
    } 
};
#endif // __LINKED_LIST_IFRN__