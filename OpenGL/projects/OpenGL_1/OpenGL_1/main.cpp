#include <iostream>
#include <glut.h>
/*glew��һ����ƽ̨��C++��չ�⣬����OpenGLͼ�νӿ�
  glu��ʵ�ÿ�,����43����������������ǰ׺Ϊglu��Glu Ϊ�˼��ᷱ�صı�̹�������װ��OpenGL������Glu����ͨ�����ú��Ŀ�ĺ�����Ϊ�������ṩ��Լ򵥵��÷���ʵ��һЩ��Ϊ���ӵĲ���
  glaux��OpenGL�����⣬������31��������������ǰ׺Ϊaux���ⲿ�ֺ����ṩ���ڹ���������������Լ�����һЩ����ά���塣
  glut��ʵ�ù��߿⣬�����������������ڽ���ģ������ǿ�ƽ̨��������ʱ��ϲ�����򵥵�demo�Ļ������Թ���glut��ok�ˣ�

  <GL/gl.h>��OpenGL��ʹ�õĺ����ͳ���������
  <GL/glu.h>��GLU��OpenGLʵ�ÿ⣩��ʹ�õĺ����ͳ���������GLU������OpenGL��׼��һ���֡�
  <GL/glaux.h>��GLAUX��OpenGL�����⣩��ʹ�õĺ����ͳ���������
  <GL/glut.h>��GLUT��OpenGLʵ�ù��߰�����ʹ�õĺ����ͳ���������
  <GL/glext.h>����չͷ�ļ���
  <GL/wglext.h>����չͷ�ļ���
*/
using namespace std;

//��һ��OPENGL��������һ������ɫ�Ŀմ���
/*
void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT); //����ض��Ļ�������ɫ(����������ͼ����Ϣ�Ĵ洢��,ͼ��ĺ�����ɫֵͨ������Ϊ��ɫ\���ػ�����)
	glFlush(); //��������δִ�е�OPENGL�����ִ�У���ʱδִ��һ�����glClear
}	

void SetupRC()
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); //���������ɫΪ��ɫ
}

int main()
{
	//���ô�����ʾģʽ�������崰��(GLUT_SINGLE)��RGB��ɫģʽ(GLUT_RGB)��
	//�����崰��:���л�ͼ�������ʾ�Ĵ�����ִ�� 
	//RGB��ɫģʽ:ͨ���ṩ�ĺ졢�̡���ɫֵ��ָ����ɫ
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	//�������ڲ�����������Ϊ"OpenGL_1"
	glutCreateWindow("OpenGL_1");

	//������ʾ�ص�����:ֻҪ����Ҫ���ƴ��ڣ�GLUT�ͻ��������ָ�������������ڵ�һ����ʾ����ʱ��
	glutDisplayFunc(RenderScene);

	//��ʼ����ɫ������ֻ����һ��
	SetupRC(); 

	//GLUT������к������˺����ᴦ�������ض��ڲ���ϵͳ����Ϣ�ȣ�ֱ���˳�����ֹ
	glutMainLoop();

	return 0;
}
*/

//��Ļ����(��Ļ����Ϊ0��0��λ�ã�
void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f, 0.0f, 0.0f); //���û��Ʋ������õ���ɫ:��ɫ

	//glRectf(100.0f, 150.0f, 150.0f, 100.0f); //����һ��w:50 h:50�������Σ�x1, y1��:��ʾ������ʼ���꣬�����Ͻǡ�(x2, y2):��ֹ���꣬���½ǡ�
	glRectf(0, 0, 150.0f, 100.0f);
	glFlush();
}

void SetupRC()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //�����ɫΪ��ɫ
}

void ChangeSize(GLsizei w, GLsizei h)
{
	cout<<"w:"<<w<<",h:"<<h<<endl; //300  300

	glViewport(0, 0, w, h); //��Ⱦ��ͼ����

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

	glutCreateWindow("GLRect"); //Ĭ�ϴ�СΪ300*300
	
	glutDisplayFunc(RenderScene);
	
	//���ô��ڸı��Сʱ�Ļص�����
	glutReshapeFunc(ChangeSize); 

	SetupRC();

	glutMainLoop();

	return 0;
}