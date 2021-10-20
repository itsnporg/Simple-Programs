#include <stdio.h>
#include <string.h>
#include "frequency.h"

// white notes
static const int c3[7] = { 122, 120, 99, 118, 98, 110, 109 };
static const int c4[7] = { 113, 119, 101, 114, 116, 121, 117 };
static const int c5[5] = { 105, 111, 112, 91, 93 };

// back notes
static const int c3f[5] = { 115, 100, 103, 104, 106 };
static const int c4f[5] = { 50, 51, 53, 54, 55 };
static const int c5f[3] = { 57, 48, 61 };

static const char wnotes[7][3] = { "C", "D", "E", "F", "G", "A", "B" };
static const char bnotes[5][3] = { "C#", "D#", "F#", "G#", "A#" };

static int has(int num, const int nums[], int len) {
    for (int i = 0; i < len; i++) {
        if (nums[i] == num) return 1;
    }
    return 0;
}

static int indexOf(const int arr[], int findIndex, int len) {
    for (int i = 0; i < len; i++) {
        if (arr[i] == findIndex) return i;
    }

    return -1;
}

static float constructFrequency(const float node, const char * note) {
    if (!strcmp(note, "C"))
        return node * 0.5946f;
    else if (!strcmp(note, "C#"))
        return node * 0.6299f;
    else if (!strcmp(note, "D"))
        return node * 0.6674f;
    else if (!strcmp(note, "D#"))
        return node * 0.7071f;
    else if (!strcmp(note, "E"))
        return node * 0.7491f;
    else if (!strcmp(note, "F"))
        return node * 0.7937f;
    else if (!strcmp(note, "F#"))
        return node * 0.8408f;
    else if (!strcmp(note, "G"))
        return node * 0.8908f;
    else if (!strcmp(note, "G#"))
        return node * 0.9438f;
    else if (!strcmp(note, "A"))
        return node;
    else if (!strcmp(note, "A#"))
        return node * 1.0594f;
    else if (!strcmp(note, "B"))
        return node * 1.1224f;
    else
        return 0;
}

float getFrequency(int keycode) {
    float frequency = 0.0f;

    // black
    if (has(keycode, c3f, 5)) {
        int idx = indexOf(c3f, keycode, 5);

        frequency = constructFrequency(220.0f, bnotes[idx]);
    } else if (has(keycode, c4f, 5)) {
        int idx = indexOf(c4f, keycode, 5);

        frequency = constructFrequency(440.0f, bnotes[idx]);
    } else if (has(keycode, c5f, 3)) {
        int idx = indexOf(c5f, keycode, 3);

        frequency = constructFrequency(880.0f, bnotes[idx]);
    }

    // white
    else if (has(keycode, c3, 7)) {
        int idx = indexOf(c3, keycode, 7);

        frequency = constructFrequency(220.0f, wnotes[idx]);
    } else if (has(keycode, c4, 7)) {
        int idx = indexOf(c4, keycode, 7);

        frequency = constructFrequency(440.0f, wnotes[idx]);
    } else if (has(keycode, c5, 5)) {
        int idx = indexOf(c5, keycode, 5);

        frequency = constructFrequency(880.0f, wnotes[idx]);
    }
    
    return frequency;
}
