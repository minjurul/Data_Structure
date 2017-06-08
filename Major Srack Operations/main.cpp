#include<iostream>
#include<cstdlib>
using namespace std;
#define STACKSIZE 5

struct bufferstack{
    int stk[STACKSIZE];
    int top;
} pointer;

void push();
int  pop();
void display();

int main(){
    int c;

    while(true){

        cout<<"\n1: Push"<<endl<<"2: Pop"<<endl<<"3: Display"<<endl<<"4: Exit"<<endl;
        cout<<"Please enter your choice :";
        cin>>c;
            switch(c){
                case 1:
                    push();
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    display();
                    break;
                case 4:
                    exit(0);
                    break;
            }
      }
}

void push(){
    int num;
    if(pointer.top==(STACKSIZE-1)){
        cout<<"\n Sorry You can't push any element into stack .... ,Stack is full";
    }else{
        cout<<"\n Enter the number to push into stack :";
        cin>>num;
        pointer.top+=1;
        pointer.stk[pointer.top]= num;
    }
}

int pop(){
    int num;
    if(pointer.top==-1){
        cout<<"\nstack is empty "<<endl;
    }else{
        num=pointer.top;
        cout<<"\n Poped number is : "<<pointer.stk[num]<<"\n";
        pointer.stk[num]=0;
        pointer.top-=1;
    }
    return num;

}

void display(){
    if(pointer.top==-1){
        cout<<"\n Stack is empty"<<endl;
    }else{
        for(int i=pointer.top;i>=0;i--){
                cout<<"\n"<<i<<":"<<pointer.stk[i]<<endl;
            }
    }
}
