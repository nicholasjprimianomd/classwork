/**********************************************************************
 *
 * Project 4: Strings, the Hard Way
 *
 * Author: 
 * Date:   
 *
 * ????
 *
 **********************************************************************/

#include <iostream>
using namespace std;

const char* get_c_string();
int strlen(const char* s);
bool islower(char c);
void toupper(char* s);
char* strdup(const char* s);
char* cat_dot(const char *s1, const char* s2, const char* sep=".");
bool is_palindrome(const char* s);

// test out our functions
int main()
{
   cout << "toupper/strdup test:\n";
   cout << "Enter a mixed-case string: ";
   const char* s = get_c_string();
   cout << "The original string is \"" << s << "\"\n";
   char *s1 = strdup(s);
   toupper(s1);
   cout << "Translated to upper case: \"" << s1 << "\"\n";

   cout << "\ncat_dot test\n";
   char str1[] = "bonjour";
   char str2[] = "olam";
   // use default separator
   cout << "cat_dot(\"" << str1 << "\", \"" << str2 << "\") is \""
        << cat_dot(str1, str2) << "\"\n";
   // use new separator
   char newsep[] = "#!?"; 
   cout << "cat_dot(\"" << str1 << "\", \"" << str2 << "\", " 
        << newsep << "\") is \""
        << cat_dot(str1, str2, newsep) << "\"\n";

   cout << "\nPalindrome test:\n";
   cout << "Enter palindrome candidates (one per line).\n"
      "End-of-file (control-D) terminates input (and program).\n";
   while (true) {
      const char* pal_cand = get_c_string();
      if (!cin)
         break;
      cout << "\"" << pal_cand << "\" is " ;
      if (!is_palindrome(pal_cand)) cout << "not ";
      cout << "a palindrome.\n";
   }
}

// returns the length of a C-string 
int strlen(const char *s)
{
   int len = 0;
   while (s[len] != 0)
      len++;
   return len;
}

// read a line of input, store in a C string
// not exactly in the spirit of C :-)
// suffers from a memory leak
const char* get_c_string()
{
   string str;
   getline(cin, str);
   const char* s = str.c_str();         // memory leak!
   return s;
}

// STUB VERSION
bool islower(char c)
{
   return true;
}

// STUB VERSION
char toupper(char c)
{
   return c;
}

// STUB VERSION
void toupper(char* s)
{
}

// STUB VERSION
char* strdup(const char* s)
{
   char *p = new char[1];
   *p = 0;
   return p;
}

// STUB VERSION
char* cat_dot(const char *s1, const char* s2, const char* sep)
{
   char *p = new char[1];
   *p = 0;
   return p;
}

// STUB VERSION
char* reverse(const char* s)
{
   char *p = new char[1];
   *p = 0;
   return p;
}

// STUB VERSION
bool equal(const char* s1, const char* s2)
{
   return true;
}

// STUB VERSION
bool is_palindrome(const char* s)
{
   return true;
}
