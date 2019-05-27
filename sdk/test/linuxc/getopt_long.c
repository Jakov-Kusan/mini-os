#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int
main(int argc, char **argv)
{
    int c;
    int digit_optind = 0;
	static struct option long_options[] = {
            {"add",     required_argument, NULL,  0 },
            {"append",  no_argument,       NULL,  0 },
            {"create",  required_argument, NULL, 'c'},
            {0,         0,                 NULL,  0 }
        };
	int option_index = 0;

    while (1) {
        c = getopt_long(argc, argv, "abc:d:",
                 long_options, &option_index);
        if (c == -1)
            break;

        switch (c) {
        case 0:
            printf("option %s", long_options[option_index].name);
            if (optarg)
                printf(" with arg %s", optarg);
            printf("\n");
            break;

        case 'a':
            printf("option a\n");
            break;

        case 'b':
            printf("option b\n");
            break;

        case 'c':
            printf("option c with value '%s'\n", optarg);
            break;

        case 'd':
            printf("option d with value '%s'\n", optarg);
            break;

        case '?':
            break;

        default:
            printf("?? getopt returned character code 0%o ??\n", c);
        }
    }

    if (optind >= argc) {
        fprintf(stderr, "expected non-option argument\n");
        fprintf(stderr, "Usage:%s [-a][-b][-c xxx][-d xxx] [--add xxx][--append][--create xxx] arg\n", argv[0]);
        exit(EXIT_FAILURE);
    } else { /* optind < argc */
        printf("non-option arguments: ");
        while (optind < argc)
            printf("%s ", argv[optind++]);
        printf("\n");
    }

    exit(EXIT_SUCCESS);
}