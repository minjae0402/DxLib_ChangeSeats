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

void SeatChange_Next_2() {
    int box_width = 100;
    int box_height = 50;
    int margin = 10;
    int rows = 4;
    int cols = 5;
    int initial_x = 50;
    int initial_y = 140;

    int index = 0;
    for (int c = 0; c < cols; c++) {
        for (int r = 0; r < rows; r++) {
            if (index < num_names) {
                int x = initial_x + c * (box_width + margin);
                int y = initial_y + r * (box_height + margin);

                bool is_fixed = false;
                for (int i = 0; i < num_fixed_seats; i++) {
                    if (fixed_seats[i] == index + 1) {
                        is_fixed = true;
                        break;
                    }
                }

                if (is_fixed) {
                    DrawBox(x, y, x + box_width, y + box_height, GetColor(110, 110, 0), TRUE);
                }
                else {
                    DrawBox(x, y, x + box_width, y + box_height, GetColor(230, 230, 230), TRUE);
                }
                DrawString(x + 5, y + 5, names[index], GetColor(0, 0, 0));

                index++;
            }
            else {
                break;
            }
        }
    }

    int sunrin_icon;
    int icon_w = 50;
    int icon_h = 50;
    int icon_x = 30;
    int icon_y = 50;

    sunrin_icon = LoadGraph("sunrin.png");
    DrawExtendGraph(icon_x, icon_y, icon_x + icon_w, icon_y + icon_h, sunrin_icon, TRUE);

    int largeFontHandle = CreateFontToHandle(NULL, 20, -1, DX_FONTTYPE_NORMAL);
    DrawStringToHandle(100, 70, "<최종>", GetColor(0, 0, 0), largeFontHandle);
    DeleteFontToHandle(largeFontHandle);

    DrawString(110, 100, "(자리바꾸기를 진행하려면 스페이스바를 누르세요!)", GetColor(0, 0, 0));

    DrawString(30, 430, "< 전으로 돌아가기", GetColor(0, 0, 0));
}

void SeatChange_Next_2_Update() {

}

