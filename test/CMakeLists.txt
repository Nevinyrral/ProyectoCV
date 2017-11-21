## =======================
## = Programs to compile =
## =======================

SET( CMAKE_CXX_STANDARD 11 )
SET( CMAKE_BUILD_TYPE Debug )
ADD_EXECUTABLE( camera_capture_module camera_capture_module.cxx )
TARGET_LINK_LIBRARIES( camera_capture_module LINK_PUBLIC ${OpenCV_LIBS} Label )
