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

void Ins() {
    int sunrin_icon;
    int icon_w = 50;
    int icon_h = 50;
    int icon_x = 30;
    int icon_y = 10;

    sunrin_icon = LoadGraph("sunrin.png");
    DrawExtendGraph(icon_x, icon_h, icon_x + icon_w, icon_h + icon_h, sunrin_icon, TRUE);

    int largeFontHandle = CreateFontToHandle(NULL, 20, -1, DX_FONTTYPE_NORMAL);
    DrawStringToHandle(100, 70, "<����>", GetColor(0, 0, 0), largeFontHandle);
    DeleteFontToHandle(largeFontHandle);
    DrawString(40, 120, "������ : ���� 10601 ������", GetColor(0, 0, 0));
    DrawString(40, 180, "������ ������ ANSI �� �Ǿ��ִ� ���ϸ� ����ؾ� �Ѵ�.", GetColor(0, 0, 0));
    DrawString(40, 210, "ȭ�� ����� Ÿ��Ʋ�� ���� �� �����ؾ��Ѵ�.", GetColor(0, 0, 0));
    DrawString(40, 240, "�ִ� 20����� �ڸ������̰����ϴ�. + �ڸ��� ����� �ٲܼ� ����", GetColor(0, 0, 0));

    DrawString(30, 430, "< ������ ���ư���", GetColor(0, 0, 0));
}

void Ins_Update() {

}