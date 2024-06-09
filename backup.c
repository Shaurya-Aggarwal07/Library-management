//-------------------------------INCLUDING HEADER FILES--------------------------------------

#include <stdio.h>
#include <stdlib.h>

#include <string.h>  //strcmp

#include <time.h>    //time access


#include <windows.h> // SetConsoleCursorPosition

#include <dos.h>    // sleep and date

#include <conio.h>   // encryption getch

#include <ctype.h>   // for characters

//-------------------------------DEFINE COLOR CODE CONSOLE OUTPUT----------------------------

#define red "\033[1;31m"
#define green "\033[1;32m"
#define yellow "\033[1;33m"
#define blue "\033[1;34m"
#define megenta "\033[1;35m"
#define cyan "\033[1;36m"
#define white "\033[1;37m"
#define reset "\033[0m\n"
#define bold "\033[1m"
#define italic "\033[3m"

//----------------------------------DECLARING FUNCTIONS--------------------------------------

char catagories[][15] = {"Computer", "Electronics", "Maths", "Biology", "Mechanics", "Physics"};
void returnfunc(void);

void mainmenu(void);
void addbooks(void);
void deletebooks(void);
void editbooks(void);
void searchbooks(void);
void issuebooks(void);
void viewbooks(void);
void credits(void);
void bookmenu(void);
void closeapp();
int  getdata();
int  checkid(int);
void searchissue2(char);
void searchissue1(void);

void Password();
void issuerecord();
void lineanim(int x);
void wanim();

//---------------------------------GLOBAL FILES AND VARIABLES-------------------------

#define RETURNTIME 15

// list of global files
FILE *fp, *ft, *fs;

COORD coord = {0, 0};

// list of global variable
int s;
char findbook;
char password[10] = {"group1"};

//----------------------------------MAKING STRUCTURES-----------------------------

void gotoxy(int x, int y)
{ 
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct Date
{
    int mm, dd, yy;
};

struct books
{
    int id;
    char stname[20];
    char name[20];
    char Author[20];
    int quantity;
    float Price;
    int count;
    int rackno;
    char *cat;
    struct Date issued;
    struct Date duedate;
};
struct books a;

//-----------------------------------MAIN FUNCTION--------------------------------

int main()
{
    Password();
    getch();
    return 0;
}

//---------------------------------MAIN MENU FUNCTION------------------------------------

void mainmenu()
{
    system("cls");
    int i;
    //----------------------------DISPLAYING MAIN MENU-------------------------

    gotoxy(20, 3);
    printf(blue"\xB2\xB2\xB2\xB2\xB2\xB2 LIBRARY MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2"reset);
    
    gotoxy(20, 5);
    printf("\xB2\xB2\xB2\xB2\ 1=> Add Books");
    gotoxy(20, 7);
    printf("\xB2\xB2\xB2\xB2\ 2=> Delete Books");
    gotoxy(20, 9);
    printf("\xB2\xB2\xB2\xB2\ 3=> Search Books");
    gotoxy(20, 11);
    printf("\xB2\xB2\xB2\xB2\ 4=> Book Issue");
    gotoxy(20, 13);
    printf("\xB2\xB2\xB2\xB2\ 5=> View Books List");
    gotoxy(20, 15);
    printf("\xB2\xB2\xB2\xB2\ 6=> Edit Book's Record");
    gotoxy(20, 17);
    printf("\xB2\xB2\xB2\xB2\ 7=> View Credits");
    gotoxy(20, 19);
    printf("\xB2\xB2\xB2\xB2\ 8=> Close Application"reset);
    gotoxy(20, 21);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20, 22);
    //-------------------------------TAKING USER CHOICE---------------------------

    gotoxy(20, 21);
    printf(cyan"Enter your choice:"reset);

    switch (getch())
    {
    case '1':
        addbooks();
        break;

    case '2':
        deletebooks();
        break;

    case '3':
        searchbooks();
        break;

    case '4':
        issuebooks();
        break;

    case '5':
        viewbooks();
        break;

    case '6':
        editbooks();
        break;

    case '7':
        credits();
        break;

    case '8':
        closeapp();
        break;

    default:
    {
        gotoxy(10, 23);
        printf("Wrong Entry !! Please re-enter correct option:");
        if (getch())
            mainmenu();
    }
    }
}
//-------------------------------Funtion that Add Books-----------------------------------
void addbooks(void)
{
    system("cls");
    int i;
    gotoxy(20, 3);
    printf(yellow"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT CATEGORIES\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"reset);
    gotoxy(20, 5);
    printf("\xB2\xB2\xB2\xB2\ 1=> Computer");
    gotoxy(20, 7);
    printf("\xB2\xB2\xB2\xB2\ 2=> Electronics");
    gotoxy(20, 9);
    printf("\xB2\xB2\xB2\xB2\ 3=> Maths");
    gotoxy(20, 11);
    printf("\xB2\xB2\xB2\xB2\ 4=> Biology");
    gotoxy(20, 13);
    printf("\xB2\xB2\xB2\xB2\ 5=> Mechanics");
    gotoxy(20, 15);
    printf("\xB2\xB2\xB2\xB2\ 6=> Physics");
    gotoxy(20, 17);
    printf("\xB2\xB2\xB2\xB2\ 7=> Back to main menu");
    gotoxy(20, 19);
    printf(yellow"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"reset);

    gotoxy(20, 21);
    printf(megenta"Enter your choice:"reset);
    scanf("%d", &s);

    if (s == 7)
        mainmenu();

    system("cls");
    fp = fopen("lib.txt", "ab+");

    if (getdata() == 1)
    {
        a.cat = catagories[s - 1];
        fseek(fp, 0, SEEK_END);     //to take the pointer on specific location
        fwrite(&a, sizeof(a), 1, fp);    //to write the data from structure to filr 

        fclose(fp);            
        gotoxy(21, 14);
        printf(green"The Record Is Sucessfully Saved"reset);
        gotoxy(21, 15);
        printf(cyan"Do you want to save more?(Y / N):"reset);
        if (getch() == 'n')
            mainmenu();
        else
            system("cls");
        addbooks();
    }
}

