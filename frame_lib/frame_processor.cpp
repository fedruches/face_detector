#include "frame_processor.hpp"

FrameProcessor::FrameProcessor()
{
}

FrameProcessor::~FrameProcessor()
{
    if (_workerThread.joinable())
        _workerThread.join();
}

cv::Mat FrameProcessor::Process(const cv::Mat &frame)
{
    auto tmpMat = frame.clone();

    cv::bitwise_not(frame, tmpMat);

    return frame;
}

void FrameProcessor::WorkFunc()
{
    static int i = 0;

    while (true)
    {
        cv::Mat frame;
        while (ThreadQueue::Pop(frame))
        {
            Process(frame);
            cv::imwrite("frame_" + std::to_string(i++) + ".png", frame);
        }
    }
}

void FrameProcessor::Run()
{
    _workerThread = std::thread(&FrameProcessor::WorkFunc, this);
}