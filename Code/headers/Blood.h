#pragma once

#include "BloodState.h"

class Blood{
public:
    Blood(){
        timeSinceLastMove = 0.0;
        isOxygenated = false;
        bloodState = &BloodState::HeartRightSide(); // Initial State.
    }

    void update(double _timeStep, double _currentTime){
        std::cout << "\033[2J\033[1;1H"; // To clear terminal.

        std::cout << "==== Blood Cell 0 status At Time: " << _currentTime << " ====" << std::endl;        
        bloodState->flow(*this);

        if(isOxygenated){
            std::cout << "The Blood is Oxygenated! (Oxygen-Rich)" << std::endl;
        }else{
            std::cout << "The Blood is not Oxygenated! (Oxygen-Poor)" << std::endl;
        }
        
        if(bloodState->getTranslateTime() <= timeSinceLastMove){
            bloodState = bloodState->translate();
            timeSinceLastMove = 0.0;
        }

        AppendToTimeSinceLastMove(_timeStep);
    }

    void setIsOxygenated(bool _isOxygenated){
        isOxygenated = _isOxygenated;
    }

    bool getIsOxygenated(){
        return isOxygenated;
    }


    double GetTimeSinceLastMove(){
        return timeSinceLastMove;
    }

    void AppendToTimeSinceLastMove(double _timeStep){
        timeSinceLastMove += _timeStep;
    }

public:
    BloodState *bloodState;
private:
    bool isOxygenated;
    double timeSinceLastMove;
    // int bloodPlasma; // 55% of entire blood (Liquid Component.).
    // int bloodCells; // 45% of entire blood (Cellular Component). Consists of red blood cells, platelets, white blood cells
};