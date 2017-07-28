#ifndef ANDROID_AUDIO_MTK_LOSSLESS_BT_BROADCAST_H
#define ANDROID_AUDIO_MTK_LOSSLESS_BT_BROADCAST_H

#include <utils/Log.h>
#include "AudioFlinger.h"

#define LOSSLESS_BT_PROP_NAME "persist.af.losslessbt.on"

#define BroadcastLLUI()  do{ \
        ALOGD("LosslessBT BroadcastLLUI 1");\
        mLLBroadcastMutex.lock(); \
        ALOGD("LosslessBT BroadcastLLUI 2 %d", android_atomic_inc(&mIsLosslessBTVaild));\
        mLLWaitWorkCV.signal(); \
        ALOGD("LosslessBT BroadcastLLUI 3");\
        mLLBroadcastMutex.unlock(); \
        ALOGD("LosslessBT BroadcastLLUI 4");\
    }while(0);

#define SetLosslessBTPlaying(x) do{ \
        mIsLosslessBTPlaying = x; \
        ALOGD("SetLosslessBTPlaying() = %d", mIsLosslessBTPlaying); \
    	BroadcastLLUI(); \
    }while(0);

#define SetLosslessBTStatus(x) do{ \
       mIsLosslessBTOn = x; \
       ALOGD("SetLosslessBTStatus() = %d", mIsLosslessBTOn); \
       property_set(LOSSLESS_BT_PROP_NAME, x ? "1" : "0"); \
       BroadcastLLUI(); \
    }while(0);

#define SetLosslessBTSupport(x) do{ \
       mIsLosslessBTSupport = x; \
       ALOGD("SetLosslessBTSupport() = %d", mIsLosslessBTSupport); \
       BroadcastLLUI(); \
    }while(0);

#define SetLosslessBTVolumeStatus(x) do{ \
       mIsLosslessBTVolumeSatisfied = x; \
       ALOGD("SetLosslessBTVolumeStatus() = %d", mIsLosslessBTVolumeSatisfied); \
       BroadcastLLUI(); \
    }while(0);

#define SetLosslessBTAbsoluteVolume(x) do{ \
       mIsLosslessBTAbsoluteVolume = x; \
       ALOGD("SetLosslessBTAbsoluteVolume() = %d", mIsLosslessBTAbsoluteVolume); \
       BroadcastLLUI(); \
    }while(0);

/*    
#define NotifyLosslessBTStatus()  do{ \
    ALOGD("NotifyLosslessBTStatus exec(%s)", mIsLosslessBTOn ? LOSSLESS_BT_UI_CMD_STOP : LOSSLESS_BT_UI_CMD_OFF); \
    ALOGD("NotifyLosslessBTStatus exec=%d", system(mIsLosslessBTOn ? LOSSLESS_BT_UI_CMD_STOP : LOSSLESS_BT_UI_CMD_OFF)); \
}while(0);

ALOGD("NotifyLosslessBTPlaying exec(%s)", \
        !mIsLosslessBTOn ? LOSSLESS_BT_UI_CMD_OFF: \
            (mIsLosslessBTPlaying ? LOSSLESS_BT_UI_CMD_ON : LOSSLESS_BT_UI_CMD_STOP)); \
ALOGD("NotifyLosslessBTPlaying exec=%d", \
        system(!mIsLosslessBTOn ? LOSSLESS_BT_UI_CMD_OFF: \
            (mIsLosslessBTPlaying ? LOSSLESS_BT_UI_CMD_ON : LOSSLESS_BT_UI_CMD_STOP))); \
*/
namespace android {

// ----------------------------------------------------------------------------
}; // namespace android

#endif // ANDROID_AUDIO_MTK_LOSSLESS_BT_BROADCAST_H
