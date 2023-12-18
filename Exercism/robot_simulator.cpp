#include "robot_simulator.h"
namespace robot_simulator {
  void Robot::turn_right() {
    switch(bearing_) {
      case Bearing::NORTH: 
        bearing_ = Bearing::EAST;
        break;
      case Bearing::EAST:
        bearing_ = Bearing::SOUTH;
        break;
      case Bearing::SOUTH:
        bearing_ = Bearing::WEST;
        break;
      case Bearing::WEST:
        bearing_ = Bearing::NORTH;
        break;
   }
  }
  void Robot::turn_left() {
     switch(bearing_) {
      case Bearing::NORTH: 
        bearing_ = Bearing::WEST;
        break;
      case Bearing::EAST:
        bearing_ = Bearing::NORTH;
        break;
      case Bearing::SOUTH:
        bearing_ = Bearing::EAST;
        break;
      case Bearing::WEST:
        bearing_ = Bearing::SOUTH;
        break;
   }
  }
  void Robot::advance() {
    switch(bearing_) {
      case Bearing::NORTH:
        ++position_.second;
        break;
      case Bearing::EAST:
        ++position_.first;
        break;
      case Bearing::SOUTH:
        --position_.second;
        break;
      case Bearing::WEST:
        --position_.first;
        break;
    }
  }
  void Robot::execute_sequence(const std::string kSequence) {
    for (size_t i = 0; i < kSequence.length(); ++i) {
      switch(kSequence[i]) {
        case 'A':
          this->advance();
          break;
        case 'L':
          this->turn_left();
          break;
        case 'R':
          this->turn_right();
          break;
      }
    }
  }
}  // namespace robot_simulator
