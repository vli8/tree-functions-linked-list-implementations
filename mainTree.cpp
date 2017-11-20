#include "ItemType.h"
#include "TreeType.h"



int main(){

    TreeType firstTree, secondTree;
    TreeNode node;

    ItemType x,y;
    x.Initialize('F');
    firstTree.InsertItem(x);
    if (firstTree.IsEmpty() == false)
       cout<<"the first item is inserted"<<endl;

    cout<<"After inserting the first item "<<x<<" into the tree"<<endl;
    firstTree.Print();

     x.Initialize('A');
    firstTree.InsertItem(x);
    x.Initialize('C');
    firstTree.InsertItem(x);
    x.Initialize('B');
    firstTree.InsertItem(x);
    x.Initialize('E');
    firstTree.InsertItem(x);

    y.Initialize('R');
    secondTree.InsertItem(y);
    y.Initialize('F');
    secondTree.InsertItem(y);
    y.Initialize('G');
    secondTree.InsertItem(y);
    y.Initialize('K');
    secondTree.InsertItem(y);

    cout<<"After inserting five items into the tree"<<endl;
    firstTree.Print();

    int count = firstTree.GetLength();
    cout<<"The tree has "<<count<<"  elements"<<endl;

    if (count !=0)
    {
        cout<<"Show the tree in Post_order"<<endl;
        firstTree.ResetTree(POST_ORDER);
        bool finished = false;

        while(finished == false)
       {
         ItemType thisItem;
         firstTree.GetNextItem(thisItem, POST_ORDER, finished);
         cout<<thisItem<<"  ";
       }
       cout<<endl;

        cout << "Leaf Count is : " << firstTree.LeafCount() << endl;
        cout << "Second tree is: " << endl;
        secondTree.Print();
        cout << "The ancestors of letter " << y << " are: ";
        secondTree.Ancestors(y);
        firstTree.Swap(secondTree);
        firstTree.Print();
        secondTree.Print();

        cout<<"Show the tree in Pre_order"<<endl;
        firstTree.ResetTree(PRE_ORDER);
        finished = false;
        while(finished == false)
        {

         ItemType thisItem;
         firstTree.GetNextItem(thisItem, PRE_ORDER, finished);
         cout<<thisItem<<"  ";
        }
        cout<<endl;

        cout<<"Delete an item : "<<x<<endl;

        bool find = false;
        firstTree.RetrieveItem(x,find);
        if ( find == true)
            firstTree.DeleteItem(x);

        cout<<"After deleting "<<x<<" from the tree"<<endl;
        count = firstTree.GetLength();
        cout<<"The tree has "<<count<<" elements"<<endl;

        firstTree.Print();
    }

    firstTree.MakeEmpty();
    cout<<"After empty the tree"<<endl;
    firstTree.Print();

    return 0;
}
