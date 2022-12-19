//
// Created by sashi0034 on 2022/05/03.
//

#ifndef FILL_TILES_GAMELOOPER_H
#define FILL_TILES_GAMELOOPER_H

#include <SDL.h>
#include <SDL_image.h>
#include "../gameEngine/gameEngine.h"

namespace inGame {
    class GameLooper {

    public:
        static void Loop(unique_ptr<AppState>& appState);
    };
}


#endif //FILL_TILES_GAMELOOPER_H
