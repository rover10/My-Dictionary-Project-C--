#include<string> 
#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
//tHIS IS A CHANGE
class Node{
	Node *arr[26];
	bool flag;
	public:
		Node(){
			int SIZE=26;
			for(int i=0;i<SIZE;i++)
				arr[i]=nullptr;
			flag=false;
		}
	
		bool strinsert(string str,int index=0){
			if(str[index]=='\0' && index!=0){ //prevent insertion of empty string
				flag=true;
				return true;
			}	
			
			if(str[index]<65||str[index]>122||(str[index]>90 && str[index]<97)){
				if(index!=0)
					flag=true;//Discard other characters when encounter first non Roman alphabets eg. "Mango9"   ----stores-----> "Mango"
				return false;	
			}
			
			int sub=65;
			if(str[index]>90)
				sub=97;
			if(arr[str[index]-sub]==nullptr){
				if(str[index]>=65 && str[index]<=90 ){
					arr[str[index]-65]=new Node;
					return true && arr[str[index]-65]->strinsert(str, index+1);
				}
				if(str[index]>=97 && str[index]<=122 ){
					arr[str[index]-97]=new Node;
					return true && arr[str[index]-97]->strinsert(str, index+1);
				}
			}else{
				if(str[index]>=65 && str[index]<=90 ){
				//	arr[str[index]-65]=new Node;
					return true && arr[str[index]-65]->strinsert(str, index+1);
				}
				if(str[index]>=97 && str[index]<=122 ){
				//	arr[str[index]-97]=new Node;
					return true && arr[str[index]-97]->strinsert(str, index+1);
				}
			}
			
			//flag=true;
		}
				
		bool strinsert(char *str,int index=0)
		{
			if(str[index]=='\0' && index!=0)
			{
					flag=true;
					return true;
			}
			
			
			if(str[index]<65||str[index]>122||(str[index]>90 && str[index]<97))
			{
				if(index!=0)
					flag=true;
				return false;
			}
					
			int sub=65;
			if(str[index]>90)
				sub=97;
				
			if(sub==65)
			{
				if(arr[str[index]-sub]==nullptr)
				{
						if(str[index]>=65 && str[index]<=90 )
							arr[str[index]-65]=new Node;
						return	true && arr[str[index]-65]->strinsert(str, index+1);
				}
				else
				{
						return	true && arr[str[index]-65]->strinsert(str, index+1);
			    }
			    
			}
			else
			{
				if(str[index]>=97 && str[index]<=122 && (arr[str[index]-sub]==nullptr))
				{
					//	if(str[index]>=97 && str[index]<=122 )
						arr[str[index]-97]=new Node;
			    		return 	true && arr[str[index]-97]->strinsert(str, index+1);
				}
				else
				{
					return	true && arr[str[index]-97]->strinsert(str, index+1);
				}
			}
			//flag=true;
	   }

		bool search(string str,int index=0){
			if(str[index]=='\0' && str.length()==index) //Returns only if length of search word equals word dictionary
				return flag;
			
			
		//	if(flag==true && str[index]!='\0')//Handles case when search string is bigger than stored & contains other special characters
		//		return false;
			if(str[index]>=65 && str[index]<=90 ){
			
				if(arr[str[index]-65]!=nullptr)
					return (true && arr[str[index]-65]->search(str,index+1));
			//	else
			//		return true;
						
			}
			
			if(str[index]>=97 && str[index]<=122 ){
				if(arr[str[index]-97]!=nullptr)
					return (true && arr[str[index]-97]->search(str,index+1));
			//	else
			//		return true;
		   }
			return false;///Handles those situation where a non Roman Alphabet is present in Search word eg..  "c88pp"
		}
		
		bool search(char *str,int index=0){
			if(str[index]=='\0'){
				return flag;
			}
			
		//	if(flag==true && str[index]!='\0')
		//		return false;
			
			if(str[index]>=65 && str[index]<=91 ){
			
				if(arr[str[index]-65]!=nullptr)
					return (true && arr[str[index]-65]->search(str,index+1));
			//	else
			//		return false;
		   }
		   
			if(str[index]>=97 && str[index]<=122 ){
		
				if(arr[str[index]-97]!=nullptr)
					return (true && arr[str[index]-97]->search(str,index+1));
			//	else
			//		return false;
		   }
			return false;
		}	
};

class Dict{
	public:
		Node root;
};

int main(){
	
	
	Node n;
	string s="RAKabcdef";
	n.strinsert(s);
	/*
	s="Tomato";
	n.strinsert(s);
	n.strinsert("Tomato");
	s="Mango9";
	n.strinsert(s);
	n.strinsert("8Cpp");
	n.strinsert("");//This string (empty string is not inserted)
	cout<<n.search("Mango")<<endl;
	cout<<n.search("c88pp")<<endl;
	cout<<n.search("tomato")<<endl;
	cout<<n.search("")<<endl;  //Since this string is not inserted it returns false; 
	*/
	
	//Reading from file to build dictionary
	ifstream i;
	i.open("input.txt");
	ofstream o;
	o.open("output.txt");
	int counter=0;
	string temp;
	
	while(i){
		i>>temp;
		n.strinsert(temp);
	//	if(n.search(temp))
		//	o<<temp<<" "<<"found"<<endl;
		//cout<<counter;
	}

/*
	s="ship";
	n.strinsert(s);
	n.strinsert("shipa");
	n.strinsert("shipy");
	n.strinsert("ship");
	if(n.search("ship"))
		cout<<"ship found"<<endl;
	else
		cout<<"Not found!"<<endl;
	
		if(n.search("papaya"))
			cout<<"papaya found"<<endl;
	else
		cout<<"papaya found!"<<endl;

*/


string istr;

while(istr.compare("exit")!=0){
	cout<<"Search >> ";
	cin>>istr;
	if(n.search(istr))
		cout<<endl<<"\t\t\t"<<istr<<endl<<"\t\t\tFound !"<<endl<<endl;
	else
		cout<<endl<<"\t\t\t"<<istr<<endl<<"\t\t\tNot Found"<<endl<<endl;
}



}
