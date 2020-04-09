#include<iostream>
#include<algorithm>
using namespace std;

class Array{
	public:
	
	//data
	int *A;
	int length=0;
	int size=0;
	
	//constructor
	Array(int s){
		this->size=s;
		this->A=new int[size];
	}
	//destructor
	~Array(){
		delete []A;
	}
	//display
	void Display(){
		for(int i=0;i<this->length;i++){
			cout<<"  "<<i<<"   :  "<<A[i]<<endl;
		}
	}
	//append
	void Append(int num){
		if(this->length<this->size){
			A[this->length]=num;
			this->length++;
			cout<<"Element "<<num<<" appended!!"<<endl;
		}else{
			cout<<"Array Full!!"<<endl;
		}
	}
	//sort
	void Sort(){
		sort(A,A+length);
		cout<<"Sorted!"<<endl;
	}
	//getSize
	int GetSize(){
		return this->size;
	}
	//getLength
	int GetLength(){
		return this->size;
	}
};

//merging
void Merge(Array *arr1,Array *arr2){
	cout<<"MERGING!"<<endl;
	cout<<""<<endl;
	int m=arr1->GetLength();
	int n=arr2->GetLength();
		
	Array C(m+n);
	int i=0,j=0;
		
	while(i<m&&j<n){
			if(arr1->A[i]<arr2->A[j]){
				C.Append(arr1->A[i]);
				i++;
			}else{
				C.Append(arr2->A[j]);
				j++;
			}
		}
	for(;i<m;i++){
			C.Append(arr1->A[i]);
	}
		
	for(;j<n;j++){
			C.Append(arr2->A[j]);
	}
		C.Display();
	}

//intersection
void Intersection(Array *arr1,Array *arr2){
	cout<<"INTERSECTION!"<<endl;
	cout<<""<<endl;
	int m=arr1->GetLength();
	int n=arr2->GetLength();
	int newsize=m+n;
	Array arr3(newsize);
	int i=0,j=0;
			
	while(i<m&&j<n){
		if(arr1->A[i]<arr2->A[j])
 			i++;
 		else if(arr2->A[j]<arr1->A[i])
 			j++;
 		else if(arr1->A[i]==arr2->A[j]){
 			arr3.Append(arr1->A[i]);
 			i++;
 			j++;
 		}
	}
	arr3.Display();
}

//union
void Union(Array *arr1,Array *arr2){
	cout<<"UNION!"<<endl;
	cout<<""<<endl;
	int m=arr1->GetLength();
	int n=arr2->GetLength();
	int newsize=m+n;
	Array arr3(newsize);
	int i=0,j=0;
	
	while(i<m&&j<n){
		if(arr1->A[i]<arr2->A[j])
 			arr3.Append(arr1->A[i++]);
 		else if(arr2->A[j]<arr1->A[i])
 			arr3.Append(arr2->A[j++]);
 		else
 		{
 			arr3.Append(arr1->A[i++]);
 			j++;
 		}
 	}
 	for(;i<arr1->length;i++)
 		arr3.Append(arr1->A[i]);
 	for(;j<arr2->length;j++)
 		arr3.Append(arr2->A[j]);
	
	arr3.Display();
}

//difference
void Difference(Array *arr1,Array *arr2){
	cout<<"DIFFERENCE A-B!"<<endl;
	cout<<""<<endl;
	int m=arr1->GetLength();
	int n=arr2->GetLength();
	int newsize=m+n;
	Array arr3(newsize);
	int i=0,j=0;
	
	while(i<m&&j<n){
		if(arr1->A[i]<arr2->A[j])
 			arr3.Append(arr1->A[i++]);
 		else if(arr2->A[j]<arr1->A[i])
 			j++;
		else
 		{
			i++;
 			j++;
 		}
 	}
 	for(;i<arr1->length;i++)
 		arr3.Append(arr1->A[i]);
	
	arr3.Display();
	
}
	
int main(){
	cout<<"Operations on A :)"<<endl;
	Array a(5);
	a.Append(10);
	a.Append(-5);
	a.Append(30);
	a.Append(55);
	a.Append(78);
	a.Sort();
	cout<<""<<endl;
	
	cout<<"Operations on B :)"<<endl;
	Array b(5);
	b.Append(45);
	b.Append(30);
	b.Append(-10);
	b.Append(55);
	b.Append(100);
	b.Sort();
	cout<<""<<endl;
	
	cout<<"Operations on C :)"<<endl;
	cout<<""<<endl;
	
	Merge(&a,&b);
	cout<<""<<endl;
	
	Intersection(&a,&b);
	cout<<""<<endl;
	
	Difference(&a,&b);
	cout<<""<<endl;
	
	Union(&a,&b);
	cout<<""<<endl;	
}
