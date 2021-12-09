#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <memory>
#include <atomic>

#include "grabber.hpp"
#include "frame_processor.hpp"

class Manager
{
public:
    Manager(const std::string &devicePath, Grabber::EDeviceType deviceType);

    ~Manager();

    void Run();

    void Stop();

private:
    std::unique_ptr<Grabber> _grabberPtr;

    std::unique_ptr<FrameProcessor> _frameProcessorPtr;

    std::atomic_bool _isStop = false;
};

#endif // MANAGER_H
