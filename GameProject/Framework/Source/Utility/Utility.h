#pragma once

namespace fw {

double GetHighPrecisionTime();
double GetHighPrecisionTimeSinceGameStarted();

void OutputMessage(const char* message, ...);
char* LoadCompleteFile(const char* filename, long* length);

}