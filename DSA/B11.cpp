
#include<iostream>
#include<string.h>
using namespace std;

typedef struct node
{
     char key[20];
     char mean[20];
     node *left;
     node *right;
}root;    //structure variable


class tree
{
    public:
    node *root;
    void create();
    //void insert();
    void display(node *root);
    void insert(node *root,node *temp);
    int search(node*root,char[]);
    int update(node*root,char key[]);
    node*del_successor(node*root,char key[]);
    node*del_predecessor(node*root,char key[]);
    node*min(node*root);
    node*max(node*root);
    tree()
    {
       root=NULL;
    }
};

void tree::create()
{
  struct node *temp;
  int ch;
  do
  {
    temp=new node;
    cout<<"\nEnter keyword:";
    cin>>temp->key;
    cout<<"\nEnter meaning:";
    cin>>temp->mean;
    temp->left=NULL;
    temp->right=NULL;
    
    if(root==NULL)
    {
      root=temp;
    }
    else
    {
    insert(root,temp);
    }
    cout<<"Enter 1 to continue or 0 to exit:";
    cin>>ch;
  }
  while(ch==1);
}    
      
      
void tree::insert(node *root,node *temp)
{
  if(strcmp(temp->key,root->key)<0)    //for less than root values
  {
     if(root->left==NULL)
     root->left=temp;
     else
     insert(root->left,temp);
  }
  else                                 //for greater than root values
     if(root->right==NULL)     
     root->right=temp;
     else
     insert(root->right,temp);
}

void tree::display(node *root)
{
   if(root!=NULL)
   {
     display(root->left);
     cout<<"\n Keyword:"<<root->key;
     cout<<"\nMeaning:"<<root->mean;
     display(root->right);
   }
}


int tree::search(node*root,char key[20])
{
     int c=0;
     while(root!=NULL)
     {
       c++;
       if(strcmp(key,root->key)==0)
       {
          cout<<"\nNuber of comparisons:"<<c;
          return 1;
       }
       if(strcmp(key,root->key)<0)
          root=root->left;
       if(strcmp(key,root->key)>0)
          root=root->right;
     }
     return -1;
}

int tree::update(node*root,char key[20])
{
     while(root!=NULL)
     {
           if(strcmp(key,root->key)==0)
           {
               cout<<"\nEnter new meaning of keyword:"<<root->key;
               cin>>root->mean;
               return 1;
            }
            if(strcmp(key,root->key)<0)
              root=root->left;
            if(strcmp(key,root->key)>0)
              root=root->right;
     }
     return -1;
}
 
//For successor
node *tree::del_successor(node*root,char key[20])
{
     node*temp;
     if(root==NULL)
     {
          cout<<"\nElement not found";
          return root;
     } 
     if(strcmp(key,root->key)<0)
     {
          root->left=del_successor(root->left,key);
          return root;
     }
     if(strcmp(key,root->key)>0)
     {
          root->right=del_successor(root->right,key);   
          return root;
     }
     
     if(root->right==NULL&&root->left==NULL)
     {
          temp=root;
          delete temp;
          return NULL;
     }
     if(root->right==NULL)
     {
          temp=root;
          root=root->left;
          delete temp;
          return root;
    }
    else if(root->left==NULL)
     {
          temp=root;
          root=root->right;
          delete temp;
          return root;
    }
    temp=min(root->right);
    strcpy(root->key,temp->key);
    root->right=del_successor(root->right,temp->key);
    return root;
}

node*tree::min(node*q)
{
  while(q->left!=NULL)
  {
     q=q->left;
  }
  return q;
}


//For predecessor
node*tree::del_predecessor(node*root,char key[20])
{
     node*temp;
     if(root==NULL)
     {
          cout<<"\nElement not found";
          return root;
     } 
     if(strcmp(key,root->key)<0)
     {
          root->left=del_predecessor(root->left,key);
          return root;
     }
     if(strcmp(key,root->key)>0)
     {
          root->right=del_predecessor(root->right,key);   
          return root;
     }
     
     if(root->right==NULL&&root->left==NULL)
     {
          temp=root;
          delete temp;
          return NULL;
     }
     if(root->right==NULL)
     {
          temp=root;
          root=root->left;
          delete temp;
          return root;
    }
    else if(root->left==NULL)
     {
          temp=root;
          root=root->right;
          delete temp;
          return root;
    }
    temp=max(root->left);
    strcpy(root->key,temp->key);
    root->left=del_predecessor(root->left,temp->key);
    return root;
}

node*tree::max(node*q)
{
  while(q->right!=NULL)
  {
     q=q->right;
  }
  return q;
}


