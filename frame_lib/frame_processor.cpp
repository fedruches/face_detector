#include "frame_processor.h"

FrameProcessor::FrameProcessor()
{

}

cv::Mat FrameProcessor::Process(const cv::Mat &frame)
{
    std::cout << frame.type() << std::endl;

    auto tmpMat = frame.clone();

    std::cout << tmpMat.type() << std::endl;

    cv::bitwise_not(frame, tmpMat);

    return frame;
}
