#include "object2D.h"

#include <vector>

//#include "core/engine.h"
//#include "utils/gl_utils.h"


Mesh* object2D::CreateSquare(
    const std::string &name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, length, 0), color),
        VertexFormat(corner + glm::vec3(0, length, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    } else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}






Mesh* object2D::CreateRectangle(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float width,
    float height,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(width, 0, 0), color),
        VertexFormat(corner + glm::vec3(width, height, 0), color),
        VertexFormat(corner + glm::vec3(0, height, 0), color)
    };

    Mesh* rectangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        rectangle->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    rectangle->InitFromData(vertices, indices);
    return rectangle;
}




Mesh* object2D::CreateRomb(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(0, 2*length, 1), color),
        VertexFormat(corner + glm::vec3(-length , 0, 1), color),
        VertexFormat(corner , color),
        VertexFormat(corner + glm::vec3(0, -2 * length, 1), color),
        VertexFormat(corner + glm::vec3(-length , 0, 1), color),
        VertexFormat(corner , color),
        VertexFormat(corner + glm::vec3(0, 2 * length, 1), color),
        VertexFormat(corner + glm::vec3(length , length*0.5 , 1), color),
        VertexFormat(corner , color),
        VertexFormat(corner + glm::vec3(0, -2 * length, 1), color),
        VertexFormat(corner + glm::vec3(length, -length * 0.5 , 1), color),
        VertexFormat(corner , color),
        VertexFormat(corner + glm::vec3(length , length * 0.5 , 1), color),
        VertexFormat(corner + glm::vec3(length * 4, length * 0.5 , 1), color),
        VertexFormat(corner , color),
        VertexFormat(corner + glm::vec3(length , -length * 0.5 , 1), color),
        VertexFormat(corner + glm::vec3(length * 4, -length * 0.5 , 1), color),
        VertexFormat(corner , color),
        VertexFormat(corner + glm::vec3(length * 4, length * 0.5 , 1), color),
        VertexFormat(corner + glm::vec3(length * 4, -length * 0.5 , 1), color),
    };

    Mesh* romb = new Mesh(name);
    romb->SetDrawMode(GL_TRIANGLES);

    std::vector<unsigned int> indices = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    romb->InitFromData(vertices, indices);
    return romb;
}




Mesh* object2D::CreateStar(
    const std::string& name,
    glm::vec3 center,
    float length,
    glm::vec3 color,
    bool fill)
{

    glm::vec3 corner = center;

    std::vector<VertexFormat> vertices =
    {
       VertexFormat(corner, color),
       VertexFormat(corner + glm::vec3(0 , 2*length, 5), color),
       VertexFormat(corner + glm::vec3(length/2, length, 5), color),
       VertexFormat(corner, color),
       VertexFormat(corner + glm::vec3(2*length , length, 5), color),
       VertexFormat(corner + glm::vec3(length/2, length, 5), color),
       VertexFormat(corner , color),
       VertexFormat(corner + glm::vec3(2*length , length, 5), color),
       VertexFormat(corner + glm::vec3(length/2, -length/2, 5), color),
       VertexFormat(corner , color),
       VertexFormat(corner + glm::vec3(2*length , -2*length, 5), color),
       VertexFormat(corner + glm::vec3( 0, - 5 *length/4, 5), color),
       VertexFormat(corner , color),
       VertexFormat(corner + glm::vec3( 0, -5 * length / 4 , 5), color),
       VertexFormat(corner + glm::vec3(-2*length, -2 * length, 5), color),
       VertexFormat(corner , color),
       VertexFormat(corner + glm::vec3(-length/2 , -length/2, 5), color),
       VertexFormat(corner + glm::vec3(-2*length, length, 5), color),
       VertexFormat(corner , color),
       VertexFormat(corner + glm::vec3(- 2* length , length, 5), color),
       VertexFormat(corner + glm::vec3(-length/2,  length , 5), color),
       VertexFormat(corner , color),
       VertexFormat(corner + glm::vec3(-length / 2,  length , 5), color),
       VertexFormat(corner + glm::vec3(0, 2* length , 5), color),
    };

    Mesh* star = new Mesh(name);
    star->SetDrawMode(GL_TRIANGLES);

    std::vector<unsigned int> indices = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};

    star->InitFromData(vertices, indices);
    return star;
}
    




Mesh* object2D::CreateHexagon(
    const std::string& name,
    glm::vec3 center,
    float length,
    glm::vec3 color,
    glm::vec3 color2,
    bool fill)
{
    glm::vec3 corner = center;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(0 , length , 2), color),
        VertexFormat(corner + glm::vec3(length ,  length/2 , 2), color),
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length ,  length / 2 , 2), color),
        VertexFormat(corner + glm::vec3( length , -length/2 , 2), color),
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length , - length/2 , 2), color),
        VertexFormat(corner + glm::vec3(0 , -length  , 2), color),
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(0 , length , 2), color),
        VertexFormat(corner + glm::vec3(-length ,  length / 2 , 2), color),
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(-length ,  length / 2 , 2), color),
        VertexFormat(corner + glm::vec3(-length , -length / 2 , 2), color),
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(-length , -length / 2 , 2), color),
        VertexFormat(corner + glm::vec3(0 , -length  , 2), color),
        VertexFormat(corner, color2),
        VertexFormat(corner + glm::vec3(0 , 2*length/3 , 3), color2),
        VertexFormat(corner + glm::vec3(2*length/3 ,  length / 3 , 3), color2),
        VertexFormat(corner, color2),
        VertexFormat(corner + glm::vec3(2 * length / 3 ,  length / 3 , 3), color2),
        VertexFormat(corner + glm::vec3(2 * length / 3 , -length / 3 , 3), color2),
        VertexFormat(corner, color2),
        VertexFormat(corner + glm::vec3(2 * length / 3 , -length / 3 , 3), color2),
        VertexFormat(corner + glm::vec3(0 , -2 * length / 3  , 3), color2),
        VertexFormat(corner, color2),
        VertexFormat(corner + glm::vec3(0 , 2 * length / 3 , 3), color2),
        VertexFormat(corner + glm::vec3(-2 * length / 3 ,  2 * length / 3 / 2 , 3), color2),
        VertexFormat(corner, color2),
        VertexFormat(corner + glm::vec3(-2 * length / 3 ,  length / 3 , 3), color2),
        VertexFormat(corner + glm::vec3(-2 * length / 3 , -length / 3 , 3), color2),
        VertexFormat(corner, color2),
        VertexFormat(corner + glm::vec3(-2 * length / 3 , -length / 3  , 3), color2),
        VertexFormat(corner + glm::vec3(0 , -2 * length / 3  , 3), color2),
    };

    Mesh* hexagon = new Mesh(name);
    hexagon->SetDrawMode(GL_TRIANGLES);

    std::vector<unsigned int> indices = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36 };

    hexagon->InitFromData(vertices, indices);
    return hexagon;
}