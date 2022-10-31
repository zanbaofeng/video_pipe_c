
#include "VP.h"

#include "../nodes/vp_file_src_node.h"
#include "../nodes/infers/vp_yunet_face_detector_node.h"
#include "../nodes/infers/vp_sface_feature_encoder_node.h"
#include "../nodes/osd/vp_face_osd_node_v2.h"
#include "../nodes/vp_screen_des_node.h"
#include "../nodes/vp_rtmp_des_node.h"
#include "../nodes/vp_split_node.h"
#include "../nodes/track/vp_sort_track_node.h"

#include "../utils/analysis_board/vp_analysis_board.h"

/*
* sameple for:
* vp_yunet_face_detector_node
* vp_sface_feature_encoder_node
* 
*/

#if MAIN5

/*
int main1() {
    //log init
    // config
    VP_SET_LOG_INCLUDE_THREAD_ID(false);
    VP_SET_LOG_LEVEL(vp_utils::vp_log_level::WARN);
    
    // init
    VP_LOGGER_INIT();
    // create nodes
    auto file_src_0 = std::make_shared<vp_nodes::vp_file_src_node>("file_src_0", 0, "/home/baofengzan/Learning/video_pipe_c/test_model/vp_data/test_video/face.mp4", 0.6);
    auto file_src_1 = std::make_shared<vp_nodes::vp_file_src_node>("file_src_1", 1, "/home/baofengzan/Learning/tensorRT_Pro/workspace/exp/face_tracker.mp4", 0.6);
    
    auto yunet_face_detector_0 = std::make_shared<vp_nodes::vp_yunet_face_detector_node>("yunet_face_detector_0", "/home/baofengzan/Learning/video_pipe_c/test_model/vp_data/models/face/face_detection_yunet_2022mar.onnx");
    auto sface_face_encoder_0 = std::make_shared<vp_nodes::vp_sface_feature_encoder_node>("sface_face_encoder_0", "/home/baofengzan/Learning/video_pipe_c/test_model/vp_data/models/face/face_recognition_sface_2021dec.onnx");

    auto split_node =  std::make_shared<vp_nodes::vp_split_node>("split", true);
    
    auto osd_0 = std::make_shared<vp_nodes::vp_face_osd_node_v2>("osd_0");
    auto screen_des_0 = std::make_shared<vp_nodes::vp_screen_des_node>("screen_des_0", 0);
    
    auto osd_1 = std::make_shared<vp_nodes::vp_face_osd_node_v2>("osd_1");
    auto screen_des_1 = std::make_shared<vp_nodes::vp_screen_des_node>("screen_des_1", 1);
    //auto rtmp_des_0 = std::make_shared<vp_nodes::vp_rtmp_des_node>("rtmp_des_0", 0, "rtmp://192.168.199.119/live/10000");


    // construct pipeline
    yunet_face_detector_0->attach_to({file_src_0, file_src_1});
    sface_face_encoder_0->attach_to({yunet_face_detector_0});

    split_node->attach_to({sface_face_encoder_0});

    osd_0->attach_to({split_node});
    osd_1->attach_to({split_node});
    // auto split
    screen_des_0->attach_to({osd_0});
    screen_des_1->attach_to({osd_1});
    //rtmp_des_0->attach_to({osd_0});

    file_src_0->start();
    file_src_1->start();
    // for debug purpose
    vp_utils::vp_analysis_board board({file_src_0, file_src_1});
    board.display();
    
}
*/

