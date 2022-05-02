# Audio engine

Audio system written in C++.
Library is built on top of [XAudio2](https://docs.microsoft.com/en-us/windows/win32/xaudio2/xaudio2-introduction) and [X3DAudio](https://docs.microsoft.com/en-us/windows/win32/xaudio2/x3daudio-overview).

## Currently Supports
- .wav
- .ogg
- .mp3
- 3D spatial playback

## How to use
```cpp
// Initialize the audio engine
AudioEngine* engine = new AudioEngine;
// Load audio source from file
// Can be loaded in 2 ways
Sound* sound1 = engine->LoadData("res/NotGivingUp.ogg");
Sound* sound2 = AudioEngine::Get().LoadData("res/NotGivingUp.ogg");
// Play audio source 2D
// 0 represents channels;
// channels can have different volumes
AudioEngine::Get().Play2D(sound1, 0);
//Play audio source 3D
AudioEngine::Get().Play3D(sound2, 0, {0, 0, 10});
//Update position
//Position can also be set on 2D sources
AudioEngine::Get().Update3D(sound2, 0, {0, 0, -10});
```
some other functionality
```cpp
AudioEngine::Get().Stop(sound1);
//Set volume on desired channel
AudioEngine::Get().SetVolume(0.8f, 0);
//Set master volume
AudioEngine::Get().SetMasterVolume(0.6f, 0);
```

Simple example of rotating sound
(Use headphones for better experience)

```cpp
#include "src/AudioEngine.h"
#include <chrono>
using namespace std::chrono;

int main()
{
    AudioEngine* engine = new AudioEngine;
    //Sound* sound = engine->LoadData("res/NotGivingUp.ogg");
    Sound* sound = AudioEngine::Get().LoadData("res/NotGivingUp.ogg");
    AudioEngine::Get().Play3D(sound, 0, {0, 0, 10});

    auto t1 = high_resolution_clock::now();
    while (true)
    {
        auto t2 = high_resolution_clock::now();
        double time = 0.000001 * (time_point_cast<microseconds>(t2).time_since_epoch().count() - time_point_cast<microseconds>(t1).time_since_epoch().count());
        AudioEngine::Get().Update3D(sound, 0, {(float)cos(time) * 10.0f, 0, (float)sin(time) * 10.0f});
    }
    return 0;
}
```

## 3rd party software
- [XAudio2](https://docs.microsoft.com/en-us/windows/win32/xaudio2/xaudio2-introduction)
- [X3DAudio](https://docs.microsoft.com/en-us/windows/win32/xaudio2/x3daudio-overview)
- [minimp3](https://github.com/lieff/minimp3)
- [stb_vorbis](https://github.com/nothings/stb/blob/master/stb_vorbis.c)


