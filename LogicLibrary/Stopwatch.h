//
// Created by elias on 11/12/2022.
//

#ifndef MEATBOY_STOPWATCH_H
#include "chrono"
#include "shared_mutex"
#include <memory>
#define MEATBOY_STOPWATCH_H
using namespace std;

/// singleton class van de stopwatch (constructor is private, en heeft geen copy
/// constructor en heeft een static var)
class Stopwatch {
private:
	static shared_ptr<Stopwatch> stopwatch;
	chrono::time_point<chrono::steady_clock> prevTime;
	float deltaTime;
	float timeMultiplier;
	/// maakt een stopwatch en zet de tijd to the curr time
	Stopwatch();

public:
	Stopwatch(Stopwatch&) = delete;
	void operator=(Stopwatch&) = delete;
	/// returned een shared pointer van de stopwatch terug
	static shared_ptr<Stopwatch> getStopwatch();
	/// berekent het verschil tussen de vorige frame en initaliseerd de nieuwe
	/// frame en prev frame
	void nextFrame();
	/// returned de multiplier waarmee wij de player zijn movement mee
	/// vermenigvuldigen, zodat de player altijd even snel beweegt al heeft de
	/// monitor een snellere hz
	float getTimeMultiplier() const;
};
#endif // MEATBOY_STOPWATCH_H
