#ifndef RAYLIBRENDERER_H
#define RAYLIBRENDERER_H

#include "IRenderer.h"
#include "raylib.h"

class RaylibRenderer : public IRenderer {
public:
    void drawPlayer(int x, int y) override;
    void drawNPC(int x, int y) override;
};

#endif
