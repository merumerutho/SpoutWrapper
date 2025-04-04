// spout_wrapper.c - Implementation file for the wrapper DLL

#include "spout_wrapper.h"
#include <windows.h>
#include "SpoutLibrary.h"

// Function pointers
static HMODULE hSpoutDLL = NULL;
static SPOUTHANDLE spout = NULL;

// Load the Spout DLL and initialize function pointers
bool LoadSpoutDLL() {
    if (hSpoutDLL) return true; // Already loaded
    hSpoutDLL = LoadLibraryA("SpoutLibrary.dll");
    if (!hSpoutDLL) return false;

    spout = (SPOUTHANDLE)GetProcAddress(hSpoutDLL, "GetSpout")();

    if (!spout) return false;

    return true;
}

__declspec(dllexport) void SetSenderNameWrapper(const char* senderName) {
    if (spout) spout->SetSenderName(senderName);
}

__declspec(dllexport) bool SendImageWrapper(const unsigned char* pixels, unsigned int width, unsigned int height, unsigned int format, bool bInvert) {
    return (spout) && spout->SendImage(pixels, width, height, format, bInvert);
}

__declspec(dllexport) bool SendFboWrapper(unsigned int FboID, unsigned int width, unsigned int height, bool bInvert) {
    return (spout) && spout->SendFbo(FboID, width, height, bInvert);
}

__declspec(dllexport) bool SendTextureWrapper(unsigned int TextureID, unsigned int TextureTarget, unsigned int width, unsigned int height, bool bInvert, unsigned int HostFBO) {
    return (spout) && spout->SendTexture(TextureID, TextureTarget, width, height, bInvert, HostFBO);
}

__declspec(dllexport) void SetReceiverNameWrapper(const char* receiverName) {
    if (spout) spout->SetReceiverName(receiverName);
}

__declspec(dllexport) bool IsConnectedWrapper() {
    return (spout) && spout->IsConnected();
}

__declspec(dllexport) bool IsUpdatedWrapper() {
    return (spout) && spout->IsUpdated();
}

__declspec(dllexport) bool IsFrameNewWrapper() {
    return (spout) && spout->IsFrameNew();
}

__declspec(dllexport) unsigned int GetSenderWidthWrapper() {
    return (spout) ? spout->GetSenderWidth() : 0;
}

__declspec(dllexport) unsigned int GetSenderHeightWrapper() {
    return (spout) ? spout->GetSenderHeight() : 0;
}

__declspec(dllexport) long GetSenderFrameWrapper() {
    return (spout) ? spout->GetSenderFrame() : -1;
}

__declspec(dllexport) const char* GetSenderNameWrapper() {
    return (spout) ? spout->GetSenderName() : "";
}

__declspec(dllexport) bool ReceiveImageWrapper(unsigned char* pixels, unsigned int format, bool bInvert, unsigned int hostFbo) {
    return (spout) && spout->ReceiveImage(pixels, format, bInvert, hostFbo);
}

// Ensure Spout DLL is unloaded when the DLL is unloaded
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved) {
    switch (fdwReason) {
    case DLL_PROCESS_ATTACH:
        LoadSpoutDLL();
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
