#ifndef QUEUETP_H_
#define QUEUETP_H_
#include <string>
#include <iostream>
#include <cstdlib>


template <typename Item>
class QueueTP
{
protected:
    //definicje zasiegu klasy
    //Node to definicja zagnie�d�ona klasy, lokalna wzgl�dem tej klasy
    struct Node { Item item; struct Node * next; };
    //prywatne sk�adowe klasy
    Node * front;       //wska�nik czo�a kolejki
    Node * rear;        //wska�nik ogona kolejki
    int items;          //bie��ca liczba element�w
    const int qsize;    //maksymalna liczba element�w kolejki
                        //definicje blokuj�ce publiczny dost�p do operacji kopiowania
    //QueueTP(const QueueTP & q) : qsize(0) {}
    //QueueTP & operator=(const QueueTP & q) { return *this; }
public:

    QueueTP(int qs);            //tworzy kolejk� o pojemno�ci qs
    virtual ~QueueTP();
    bool isempty() const;
    bool isfull() const;
    int  queuecount() const;
    bool enqueue(const Item &item); //dodaje element na koniec kolejki
    bool dequeue(Item & item);      //wyci�ga element z czo�a kolejki
    bool operator>(const QueueTP & l)
    {
        if (this->items > l.items)
            return true;

        return false;
    }
};

//metody klasy Queue
template <typename Item>
QueueTP<Item>::QueueTP(int qs) : qsize(qs)
{
    front = rear = nullptr;
    items = 0;
}
template <typename Item>
QueueTP<Item>::~QueueTP()
{
    Node * temp;
    while (front != NULL)   //do wyczerpania kolejki
    {
        temp = front;       //zachowanie adresu elementu bie��cego
        front = front->next; //przesuni�cie wska�nika do elementu nast�pnego
        delete temp;        //zwolnienie elementu spod zapami�tanego adresu
    }
}
template <typename Item>
bool QueueTP<Item>::isempty() const
{
    return items == 0;
}
template <typename Item>
bool QueueTP<Item>::isfull() const
{
    return items == qsize;
}
template <typename Item>
int QueueTP<Item>::queuecount() const
{
    return items;
}

//dodaje element do kolejki
template <typename Item>
bool QueueTP<Item>::enqueue(const Item &item)
{
    if (isfull())
        return false;
    Node * add = new Node;      //utworzenie w�z�a
                                //w przypadku niepowodzenia przydzia�u new zrzudzi wyj�tek na std::bad_alloc
    add->item = item;            //ustawienie wska�nik�w w�z��w
    add->next = nullptr;
    ++items;
    if (front == NULL)          //je�li kolejka pusta
        front = add;            //umie�� element na czele listy
    else
        rear->next = add;        //w przeciwnym wypadku do��cz do ko�ca
    rear = add;                 //rear wskazuje teraz nowy w�ze�

    return true;
}

//kopiuje element czo�owy kolejki do argumentu wywo�ania i usuwa go z kolejki
template <typename Item>
bool QueueTP<Item>::dequeue(Item & item)
{
    if (front == NULL)
        return false;
    item = front->item;          //skopiowanie do item pierwszego elementu
    --items;
    Node * temp = front;        //zachowanie po�o�enia pierwszego elementu
    front = front->next;     //przestawienie wska�nika front na nast�pny element
    delete temp;                //usuni�cie dotychczasowego pierwszego elementu
    if (items == 0)
        rear = NULL;
    return true;
}

#endif
