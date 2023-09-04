#include <opencv2/opencv.hpp>

int main() {
    // Initialize webcam capture
    cv::VideoCapture cap(0); // 0 represents the default camera

    // Check if the webcam is opened successfully
    if (!cap.isOpened()) {
        std::cerr << "Error: Unable to access the webcam." << std::endl;
        return -1;
    }

    cv::Mat frame;

    while (true) {
        // Read a frame from the webcam
        cap.read(frame);

        if (frame.empty()) {
            std::cerr << "Error: Webcam frame is empty." << std::endl;
            break;
        }

        // Process the frame here (e.g., display, manipulate, analyze)

        cv::imshow("Webcam", frame); // Display the frame

        // Break the loop if the user presses the 'q' key
        if (cv::waitKey(1) == 'q') {
            break;
        }
    }

    // Release the webcam and close the display window
    cap.release();
    cv::destroyAllWindows();

    return 0;
}

/*
cmake_minimum_required(VERSION 3.5.0)
project(opencvtest VERSION 0.1.0)

include(CTest)
enable_testing()

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(opencvtest main.cpp)

target_link_libraries( opencvtest ${OpenCV_LIBS} )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


*/
