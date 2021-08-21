#include <iostream>
#include<fstream>

using namespace std;

void ControlPanel(){
    cout<<"      ****************************"<<endl;
    cout<<"      *   FEATURES OF LIBRARY    *"<<endl;
    cout<<"      ****************************"<<endl;
    cout<<"      1.Add New Books"<<endl;
    cout<<"      2.Display Books"<<endl;
    cout<<"      3.Check Book"<<endl;
    cout<<"      4.Update Books"<<endl;
    cout<<"      5.Delete Books"<<endl;
    cout<<"      6.EXIT"<<endl;
}

void AddBooks(){
    fstream file;
    string book_name,author_name,book_id;
    int n;
    cout<<"   *Enter Book Name: ";
    cin>>book_name;
    cout<<"   *Enter Author Name: ";
    cin>>author_name;
    cout<<"   *Enter Book ID: ";
    cin>>book_id;
    cout<<"   *Enter number of books: ";
    cin>>n;
    file.open("Books.txt",ios::out|ios::app);
    file<<book_name<<" "<<author_name<<" "<<book_id<<" "<<n<<endl;
    file.close();
}

void DisplayBooks(){
    fstream file;
    string book_name,author_name,book_id;
    int n;
    file.open("Books.txt",ios::in);
    if(!file){
        cout<<"Error - File not found";
    }else{
        cout<<"Books   |   Author  |  Book_ID | No.of_Copies"<<endl<<endl;
        file>>book_name>>author_name>>book_id>>n;
        while(!file.eof()){
            cout<<book_name<<" | "<<author_name<<" | "<<book_id<<" | "<<n<<endl<<endl;
            file>>book_name>>author_name>>book_id>>n;
        }
        file.close();
    }
}

void CheckBook(){
    fstream file;
    string book_name,author_name,book_id,book_idd;
    int n,cnt=0;
    file.open("Books.txt",ios::in);
    if(!file){
        cout<<"Error - File not found"<<endl;
    }else{
        cout<<"Book ID: ";
        cin>>book_idd;
        file>>book_name>>author_name>>book_id>>n;
        while(!file.eof()){
            if(book_idd==book_id){

                cout<<"Book Id: "<<book_id<<endl;
                cout<<"Book Name: "<<book_name<<endl;
                cout<<"Author: "<<author_name<<endl;
                cout<<"No. of books available: "<<n<<endl;
                cnt++;
                break;
            }
            file>>book_name>>author_name>>book_id>>n;
        }
        file.close();
        if(cnt==0){
            cout<<"Book Not Found"<<endl;
        }
    }
}

void UpdateBook(){
    fstream file,file1;
    int n,n1,cnt=0;
    string book_name,b_name,author_name,a_name,book_id,book_idd;
    file1.open("Books1.txt",ios::out|ios::app);
    file.open("Books.txt",ios::in);
    if(!file){
        cout<<"Error - File not found";
        }
        else{
            cout<<"Book ID: ";
            cin>>book_id;
            file>>book_name>>author_name>>book_idd>>n;
            while(!file.eof()){
                if(book_id==book_idd){
                    cout<<"New book name: ";
                    cin>>b_name;
                    cout<<"Author Name: ";
                    cin>>a_name;
                    cout<<"No.of copies: ";
                    cin>>n1;
                    file1<<b_name<<" "<<a_name<<" "<<book_id<<" "<<n1<<endl;
                    cnt++;
                }else{
                    file1<<book_name<<" "<<author_name<<" "<<book_idd<<" "<<n<<endl;
                }
                file>>book_name>>author_name>>book_idd>>n;
            }
            if(cnt==0){
                cout<<"Book Not Found"<<endl;
            }
        }
        file.close();
        file1.close();
        remove("Books.txt");
        rename("Books1.txt","Books.txt");
}

void DeleteBook(){
    fstream file,file1;
    int n,cnt=0;
    string book_name,author_name,book_id,book_idd;
    file1.open("Books1.txt",ios::out|ios::app);
     file.open("Books.txt",ios::in);
     if(!file){
        cout<<"Error - File not found";
        }else{
            cout<<"Book ID: ";
            cin>>book_id;
            file>>book_name>>author_name>>book_idd>>n;
            while(!file.eof()){
                if(book_id==book_idd){
                    cout<<"One book is deleted successfully..."<<endl;
                    cnt++;

                }else{
                    file1<<book_name<<" "<<author_name<<" "<<book_idd<<" "<<n<<endl;
                }file>>book_name>>author_name>>book_idd>>n;
            }
            if(cnt==0){
                cout<<"Book Not Found"<<endl;
            }
        }
        file.close();
        file1.close();
        remove("Books.txt");
        rename("Books1.txt","Books.txt");
}

int main(){
    int c;
    char x;
    do{
        ControlPanel();
        cout<<"   *Enter your Choice: *"<<endl;
        cin>>c;
        switch(c){
        case 1:
            {
                do{
                    AddBooks();
                    cout<<"Do you want to insert more books(y,n): ";
                    cin>>x;
                }while(x!='n');
                break;
            }
        case 2:
            {
                DisplayBooks();
                break;
            }
        case 3:
            {
                CheckBook();
                break;
            }
        case 4:
            {
                UpdateBook();
                break;
            }
        case 5:
            {
                DeleteBook();
                break;
            }
        case 6:
            {
                break;
            }
        default:
            {
                cout<<"Please enter valid choice :"<<endl;
            }
        }
    }while(c!=6);
    return 0;
}
