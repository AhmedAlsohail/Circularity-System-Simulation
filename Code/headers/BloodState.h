#pragma once

#include <iostream>

class Blood;

// Forward declarations for all classes
class Heart_Left_Side;
class From_Heart_To_Body;
class InBrainState;
class From_Body_To_Heart;
class Heart_Right_Side;
class From_Heart_To_Lungs;
class InLungsState;
class From_Lung_To_Heart;

class BloodState {
public:
    virtual void flow(Blood& blood) { std::cout << "Default\n"; }
    virtual BloodState* translate();
    virtual double getTranslateTime() { return translateTime; }
    virtual ~BloodState() = default;

    static BloodState& HeartLeftSide();
    static BloodState& HeartToBody();
    static BloodState& Brain();
    static BloodState& BodyToHeart();
    static BloodState& HeartRightSide();
    static BloodState& HeartToLungs();
    static BloodState& Lungs();
    static BloodState& LungToHeart();
    

protected:
    double translateTime;
};

class Heart_Left_Side : public BloodState {
public:
    Heart_Left_Side();
    void flow(Blood& blood) override;
    BloodState* translate() override;
};

class From_Heart_To_Body : public BloodState {
public:
    From_Heart_To_Body();
    void flow(Blood& blood) override;
    BloodState* translate() override;
};

class InBrainState : public BloodState {
public:
    InBrainState();
    void flow(Blood& blood) override;
    BloodState* translate() override;
};

class From_Body_To_Heart : public BloodState {
public:
    From_Body_To_Heart();
    void flow(Blood& blood) override;
    BloodState* translate() override;
};

class Heart_Right_Side : public BloodState {
public:
    Heart_Right_Side();
    void flow(Blood& blood) override;
    BloodState* translate() override;
};

class From_Heart_To_Lungs : public BloodState {
public:
    From_Heart_To_Lungs();
    void flow(Blood& blood) override;
    BloodState* translate() override;
};

class InLungsState : public BloodState {
public:
    InLungsState();
    void flow(Blood& blood) override;
    BloodState* translate() override;
};

class From_Lung_To_Heart : public BloodState {
public:
    From_Lung_To_Heart();
    void flow(Blood& blood) override;
    BloodState* translate() override;
};
