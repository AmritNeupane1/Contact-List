#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    char number[50];
    char gmail[40];
    char name[30];
    Node *prev, *next;
    Node(char n[], char r[], char g[])
    {
        strcpy(name, n);
        strcpy(number, r);
        strcpy(gmail, g);
        next = NULL;
        prev = NULL;
    }

};
class contacts
{
    Node *head, *temp, *ptr;

    Node *ptr1, *ptr2, *dup;

public:
    Node *prevn;

    void insert();
    void sort();
    void deletecontact(char n[20]);
    void deletesamenumber();
    void deletesamename();
    void deletesamegmail();
    void searchbyname(char p[20]);
    void searchbynumber(char no[30]);
    void searchbygmail(char g[20]);
//    void saveentry(); 

   
    void accept();
    void display();
    void update(char ch[10]);
    contacts()
    {
        head = NULL;
        temp = NULL;
        ptr = NULL;
        ptr1 = NULL;
        ptr2 = NULL;
        dup = NULL;
    }
};

void contacts::accept()
{
    char number[50];
    char gmail[40];
    char name[30];
    char ans;
    do
    {
        cout << "ENTER NAME      :";
        cin >> name;
     
        cout << "ENTER NUMBER    :";
        cin >> number;
        while (strlen(number) != 10)
        {
            cout << "ENTER VALID NUMBER  :";
            cin >> number;
        }
        cout << "ENTER G-MAIL    :";
        cin >> gmail;
        temp = new Node(name, number, gmail);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->prev = ptr;
        }
        cout << "DO YOU WANT TO CONTINUE?????????";
        cin >> ans;
    } while (ans == 'y');
}
void contacts::display()
{
    ptr = head;         // start the node
    while (ptr != NULL) // traverse till last
    {
        cout << "\n\nNAME  ::\t" << ptr->name;
        cout << "\nNUMBER::\t+91-" << ptr->number;
        cout << "\nG-MAIL::\t" << ptr->gmail<<endl;
        ptr = ptr->next;
    }
}

