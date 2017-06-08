#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
    int info;
    struct node *next;
};

class Link{
     node *list;
    public:
        Link();
        void insert_at_begining(int);
        void insert_at_end(int);
        void insert_before_node();
        void insert_after_node();
        node *find_before_node(node*);
        void display();
};
Link::Link(){
    list = NULL;
}
node *Link::find_before_node(node *p){
    int count = 0;
    int count1 = 0;
    node *temp = new node;
    temp = list;
    while(temp!=p){
        count++;
        temp=temp->next;
    }
    temp = list;
    while(count1<count-1){
        count1++;
        temp = temp->next;
    }
    return temp;
}


void Link::insert_at_begining(int data){
    node *p = new node;
    p->info = data;
    p->next = list;
    list = p;
}



void Link::insert_at_end(int data){
    node *p = new node;
    node *r = new node;
    r = list;
    p->info = data;
    p->next = NULL;
    if(list == NULL){
        list = p;
    }else{
        while(r->next!=NULL){
            r = r->next;
        }
        r->next = p;
    }
}




void Link::insert_before_node(){
    node *p = new node;
    node *l = new node;
    node *r = new node;
    int data1, data2;
    bool isFound = false;
    cout<<"Enter the node: ";
    cin>>data1;
    p = list;
    while(p != NULL){
        if(p->info == data1){
            isFound = true;
            break;
        }
        l = p;
        p = p->next;
    }
    if(isFound){
        cout<<"Enter the data to insert:";
        cin >> data2;
        r->info = data2;
        if(p==list){
            insert_at_begining(data2);
        }else{
            l->next = r;
            r->next = p;
        }
    }else{
        cout<<"\nMember not found\n";
    }
}
void Link::insert_after_node(){
    node *p = new node;
    node *r = new node;
    node *l = new node;
    int data1, data2;
    bool isFound = false;
    cout<<"Enter the node: ";
    cin>>data1;
    p = list;
    while(p!= NULL){
        if(p->info == data1){
            isFound = true;
            break;
        }
        p = p->next;
    }
    if(isFound){
        cout<<"Enter the data to insert: ";
        cin>>data2;
        r->info = data2;
        if(p->next == NULL){
            insert_at_end(data2);
        }else{
            l = p->next;
             p->next = r;
            r->next = l;
        }
    }else{
        cout<<"\nMember not found\n";
    }
}

void Link::display(){
    node *p = new node;
    p = list;
    if(list==NULL){
        cout<<"\nNothing to Display\n";
    }else{
        cout<<"\nThe contents of list\n";
        while(p!=NULL){
            cout<<p->info<<endl;
            p = p->next;
        }
    }
}
int main(){
    int choice;
    Link link;
    while(true){
        int data;
        cout<<"\n1. Insert at the begining"<<endl;
        cout<<"2. Insert at the end"<<endl;
        cout<<"3. Insert before node"<<endl;
        cout<<"4. Insert After node"<<endl;
        cout<<"5. Display"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter the option: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"\nEnter data to Insert: ";
                cin>>data;
                link.insert_at_begining(data);
                break;
            case 2:
                cout<<"Enter data to Insert: ";
                cin>>data;
                link.insert_at_end(data);
                break;
            case 3:
                link.insert_before_node();
                break;
            case 4:
                link.insert_after_node();
                break;
            case 5:
                link.display();
                break;
            case 6:
                exit(0);
                break;
        }
    }
    return 0;
}
