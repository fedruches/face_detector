#include <iostream>

#include "grabber.h"
#include "frame_processor.h"

using namespace std;

int main()
{

    Grabber grabber("/home/fedor/Downloads/mixkit-happy-smiling-girl-4689.mp4", Grabber::EDeviceType::file);

    FrameProcessor frameProcessor;

    if (grabber.Open() != Grabber::EOpenStatus::success)
        return 1;

    while(true)
    {
        auto [isGrab, frame] = grabber.GetFrame();
        if (!isGrab)
            break;

        auto processedFrame = frameProcessor.Process(frame);
        cv::imshow("Frame", frame);
        cv::waitKey(0);
    }

    return 0;
}
