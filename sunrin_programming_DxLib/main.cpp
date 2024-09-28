
//*******************************************************************
/*
개발자 : 강민재
프로그래밍 1학년 1학기 수행 프로젝트
자유주제 : 선린 자리바꾸기 프로그램 
DxLib활용 개발.
*/
//*******************************************************************

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

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE);
    DxLib_Init();
    SetDrawScreen(DX_SCREEN_BACK);

    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
        Keyboard_Update();
        SceneMgr_Update();
        SceneMgr_Draw();
    }

    DxLib_End();
    return 0;
}