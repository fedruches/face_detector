#include <iostream>

#include "grabber.hpp"
#include "frame_processor.hpp"
#include "manager.hpp"

using namespace std;

boost::lockfree::spsc_queue<cv::Mat, boost::lockfree::capacity<1024>> ThreadQueue::_spscQueue{};

int main()
{
    Manager manager("/home/fedor/Downloads/mixkit-happy-smiling-girl-4689.mp4", Grabber::EDeviceType::file);

    manager.Run();

    std::this_thread::sleep_for(std::chrono::seconds(50));

    manager.Stop();

    return 0;
}
