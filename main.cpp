#include<iostream>
#include<string>

using namespace std;

struct Node {
    string data;
    Node *next;
};

struct List{
    Node *head;
};
bool reg_print (List list ,string filter ) {
    bool test=false;
    List list1=list;
    while(list1.head!=nullptr){
        string stroka=list1.head->data;
        if (filter[0] == stroka [0]){
            for(int i=0; i<filter.size();i++){
                if(filter[i]!= stroka[i]){
                    test=false;
                    break;
                } else {
                    test=true;
                }
            }
            if (test==true) {
                return true;
            }
        }
        list1.head=list1.head->next;
    }
    return false;
}
bool simple_print(List list,string filter){
    List list1=list;
    while(list1.head !=nullptr) {
        if (list1.head->data==filter) {
                return true;
        }
        list1.head=list1.head->next;
    }
    return false;
}

int main(int argc , char *argv[]){
    List list;
    list.head=new Node{"stroka1",nullptr};
    list.head->next=new Node {"stroka2",nullptr};
    list.head->next->next=new Node {"stroka30",nullptr};
    cout<<simple_print(list,"stroka1")<<endl;
    cout<<reg_print(list,"stroka300")<<endl;
    return 0;
}

