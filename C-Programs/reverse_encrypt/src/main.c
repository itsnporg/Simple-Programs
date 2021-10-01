/*
 * Author      : Prajwal Chapagain <prajjwal2058@gmail.com>
 * Date        : Sunday Aug 15, 2021 17:06:08 NPT
 * License     : MIT
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define KEY 50
#define MIN_RANGE 33
#define MAX_RANGE 122

void swap_letters(char *restrict msg, size_t msg_len)
{
    // end index to swap with first index
    size_t end_idx = msg_len - 1;
    for (size_t i = 0; i < end_idx; i++) {
        msg[i] ^= msg[end_idx];
        msg[end_idx] ^= msg[i];
        msg[i] ^= msg[end_idx];

        end_idx--;
    }
}

static bool is_empty_msg(size_t msg_len)
{
    if (msg_len > 0) {
        return false;
    }
    fprintf(stderr, "Message is empty\n");
    return true;
}

void reverse_msg(char *restrict msg, size_t msg_len)
{
    if (is_empty_msg(msg_len)) return;
    for (size_t i = 0; i < msg_len - 1; i++) {
        msg[i] = (msg[i] + KEY) % MAX_RANGE + MIN_RANGE;
    }
    swap_letters(msg, msg_len);
    printf("%s\n", msg);
}

void orginal_msg(char *restrict msg, size_t msg_len)
{
    if (is_empty_msg(msg_len)) return;
    swap_letters(msg, msg_len);
    for (size_t i = 0; i < msg_len - 1; i++) {
        msg[i] = (msg[i] - KEY - MIN_RANGE + MAX_RANGE) % MAX_RANGE;
    }
    printf("%s\n", msg);
}

static inline void display_usage(FILE *stream)
{
    fprintf(stream,
            "Usage: ./reverse_reverse [option] <msg>\n"
            "Options:\n"
            "  -o \t\tconverts orginal to reverse\n"
            "  -r \t\tconverts reverse to orginal\n");
}

int main(int argc, char **argv)
{
    int opt_ch = 0;
    bool is_opt_args = false;

    // don't show pre-defined error message when option arg is not provided
    opterr = 0;
    while ((opt_ch = getopt(argc, argv, "o:r:h")) != -1) {
        switch (opt_ch) {
            case 'o':
                is_opt_args = true;
                reverse_msg(optarg, strlen(optarg));
                break;
            case 'r':
                is_opt_args = true;
                orginal_msg(optarg, strlen(optarg));
                break;
            case 'h':
                is_opt_args = true;
                display_usage(stdout);
                break;
            case '?':
                is_opt_args = true;
                if (optopt == 'o' || optopt == 'r')
                    fprintf(stderr, "Message is not provided\n");
                else
                    fprintf(stderr, "Unknown option '-%c'\n", optopt);
                printf("\n");
                display_usage(stderr);
                exit(EXIT_FAILURE);
            default:
                break;
        }
    }

    if (!is_opt_args) {
        display_usage(stderr);
        exit(EXIT_FAILURE);
    }
    return 0;
}

