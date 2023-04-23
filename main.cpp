#include <iostream>
#include "Student.h"

#define TAM 50

using namespace std;

template<class T>
class Cola{
private:
    T datos[TAM];
    int ult;
    bool inserta(T , int);
    bool elimina(int);
    T recupera(int)const;
    int primero()const;
    int ultimo()const;

public:
    Cola();
    bool vacia()const;
    bool llena()const;
    bool  Queue( T );
    bool Dequeue();
    T Front()const;
    int busquedaLineal(T& elem) const;

    void sortDataBubble();
    void sortDataInsert();
    void sortDataQuick();
};
template< class T>
Cola<T>::Cola() : ult( -1 ){};

template <class T>
void Cola<T>::sortDataQuick(){

}

template <class T>
void Cola<T>::sortDataInsert(){
    int i(1), j;
    T aux;

    while(i<=ult){
        aux=datos[i];
        j=i;

        while(j=0 and aux<datos[j-1]){
            datos[j] = datos[j-1];

            j--;
        }
    if(i!=j){
        datos[j] = aux;
    }

    i++;
    }
}

template <class T>
void Cola<T>::sortDataBubble(){
    int i(ult), j;
    bool flag;

    do{
        flag = false;
        int j=0;

        while (i<j){
            if(datos[j] > datos[j+1]){
                swapData(datos[j], datos[j+1]);

                flag = true;
            }
        j++;
        }
    i--;
    }
    while(flag);
}


template<class T>
T Cola<T>::Front()const{
    T x=datos[primero()];
    return x;
}

template<class T>
bool Cola<T>::Dequeue(){
    if(vacia()){
        return false;
    }
    else{
        elimina(primero());
    }
    return true;
}

template<class T>
bool Cola<T>::Queue(T elem){
    if(llena()){
        return false;
    }
    if(vacia()){
        inserta(elem,0);
    }
    else{
        inserta(elem, ultimo()+1);
    }
    return true;
}


template<class T>
bool Cola<T>::vacia()const{
    return ult==-1;
}

template<class T>
bool Cola<T>::llena()const{
    return ult==TAM-1;
}

template<class T>
int Cola<T>::busquedaLineal(T& elem) const{
    Student s;
    for(int i=0;i<=ult; i++){
        s=datos[i];
    if(elem==s)
        return i;
    }
    return -1;
}

template<class T>
bool Cola<T>::inserta(T elem, int pos){
    if(llena() || pos<0 || pos>ult+1){
        std::cout<<"\n No se pudo insertar";
        return false;
    }
    int i=ult+1;
    while(i>pos){
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return true;
}

template<class T>
bool Cola<T>::elimina(int pos){
    if(vacia() || pos<0 || pos>ult){
        std::cout<<"\n No se pudo eliminar";
        return false;
    }
    int i=pos;
    while(i<ult){
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return true;
}

template<class T>
T Cola<T>::recupera(int pos)const{
    if(vacia() || pos<0 || pos>ult-1){
        std::cout<<"\n Insuficiencia de datos";

        //Manejar exceptions
    }
    else{
       return datos[pos];
    }
}

template<class T>
int Cola<T>::primero()const{
    if(vacia()){
       return -1;
    }
    return 0;
}

template<class T>
int Cola<T>::ultimo()const{
    if(vacia()){
       return -1;
    }
    return ult;
}

int main(){
    Student myStudent;
    Name myName;
    Date myDate;
    string myStr;
    char opc;
    Cola<Student> myCola;
    int opcion;

    do{

             if(!myCola.vacia()){
        cout << "siguiente en la Cola: " << endl;
        cout << myCola.Front().getName().toString();
        cout << "/";
        cout << myCola.Front().getCode();
        cout << "/";
        cout << myCola.Front().getCareer();
        cout << "/";
        cout << "promedio: " << myCola.Front().getGrade();
        cout << endl << endl;
    }

        cout << "__________Menu__Del__Sistema__________" << endl;
        cout << "1 Meter una solicitud" << endl;
        cout << "2 Crear la constancia" << endl;
        cout << "3 encontrar una solicitud" << endl;
        cout << "4 ordenar las solicitudes" << endl;
        cout << "5 Salir" << endl;
        cin >> opcion;



        switch(opcion){

        case 1:
        do{

            cout << "Dame tu codigo: ";
            fflush(stdin);
            getline(cin, myStr);
            myStudent.setCode(myStr);

            cout << "Dame tu(s) Apellido: ";
            getline(cin, myStr);
            myName.setLast(myStr);

            cout << "Dame tu Nombre: ";
            getline(cin, myStr);
            myName.setFirst(myStr);

            myStudent.setName(myName);

            cout << "Dia de nacimiento: ";
            fflush(stdin);
            getline(cin, myStr);
            myDate.setYear(stoi(myStr));
            cout<<"Ingrese mes de nacimiento: ";
            fflush(stdin);
            getline(cin, myStr);
            myDate.setMonth(stoi(myStr));
            cout<<"Ingrese año de nacimiento: ";
            fflush(stdin);
            getline(cin, myStr);
            myDate.setDay(stoi(myStr));

            myStudent.setBirthDate(myDate);

            cout << "Dame tu carrera:";
            getline(cin, myStr);
            myStudent.setCareer(myStr);

            cout << "Dame tu promedio:";
            getline(cin, myStr);
            myStudent.setGrade(atof(myStr.c_str()));

            myCola.Queue(myStudent);

            cout << "Quieres insertar otro? (s/n):";
            fflush(stdin);
            myCola.sortDataInsert();
            cin >> opc;
            cin.ignore();
            }
        while(opc == 's');

        cout << endl << endl;
        break;

        case 2:
            if(!myCola.vacia()){
            cout << "Constancia creada..." << endl;
            cout << "Desencolando..." << endl;
            myCola.Dequeue();
            }
            else{
                cout << "no hay ninguna constancia en cola" << endl;
            }
        break;

        case 3:
            int pos;
            cout << "Buscaremos en cuantos turnos te toca" << endl;
            cout << "Dame el codigo que quieres buscar" << endl << endl;
            fflush(stdin);
            getline(cin, myStr);

            myStudent.setCode(myStr);

            pos = myCola.busquedaLineal(myStudent);
            cout << "el estudiante con el codigo" << myStr << " ";

            cout << endl << endl;

            if(pos == -1){
                cout << "no se encuentra en la Cola" << endl;
            }
            else{
                cout << "registro encontrado: " << endl;
                cout << "se encuentra en la posicion:" << pos << "de la cola" << endl;
                cout << endl << endl;
            }

        break;

        case 4:
            fflush(stdin);
            myCola.sortDataInsert();
            break;

        default: cout << "opcion no disponible";
        }
    }while(opcion!=5);

     if(!myCola.vacia()){
        cout << "siguiente en la Cola: " << endl;
        cout << myCola.Front().getName().toString();
        cout << "/";
        cout << myCola.Front().getCode();
        cout << "/";
        cout << myCola.Front().getCareer();
        cout << "/";
        cout << "promedio: " << myCola.Front().getGrade();
    }
    cout << endl << endl;
}
