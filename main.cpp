#include <iostream>
using namespace std;

string name[20];
int inputValue,welcome;

void read(){

}




void write(){
    
}



void overwrite(){

}



void delet(){

}


void search(){

}


int main(){

    cout<<"\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
    cout<<"!!!! Welcome to our Record keeping software !!!!!"<<endl;
    cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;

    while (true){

    cout <<"\nPress the following keys for various functions"<<endl<<endl;
    cout<<"\t 1 : Read data"<<endl;
    cout<<"\t 2 : Write/Append data"<<endl;
    cout<<"\t 3 : Overwrite data"<<endl;
    cout<<"\t 4 : Delete data"<<endl;
    cout<<"\t 5 : Search data"<<endl;
    cout<<"\t 6 : Exit"<<endl;

    cin>>inputValue;

    switch(inputValue){

    case 1: 
        read();            //function call
        break;

    case 2:
        write();
        break;

    case 3:
         overwrite();
         break;
        
    case 4:
        delet();
        break;

    case 5:
      search();
      break;

    case 6:
       exit(0);

    default:
      cout<<"\nInvalid Input"<<endl;
      break;
    


    }

    }



}