#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__
class Vetor_dinamico {
private:
    int* array;
    unsigned int size_, capacity_;
    void increase_capacity_() { // Aumenta capacidade do seu ponteiro (array);
        int *new_array = new int[capacity_  * 2]; // Cria um novo ponteiro e reserva na memória tamanho capacity_ + 100;
        for (unsigned int i=0; i < size_; i++) new_array[i] = array[i]; // O novo ponteiro (new_array) receberá os mesmos valores que o outro ponteiro (array);
        delete [] array; // Libere a memória utilizada pelo ponteiro antigo(array);
        array =  new_array; // O ponteiro antigo (array) apontará para o ponteiro novo (new_array);
        capacity_ = capacity_  * 2; // Some a capacidade antiga + 100;
    }
public:
    Vetor_dinamico() { // Construtor
        this->size_ = 0; // Definindo tamanho para 0;
        this->capacity_ = 8; // Definindo a capacidade para 100;
        this->array = new int[capacity_]; // Criando novo ponteiro de tamanho capacidade.
    } 
    ~Vetor_dinamico() { // Destrutor
        delete [] this->array; // Libere a memória alocada por array.
    }
    unsigned int size() { // Retorna a quantidade de elementos armazenados
        return this->size_; 
    }
    unsigned int capacity() { // Retorna o espaço reservado para armazenar os elementos !!!
        return this->capacity_;
    }
    double percent_occupied() { // Retorna um valor entre 0.0 a 1.0 com o percentual da memória usada.
        double retorno = 0; // Supondo que o array está vazio ele não possui nada ocupado então retorno será 0.0;
        if (this->size_ == this->capacity_ ) retorno = 1.0; // Se o tamanho for igual capacidade quer dizer que tudo foi ocupado então retorno sera 1.0;
        else retorno = ((double)this->size_ / (double)this->capacity_); // Caso contrário o percentual ocupado sera a divisao de tamanho por capacidade;
        return retorno; // Retorne o valor de retorno.
    }
    bool insert_at(unsigned int index, int value) { // Insere elemento no índice index 
        int retorno = false;
        if (index < this->size_) retorno = true;
        if (this->capacity_ == this->size_) increase_capacity_();
        int atual = this->array[index], proximo = this->array[index + 1], ultimo = this->array[this->size_-1];
        this->array[index] = value;
        for (unsigned int i = index + 1; i < this->size_;i++){
                proximo = this->array[i]; 
                this->array[i] = atual;
                atual = proximo;
        }   
        this->array[this->size_] = ultimo;
        this->size_++;
        return retorno;
    }
   
    bool remove_at(unsigned int index) {
        int retorno = true;
        if (index >= size_) {
            retorno = false;
        }
        for (unsigned int i = index; i < size_ - 1; ++i) {
            array[i] = array[i + 1];
        }
        size_--;
        return retorno;
    }
   
    int get_at(unsigned int index) { // Retorna elemento no índice index, −1 se índice inválido  FUNCIONANDO
        if (index >= this->size_){
            this->array[index] = -1;
        }
        return this->array[index];
    }
   
    void clear() {  // Remove todos os elementos, deixando o vetor no estado inicial 
            size_ = 0;
            capacity_ = 0;
            delete [] array;
            array = new int[capacity_];
    }
   
    void push_back(int value) { // Adiciona um elemento no ``final'' do vetor FUNCIONANDO
        if (this->capacity_==this->size_) increase_capacity_(); 
        this->array[this->size_] = value;
        this->size_ +=1;    
    }
   
    void push_front(int value) { // Adiciona um elemento no ``início'' do vetor FUNCIONANDO
        if (this->size_==this->capacity_) increase_capacity_();
            int atual = array[0], proximo = array[1];
            for (unsigned int i = 0; i < this->size_+1;i++){
                proximo = this->array[i]; 
                this->array[i] = atual; 
                atual = proximo;
            }
        this->array[0] = value;
        this->size_+= 1;
        }

    bool pop_back() { // Remove um elemento do ``final'' do vetor FUNCIONANDO
        int retorno = false;
        if (this->size_ >= 1){
            this->size_--;
            retorno = true;
        }
        return retorno;
   }
   
    bool pop_front() {  // Remove um elemento do ``início'' do vetor FUNCIONANDO
        int retorno = false;
        if (this->size_ > 1){
            retorno = true;
            for (unsigned int i = 0; i <this->size_-1;i++){
                array[i] = array[i+1];
            }
        }
        this->size_--;
        return retorno;
    }
   
    int back(){ // Retorna o elemento do ``final'' do vetor FUNCIONANDO
        return this->array[this->size_-1];
    }
    int front(){ // Retorna o elemento do ``início'' do vetor 
        return this->array[0];
    }

        bool remove(int value) { // Remove value do vetor caso esteja presente FUNCIONANDO
        int retorno = false;
        for (unsigned int i = 0 ; i < this->size_; i++){
            if (array[i] == value){
                retorno = true;
                for (unsigned int j = i; j < this->size_ - 1; j++) array[j] = array[j + 1];
                break;
            }
        }
        this->size_--;
        return retorno;
        }
    int find(int value) { // Retorna o índice de value, −1 caso value não esteja presente FUNCIONANDO
        int valor = -1;
        for (unsigned int i = 0; i < this->size_; i++){
            if (array[i] == value){
                valor = i;
                break;
            }
        }
        return valor;
    }
   
    int count(int value) { // Retorna quantas vezes value occorre no vetor FUNCIONANDO
        int cont = 0;
        for (unsigned int i = 0; i < this->size_; i++){
            if (array[i] == value) cont++;
        }
        return cont;
    }
   
    int sum() { // Retorna a soma dos elementos do vetor FUNCIONANDO
        int soma = 0;
        for (unsigned int i = 0; i < this->size_; i++){
            soma = soma + array[i];
        }
        return soma;
    }
};
#endif // __ARRAY_LIST_IFRN__