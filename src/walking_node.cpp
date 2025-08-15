#include <rclcpp/rclcpp.hpp>

class WalkingNode : public rclcpp::Node {
public:
  WalkingNode() : rclcpp::Node("humanoid_walking") {
    double Tsup = declare_parameter("Tsup", 0.8);
    double sx   = declare_parameter("sx",   0.2);
    double sy   = declare_parameter("sy",   0.2);
    double x0   = declare_parameter("x0",   0.0);
    double y0   = declare_parameter("y0",   0.0);
    double px0  = declare_parameter("px0",  0.0);
    double py0  = declare_parameter("py0",  0.1);
    RCLCPP_INFO(get_logger(),
      "params: Tsup=%.2f sx=%.2f sy=%.2f x0=%.2f y0=%.2f px0=%.2f py0=%.2f",
      Tsup, sx, sy, x0, y0, px0, py0);
  }
};

int main(int argc, char** argv){
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<WalkingNode>());
  rclcpp::shutdown();
  return 0;
}
