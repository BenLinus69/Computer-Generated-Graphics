#include "lab_m1/Tema1/Tema1.h"

#include <vector>
#include <iostream>

#include "lab_m1/Tema1/object2D.h"
#include "lab_m1/Tema1/transform2D.h"
#include "lab_m1/Tema1/Romb.h"
#include "lab_m1/Tema1/Star.h"
#include "lab_m1/Tema1/Enemy.h"

using namespace std;
using namespace m1;



Tema1::Tema1()
{
}


Tema1::~Tema1()
{
}


void Tema1::Init()
{
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);
    for (int i = 0; i < 9; ++i) {
        rombVector.push_back(Romb());
    }
    std::vector<std::pair<float, float>> coordinates = {
    {100, 25}, {250, 25}, {400, 25},
    {400, 175}, {250, 175}, {100, 175},
    {100, 325}, {250, 325}, {400, 325}
    };

    for (size_t i = 0; i < rombVector.size() && i < coordinates.size(); ++i) {
        rombVector[i].setpositionX(coordinates[i].first);
        rombVector[i].setpositionY(coordinates[i].second);
    }
    for (int i = 0; i < 3; i++)
    {
        rombVector[i].row = 3;
    }
    for (int i = 3; i < 6; i++)
    {
        rombVector[i].row = 2;
    }
    for (int i = 6; i < 9; i++)
    {
        rombVector[i].row = 1;
    }

    for (int i = 0; i < 4; ++i) {
        SquareVector.push_back(Romb());
    }
    std::vector<std::pair<float, float>> coordinatesSquares = {
    {88, 575}, {288, 575}, {488, 575},
    {688, 575}
    };
    for (size_t i = 0; i < SquareVector.size() && i < coordinates.size(); ++i) {
        SquareVector[i].setpositionX(coordinatesSquares[i].first);
        SquareVector[i].setpositionY(coordinatesSquares[i].second);
        if (i == 0)
        {
            SquareVector[i].squareCost = 1;
        }
        else if (i == 1 || i == 2)
        {
            SquareVector[i].squareCost = 2;
        }
        else if (i == 3)
        {
            SquareVector[i].squareCost = 3;
        }
    }

    for (int i = 0; i < 3; ++i) {
        LivesVector.push_back(Romb());
    }
    std::vector<std::pair<float, float>> coordinatesLives = {
    {888, 575}, {1020, 575}, {1152, 575},
    };
    for (size_t i = 0; i < LivesVector.size() && i < coordinatesLives.size(); ++i) {
        LivesVector[i].setpositionX(coordinatesLives[i].first);
        LivesVector[i].setpositionY(coordinatesLives[i].second);
    }

    for (int i = 0; i < 10; ++i) {
        ScoreVector.push_back(Star());
    }

    std::vector<std::pair<float, float>> coordinatesScore = {
    {900, 555}, {940, 555}, {980, 555},
    {1020, 555}, {1060, 555}, {1100, 555},
    {1140, 555}, {1180, 555}, {1220, 555},
    {1260, 555}
    };

    for (size_t i = 0; i < ScoreVector.size() && i < coordinatesScore.size(); ++i) {
        ScoreVector[i].positionX=coordinatesScore[i].first;
        ScoreVector[i].positionY=coordinatesScore[i].second;
    }

    for (int i = 0; i < 8; ++i) {
        SceneryStarVector.push_back(Star());
    }

    std::vector<std::pair<float, float>> coordinatesSceneryStars = {
    {145, 555}, {325, 555}, {365, 555},
    {525, 555}, {565, 555}, {700, 555},
    {740, 555}, {780, 555}
    };

    for (size_t i = 0; i < SceneryStarVector.size() && i < coordinatesSceneryStars.size(); ++i) {
        SceneryStarVector[i].positionX = coordinatesSceneryStars[i].first;
        SceneryStarVector[i].positionY = coordinatesSceneryStars[i].second;
    }

    glm::vec3 corner = glm::vec3(0, 0, 0);
    squareSide = 110;
    rombSide = 20;
    enemySide = 30;
    starSide = 8;
    rect_width = 60;
    rect_height = 410;
    outerRadius = 40;
    innerRadius = 20;
    ok = false;
    lives = 3;
    money = 5;
    squareCost = 0;
    MousePressed = false;
    // Initialize tx and ty (the translation steps)
    translateX = 0;
    translateY = 0;
    translateX2 = 0;
    translateY2 = 0;
    transX = 0;
    transY = 0;
    starmove = 0;
    rotateX = 0;
    rotateY = 0;
    enemyThirdRow = false;
    enemyFirstRow = false;
    enemySecondRow = false;

    // Initialize sx and sy (the scale factors)
    scale = 1;

    // Initialize angularStep
    angularStep = 0;

    Mesh* square1 = object2D::CreateSquare("square1", corner, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square1);

    Mesh* square2 = object2D::CreateSquare("square2", corner, squareSide-5, glm::vec3(0, 1, 0), false);
    AddMeshToList(square2);

    Mesh* square3 = object2D::CreateSquare("square3", corner, squareSide - 5, glm::vec3(1, 0, 0), true);
    AddMeshToList(square3);

    Mesh* rectangle = object2D::CreateRectangle("rectangle", corner, rect_width,rect_height, glm::vec3(1, 0, 0), true);
    AddMeshToList(rectangle);

    Mesh* romb1 = object2D::CreateRomb("romb1", corner, rombSide, glm::vec3(128, 0, 128), true);
    AddMeshToList(romb1);

    Mesh* romb2 = object2D::CreateRomb("romb2", corner, rombSide, glm::vec3(128, 0, 128), true);
    AddMeshToList(romb2);

    Mesh* romb3 = object2D::CreateRomb("romb3", corner, rombSide, glm::vec3(128, 0, 128), true);
    AddMeshToList(romb3);

    Mesh* romb4 = object2D::CreateRomb("romb4", corner, rombSide, glm::vec3(128, 0, 128), true);
    AddMeshToList(romb4);

    Mesh* star = object2D::CreateStar("star", corner, starSide, glm::vec3(255, 255, 255), true);
    AddMeshToList(star);

    Mesh* enemy = object2D::CreateHexagon("enemy", corner, enemySide, glm::vec3(1, 0, 0), glm::vec3(0, 0, 1), true);
    AddMeshToList(enemy);
}


