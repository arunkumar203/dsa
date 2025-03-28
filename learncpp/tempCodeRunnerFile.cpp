template<class t>
void  display(vector< t> &v){
    for(int i = 0; i < v.size();i++) {
        cout<<v[i]<<" ";
        // cout<<v.at(i)<<" ";
    }
    printf("\n");
}