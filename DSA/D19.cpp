#include<string.h>
#include<fstream>
#include<iostream>
using namespace std;
class node
{ char key[20],meaning[20];
node *left,*right;
int ht;
public:
node(char [], char []);
friend class tree;
};
node::node(char k[], char m[])
{
 strcpy(key,k);
 strcpy(meaning,m);
 left=right=NULL;
}
class tree
{
node *root;
node *insert(node *,node *);
node *Delete1(node *,int);
void preorder(node *);
void inorder(node *);
int height( node *);
node *rotateright(node *);
node *rotateleft(node *);
node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);
int bfactor(node *);
public:
tree()
{
 root=NULL;
}
void insert(node *newnd)
{
 root=insert(root,newnd);
}
void Delete(int x)
{
 root=Delete1(root,x);
}
void preorder()
{
 preorder(root);
}
void inorder()
{
 inorder(root);
}
void makenull()
{
 root=NULL;
}
};
int menu()
{
 int choice;
 cout<<"\n1.Insert : ";
 cout<<"\n2.Construct AVL : ";
 cout<<"\n3.Print : ";
 cout<<"\n4.Exit : ";
 cout<<"\nEnter Your Choice : ";
 cin >> choice;
 return choice;
}//
node * tree::insert(node *t,node *newnd)
{
 if(t==NULL)
 {
 t=newnd;
 }
 else if(strcmp(newnd->key,t->key)>0) // insert in right subtree
 {
 t->right=insert(t->right,newnd);
 if(bfactor(t)==-2)
 {
 cout<<"\nUnbalance at "<<t->key;
 if(strcmp(newnd->key,t->right->key)>0)
 t=RR(t); // right's right
 else
 t=RL(t); // right's left
 }
 }
 else if(strcmp(newnd->key,t->key)<0) // insert in left subtree
 {
 t->left=insert(t->left,newnd);
 if(bfactor(t)==2)
 {
 cout<<"\nUnbalance at "<<t->key;
 if(strcmp(newnd->key,t->left->key)<0)
 t=LL(t); // left's left
 else
 t=LR(t); //left's right
 }
 }
 t->ht=height(t);
 return t;
}
int tree::height(node *t)
{
 int lh,rh;
 if(t==NULL)
 return 0;
 if(t->left==NULL)
 lh=0;
 else
 lh=1+t->left->ht;
 if(t->right==NULL)
 rh=0;
 else
 rh=1+t->right->ht;
 if(lh>rh)
 return lh;
 else
 return rh;
}
node * tree::rotateright(node *t)
{
 node *p,*q;
 cout<<"\nRight shifted at "<<t->key;
 p=t->left;
 q=p->right;
 p->right=t; // now p becomes root
 t->left=q;
 // store height also
 t->ht=height(t);
 p->ht=height(p);
 return(p);
}
node * tree::rotateleft(node *t)
{
 node *p,*q;
 cout<<"\nLeft shifted at "<<t->key;
 p=t->right;
 q=p->left;
 p->left=t; // now p becomes root
 t->right=q;
 // store height also
 t->ht=height(t);
 p->ht=height(p);
 return(p);
}
node * tree::RR(node *t)
{
 t=rotateleft(t);
 return(t);
}
node * tree::LL(node *t)
{
 t=rotateright(t);
 return(t);
}
node * tree::LR(node *t)
{
 t->left=rotateleft(t->left);
 t=rotateright(t);
 return(t);
}
node * tree::RL(node *t)
{
 t->right=rotateright(t->right);
 t=rotateleft(t);
 return(t);
}
int tree::bfactor(node *t)
{
 int lh,rh;
 if(t==NULL)
 return 0;
 if(t->left==NULL)
 lh=0;
 else
 lh=1+t->left->ht;
 if(t->right==NULL)
 rh=0;
 else
 rh=1+t->right->ht;
 return lh-rh;
}
void tree::preorder(node *t)
{
 if(t!=NULL)
 {
 cout<<"\n"<<t->key<<"(bfactor="<<bfactor(t)<<")";
 preorder(t->left);
 preorder(t->right);
 }
}
void tree::inorder(node *t)
{
 if(t!=NULL)
 {
 inorder(t->left);
 cout<<"\n"<<t->key<<"(bfactor="<<bfactor(t)<<")";
 inorder(t->right);
 }
}
int main()
{
 //clrscr();
 tree t;
 node *newnd;
 char k[20],m[30];
 fstream f;
 int x,n,i,choice;
 while(1)
 {
 choice=menu();
 switch(choice)
 {
 case 1: cout<<"\nHow many words\t";
 cin>>n;
 f.open("dict.txt",ios::out);
 cout<<"\nEnter word and its meaning\n";
 for(i=0;i<n;i++)
 {
 cout<<"\n\t"<<i+1<<"\t";
 cin>>k>>m;
 //write into file
 f<<k<<"\t"<<m<<"\n";
 }
 f.close();
 break;
 case 2: //read from file
 f.open("dict.txt",ios::in);
 while(!f.eof())
 {
 f>>k>>m;
 newnd=new node(k,m);
 t.insert(newnd);
 }
 f.close();
 break;
 case 3: cout<<"\nPreorder sequence :\n";
 t.preorder();
 cout<<"\nInorder sequence :\n";
 t.inorder();
 break;
 case 4: cout <<"\nProgram ending....:\n";
 exit(1);
 //getch();
 //return;
 default: cout <<"\nEnter correct choice...:\n";
 }//switch
 }//while
 return 0;
}//main



