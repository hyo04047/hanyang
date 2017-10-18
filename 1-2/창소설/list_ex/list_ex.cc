#include <iostream>
#include <list>

using namespace std;

/* Print out list
 *
 * @param[in]   l   list to print out
 */
void Print(list<int>& l) {
    list<int>::iterator iter;
    
    cout << "list contains : ";
    for (iter = l.begin(); iter != l.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

int main(void) {
    
    list<int> my_list;
    list<int>::iterator iter;

    /* push back */
    for (int i = 1; i <= 5; i++) {
        my_list.push_back(i);
    }
    Print(my_list);

    /* insert to second position */
    iter = my_list.begin();
    iter++;
    my_list.insert(iter, 10);
    Print(my_list);
    cout << "iterator now : " << *iter << endl;
    
    /* erase the third position */
    iter = my_list.erase(iter);
    Print(my_list);
    cout << "iterator now : " << *iter << endl;

    return 0;
}
