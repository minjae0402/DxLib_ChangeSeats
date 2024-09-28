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

//60 프레임이 1초임
int images[3];
int sounds[4];
int currentImage = 0;
int frameCount = 0;
int maxFrames = 60;

int bgm;

void mainAnime() {
    images[0] = LoadGraph("Balloon3.png");
    images[1] = LoadGraph("Balloon2.png");
    images[2] = LoadGraph("Balloon1.png");

    sounds[0] = LoadSoundMem("ing-sen.mp3");
    sounds[1] = LoadSoundMem("ing-sen.mp3");
    sounds[2] = LoadSoundMem("ing-sen.mp3");
    sounds[3] = LoadSoundMem("end.mp3");

    bgm = LoadSoundMem("ing.mp3");
    PlaySoundMem(bgm, DX_PLAYTYPE_LOOP);

    int screenWidth, screenHeight;
    GetDrawScreenSize(&screenWidth, &screenHeight);

    while (ProcessMessage() == 0 && currentImage < 3) {
        ClearDrawScreen();

        int imgWidth = 640;
        int imgHeight = 480;
        int posX = (screenWidth - imgWidth) / 2;
        int posY = (screenHeight - imgHeight) / 2;

        DrawExtendGraph(posX, posY, posX + imgWidth, posY + imgHeight, images[currentImage], FALSE);

        ScreenFlip();

        frameCount++;

        if (frameCount >= maxFrames) {
            frameCount = 0;
            PlaySoundMem(sounds[currentImage], DX_PLAYTYPE_BACK);
            currentImage++;
        }

        Sleep(16);
    }
    /*
    PlaySoundMem(sounds[3], DX_PLAYTYPE_BACK);
    Sleep(120);
    */
    for (int i = 0; i < 3; i++) {
        DeleteGraph(images[i]);
        DeleteSoundMem(sounds[i]);
        //DeleteSoundMem(sounds[3]);
    }
    StopSoundMem(bgm);
    DeleteSoundMem(bgm);


    ClearDrawScreen();
    End();
}


void mainAnime_Update() {
    if (frameCount >= maxFrames) {
        frameCount = 0;
        currentImage++;
        if (currentImage >= 3) {
            currentImage = 0;
        }
        DrawGraph(0, 0, images[currentImage], FALSE);
        PlaySoundMem(sounds[currentImage], DX_PLAYTYPE_BACK);
    }
}
