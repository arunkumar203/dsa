#include<bits/stdc++.h>
using namespace std;
template<class t>
void  display(list< t> &v){
     for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
     }
    
    printf("\n");
}
int main(){
    list<int > v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_front(5);
    v.push_back(10);
    display(v);
    list<int > v2;
    v2.insert(v2.begin(),4,6);
    
    display(v2);
    v.merge(v2);
    display(v);

    v.sort();
    display(v);
    v.reverse();
    display(v);

    return 0;
}