//------------------------------------------------------------------------------------
void bookmenu()
{
    int i, j;
    gotoxy(1, 1);
    printf("::::::::::::::::::::::::::::::::Book List:::::::::::::::::::::::::::::::::");
    gotoxy(2, 2);
    printf(megenta" CATEGORY     ID    BOOK NAME     AUTHOR       QTY     PRICE     RackNo "reset);
    j = 4;
    fp = fopen("lib.txt", "rb");   //rb is reading mode only
    while (fread(&a, sizeof(a), 1, fp) == 1)
    {
        gotoxy(3, j);
        printf("%s", a.cat);
        gotoxy(16, j);
        printf("%d", a.id);
        gotoxy(22, j);
        printf("%s", a.name);
        gotoxy(36, j);
        printf("%s", a.Author);
        gotoxy(50, j);
        printf("%d", a.quantity);
        gotoxy(57, j);
        printf("%.2f", a.Price);
        gotoxy(69, j);
        printf("%d", a.rackno);
        printf("\n\n");
        j++;
        i = i + a.quantity;
    }
    fclose(fp);
}

//-----------------------function that delete books from file fp-------------------
void deletebooks() {
    system("cls");
    int d;
    char another = 'y';

    
    char findbook = 'f'; // Initialize findbook

    while (another == 'y') {
        system("cls");
        bookmenu();

        printf(cyan"Enter the Book ID to delete:"reset);
        scanf("%d", &d);

        fp = fopen("lib.txt", "rb+");
        if (fp == NULL) {
            printf(red"Error: Unable to open file\n"reset);
            return;
        }

        rewind(fp);
        while (fread(&a, sizeof(a), 1, fp) == 1) {
            if (a.id == d) {
                findbook = 't'; // Set findbook if record found
                printf(green"The Book Record Is Available"reset);
                printf("Book name is %s\n", a.name);
                printf("Rack No. is %d\n", a.rackno);

                printf(yellow"Do you want to delete it?(Y/N):"reset);
                if (getch() == 'y') {
                    ft = fopen("temp.txt", "wb+");
                    rewind(fp);
                    while (fread(&a, sizeof(a), 1, fp) == 1) {
                        if (a.id != d) {
                            fwrite(&a, sizeof(a), 1, ft);
                        }
                    }
                    fclose(ft);
                    fclose(fp);
                    remove("lib.txt");
                    rename("temp.txt", "lib.txt");
                    printf(green"The Record Is Successfully Deleted"reset);
                    break; // Exit loop after deletion
                } else {
                    fclose(fp);
                    mainmenu();
                    return;
                }
            }
        }

        if (findbook != 't') {
            printf(red"No record is found modify the search\n"reset);
            fclose(fp);
            mainmenu();
            return;
        }

        printf(cyan"Delete another record?(Y/N)"reset);
        fflush(stdin);
        another = getch();
    }

    mainmenu();
}

