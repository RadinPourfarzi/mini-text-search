#include "options.h"
#include <stdio.h>

arg_CO arg_manager = {0, 0, NULL, NULL, 0, 0};

int check_options(char *options);

int read_arguments(int argument_count, char *arguments[])
{
    int i;
    
    arg_manager.conditions = 0;
    arg_manager.options = 0;
    arg_manager.pattern = NULL;
    arg_manager.pattern_file = NULL;
    arg_manager.file_count = 0;
    arg_manager.first_file = 0;

    if(argument_count == 1)
        return -1;
    
    i = 1;
    while(i < argument_count && arguments[i][0] == '-' && !(arg_manager.options & LITERAL_PATTERN)) {
        if((check_options(arguments[i]) & ERROR_O) == ERROR_O)
            return -1;
        arg_manager.conditions |= GIVEN_OPTION;
        i++;
    }
    if(i >= argument_count)
        return -1;
    arg_manager.pattern = arguments[i];
    arg_manager.conditions |= GIVEN_PATTERN;
    i++;
    if(i < argument_count) {
        arg_manager.first_file = i;
        arg_manager.file_count = argument_count - i;
        arg_manager.conditions |= GIVEN_FILES;
    }
    return 0;
}

int check_options(char *options)
{
    char *s;
    
    s = options;

    if(*s++ != '-')
        return (arg_manager.options = 0);
    while(*s != '\0') {
        switch(*s) {
            case 'i':
                arg_manager.options |= IGNORE_CASE;
                break;
            case 'v':
                arg_manager.options |= INVERT_MATCH;
                break;
            case 'n':
                arg_manager.options |= LINE_NUMBERS;
                break;
            case 'c':
                arg_manager.options |= COUNT_MATCHES;
                break;
            case '-':
                arg_manager.options |= LITERAL_PATTERN;
                break;
            default:
                arg_manager.options |= ERROR_O;
                return arg_manager.options;
        }
        s++;
    }
    return arg_manager.options;
}

void read_flags()
{
    printf("\n\t__Conditions Checking__\n");
    if((arg_manager.conditions & GIVEN_PATTERN) == GIVEN_PATTERN)
        printf("Given Pattern__\n");
    if((arg_manager.conditions & GIVEN_OPTION) == GIVEN_OPTION)
        printf("Given Option(s)__\n");
    if((arg_manager.conditions & GIVEN_FILES) == GIVEN_FILES)
        printf("Given File(s)__\n");

    printf("\n\t__Options Checking__\n");
    if((arg_manager.options & IGNORE_CASE) == IGNORE_CASE)
        printf("__Ignore Case\n");
    if((arg_manager.options & INVERT_MATCH) == INVERT_MATCH)
        printf("__Invert Match\n");
    if((arg_manager.options & LINE_NUMBERS) == LINE_NUMBERS)
        printf("__Line Numbers\n");
    if((arg_manager.options & COUNT_MATCHES) == COUNT_MATCHES)
        printf("__Count Matches\n");
    if((arg_manager.options & LITERAL_PATTERN) == LITERAL_PATTERN)
        printf("__Literal Pattern\n");   
}