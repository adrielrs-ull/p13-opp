#if !defined(ROBOT_SIMULATOR_H)
#define ROBOT_SIMULATOR_H
#include <utility>
#include <string>
namespace robot_simulator {
   enum class Bearing {
    NORTH,
    SOUTH,
    EAST,
    WEST
  };
  typedef std::pair<int, int> Coordinates;
 class Robot {
   public:
    Robot() : position_{0, 0}, bearing_{Bearing::NORTH} {}
    Robot(const Coordinates kCoordinates, const Bearing kBearing) : position_{kCoordinates}, bearing_{kBearing} {}
    Coordinates get_position() const { return position_;} 
    Bearing get_bearing() const { return bearing_; }
    void turn_right();
    void turn_left();
    void advance();
    void execute_sequence(const std::string kSequence);
   private:
    Coordinates position_;
    Bearing bearing_;
  };
  
}  // namespace robot_simulator
#endif // ROBOT_SIMULATOR_H