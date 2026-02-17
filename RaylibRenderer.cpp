#include "RaylibRenderer.h"

void RaylibRenderer::drawPlayer(int x, int y) {
    DrawRectangle(x, y, 40, 40, BLUE);
}

void RaylibRenderer::drawNPC(int x, int y) {
    DrawRectangle(x, y, 40, 40, RED);
}
