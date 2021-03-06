#include <iostream>

using namespace std;

struct nodo {
	int dato;
	nodo *sig;
    nodo *ant;
};

class Ldec {

	private:
		nodo *inicial;

	public:

    Ldec(){
        inicial = NULL;
    }

    ~Ldec(){

        int deletedData;
        nodo* nodoActual = inicial;

        while(nodoActual->sig != inicial){

            nodo* temp = nodoActual;
            deletedData = temp->dato;

            nodoActual = nodoActual->sig;

            delete temp;
            cout << "Borro: " <<deletedData<< endl;
            
        }

        deletedData = nodoActual->dato;

        delete nodoActual;
        cout << "Borro: " <<deletedData<< endl;
    }

	void desplegarLista(){

        string opt;
        string out = "[";
        nodo *nodoActual;

        cout << "1: Sentido horario | Else: Sentido antihorario: ";
        cin >> opt;

        if(inicial == NULL){
			cout << "[]" << endl;
			return;
		}

        if(opt == "1"){

            nodoActual = this->inicial;

            while (nodoActual->sig != inicial){

                out = out + std::to_string(nodoActual->dato) + ", ";
                nodoActual = nodoActual->sig;

            }

        } else {

            nodoActual = this->inicial->ant;

            while (nodoActual != inicial){

                out = out + std::to_string(nodoActual->dato) + ", ";
				nodoActual = nodoActual->ant;
            }
        }

        out = out + std::to_string(nodoActual->dato) + "]";
        cout << out << endl;
	}

	nodo* buscarLista(int clave){

		//Devuelve la direccion del nodo que antecede al nuevo
		//nodo que va a ser agregado, o que va a ser eliminado.

		//Si la clave es menor o igual al dato del primer nodo
		//el valor devuelto es NULL.

		//Si la clave es mayor que el dato del Ãºltimo nodo
		//devuelve la direcciÃ³n del Ãºltimo nodo.

		nodo *anterior;
		anterior = NULL;

		if (inicial->dato >= clave){

            return anterior;

        } else {

			anterior = inicial;

			while ((anterior->sig != inicial) && (anterior->sig->dato < clave)){

				anterior=anterior->sig;

			}
													
			return anterior;
		}
	}

    void agregar(){

        nodo *nuevo, *anterior;
        char resp;

        nuevo = new nodo();
        cout << "Entre la clave del nodo a agregar: ";
        cin >> nuevo->dato;

        if (inicial == NULL){

            //Agrega el primer nodo a la lista
            inicial = nuevo;
            nuevo->sig = nuevo;
            nuevo->ant = nuevo;

        } else {
            
            anterior = buscarLista(nuevo->dato);	
            
            if (anterior == NULL && nuevo->dato != inicial->dato){

            //Agrega un nodo que queda de primero
            //en una lista que no estaba vacia
            inicial->ant->sig = nuevo;
            nuevo->ant = inicial->ant;
            nuevo->sig = inicial;
            inicial->ant = nuevo;
            inicial = nuevo;

            } else if (anterior == NULL || (anterior->sig != NULL && anterior->sig->dato == nuevo->dato)){

                cout << "El nodo a agregar ya existe!" << endl;

            } else if (anterior->sig != NULL){

                //Agrega un nodo que queda entre el
                //primero y el ultimo
                nuevo->sig = anterior->sig;
                nuevo->ant = anterior;

                anterior->sig = nuevo;
                nuevo->sig->ant = nuevo;

            } else {

                //Agrega un nodo que queda de ultimo
                nuevo->sig = inicial;
                nuevo->ant = anterior;
                
                anterior->sig = nuevo;

            }
        }
    }

    void eliminarNodo(){

		int clave;
		nodo* anterior;

		cout << "Inserte la clave del nodo a eliminar: ";
        cin >> clave;
        
        anterior = buscarLista(clave);

        if(anterior == NULL || anterior->sig == inicial || anterior->sig->dato != clave){

            if(inicial->dato != clave){

                cout << "El nodo no existe" << endl;

            } else {
                // Borra el nodo que esta en la primera posicion

                nodo* ultimo = inicial->ant;
                nodo* temp = inicial;
                int deletedData = temp->dato;

                if(ultimo == inicial){

                    inicial = NULL;
                    delete temp;

                } else {

                    inicial = inicial->sig;
                    inicial->ant = ultimo;

                    ultimo->sig = inicial;
                    delete temp;

                }

                cout << "Borrado dato: "<<deletedData<< endl;
            }
        
        } else {

            // Borra una dato en medio de la lista
            nodo* temp = anterior->sig;
            int deletedData = temp->dato;

            anterior->sig = anterior->sig->sig;
            anterior->sig->ant = anterior;
            delete temp;

            cout << "Borrado dato: "<<deletedData<< endl;
        }
    }
};

int main(){

	Ldec l;
    int opcion;

    do {

        cout << "Lista Circular Doblemente Encadenada!" << endl << endl;
        cout << "1. Agregar objeto a lista" << endl;
        cout << "2. Eliminar objeto de lista" << endl;
        cout << "3. Salir" << endl;
        cout << endl;

        cout << "Inserte su opcion: ";
        cin >> opcion;
        cout << endl;

        if (opcion == 1){
            
            l.agregar();

            cout << "Lista actual: ";
            l.desplegarLista();

        } else if (opcion == 2){

            l.eliminarNodo();
            
            cout << "Lista actual: ";
            l.desplegarLista();

        }

        system("pause");
        system("cls");
       
    } while (opcion != 3);

    l.desplegarLista();    
    
}