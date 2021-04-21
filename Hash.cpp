//Lydia Smith
//Program 3
//COSC 2030
//4/20/21

#include <iostream>
#include<string>
using namespace std;

//Hash class
template<class T>
class Hash
{
    const static int HASHSIZE = 266366;
    int size;
    T* hash;

public:
    // Default Constructor
    Hash()
    {
        hash = new T[HASHSIZE];
        size = 0;
        for (int i = 0; i < HASHSIZE; i++)
        {
            hash[i] = " ";

        }
    };
    Hash(T V)
    {
        this->size = V;
        hash = new T[HASHSIZE];

    };
    //Destructor
    ~Hash()
    {
        delete[] hash;

    };

    // inserts a key into hash table
    void insertItem(T item)
    {
        int key = hashFunction(item);
        if (hash[key].empty())
        {
            hash[key] = item;
            size++;

        }
        else
        {
            bool entered = false;
            while (!entered)
            {
                key++;
                if (hash[key] == " ")
                {
                    hash[key] = item;
                    size++;
                    entered = true;
                    

                }
            }
        }
    };
    //finds item in hash table
    bool find(T item)
    {
        int key = hashFunction(item);
        if (hash[key].compare(item) == 0)
        {
            return true;

        }
        else if (hash[key].compare("") == 0)
        {
            return false;
        }
        else
        {
            bool found = false;
            while (!found)
            {
                if (hash[key].compare(item) == 0)
                {
                    return true;

                }
                else if (hash[key].compare("") == 0)
                {

                    return false;

                }

            }

        }
    };

    // hash function to map values to key
    int hashFunction(T x) {
        int i = 0; long int val = 0; int g = 5;

        for (i = 0; i < x.size(); i++)
        {
            val = g * val + x.at(i);

        }
        return val % HASHSIZE;
    };
    //display hash
    void displayHash()
    {
        for (int i = 0; i < HASHSIZE; i++) {
            cout << i;
            for (auto x : hash[i])
                cout << " --> " << x;
            cout << endl;
        }

    };
    int returnSize()
    {
        return size;
    
    }

};

/*int main()
{

    Hash<string> ht;
    ht.insertItem("hello");
    ht.insertItem("goodbye");
    ht.displayHash();
    bool found = false;
    if(!ht.find("no"))
    {
        cout << "Not found";

    }else
    {
        cout << "found";

    }

    return 0;

}*/
