#include "manager.hpp"

Manager::Manager(const std::string &devicePath, Grabber::EDeviceType deviceType)
    : _grabberPtr{std::make_unique<Grabber>(devicePath, deviceType)},
      _frameProcessorPtr{std::make_unique<FrameProcessor>()}
{
}

void Manager::Run()
{
    _grabberPtr->Open();
    _grabberPtr->Run();
    _frameProcessorPtr->Run();
}
