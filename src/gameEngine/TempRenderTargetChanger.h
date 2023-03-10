//
// Created by sashi0034 on 2022/08/27.
//

#ifndef FILL_TILES_TEMPRENDERTARGETCHANGER_H
#define FILL_TILES_TEMPRENDERTARGETCHANGER_H

#include <SDL.h>
#include <SDL_image.h>

namespace gameEngine
{

    class TempRenderTargetChanger
    {
    public:
        [[nodiscard("スコープ内で保持してください。")]] explicit TempRenderTargetChanger(SDL_Renderer* renderer);
        TempRenderTargetChanger* ChangeInScope(SDL_Texture* changingTarget);
        void RenderClear();
        ~TempRenderTargetChanger();
    private:
        SDL_Renderer* const renderer;
        SDL_Texture* const beforeTexture;
    };

} // gameEngine

#endif //FILL_TILES_TEMPRENDERTARGETCHANGER_H
