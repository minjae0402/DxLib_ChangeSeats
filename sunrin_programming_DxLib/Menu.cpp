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

static int m_Key[256];
static int NowSelect = 0;

const int GAME_Y = 240;
const int CONFIG_Y = 270;

enum eMenu {
    eMenu_Seat,
    eMenu_Config,
    eMenu_Num,
};

enum eScene {
    eScene_Seat,
    eScene_Config,
    eScene_Next_1,
    eScene_Next_2,
    eScene_Anime,
    eScene_Num,
};

static int CurrentScene = eScene_Num;

void Keyboard_Update() {
    char tmpKey[256];
    GetHitKeyStateAll(tmpKey);
    for (int i = 0; i < 256; i++) {
        if (tmpKey[i] != 0) {
            m_Key[i]++;
        }
        else {
            m_Key[i] = 0;
        }
    }
}

int Keyboard_Get(int KeyCode) {
    return m_Key[KeyCode];
}

void SceneMgr_ChangeScene(int nextScene) {
    CurrentScene = nextScene;
}

void Menu_Update() {
    if (Keyboard_Get(KEY_INPUT_DOWN) == 1) {
        NowSelect = (NowSelect + 1) % eMenu_Num;
    }
    if (Keyboard_Get(KEY_INPUT_UP) == 1) {
        NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;
    }
    if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {
        switch (NowSelect) {
        case eMenu_Seat:
            SceneMgr_ChangeScene(eScene_Seat);
            break;
        case eMenu_Config:
            SceneMgr_ChangeScene(eScene_Config);
            break;
        }
    }
}

void Menu_Draw() {
    int sunrin_icon;
    int icon_w = 50;
    int icon_h = 50;
    int icon_x = 300;
    int icon_y = 50;
    sunrin_icon = LoadGraph("sunrin.png");
    SetGraphMode(640, 480, 32);
    SetBackgroundColor(255, 255, 255);
    ClearDrawScreen();
    DrawString(180, 150, "    선린고 자리 바꾸기 프로그램", GetColor(0, 0, 0));
    DrawString(180, 170, "위아래 키를 누르고 엔터를 누르십시오.", GetColor(0, 0, 0));
    DrawString(290, GAME_Y, "자리바꾸기", GetColor(0, 0, 0));
    DrawString(290, CONFIG_Y, "설명서", GetColor(0, 0, 0));
    DrawExtendGraph(icon_x, icon_h, icon_x + icon_w, icon_h + icon_h, sunrin_icon, TRUE);
    int y = 0;
    switch (NowSelect) {
    case eMenu_Seat:
        y = GAME_Y;
        break;
    case eMenu_Config:
        y = CONFIG_Y;
        break;
    }
    DrawString(250, y, "■", GetColor(0, 0, 0));

}

void SeatChange_Update_Move() {
    if (Keyboard_Get(KEY_INPUT_LEFT) == 1) {
        SceneMgr_ChangeScene(eScene_Num);
    }
}

void Ins_Update_Move() {
    if (Keyboard_Get(KEY_INPUT_LEFT) == 1) {
        SceneMgr_ChangeScene(eScene_Num);
    }
}

void Next_1_Update_Move() {
    if (Keyboard_Get(KEY_INPUT_LEFT) == 1) {
        SceneMgr_ChangeScene(eScene_Seat);
    }
    if (Keyboard_Get(KEY_INPUT_RIGHT) == 1) {
        SceneMgr_ChangeScene(eScene_Next_2);
    }
}

void SeatChange_Update_Move_next() {
    if (Keyboard_Get(KEY_INPUT_RIGHT) == 1) {
        SceneMgr_ChangeScene(eScene_Next_1);
    }
}

void SeatChange_Update_Move_next_2() {
    if (Keyboard_Get(KEY_INPUT_LEFT) == 1) {
        SceneMgr_ChangeScene(eScene_Next_1);
    }
    if (Keyboard_Get(KEY_INPUT_SPACE) == 1) {
        SceneMgr_ChangeScene(eScene_Anime);
    }
    
}

void End_goHome() {
    if (Keyboard_Get(KEY_INPUT_RIGHT) == 1) {
        DxLib_End();
    }
}


void SceneMgr_Update() {
    switch (CurrentScene) {
    case eScene_Seat:
        SeatChange_Update_Move();
        SeatChange_Update();
        break;
    case eScene_Config:
        Ins_Update_Move();
        Ins_Update();
        break;
    case eScene_Next_1:
        Next_1_Update_Move();
        SeatChange_Next_1_Update();
        break;
    case eScene_Next_2:
        SeatChange_Update_Move_next_2();
        SeatChange_Next_2_Update();
        break;
    case eScene_Anime:
        mainAnime_Update();
        break;
    default:
        Menu_Update();
        break;
    }
}

void SceneMgr_Draw() {
    switch (CurrentScene) {
    case eScene_Seat:
        SeatChange();
        break;
    case eScene_Config:
        Ins();
        break;
    case eScene_Next_1:
        SeatChange_Next_1();
        break;
    case eScene_Next_2:
        SeatChange_Next_2();
        break;
    case eScene_Anime:
        mainAnime();
        break;
    default:
        Menu_Draw();
        break;
    }
}
