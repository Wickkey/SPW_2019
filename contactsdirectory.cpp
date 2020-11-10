#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void Insert();



class BstNode{
public:
    string name;
    vector <long int> phoneno1;
    //long int phoneno2;
    //long int phoneno3;
    BstNode *left;
    BstNode *right;

BstNode(string phname,long int arr)
{
   name = phname;

   phoneno1.push_back (arr);

  // phoneno2 = NULL;

  // phoneno3 = NULL;

}

/*BstNode(string phname,long int arr1,long int arr2)
{
   name = phname;

   phoneno1 = arr1;

   phoneno2 = arr2;

   phoneno3 = NULL;
}

BstNode(string phname,long int arr1,long int arr2,long int arr3)
{
   name = phname;

   phoneno1 = arr1;

   phoneno2 = arr2;

   phoneno3 = arr3;

} */

};



void inorder(BstNode *root)
{
 if(root)
    {
         inorder(root->left);
         cout<<"contact name : " <<root->name <<"\ncontact number : " <<root->phoneno1[0]<<endl;
         inorder(root->right);
    }
}

BstNode* root = NULL;

BstNode *GetnewNode(string name,long int arr)
{
    BstNode *temp = new BstNode(name,arr);
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

BstNode* Insert(BstNode* root ,string name1 , long int arr)
{
 if(root == NULL)
  { root = GetnewNode(name1,arr);
  return root; }
 else
  {
    if(name1 > root->name)
      root->right = Insert(root->right , name1 ,arr);
    else
      root->left  = Insert(root->left , name1 , arr);

    return root;
  }

}

void menu()
{
 cout<<"Hello, Welcome to telephone directory : \n";
 cout<<"1.create new contact \n2.Search for contact \n3.Edit contact details \n4.Delete contact \n5.Display all contacts: \n ";
}

BstNode* SearchResult(BstNode* root,string phname)
{
if(root)
{
if(root->name == phname)
   return root;

else
  if(phname > root->name )
    return SearchResult(root->right ,phname);

else
  return SearchResult(root->left , phname);
}
else
  {
  root = NULL;
  return root;
  }
}

BstNode *Findmin(BstNode* rr)
{

 if(rr)
    {
         if((rr->left))
            return Findmin(rr->left);

         else
            return rr;

    }
  else return rr;
}

BstNode* Delete(BstNode *root,string phname)
{
    if(root == NULL)
        return root;
    else if(phname < root->name)
        root->left = Delete(root->left,phname);
    else if(phname > root->name)
        root->right = Delete(root->right,phname);

    else
    {
        if(root->left == NULL && root->right == NULL){
            BstNode *temp = root;
            delete root;
            root = NULL;
        }

        else if(root->left == NULL) {
            BstNode *temp = root;
            root = root->right;
            delete temp;
        }

        else if(root->right == NULL) {
            BstNode *temp = root;
            root = root->left;
            delete temp;
        }

        else{
            BstNode *temp = Findmin(root->right);
            root->phoneno1[0] = temp->phoneno1[0];
            root->name = temp->name;
            root->right = Delete(root->right,temp->name);
        }

    } return root;

}


void display()
{
char rep = 'y';
   while(rep=='y')
   {
    menu();
	int choice;
	cin>>choice;
	switch(choice)
	{
	 case 1:
	         {
	         int num;
	         cout<<"how many contacts do you want to create :" ;
	         cin>>num;
	         while(num--)
	            {
	            Insert();
	            }
	         }
	         break;

	 case 2:
           {
	       cout<<"do you want to search by \na)name \n \tor \nb)search by number : ";
	       char c;
	       cin>>c;
	       switch(c)
	          {
                case 'a':
                       {
                        string phname;
                        cout<<"enter name of contact person to be searched : ";
                        cin>>phname;
                  		BstNode* Result = SearchResult(root,phname);
                  		if(Result)
                  		  {
                  		  cout<<"Success : \nContact name : "<<Result->name<<"\nContact number :"<<Result->phoneno1[0]<<endl;
                  		  }
                  		else
                  		  cout<<"No contact found :\n";
                  		break;
                       }

                  //type case b:
               default:
                  cout<<"Invalid input : "<<endl;
	          }
	         }
	          break;

	 case 3:
	     {
	       cout<<"enter name of the person ";
	       string phname;
	       cin>>phname;
	       BstNode* Result = SearchResult(root,phname);
	       if(Result)
	         {
	         cout<<"Existing details : \nContact name: "<<Result->name<<"\nContact name: "<<Result->phoneno1[0]<<endl;
	         cout<<"Rewrite a)name\n\tb)phone number\n\tc)both\n ";
	         char c;
	         cin>>c;
	         	switch(c)
	         	 {
	         	   case 'b':
	         	      cout<<"Enter new number :";
	         	      cin>>Result->phoneno1[0];
	         	      cout<<"Sucess \n";
	         	      break;
	         	   case 'c':
	         	      Insert();
	         	      break;
	         	   default:
	         	     cout<<"Invalid input";

	         	 }
	         }
	         else
                  cout<<"No contact found :\n";
 	     }
 	     break;

 	 case 4:
 	      {
 	      string phname;
 	      cout<<"enter name of the contact to be deleted :";
 	      cin>>phname;
            //BstNode * temp = SearchResult(root,phname);
            //BstNode * temp1 = Findmin(temp);
            //cout<<"right subtree min name : " <<temp1->name;
 	        root = Delete(root,phname);
 	        cout<<root->name;
 	      cout<<"Do you wish to view all contacts ?(y/n) ";
 	      char c;
 	      cin>>c;
 	      if(c=='y')
 	        inorder(root);
 	      }
 	      break;
	 case 5:
	        inorder(root);
	        break;
	 default :cout<<"Invalid Output : \n ";

	}
	cout<<"do you wish to continue :\n";
	cin>>rep;
 	}
}

void Insert()
{
 string phname;
 long int phno;
 cout<<"enter name :\n";
 cin>>phname;
 cout<<"enter phone number :\n";
 cin>>phno;
 root = Insert(root , phname , phno );
 cout<<"success : \n";
}

int main()
{


display();
 /*root = Insert(root ,"Vignesh",1212414);
 root = Insert(root ,"kaj;kldjfaf",1231321);
 root = Insert(root ,"jkfjkfj",23424);
 cout<<"success "; */




    return 0;
}