//----------------------------------function to search books----------------------------------

void searchbooks()
{
    system("cls");
    int d;
    printf(yellow":::::::::::::::::::::::::::::Search Books:::::::::::::::::::::::::::::"reset);
    gotoxy(20, 3);
    printf("\xB2\xB2\xB2\xB2\ 1=> Search By ID");
    gotoxy(20, 5);
    printf("\xB2\xB2\xB2\xB2\ 2=> Search By Name");

    gotoxy(20, 9);
    printf("Enter Your Choice");

    fp = fopen("lib.txt", "rb+"); // open file for reading propose
    rewind(fp);                   // move pointer at the begining of file

    switch (getch())
    {
    case '1':
    {
        system("cls");
        gotoxy(25, 4);
        printf("::::Search Books By Id::::");
        gotoxy(20, 6);
        printf("Enter the book id:");
        scanf("%d", &d);
        gotoxy(20, 8);
        printf("Searching.....");

        while (fread(&a, sizeof(a), 1, fp) == 1)
        {
            if (a.id == d)
            {
        
                gotoxy(20, 7);
                printf("The Book Is Available");
                gotoxy(20, 8);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                gotoxy(20, 9);
                printf("\xB2 ID:%d", a.id);
                gotoxy(47, 9);
                printf("\xB2");
                gotoxy(20, 10);
                printf("\xB2 Name:%s", a.name);
                gotoxy(47, 10);
                printf("\xB2");
                gotoxy(20, 11);
                printf("\xB2 Author:%s ", a.Author);
                gotoxy(47, 11);
                printf("\xB2");
                gotoxy(20, 12);
                printf("\xB2 Quantity:%d ", a.quantity);
                gotoxy(47, 12);
                printf("\xB2");
                gotoxy(47, 11);
                printf("\xB2");
                gotoxy(20, 13);
                printf("\xB2 Price:Rs.%.2f", a.Price);
                gotoxy(47, 13);
                printf("\xB2");
                gotoxy(20, 14);
                printf("\xB2 Rack No:%d ", a.rackno);
                gotoxy(47, 14);
                printf("\xB2");
                gotoxy(20, 15);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                findbook = 't';
            }
        }

        if (findbook != 't') // checks whether conditiion enters inside loop or not
        {
            gotoxy(20, 8);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(20, 9);
            printf("\xB2");
            gotoxy(38, 9);
            printf("\xB2");
            gotoxy(20, 10);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(22, 9);
            printf("\aNo Record Found");
        }

        gotoxy(20, 17);
        printf("Try another search?(Y/N)");
        if (getch() == 'y')
            searchbooks();
        else
            mainmenu();

        break;
    }

    case '2':
    {
        char s[15];
        system("cls");
        gotoxy(25, 4);
        printf("::::Search Books By Name::::");
        gotoxy(20, 5);
        printf("Enter Book Name:");
        scanf("%s", s);
        int d = 0;

        while (fread(&a, sizeof(a), 1, fp) == 1)
        {
            if (strcmp(a.name, (s)) == 0) // checks whether a.name is equal to s or not
            {
                gotoxy(20, 7);
                printf("The Book Is Available");
                gotoxy(20, 8);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                gotoxy(20, 9);
                printf("\xB2 ID:%d", a.id);
                gotoxy(47, 9);
                printf("\xB2");
                gotoxy(20, 10);
                printf("\xB2 Name:%s", a.name);
                gotoxy(47, 10);
                printf("\xB2");
                gotoxy(20, 11);
                printf("\xB2 Author:%s", a.Author);
                gotoxy(47, 11);
                printf("\xB2");
                gotoxy(20, 12);
                printf("\xB2 Qantity:%d", a.quantity);
                gotoxy(47, 12);
                printf("\xB2");
                gotoxy(20, 13);
                printf("\xB2 Price:Rs.%.2f", a.Price);
                gotoxy(47, 13);
                printf("\xB2");
                gotoxy(20, 14);
                printf("\xB2 Rack No:%d ", a.rackno);
                gotoxy(47, 14);
                printf("\xB2");
                gotoxy(20, 15);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                d++;
            }
        }

        if (d == 0)
        {
            gotoxy(20, 8);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(20, 9);
            printf("\xB2");
            gotoxy(38, 9);
            printf("\xB2");
            gotoxy(20, 10);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(22, 9);
            printf("\aNo Record Found");
        }

        gotoxy(20, 17);
        printf("Try another search?(Y/N)");

        if (getch() == 'y')
            searchbooks();
        else
            mainmenu();

        break;
    }

    default:
        getch();
        searchbooks();
    }
    fclose(fp);
}

