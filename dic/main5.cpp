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

FILE *fr;

struct node * dic [ 26 ] ;
int f=0;
void add ( char * ) ;
int  search ( char * ) ;
void show( ) ;
void deldic(char * ) ;
void lexi ();
void recent_show( );
int about();
void window();
int screen();
void SetColor(int ForgC);
int main_menu();
int main_dic( );
void mainmenu();

int exit1();
int not_yet();
int recent_search(char *);

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
    system("color 1");
    gotoxy(28,2);
    SetColor(35);
    printf("  Dictionary ");
    gotoxy(16,3);
    SetColor(25);
    printf("Daffodil International University,Bangladesh");
    gotoxy(22,4);
    SetColor(45);
    printf("\tPrepared by Al-Amin");
    gotoxy(22,5);

    SetColor(27);

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
    system("color 1D");

    printf("\n\n\n\t\tThanks for using our my Dictionary......\n");
    printf("\n\t\tPrepared by Al-Amin :)\n\n");
    printf("\tExiting in 5 sec");
    Sleep(5000);
    exit(0);
    return 0;
}

int main_dic( )
{
    char word [ 20 ] , ch ;
    system("cls");
    int i,n,j,y ,p;
    SetColor(28);
    int x = 2;
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
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2 4.Main Menu       \xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\n");
    printf("\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    printf("\n\n");
	printf("Enter your choice: ");
        scanf ( "%d", &ch ) ;

        switch ( ch )
        {
            case 1 :
               ClearConsoleToColors(17,15);
               SetConsoleTitle("BID");
               window();
                fr = fopen ("1.txt", "a");

                printf ( "\nEnter any word : " );
                fflush ( stdin ) ;

                gets ( word ) ;
                for(p = 0; word[p]; p++){
                word[p] = tolower(word[p]);
                  }
                 i = search ( word ) ;

                 printf ( "\n1.Add another word\n" ) ;
                 scanf ( "%d", &ch ) ;
                 system("cls");
                 switch ( ch )
                    {
                    case 1 :
                 ClearConsoleToColors(17,15);
               SetConsoleTitle("BID");
               window();
                fr = fopen ("1.txt", "a");

                printf ( "\nEnter any word : " );
                fflush ( stdin ) ;

                gets ( word ) ;
                for(p = 0; word[p]; p++){
                word[p] = tolower(word[p]);
                  }
                fprintf(fr,"\n");
                fprintf(fr,"%s .",word);
                add ( word ) ;
                lexi ();
                getch( ) ;
                fclose(fr);

                 break ;
                default :

                printf ( "\nWrong Choice" ) ;
                    }

            break ;

            case 2 :
                system("cls");
                printf ( "\nEnter the word to search : " ) ;
                fflush ( stdin ) ;

                gets ( word ) ;

                 for(p = 0; word[p]; p++){
                 word[p] = tolower(word[p]);
                  }
                 i = search ( word ) ;


                getch( ) ;

                break ;

            case 3 :
                 for(y=0;y<2;y++)
                 {
                system("cls");
                printf ( "\t\t1.Show Recent Add words.\n" ) ;
                printf ( "\t\t2.Show All words.\n" ) ;
                printf ( "\t\t3.Main Menu.\n" ) ;
                scanf ( "%d", &ch ) ;

                switch ( ch )
                    {
                    case 1 :
                        system("cls");
                        recent_show( );
                        getch( ) ;
                        break ;
                     case 2 :
                          system("cls");
                          show( ) ;
                          getch( ) ;
                          break ;
                     case 3 :
                        main_dic( );

                      default :

                printf ( "\nWrong Choice" ) ;
                    }
                    main( );
                 }

            case 4 :

               main_menu();

                break ;


            default :

                printf ( "\nWrong Choice" ) ;
        }
    }
}