void contacts::insert()
{
    accept();
}
void contacts::sort()
{
    Node *i, *j;
    int temp;
 
    char n[10];
    for (i = head; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            temp = strcmp(i->name, j->name);
           
            if (temp > 0)
            {
                strcpy(n, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, n);
                strcpy(n, i->gmail);
                strcpy(i->gmail, j->gmail);
                strcpy(j->gmail, n);
                strcpy(n, i->number);
                strcpy(i->number, j->number);
                strcpy(j->number, n);
            }
        }
    }
}
void contacts::deletecontact(char s[20])
{
    int c = 0;
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(s, ptr->name) == 0)
        {
            c = 1;
            break;
        }
        else
        {
            c = 2;
        }
        ptr = ptr->next;
    }
    if (c == 1 && ptr != head && ptr->next != NULL)
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete (ptr);
        cout << "YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
    }
    if (ptr == head)
    {
        head = head->next;
        head->prev = NULL;
        delete (ptr);
        cout << "YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
    }
    if (ptr->next == NULL)
    {
        ptr->prev->next = NULL;
        ptr->prev = NULL;
        delete (ptr);
        cout << "YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
    }
    if (c == 2)
    {
        cout << "YOUR ENTERED NAME IS NOT IN THE LIST...";
    }
}
void contacts::deletesamename()
{
    ptr1 = head;
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (strcmp(ptr1->name, ptr2->next->name) == 0)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}
void contacts::deletesamegmail()
{
    ptr1 = head;
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (strcmp(ptr1->gmail, ptr2->next->gmail) == 0)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}
void contacts::deletesamenumber()
{
    ptr1 = head;
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (strcmp(ptr1->number, ptr2->number) == 0)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}
void contacts::searchbyname(char na[10])
{
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(na, ptr->name) == 0)
        {
            cout << "NAME FOUND" << endl;
            cout << "CONTACT DETAILS ARE BELOW:\n"
                 << endl;
            cout << "\n\nNAME  ::\t" << ptr->name;
            cout << "\nNUMBER::\t+91-" << ptr->number;
            cout << "\nG-MAIL::\t" << ptr->gmail<<endl;
        }
        ptr = ptr->next;
    }
}
void contacts::searchbynumber(char num[20])
{
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(num, ptr->number) == 0)
        {
            cout << "NUMBER FOUND\n"
                 << endl;
            cout << "CONTACT DETAILS ARE BELOW:\n"
                 << endl;
            cout << "\n\nNAME  ::\t" << ptr->name;
            cout << "\nNUMBER::\t+91-" << ptr->number;
            cout << "\nG-MAIL::\t" << ptr->gmail<<endl;
        }
        ptr = ptr->next;
    }
}
void contacts::searchbygmail(char gm[20])
{
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(gm, ptr->gmail) == 0)
        {
            cout << "G-MAIL FOUND\n"
                 << endl;
            cout << "CONTACT DETAILS ARE BELOW:\n"
                 << endl;
            cout << "\n\nNAME  ::\t" << ptr->name;
            cout << "\nNUMBER::\t+91-" << ptr->number;
            cout << "\nG-MAIL::\t" << ptr->gmail<<endl;
        }
        ptr = ptr->next;
    }
}
void contacts::update(char n[20])
{
    char ans;
    int c;
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(n, ptr->name) == 0)
        {

            do
            {
                cout << "\nWHAT DO YOU WANT TO UPDATE?\n1.NAME\n2.PHONE NUMBER\n3.G-MAIL\n";
                cin >> c;
                switch (c)
                {
                case 1:
                    cout << "ENTER NEW-NAME=";
                    cin >> ptr->name;
                    break;
                case 2:
                    cout << "ENTER NEW PHONE-NUMBER?";
                    cin >> ptr->number;
                    while (strlen(ptr->number) != 10)
                    {
                        cout << "ENTER VALID NUMBER  :";
                        cin >> ptr->number;
                    }
                    break;
                case 3:
                    cout << "ENTER NEW G-MAIL";
                    cin >> ptr->gmail;
                    break;
                }
                cout << "DO YOU WANT TO CONTINUE UPDATING?   (y/n)\n";
                cin >> ans;
            } while (ans == 'y');
        }
        ptr = ptr->next;
    }
}
int main()
{
     char n[20];
    // char nam[20];
    char name[10];
    char number[10];
    char gmail[20];
    contacts d1;
    // apply d;
    char ans;
    int ch, a;
    cout << "**************                                CONTACT LIST                        ********************";
    cout << "\n\nWHAT IS YOUR NAME?\n";
    cin.getline(name, 20);
    cout << "\n\n!!!!!!!!!!!!!!!!!!!!!!!   WELCOME " << name << "   !!!!!!!!!!!!!!!!!!!!!";
    cout << "\n\n\nLET'S CREATE OUR CONTACT LIST " << name << "  \n\n";
    d1.accept();
    d1.sort();
    do
    {
        cout << "\n\n\n\n1) DISPLAY YOUR CONTACT LIST\n2) INSERT NEW CONTACT\n3) UPDATE DETAILS ON EXISTING CONTACT\n4) DELETE CONTACT\n5) DELETE SAME NAME IN CONTACT LIST\n6) DELETE SAME NUMBERS IN CONTACT LIST\n7) SEARCH\n";
        cin >> ch;
        switch (ch)
        {
        case 2:
            d1.insert();
            d1.sort();
            break;

        case 1:
            // d1.sort();
            d1.display();
            break;
        case 3:

            cout << "\n\nENTER THE NAME OF PERSON WHOSE DETAILS YOU WANT TO UPDATE...\n";
            cin >> n;
            d1.update(n);
            d1.sort();
            break;
        case 4:
            cout << "\nENTER THE NAME YOU WANT TO DELETE FROM CONTACT LIST\n";
            cin >> name;
            d1.deletecontact(name);
            break;
        case 5:
            d1.deletesamename();
            d1.display();
            break;
        case 6:
            d1.deletesamenumber();
            d1.display();
            break;
        case 7:
            do
            {
                cout << "1.SEARCH BY NAME\n2.SEARCH BY NUMBER\n3.SEARCH BY GMAIL\n";
                cin >> a;
                switch (a)
                {
                case 1:
                    cout << "ENTER THE NAME TO BE SEARCHED\n";
                    cin >> name;
                    d1.searchbyname(name);
                    break;
                case 2:
                    cout << "ENTER THE NUMBER TO BE SEARCHED\n";
                    cin >> number;
                    d1.searchbynumber(number);
                    break;
                case 3:
                    cout << "ENTER THE GMAIL TO BE SEARCHED\n";
                    cin >> gmail;
                    d1.searchbygmail(gmail);
                    break;
                default:
                    cout << "\nNO PROPER INPUT GIVEN.....\n";
                }
                cout << "DO YOU WANT TO CONTINUE SEARCHING?? (y/n)\n";
                cin >> ans;
            } while (ans == 'y');

            break;
    
        default:
            cout << "\nNO PROPER INPUT GIVEN..\n";
        }
        cout << "\n\nDO YOU WANT TO CONTINUE OPERATIONS?? (y/n)\n";
        cin >> ans;
    } while (ans == 'y');
}