//-----------------------function that issue books from library-----------------------------

void issuebooks(void)
{
    int t;

    system("cls");
    printf(":::::::::::::::::::::::::::::::ISSUE SECTION::::::::::::::::::::::::::::::::");
    gotoxy(20, 5);
    printf("\xB2\xB2\xB2\xB2\ 1=> Issue a Book");
    gotoxy(20, 7);
    printf("\xB2\xB2\xB2\xB2\ 2=> View Issued Book");
    gotoxy(20, 9);
    printf("\xB2\xB2\xB2\xB2\ 3=> Search Issued Book");
    gotoxy(20, 11);
    printf("\xB2\xB2\xB2\xB2\ 4=> Remove Issued Book");
    gotoxy(20, 13);
    printf("\xB2\xB2\xB2\xB2\ 5=> Back to main menu");

    gotoxy(20, 15);
    printf("Enter a Choice:");

    switch (getch())
    {
    case '1': // issue book
    {
        system("cls");
        int c = 0;
        char another = 'y';
        while (another == 'y')
        {
            system("cls");
            int i, j;
            gotoxy(1, 1);
            printf("::::::::::::::::::::::::::::::::Book List:::::::::::::::::::::::::::::::::");
            gotoxy(2, 2);
            printf(" CATEGORY     ID    BOOK NAME     AUTHOR       QTY     PRICE     RackNo ");
            j = 4;
            fp = fopen("lib.txt", "rb");
            while (fread(&a, sizeof(a), 1, fp) == 1)
            {
                gotoxy(3, j);
                printf("%s", a.cat);
                gotoxy(16, j);
                printf("%d", a.id);
                gotoxy(22, j);
                printf("%s", a.name);
                gotoxy(36, j);
                printf("%s", a.Author);
                gotoxy(50, j);
                printf("%d", a.quantity);
                gotoxy(57, j);
                printf("%.2f", a.Price);
                gotoxy(69, j);
                printf("%d", a.rackno);
                printf("\n\n");
                j++;
                i = i + a.quantity;
            }
            fclose(fp);
            gotoxy(5, 9);
            printf("::::::::::::::::::::::::::::::::Issue Book section::::::::::::::::::::::::::::::::");
            gotoxy(25, 11);
            printf("Enter the Book Id:");
            scanf("%d", &t);
            fp = fopen("lib.txt", "rb");
            fs = fopen("Issue.txt", "ab+");

            if (checkid(t) == 0) // issues those which are present in library
            {
                gotoxy(23, 12);
                printf("The Book Record Is Available!");
                gotoxy(23, 13);
                printf("There are %d unissued books in library ", a.quantity);
                gotoxy(23, 14);
                printf("The name of book is %s", a.name);
                gotoxy(23, 15);
                printf("Enter student name:");
                scanf("%s", a.stname);

                time_t t = time(NULL);
                struct tm date = *localtime(&t);
                a.issued.dd = date.tm_mday;
                a.issued.mm = date.tm_mon;
                a.issued.yy = date.tm_year-100;
                gotoxy(23, 16);
                printf("Issued date=%d-%d-%d", a.issued.dd, a.issued.mm, a.issued.yy);
                gotoxy(23, 17);
                printf("The BOOK of ID %d is issued", a.id);

                a.duedate.dd = a.issued.dd + RETURNTIME; // for return date
                a.duedate.mm = a.issued.mm;
                a.duedate.yy = a.issued.yy;
                if (a.duedate.dd > 30)
                {
                    a.duedate.mm += a.duedate.dd / 30;
                    a.duedate.dd -= 30;
                }
                if (a.duedate.mm > 12)
                {
                    a.duedate.yy += a.duedate.mm / 12;
                    a.duedate.mm -= 12;
                }
                gotoxy(23, 18);
                printf("To be return:%d-%d-%d", a.duedate.dd, a.duedate.mm, a.duedate.yy);
                fseek(fs, sizeof(a), SEEK_END);
                fwrite(&a, sizeof(a), 1, fs);
                fclose(fs);
                c = 1;
            }

            if (c == 0)
            {
                gotoxy(25, 13);
                printf("No record found");
            }

            gotoxy(25, 20);
            printf("Issue any more(Y/N):");
            fflush(stdin);
            another = getch();
            if (another == 'n')
            {
                issuebooks();
            }
            fclose(fp);
        }
        break;
    }
    break;

    case '2': // show issued book list
    {
        system("cls");
        int j = 4;
        printf("::::::::::::::::::::::::::::::Issued Book List:::::::::::::::::::::::::::::::\n");
        gotoxy(2, 2);
        printf("STUDENT NAME    CATEGORY    ID    BOOK NAME    ISSUED DATE    RETURN DATE");
        fs = fopen("Issue.txt", "rb");

        while (fread(&a, sizeof(a), 1, fs) == 1)
        {
            gotoxy(2, j);
            printf("%s", a.stname);
            gotoxy(18, j);
            printf("%s", a.cat);
            gotoxy(30, j);
            printf("%d", a.id);
            gotoxy(36, j);
            printf("%s", a.name);
            gotoxy(51, j);
            printf("%d-%d-%d", a.issued.dd, a.issued.mm, a.issued.yy);
            gotoxy(65, j);
            printf("%d-%d-%d", a.duedate.dd, a.duedate.mm, a.duedate.yy);
            // struct dosdate_t d;
            //_dos_getdate(&d);
            gotoxy(50, 25);
            //            printf("Current date=%d-%d-%d",d.day,d.month,d.year);
            j++;
        }

        fclose(fs);
        gotoxy(1, 25);
        printf("Enter Any Key To Return To Issued Book Section");
        getch();
        issuebooks();
    }
    break;

    case '3': // search issued books
    {
        searchissue1();
    }
    break;

    case '4': // remove issued books from list
    {
        char s[15];
        system("cls");
        int b;
        FILE *fg; // declaration of temporary file for delete
        char another = 'y';
        while (another == 'y')
        {
            gotoxy(10, 5);
            printf("Enter book id to remove:");
            scanf("%d", &b);
            gotoxy(10, 6);
            printf("Enter User Name Of Current Book User:");
            scanf("%s", s);
            fs = fopen("Issue.txt", "rb+");
            while (fread(&a, sizeof(a), 1, fs) == 1)
            {
                if (a.id == b && strcmp(a.stname, (s)) == 0 )
                {
                    issuerecord();
                    findbook = 't';
                }
                if (findbook == 't')
                {
                    gotoxy(10, 12);
                    printf("Do You Want to Remove it?(Y/N)");
                    if (getch() == 'y')
                    {
                        fg = fopen("record.txt", "wb+");
                        rewind(fs);
                        while (fread(&a, sizeof(a), 1, fs) == 1)
                        {
                            if (a.id != b && strcmp(a.stname, (s)) != 0)
                            {
                                fseek(fs, 0, SEEK_CUR);
                                fwrite(&a, sizeof(a), 1, fg);
                            }
                        }
                        fclose(fs);
                        fclose(fg);
                        remove("Issue.txt");
                        rename("record.txt", "Issue.txt");
                        gotoxy(10, 14);
                        printf("The issued book is removed from list");
                    }
                }
                if (findbook != 't')
                {
                    gotoxy(10, 15);
                    printf("No Record Found");
                }
            }
            gotoxy(10, 16);
            printf("Delete any more?(Y/N)");
            another = getch();
        }

        printf("Enter Any Key to Return To Issue Section");
        getch();
        issuebooks();
    }
    break;

    case '5':
        mainmenu();
        break;

    default:
        printf("\n\n");
        gotoxy(20, 18);
        printf("Wrong Entry!!");
        getch();
        issuebooks();
        break;
    }


}
//----------------------------show the list of book persists in library-----------------------