void Tema1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}


void Tema1::Update(float deltaTimeSeconds)
{
    for (int i = 0; i < 9; i++)//afisare 9 patrate
    {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(rombVector[i].getpositionX(), rombVector[i].getpositionY());
        RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);
    }
    for (int i = 0; i < 9; i++)//render shooter
    {
        if (rombVector[i].getvis() == true && rombVector[i].destroyed == false)//romb is rendered
        {
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(rombVector[i].getpositionX() + 25, rombVector[i].getpositionY() + 55);
            RenderMesh2D(meshes["romb4"], shaders["VertexColor"], modelMatrix);
            rombVector[i].scale = 1;
        }
        else if (rombVector[i].getWasvis() == true || rombVector[i].destroyed==true)//romb disappear animation
        {
            rombVector[i].setvis(false);
            modelMatrix = glm::mat3(1);
            rombVector[i].scale -= deltaTimeSeconds * 0.9;
            modelMatrix *= transform2D::Translate(rombVector[i].getpositionX() + 25, rombVector[i].getpositionY() + 55);
            modelMatrix *= transform2D::Scale(rombVector[i].scale, rombVector[i].scale);
            RenderMesh2D(meshes["romb4"], shaders["VertexColor"], modelMatrix);
            if (rombVector[i].scale <= 0.1)
            {
                rombVector[i].setWasvis(false);
                rombVector[i].destroyed=false;
            }
        }
        
    }
    for (int i = 0; i < 9; i++)
    {
        rombVector[i].shootTime += deltaTimeSeconds;
    }
    for (int i = 0; i < 9; i++)
    {
        if (rombVector[i].getvis() == true)
        {
            if (enemyThirdRow == true && rombVector[i].row==3)//if romb is visible and there are enemyes on that row, create projectile
            {
                if (rombVector[i].shootTime >= 2)//create a projectile at a 2 second interval
                {
                    ProjectilesVector.push_back(Star());
                    ProjectilesVector.back().positionX = rombVector[i].getpositionX() + 95;
                    ProjectilesVector.back().positionY = rombVector[i].getpositionY() + 55;
                    ProjectilesVector.back().starmove = 0;
                    ProjectilesVector.back().rotate = 0;
                    ProjectilesVector.back().rowNumber = 3;
                    rombVector[i].shootTime = 0.0f;
                }
            }
            if (enemySecondRow == true && rombVector[i].row == 2)
            {
                if (rombVector[i].shootTime >= 2)//create a projectile at a 2 second interval
                {
                    ProjectilesVector.push_back(Star());
                    ProjectilesVector.back().positionX = rombVector[i].getpositionX() + 95;
                    ProjectilesVector.back().positionY = rombVector[i].getpositionY() + 55;
                    ProjectilesVector.back().starmove = 0;
                    ProjectilesVector.back().rotate = 0;
                    ProjectilesVector.back().rowNumber = 2;
                    rombVector[i].shootTime = 0.0f;
                }
            }
            if (enemyFirstRow == true && rombVector[i].row == 1)
            {
                if (rombVector[i].shootTime >= 2)//create a projectile at a 2 second interval
                {
                    ProjectilesVector.push_back(Star());
                    ProjectilesVector.back().positionX = rombVector[i].getpositionX() + 95;
                    ProjectilesVector.back().positionY = rombVector[i].getpositionY() + 55;
                    ProjectilesVector.back().starmove = 0;
                    ProjectilesVector.back().rotate = 0;
                    ProjectilesVector.back().rowNumber = 1;
                    rombVector[i].shootTime = 0.0f;
                }
            }
        }
    }
    for (size_t i = 0; i < ProjectilesVector.size(); i++)//Projectiles render
    {
        if (ProjectilesVector[i].deleted == false)
        {
            modelMatrix = glm::mat3(1);
            ProjectilesVector[i].starmove += deltaTimeSeconds * 150;
            ProjectilesVector[i].rotate += deltaTimeSeconds * 7;
            modelMatrix *= transform2D::Translate(ProjectilesVector[i].positionX+ProjectilesVector[i].starmove, ProjectilesVector[i].positionY);
            modelMatrix *= transform2D::Rotate(ProjectilesVector[i].rotate);
            RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);
            ProjectilesVector[i].movingPositionX = ProjectilesVector[i].positionX + ProjectilesVector[i].starmove;
        }
    }
    

    for (int i = 0; i < 4; i++)//afisare 9 patrate
    {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(SquareVector[i].getpositionX(), SquareVector[i].getpositionY());
        RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);
    }

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(10, 25);
    RenderMesh2D(meshes["rectangle"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(110, 625);
    RenderMesh2D(meshes["romb1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(310, 625);
    RenderMesh2D(meshes["romb2"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(510, 625);
    RenderMesh2D(meshes["romb3"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(710, 625);
    RenderMesh2D(meshes["romb4"], shaders["VertexColor"], modelMatrix);

    for (size_t i = 0; i < SceneryStarVector.size(); i++)//render shooter costs
    {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(SceneryStarVector[i].positionX, SceneryStarVector[i].positionY);
        RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);
    }

    for (int i = 0; i < lives; i++)//life squares render
    {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(LivesVector[i].getpositionX(), LivesVector[i].getpositionY());
        RenderMesh2D(meshes["square3"], shaders["VertexColor"], modelMatrix);
    }
    //end of scene elements 
    
    //
    static float timeElapsed = 0.0f; 
    static float nextRenderTime = rand() % 5 + 3; 
    timeElapsed += deltaTimeSeconds;
    
    if (timeElapsed >= nextRenderTime)//enemy creation
    {
        std::vector<float> coordinatesEnemy = {
        80, 230, 390
        };
        int i = rand() % 3;//randomize row

        EnemyVector.push_back(Enemy());
        EnemyVector.back().positionY = coordinatesEnemy[i];
        EnemyVector.back().positionX = 1255;
        EnemyVector.back().rowNumber = 3-i;

       
        timeElapsed = 0.0f;
        nextRenderTime = rand() % 5 + 3;//reset the timer
    }

    for (size_t i = 0; i < EnemyVector.size(); i++)
    {
        if (EnemyVector[i].deleted == false)//reder enemy
        {
            modelMatrix = glm::mat3(1);
            EnemyVector[i].translateX += deltaTimeSeconds * 100;
            modelMatrix *= transform2D::Translate(EnemyVector[i].positionX - EnemyVector[i].translateX, EnemyVector[i].positionY);
            RenderMesh2D(meshes["enemy"], shaders["VertexColor"], modelMatrix);
            EnemyVector[i].movingPositionX = EnemyVector[i].positionX - EnemyVector[i].translateX;
        }
        else if (EnemyVector[i].deleted == true && EnemyVector[i].hasLived == true)//disappear animation for enemy
        {
            modelMatrix = glm::mat3(1);
            EnemyVector[i].scale -= deltaTimeSeconds * 0.9;
            modelMatrix *= transform2D::Translate(EnemyVector[i].movingPositionX, EnemyVector[i].positionY);
            modelMatrix *= transform2D::Scale(EnemyVector[i].scale, EnemyVector[i].scale);
            RenderMesh2D(meshes["enemy"], shaders["VertexColor"], modelMatrix);
            if (EnemyVector[i].scale <= 0.1)
            {
                EnemyVector[i].hasLived=false;
            }
        }
        if (EnemyVector[i].positionX - EnemyVector[i].translateX < 40 && EnemyVector[i].deleted == false)
        {
            lives--;
            if (lives == 0)
            {
                exit(0);
            }
            EnemyVector[i].deleted = true;
            if (EnemyVector[i].rowNumber == 1)
            {
                enemyFirstRow = false;
            }
            if (EnemyVector[i].rowNumber == 2)
            {
                enemySecondRow = false;
            }
            if (EnemyVector[i].rowNumber == 3)
            {
                enemyThirdRow = false;
            }

            }
    }

    static float timeElapsed2 = 0.0f;
    timeElapsed2 += deltaTimeSeconds;

    if (timeElapsed2 >= 5)//random stars creation
    {
        RandomStarVector.push_back(Star());
        RandomStarVector.back().positionY = rand() % 650 + 50;
        RandomStarVector.back().positionX = rand() % 1200 + 50;
        RandomStarVector.push_back(Star());
        RandomStarVector.back().positionY = rand() % 650 + 50;
        RandomStarVector.back().positionX = rand() % 1200 + 50;
        RandomStarVector.push_back(Star());
        RandomStarVector.back().positionY = rand() % 650 + 50;
        RandomStarVector.back().positionX = rand() % 1200 + 50;

        timeElapsed2 = 0.0f;
    }
    for (size_t i = 0; i < RandomStarVector.size(); i++)//random stars render
    {
        if (RandomStarVector[i].deleted == false)
        {
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(RandomStarVector[i].positionX , RandomStarVector[i].positionY);
            RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);
        }
    }

    for (size_t i = 0; i < ScoreVector.size() && i<money; i++)//render available money
    {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(ScoreVector[i].positionX, ScoreVector[i].positionY);
        RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);
    }
    


    //collision
    for (size_t i = 0; i < EnemyVector.size(); i++)
    {
        if (EnemyVector[i].lives <= 0)
        {
            EnemyVector[i].deleted = true;
            if (EnemyVector[i].rowNumber == 1)
            {
                enemyFirstRow = false;
            }
            if (EnemyVector[i].rowNumber == 2)
            {
                enemySecondRow = false;
            }
            if (EnemyVector[i].rowNumber == 3)
            {
                enemyThirdRow = false;
            }
        }
        for (size_t j = 0; j < ProjectilesVector.size(); j++)
        {
            
            float radiusSum = EnemyVector[i].radius + ProjectilesVector[j].radius;
            if(EnemyVector[i].movingPositionX-ProjectilesVector[j].movingPositionX < radiusSum && 
                EnemyVector[i].deleted==false && ProjectilesVector[j].hit == false &&
                ProjectilesVector[j].rowNumber==EnemyVector[i].rowNumber && 
                EnemyVector[i].movingPositionX > ProjectilesVector[j].movingPositionX)//enemy and projectile collision
            {
                ProjectilesVector[j].deleted = true;
                EnemyVector[i].lives--;
                ProjectilesVector[j].hit = true;
            }
        }
        for (size_t k = 0; k < rombVector.size(); k++)
        {
            float radiusSum2 = rombVector[k].radius + EnemyVector[i].radius;
            if (EnemyVector[i].movingPositionX - rombVector[k].getpositionX() < radiusSum2 &&
                EnemyVector[i].deleted == false && rombVector[k].getvis() == true &&
                rombVector[k].row == EnemyVector[i].rowNumber &&
                EnemyVector[i].movingPositionX > rombVector[k].getpositionX())//enemy and shooter collision
            {
                rombVector[k].destroyed = true;
            }
        }

    }

    for (size_t i = 0; i < EnemyVector.size(); i++)//check if there are enemies on a row
    {
        if (EnemyVector[i].rowNumber == 3 && EnemyVector[i].deleted == false)
        {
            enemyThirdRow = true;
        }

        if (EnemyVector[i].rowNumber == 2 && EnemyVector[i].deleted == false)
        {
            enemySecondRow = true;
        }
        if (EnemyVector[i].rowNumber == 1 && EnemyVector[i].deleted == false)
        {
            enemyFirstRow = true;
        }
    }
    

    //mouse hold animation for drag and drop
    if (MousePressed == true)
    {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(mousePosX, mousePosY);
        RenderMesh2D(meshes["romb4"], shaders["VertexColor"], modelMatrix);
    }
    
    
}


void Tema1::FrameEnd()
{
}


void Tema1::OnInputUpdate(float deltaTime, int mods)
{
}


void Tema1::OnKeyPress(int key, int mods)
{
    // Add key press event
}


void Tema1::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
    float screenY = 720 - (float)mouseY;
    float screenX = (float)mouseX;

    mousePosX = screenX;
    mousePosY = screenY;
}


void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{   
        
        float screenY = 720 - (float)mouseY;
        float screenX = (float)mouseX;

        if (button == 1)
        {
            for (size_t i = 0; i < SquareVector.size(); ++i)//check if the squares are pressed
            {
                float x = SquareVector[i].getpositionX();
                float y = SquareVector[i].getpositionY();
                if ((screenX > x && screenX < x + 110) && (screenY > y && screenY < y + 110) && money >= SquareVector[i].squareCost)
                {
                    MousePressed = true;
                    squareCost = SquareVector[i].squareCost;
                }
            }


            for (size_t i = 0; i < RandomStarVector.size(); ++i)
            {
                float x = RandomStarVector[i].positionX;
                float y = RandomStarVector[i].positionY;

                if (screenX<x + RandomStarVector[i].radius && screenX>x - RandomStarVector[i].radius &&
                    screenY < y + RandomStarVector[i].radius && screenY > y - RandomStarVector[i].radius &&
                    RandomStarVector[i].deleted == false)
                {
                    RandomStarVector[i].deleted = true;
                    if (money < 10)
                    {
                        money++;
                    }

                }

            }
        }
        if (button == 2)
        {
            for (size_t i = 0; i < rombVector.size(); ++i)//check for romb disappear animation
            {
                float x = rombVector[i].getpositionX();
                float y = rombVector[i].getpositionY();

                if ((screenX > x && screenX < x + 110) && (screenY > y && screenY < y + 110))
                {

                    if (rombVector[i].getvis() == true)
                    {
                        rombVector[i].setvis(false);
                        rombVector[i].setvis(false);
                    }
                }
            }
        }


}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
    float screenY = 720 - (float)mouseY;
    float screenX = (float)mouseX;
    for (size_t i = 0; i < rombVector.size(); ++i)
    {
        float x = rombVector[i].getpositionX();
        float y = rombVector[i].getpositionY();

        if ((screenX > x && screenX < x + 110) && (screenY > y && screenY < y + 110) && MousePressed == true)
        {

            if (rombVector[i].getvis() == false && money)
            {
                rombVector[i].setvis(true);
                rombVector[i].setWasvis(true);
                MousePressed = false;
                money -= squareCost;
            }
            else
            {
                rombVector[i].setvis(false);
                rombVector[i].setvis(false);

            }
        }
        
        
    }
    MousePressed = false;

}
void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY){}
void Tema1::OnWindowResize(int width, int height){ }