int main()
{
   int choice;
   tree t; 
   t.root=NULL;
   do
   {
     cout<<"\n-----------------------------------------------------------";
     cout<<"\n1)Create\n2)Display\n3)Search\n4)Update\n5)Delete using successor\n6)Delete using predecessor";
     cout<<"\n-----------------------------------------------------------";
     cout<<"\nEnter your choice:";
     cin>>choice;
     
     switch(choice)
     {
          case 1:
                 t.create();
                 break;
                 
          case 2:
                 if(t.root==NULL)
                 {
                    cout<<"\nNO keyword found";
                 }
                 else
                 {
                    t.display(t.root);
                 }
                 break;
                 
         case 3:
                if(t.root==NULL)
                { 
                    cout<<"\nEmpty....Add keyword and try";
                }
                else
                {
                    cout<<"\nEnter keyword to search:";
                    char key[20];
                    cin>>key;
                    if(t.search(t.root,key)==1)
                    cout<<"\nFound";
                    else
                    cout<<"\nNot found";
                }
                break;
                
          case 4:
                if(t.root==NULL)
                { 
                    cout<<"\nEmpty....Add keyword and try";
                }
                else
                {
                    cout<<"\nEnter keyword to update:";
                    char key[20];
                    cin>>key;
                    if(t.update(t.root,key)==1)
                    cout<<"\nupdated";
                    else
                    cout<<"\nNot found";
                }
                break;
                
            case 5:
                   if(t.root==NULL)
                   { 
                    cout<<"\nEmpty....Add keyword and try";
                   }
                  else
                   {
                    cout<<"\nEnter keyword to delete:";
                    char key[20];
                    cin>>key;
                    if(t.root==NULL)
                      cout<<"\nEmpty ";
                    else
                      t.root=t.del_successor(t.root,key);
                    
                }
                break;
                
                
          case 6:
                   if(t.root==NULL)
                   { 
                    cout<<"\nEmpty....Add keyword and try";
                   }
                  else
                   {
                    cout<<"\nEnter keyword to delete:";
                    char key[20];
                    cin>>key;
                    if(t.root==NULL)
                      cout<<"\nEmpty ";
                    else
                      t.root=t.del_predecessor(t.root,key);
                    
                   }
                   break;
                    
        }
        
   }
    while(choice<=6);
    return 0;
}           
             
    
/*Output
-----------------------------------------------------------
1)Create
2)Display
3)Search
4)Update
5)Delete using successor
6)Delete using predecessor
-----------------------------------------------------------
Enter your choice:1
Enter keyword:g
Enter meaning:good
Enter 1 to continue or 0 to exit:1
Enter keyword:a
Enter meaning:average
Enter 1 to continue or 0 to exit:1
Enter keyword:b
Enter meaning:bad
Enter 1 to continue or 0 to exit:1
Enter keyword:w
Enter meaning:worse
Enter 1 to continue or 0 to exit:1
Enter keyword:f
Enter meaning:fair
Enter 1 to continue or 0 to exit:0
-----------------------------------------------------------
1)Create
2)Display
3)Search
4)Update
5)Delete using successor
6)Delete using predecessor
-----------------------------------------------------------
Enter your choice:2
Keyword:a
Meaning:average
 Keyword:b
Meaning:bad
 Keyword:f
Meaning:fair
 Keyword:g
Meaning:good
 Keyword:w
Meaning:worse
-----------------------------------------------------------
1)Create
2)Display
3)Search
4)Update
5)Delete using successor
6)Delete using predecessor
-----------------------------------------------------------
Enter your choice:3
Enter keyword to search:f
Nuber of comparisons:3
Found
-----------------------------------------------------------
1)Create
2)Display
3)Search
4)Update
5)Delete using successor
6)Delete using predecessor
-----------------------------------------------------------
Enter your choice:4
Enter keyword to update:b
Enter new meaning of keyword:bbetter
updated
-----------------------------------------------------------
1)Create
2)Display
3)Search
4)Update
5)Delete using successor
6)Delete using predecessor
-----------------------------------------------------------
Enter your choice:2
Keyword:a
Meaning:average
 Keyword:b
Meaning:better
 Keyword:f
Meaning:fair
 Keyword:g
Meaning:good
 Keyword:w
Meaning:worse
-----------------------------------------------------------
1)Create
2)Display
3)Search
4)Update
5)Delete using successor
6)Delete using predecessor
-----------------------------------------------------------
Enter your choice:5
Enter keyword to delete:f
-----------------------------------------------------------
1)Create
2)Display
3)Search
4)Update
5)Delete using successor
6)Delete using predecessor
-----------------------------------------------------------
Enter your choice:2
Keyword:a
Meaning:average
 Keyword:b
Meaning:better
 Keyword:g
Meaning:good
 Keyword:w
Meaning:worse
-----------------------------------------------------------
1)Create
2)Display
3)Search
4)Update
5)Delete using successor
6)Delete using predecessor
-----------------------------------------------------------
Enter your choice:*/