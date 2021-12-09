#include "frame_processor.hpp"

FrameProcessor::FrameProcessor(std::atomic_bool &isStop) : _isStop{isStop}
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

    return tmpMat;
}

void FrameProcessor::WorkFunc()
{
    static std::size_t i = 0;
    cv::Mat frame;

    while (!_isStop)
    {
        while (ThreadQueue::Pop(frame) && !_isStop)
        {
            if  (i % 3 == 0)
            {
                std::cout << i << std::endl;
                cv::imwrite("frame_"+ std::to_string(i) + ".jpg", frame, { cv::IMWRITE_JPEG_QUALITY, 60 });
            }
            i++;
        }
    }

    std::cout << "Stop FrameProcessor..." << std::endl;
}

void FrameProcessor::Run()
{
    _workerThread = std::thread(&FrameProcessor::WorkFunc, this);
}