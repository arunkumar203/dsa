#include<bits/stdc++.h>
using namespace std;
template<class t>
void  display(vector< t> &v){
    for(int i = 0; i < v.size();i++) {
        cout<<v[i]<<" ";
        // cout<<v.at(i)<<" ";
    }
    printf("\n");
}
int main(){
    vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);
    display(vec1);
    vec1.pop_back();
    display(vec1);

    // vector<int> :: iterator iter=vec1.begin();
    vec1.insert(vec1.begin(),45);
    display(vec1);

    vec1.insert(vec1.begin()+1,2,69);
    display(vec1);



    vector <int> vec2;//zerp length integer vector
    vector <char> vec3(4);//4 element character vector 
    vec3.push_back(6);
    display(vec3);

    vector <char> vec4(vec3);//   character vector from vector 3
    vector<int> vec5(6,5);// 6 element vector from 5
    display(vec5);
    cout<<vec5.front()<<endl;

    return 0;
}