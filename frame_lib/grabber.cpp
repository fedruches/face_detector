#include "grabber.hpp"

Grabber::Grabber(const std::string &devicePath, EDeviceType deviceType, std::atomic_bool &isStop) :
    _capturePtr{std::make_unique<cv::VideoCapture>()},
    _devicePath{devicePath},
    _isStop{isStop}
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
    try
    {
        _capturePtr->read(grabbedFrame);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return { false, {} };
    }
    catch (...)
    {
        std::cerr << "Unknown exception" << std::endl;
        return { false, {} };
    }

    return { true, grabbedFrame };
}

void Grabber::WorkFunc()
{
    static int i = 0;

    while (!_isStop)
    {
        auto [isGrab, frame] = GetFrame();
        if (!isGrab || frame.empty())
            break;

        while(!ThreadQueue::Push(frame))
            continue;
    }

    std::cout << "Stop Grabber..." << std::endl;
}

void Grabber::Run()
{
    _workerThread = std::thread(&Grabber::WorkFunc, this);
}