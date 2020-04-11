#include<bits/stdc++.h>
using namespace std;

//struct implementation
//addition


struct element{
        int i;
        int j;
        int x;
};
struct sparseMatrix{
        int m;
        int n;
        int num;
        element *e;
};
int length(sparseMatrix *s){
    return s->num;
}
void createMatrix(sparseMatrix *s){
    s->e=new element[s->num];
    cout<<"Enter all elements : "<<endl;
    for(int iter=0;iter<s->num;iter++){
        cout<<"element > "<<iter<<" | enter row, col, num : ";
        cin>>s->e[iter].i>>s->e[iter].j>>s->e[iter].x;
    }
}
void displayMatrix(sparseMatrix *s){
    // cout<<"All elements are : "<<endl;
    for(int iter=0;iter<s->num;iter++){
        cout<<"element > "<<iter<<" | row = "<<s->e[iter].i<<" col = "<<s->e[iter].j<<" num = "<<s->e[iter].x;
        cout<<"\n";
    }
}
void additionMatrices(sparseMatrix *s1,sparseMatrix *s2){
    struct sparseMatrix s3;
    s3.num=s1->num+s2->num;
    s3.m=s1->m;
    s3.n=s1->n;
    s3.e=new element[s1->num+s2->num];

    int m{},n{},o{};
    while(m<s1->num&&n<s2->num){
        //row check
        if(s1->e[m].i<s2->e[n].i){
            s3.e[o++]=s1->e[m++];
        }else if(s1->e[m].i>s2->e[n].i){
            s3.e[o++]=s2->e[n++];
        }else{
            //col check
            if(s1->e[m].j<s2->e[n].j){
                s3.e[o++]=s1->e[m++];
            }else if(s1->e[m].j>s2->e[n].j){
                s3.e[o++]=s2->e[n++];
            }else{
                s3.e[o]=s1->e[m++];
                s3.e[o].x+=s2->e[n].x;
                n++;
                o++;
            }
        }
    }
    // copy remaining terms of longer array
    for(;m<s1->num;m++){
        s3.e[o++]=s1->e[m];
    }
    for(;n<s2->num;m++){
        s3.e[o++]=s2->e[m];
    }
    
    s3.num=o;
    cout<<"Sum matrix : "<<endl;
    for(int iter=0;iter<s3.num;iter++){
        cout<<"element > "<<iter+1<<" | row = "<<s3.e[iter].i<<" col = "<<s3.e[iter].j<<" num = "<<s3.e[iter].x;
        cout<<"\n";
    }

}


int main(){

    //matrix 1
    int n1;
    cout<<"Enter number of non zero elements in matrix 1 : ";
    cin>>n1;
    struct sparseMatrix s1;
    s1.num=n1;
    s1.m=4;
    s1.n=4;
    createMatrix(&s1);
    //matrix 2
    int n2;
    cout<<"Enter number of non zero elements in matrix 2 : ";
    cin>>n2;
    struct sparseMatrix s2;
    s2.num=n2;
    s2.m=4;
    s2.n=4;
    createMatrix(&s2);

    cout<<"\n\n";
    //display
    cout<<"Matrix 1 : "<<endl;
    displayMatrix(&s1);
    cout<<"Matrix 2 : "<<endl;
    displayMatrix(&s2);

    //sum
    cout<<"Addition of 2 matrices : "<<endl;
    additionMatrices(&s1,&s2); 

}