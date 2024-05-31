//
// Created by Adamo08 on 31/05/2024.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


// Creating the node of the linked list

struct Node {
    int Data; // Data of the Node
    struct Node *Link; // A link to the next Node
};

/**
 ********************
 * int Data | *Link |
 * ******************
*/



// Function to count the number of Nodes in a Linked List
void countNodes(struct Node *head){
    int count = 0;
    if (head == NULL)
    {
        // Means that the Linked List is Empty
        printf("The Linked List is Empty!");
    }
    // Otherwise
    struct Node *tmp = head;
    while( tmp != NULL ){
        count ++;
        tmp = tmp -> Link;
    }
    printf("Number of Nodes : %d",count);
    cout << endl;
}

// Function to print (show) The Linked List
void showList(struct Node *head)
{
    int j = 1; // A number to assign to the current Node (1,2 ...)
    cout << endl;
    // If the List is Empty
    if (head == NULL){
        printf("The Linked List is Empty!");
    }
    else{
        // Otherwise : we create a temporary pointer that points initialy to the head of the list
        struct Node *tmp = head;
        printf("The Nodes Of The Linked List : ");
        cout << endl;
        while ( tmp != NULL)
        {
            printf("\tNode %d --> Data : %d\n",j,tmp->Data);
            j++;
            tmp = tmp -> Link;
        }
    }

}

/*
    *
    *  Inserting New Nodes To The Linked List
    *
*/

// Function to add new Nodes to the List (To the end of the list)
void addToList(struct Node *head, int data){
    // We have two cases to check :
    /**
         * 1st Case : if the List is Empty :
            * Then the head of the list becomes the new element to add
            * Then the new element will point the NULL
         * 2nd Case : if the List is Not Empty :
            * In this case , we will create a temporary pointer
            * Then we will move it to the last Node
            * Finaly , we link it to the new Element
    */

    // If the list is Empty :
    if (head == NULL){
        head -> Data = data;
        head -> Link = NULL;
    }
    // Otherwise
    struct Node *tmp, *New;
    tmp = head;
    // Moving Temp to the last Node
    while (tmp->Link != NULL){
        tmp = tmp -> Link;
    }
    New = (struct Node *)malloc(sizeof (struct Node));
    New -> Data = data;
    New -> Link = NULL;

    // Finaly we link the tmp to the new Node
    tmp->Link = New;
}

// Function to insert new Node to the beginning of the Linked List
struct Node* addToStart(struct Node *head, int data){
    struct Node *New;
    New = (struct Node *)malloc(sizeof(struct Node));

    New -> Data = data;
    New -> Link = head;
    // The we update the head to the new element
    head = New;

    // Finaly , we return the head pointer
    return head;
}

// Function to insert a Node in a specific position (pos)
void insertAtPos(struct Node *head, int data, int pos){
    // We are assuming that the position is less than the Length of The Linked List
    // If pos=1 : we insert to the start of the list

    if (pos == 1){
        addToStart(head,data);
    }
    else{
        struct Node *tmp, *New;
        tmp = head;
        New = (struct Node *)malloc(sizeof(struct Node));
        New -> Data = data;
        New -> Link = NULL;

        // Moving tmp the element at position (pos-1)
        int j=1;
        while (j != pos-1){
            tmp = tmp -> Link;
            j++;
        }

        // Then we Link tmp to the new element ,
        // and the new element to the element at position = pos
        New -> Link = tmp -> Link;
        tmp -> Link = New;
    }
}


/*
    *  Deleting Nodes From The Linked List
*/

// Function to delete a Node from the start (Head)
struct Node* removeHead(struct Node *head)
{
    // If the Linked List is Empty :
    if ( head == NULL ){
        cout << endl;
        printf("The Linked List is Empty!");
        cout << endl;
    }
    // Otherwise :
    struct Node *tmp = head;
    // We update the head
    head = head -> Link;
    free(tmp);
    tmp = NULL;

    // Finaly , we return the New Head
    return head;
}


