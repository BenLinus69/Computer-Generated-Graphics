#pragma once

#include "components/simple_scene.h"
#include "lab_m1/Tema1/Romb.h"
#include "lab_m1/Tema1/Star.h"
#include "lab_m1/Tema1/Enemy.h"


namespace m1
{
    class Tema1 : public gfxc::SimpleScene
    {
     public:
        Tema1();
        ~Tema1();

        void Init() override;

     private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

     protected:
        float cx, cy;
        glm::mat3 modelMatrix;
        float translateX, translateY;
        float mousePosX;
        float mousePosY;
        float translateX2, translateY2;
        float transX, transY;
        float scale;
        float angularStep;
        float squareSide;
        float rombSide;
        float enemySide;
        float starSide;
        float rect_width;
        float rect_height;
        float outerRadius;
        float innerRadius;
        float rotateX;
        float rotateY;
        float starmove;
        float squareCost;
        bool enemyFirstRow;
        bool enemySecondRow;
        bool enemyThirdRow;
        bool MousePressed;
        float lives;
        bool ok;
        float money;
        size_t test;
        std::vector<Romb> rombVector;
        std::vector<Romb> SquareVector;
        std::vector<Romb> LivesVector;
        std::vector<Enemy> EnemyVector;
        std::vector<Star> ProjectilesVector;
        std::vector<Star> RandomStarVector;
        std::vector<Star> ScoreVector;
        std::vector<Star> SceneryStarVector;
        // TODO(student): If you need any other class variables, define them here.

    };
}   // namespace m1
