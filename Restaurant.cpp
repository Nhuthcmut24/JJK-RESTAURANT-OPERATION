#include "main.h"

// Singly Linked List Implementation
template <class T>
class SLinkedList
{
public:
    class Node // use inside of SLinkedList
    {
    private:
        T data;
        Node *next;
        friend class SLinkedList<T>; // SlinkedList class class can access all property and method of Node class
        friend class imp_res;

    public:
        Node()
        {
            this->next = nullptr;
        }
        Node(Node *next)
        {
            this->next = next;
        }
        Node(T data, Node *next)
        {
            this->data = data;
            this->next = next;
        }
    };

protected:
    Node *head;
    Node *tail;
    int count;
    friend class imp_res;

public:
    SLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->count = 0;
    }
    ~SLinkedList()
    {
        delete head;
        delete tail;
    }
    void add(const T &e);
    void add(int index, const T &e);
    int size();
    bool empty();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    void clear();
    T removeAt(int index);
    bool removeItem(const T &item);
};

template <class T>
void SLinkedList<T>::add(const T &e)
{
    Node *new_node = new Node(e, nullptr);
    if (this->head != nullptr)
    {
        Node *temp = this->head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        count++;
        this->tail = new_node;
    }
    else
    {
        this->head = new_node;
        this->count++;
        this->tail = new_node;
    }
}
template <class T>
void SLinkedList<T>::add(int index, const T &e)
{
    if (index >= 0 && index <= count)
    {
        if (index == 0)
        {
            if (this->head)
            {
                Node *new_node = new Node(e, head);
                this->head = new_node;
                count++;
            }
            else
            {
                Node *new_node = new Node(e, nullptr);
                this->head = new_node;
                count++;
                tail = head;
            }
        }
        else if (index == count)
        {
            add(e);
        }
        else
        {
            Node *temp = this->head;
            Node *pre = temp;
            int idx = 0;
            while (idx < index)
            {
                pre = temp;
                temp = temp->next;
                idx++;
            }
            Node *new_node = new Node(e, temp);
            count++;
            pre->next = new_node;
        }
    }
}

template <class T>
int SLinkedList<T>::size()
{
    return this->count;
}

template <class T>
T SLinkedList<T>::get(int index)
{
    if (index < 0 || index >= this->size())
    {
        throw std::out_of_range("index is out of range!");
    }
    Node *temp = this->head;
    int idx = 0;
    while (idx < index)
    {
        temp = temp->next;
        idx++;
    }
    return temp->data;
}

template <class T>
void SLinkedList<T>::set(int index, const T &e)
{
    if (index >= 0 && index < this->size())
    {
        int idx = 0;
        Node *temp = this->head;
        while (idx < index)
        {
            temp = temp->next;
            idx++;
        }
        temp->data = e;
    }
}