// Function to delete a Node from the end (Queue)
void removeEnd(struct Node *head)
    {
        /*
             *
             * We will create 2 ptrs , pointing both to the head of the list
             * Then they'll be moved so that one of them points to the last Node
             * And the second will point to the second last Node
             *
             *------------------------------------------------------------------------*
             | Head | -> | ... | -> | .... | ........ -> | tmp2 | -> | tmp1 | -> NULL |
             *------------------------------------------------------------------------*
             *
             * Then tmp2 -> Link = NULL
             * free(tmp1)
             * tmp1 = NULL;
             *
             * Note :
             *      We can use just one pointer (tmp) to performe the same task (tmp points to the second last Node)
             *      free(tmp -> Link)
             *      tmp -> Link = NULL
             *
        */

        // If The Linked List Is Empty
        if (head == NULL)
            {
                cout << endl;
                printf("The Linked List Is Empty!");
                cout << endl;
            }
        // If The List Contains one single Node (Head)
        else if (head -> Link == NULL)
            {

                free(head);
                head = NULL;

            }
        // Otherwise
        else
            {
                struct Node *tmp1 = head;
                struct Node *tmp2 = head;

                // Moving tmp1 to the end and tmp2 to the second last Node
                while( tmp1 -> Link != NULL)
                    {
                        tmp2 = tmp1;
                        tmp1 = tmp1 -> Link;
                    }
                tmp2 -> Link = NULL;
                free(tmp1);
                tmp1 = NULL;
            }

    }


// Function to delete a Node from the a given position (pos)
void removeFromPos(struct Node ** head, int pos)
    {
        /*
             * Suppose that the given position is less than the length of the linked list
             * pos <= Length(Linked List)
             * We will create two ptrs one will point to the Node to delete
             * And an other an other ptr will point to the positin right before the Node to delete
             *
             *-----------------------------------------------------------------*
             | Head | -> | ... | -> | tmp2 | -> | tmp1 | -> | ..... | -> NULL  |
             *-----------------------------------------------------------------*
             *
             * Then tmp2 -> Link = tmp1 -> Link
             * tmp1 -> Link = NULL
             * free(tmp1)
             * tmp1 = NULL
        */

        struct Node *current = *head;
        struct Node *previous = *head;


        // If The Linked List Is Empty
        if (*head == NULL)
            {
                printf("The Linked List is Empty!");
                return;
            }
        else if (pos == 1)
            {
                *head = current -> Link;
                free(current);
                current = NULL;
            }
        else
            {

                while (pos != 1)
                    {
                        previous = current;
                        current = current -> Link;
                        pos --;
                    }
                previous -> Link = current -> Link;
                free(current);
                current = NULL;
            }


    }


// Function to delete the entire Linked List
struct Node* deleteList(struct Node *head){
    struct Node *tmp = head;

    // If the List is Empty
    while (tmp != NULL)
        {
            tmp = tmp->Link;
            free(head);
            head = tmp;
        }
    return head;
}


int main() {

    struct Node *Head = NULL;
    Head = (struct Node *) malloc(sizeof (struct Node));
    Head -> Data = 45;
    Head -> Link = NULL;

    /*
         *******************
         | 45    | -> NULL |
         *******************
    */

    addToList(Head,15);
    addToList(Head,55);
    addToList(Head,5);




    // Counting the number of Nodes in the linked list
    countNodes(Head);

    // Printing th Linked List
    showList(Head);

    /*
         **********************************************************
         | 45    | -> | 15    | -> | 55    | -> | 5    | -> NULL  |
         **********************************************************
     */

    // Adding 44 to the start of the Linked List
    Head = addToStart(Head,44);


    // Adding 56 to the start of the Linked List
    Head = addToStart(Head,56);

    countNodes(Head); // 4+2 = 6
    showList(Head);

    /*
         ************************************************************************************
         | 56    | -> | 44    | -> | 45    | -> | 15    | -> | 55    | -> | 5    | -> NULL  |
         ************************************************************************************
     */

    // Inserting 0 at pos 3
    insertAtPos(Head,0,3);
    countNodes(Head); // 6+1 = 7
    showList(Head);

    /*
         ************************************************************************************************
         | 56    | -> | 44    | -> | 0    | -> | 45    | -> | 15    | -> | 55    | -> | 5    | -> NULL  |
         ************************************************************************************************
     */

    // Removing the First Node
    Head = removeHead(Head);
    countNodes(Head); // 7-1 = 6
    showList(Head);

    /*
         **********************************************************************************
         | 44    | -> | 0   | -> | 45    | -> | 15    | -> | 55    | -> | 5    | -> NULL  |
         **********************************************************************************
     */

    // Removing the Las Node of The Linked List
    removeEnd(Head);
    countNodes(Head); // 6-1 = 5
    showList(Head);

    /*
         **********************************************************************
         | 44    | -> | 0   | -> | 45    | -> | 15    | -> | 55    | -> NULL  |
         **********************************************************************
     */


    // Removing the Node At 3rd position
    removeFromPos(&Head,3);
    countNodes(Head); // 5-1 = 5
    showList(Head);

    /*
         **********************************************
         | 44    | -> | 45    | -> | 55    | -> NULL  |
         **********************************************
     */



    // Deleting the entire Linked List
    Head = deleteList(Head);
    showList(Head);





    return 0;
}
