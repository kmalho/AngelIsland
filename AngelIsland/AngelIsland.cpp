#include "pch.h"
#include <LandTableInfo.h>
#include <SA2ModLoader.h>
#include <ModelInfo.h>

static const void* const Transporter_LoadPtr = (void*)0x0057E4F0;
EntityData1* Transporter_Load(NJS_VECTOR* a1, int a2)
{
    EntityData1* result;
    __asm
    {
        push[a2]
        mov ebx, [a1]
        call Transporter_LoadPtr
        mov result, eax
    }
    return result;
}

void TransporterLoadingDark()
{
    NJS_VECTOR position;
    position.x = 488.816f;
    position.y = 54.061f;
    position.z = -291.467f;
    Transporter_Load(&position, 40959);
}

NJS_VECTOR darkGBASpawn = { 488.816f , 56.061f, -291.467f };

NJS_TEXNAME AngelIslandtex[75];
NJS_TEXLIST IslandTexList = { arrayptrandlength(AngelIslandtex) };

extern "C"

{
    __declspec(dllexport) void Init(const char* path, const HelperFunctions& helperFunctions)
    {

        HMODULE hmodule = GetModuleHandle(__TEXT("Data_DLL_orig"));


        LandTable* AngelTable = (LandTable*)GetProcAddress(hmodule, "objLandTableDark");
        *AngelTable = *(new LandTableInfo(std::string(path) + "\\Levels\\Chao World\\Garden\\Dark\\Angel.sa2blvl"))->getlandtable();
        AngelTable->TextureList = &IslandTexList;
        AngelTable->TextureName = (char*)"AngelTex";

        DataArray(NJS_VECTOR, ChaoSpawn, 0x01366260, 16 * 3);
        ChaoSpawn[32] = { 225.27f, 19.385f, -18.51f };
        ChaoSpawn[33] = { 186.1f, 14.83f, 73.31f };
        ChaoSpawn[34] = { -12.93f, 2.56f, 67.27f };
        ChaoSpawn[35] = { 463.02f, 56.06f, 27.06f };
        ChaoSpawn[36] = { 789.22f, 86.65f, 38.39f };
        ChaoSpawn[37] = { 842.31f, 86.65f, 105.94f };
        ChaoSpawn[38] = { 748.03f, 86.65f, 89.82f };
        ChaoSpawn[39] = { 666.33f, 57.49f, 78.73f };
        ChaoSpawn[40] = { 141.87f, 10.88f, 106.81f };
        ChaoSpawn[41] = { 944.74f, 56.06f, 430.75f };
        ChaoSpawn[42] = { 843.28f, 37.15f, 205.60f };
        ChaoSpawn[43] = { 699.37f, 37.15f, 8.70f };
        ChaoSpawn[44] = { -140.33f, 2.00f, 77.41f };
        ChaoSpawn[45] = { 674.49f, 56.06f, -225.23f };
        ChaoSpawn[46] = { 796.42f, 93.15f, 62.02f };
        ChaoSpawn[47] = { 694.41f, 35.15f, 131.13f };

        DataArray(NJS_VECTOR, TreeLoc, 0x01366B30, 30);
        TreeLoc[17] = { 555.81f, 54.06f, 401.10f };
        TreeLoc[18] = { 441.62f, 54.06f, -234.94f };
        TreeLoc[19] = { 174.31f, 7.61f, -248.66f };
        TreeLoc[20] = { -35.03f, -1.45f, 15.79f };
        TreeLoc[21] = { 1149.25f, 54.06f, -276.87f };
        TreeLoc[22] = { 190.47f, 12.62f, 364.66f };
        TreeLoc[23] = { 8.74f, -1.37f, -7.34f };

        WriteCall((void*)0x0054B914, TransporterLoadingDark);
        WriteData((float**)0x0052B970, &darkGBASpawn.x);
        WriteData((float**)0x0052B978, &darkGBASpawn.y);
        WriteData((float**)0x0052B981, &darkGBASpawn.z);

        NJS_OBJECT* OBJ = (NJS_OBJECT*)0x11C0834;
        *OBJ = *(new ModelInfo(std::string(path) + "\\Location\\OBJModel.sa2mdl"))->getmodel();
    }


    __declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };
}