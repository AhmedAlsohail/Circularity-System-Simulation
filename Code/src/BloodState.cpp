#include "BloodState.h"
#include "Blood.h"

// ==============       Default     ==============
BloodState* BloodState::translate() {
    return nullptr;
}

// ============== Heart_Left_Side ==============
Heart_Left_Side::Heart_Left_Side() {
    translateTime = 0.75;
}

void Heart_Left_Side::flow(Blood& blood) {
    std::cout << "AT Heart_Left_Side\n";
}

BloodState* Heart_Left_Side::translate() {
    std::cout << "Translating from \"Heart_Left_Side\" to From_Heart_To_Body State\n";
    return &BloodState::HeartToBody();
}


// ============== From_Heart_To_Body ==============
From_Heart_To_Body::From_Heart_To_Body() {
    translateTime = 1.0;
}

void From_Heart_To_Body::flow(Blood& blood) {
    std::cout << "AT From_Heart_To_Body\n";
}

BloodState* From_Heart_To_Body::translate() {
    std::cout << "Translating from \"From_Heart_To_Body\" to Brain State\n";
    return &BloodState::Brain();
}


// ==============       Brain       ==============
InBrainState::InBrainState() {
    translateTime = 1.0;
}

void InBrainState::flow(Blood& blood) {
    std::cout << "AT BRAIN\n";
    blood.setIsOxygenated(false);
}

BloodState* InBrainState::translate() {
    std::cout << "Translating from \"Brain\" to From_Body_To_Heart State\n";
    return &BloodState::BodyToHeart();
}


// ============== From_Body_To_Heart ==============
From_Body_To_Heart::From_Body_To_Heart() {
    translateTime = 1.0;
}

void From_Body_To_Heart::flow(Blood& blood) {
    std::cout << "AT From_Body_To_Heart\n";
}

BloodState* From_Body_To_Heart::translate() {
    std::cout << "Translating from \"From_Body_To_Heart\" to Heart_Right_Side State\n";
    return &BloodState::HeartRightSide();
}


// ============== Heart_Right_Side ==============
Heart_Right_Side::Heart_Right_Side() {
    translateTime = 0.5;
}

void Heart_Right_Side::flow(Blood& blood) {
    std::cout << "AT Heart_Right_Side\n";
}

BloodState* Heart_Right_Side::translate() {
    std::cout << "Translating from \"Heart_Right_Side\" to From_Heart_To_Lung State\n";
    return &BloodState::HeartToLungs();
}


// ============== From_Heart_To_Lungs ==============
From_Heart_To_Lungs::From_Heart_To_Lungs() {
    translateTime = 0.75;
}

void From_Heart_To_Lungs::flow(Blood& blood) {
    std::cout << "AT From_Heart_To_Lung\n";
}

BloodState* From_Heart_To_Lungs::translate() {
    std::cout << "Translating from \"From_Heart_To_Lung\" to Lungs State\n";
    return &BloodState::Lungs();
}


// ==============       Lungs       ==============
InLungsState::InLungsState() {
    translateTime = 0.5;
}

void InLungsState::flow(Blood& blood) {
    std::cout << "AT Lungs\n";
    blood.setIsOxygenated(true);
}

BloodState* InLungsState::translate() {
    std::cout << "Translating from \"Lungs\" to From_Lung_To_Heart State\n";
    return &BloodState::LungToHeart();
}


// ============== From_Lung_To_Heart ==============
From_Lung_To_Heart::From_Lung_To_Heart() {
    translateTime = 0.75;
}

void From_Lung_To_Heart::flow(Blood& blood) {
    std::cout << "AT From_Lung_To_Heart\n";
}

BloodState* From_Lung_To_Heart::translate() {
    std::cout << "Translating from \"From_Lung_To_Heart\" to Heart_Left_Side State\n";
    return &BloodState::HeartLeftSide();
}


// === Static instances ===

BloodState& BloodState::HeartLeftSide() {
    static Heart_Left_Side instance;
    return instance;
}

BloodState& BloodState::HeartToBody() {
    static From_Heart_To_Body instance;
    return instance;
}

BloodState& BloodState::Brain() {
    static InBrainState instance;
    return instance;
}

BloodState& BloodState::BodyToHeart() {
    static From_Body_To_Heart instance;
    return instance;
}

BloodState& BloodState::HeartRightSide() {
    static Heart_Right_Side instance;
    return instance;
}

BloodState& BloodState::HeartToLungs() {
    static From_Heart_To_Lungs instance;
    return instance;
}

BloodState& BloodState::Lungs() {
    static InLungsState instance;
    return instance;
}

BloodState& BloodState::LungToHeart() {
    static From_Lung_To_Heart instance;
    return instance;
}