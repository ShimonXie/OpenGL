#include <iostream>
#include <glut.h>
/*glew是一个跨平台的C++扩展库，基于OpenGL图形接口
  glu是实用库,包含43个函数，函数名的前缀为glu。Glu 为了减轻繁重的编程工作，封装了OpenGL函数，Glu函数通过调用核心库的函数，为开发者提供相对简单的用法，实现一些较为复杂的操作
  glaux是OpenGL辅助库，包含有31个函数，函数名前缀为aux。这部分函数提供窗口管理、输入输出处理以及绘制一些简单三维物体。
  glut是实用工具库，基本上是用于做窗口界面的，并且是跨平台（所以有时你喜欢做简单的demo的话，可以光用glut就ok了）

  <GL/gl.h>：OpenGL所使用的函数和常量声明。
  <GL/glu.h>：GLU（OpenGL实用库）所使用的函数和常量声明。GLU库属于OpenGL标准的一部分。
  <GL/glaux.h>：GLAUX（OpenGL辅助库）所使用的函数和常量声明。
  <GL/glut.h>：GLUT（OpenGL实用工具包）所使用的函数和常量声明。
  <GL/glext.h>：扩展头文件。
  <GL/wglext.h>：扩展头文件。
*/
using namespace std;

//第一个OPENGL程序：生成一个带蓝色的空窗口
/*
void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT); //清除特定的缓冲区颜色(缓冲区：是图像信息的存储区,图像的红绿蓝色值通常被称为颜色\像素缓冲区)
	glFlush(); //让所有尚未执行的OPENGL命令都被执行，此时未执行一条命令：glClear
}	

void SetupRC()
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); //设置清除颜色为蓝色
}

int main()
{
	//设置窗口显示模式（单缓冲窗口(GLUT_SINGLE)和RGB颜色模式(GLUT_RGB)）
	//单缓冲窗口:所有绘图命令都在显示的窗口中执行 
	//RGB颜色模式:通过提供的红、绿、蓝色值来指定颜色
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	//创建窗口并将标题设置为"OpenGL_1"
	glutCreateWindow("OpenGL_1");

	//设置显示回调函数:只要有需要绘制窗口，GLUT就会调用这里指定函数（比如在第一次显示窗口时候）
	glutDisplayFunc(RenderScene);

	//初始化颜色函数，只掉用一次
	SetupRC(); 

	//GLUT框架运行函数，此函数会处理所有特定于操作系统的消息等，直到此程序终止
	glutMainLoop();

	return 0;
}
*/

//屏幕坐标(屏幕中心为0，0点位置）
void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f, 0.0f, 0.0f); //设置绘制操作所用的颜色:红色

	//glRectf(100.0f, 150.0f, 150.0f, 100.0f); //绘制一个w:50 h:50的填充矩形（x1, y1）:表示矩形起始坐标，在左上角。(x2, y2):终止坐标，右下角。
	glRectf(0, 0, 150.0f, 100.0f);
	glFlush();
}

void SetupRC()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //清除颜色为白色
}

void ChangeSize(GLsizei w, GLsizei h)
{
	cout<<"w:"<<w<<",h:"<<h<<endl; //300  300

	glViewport(0, 0, w, h); //渲染视图窗口

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	if (w <= h) 
		glOrtho(0.0f, 250.0f, 0.0f, 250.0f*h/w, 1.0, -1.0);
	else
		glOrtho(0.0f, 250.0f*w/h, 0.0f, 250.0f, 1.0, -1.0);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
}

int main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutCreateWindow("GLRect"); //默认大小为300*300
	
	glutDisplayFunc(RenderScene);
	
	//设置窗口改变大小时的回调函数
	glutReshapeFunc(ChangeSize); 

	SetupRC();

	glutMainLoop();

	return 0;
}