void viewbooks(void)
{
    int i = 0, j;
    system("cls");
    gotoxy(1, 1);
    printf("::::::::::::::::::::::::::::::::Book List:::::::::::::::::::::::::::::::::");
    gotoxy(2, 2);
    printf(" CATEGORY     ID    BOOK NAME     AUTHOR       QTY     PRICE     RackNo ");
    j = 4;
    fp = fopen("lib.txt", "rb");
    while (fread(&a, sizeof(a), 1, fp) == 1)
    {
        gotoxy(3, j);
        printf("%s", a.cat);
        gotoxy(16, j);
        printf("%d", a.id);
        gotoxy(22, j);
        printf("%s", a.name);
        gotoxy(36, j);
        printf("%s", a.Author);
        gotoxy(50, j);
        printf("%d", a.quantity);
        gotoxy(57, j);
        printf("%.2f", a.Price);
        gotoxy(69, j);
        printf("%d", a.rackno);
        printf("\n\n");
        j++;
        i = i + a.quantity;
    }
    gotoxy(3, 25);
    printf("Total Books =%d", i);
    fclose(fp);
    gotoxy(35, 25);
    returnfunc();
}
//----------------------------edit information about book-------------------------------
void editbooks(void)
{
    system("cls");
    int c = 0;
    int d, e;
    gotoxy(20, 4);
    printf("****Edit Books Section****");
    char another = 'y';

    while (another == 'y')   //infinite loop
    {
        system("cls");
        gotoxy(15, 6);
        printf("Enter Book Id to be edited:");
        scanf("%d", &d);
        fp = fopen("lib.txt", "rb+");

        while (fread(&a, sizeof(a), 1, fp) == 1)
        {
            if (checkid(d) == 0)
            {
                gotoxy(15, 7);
                printf("The Book Is Available");
                gotoxy(15, 8);
                printf("The Book ID:%d", a.id);
                gotoxy(15, 9);
                printf("Enter New Name:");
                scanf("%s", a.name);
                gotoxy(15, 10);
                printf("Enter New Author:");
                scanf("%s", a.Author);
                gotoxy(15, 11);
                printf("Add New Quantity:");
                scanf("%d", &a.quantity);
                gotoxy(15, 12);
                printf("Enter New Price:");
                scanf("%f", &a.Price);
                gotoxy(15, 13);
                printf("Enter New Rackno:");
                scanf("%d", &a.rackno);
                gotoxy(15, 14);
                printf("The record is modified");
                fseek(fp, ftell(fp) - sizeof(a), 0);
                fwrite(&a, sizeof(a), 1, fp);
                fclose(fp);
                c = 1;
            }

            if (c == 0)
            {
                gotoxy(15, 9);
                printf("No record found");
            }
        }

        gotoxy(15, 16);
        printf("Modify another Record?(Y/N)");
        fflush(stdin);
        another = getch();
    }

    returnfunc();
}
//----------------------------------------------------------------------------
void returnfunc(void)
{
    {
        printf(" Press ENTER to return to main menu");
    }
a:
    if (getch() == 13) // allow only use of enter
        mainmenu();
    else
        goto a;
}

