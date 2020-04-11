#include<bits/stdc++.h>
using namespace std;

//creation | display 

class element{
    public:
        int i;
        int j;
        int x;
};
class sparseMatrix{
    private:
        int m;
        int n;
        int num;
        element *e;
    public:
        sparseMatrix(int num){
            this->num=num;
            this->e=new element[num];
        }
        ~sparseMatrix(){
            delete []e;
        }
        int length(){
            return this->num;
        }
        void setDimentions(){
            cout<<"Enter dimentions : "<<endl;
            cout<<"m(rows) : ";
            cin>>m;
            cout<<"n(cols) : ";
            cin>>n;
        }
        void createMatrix(){
            cout<<"Enter all elements : "<<endl;
            for(int iter=0;iter<num;iter++){
                cout<<"element > "<<iter+1<<" | enter row, col, num : ";
                cin>>e[iter].i>>e[iter].j>>e[iter].x;
            }
            cout<<"\n";
        }
        void displayMatrix(){
            cout<<"All elements are : "<<endl;
            for(int iter=0;iter<num;iter++){
                cout<<"element > "<<iter+1<<" | row = "<<e[iter].i<<" col = "<<e[iter].j<<" num = "<<e[iter].x;
                cout<<"\n";
            }
        }
};

int main(){

    //matrix
    int n1;
    cout<<"Enter number of non zero elements in matrix : ";
    cin>>n1;
    sparseMatrix s1(n1);
    s1.setDimentions();
    s1.createMatrix();

    //display
    cout<<"Matrix : "<<endl;
    s1.displayMatrix();
}