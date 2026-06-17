#ifndef OPTIONS_H
#define OPTIONS_H

struct argument_conditions_options {
    int options;
    int conditions;
    char *pattern;
    char *pattern_file;
    int first_file;
    int file_count;
};
typedef struct argument_conditions_options arg_CO;

extern arg_CO arg_manager;

enum option_flags {
    IGNORE_CASE     = 01,
    INVERT_MATCH    = 02,
    LINE_NUMBERS    = 04,
    COUNT_MATCHES   = 010,
    LITERAL_PATTERN = 020,
    ERROR_O         = 040
};

enum condition_flags {
    GIVEN_PATTERN   = 01,
    GIVEN_OPTION    = 02,
    GIVEN_FILES     = 04,
    ERROR_C         = 020
};

int read_arguments(int argument_count, char *arguments[]);
void read_flags();

#endif