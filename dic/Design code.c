#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include<dos.h>
#include<time.h>

struct node
{
	char data [ 20 ] ;
	char m [ 5 ] [ 20 ] ;
	int mcount ;
	struct node * link ;
} ;


struct node * dic [ 26 ] ;

void aux();
void add ( char * ) ;
int  search ( char * ) ;
void show( ) ;
void deldic( ) ;
int about();
void window();
int screen();
void SetColor(int ForgC);
int main_menu();
int main_dic( );
void mainmenu();


     COORD coord = {0, 0};
COORD max_res,cursor_size;

void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main ()
{
    screen();
    main_menu();
    return 0;
}

int screen()
{
    system("cls");
    system("color 1D");

    int i,j;
    char name[50]="Welcome to our Dictionary project";
    printf("\n\n\n\n\n\n\n\t\t\t");
    for(i=0;i<50;i++)
    {
        printf("%c",name[i]);
        Sleep(50);
    }
    printf("\n\n\n\n\t\t\t");
    char name1[60]="\t\tLOADING......";
    printf("\n\t\t");
    for(j=0;j<60;j++)
    {
        printf("%c",name1[j]);
        Sleep(50);
    }
    Sleep(2000);
    return 0;
}

void SetColor(int ForgC)
{
     WORD wColor;

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;


     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {

          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

void ClearConsoleToColors(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

     COORD coord = {0, 0};

     DWORD count;

     CONSOLE_SCREEN_BUFFER_INFO csbi;

     SetConsoleTextAttribute(hStdOut, wColor);
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {

          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );

          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}

void SetColorAndBackground(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

void clearWindow(){
    int i,j;
    for(i = 37; i < 78; i++){
        for(j = 7; j < 25; j++){
            gotoxy(i,j);printf(" ");
        }
    }
    return;
}

void window(){

    gotoxy(28,2);
    SetColor(35);
    printf("  Dictionary ");
    gotoxy(16,3);
    SetColor(25);
    printf("Daffodil International University,Bangladesh");
    gotoxy(22,4);
    SetColor(45);
    printf("\t\t BID");
    gotoxy(22,5);

    SetColor(17);

}
void print_heading(const char st[]){
    SetColorAndBackground(31,38);
    gotoxy(45,8);printf("SRS : %s",st);
    SetColorAndBackground(17,15);
}


int main_menu()
{
    system("cls");
    char ch;
    system("color 1E");

    printf("\n\n\n");
    printf("\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2  Main Menu   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2  Enter it[E]  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2  Quit [Q]     \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2  Information[I]  \xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    printf("\n\n");
    printf("Enter your key : ");
    scanf("%c",&ch);
    switch(ch)
    {
        case 'E':
        case 'e':
        {
            main_dic( );

            break;
        }
        case 'I':
        case 'i':
        {
            about();
            break;
        }
        case 'q':
        case 'Q':
        {
            exit1();
            break;
        }

        default:
        main_menu();
        break;

    }
    return 0;
}

int exit1()
{
    system("cls");
    system("color 48");

    printf("\nThanks for using our product......\n");
    printf("Exiting in 5 sec");
    Sleep(5000);
    exit(0);
    return 0;
}

void mainmenu()
{
	system("cls");
    system("color 0E");

	int n;
	printf("\n");
    printf("\n\n\n");
    printf("\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2  MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2 1.Reseve Ticket   \xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2 2 Platform status \xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2 3. Back           \xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    printf("\n\n");
	printf("Enter your choice: ");
	scanf("%d",&n);
	switch (n)
	{
		case 1:
                {
                    not_yet();
                    break;
                }
        case 2:{
			aux( );
            break;
                }
		case 3:{
            main_menu();
            break;
                }
        default:
            {
                printf("Why you've typed wrong key??");
                Sleep(5000);
                mainmenu();
            }
	}
}

int about()
{
    system("cls");
    system("color 0E");

        int a=8;
        printf("\n\n\n");
		gotoxy(16,3);
		printf("Programmers....");
		gotoxy(16,5);
		printf("1. Al-Amin            (132-15-2625)");
		gotoxy(16,7);

		printf("2. Istiaq Hasan       (132-15-2698)");
		gotoxy(16,9);

		printf("3. Parvez             (132-15-2755)");
		gotoxy(16,15);



		printf("press 8 to go back to the main menu : ");
		scanf("%d",&a);
		if(a==8)
            {
                main_menu();
            }
            else
            {
                printf("You have press wrong key");
            }
}


int search ( char *str )
{
    clearWindow();
    print_heading("Display Search Info");
    SetColor(45);
    fflush(stdin);

	struct node *n ;
	char temp1 [ 20 ] ;
	char temp2 [ 20 ] ;
	int i ;

	n = dic [ toupper ( str [ 0 ] ) - 65 ] ;
	strcpy ( temp2, str ) ;
	strupr ( temp2 ) ;

	while ( n != NULL )
	{
		strcpy ( temp1, n -> data ) ;

		if (  strcmp ( strupr ( temp1 ), temp2 ) == 0 )
		{
			 gotoxy(37,12);printf ( "\n%s\t\t%s", n -> data, n -> m [ 0 ] ) ;
			for ( i = 1 ; i < n -> mcount ; i++ )
				 gotoxy(37,13);printf ( "\n\t\t%s", n -> m [ i ] ) ;
			return 1 ;
		}
		n = n -> link ;
	}
	SetColor(28);
	return 0 ;
}

void deldic( )
{
	struct node *n, *t ;
	int i ;

	for ( i = 0 ; i <= 25 ; i++ )
	{
		n = dic [ i ] ;
		while ( n != NULL )
		{
			t = n -> link ;
			free ( n ) ;
			n = t ;
		}
	}
}

int not_yet()
{
    system("cls");
    char ch;
    system("color 0E");

    printf("\n\n\n");
    printf("\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2 Under processing!!\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2     Back[B]       \xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    printf("\n\n");
    printf("Enter your key : ");
    scanf("%c",&ch);
    switch(ch)
    {
        case 'B':
        case 'b':
        {
           main_dic( );

            break;
        }
        default:
        not_yet();
        break;
    }
    return 0;
}



int main_dic( )
{
	char word [ 20 ] , ch ;
	int i ;
	 SetColor(28);
    int x = 2;

	system ( "cls" ) ;

	while ( 1 )
	{
		system("cls");
    system("color 0E");

	int ch ;
	printf("\n");
    printf("\n\n\n");
    printf("\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2  MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2 1.Add Word        \xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2 2.Search Word     \xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2 3.Show Dictionary \xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2 0.Exit            \xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    printf("\n\n");
	printf("Enter your choice: ");
		scanf ( "%d", &ch ) ;

		switch ( ch )
		{
			case 1 :{
				aux( ) ;
				break ;
			}

			case 2 :

				printf ( "\nEnter the word to search : " ) ;
				fflush ( stdin ) ;
				gets ( word ) ;
				i = search ( word ) ;
				if ( ! i )
					printf ( "Word does not exists." ) ;
        getch( ) ;
				break ;

			case 3 :

				show( ) ;
        getch( ) ;
				break ;

			case 0 :

				deldic( ) ;
				exit ( 0 ) ;

			default :

				printf ( "\nWrong Choice" ) ;
		}
	}
  return 0 ;
}

void aux( ){
    char word;
    ClearConsoleToColors(17,15);
    SetConsoleTitle("BID");
    window();
    printf ( "\nEnter any word : " ) ;
    fflush ( stdin ) ;
    scanf("%s",word);
    add (word);
    return;
}


void add ( char * str )
{


	int i, j = toupper ( str [ 0 ] ) - 65 ;
	struct node * r, * temp = dic [ j ], * q ;
	char mean [ 5 ] [ 20 ], ch = 'y' ;

	i = search ( str ) ;
	if ( i )
	{

		printf ( "\nWord already exists." ) ;
		return ;
	}
	q = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
	strcpy ( q -> data, str ) ;
	q -> link = NULL ;

	for ( i = 0 ; tolower ( ch ) == 'y' && i < 5 ; i++ )
	{
		fflush ( stdin ) ;
		  system("cls");
    system("color 0E");

        printf("Enter the meaning(s)");

		gets ( mean [ i ] ) ;
		strcpy ( q -> m [ i ] , mean [ i ] ) ;
		if ( i != 4 ){
       printf("Add more meanings (y/n)");

		}

		else
        printf("You cannot enter more than 5 meanings.");


		fflush ( stdin ) ;
		//fclose(fp);
		ch = getche( ) ;
	}

	q -> mcount = i ;
	if ( dic [ j ] == NULL || strcmp ( dic [ j ] -> data, str ) > 0 )
	{
		r = dic [ j ] ;
		dic [ j ] = q ;
		q -> link = r ;
		return ;
	}

	else
	{
		while ( temp != NULL )
		{
			if ( ( strcmp ( temp -> data, str ) < 0 ) && ( ( strcmp ( temp -> link -> data, str ) > 0 ) ||
											temp -> link == NULL ) )
			{
				q -> link = temp -> link ;
				temp -> link = q ;
				return ;
			}
			temp = temp -> link ;
		}
	}
}
  FILE *fp;


void show( )
{
	struct node *n ;
	int i, j ;

    fp=fopen("dictionary.txt","a");
	printf ( "Word\t\tMeaning\n" ) ;

	fprintf(fp,"Word\t\tMeaning\n");

	for ( i = 0 ; i <= 30 ; i++ ){

		printf ( "-" ) ;
        fprintf(fp,"-");
	}


	for ( i = 0 ; i <= 25 ; i++ )
	{
		n = dic [ i ] ;
		while ( n != NULL )
		{
			printf ( "\n%s\t\t%s", n -> data, n -> m [ 0 ] ) ;

			fprintf(fp,"\n%s\t\t%s", n -> data, n -> m [ 0 ]);

			for ( j = 1 ; j < n -> mcount ; j++ )
				printf ( "\n\t\t%s", n -> m [ j ] ) ;


				fprintf(fp,"\n\t\t%s", n -> m [ j ] );

			n = n -> link ;

		}
	}
	fclose(fp);

}



void display()
{

    printf("                       *****This is Dictionary *****");
}
