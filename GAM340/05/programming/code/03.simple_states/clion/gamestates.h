//
// Created by gareth on 16/10/2019.
//

#pragma once
#include "StateMachine.h"

class State_0 : public StateMachine::State
{
public:
    void Init()
    {

    }

    void Update()
    {

    }

    void Draw(SDL_Renderer* renderer)
    {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderClear(renderer);
    }

    void Exit()
    {

    }
};

class State_1 : public StateMachine::State
{
public:
    void Init()
    {

    }

    void Update()
    {

    }

    void Draw(SDL_Renderer* renderer)
    {
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderClear(renderer);
    }

    void Exit()
    {

    }
};

class State_2 : public StateMachine::State
{
public:
    void Init()
    {

    }

    void Update()
    {

    }

    void Draw(SDL_Renderer* renderer)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderClear(renderer);
    }

    void Exit()
    {

    }
};