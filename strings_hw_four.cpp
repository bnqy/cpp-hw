#include <cstdio>
#include <cstddef>
#include <cstdlib>
#include <cstring>
 
void commaSake(char *string)
{
   int string_length = strlen(string);
   char *p = (char*)malloc(string_length + 1);
   char *s = string;
   char *d = p;
   do
   {
      *d++  = *s;
      if (*s== ' ') *d++ = ',';
   } while (*s++ != '\0');
      
   strcpy(string, p);
   free(p);
}
 
int main(int argc, char *argv[])
{
   size_t p_size = 65535;
   char *p = (char*)malloc(p_size);
 
   while (!feof(stdin))
   {
      if (fgets(p, p_size, stdin))
      {
         size_t p_length = strlen(p);
         if (p_length > 0) 
            p[p_length - 1] = '\0';
         commaSake(p);
         printf("%s\n", p);
      }
   }
 
   free(p);
   return 0;
}
