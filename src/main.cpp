#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
void framebuffer_size_callback(GLFWwindow*window,int width,int height);
void framebuffer_size_callback(GLFWwindow*window,int width,int height){
    glViewport(0,0,width,height);
}
void processInput(GLFWwindow*window);
int main(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
    GLFWwindow*window=glfwCreateWindow(800,600,"LearningOpenGl",NULL,NULL);
if(window==NULL){
    std::cout<<"error to create a window\n";
    glfwTerminate();
    return -1;
}
glfwMakeContextCurrent(window);
if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
    std::cout<<"error to initiate GLAD\n";
    return -1;
} glViewport(0,0,800,600);

glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);
//render
while(!glfwWindowShouldClose(window)){
    processInput(window);
    glClearColor(0.2f,0.3f,0.3f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
}

//myTriiangle:-)
float vertices[]={
    -0.5f,-0.5f,-0.0f,
    -0.5f,-0.5f,-0.0f,
    -0.5f,-0.5f,-0.0f
};
unsigned int VBO;
glGenBuffers(1,&VBO);
glBindBuffer(GL_ARRAY_BUFFER,VBO);
glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
glfwTerminate();
return 0;}
void processInput(GLFWwindow*window){
    if(glfwGetKey(window,GLFW_KEY_ESCAPE)==GLFW_PRESS){
        glfwSetWindowShouldClose(window,true);
    }
}