void add ( char * str )
{
    int i, j = toupper ( str [ 0 ] ) - 65 ;
    struct node * r, * temp = dic [ j ], * q ;
    char mean [ 5 ] [ 20 ], ch = 'y' ;

    q = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
    strcpy ( q -> data, str ) ;
    q -> link = NULL ;

    for ( i = 0 ; tolower ( ch ) == 'y' && i < 5 ; i++ )
    {

        fflush ( stdin ) ;
        printf ( "\n\nEnter the meaning(s) : " ) ;
        gets ( mean [ i ] ) ;
        fprintf(fr,"%s ",mean[i]);
        strcpy ( q -> m [ i ] , mean [ i ] ) ;
        if ( i != 4 )
            printf ( "\nAdd more meanings (y/n) " ) ;

        else
            printf ( "You cannot enter more than 5 meanings." ) ;

        fflush ( stdin ) ;
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

int search ( char *st )
{

    clearWindow();
    print_heading("Display Search Info");
    SetColor(45);
    fflush(stdin);

   int n,i,j;
   long elapsed_seconds;
   char str[80];
   fr = fopen ("1.txt", "rt");
   n=0;
   while(fgets(str, 80, fr) != NULL)
   {
       if((strstr( str ,st)) != NULL) {

        gotoxy(37,12);printf("\n%s\n", str);
			f++;

			}
	n++;
   }

 if(f==0){
        recent_search(st);

 }
 fclose(fr);
 SetColor(28);

}

int recent_search ( char *str )
{
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
            printf ( "\n%s\t\t%s", n -> data, n -> m [ 0 ] ) ;
            for ( i = 1 ; i < n -> mcount ; i++ )
                printf ( "\n\t\t%s", n -> m [ i ] ) ;
           f++ ;
        }
        n = n -> link ;
    }
    if(f==0){
    gotoxy(37,13);printf ( "Word does not exists." ) ;
    }
}


void recent_show( )
{
    struct node *n ;
    int i, j ,a,y,ch;

    printf ( "Word\t\tMeaning\n" ) ;
    for ( i = 0 ; i <= 30 ; i++ )
        printf ( "-" ) ;


    for ( i = 0 ; i <= 25 ; i++ )
    {
        n = dic [ i ] ;
        while ( n != NULL )
        {
            printf ( "\n%s\t\t%s", n -> data, n -> m [ 0 ] ) ;
            for ( j = 1 ; j < n -> mcount ; j++ )
                printf ( "\n\t\t%s", n -> m [ j ] ) ;
            n = n -> link ;
        }
    }
    printf("\n\npress 1 to go back to the Show Dictionary : ");
  printf("\n\npress 2 to go back to the main menu : ");
		scanf("%d",&a);
		if(a==1)
            {
                for(y=0;y<2;y++)
                 {
                system("cls");
                printf ( "\t\t1.Show Recent Add words.\n" ) ;
                printf ( "\t\t2.Show All words.\n" ) ;
                printf("\n\npress 2 to go back to the main menu : ");
                scanf ( "%d", &ch ) ;

                switch ( ch )
                    {
                    case 1 :
                        system("cls");
                        recent_show( );
                        getch( ) ;
                        break ;
                     case 2 :
                          system("cls");
                          show( ) ;
                          getch( ) ;
                          break ;
                     case 3 :
                        main_menu();
                    }
                 }
            }

		else if(a==2)
            {
                main_menu();
            }
            else
            {
                printf("You have press wrong key");
            }
}



void show( )
{
    int n,i,j,a,y,ch;
    long elapsed_seconds;
    char str[10000][100];
     fr = fopen ("1.txt", "rt");
     n=0;
      while(fgets(str[n],80, fr) != NULL)
       {

	printf(str[n]);
	n++;

   }
 fclose(fr);
 printf("\n\npress 1 to go back to the Show Dictionary : ");
  printf("\n\npress 2 to go back to the main menu : ");
		scanf("%d",&a);
		if(a==1)
            {
                for(y=0;y<2;y++)
                 {
                system("cls");
                printf ( "\t\t1.Show Recent Add words.\n" ) ;
                printf ( "\t\t2.Show All words.\n" ) ;
                 printf("\n\npress 3 to go back to the main menu : ");
                scanf ( "%d", &ch ) ;

                switch ( ch )
                    {
                    case 1 :
                        system("cls");
                        recent_show( );
                        getch( ) ;
                        break ;
                     case 2 :
                          system("cls");
                          show( ) ;
                          getch( ) ;
                          break ;
                    case 3 :
                        main_menu();
                    }
                 }
            }


		else if(a==2)
            {
                main_menu();
            }
            else
            {
                printf("You have press wrong key");
            }


}

void lexi () {
   int n,i,j;
   long elapsed_seconds;
   char str[10000][100],temp[80];


   fr = fopen ("1.txt", "rt");

 n=0;
   while(fgets(str[n],80, fr) != NULL)
   {

	n++;

   }
 fclose(fr);

   for(i=0;i<n-1;i++)
       for(j=i+1;j<n;j++){
          if(strcmp(str[i],str[j])>0)
          {
            strcpy(temp,str[i]);
            strcpy(str[i],str[j]);
            strcpy(str[j],temp);
          }
    }

   fr = fopen ("1.txt", "w+");
    for(i=0;i<n;i++){
       fprintf(fr,"%s",str[i]);
    }

  fclose(fr);
}
int about()
{
    system("cls");
    system("color 0E");

        int a;
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



		printf("press 4 to go back to the main menu : ");
		scanf("%d",&a);
		if(a==4)
            {
                main_menu();
            }
            else
            {
                printf("You have press wrong key");
            }

}

