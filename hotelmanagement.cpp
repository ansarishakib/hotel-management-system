#include<iostream>
using namespace std;

class Hotel{
    private:
        struct Node{
            int id,date;
            string name,roomtype;
            Node* next;
        };
    public:
        Node* head=NULL;
        void insert();
        void menu();
        void update();
        void search();
        void del();
        void sort();
        void show();
};

void Hotel::menu()
{
    
    
    int choice;
    cout<<"\n";
    cout<<"\n\n\tWelcome to Hotel Management System Application\n"<<endl;
    cout<<"\n\t__________Hotel Management System_________";
    cout<<"\n\nS.No       Functions             Description"<<endl;
    cout<<"\n1\tAllocate Room\t\t\tInsert New Room";
    cout<<"\n2\tSearch Room\t\t\tSearch Room with RoomID";
    cout<<"\n3\tUpdate Room\t\t\tUpdate Room Record";
    cout<<"\n4\tDelete Room\t\t\tDelete Room with RoomID";
    cout<<"\n5\tShow Room Records\t\tShow Room Records (thet we added)"<<endl;
    cout<<"6\tExit";

    cout<<"\n\nEnter Your Choice"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
            insert();
            menu();
            
        case 2:
            show();
            menu();
            

        case 3:
            update();
            menu();
            

        case 4:
            del();
            menu();
            
        case 5:
            sort();
            show();
            menu();
            
        
        case 6:
            exit(0);
            default:
                cout<<"Invalid";

    }
}

void Hotel::insert(){
    cout<<"\n\n\n\t_____Hotel Management System______";
    Node *new_node = new Node;
    cout<<"\nEnter RoomID : ";
    cin>> new_node->id;
    cout<<"\nEnter Customer Name : ";
    cin>>new_node->name;
    cout<<"\nEnter Allocated Date : ";
    cin>>new_node->date;
    cout<<"\nEnter Room Type (single/double) : ";
    cin>>new_node->roomtype;

    if(head==NULL)
        head=new_node;
    else{
        Node* ptr=head;
        while(ptr->next !=NULL)
        {
            ptr =ptr->next;
        }
        ptr->next = new_node;
    }
    cout<<"\n\n\t\tNew Room Inserted";

}

void Hotel::search(){
    cout<<"\n\n\n\t_____Hotel Management System______";
    int t_id;
    if(head==NULL)
        cout<<"\n\nLinked List is Empty";
    else{
        cout<<"\n\nRoomId ";
        cin>>t_id;
        Node* ptr=head;
        while(ptr!=NULL)
        {
            if(t_id == ptr->id)
            {
                cout<<"\nRoomID : "<<ptr->id;
                cout<<"\n\nCustomer Name : "<<ptr->name;
                cout<<"\n\nRoom Allocated Date : "<<ptr->date;
                cout<<"\n\nRoom Type : "<<ptr->roomtype;
            }
            ptr=ptr->next;
        }
        
    }
    
    
}

void Hotel::update(){
    cout<<"\n\n\n\t_____Hotel Management System______";
    int t_id;
    if(head==NULL)
        cout<<"\n\nLinked List is Empty";
    else{
        cout<<"\n\nRoomID : ";
        cin>>t_id;
        Node *ptr =head;
        while(ptr!=NULL)
        {
            if(t_id == ptr->id)
            {
                cout<<"\n\nRoomID : ";
                cin>>ptr->id;
                cout<<"\n\nCustomer Name : ";
                cin>>ptr->name;
                cout<<"\n\nAllocated Date : ";
                cin>>ptr->date;
                cout<<"\n\nRoom Type : ";
                cin>>ptr->roomtype;
                

                cout<<"\n\n\t\t Record Update Successfuly";
            }
            ptr=ptr->next;
        }

    }
}

void Hotel::del(){
    cout<<"\n\n\n\t_____Hotel Management System______";
    int t_id;
    if(head==NULL)
        cout<<"\n\nLinked List is Empty";
    else{
        cout<<"\n\nRoomID : ";
        cin>>t_id;
        if(t_id ==head->id)
        {
            Node* ptr = head;
            head=head->next;
            delete ptr;
            cout<<"\n\t\tDelete Room Record Successfully";
        }
        else{
            Node* pre =head;
            Node* ptr =head;
            while(ptr!=NULL)
            {
                if(t_id==ptr->id)
                {
                    pre->next =ptr->next;
                    delete ptr;
                    cout<<"\n\t\tDelete Room Record Successfully";
                    break;
                }
                pre=ptr;
                ptr=ptr->next;
            }
        }
    }
}

void Hotel::show(){
    Node* ptr=head;
    while(ptr!=NULL)
    {
        cout<<"\nRoomID : "<<ptr->id;
        cout<<"\nCustomer Date : "<<ptr->name;
        cout<<"\nAllocated Date : "<<ptr->date;
        cout<<"\nRoomType : "<<ptr->roomtype;
        ptr=ptr->next;
    }
}

void Hotel::sort(){
    if(head==NULL)
    {
        cout<<"\n\nLinked list is Empty";
        menu();
    }
    int count=0, t_date,t_id;
    string t_name, t_roomtype;
    Node* ptr = head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    for(int i=1;i<=count;i++)
    {
        Node *ptr=head;
        for(int j=1;j<count;j++)
        {
            if(ptr->id > ptr->next->id){
                t_id = ptr->id;
                t_name = ptr->name;
                t_date = ptr->date;
                t_roomtype = ptr->roomtype;

                //Save Data into current Node
                ptr->id = ptr->next->id;
                ptr->name=ptr->next->name;
                ptr->date=ptr->next->date;
                ptr->roomtype = ptr->next->roomtype;

                //Save data into next node
                ptr->next->id=t_id;
                ptr->next->name=t_name;
                ptr->next->date=t_date;
                ptr->next->roomtype=t_roomtype;
            }
            ptr=ptr->next;
        }
    }
}

int main()
{
    Hotel h;
    h.menu();
}