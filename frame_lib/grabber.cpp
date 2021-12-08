#include "grabber.hpp"

Grabber::Grabber(const std::string &devicePath, EDeviceType deviceType) :
    _capturePtr{std::make_unique<cv::VideoCapture>()}, _devicePath{devicePath}
{
    _capturePtr->setExceptionMode(true);
}

Grabber::~Grabber()
{
    if (_workerThread.joinable())
        _workerThread.join();
}

Grabber::EOpenStatus Grabber::Open()
{
    try
    {
        _capturePtr->open(_devicePath, cv::CAP_FFMPEG);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return EOpenStatus::error;
    }
    catch (...)
    {
        std::cerr << "Unknown exception" << std::endl;
        return EOpenStatus::error;
    }

    return EOpenStatus::success;
}

std::pair<bool, cv::Mat> Grabber::GetFrame()
{
    cv::Mat grabbedFrame;
    bool isGrab = _capturePtr->read(grabbedFrame);

    return { isGrab, grabbedFrame };
}

void Grabber::WorkFunc()
{
    static int i = 0;

    while (true)
    {
        auto [isGrab, frame] = GetFrame();
        while(!ThreadQueue::Push(frame))

        if (!isGrab)
            return;
    }
}

void Grabber::Run()
{
    _workerThread = std::thread(&Grabber::WorkFunc, this);
}
