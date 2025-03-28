#include <iostream>
using namespace std;
int lcm(int x,int y,int m)
{
    int l=0;
     for(;;m++){
        if(m%x==0 & m%y==0 ){
        l=m;
        break;
        }
     }
     return l;
}
int gcd(int x,int y,int m)
{
    
    int g=(x*y)/lcm(x,y,m);
    return g;
}

int main() {
	// your code goes here
	int x;
	cin>>x;
	while(x--){
	    int k,mi;
	    int count=0;
	    cin>>k;
	    int a[k];
	    for(int i=0;i<k;k++)
	    cin>>a[i];
	    for(int i=0;i<k;k++)
	    {
	        for(int j=i+1;j<k;k++)
	        {
	              if(a[i]>a[j])
                  mi=a[i];
                  else
                  mi=a[j];
	            if(lcm(a[i],a[j],mi)==gcd(a[i],a[j],mi))
	            count++;
	        }
	    }
	    cout<<count<<endl;
	}
	
	return 0;
}