#include "src/AudioEngine.h"
#include <chrono>
using namespace std::chrono;

int main()
{
	AudioEngine* engine = new AudioEngine;
	//Sound* sound = engine->LoadData("res/NotGivingUp.ogg");
	Sound* sound = AudioEngine::Get().LoadData("res/NotGivingUp.ogg");
	AudioEngine::Get().Play2D(sound, 0);
	auto t1 = high_resolution_clock::now();
	while (true)
	{
		auto t2 = high_resolution_clock::now();
		double time = 0.000001 * (time_point_cast<microseconds>(t2).time_since_epoch().count() - time_point_cast<microseconds>(t1).time_since_epoch().count());
		AudioEngine::Get().Update3D(sound, 0, {(float)cos(time) * 10.0f, 0, (float)sin(time) * 10.0f});
	}

	return 0;
}