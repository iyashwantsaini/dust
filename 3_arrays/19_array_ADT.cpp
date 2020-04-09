#include<iostream>
#include<algorithm>
using namespace std;

class Array{
	//data
	private:
	int *A;
	int length=0;
	int size=0;
	
	public:
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
	//insert
	void Insert(int index,int num){
		if(this->length<this->size){
			for(int i=this->length;i>index;i--){
				A[i]=A[i-1];
			}
			A[index]=num;
			this->length++;
		}else{
			cout<<"Array Full!!"<<endl;
		}
	}
	//delete
	void Delete(int index){
		int el=A[index];
		if(index>=0&&index<this->length){
			for(int i=index;i<this->length;i++){
				A[i]=A[i+1];
			}
			this->length--;
			cout<<"Element "<<el<<" at index {"<<index<<"} deleted!!"<<endl;
		}else{
			cout<<"Invalid Index!!"<<endl;
		}
	}
	//linear search
	void LinearSearch(int num){
		cout<<"You'll only see the first occurence of the element :( "<<endl;
		for(int i=0;i<this->length;i++){
			if(A[i]==num){
				cout<<"Element "<<num<<" found at posn : "<<i<<endl;
				return;
			}
		}
		cout<<"Element not found :("<<endl;
	}
	//binary search
	void BinarySearch(int l,int h,int num){
		static int count{};
		sort(this->A,this->A+length);
		if(count==0){
		Display();
		}
		count++;
		
		int key=num;
		int mid;
		if(l<=h){
		mid=(l+h)/2;
		if(key==A[mid]){
			cout<<"found at index : "<<mid;
			return;
		}else if(key<A[mid]){
			BinarySearch(l,mid-1,num);
		}else if(key>A[mid]){
			BinarySearch(mid+1,h,num);
		}
		}
//		cout<<"not found!";
		return;
	}
	//get
	void Get(int num){
		for(int i=0;i<length;i++){
			if(A[i]==num){
				cout<<"Found "<<num<<" at posn : "<<i<<endl;
			}
		}
	}
	//set
	void Set(int index,int num){
		A[index]=num;
		cout<<"Done!"<<endl;
	}
	//sum
	void Sum(){
		int sum=0;
		for(int i=0;i<length;i++){
			sum=sum+A[i];
		}
		cout<<"Sum : "<<sum<<endl;
	}
	//average
	void Average(){
		int sum=0;
		for(int i=0;i<length;i++){
			sum=sum+A[i];
		}
		cout<<"Average : "<<(sum/length)<<endl;
	}
	//max
	void Max(){
		int max=A[0];
		for(int i=0;i<length;i++){
			if(A[i]>max){
				max=A[i];
			}
		}
		cout<<"Max Element : "<<max<<endl;
	}
	//min
	void Min(){
		int min=A[0];
		for(int i=0;i<length;i++){
			if(A[i]<min){
				min=A[i];
			}
		}
		cout<<"Min Element : "<<min<<endl;
	}
	//reverse
	void Reverse(){
		int temp;
		for(int i=0,j=length-1;i<j;i++,j--){
			temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}
		cout<<"Done Reversing!"<<endl;
	}
	//leftshift
	void LeftShift(){
		cout<<"It's Left Rotate i.e Not removing any element ;)"<<endl;
		int first=A[0];
		for(int i=0;i<length-1;i++){
			A[i]=A[i+1];
		}
		A[length-1]=first;
		cout<<"Done :)"<<endl;
	}
	//rightshift
	void RightShift(){
		cout<<"It's Right Rotate i.e Not removing any element ;)"<<endl;
		int last=A[length-1];
		for(int i=length-1;i>0;i--){
			A[i]=A[i-1];
		}
		A[0]=last;
		cout<<"Done :)"<<endl;
	}
	//sort
	void Sort(){
		sort(A,A+length);
		cout<<"Sorted!"<<endl;
	}
	//insertInSorted
	void InsertInSorted(int num){
		int l=length-1;
		if(length<size){
			while(num<A[l]){
				A[l+1]=A[l];
				l--;
			}
			A[l+1]=num;
			length++;
			cout<<"Inserted!"<<endl;
		}else{
				cout<<"Array Full!"<<endl;
			}
	}
	//rearrange
	void Rearrange(){
		int i=0,j=length-1;
		while(i<j){
			while(A[i]<0){
				i++;
			}
			while(A[j]>=0){
				j--;
			}
			if(i<j){
				swap(A[i],A[j]);
			}
		}
		cout<<"Done!"<<endl;
	}
	//isSorted
	void IsSorted(){
		for(int i=0;i<length-1;i++){
			if(A[i]<A[i+1]){
				continue;
			}else{
				cout<<"Not Sorted!"<<endl;
				break;
			}
		}
		cout<<"Sorted!!"<<endl;
	}
	//getSize
	int GetSize(){
		return this->size;
	}
	//getLength
	int GetLength(){
		return this->size;
	}
//	//merging
//	void Merge(Array *B){
//		int m=this->GetLength();
//		int n=B->GetLength();
//		
//		Array C(m+n+1);
//		int i=0,j=0;
//		
//		while(i<m&&j<n){
//			if(A[i]<B->A[j]){
//				C.Append(A[i]);
//				i++;
//			}else{
//				C.Append(B->A[j]);
//				j++;
//			}
//		}
//
//		for(;i<m;i++){
//			C.Append(A[i]);
//		}
//		
//		for(;j<n;j++){
//			C.Append(B->A[j]);
//		}
//		cout<<"Merged!!"<<endl;
//		cout<<"New array elements : "<<endl;
//		C.Display();
//	}
//	
	
};

