//
// Created by sashi0034 on 2022/05/23.
//

#ifndef FILL_TILES_GAMEROOT_H
#define FILL_TILES_GAMEROOT_H

#include "ActorBase.h"
#include "resource/Image.h"
#include "resource/Font.h"
#include "LuaEngine.h"
#include "./NineAnchor.h"

namespace inGame
{
    namespace resource
    {
        class Image;
        class Font;
    }

    class LuaEngine;


    class GameRoot : public Singleton<GameRoot>
    {
    public:
        explicit GameRoot(IAppState* appState);
        ~GameRoot() override;
        const unique_ptr<resource::Image> RscImage;
        const unique_ptr<resource::Font> RscFont;
        IAppState* GetAppState();
        TextureAnimator& GetTextureAnimator();
        LuaEngine* GetLua();
        IChildrenPool<ActorBase>* GetChildren();
        NineAnchor* GetAnchor();
    private:
        SpriteTexture m_Spr = SpriteTexture::Create();
        ChildrenPool<ActorBase> m_ChildrenPool{};
        TextureAnimator m_TextureAnimator{};
        IAppState* m_AppState;
        LuaEngine m_LuaEngine{this};
        NineAnchor m_Anchor{};
        void createSelfSpr();
    };
}


#endif //FILL_TILES_GAMEROOT_H
