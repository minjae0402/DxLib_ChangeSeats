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
    DrawStringToHandle(100, 70, "<설명서>", GetColor(0, 0, 0), largeFontHandle);
    DeleteFontToHandle(largeFontHandle);
    DrawString(40, 120, "개발자 : 선린 10601 강민재", GetColor(0, 0, 0));
    DrawString(40, 180, "파일은 인코팅 ANSI 로 되어있는 파일를 사용해야 한다.", GetColor(0, 0, 0));
    DrawString(40, 210, "화면 상단의 타이틀을 보고 잘 실행해야한다.", GetColor(0, 0, 0));
    DrawString(40, 240, "최대 20명까지 자리변경이가능하다. + 자리의 모양은 바꿀수 없다", GetColor(0, 0, 0));

    DrawString(30, 430, "< 전으로 돌아가기", GetColor(0, 0, 0));
}

void Ins_Update() {

}