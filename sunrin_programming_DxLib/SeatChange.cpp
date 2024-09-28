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

#define MAX_NAMES 20

TCHAR names[MAX_NAMES][256];
int num_names = 0;

int ReadNamesFromFile(const char* filename, TCHAR names[][256], int max_names) {
    FILE* file;
    errno_t err = fopen_s(&file, filename, "r");
    if (err != 0) {
        printf("파일 %s 열기 오류\n", filename);
        return 0;
    }

    int count = 0;
    while (count < max_names && fscanf_s(file, "%255s", names[count], (unsigned)_countof(names[count])) == 1) {
        count++;
    }
    fclose(file);
    return count;
}

void DrawCenteredText(int centerX, int y, const TCHAR* text, int fontSize, unsigned int color) {
    int textWidth = GetDrawStringWidth(text, _tcslen(text));
    int x = centerX - textWidth / 2;
    DrawString(x, y, text, color);
}

void SeatChange() {
    int box_width = 100;
    int box_height = 50;
    int margin = 10;
    int rows = 4;
    int cols = 5;
    int initial_x = 50;
    int initial_y = 140;

    int sunrin_icon;
    int icon_w = 50;
    int icon_h = 50;
    int icon_x = 30;
    int icon_y = 30;

    sunrin_icon = LoadGraph("sunrin.png");
    int icon_right = icon_x + icon_w;
    int icon_bottom = icon_y + icon_h;

    DrawExtendGraph(icon_x, icon_y, icon_right, icon_bottom, sunrin_icon, TRUE);

    int topBoxX = 50;
    int topBoxY = 100;
    int topBoxWidth = 540;
    int topBoxHeight = 20;
    DrawBox(topBoxX, topBoxY, topBoxX + topBoxWidth, topBoxY + topBoxHeight, GetColor(200, 200, 200), TRUE);
    DrawCenteredText(topBoxX + topBoxWidth / 2, topBoxY, _T("칠판"), 20, GetColor(0, 0, 0));

    int largeFontHandle = CreateFontToHandle(NULL, 20, -1, DX_FONTTYPE_NORMAL);
    DrawStringToHandle(100, 50, _T("A 키를 눌러 파일 선택"), GetColor(0, 0, 0), largeFontHandle);
    DeleteFontToHandle(largeFontHandle);

    DrawString(30, 430, _T("< 전으로 돌아가기"), 20, GetColor(0, 0, 0));
}

void SeatChange_Update() {
    static bool fileSelected = false;
    static char selectedFile[256];

    if (CheckHitKey(KEY_INPUT_A)) {
        OPENFILENAME ofn;
        memset(&ofn, 0, sizeof(OPENFILENAME));
        ofn.lStructSize = sizeof(OPENFILENAME);
        ofn.lpstrFilter = "Text Files\0*.txt\0All Files\0*.*\0";
        ofn.lpstrFile = selectedFile;
        ofn.lpstrFile[0] = '\0';
        ofn.nMaxFile = sizeof(selectedFile);
        ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;

        if (GetOpenFileName(&ofn)) {
            num_names = ReadNamesFromFile(selectedFile, names, MAX_NAMES);
            fileSelected = true;
        }
    }

    if (fileSelected) {
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

                    DrawBox(x, y, x + box_width, y + box_height, GetColor(200, 200, 200), TRUE);
                    DrawString(x + 5, y + 5, names[index], GetColor(0, 0, 0));

                    index++;
                }
                else {
                    break;
                }
            }
        }
        DrawString(440, 390, _T("(추가 성공(완료))"), 20, GetColor(0, 0, 0));
        DrawString(450, 430, _T("다음으로 넘어가기 >"), 20, GetColor(0, 0, 0));
        SeatChange_Update_Move_next();
    }
}