template <class T>
bool SLinkedList<T>::empty()
{
    if (this->size())
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <class T>
int SLinkedList<T>::indexOf(const T &item)
{
    int idx = 0;
    Node *temp = head;
    while (temp != nullptr && temp->data != item)
    {
        temp = temp->next;
        idx++;
    }
    if (idx < this->size())
    {
        return idx;
    }
    else
    {
        return -1;
    }
}

template <class T>
bool SLinkedList<T>::contains(const T &item)
{
    Node *temp = this->head;
    while (temp && temp->data != item)
    {
        temp = temp->next;
    }
    if (temp)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
T SLinkedList<T>::removeAt(int index)
{
    if (index < 0 || index >= this->size())
    {
        throw std::out_of_range("index is out of range!");
    }
    if (index == 0)
    {
        if (head == tail)
        {
            tail = nullptr;
        }
        Node *temp = this->head;
        this->head = this->head->next;
        T res = temp->data;
        temp = nullptr;
        count--;
        return res;
    }
    else if (index == this->size() - 1)
    {
        Node *temp = this->head;
        while (temp->next->next)
        {
            temp = temp->next;
        }
        T res = temp->next->data;
        temp->next = nullptr;
        tail = temp;
        count--;
        return res;
    }
    else
    {
        Node *temp = this->head;
        Node *pre = temp;
        int idx = 0;
        while (idx < index)
        {
            pre = temp;
            temp = temp->next;
            idx++;
        }
        T res = temp->data;
        pre->next = temp->next;
        temp = nullptr;
        count--;
        return res;
    }
}

template <class T>
bool SLinkedList<T>::removeItem(const T &item)
{
    Node *temp = this->head;
    int idx = 0;
    while (idx < this->size() && temp->data != item)
    {
        temp = temp->next;
        idx++;
    }
    if (idx == this->size())
    {

        return false;
    }
    else
    {
        removeAt(idx);
        return true;
    }
}

template <class T>
void SLinkedList<T>::clear()
{
    if (this->size())
    {

        while (this->head)
        {
            Node *pre = this->head;
            this->head = this->head->next;
            delete pre;
            count--;
        }
        tail = nullptr;
    }
}

// imp_res implementation

class imp_res : public Restaurant
{
public:
    class DLinkedList // Doubly Linked List implementation
    {

    public:
        DLinkedList()
        {
            this->count = 0;
            this->current = nullptr;
            this->key = nullptr;
        }
        ~DLinkedList()
        {
        }
        int sumEnergy(customer *start_node, int sublist_length) // Calculate sum of energy of sublist from start_node and the length is sublist_length
        {
            customer *current = start_node;
            int energySum = 0;
            for (int i = 0; i < sublist_length; i++)
            {
                energySum += current->energy;
                current = current->next;
            }
            return energySum;
        }

        long int energyOfOanlinh()
        {
            int res = 0;
            customer *temp = this->key;
            for (int i = 0; i < this->size(); i++)
            {
                if (this->isOanlinh(temp))
                {
                    res += temp->energy;
                }
                temp = temp->next;
            }
            return res;
        }
        long int energyOfThuatsu()
        {
            int res = 0;
            customer *temp = this->key;
            for (int i = 0; i < this->size(); i++)
            {
                if (this->isThuatsu(temp))
                {
                    res += temp->energy;
                }
                temp = temp->next;
            }
            return res;
        }
        int numOfThuatsu()
        {
            int res = 0;
            customer *temp = this->key;
            for (int i = 0; i < this->size(); i++)
            {
                if (this->isThuatsu(temp))
                {
                    res++;
                }
                temp = temp->next;
            }
            return res;
        }
        int numOfOanlinh()
        {
            int res = 0;
            customer *temp = this->key;
            for (int i = 0; i < this->size(); i++)
            {
                if (this->isOanlinh(temp))
                {
                    res++;
                }
                temp = temp->next;
            }
            return res;
        }
        bool isSameType(customer *cus1, customer *cus2)
        {
            if ((this->isOanlinh(cus1) && this->isOanlinh(cus2)) || (this->isThuatsu(cus1) && this->isThuatsu(cus2)))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        int size() // size of DLinkedList
        {
            return this->count;
        }
        void clear()
        {
            if (!this->empty())
            {
                for (int i = 0; i < this->size(); i++)
                {
                    string name = this->key->name;
                    this->removeByNameSimple(name);
                }
            }
        }
        bool empty() // empty check
        {
            return this->count == 0;
        }
        void addTail(string name, int energy)
        {
            customer *new_cus = new customer(name, energy, nullptr, nullptr);
            if (this->empty()) // them vao danh sach rong
            {
                this->current = new_cus;
                this->key = new_cus;
            }
            else
            {
                if (this->size() == 1)
                {
                    this->key->next = new_cus;
                    this->key->prev = new_cus;
                    new_cus->prev = this->key;
                    new_cus->next = this->key;
                    this->current = new_cus;
                }
                else
                {
                    new_cus->next = this->key;
                    new_cus->prev = this->key->prev;
                    this->key->prev->next = new_cus;
                    this->key->prev = new_cus;
                    this->current = new_cus;
                }
            }
            this->count++;
        }
        void addDir(bool clock_dir, string name, int energy) // add customer to DLinkedList at index base on energy
        {
            customer *new_cus = new customer(name, energy, nullptr, nullptr);
            if (this->empty()) // them vao danh sach rong
            {
                this->current = new_cus;
                this->key = new_cus;
            }
            else
            {
                if (clock_dir) // them cung chieu kim dong ho
                {
                    new_cus->next = this->current->next;
                    if (this->current->next)
                    {
                        this->current->next->prev = new_cus;
                    }
                    this->current->next = new_cus;
                    new_cus->prev = this->current;
                    if (!new_cus->next)
                    {
                        new_cus->next = new_cus->prev;
                    }
                    if (!this->current->prev)
                    {
                        this->current->prev = new_cus;
                    }
                    this->current = new_cus;
                }
                else
                {
                    new_cus->prev = this->current->prev;
                    if (this->current->prev)
                    {
                        this->current->prev->next = new_cus;
                    }
                    new_cus->next = this->current;
                    this->current->prev = new_cus;
                    if (!this->current->next)
                    {
                        this->current->next = new_cus;
                    }
                    if (!new_cus->prev)
                    {
                        new_cus->prev = this->current;
                    }
                    this->current = new_cus;
                }
            }
            this->count++;
        }
        bool isOanlinh(customer *cus)
        {
            if (cus->energy < 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool isThuatsu(customer *cus)
        {
            if (cus->energy > 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool contains(const string &name)
        {
            customer *temp = this->key;
            for (int i = 0; i < this->size(); i++)
            {
                if (temp->name == name)
                {
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }
        void removeByName(string name) // reset X base on energy that be removed
        {
            if (this->size() >= 1)
            {
                customer *temp = this->key;
                for (int i = 0; i < this->size(); i++)
                {
                    if (temp->name == name)
                    {
                        break;
                    }
                    temp = temp->next;
                }

                if (temp->energy > 0)
                {
                    this->current = temp->next;
                }
                else
                {
                    this->current = temp->prev;
                }
                if (temp->name == this->key->name)
                {
                    this->key = this->key->next;
                }
                if (this->size() > 1)
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    temp->next = nullptr;
                    temp->prev = nullptr;
                    delete temp;
                }
                else
                {
                    this->current = nullptr;
                    this->key = nullptr;
                    delete temp;
                }
                this->count--;
            }
        }
        void removeByNameSimple(string name) // 20-10-23 not checked
        {
            if (this->size() >= 1)
            {
                if (name == this->key->name)
                {
                    this->key = this->key->next;
                }
                customer *temp = this->current;
                for (int i = 0; i < this->size(); i++)
                {
                    if (temp->name == name)
                    {
                        break;
                    }
                    temp = temp->next;
                }

                this->current = temp->next;

                if (this->size() > 1)
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    temp->next = nullptr;
                    temp->prev = nullptr;
                    delete temp;
                }
                else
                {
                    this->current = nullptr;
                    this->key = nullptr;
                    delete temp;
                }
                this->count--;
            }
        }

    private:
        int count;
        customer *key; // need to use??
        customer *current;
        friend class imp_res;
    };

private:
    DLinkedList *cList;    // List of customer who is eating
    DLinkedList *waitList; // List of customer who is waiting
    DLinkedList *timeArrive;
    DLinkedList *subListMin; // Lich su khach vao nha hang
    int swapCount;
    // friend class imp_res;

public:
    imp_res()
    {
        this->cList = new DLinkedList();
        this->waitList = new DLinkedList();
        this->timeArrive = new DLinkedList();
    };
    ~imp_res()
    {
        this->cList->clear();
        this->waitList->clear();
        this->timeArrive->clear();
        delete cList;
        delete waitList;
        delete timeArrive;
    }
    void insertionSort(DLinkedList *list, int n, int start = 0, int step = 1)
    {
        customer *startCus = list->key;
        for (int i = 0; i < start; i++)
        {
            startCus = startCus->next;
        }
        int round = 1;
        for (int i = start + step; i < n; i += step)
        {
            int j = i;
            customer *temp = startCus;
            for (int m = 0; m < step * round; m++)
            {
                temp = temp->next;
            }
            customer *temp2 = temp;
            for (int m = 0; m < step; m++)
            {
                temp2 = temp2->prev;
            }

            while ((j > 0 && abs(temp->energy) > abs(temp2->energy)) || (j > 0 && (abs(temp->energy) == abs(temp2->energy)) && this->isT1ComingBeforeT2(temp, temp2)))
            {
                swap(temp->energy, temp2->energy);
                swap(temp->name, temp2->name);
                this->swapCount++;
                j -= step;
                if (j <= start)
                {
                    break;
                }
                else
                {
                    temp = temp2;
                    for (int z = 0; z < step; z++)
                    {
                        temp2 = temp2->prev;
                    }
                }
            }
            round++;
        }
    }

    void shellShort(DLinkedList *list, int n)
    {
        this->swapCount = 0;

        int k = n / 2;
        while (k > 0)
        {
            if (k == 2)
            {
                k = 1;
            }
            for (int i = 0; i <= k - 1; i++)
            {
                insertionSort(list, n, i, k);
            }
            k /= 2;
        }
    }

    bool isT1ComingBeforeT2(customer *t1, customer *t2)
    {
        int indexOfT1 = 0;
        int indexOfT2 = 0;
        customer *temp = this->timeArrive->key;
        while (temp->name != t1->name)
        {
            indexOfT1++;
            temp = temp->next;
        }
        customer *temp2 = this->timeArrive->key;
        while (temp2->name != t2->name)
        {
            temp2 = temp2->next;
            indexOfT2++;
        }
        if (indexOfT1 > indexOfT2)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    bool containCus(string name)
    {
        customer *temp = this->cList->key;
        for (int i = 0; i < this->cList->size(); i++)
        {
            if (temp->name == name)
            {
                return true;
            }
            temp = temp->next;
        }
        customer *temp2 = this->waitList->key;
        for (int i = 0; i < this->waitList->size(); i++)
        {
            if (temp2->name == name)
            {
                return true;
            }
            temp2 = temp2->next;
        }
        return false;
    }

    void RED(string name, int energy)
    {
        if (!this->containCus(name) && energy != 0)
        {
            if (this->cList->size() == MAXSIZE) // check full size and put customer to waiting list
            {
                if (this->waitList->size() != MAXSIZE)
                {
                    this->waitList->addTail(name, energy);
                    this->timeArrive->addTail(name, energy);
                }
            }
            else // chua full slot
            {
                if (!this->timeArrive->contains(name))
                {
                    this->timeArrive->addTail(name, energy);
                }
                if (this->cList->empty())
                {
                    this->cList->addDir(true, name, energy);
                }
                else if (this->cList->size() < MAXSIZE / 2)
                {
                    if (energy >= this->cList->current->energy)
                    {
                        this->cList->addDir(true, name, energy);
                    }
                    else
                    {
                        this->cList->addDir(false, name, energy);
                    }
                }
                else
                {
                    // Tim chenh lech nang luong lon nhat
                    SLinkedList<int> *listRES = new SLinkedList<int>();
                    customer *temp = this->cList->current;
                    for (int i = 0; i < this->cList->size(); i++)
                    {
                        listRES->add(abs(energy - temp->energy));
                        temp = temp->next;
                    }

                    int indexOfMaxRes = 0;
                    int maxRES = listRES->get(0);
                    for (int i = 1; i < listRES->size(); i++)
                    {
                        if (listRES->get(i) > maxRES)
                        {
                            maxRES = listRES->get(i);
                            indexOfMaxRes = i;
                        }
                    }
                    customer *temp2 = this->cList->current;
                    for (int i = 0; i < indexOfMaxRes; i++)
                    {
                        temp2 = temp2->next;
                    }
                    this->cList->current = temp2;
                    if (energy - temp2->energy >= 0)
                    {
                        this->cList->addDir(true, name, energy);
                    }
                    else
                    {
                        this->cList->addDir(false, name, energy);
                    }
                    listRES->clear();
                    delete listRES;
                }
            }
        }
    }
    void BLUE(int num)
    {
        int max = this->cList->size();
        num = num > max ? max : num;
        if (!this->cList->empty())
        {
            for (int i = 0; i < num; i++)
            {
                customer *temp = this->timeArrive->key;
                while (!this->cList->contains(temp->name))
                {
                    temp = temp->next;
                }
                this->cList->removeByName(temp->name);
                this->timeArrive->removeByNameSimple(temp->name);
            }
            // Moi khach tu hang cho
            if (this->waitList->size() >= num)
            {

                customer *temp = this->waitList->key;
                for (int i = 0; i < num; i++)
                {
                    string name = temp->name;
                    int energy = temp->energy;
                    temp = temp->next;
                    this->waitList->removeByNameSimple(name);
                    this->RED(name, energy);
                }
            }
            else
            {
                customer *temp = this->waitList->key;
                int size = this->waitList->size();
                for (int i = 0; i < size; i++)
                {
                    string name = temp->name;
                    int energy = temp->energy;

                    temp = temp->next;
                    this->waitList->removeByNameSimple(name);
                    this->RED(name, energy);
                }
            }
        }
    }
    void PURPLE()
    {
        if (this->waitList->size() > 1)
        {
            int max = abs(this->waitList->key->energy);
            customer *temp = this->waitList->key;
            customer *maxCus = nullptr;
            for (int i = 0; i < this->waitList->size(); i++)
            {
                if (abs(temp->energy) >= max)
                {
                    max = abs(temp->energy);
                    maxCus = temp;
                }
                temp = temp->next;
            }

            int numToSort = 0;
            customer *temp2 = this->waitList->key;
            while (temp2->name != maxCus->name)
            {
                numToSort++;
                temp2 = temp2->next;
            }
            numToSort++;
            if (numToSort > 1)
            {
                this->shellShort(this->waitList, numToSort);
                this->BLUE(this->swapCount % MAXSIZE);
            }
        }
    }
    void REVERSAL()
    {
        if (this->cList->size() >= 2)
        {
            string currentBeforeReveral = this->cList->current->name;
            customer *l = nullptr;
            customer *r = nullptr;
            // Swap Thuat su
            customer *temp = this->cList->current;
            for (int i = 0; i < this->cList->size(); i++)
            {
                if (!this->cList->isThuatsu(temp))
                {

                    temp = temp->prev;
                }
                else
                {
                    l = temp;
                    break;
                }
            }
            if (l != nullptr)
            {
                temp = this->cList->current->next;
                for (int i = 0; i < this->cList->size(); i++)
                {
                    if (!this->cList->isThuatsu(temp))
                    {

                        temp = temp->next;
                    }
                    else
                    {
                        r = temp;
                        break;
                    }
                }
                int reversalCount = 0;
                int limitSwap = this->cList->numOfThuatsu() / 2;
                while (reversalCount < limitSwap)
                {
                    swap(l->name, r->name);
                    swap(l->energy, r->energy);
                    reversalCount++;
                    l = l->prev;
                    while (!this->cList->isThuatsu(l))
                    {
                        l = l->prev;
                    }
                    r = r->next;
                    while (!this->cList->isThuatsu(r))
                    {
                        r = r->next;
                    }
                }
            }
            l = nullptr;
            r = nullptr;
            temp = this->cList->current;
            // Swap oan linh
            for (int i = 0; i < this->cList->size(); i++)
            {
                if (!this->cList->isOanlinh(temp))
                {

                    temp = temp->prev;
                }
                else
                {
                    l = temp;
                    break;
                }
            }
            if (l != nullptr)
            {

                temp = this->cList->current->next;
                for (int i = 0; i < this->cList->size(); i++)
                {
                    if (!this->cList->isOanlinh(temp))
                    {

                        temp = temp->next;
                    }
                    else
                    {
                        r = temp;
                        break;
                    }
                }
                int reversalCount = 0;
                int limitSwap = this->cList->numOfOanlinh() / 2;
                while (reversalCount < limitSwap)
                {
                    swap(l->name, r->name);
                    swap(l->energy, r->energy);
                    reversalCount++;
                    l = l->prev;
                    while (!this->cList->isOanlinh(l))
                    {
                        l = l->prev;
                    }
                    r = r->next;
                    while (!this->cList->isOanlinh(r))
                    {
                        r = r->next;
                    }
                }
            }
            // Tim lai current ban dau
            customer *temp5 = this->cList->key;
            while (temp5->name != currentBeforeReveral)
            {
                temp5 = temp5->next;
            }
            this->cList->current = temp5;
        }
    }
    void UNLIMITED_VOID()
    {
        if (this->cList->size() >= 4)
        {
            customer *key = this->cList->current;
            customer *startNode = this->cList->current;
            customer *startNodeTocheck = this->cList->current;
            int minSum = this->cList->sumEnergy(this->cList->current, this->cList->size());
            int maxLength = this->cList->size();
            for (int i = 0; i < this->cList->size(); i++)
            {
                customer *current = startNodeTocheck;
                int currentSum = 0;
                int sublistLength = 0;
                for (int i = 0; i < this->cList->size(); i++)
                {
                    sublistLength++;
                    currentSum += current->energy;
                    if (sublistLength >= 4)
                    {
                        if (currentSum < minSum)
                        {
                            minSum = currentSum;
                            startNode = startNodeTocheck;
                            maxLength = sublistLength;
                        }
                        else if (currentSum == minSum && sublistLength == maxLength)
                        {

                            startNode = startNodeTocheck;
                        }
                        else if (currentSum == minSum && sublistLength > maxLength)
                        {
                            startNode = startNodeTocheck;
                            maxLength = sublistLength;
                        }
                    }
                    current = current->next;
                }
                startNodeTocheck = startNodeTocheck->next;
            }
            this->subListMin = new DLinkedList();
            customer *temp5 = startNode;
            for (int i = 0; i < maxLength; i++)
            {
                this->subListMin->addTail(temp5->name, temp5->energy);
                temp5 = temp5->next;
            }
            customer *minStart = this->subListMin->key;
            customer *temp2 = this->subListMin->key;
            int minEnergyInSubList = minStart->energy;
            for (int i = 0; i < maxLength; i++)
            {
                if (temp2->energy < minEnergyInSubList)
                {
                    minEnergyInSubList = temp2->energy;
                    minStart = temp2;
                    this->subListMin->key = temp2;
                }
                temp2 = temp2->next;
            }
            customer *temp3 = this->subListMin->key;
            for (int i = 0; i < this->subListMin->size(); i++)
            {
                temp3->print();
                temp3 = temp3->next;
            }
            this->subListMin->clear();
            delete subListMin;
        }
    }

    void DOMAIN_EXPANSION()
    {

        if (this->timeArrive->numOfOanlinh() >= 1 && this->timeArrive->numOfThuatsu() >= 1)
        {
            long int sumEnergyChulinh = this->cList->energyOfOanlinh() + this->waitList->energyOfOanlinh() + this->cList->energyOfThuatsu() + this->waitList->energyOfThuatsu();
            long int sumEnergyThuatsu = this->cList->energyOfThuatsu() + this->waitList->energyOfThuatsu();
            int numBeRemoveInTable = 0;
            int numBeRemoveInWait = 0;
            if (sumEnergyThuatsu >= abs(sumEnergyChulinh)) // Duoi tat ca oan linh trong nha hang
            {
                numBeRemoveInTable = this->cList->numOfOanlinh(); // De biet moi khach vo sau khi duoi

                customer *tempHisCus = nullptr;
                // PRINT
                if (this->timeArrive->key->prev == nullptr)
                {
                    tempHisCus = this->timeArrive->key;
                    if (this->timeArrive->isOanlinh(tempHisCus))
                    {
                        tempHisCus->print();
                    }
                }
                else
                {

                    tempHisCus = this->timeArrive->key->prev;
                    for (int i = 0; i < this->timeArrive->size(); i++)
                    {
                        if (this->timeArrive->isOanlinh(tempHisCus))
                        {
                            tempHisCus->print();
                        }
                        tempHisCus = tempHisCus->prev;
                    }
                }
                // DUOI

                int fistSizeHistory = this->timeArrive->size();
                customer *temp = this->timeArrive->key;
                for (int i = 0; i < fistSizeHistory; i++)
                {
                    if (this->timeArrive->isOanlinh(temp) && this->cList->contains(temp->name))
                    {
                        string name = temp->name;
                        temp = temp->next;
                        this->cList->removeByName(name);
                        this->timeArrive->removeByNameSimple(name);
                    }
                    else if (this->timeArrive->isOanlinh(temp) && this->waitList->contains(temp->name))
                    {
                        string name = temp->name;
                        int energy = temp->energy;
                        temp = temp->next;
                        this->waitList->removeByNameSimple(name);
                        this->timeArrive->removeByNameSimple(name);
                    }
                    else
                    {
                        temp = temp->next;
                    }
                }
            }
            else // Duoi tat ca thuat su trong nha hang
            {
                numBeRemoveInTable = this->cList->numOfThuatsu();
                customer *tempHisCus = nullptr;
                // PRINT
                if (this->timeArrive->key->prev == nullptr)
                {
                    tempHisCus = this->timeArrive->key;
                    if (this->timeArrive->isThuatsu(tempHisCus))
                    {
                        tempHisCus->print();
                    }
                }
                else
                {
                    tempHisCus = this->timeArrive->key->prev;
                    for (int i = 0; i < this->timeArrive->size(); i++)
                    {
                        if (this->timeArrive->isThuatsu(tempHisCus))
                        {
                            tempHisCus->print();
                        }
                        tempHisCus = tempHisCus->prev;
                    }
                }
                // DUOI
                int firstSize = this->timeArrive->size();
                customer *temp = this->timeArrive->key;
                for (int i = 0; i < firstSize; i++)
                {
                    if (this->timeArrive->isThuatsu(temp) && this->cList->contains(temp->name))
                    {
                        string name = temp->name;
                        temp = temp->next;
                        this->cList->removeByName(name);
                        this->timeArrive->removeByNameSimple(name);
                    }
                    else if (this->timeArrive->isThuatsu(temp) && this->waitList->contains(temp->name))
                    {
                        string name = temp->name;
                        temp = temp->next;
                        this->waitList->removeByNameSimple(name);
                        this->timeArrive->removeByNameSimple(name);
                    }
                    else
                    {
                        temp = temp->next;
                    }
                }
            }
            // Moi khach vao nha hang neu co
            if (this->waitList->size() >= numBeRemoveInTable)
            {
                customer *temp = this->waitList->key;
                for (int i = 0; i < numBeRemoveInTable; i++)
                {
                    string name = temp->name;
                    int energy = temp->energy;
                    temp = temp->next;
                    this->waitList->removeByNameSimple(name);
                    this->RED(name, energy);
                }
            }
            else
            {
                customer *temp = this->waitList->key;
                int size = this->waitList->size();
                for (int i = 0; i < size; i++)
                {
                    string name = temp->name;
                    int energy = temp->energy;
                    temp = temp->next;
                    this->waitList->removeByNameSimple(name);
                    this->RED(name, energy);
                }
            }
        }
    }
    void LIGHT(int num)
    {
        if (num > 0)
        {
            if (!this->cList->empty())
            {
                customer *temp = this->cList->current;
                for (int i = 0; i < this->cList->size(); i++)
                {
                    temp->print();
                    temp = temp->next;
                }
            }
        }
        else if (num < 0)
        {
            if (!this->cList->empty())
            {
                customer *temp = this->cList->current;
                for (int i = 0; i < this->cList->size(); i++)
                {
                    temp->print();
                    temp = temp->prev;
                }
            }
        }
        else
        {
            if (!this->waitList->empty())
            {
                customer *temp = this->waitList->key;
                for (int i = 0; i < this->waitList->size(); i++)
                {
                    temp->print();
                    temp = temp->next;
                }
            }
        }
    }
};