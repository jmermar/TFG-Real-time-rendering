#include <Profiler.hpp>

#include <SDL2/SDL.h>
#include <glm/glm.hpp>

Profiler::Profiler() {
    fps.min = INFINITY;
    fps.max = 0;
    fps.average = -1;

    raster.min = INFINITY;
    raster.max = 0;
    raster.average = -1;
}

Profiler::~Profiler() {

}

Profiler& Profiler::get() {
    static Profiler p;
    return p;
}

void Profiler::printResults() {
    cout << "PROFILER RESULTS" << endl;
    cout << "FPS: min=" << fps.min << " max=" << fps.max << " average=" << fps.average << endl;
    cout << "Frame time: min=" <<  1.f / fps.max << " max=" << 1.f / fps.min << " average=" << 1.f / fps.average << endl;
    cout << "Raster: min=" << raster.min << " max=" << raster.max << " average=" << raster.average << endl;
}

void Profiler::startFPSMeasure() {
    fpsTicks = SDL_GetTicks();
}

float Profiler::endFPSMeasure() {
    float measured = 1000.f / (SDL_GetTicks() - fpsTicks);
    fps.min = glm::min(measured, fps.min);
    fps.max = glm::max(measured, fps.max);

    if (fps.average < 0) fps.average = measured;
    else fps.average = fps.average * 0.9f + measured * 0.1;

    return measured;
}

Profiler::Metric Profiler::getFPSMeasure() {
    return fps;
}

void Profiler::startRasterMeasure() {
    rasterTicks = SDL_GetTicks();
}

float Profiler::endRasterMeasure() {
    float elapsed = (SDL_GetTicks() - rasterTicks) / 1000.f;
    raster.min = glm::min(elapsed, raster.min);
    raster.max = glm::max(elapsed, raster.max);

    if (raster.average < 0) raster.average = elapsed;
    else raster.average = raster.average * 0.9f + elapsed * 0.1;

    return elapsed;
}

Profiler::Metric Profiler::getRasterMeasure() {
    return raster;
}