#include<iostream>
using namespace std;

int flag2 = 0, flag3 = 0, cmp = 0;

struct AVLNode{
    string word, meaning;
    AVLNode* left;
    AVLNode* right;
};
AVLNode* tree1;

AVLNode* GetNewNode(AVLNode* new_node){
    AVLNode* newNode = new AVLNode();
    newNode->word = new_node->word;
    newNode->meaning = new_node->meaning;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int FindHeight(AVLNode* root){
    if(root == NULL){
        return -1;
    }
    int leftHeight = FindHeight(root->left);
    int rightHeight = FindHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int getBalanceFactor(AVLNode* root){
    if(root == NULL) return -1;
    else{
        return(FindHeight(root->left) - FindHeight(root->right));
    }
}

AVLNode* rightRotate(AVLNode* current_root){
    AVLNode* new_root = current_root->left;
    AVLNode* T2 = new_root->right;

    //Perform rotation
    new_root->right = current_root;
    current_root->left = T2;

    return new_root;
}

AVLNode* leftRotate(AVLNode* current_root){
    AVLNode* new_root = current_root->right;
    AVLNode* T2 = new_root->left;

    //Perform rotation
    new_root->left = current_root;
    current_root->right = T2;

    return new_root;
}

AVLNode* insertRecursive(AVLNode* root, AVLNode* new_node){
    if(root == NULL){   //empty tree
        root = GetNewNode(new_node);
        return root;
    } 
    else if(new_node->word < root->word){
        root->left = insertRecursive(root->left, new_node);
    }
    else if(new_node->word > root->word){
        root->right = insertRecursive(root->right, new_node);
    }
    else{
        cout<<"*** No duplicates allowed! ***"<<endl;
        return root;
    }

    //AVL operations begin

    int bf = getBalanceFactor(root);
    if(bf > 1 && new_node->word < root->left->word){  //LL imbalance
        return rightRotate(root);
    }
    else if(bf < -1 && new_node->word > root->right->word){   //RR imbalance
        return leftRotate(root);
    }
    else if(bf > 1 && new_node->word > root->left->word){ //LR imbalance
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    else if(bf < -1 && new_node->word < root->right->word){   //RL imbalance
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    else{
        return root;
    } 
}

AVLNode* insert(AVLNode* root)
{
	   AVLNode* new_node = new AVLNode();
	   cout<<"\nEnter keyword:";
	   cin>>new_node->word;
	   cout<<"Enter the meaning of the keyword:";
	   cin.ignore();
	   getline(cin, new_node->meaning);
	   insertRecursive(root, new_node);
}


AVLNode* FindMinRecursive(AVLNode* root){
    if(root == NULL){
        cout<<"BST is empty!\n";
        return NULL;
    }
    else if(root->left == NULL){
        return root;
    }
    return FindMinRecursive(root->left);
}

AVLNode* deleteNode(AVLNode* root, string toDelete){
    if(root == NULL) return root;

    else if(toDelete < root->word){     //Target word in left subtree
        root->left = deleteNode(root->left, toDelete);
    }
    else if(toDelete > root->word){     //Target word in right subtree
        root->right = deleteNode(root->right, toDelete);
    }
    else{   //Target word found

        //Case 1: No child(Leaf node)
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }

        //Case 2:- 
        //One child(right child)
        else if(root->left == NULL){
            AVLNode* temp = root;
            root = root->right;
            delete temp;
        }
        //One child(left child)
        else if(root->right == NULL){
            AVLNode* temp = root;
            root = root->left;
            delete temp;
        }

        //Case 3: Two children
        else {
            AVLNode* temp = FindMinRecursive(root->right);
            root->word = temp->word;
            root->right = deleteNode(root->right, temp->word);
        }
    }

    int bf = getBalanceFactor(root);
    if(bf == 2 && getBalanceFactor(root->left) >= 0){
        return rightRotate(root);
    }
    else if(bf == 2 && getBalanceFactor(root->left) == -1){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    else if(bf == -2 && getBalanceFactor(root->right) <= 0){
        return leftRotate(root);
    }
    else if(bf == -2 && getBalanceFactor(root->right) == 1){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

AVLNode* remove(AVLNode* root){
    string toDelete;
    cout<<"Enter word to be deleted: ";
    cin>>toDelete;

    return deleteNode(root, toDelete);
}

void ascendingDisplay(AVLNode* tree)    //inorder traversal
{
    if(tree->left==NULL&&tree->right==NULL)
    {	
    	cout<<tree->word<<": "<<tree->meaning<<"\n";
    }
    else
    {
        if(tree->left!=NULL)
        {
        	ascendingDisplay(tree->left);
        }
        cout<<tree->word<<": "<<tree->meaning<<"\n";
        if(tree->right!=NULL)
        {
        	ascendingDisplay(tree->right);
        }
    }
}

void descendingDisplay(AVLNode* tree)
{
    if(tree->left==NULL&&tree->right==NULL)
    {
    	cout<<tree->word<<": "<<tree->meaning<<"\n";
    }
    else
    {
        if(tree->right!=NULL)
        {
        	descendingDisplay(tree->right);
        }
        cout<<tree->word<<": "<<tree->meaning<<"\n";
        if(tree->left!=NULL)
        {
        	descendingDisplay(tree->left);
        }
    }
}

bool Search(AVLNode* root, string data){
    if(root == NULL) return false;
    else if(root->word == data) return true;
    else if(data <= root->word) return Search(root->left, data);
    else return Search(root->right, data);
}

void in_search(AVLNode* root){
    string toSearch;
    cout<<"Enter word to be searched: ";
    cin>>toSearch;
    bool res = Search(root, toSearch);
    if(res)
    {
        cout<<"Word found in dictionary\n\n";
    }
    else
    {
        cout<<"Word not found!\n\n";
    }
}

AVLNode* find(AVLNode* tree, string toFind)
{
	if(tree==NULL)
	{
		cout<<"\nWord not found.\n";
		flag2=1;
		flag3=1;
		cmp=0;
	}
	else
	{   
        //AVLNode* tree1;
		if(tree->word==toFind)
		{
			cmp++;
			cout<<"\nWord found.\n";
			cout<<tree->word<<": "<<tree->meaning<<"\n";
			tree1=tree;
			return tree;
		}
		else if(tree->word>toFind)
		{
			cmp++;
			find(tree->left,toFind);
		}
		else if(tree->word<toFind)
		{
			cmp++;
			find(tree->right,toFind);
		}
	}
	return tree;
}

void in_find(AVLNode* root)
{
	flag2=0,cmp=0;
    string word;
	if(root!=NULL)
	{
		cout<<"\nEnter the keyword to be searched:";
		cin>>word;
    	find(root,word);
    	if(flag2==0)
    	{
			cout<<"Number of comparisons needed: "<<cmp<<"\n";
			cmp=0;
    	}
	}
	else
	{
		cout<<"\nThere are no words in the dictionary.\n";
	}
}

AVLNode* updateMeaning(AVLNode* tree, string toUpdate)
{
	flag3=0;
	find(tree,toUpdate);
	if(flag3==0)
	{
    	cout<<"\nEnter the updated meaning of the keyword:";
    	cin.ignore();
    	getline(cin,tree1->meaning);
    	cout<<"\nThe meaning of '"<<toUpdate<<"' has been updated.\n";
	}
    return tree;
}

void in_update(AVLNode* root)
{   
    string word;
	if(root!=NULL)
	{
		cout<<"\nEnter the keyword to be updated:";
		cin>>word;
    	updateMeaning(root,word);
	}
	else
	{
		cout<<"\nThere are no words in the dictionary.\n";
	}
}


int main(){

    AVLNode* rootPtr;   //Pointer to root node
    rootPtr = NULL; //Initialising an empty BST

    for(int i=0; i<7; i++)
    {
        rootPtr = insert(rootPtr);
    }

    cout<<"\nAscending order of AVL tree:"<<endl;
    ascendingDisplay(rootPtr);
    cout<<endl<<endl;

    cout<<"\nDescending order of AVL tree:"<<endl;
    descendingDisplay(rootPtr);
    cout<<endl<<endl;

    in_find(rootPtr);

    in_update(rootPtr);

    cout<<"Ascending order of AVL tree after updating: "<<endl;
    ascendingDisplay(rootPtr);
    cout<<endl<<endl;

    rootPtr = remove(rootPtr);

    cout<<"Ascending order of AVL tree after deleting: "<<endl;
    ascendingDisplay(rootPtr);
    cout<<endl<<endl;


    return 0;
    
}