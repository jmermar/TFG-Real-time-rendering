#pragma once
#include <iostream>
using namespace std;
class Profiler {
public:
    struct Metric {
        float min, max, average;
    };
private:
    Profiler();
    ~Profiler();

    Metric fps;
    Metric raster;

    uint32_t fpsTicks;
    uint32_t rasterTicks;
public:
    static Profiler& get();

    void printResults();

    void startFPSMeasure();
    float endFPSMeasure();
    Metric getFPSMeasure();

    void startRasterMeasure();
    float endRasterMeasure();
    Metric getRasterMeasure();
};