/*
 Author: Brian Hernandez
 Description: HW 3 Storage (Bookshelf)
 All methods implemented
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class bookCase
{
public:
    void empty();
    int numberOfDistinctItems();
    int count(int id);
    void add(int id);
    void remove(int id);
    bool pickAnItem(int &id);
private:
    vector<int> bookIDs;
    vector<int> uniqueBookIDs;
};

void bookCase::empty()
{
    bookIDs.erase(bookIDs.begin(), bookIDs.end());
    uniqueBookIDs.erase(uniqueBookIDs.begin(), uniqueBookIDs.end());
}

int bookCase::numberOfDistinctItems()
{
    return uniqueBookIDs.size();
}

int bookCase::count(int id)
{
    int n = 0;
    for(int i = 0; i<bookIDs.size(); i++)
    {
        if(bookIDs[i] == id)
        {
            n+=1;
        }
    }
    return n;
}

void bookCase::add(int id)
{
    bool uniqueID = true;
    for(int i = 0; i<uniqueBookIDs.size(); i++)
    {
        if(uniqueBookIDs[i] == id)
        {
            uniqueID = false;
        }
    }
    if(uniqueID == true)
    {
        uniqueBookIDs.push_back(id);
    }
    bookIDs.push_back(id);
}

void bookCase::remove(int id)
{
    for(int i = 0; i<bookIDs.size(); i++)
    {
        if(bookIDs[i] == id)
        {
            if(count(id) <= 1)
            {
                uniqueBookIDs.erase(uniqueBookIDs.begin()+i);
            }
            bookIDs.erase(bookIDs.begin()+i);
            break;
        }
    }
}

bool bookCase::pickAnItem(int &id)
{
    if(uniqueBookIDs.size() <= 0)
    {
        return false;
    }
    else
    {
        int chosen = rand() % uniqueBookIDs.size();
        id = uniqueBookIDs[chosen];
        return true;
    }
}

int main()
{
    srand(time(NULL));
    bookCase case1;
    //Tests all of the functions, as well as removing from an empty "book case." Also counts the number of a unique items / a specific item with an emptied "book case."
    case1.remove(12345);
    case1.add(12345);
    case1.add(12345);
    case1.add(12345);
    case1.remove(12345);
    case1.add(56789);
    case1.add(45678);
    case1.add(34567);
    case1.add(98765);
    cout << case1.numberOfDistinctItems() << endl;
    int picked;
    case1.pickAnItem(picked);
    cout << picked << endl;
    case1.empty();
    cout << case1.numberOfDistinctItems() << endl << case1.count(12345) << endl;
    
}