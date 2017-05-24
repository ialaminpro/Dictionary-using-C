#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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


int main( )
{
    char word [ 20 ] , ch ;
    char c,words[20];

    int i,n,j,y ,p;
    while ( 1 )
    {

        system("cls");
        printf ( "\n\t\tDictionary\n" ) ;
        printf ( "\n\t\t1.Add Word.\n" ) ;
        printf ( "\t\t2.Search Word.\n" ) ;
        printf ( "\t\t3.Show Dictionary.\n" ) ;
        printf ( "\t\t0.Exit." ) ;
        printf ( "\n\n\t\tYour Choice ") ;
        scanf ( "%d", &ch ) ;

        switch ( ch )
        {
            case 1 :

                fr = fopen ("1.txt", "a");
                system("cls");

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
                 fclose(fr);
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

                      default :

                printf ( "\nWrong Choice" ) ;
                    }
                    main( );
                 }

            case 0 :
               exit(0);

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

      search ( str ) ;
    if ( f==1 )
    {
        printf ( "\nWord already exists." ) ;
        getch( ) ;
        f=0;
        return ;
    }

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

   int n,i,j;
   long elapsed_seconds;
   char str[80];
   fr = fopen ("1.txt", "rt");
   n=0;
   while(fgets(str, 80, fr) != NULL)
   {
       if((strstr( str ,st)) != NULL) {

			printf("\n%s\n", str);
			f=1;

			}
	n++;
   }
   if(f==0)
     printf ( "Word does not exists." ) ;
 fclose(fr);

}

void recent_show( )
{
    struct node *n ;
    int i, j ;

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
}

void show( )
{
    int n,i,j;
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