//----------------------------------------------------------------
int getdata()
{
    int t;
    gotoxy(20, 3);
    printf(blue"Enter the Information Below"reset);
    gotoxy(20, 4);
    printf(yellow"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20, 5);
    printf("\xB2");
    gotoxy(46, 5);
    printf("\xB2");
    gotoxy(20, 6);
    printf("\xB2");
    gotoxy(46, 6);
    printf("\xB2");
    gotoxy(20, 7);
    printf("\xB2");
    gotoxy(46, 7);
    printf("\xB2");
    gotoxy(20, 8);
    printf("\xB2");
    gotoxy(46, 8);
    printf("\xB2");
    gotoxy(20, 9);
    printf("\xB2");
    gotoxy(46, 9);
    printf("\xB2");
    gotoxy(20, 10);
    printf("\xB2");
    gotoxy(46, 10);
    printf("\xB2");
    gotoxy(20, 11);
    printf("\xB2");
    gotoxy(46, 11);
    printf("\xB2");
    gotoxy(20, 12);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"reset);
    gotoxy(21, 5);
    printf(megenta"Category:");
    gotoxy(31, 5);
    printf("%s", catagories[s - 1]);
    gotoxy(21, 6);
    printf("Book ID:\t");

    gotoxy(30, 6);
    scanf("%d", &t);

    if (checkid(t) == 0)
    {
        gotoxy(21, 13);
        printf("\aThe book id already exists\a");
        getch();
        mainmenu();
        return 0;
    }
    a.id = t;
    gotoxy(21, 7);
    printf("Book Name:");
    gotoxy(33, 7);
    scanf("%s", a.name);
    gotoxy(21, 8);
    printf("Author:");
    gotoxy(30, 8);
    scanf("%s", a.Author);
    gotoxy(21, 9);
    printf("Quantity:");
    gotoxy(31, 9);
    scanf("%d", &a.quantity);
    gotoxy(21, 10);
    printf("Price:");
    gotoxy(28, 10);
    scanf("%f", &a.Price);
    gotoxy(21, 11);
    printf("Rack No:"reset);
    gotoxy(30, 11);
    scanf("%d", &a.rackno);
    return 1;
}
//-----------------------check whether the book is exist in library or not-------------------
int checkid(int t)
{
    rewind(fp);
    while (fread(&a, sizeof(a), 1, fp) == 1)
        if (a.id == t)
            return 0; // returns 0 if book exits
    return 1;         // return 1 if it not
}
//-------------------------display issued book's information-----------------------------
void issuerecord()
{
    system("cls");
    gotoxy(10, 8);
    printf("The Book has taken by Mr. %s", a.stname);
    gotoxy(10, 9);
    printf("The Name Of The Book Taken By Mr. %s Is %s",a.stname,a.name);
    gotoxy(10,10);
    printf("Issued Date:%d-%d-%d", a.issued.dd, a.issued.mm, a.issued.yy);
    gotoxy(10, 11);
    printf("Returning Date:%d-%d-%d", a.duedate.dd, a.duedate.mm, a.duedate.yy);
}

//------------------------------------------PASSWORD-------------------------------
void Password(void) //
{
    system("cls");
    char ch, pass[10];
    int i = 0, j;

    gotoxy(10, 4);
    lineanim(20);

    char d[] = " Welcome To our CS group project ";
    wanim(d);

    lineanim(20);

    gotoxy(36, 7);
    char y[] = "Enter Password:";
    wanim(y);

    while (ch != 13)   // 13 is ascii value pf enterr
    {
        ch = getch();
        if (ch != 13 && ch != 8)   // 8 is ascii value of 
        {
            putch('*');     // puts the star in place of all characters 
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    if (strcmp(pass, password) == 0)
    {
        gotoxy(35, 9);
        
        printf(green"Now You Are Logged In!");
        gotoxy(32, 11);
        printf(green"Press any key to countinue..."reset);
        getch();
        mainmenu();
    }
    else
    {
        gotoxy(40, 10);
        printf(red"\aWarning!!");
        gotoxy(35, 12);
        printf("Incorrect Password"reset);
        getch();
        Password();
    }
}

//------------------------------------------CREDITS(DONE)--------------------------------
void credits()
{
    system("cls");

    gotoxy(10, 2);
    lineanim(40);

    gotoxy(10, 3);
    char d1[] = "\tTHIS PROJECT IS CREATED BY: ";
    wanim(d1);

    gotoxy(14, 5);
    char d2[] = "\tShaurya 2301MM14";
    wanim(d2);

    gotoxy(14, 6);
    char d3[] = "\tSumit 2301MC29";
    wanim(d3);

    gotoxy(14, 7);
    char d4[] = "\tAmaan Ali 2302GT06";
    wanim(d4);

    gotoxy(14, 8);
    char d5[] = "\tSujal  2301AI26";
    wanim(d5);

    gotoxy(14, 9);
    char d6[] = "\tAryaman 2301MC43";
    wanim(d6);

    gotoxy(14, 10);
    char d7[] = "\tGajendra 2301ME18";
    wanim(d7);

    gotoxy(14, 11);
    char d8[] = "\tShourya 2302MT03";
    wanim(d8);

    gotoxy(14, 12);
    char d9[] = "\tRitesh 2301PH15";
    wanim(d9);

    gotoxy(14, 13);
    char d10[] = "\tTaksh 2302ST08";
    wanim(d10);

    gotoxy(14, 14);
    char d11[] = "\tMonali 2301ME75\n\n";
    wanim(d11);

    gotoxy(10, 15);
    lineanim(40);
    printf("\n\n");

    returnfunc();
}

//---------------------------------------Line Animation(DONE)-------------------------------
void lineanim(int x)
{
    for (int j = 0; j < x; j++)
    {
        Sleep(25);
        printf(":");
    }
}

//--------------------------------------Word Animation(DONE)-------------------------------

void wanim(char d[])
{
    int j = 0;
    while (d[j] != '\0')
    {
        Sleep(20);
        printf("%c", d[j]);
        j++;
    }
}

//----------------------------------------Closing App(DONE)--------------------------------
void closeapp()
{
    system("cls");
    gotoxy(14, 1);
    lineanim(35);

    gotoxy(14, 3);
    char d1[] = "\t     Thanks for exploring";
    wanim(d1);

    gotoxy(15, 5);
    char d2[] = "\t   Library Management System !";
    wanim(d2);

    gotoxy(17, 7);
    char d3[] = "\tHappy reading :)";
    wanim(d3);

    gotoxy(14, 9);
    lineanim(35);

    gotoxy(14, 11);
    char d4[] = "  .....Exiting in 5 seconds......";
    wanim(d4);
    printf("\n");

    gotoxy(1, 20);
    Sleep(3000);
    exit(0);
}


void searchissue1()
{
        system("cls");
        int d;
        printf(":::::::::::::::::::::::::::::Search Issued Books:::::::::::::::::::::::::::::");
        gotoxy(20, 3);
        printf("\xB2\xB2\xB2\xB2\ 1=> Search Issued By ID");
        gotoxy(20, 5);
        printf("\xB2\xB2\xB2\xB2\ 2=> Search Issued By Name");

        gotoxy(20, 9);
        printf("Enter Your Choice");

        char x;
        x=getch();

        if(x=='1' || x=='2')    
            searchissue2(x);

        else
        {
           printf("wrong entry");
            searchissue1();
        }
        
}

void searchissue2(char x)
{

    switch (x)
    {
        case '1':
        {
            system("cls");
            gotoxy(25, 4);
            printf("::::Search Issued Books By Id::::");
            gotoxy(20, 6);
            printf("Enter Book ID:");
            int p, c = 0;
            char another = 'y';
            while (another == 'y')
            {

                scanf("%d", &p);
                fs = fopen("Issue.txt", "rb");
                while (fread(&a, sizeof(a), 1, fs) == 1)
                {
                    if (a.id == p)
                    {
                        issuerecord();
                        gotoxy(10, 12);
                        printf("Press any key.......");
                        getch();
                        c = 1;
                    }
                }
                fclose(fs);
                if (c == 0)
                {
                    gotoxy(10, 8);
                    printf("No Record Found");
                }
                gotoxy(10, 13);
                printf("Try Another Search?(y/n)");
                another = getch();
                if (another == 'n')
                {
                    issuebooks();
                }
                if(another=='y')
                    searchissue1();
                fclose(fp);

            }
        }
        break;

         case '2':
        {
            char s[15];
            system("cls");
            gotoxy(25, 4);
            printf("::::Search Books By Name::::");
            gotoxy(20, 5);
            printf("Enter Book Name:");
            scanf("%s", s);
            int d = 0;

            while (fread(&a, sizeof(a), 1, fp) == 1)
            {
                if (strcmp(a.name, (s)) == 0) // checks whether a.name is equal to s or not
                {
                    gotoxy(20, 7);
                    printf("The Book Is Available");
                    gotoxy(20, 8);
                    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                    gotoxy(20, 9);
                    printf("\xB2 ID:%d", a.id);
                    gotoxy(47, 9);
                    printf("\xB2");
                    gotoxy(20, 10);
                    printf("\xB2 Name:%s", a.name);
                    gotoxy(47, 10);
                    printf("\xB2");
                    gotoxy(20, 11);
                    printf("\xB2 Author:%s", a.Author);
                    gotoxy(47, 11);
                    printf("\xB2");
                    gotoxy(20, 12);
                    printf("\xB2 Qantity:%d", a.quantity);
                    gotoxy(47, 12);
                    printf("\xB2");
                    gotoxy(20, 13);
                    printf("\xB2 Price:Rs.%.2f", a.Price);
                    gotoxy(47, 13);
                    printf("\xB2");
                    gotoxy(20, 14);
                    printf("\xB2 Rack No:%d ", a.rackno);
                    gotoxy(47, 14);
                    printf("\xB2");
                    gotoxy(20, 15);
                    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                    d++;
                }
            }

            if (d == 0)
            {
                gotoxy(20, 8);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                gotoxy(20, 9);
                printf("\xB2");
                gotoxy(38, 9);
                printf("\xB2");
                gotoxy(20, 10);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                gotoxy(22, 9);
                printf("\aNo Record Found");
            }

            gotoxy(20, 17);
            printf("Try another search?(Y/N)");

            if (getch() == 'y')
                searchbooks();
            else
                mainmenu();

            break;
        }
        break;

        default:
            getch();
            searchbooks();
        break;
    }
    fclose(fp);
}

//---------------------------------------------END------------------------------------------