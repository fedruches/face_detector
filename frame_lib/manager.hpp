#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <memory>

#include "grabber.hpp"
#include "frame_processor.hpp"

class Manager
{
public:
    Manager(const std::string &devicePath, Grabber::EDeviceType deviceType);

    void Run();

private:
    std::unique_ptr<Grabber> _grabberPtr;

    std::unique_ptr<FrameProcessor> _frameProcessorPtr;
};

#endif // MANAGER_H
