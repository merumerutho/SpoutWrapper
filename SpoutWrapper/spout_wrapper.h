// spout_wrapper.h - Header file for the wrapper DLL

#ifndef SPOUT_WRAPPER_H
#define SPOUT_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

	__declspec(dllexport) void SetSenderNameWrapper(const char* senderName);
	__declspec(dllexport) bool SendImageWrapper(const unsigned char* pixels, unsigned int width, unsigned int height, unsigned int format, bool bInvert);
	__declspec(dllexport) bool SendTextureWrapper(unsigned int TextureID, unsigned int TextureTarget, unsigned int width, unsigned int height, bool bInvert, unsigned int HostFBO);
	__declspec(dllexport) bool SendFboWrapper(unsigned int FboID, unsigned int width, unsigned int height, bool bInvert);
	__declspec(dllexport) void SetReceiverNameWrapper(const char* receiverName);
	__declspec(dllexport) bool IsConnectedWrapper();
	__declspec(dllexport) bool IsUpdatedWrapper();
	__declspec(dllexport) bool IsFrameNewWrapper();
	__declspec(dllexport) unsigned int GetSenderWidthWrapper();
	__declspec(dllexport) unsigned int GetSenderHeightWrapper();
	__declspec(dllexport) long GetSenderFrameWrapper();
	__declspec(dllexport) const char* GetSenderNameWrapper();
	__declspec(dllexport) bool ReceiveImageWrapper(unsigned char* pixels, unsigned int format, bool bInvert, unsigned int hostFbo);

#ifdef __cplusplus
}
#endif

#endif // SPOUT_WRAPPER_H
