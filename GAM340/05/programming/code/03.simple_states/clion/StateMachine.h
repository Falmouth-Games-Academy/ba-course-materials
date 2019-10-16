//
// Created by gareth on 16/10/2019.
//

#pragma once

#include <SDL.h>

class StateMachine
{
public:
    class State
    {
    public:
        virtual void Init(){}
        virtual void Update(){}
        virtual void Draw(SDL_Renderer* renderer){}
        virtual void Exit(){}
    };

    State** stateList;

    void Init();
    void Update();
    void Draw(SDL_Renderer* renderer);
    void Quit();

    void SetState(int index);
private:
    int currentState;
    int nextState;

};
