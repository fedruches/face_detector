#include "grabber.h"

Grabber::Grabber(const std::string &devicePath, EDeviceType deviceType) :
    _capturePtr{std::make_unique<cv::VideoCapture>()}, _devicePath{devicePath}
{
    _capturePtr->setExceptionMode(true);
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

//    m_frameWidth = static_cast<int>(m_cap.get(cv::CAP_PROP_FRAME_WIDTH));
//    m_frameHeight = static_cast<int>(m_cap.get(cv::CAP_PROP_FRAME_HEIGHT));
//    m_fps = static_cast<int>(m_cap.get(cv::CAP_PROP_FPS));

//    _capturePtr->grab();
    bool isGrab = _capturePtr->read(grabbedFrame);

    return { isGrab, grabbedFrame };
}
