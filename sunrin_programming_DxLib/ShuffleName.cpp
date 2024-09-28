#include "DxLib.h"
#include "Menu.h"
#include "SeatChange.h"
#include "Ins.h"
#include "SeatChange_Next_1.h"
#include "SeatChange_Next_2.h"
#include "End.h"
#include "Anime.h"
#include "ShuffleName.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>
#include <time.h>
#include <commdlg.h>
/*
#include "DxUseCLib.h"
#include "DxUseCStr.h"
#include "DxUseCPixel.h"
#include "DxUseSound.h"
#include "DxUseSound.h"
#include "DxUseInputString.h"
#include "DxUseDInput.h"
*/

extern TCHAR names[][256];
extern int num_names;
extern int fixed_seats[];
extern int num_fixed_seats;

bool shuffled = false;
bool IsNameInArray(TCHAR array[][256], int size, TCHAR name[256]);

void ShuffleNames() {
    srand(static_cast<unsigned int>(time(nullptr)));

    TCHAR shuffled_names[256][256];

    TCHAR fixed_names[256][256];
    int num_fixed_names = 0;

    for (int k = 0; k < num_fixed_seats; ++k) {
        int fixed_index = fixed_seats[k] - 1;
        _tcscpy_s(fixed_names[num_fixed_names], 256, names[fixed_index]);
        ++num_fixed_names;
    }

    int shuffled_index = 0;
    for (int i = 0; i < num_names; ++i) {
        bool is_fixed = false;
        for (int k = 0; k < num_fixed_seats; ++k) {
            if (fixed_seats[k] == i + 1) {
                is_fixed = true;
                break;
            }
        }

        if (!is_fixed) {
            do {
                int j = rand() % num_names;
                _tcscpy_s(shuffled_names[shuffled_index], 256, names[j]);
            } while (IsNameInArray(shuffled_names, shuffled_index, shuffled_names[shuffled_index]) || IsNameInArray(fixed_names, num_fixed_names, shuffled_names[shuffled_index]));

            ++shuffled_index;
        }
    }

    shuffled_index = 0;
    for (int i = 0; i < num_names; ++i) {
        bool is_fixed = false;
        for (int k = 0; k < num_fixed_seats; ++k) {
            if (fixed_seats[k] == i + 1) {
                is_fixed = true;
                break;
            }
        }

        if (!is_fixed) {
            _tcscpy_s(names[i], 256, shuffled_names[shuffled_index]);
            ++shuffled_index;
        }
    }

    shuffled = true;
}

bool IsNameInArray(TCHAR array[][256], int size, TCHAR name[256]) {
    for (int i = 0; i < size; ++i) {
        if (_tcscmp(array[i], name) == 0) {
            return true;
        }
    }
    return false;
}
