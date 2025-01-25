#include<iostream>
using namespace std;
class example{
    public:
    example(){
        cout<<"const..\n";
    }
    ~example(){
        cout<<"dist..\n";
    }
};
int main() {
    int a=0;
    if (a==0){
       static example eg1;
    }
    cout<<"code ending\n";
    return 0;
}
