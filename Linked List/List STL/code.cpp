#include<iostream>
#include<list>
#include<iterator>
using namespace std;

int main() {
    list<int> ll; //creating list like vector
    //element enter
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_front(1);
    // iterator are obj that allow you to traverse -
    // through the elements of a container in a seqential manner
    list<int>::iterator itr;
    // listname.begin()- itr of head
    // listname.end() - itr of tail->next (Null)
    cout<<"List = ";
    for(itr =ll.begin();itr!=ll.end();itr++){
        cout<<(*itr)<<" ";
    }
    cout<<endl;
    // size
    cout<<"size = "<<ll.size()<<endl;
    // front()& back()
    cout<<"head = "<<ll.front()<<endl;
    cout<<"tail = "<<ll.back();

    // and also pop_front() & pop_back()
    return 0;
}