int main(){
	int size;
	cout<<"Enter Size of Array : ";
	cin>>size;
	Array a(size);
	
//	cout<<"Creating temp Array B"<<endl;
//	Array b(5);
//	b.Append(2);
//	b.Append(-100);
//	b.Append(30);
//	b.Append(55);
//	b.Append(-23);
	
	cout<<"0:  Exit Loop :)"<<endl;
	cout<<"1:  Append"<<endl;
	cout<<"2:  Insert"<<endl;
	cout<<"3:  Delete"<<endl;
	cout<<"4:  Display"<<endl;
	cout<<"5:  Linear Search"<<endl;
	cout<<"6:  Binary Search"<<endl;
	cout<<"7:  Get"<<endl;
	cout<<"8:  Set"<<endl;
	cout<<"9:  Max"<<endl;
	cout<<"10: Min"<<endl;
	cout<<"11: Sum"<<endl;
	cout<<"12: Average"<<endl;
	cout<<"13: Reverse"<<endl;
	cout<<"14: Left Shift/Rotate"<<endl;
	cout<<"15: Right Shift/Rotate"<<endl;
	cout<<"16: Insert in Sorted"<<endl;
	cout<<"17: Rearrange"<<endl;
	cout<<"18: IsSorted"<<endl;
	cout<<"19: Sort"<<endl;
	
	while(1){
		int option;
		int num;
		int index;
		int sizenewarr;

		cin>>option;
		switch(option){
			case 0:
				cout<<"Bye!! :(";
				break;
			case 1:
				cout<<"Enter element to Append : ";
				cin>>num;
				a.Append(num);
				break;
			case 2:
				cout<<"Enter element to Insert : ";
				cin>>num;
				cout<<"Enter Index for element : ";
				cin>>index;
				a.Insert(index,num);
				break;
			case 3:
				cout<<"Enter index to Delete : ";
				cin>>index;
				a.Delete(index);
				break;
			case 4:
				cout<<"INDEX : VALUE"<<endl;
				a.Display();
				break;
			case 5:
				cout<<"Enter element to Search : ";
				cin>>num;
				a.LinearSearch(num);
				break;
			case 6:
				cout<<"Beware! Elements will be sorted permanently! :)"<<endl;
				int l,h,num;
				cout<<"Enter lower index : ";
				cin>>l;
				cout<<"Enter higher index :";
				cin>>h;
				cout<<"Enter value to search : ";
				cin>>num;
				cout<<"You'll only see first occurence of the element in the sorted array :("<<endl;
				a.BinarySearch(l,h,num);
				break;
			case 7:
				cout<<"Enter element to get : "<<endl;
				cin>>num;
				a.Get(num);
				break;
			case 8:
				cout<<"Enter element to set : "<<endl;
				cin>>num;
				cout<<"Enter index where : "<<endl;
				cin>>index;
				a.Set(index,num);
				break;
			case 9:
				a.Max();
				break;
			case 10:
				a.Min();
				break;
			case 11:
				a.Sum();
				break;
			case 12:
				a.Average();
				break;
			case 13:
				a.Reverse();
				break;
			case 14:
				a.LeftShift();
				break;
			case 15:
				a.RightShift();
				break;
			case 16:
				cout<<"Make Sure Array is sorted before moving on! :)"<<endl;
				cout<<"Enter value : ";
				cin>>num;
				a.InsertInSorted(num);
				break;
			case 17:
				cout<<"All -ves to left and +ves to right :)"<<endl;
				a.Rearrange();
				break;
			case 18:
				a.IsSorted();
				break;
			case 19:
				a.Sort();
				break;
			default:
				cout<<"Press 0 to Exit! :)";
				break;
		}
	}
	return 0;	
}
