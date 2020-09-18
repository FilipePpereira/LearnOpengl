#include "PlayerControl.h"
#include"InputManager.h"






PlayerControl::PlayerControl(): deltaTime(0.0f), lastTime(0.0f), m_camera(nullptr)
{
}

PlayerControl::~PlayerControl()
{
}

void PlayerControl::Initialized(GLFWwindow* window)
{

    m_camera = new Camera();
    glm::vec3 positionCamera = glm::vec3(0.0f, 0.0f, 3.0f);
    m_camera->SetPosition(positionCamera);

    glfwSetKeyCallback(window, InputManager::InputManagerCallback);

}

void PlayerControl::Update(float deltaTime)
{
    glm::vec3 cameraPosition = m_camera->GetCameraPosition();

    float speed = 1.0f;

    
    if (InputManager::Instance()->isKeyPressed(GLFW_KEY_W))
    {
        cameraPosition.z += speed * deltaTime;
        std::cout << "Move Z: " << cameraPosition.z << "\n";
    }
    if (InputManager::Instance()->isKeyPressed(GLFW_KEY_S))
    {
        cameraPosition.z -= speed * deltaTime;
        std::cout << "Move Z: " << -cameraPosition.z << "\n";
    }
    if (InputManager::Instance()->isKeyPressed(GLFW_KEY_A))
    {
        cameraPosition.x += speed * deltaTime;
        std::cout << "Move -X: " << -cameraPosition.x << "\n";
    }
    if (InputManager::Instance()->isKeyPressed(GLFW_KEY_D))
    {
        cameraPosition.x -= speed * deltaTime;
        std::cout << "Move X: " << cameraPosition.x << "\n";
    }

    if (InputManager::Instance()->isKeyPressed(GLFW_KEY_SPACE))
    {
        cameraPosition.y -= speed * deltaTime;
        std::cout << "Move Y: " << cameraPosition.y << "\n";
    }
    if (InputManager::Instance()->isKeyPressed(GLFW_KEY_Z))
    {
        cameraPosition.y += speed * deltaTime;
        std::cout << "Move -Y: " << -cameraPosition.y << "\n";
    }

    
    m_camera->SetPosition(cameraPosition);

}

glm::vec3 PlayerControl::GetCameraPosition()
{
    return m_camera->GetCameraPosition();
}

glm::mat4 PlayerControl::GetCameraView()
{
    return m_camera->GetViewMatrix();
}
