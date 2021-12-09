#include "manager.hpp"

Manager::Manager(const std::string &devicePath, Grabber::EDeviceType deviceType)
    : _grabberPtr{std::make_unique<Grabber>(devicePath, deviceType, _isStop)},
      _frameProcessorPtr{std::make_unique<FrameProcessor>(_isStop)}
{
}

Manager::~Manager()
{
    _isStop = true;
}

void Manager::Run()
{
    _grabberPtr->Open();
    _grabberPtr->Run();
    _frameProcessorPtr->Run();
}

void Manager::Stop()
{
    std::cout << "Stop from Manager!" << std::endl;
    _isStop = true;
}


