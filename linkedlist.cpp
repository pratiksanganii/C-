#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    
    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtTail(node* &head,int val){
    node* n=new node(val);

    if(head==NULL){
        head=n;
        return;
    }

    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

bool search(node* head,int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

// Deletion in linked list

void deleteathead(node* &head){
    node* todelete=head;
    head=head->next;
    delete todelete;
}

void deletion(node* &head,int val){
    node* temp=head;

    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deleteathead(head);
        return;
    }

    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* tobdeleted=temp->next;
    temp->next=temp->next->next;
    delete tobdeleted;
}

// Reverse linked list
node* reverse(node* &head){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    while(currptr!=0){
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}

node* reverseusingrecursive(node* &head){
    
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newhead = reverseusingrecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

node* reversetillk(node* &head,int k){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    int count=0;
    while(currptr!=NULL && count!=k){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if(nextptr!=NULL){
        head->next = reversetillk(nextptr,k);
    }
    return prevptr;
}

bool detectCycle(node* &head){
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow){
            return true;
        }
    }
    return false;
}

void makeCycle(node* &head,int pos){
    node* temp=head;
    node* startNode;

    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startNode;
}

void removeCycle(node* &head){
    node* slow=head;
    node* fast=head;

    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);

    fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }

    slow->next=NULL;
}

int length(node* head){
    int l=0;
    node* temp=head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}

node* appendk(node* &head,int k){
        node* newHead;
        node* newTail;
        node* tail=head;
        int l=length(head);
        k=k%l;
        int count=1;
        while(tail->next!=NULL){
            if(count==l-k){
                newTail=tail;
            }
            if(count==(l-k+1)){
                newHead=tail;
            }
            tail=tail->next;
            count++;
        }
        newTail->next=NULL;
        tail->next=head;
        return newHead;
}


int intersection(node* &head1,node* &head2){
    int l1=length(head1);
    int l2=length(head2);

    int d=0;
    node* ptr1;
    node* ptr2;

    if(l1>l2){
        d=l1-l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }
    while(d){
        ptr1=ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        d--;
    }
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}

void intersect(node* &head1,node* &head2,int pos){
    node* temp1=head1;
    node* temp2=head2;
    pos--;
    while(pos--){
        temp1=temp1->next;
    }
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;

}

int main(){
    node* head2=NULL;
    node* head1=NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,2);
    insertAtTail(head1,3);
    insertAtTail(head1,4);
    insertAtTail(head1,5);
    insertAtTail(head1,6);
    insertAtTail(head2,9);
    insertAtTail(head2,10);
    intersect(head1,head2,3);
    display(head1);
    display(head2);
    cout<<intersection(head1,head2);
    //makeCycle(head,3);
    //cout<<detectCycle(head)<<endl;
    //removeCycle(head);
    //cout<<detectCycle(head)<<endl;
    //display(head);
    //int k=2;
    //node* newhead=reversetillk(head,k);
    //display(newhead);
    //node* newhead=appendk(head,3);
    //display(newhead);
    return 0;
}