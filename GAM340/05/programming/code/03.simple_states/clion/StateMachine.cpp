//
// Created by gareth on 16/10/2019.
//

#include "StateMachine.h"

void StateMachine::Init()
{
    currentState = -1;
    nextState = -1;
}

void StateMachine::SetState(int index)
{
    nextState = index;
}

void StateMachine::Update()
{
    if(nextState != -1)
    {
        if(currentState != -1)
        {
            stateList[currentState]->Exit();
            currentState = nextState;
            nextState = -1;

            if(currentState != -1)
            {
                stateList[currentState]->Init();
            }
        }
    }

    if(currentState != -1)
    {
        stateList[currentState]->Update();
    }
}

void StateMachine::Draw(SDL_Renderer* renderer)
{
    if(currentState != -1)
    {
        stateList[currentState]->Draw(renderer);
    }
}

void StateMachine::Quit()
{
    currentState = -1;
    nextState = -1;
}