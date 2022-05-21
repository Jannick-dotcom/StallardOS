#pragma once
#include "StallardOSFaulhaberControllword.hpp"
#include "StallardOSFaulhaberMessages.hpp"
//#include "StallardOSFaulhaberAntrieb.hpp"
class StallardOSFaulhaberMotionController
{
private:
    enum class State
    {
        INITIALIZATION,
        PRE_OPERATIONAL,
        STOPPED,
        OPERATIONAL
    };

    int node_ID;
    State state;
    StallardoOSFaulhaberControllword controllword;

    void StateTransitionInitialization();
    void StateTransitionPreOperational();
    void StateTransitionOperational();
    void StateTransitionStopped();

    void InitializationFinished();
    void StartRemoteNodeIndication();
    void EnterPreOperationalStateIndication();
    void StopRemoteNodeIndication();
    void StartRemoteNodeIndication();
    void ResetCommunicationIndication();
    void ResetNodeIndication();

public:
    StallardOSFaulhaberMotionController(int node_ID);
    State GetState() { return state; };
    State SetState(State new_state) { state = new_state; }
    int GetNodeID() { return node_ID; };
};
