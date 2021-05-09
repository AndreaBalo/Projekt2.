#include "hajokirandulas.h"
Node *create() //helyetfoglal egy agnak
{
    Node *ag;
    ag = (Node *)(malloc(sizeof(Node)));
    if(!ag)
    {
        printf("Sikertelen lefoglalas");
        return 0;
    }
    ag->left=NULL;
    ag->right=NULL;
    return ag;
}
Person *createPerson()
{
    Person *persons;
    persons=(Person*)malloc(sizeof (Person));
    return persons;
}
Person *insertPerson(Person * persons,const char *firstname,const char* lastname,int counter,int szemelyszam)
{
    if(counter!=0)
    {
        persons= (Person *) realloc(persons, counter * sizeof(Person));
    }
    persons[counter].firstName=(char *) malloc((strlen(firstname) + 1) * sizeof(char));
    persons[counter].lastName=(char *) malloc((strlen(lastname) + 1) * sizeof(char));
    strcpy(persons[counter].lastName,lastname);
    strcpy(persons[counter].firstName,firstname);
    persons[counter].ID=counter;
    persons[counter].szemelyekSzama=szemelyszam;

}
void insert(Node ** root,Date date,int ID) //beszur egy datumot
{
    if((*root) == NULL)
    {
        (*root) = create();
        (*root)->date.year=date.year;
        (*root)->date.month=date.month;
        (*root)->date.day=date.day;
        (*root)->ID=ID;

    }
    else
    {
        if(compareDate((*root)->date,date)==1)
            insert(&((*root)->left),date,ID);
        else if(compareDate((*root)->date,date)==-1)
        {insert(&((*root)->right),date,ID);}
    }
}
void inorder(Node *root) //kiirja sorrendben a datumokat
{
    if(root->left)
        inorder(root->left);
    printf("%4i%4i%4i%4i\n", root->date.year,root->date.month,root->date.day,root->ID);
    if(root->right)
        inorder(root->right);
}
int compareDate(Date date1,Date date2)//osszehasonlit 2 datumot
{
    if(date1.year>date2.year)
    {
        return 1;
    }
    if(date1.year<date2.year)
    {
        return -1;
    }
    if(date1.month>date2.month)
    {
        return  1;
    }
    if(date2.month>date1.month)
    {
        return -1;
    }
    if(date1.day>date2.day)
    {
        return 1;
    }
    if(date1.day<date2.day)
    {
        return -1;
    }
    return 0;
}
bool search(Node *root,Date date)//megkeres egy adott datumot es visszateriti hogy letezik a faban vagy sem
{
    if (root == NULL) {
        return false;
    } else if (compareDate(date, root->date) == -1) {
        search(root->left, date);
    } else if (compareDate(date, root->date) == 1) {
        search(root->right, date);
    } else {
        return true;
    }
}
int returnID(Node *root,Date date)
{
    if(root==NULL)
    {
        return -1;
    }
    else if(compareDate(date,root->date)==-1)
    {
        search(root->left,date);
    } else if(compareDate(date,root->date)==1)
    {
        search(root->right,date);
    }
    else {
        return root->ID;
    }
}
Node* deleteNode( Node* root, Date key)//torol egy adott datumot a fabol
{
    if (root == NULL)
        return root;
    if (compareDate(root->date,key)==1)
        root->left = deleteNode(root->left, key);
    else     if (compareDate(root->date,key)==-1)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            Node* p = root->right;
            free(root);
            return p;
        }
        else if (root->right == NULL) {
            Node * p = root->left;
            free(root);
            return p;
        }
        Node* p = minValueNode(root->right);
        root->date.year = p->date.year;
        root->date.month=p->date.month;
        root->date.day=p->date.day;
        root->ID=p->ID;

        root->right = deleteNode(root->right, p->date);
    }
    return root;
}
Node * minValueNode(Node * node)//megkeresi a legkisebb datumot
{
    Node * current = node;
    while (current->left != NULL)
        current = current->left;

    return current;
}
bool isValidDate(int year,int month,int day)//ellenorzi egy datum valossagat
{
    if(year<2021 || month<1 || month>12 || day<1 || day>31)
        return false;
    if (month == 2) {
        return day <= (leapYear(year) ? 29 : 28);
    }
    return day <= ((month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31);
}
int leapYear(int year)//ellenorzi hogy egy ev szokoev vagy sem
{
    if(year%4==0 &&(year%100!=0 || year %400==0))
        return 1;
    else return 0;
}
Date formatToDate(int year,int month,int day)// atalakit Date tipussa egy datumot
{
    Date date;
    date.day=day;
    date.month=month;
    date.year=year;
    return date;
}