int main2() {
    /*测试一个输入流，多个模型推理*/
    //log init
    // config
    VP_SET_LOG_INCLUDE_THREAD_ID(false);
    VP_SET_LOG_LEVEL(vp_utils::vp_log_level::WARN);
    
    // init
    VP_LOGGER_INIT();
    // create nodes
    auto file_src_0 = std::make_shared<vp_nodes::vp_file_src_node>("file_src_0", 0, "/home/baofengzan/Learning/video_pipe_c/test_model/vp_data/test_video/face.mp4", 0.6);
    //auto file_src_1 = std::make_shared<vp_nodes::vp_file_src_node>("file_src_1", 0, "/home/baofengzan/Learning/video_pipe_c/test_model/vp_data/test_video/face.mp4", 0.6);
    
    auto split_node =  std::make_shared<vp_nodes::vp_split_node>("split", false, true); // split deep-copy not  by channel


    auto yunet_face_detector_0 = std::make_shared<vp_nodes::vp_yunet_face_detector_node>("yunet_face_detector_0", "/home/baofengzan/Learning/video_pipe_c/test_model/vp_data/models/face/face_detection_yunet_2022mar.onnx");
    auto sface_face_encoder_0 = std::make_shared<vp_nodes::vp_sface_feature_encoder_node>("sface_face_encoder_0", "/home/baofengzan/Learning/video_pipe_c/test_model/vp_data/models/face/face_recognition_sface_2021dec.onnx");
    auto osd_0 = std::make_shared<vp_nodes::vp_face_osd_node_v2>("osd_0");
    auto screen_des_0 = std::make_shared<vp_nodes::vp_screen_des_node>("screen_des_0", 0);

    auto yunet_face_detector_1 = std::make_shared<vp_nodes::vp_yunet_face_detector_node>("yunet_face_detector_1", "/home/baofengzan/Learning/video_pipe_c/test_model/vp_data/models/face/face_detection_yunet_2022mar.onnx");
    auto sface_face_encoder_1 = std::make_shared<vp_nodes::vp_sface_feature_encoder_node>("sface_face_encoder_1", "/home/baofengzan/Learning/video_pipe_c/test_model/vp_data/models/face/face_recognition_sface_2021dec.onnx");
    auto osd_1 = std::make_shared<vp_nodes::vp_face_osd_node_v2>("osd_1");
    auto screen_des_1 = std::make_shared<vp_nodes::vp_screen_des_node>("screen_des_1", 0);
    //auto rtmp_des_0 = std::make_shared<vp_nodes::vp_rtmp_des_node>("rtmp_des_0", 0, "rtmp://192.168.199.119/live/10000");

    split_node->attach_to({file_src_0});
    // construct pipeline
    yunet_face_detector_0->attach_to({split_node});
    sface_face_encoder_0->attach_to({yunet_face_detector_0});
    osd_0->attach_to({sface_face_encoder_0});
    screen_des_0->attach_to({osd_0});

    yunet_face_detector_1->attach_to({split_node});
    sface_face_encoder_1->attach_to({yunet_face_detector_1});
    osd_1->attach_to({sface_face_encoder_1});
    screen_des_1->attach_to({osd_1});
    //rtmp_des_0->attach_to({osd_0});
  
    file_src_0->start();
    //file_src_1->start();
    // for debug purpose
    vp_utils::vp_analysis_board board({file_src_0});
    board.display();
    
}



int main() {
    /*测试一个输入流，多个模型推理*/
    //log init
    // config
    VP_SET_LOG_INCLUDE_THREAD_ID(false);
    VP_SET_LOG_LEVEL(vp_utils::vp_log_level::WARN);
    
    // init
    VP_LOGGER_INIT();
    // create nodes
    auto file_src_0 = std::make_shared<vp_nodes::vp_file_src_node>("file_src_0", 0, "/home/baofengzan/Learning/tensorRT_Pro/workspace/exp/face_tracker.mp4", 0.6);
    //auto file_src_1 = std::make_shared<vp_nodes::vp_file_src_node>("file_src_1", 0, "/home/baofengzan/Learning/video_pipe_c/test_model/vp_data/test_video/face.mp4", 0.6);

    auto yunet_face_detector_0 = std::make_shared<vp_nodes::vp_yunet_face_detector_node>("yunet_face_detector_0", "/home/baofengzan/Learning/video_pipe_c1/test_model/vp_data/models/face/face_detection_yunet_2022mar.onnx");
    //auto sface_face_encoder_0 = std::make_shared<vp_nodes::vp_sface_feature_encoder_node>("sface_face_encoder_0", "/home/baofengzan/Learning/video_pipe_c/test_model/vp_data/models/face/face_recognition_sface_2021dec.onnx");
    auto sface_track = std::make_shared<vp_nodes::vp_sort_track_node>("track_node_0", vp_nodes::vp_track_for::FACE);
    
    auto osd_0 = std::make_shared<vp_nodes::vp_face_osd_node_v2>("osd_0");
    auto screen_des_0 = std::make_shared<vp_nodes::vp_screen_des_node>("screen_des_0", 0);

    yunet_face_detector_0->attach_to({file_src_0});
    sface_track->attach_to({yunet_face_detector_0});
    osd_0->attach_to({sface_track});
    screen_des_0->attach_to({osd_0});
  
    file_src_0->start();

    vp_utils::vp_analysis_board board({file_src_0});
    board.display();
    
}

#endif