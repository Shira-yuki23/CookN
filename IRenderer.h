#ifndef IRENDERER_H
#define IRENDERER_H

class IRenderer {
public:
    virtual ~IRenderer() {}

    virtual void drawPlayer(int x, int y) = 0;
    virtual void drawNPC(int x, int y) = 0;
};

#endif
//PURPOSE OF USING A SEPERATE RENDER CLASS SO THAT WE CAN EASILY MAKE CHANGE WHILE USING DIFF GRAPHICS OTHER THAN RAYLIB