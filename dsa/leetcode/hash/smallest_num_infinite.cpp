//2336
#include<bits/stdc++.h>
using namespace std;
class SmallestInfiniteSet {
    public:
    vector<int>nums;
    int i;
        SmallestInfiniteSet() {
            nums=vector<int>(1001,1);
            i=1;
        }
        
        int popSmallest() {
            int temp=i;
            nums[i]=0;
            for(int j=i+1;j<=1000;j++){
                if(nums[j]==1){
                    i=j;
                    break;
                }
            }
            return temp;
        }
        
        void addBack(int num) {
            if(num<i) i=num;
            nums[num]=1;
        }
    };
    
    /**
     * Your SmallestInfiniteSet object will be instantiated and called as such:
     * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
     * int param_1 = obj->popSmallest();
     * obj->addBack(num);
     */
    int main(){
        SmallestInfiniteSet s;
        cout<<s.popSmallest()<<endl;
        cout<<s.popSmallest()<<endl;
        cout<<s.popSmallest()<<endl;
        s.addBack(1);
        cout<<s.popSmallest()<<endl;
    }