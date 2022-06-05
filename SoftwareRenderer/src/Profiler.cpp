#include <Profiler.hpp>

#include <SDL2/SDL.h>
#include <glm/glm.hpp>

Profiler::Profiler() {
    fps.min = INFINITY;
    fps.max = 0;

    raster.min = INFINITY;
    raster.max = 0;
}

Profiler::~Profiler() {

}

Profiler& Profiler::get() {
    static Profiler p;
    return p;
}

void Profiler::printResults() {
    cout << "PROFILER RESULTS" << endl;
    cout << "FPS: min=" << fps.min << " max=" << fps.max << endl;
    cout << "Frame time: min=" <<  1.f / fps.max << " max=" << 1.f / fps.min << endl; 
    cout << "Raster time: min=" << raster.min << " max=" << raster.max << endl;
}

void Profiler::startFPSMeasure() {
    fpsTicks = SDL_GetTicks();
}

float Profiler::endFPSMeasure() {
    float measured = 1000.f / (SDL_GetTicks() - fpsTicks);
    fps.min = glm::min(measured, fps.min);
    fps.max = glm::max(measured, fps.max);

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

    return elapsed;
}

Profiler::Metric Profiler::getRasterMeasure() {
    return raster;
}