#include <stdio.h>   /* required for file operations */
#include <string.h>  /* for string operatins */

FILE *fr;            /* declare the file pointer */

main()

{
   int n,i,j;
   long elapsed_seconds;
   char str[80][80],temp[80];


   fr = fopen ("1.txt", "rt");  /* open the file for reading */

   /* "rt" means open the file for reading text */
 n=0;
   while(fgets(str[n],80, fr) != NULL)
   {
	 /* get a line, up to 80 chars from fr.  done if NULL */

	printf(str[n]);
	n++;

   }
 fclose(fr);// close a file

 // for lexicographic sorting of words
   for(i=0;i<n-1;i++)
       for(j=i+1;j<n;j++){
          if(strcmp(str[i],str[j])>0)
          {
            strcpy(temp,str[i]);
            strcpy(str[i],str[j]);
            strcpy(str[j],temp);
          }
    }
    // after lexicographic sorting write words in 1.txt file which can reuse

   fr = fopen ("1.txt", "w+");
    printf("\nAfter lexicographical order: \n\n");
    for(i=0;i<n;i++){
       printf(str[i]);
       fprintf(fr,"%s",str[i]);
    }

  fclose(fr);  /* close the file */
}
