#include <stdio.h>
#include <stdbool.h>

#define EOS ('\0')
#define SPACE (32)

void remove_multiple_spaces(char * my_string)
{
    if(my_string) {

    char * current = my_string;
    char * next = current++;
    char * head = next;

    bool flag_multiple_spaces = 0;

    while(*next != EOS) {

        if(*current == SPACE && *next == SPACE) {
            next++;  current++;

            if(!flag_multiple_spaces)
                *head = SPACE;

            flag_multiple_spaces = 1;
        }
        else {
            flag_multiple_spaces = 0;
            current++;  
            *head++ = *next++;
        }
    }
    /* Terminate the sentence */
    *head = EOS;
   }
}

int get_total_words(const char * my_string)
{
    int count = 0;

    if(my_string) {

        count++;
        while(*my_string++ != EOS)
            if(*my_string == SPACE)
                count++;
    }
    return count;
}


char * get_string_end(const char * my_string)
{
    const char * c = NULL;

    if(my_string) {

        c = my_string;
        while(*c++ != EOS);
        /* Point to element just before string terminator */
        c -= 2;
    }
    return (char *) c;
}

void reverse_string(char * start, char * end)
{
    if(start && end) {

        char c;
        while(start < end) {
    
            c = *start;
            *start++ = *end;
            *end-- = c;
        }
    }  
}

void reverse_sentence(char * input_string)
{
    if(input_string) {

        remove_multiple_spaces(input_string);
    
        char * string_start = input_string;
        char * string_end = get_string_end(input_string);
        reverse_string(string_start, string_end);

        int words = get_total_words(input_string);

        while(words--) {

            string_end = string_start;

            while(*string_end != SPACE && *string_end != EOS)
                string_end++;
            /* Point to element just before a space or a string terminator */
            string_end--;
        
            reverse_string(string_start, string_end);
            string_start = string_end + 2;  
        }
    }
}

int main(void)
{
    char input1[] = "I love pizza";
    reverse_sentence(input1);
    printf("%s\n", input1); 

    char input2[] = "I am a good  coder";
    reverse_sentence(input2);
    printf("%s\n", input2); 

    return 0;
}
