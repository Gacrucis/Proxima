#include <iostream>

using namespace std;

struct nodo
{
	int codigo;
    string nombre;
    int nivel;
	nodo *sig;
};

class linkedList{

    nodo *firstNode, *lastNode;
    int lenght;

    public:

    linkedList(){

        this->firstNode = NULL;
        this->lastNode = NULL;
        this->lenght = 0;
    }

    ~linkedList(){
        
        int i = 0;

        cout << this->to_string() << endl;

        while(this->firstNode->sig != NULL){

            cout << "Borrando " << this->get(0) << " en la posicion " << "["<<i<<"]"<<endl;

            nodo *previousNode = this->firstNode;
            this->firstNode = this->firstNode->sig;

            this->lenght -= 1;
            i += 1;

            delete previousNode;

        }

        if(this->lenght > 0){
            cout << "Borrando " << this->get(0) << " en la posicion " << "["<<i<<"]"<<endl;
            this->lenght -= 1;
            delete this->firstNode;
            cout << "Borrando lista encadenada" <<endl;
        } 
    }

    void read_student(){

        int codigo, nivel;
        string nombre;

        cout << "Inserte el codigo de estudiante: ";
        cin >> codigo;

        cout << "Inserte el nombre de estudiante: ";
        cin >> nombre;

        cout << "Inserte el nivel de estudiante: ";
        cin >> nivel;

        this->add(codigo, nombre, nivel);
        
        cout << this->to_string() << endl;
    }

    void remove(int index){

        nodo* erasedNode = this->get_node(index);

        

        if(index == 0){
            this->firstNode = this->firstNode->sig;
            delete erasedNode;
            this->lenght -= 1;
            return;
        }

        nodo *previousNode;
        previousNode = this->get_node(index-1);

        previousNode->sig = erasedNode->sig;
        delete erasedNode;

        this->lenght -= 1;
    }

    void remove_by_code(int codigo){

        int foundNodeIndex = this->search_by_code(codigo);

        if(foundNodeIndex != -1){

            cout << "Borrando " << this->get(foundNodeIndex) << " en la posicion " << "["<<foundNodeIndex<<"]"<<endl;
            this->remove(foundNodeIndex);

            cout << this->to_string() << endl;

        } else {
            cout << "Codigo " << codigo << " No encontrado!";
        }
    }

    int search_by_code(int codigo){

        for(int i=0; i < this->lenght; i++){

            if(this->get_node(i)->codigo == codigo){
                return i;
            }
        }

        return -1;
    }

    void add(int codigo, string nombre, int nivel){


        nodo *newNode = new nodo();
        newNode->codigo = codigo;
        newNode->nombre = nombre;
        newNode->nivel = nivel;
        newNode->sig = NULL;

        if(this->firstNode == NULL){

            cout << "Creando lista por primera vez!" << endl;
            cout << "Insertando " <<"("<<codigo <<", "<<nombre<<", "<<nivel<<") " <<" en la posicion" << " [0]" << endl;
            this->firstNode = newNode;
            this->lastNode = newNode;
        }

        else {
            
            cout << "Insertando " <<"("<<codigo <<", "<<nombre<<", "<<nivel<<") " << " en la posicion" << " ["<<this->lenght<<"]"<<endl;
            this->lastNode->sig = newNode;
            this->lastNode = newNode;
        }

        this->lenght += 1;
    }

    void add(int codigo, string nombre, int nivel, int index){

        if(index > lenght){

            cout << "Indice "<<"["<<index<<"]"<<" invalido, inserte un indice menor al largo de la lista!" << endl;
            return;
        }

        nodo *newNode = new nodo();
        newNode->codigo = codigo;
        newNode->nombre = nombre;
        newNode->nivel = nivel;
        newNode->sig = NULL;

        if (index == 0 && this->firstNode != NULL){

            cout << "Insertando " <<"("<<codigo <<", "<<nombre<<", "<<nivel<<") " << " en la posicion" << " ["<<index<<"]"<<endl;

            nodo *replaceNode = firstNode;
            newNode->sig = replaceNode;
            this->firstNode = newNode;
            this->lenght += 1;
            return;
        }

        if (index == this->lenght){
            this->add(codigo, nombre, nivel);
            return;
        }

        cout << "Insertando " <<"("<<codigo <<", "<<nombre<<", "<<nivel<<") " << " en la posicion" << " ["<<index<<"]"<<endl;

        nodo *previousNode;
        previousNode = firstNode;

        for (int i = 1; i < index; i++){
            previousNode = previousNode->sig;
        }

        nodo *replaceNode = previousNode->sig;
        previousNode->sig = newNode;
        newNode->sig = replaceNode;
        

        this->lenght += 1;
    }

    nodo* get_node(int index){

        if(index >= lenght || index < 0){

            cout << "Indice "<<"["<<index<<"]"<<" invalido, inserte un indice menor al largo de la lista!" << endl;
            return NULL;
        }

        nodo *currentNode;
        currentNode = firstNode;

        for (int i = 0; i < index; i++){
            currentNode = currentNode->sig;
        }

        return currentNode;
    }

    string get(int index){

        if(index >= lenght || index < 0){

            cout << "Indice "<<"["<<index<<"]"<<" invalido, inserte un indice menor al largo de la lista!" << endl;
            return "";
        }

        nodo *currentNode;
        currentNode = firstNode;

        for (int i = 0; i < index; i++){
            currentNode = currentNode->sig;
        }

        return "(" + std::to_string(currentNode->codigo) + 
        ", " + currentNode->nombre + 
        ", " + std::to_string(currentNode->nivel) + ")";
    }

    string to_string(){

        string out = "[";
        nodo *currentNode;
        currentNode = this->firstNode;

        for(int i = 0; i < lenght-1; i++){
            out = out + this->get(i) + ", ";
            currentNode = currentNode->sig;
        }

        out = out + this->get(lenght-1) + "]";

        return out;

    }

};

int main(){

    linkedList list;

    for (int i = 1; i <= 3; i++){

        // list.add(i*2,"jose", i*5);
        list.read_student();
    }
    
    cout << list.to_string() << endl;

    // list.add(1000, 7);

    // cout << list.to_string() << endl;

    // system("pause");

    cout << list.to_string() << endl;

    return 0;
}
