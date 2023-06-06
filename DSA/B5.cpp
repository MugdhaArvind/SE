#include<iostream>
using namespace std;
struct node
{
    char label[50];
    int chap_count;
    struct node *child[10];
} * root;

class book
{
    public:
        void create_tree();
        void display(node *r1);
        book()
        {
            root=NULL;
        }
};

void book::create_tree()
{
    int number,i,j,k;
    root=new node;
    cout<<"Enter the name of book:";
    cin>>root->label;
    cout<<"\nEnter number of chapters in book "<<root->label<<":";
    cin>>number;
    root->chap_count=number;
    for(i=0;i<number;i++)
    {
        root->child[i] = new node;
        cout<<"\nEnter name of chapter "<<i+1<<":";
        cin>>root->child[i]->label;
        cout<<"\nEnter number of Sections in chapter "<<root->child[i]->label<<":";
        cin>>root->child[i]->chap_count;
        for(j=0;j<root->child[i]->chap_count;j++)
        {
            root->child[i]->child[j] = new node;
            cout<<"\nEnter name of section"<<j+1<<":";
            cin>>root->child[i]->child[j]->label;
            cout<<"\nEnter number of subsections in section "<<root->child[i]->child[j]->label<<":";
            cin>>root->child[i]->child[j]->chap_count;
            for(k=0;k<root->child[i]->child[j]->chap_count;k++)
            {
                root->child[i]->child[j]->child[k]=new node;
                cout<<"\nEnter name of subsection"<<k+1<<":";
                cin>>root->child[i]->child[j]->child[k]->label;
            }
        }


    }

}

void book::display(node *r1)
{
    int number,i,j,k;
    cout<<"\nBook";
    cout<<"\nBook title:";
    cout<<r1->label;
    cout<<"\nChapters:";
    cout<<r1->chap_count;
    r1->chap_count=number;
    for(i=0;i<number;i++)
    {
        
        cout<<"\nChapter "<<i+1<<":";
        cout<<r1->child[i]->label;
        for(j=0;j<r1->child[i]->chap_count;j++)
        {
            cout<<"\nSection "<<i+1<<"."<<j+1<<":";
            cout<<r1->child[i]->child[j]->label;
            for(k=0;k<r1->child[i]->child[j]->chap_count;k++)
            {
                cout<<"\nSubsection "<<i+1<<"."<<j+1<<"."<<k+1<<":";
                cout<<r1->child[i]->child[j]->child[k]->label;
            }
        }


    }



}

int main()
{
    int choice;
    book b;
    while(1)
    {
        cout<<"\n1.Create\n2.display\n3.exit";
        cout<<"\nEnter you choice of operation:";
        cin>>choice;
        switch(choice)
        {
            case 1:b.create_tree();
                   break;
            case 2:b.display(root);
                   break;
            case 3:exit(1);
                   break;
        }
    }
    return 0;
}