#include <iostream>
#include "glut.h" //GLUT���߰��ṩglut��ͷ�ĺ���
#include <math.h>
using namespace std;

/*------------��ʼѧϰʱ�䣺 20150817
--ѧϰ��ַ:
http://blog.csdn.net/slience_perseverance/article/details/8096233
http://www.cnblogs.com/crazyxiaom/articles/2073586.html
--��glBegin()��glEnd()֮��ɵ��õĺ���������
����				��������
glVertext*()	���ö�������
glColor*()		���õ�ǰ��ɫ
glIndex*()		������ɫ��
glNormal*()		���÷�������
glCoord*()		��������
glCallList(),glCallLists() ִ����ʾ�б�
glTexCoord*()	������������
glEdgeFlag*()	���Ʊ߽����
glMaterial*()	���ò���

����				˵��
GL_POINTS		�������㼯
GL_LINES		����˫�����߶�
GL_POLYGON		���������͹�����
GL_TRIANGLES	����������������
GL_QUADS		�����������ı���
GL_LINE_STRIP	���պ�����
GL_LINE_LOOP	�պ�����
GL_TRIANGLE_STRIP	����������������δ�
GL_TRIANGLE_FAN		����������������δ�
GL_QUAD_STRIP	��������ı��δ�

glxxxxxd: ĩ��ĸd�ĺ��壺
b:8λ������GLbype)��Χ:0~127
s:16λ����(GLshort)��Χ:-2^16/2 + 0.5 ~ 2^16/2 - 0.5  (-32768 ~ 32767)
us:16λ�޷���������GLushort)0 ~ 2^16
i:32λ����(GLint��GLsizei)��Χ:-2^32/2 + 0.5 ~ 2^32/2 - 0.5 
f:32λ������(GLfloat��GLclampf) ��Χ:0.0~1.0
d:64λ������(GLdouble��GLdoubled) ��Χ:0.0~1.0
v:��ʾ���ݵļ�������ʹ��ָ�뷽ʽ
*/
const GLfloat Pi = 3.1415926536f;
//------------------------------Exmple1:����һ����ɫ�ľ���-------------------------

//void myDisplay(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT); //�����GL_COLOR_BUFFER_BIT�������ɫ������
//	glRectf(-0.5f, -0.4f, 0.4f, 0.4f); //����һ�����Σ�x, y, width ,height
//	glFlush(); //��������ִ��ǰ���OPENGL����������ڻ������ȴ�
//}
//

//------------------------------Exmple2:����һ��Բ��-------------------------

//
//#include <math.h>
//const int dots = 50;
//const GLfloat R = 0.5f;
//void myDisplay(void)
//{
//	int i;
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0f, 1.0f, 0); // ���û�����ɫ
//	glBegin(GL_POLYGON); //���ƿ�ʼ������λ���ģʽ
//	//glBegin(GL_POINTS); //���ƿ�ʼ��������ģʽ
//	//glBegin(GL_LINES); //���ƿ�ʼ��ֱ�߻���ģʽ
//	//glBegin(GL_LINE_LOOP); //���ƿ�ʼ���պ�ֱ�߻���ģʽ�����ӳ�һ��Բ��
//	//glBegin(GL_LINE_STRIP); //���ƿ�ʼ��������ֱ�߻���ģʽ(��ʼ�����ӵ��յ㣩
//	//glBegin(GL_TRIANGLES); //���ƿ�ʼ�����������������λ���ģʽ
//	for (int i = 0; i < dots; i++)
//	{
//		glVertex2f(R * cos(2 * Pi / dots * i), R * sin(2 * Pi / dots * i));
//	}
//	glEnd(); //���ƽ���
//
//	glFlush();
//}

//------------------------------Exmple3:����һ�������-------------------------
/* ����ǵ�5������
  A
E	B
 D C
*/
//void myDisplay(void)
//{
//	GLfloat a = 1 / (2 - 2 * cos(72 * Pi / 180));
//	GLfloat bx = a * cos(18 * Pi / 180);
//	GLfloat by = a * sin(18 * Pi / 180);
//	GLfloat cy = -a * cos(18 * Pi / 180);
//	GLfloat
//		PointA[2] = {0, a},
//		PointB[2] = {bx, by},
//		PointC[2] = {0.5, cy},
//		PointD[2] = {-0.5, cy},
//		PointE[2] = {-bx, by};
//
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0f, 0, 0);
//	glBegin(GL_LINE_LOOP); //A->C->E->B->D->A��˳�򣬿���һ�ʽ�����ǻ���
//		glVertex2fv(PointA);
//		glVertex2fv(PointC);
//		glVertex2fv(PointE);
//		glVertex2fv(PointB);
//		glVertex2fv(PointD);
//	glEnd();
//	glFlush();
//}

//------------------------------Exmple4:�������Һ���ͼ-------------------------

//const GLfloat factor = 0.1f;
//void myDisplay(void)
//{
//	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(0.0f, 0.0f, 0.0f);
//	glBegin(GL_LINES);
//		glVertex2f(-1.0f, 0.0f);
//		glVertex2f(1.0f, 0.0f);
//		glVertex2f(0.0f, -1.0f);
//		glVertex2f(0.0f, 1.0f);
//	glEnd();
//
//	glColor3f(1.0f, 0.0f, 0.0f);
//	glBegin(GL_LINE_STRIP);
//	for (float x = -1.0f / factor; x < 1.0f / factor; x += 0.01)
//	{
//		glVertex2f(x * factor, sin(x) * factor);
//	}
//	glEnd();
//
//	glFlush();
//}

//------------------------------Exmple5:����������\�����ͼ-------------------------

 //void myDisplay(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	//glBegin(GL_TRIANGLES);	//���������������� ֻ�ܻ��Ƶ���������
//	//glBegin(GL_TRIANGLE_FAN);	//����������������δ�
//	glBegin(GL_TRIANGLE_STRIP);	//����������������δ�
//	//glBegin(GL_POLYGON);		//���������͹�����
//	//glBegin(GL_QUADS);		//�����������ı���
//	//glBegin(GL_QUAD_STRIP);	//��������ı��δ�
//		glVertex2f(-0.5f, 0.5f);
//		glVertex2f(0.5f, 0.5f);
//		glVertex2f(0.0f, -0.5f);
//		glVertex2f(-0.25f, -0.75f);
//		glVertex2f(0.25f, -0.75f);
//
//	glEnd();
//	glFlush();
//}
 
//------------------------------Exmple7:���Ƶ㡢�ߡ�����-------------------------

//
//void myDisplay(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0f, 0.0f, 0.0f);
//	glPointSize(10.0f); //���õ��С
//	glBegin(GL_POINTS);//���ƶ���� ��GL_POINT�������޷���glBegin~glEnd�л��ƣ�
//		glVertex2f(0.0f, 0.0f);
//		glVertex2f(0.5f, 0.5f);
//	glEnd();
//
//	glEnable(GL_LINE_STIPPLE); //���õ㻭�߹���
//	////����ֱ�ߵĵ�ǰ�㻭ģʽ��factor���ظ����ӣ�ÿ�����ص��ظ���,pattern:ģʽ,��λ���λ����)
//	glLineStipple(3 , 0x3f07);  //ģʽ0x3f07(�����ƣ�11111100000111),�Ȼ��Ƶ�λ3�����أ�5λ���գ��ٻ���6������;�ظ�����Ϊ2������6�����أ�10�����գ��ٻ���12������
//	//glLineStipple(1 , 0xffff); // ģʽ0xffff(�����ƣ�111111111111111))��ֱ��
//	//glLineStipple(0 , 0x8001); // ģʽ0x8001(�����ƣ�1000000000000001))
//	glBegin(GL_LINES);
//		glVertex2f(-1.0f, -0.5f);
//		glVertex2f(1.0f, -0.5f);
//	glEnd();
//	glDisable(GL_LINE_STIPPLE); //�رյ㻭�߹���
//
//	glLineWidth(5.0f); //�����߿�
//	glBegin(GL_LINES); //���Ƶ����߶�
//		glVertex2f(-1.0f, 0.0f);
//		glVertex2f(1.0f, 1.0f);
//	glEnd();
//
//	glFlush();
//}

//------------------------------Exmple8:�޳�����ε�һ����󣬱����ŵ������-------------------------

//1:glPolygonMode���ö���λ��Ʒ�ʽ������ or ���棬��� or ���� or ��
//2:glFrontFace����ͶӰ����εĻ��ƻ��Ʒ�����ʱ�뷽�� or ˳ʱ�뷽��
//3:glCullFace�����޳�����enable������disable�رգ����޳����� or �޳�����
//void myDisplay(void)
//{
//	glClearColor(1.0f,1.0f,1.0f,1.0f);
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0f, 0.0f, 0.0f);
//
//	glPolygonMode(GL_FRONT, GL_FILL); //�����������ģʽ
//	glPolygonMode(GL_BACK, GL_LINE); //���÷�������ģʽ
//	glPolygonMode(GL_BACK, GL_POINT); //���÷����ģʽ
//	glFrontFace(GL_CW); //GL_CCW:����ͶӰ�϶���εĶ���˳��Ϊ��ʱ�뷽��ı���Ϊ����
//
//	glBegin(GL_POLYGON);
//		glVertex2f(-0.5f, 0.5f); 
//		glVertex2f(0.5f, 0.5f);
//		glVertex2f(0.5f, -0.5f);
//		glVertex2f(-0.5f, -0.5f);
//	glEnd();
//
////	glPolygonMode(GL_FRONT, GL_FILL); //�����������ģʽ�� 
////	glPolygonMode(GL_BACK, GL_LINE);  //���÷�������ģʽ
////	glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);  //�������桢����㻭ģʽ
////	glFrontFace(GL_CCW); //GL_CCW:����ͶӰ�϶���εĶ���˳��Ϊ��ʱ�뷽��ı���Ϊ����--���Ʒ���
////	glFrontFace(GL_CW); //���ö���ε�����ģʽ��GL_CW:����˳��Ϊ˳ʱ�뷽��ı��汻��Ϊ������
//	
//	glPolygonMode(GL_FRONT, GL_FILL); //�����������ģʽ�� ������䱻�޳���
//	glColor3f(0.0f, 1.0f, 0.0f);
//	glEnable(GL_CULL_FACE); //�����޳�����
//	glCullFace(GL_FRONT); //�޳�����,
//
//	glBegin(GL_POLYGON);
//		glVertex2f(-0.5f, 0.5f); 
//		glVertex2f(0.5f, 0.5f);
//		glVertex2f(0.5f, -0.5f);
//		glVertex2f(-0.5f, -0.5f);
//		
//	glEnd();
//	glDisable(GL_CULL_FACE);
//
//	glFlush();
//}

//------------------------------Exmple9:���Ƶ㻭����Σ��οգ�-------------------------

//1:glPolygonStipple����㻭����enable������disable�رգ��������С128���ļ�ָ������
//#include <stdio.h>
//#include <stdlib.h>
////static GLubyte Mask[128] = 
////{
////
////     0x00, 0x00, 0x00, 0x00,    //   �����������һ��
////
////     0x00, 0x00, 0x00, 0x00,
////
////     0x03, 0x80, 0x01, 0xC0,    //   ��
////
////     0x06, 0xC0, 0x03, 0x60,    //   ��
////
////     0x04, 0x60, 0x06, 0x20,    //   ��
////
////     0x04, 0x30, 0x0C, 0x20,    //   ��
////
////     0x04, 0x18, 0x18, 0x20,    //   ʼ
////
////     0x04, 0x0C, 0x30, 0x20,    //   ��
////
////     0x04, 0x06, 0x60, 0x20,    //   ��
////
////     0x44, 0x03, 0xC0, 0x22,    //   ��
////
////     0x44, 0x01, 0x80, 0x22,    //   ��
////
////     0x44, 0x01, 0x80, 0x22,    //   ��
////
////     0x44, 0x01, 0x80, 0x22,    //   ʹ
////
////     0x44, 0x01, 0x80, 0x22,    //   ��
////
////     0x44, 0x01, 0x80, 0x22,
////
////     0x44, 0x01, 0x80, 0x22,
////
////     0x66, 0x01, 0x80, 0x66,
////
////     0x33, 0x01, 0x80, 0xCC,
////
////     0x19, 0x81, 0x81, 0x98,
////
////     0x0C, 0xC1, 0x83, 0x30,
////
////     0x07, 0xE1, 0x87, 0xE0,
////
////     0x03, 0x3F, 0xFC, 0xC0,
////
////     0x03, 0x31, 0x8C, 0xC0,
////
////     0x03, 0x3F, 0xFC, 0xC0,
////
////     0x06, 0x64, 0x26, 0x60,
////
////     0x0C, 0xCC, 0x33, 0x30,
////
////     0x18, 0xCC, 0x33, 0x18,
////
////     0x10, 0xC4, 0x23, 0x08,
////
////     0x10, 0x63, 0xC6, 0x08,
////
////     0x10, 0x30, 0x0C, 0x08,
////
////     0x10, 0x18, 0x18, 0x08,
////
////     0x10, 0x00, 0x00, 0x08    // �����������һ��
////
////};
//void myDisplay(void)
//{
//	static GLubyte Mask[128]; //��128 ��128
//	FILE *fp;
//	fp = fopen("Resource/mask.bmp", "rb"); //��������ĸ߶�:32 ���:32 ��ɫλͼͼƬ
//	if (!fp)
//		exit(0);
//
//	if (fseek(fp, -(int)sizeof(Mask), SEEK_END)) //�ƶ��ļ�ָ�뵽-(int)sizeof(Mask)���λ��
//		exit(0);
//
//	if (!fread(Mask, sizeof(Mask), 1, fp)) //��ȡ sizeof(Mask)���ֽڵ�Mask
//		exit(0);
//	fclose(fp);
//
//	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0f, 0.0f, 0.0f);
//
//	glEnable(GL_POLYGON_STIPPLE); //��������ε㻭ģʽ
//	glPolygonStipple(Mask); //����㻭ģʽ��Mask:��һ��ָ��32*32��λͼָ�루0��1�����룺1���ƣ�0�������ƣ�
//	glRectf(-0.5f, -0.5f, 0.0f, 0.0f); //����128/32=4��ͼƬ
//	
//	glDisable(GL_POLYGON_STIPPLE); //�رն���ε㻭ģʽ
//	glColor3f(0.0f, 0.0f, 1.0f);
//	glRectf(0.0f, 0.0f, 0.5f, 0.5f);
//	glFlush();
//}

//------------------------------Exmple10:����ָ����ɫ��ɫ��8����-------------------------

//1:glClearColor�����������Ļ��ʣ����ɫ
//2:glShadeModel������ɫ��䷽ʽ������orƽ��
//void myDisplay(void)
//{
////	glShadeModel(GL_FLAT); //����ģ�͵�����ʽ
//	glShadeModel(GL_SMOOTH); //����ģ��ƽ����ʽ
//	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glBegin(GL_TRIANGLE_FAN);
//	glColor3f(1.0f, 1.0f, 1.0f); //���ð�ɫΪָ�������ɫ����ͬ�����ɫ�����Ƴ���ģ����ɫֵ��ͬ
//	glVertex2f(0.0f, 0.0f);
//	for (int i = 0; i <= 8; ++i)
//	{
//		glColor3f(i & 0x04, i & 0x02, i & 0x01);
//		glVertex2f((float)cos(i * Pi / 4), (float)sin(i * Pi / 4));
//	}
//	glEnd();
//	glFlush();
//}

//
//int main(int argc, char *argv[]) //argc: argument component����������argv[]��argument value����ֵ
//{
//	//��GLUT���г�ʼ��
//	glutInit(&argc, argv); 
//
//	//��ʼ����ʾģʽ��ʹ��arg��ɫ�Լ�������()
//	//GLUT_SINGLE�����壺�����е�ָ���ڴ�����ִ�У�ֱ���ڴ����ϻ�ͼ��Ч�ʵͣ������������ڵ���ֻ��ʾ���Ƕ�̬��ͼƬ
//	//GLUT_DOUBLE˫���壺��ͼָ����һ����������ɣ�ָ�����֮��ͨ������ָ�����ɵ�ͼ��������ʾ����Ļ�ϣ�Ч�ʺܿ졣OPENGL��ͼ���ô˷�����
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); 
//	
//	//���ô�������ʾ��Ļ�е�λ��(��Ļ����Ϊԭ��)
//	glutInitWindowPosition(100, 600); 
//
//	//���ô��ڵĳߴ�
//	glutInitWindowSize(400, 400);
//
//	//�������ڲ�����title�������glutMainLoop���ܿ�������
//	glutCreateWindow("һ��Ҫ��ְ���OpenGL");
//
//	//���û�ͼ����
//	glutDisplayFunc(&myDisplay);
//
//	//������Ϣѭ�������ڹرղŻ᷵��
//	glutMainLoop();
//
//	return 0;
//}


//------------------------------��ά�任-------------------------
/*
1.��ͼ�任����������̶������ż��ϲ�ʹ����׼���� 
	gluLookAt()�������������λ��,ǰ����������ʾ�۲���λ�ã��м�����������ʾ�۲�Ŀ���λ�ã���������ʾ�ӣ�0,0,0����(x,y,z)��ֱ�ߣ��۲�����Ϊ�ġ��ϡ��ķ���
2.ģ�ͱ任������ģ�͵�λ�úͷ���
	glTranslate*():�ѵ�ǰ������һ����ʾ�ƶ�����ľ�����ˣ�����������ʾ�������ϵ�λ��ֵ
	glScale*():�ѵ�ǰ������һ����ʾ��������ľ�����ˣ�����������ʾ�÷����ϵ����ű���
	glRotate*():�ѵ�ǰ������һ����ʾ��ת������ľ�����ˣ����彫����ԭ��(0,0,0)������(x,y,z)�ķ�����ʱ����ת��angle��ʾ�Ƕ�
3.ͶӰ�仯��Ϊ�����ѡ��ͷ 
	glFrustum()��ָ��ʹ��͸��ͶӰ(ʹԶ�������忴��ȥСһ��) 
	glOrtho(): ����һ���������Ӿ��壬ָ����ͶӰ��������ֱ��ӳ������Ļ�ϣ�����Ӱ�����ǵ���Դ�С��
4.�ӿڱ任�������˳�����ӳ�����Ч��Ļ�������״
	glViewport()��ָ�������ڲ���Ч��Ļ�ռ��ԭ�㡢���
---
glMatrixMode() :ָ���޸ĵ�ģ�;���(GL_MODEVIEW:ģ����ͼ����GL_PROJECTION:ͶӰ����GL_TEXTURE:�������
glLoadIdentity():�ѵ�ǰ�Ŀ��޸ľ�������Ϊ4*4�ĵ�λ���󣬹�δ���ı任����ʹ�ã���ͶӰ����ͼ�任ǰ����

PS: 1.����任˳���������ָ����˳�����෴��
	2.������ת��ʱ������ϵͳ����������ת���ƶ���ʱ������ϵͳ���������ƶ�

*/

//------------------------------Exmple12:����һ��͸��ͶӰ��������-------------------------

//void myDisplay(void)
//{
//	glShadeModel(GL_FLAT);
//	
////----------step3: ģ�ͱ任 begin------
//	glMatrixMode(GL_MODELVIEW); //�ѵ�ǰ����ָ��Ϊ����ģ����ͼ�任(GL_MODELVIEW��ģ����ͼ����)
//
//	glLoadIdentity(); //ģ����ͼ������г�ʼ��
////------------step3.1: ��ͼ�任 ----------
////	gluLookAt(0.0f,0.0f,5.0f, 0.0f,0.0f,0.0f, 0.0f,1.0f,0.0f); //��ͼ�任�������������λ�ã�x:0,y:0,z:5)�������ӽǣ�x:0,y:0,z:0����������(x:0,y:1,z:0)
//
////------------step3.1: ʹ��ģ�ͱ任 ----------
//	glTranslatef(0.0f, 0.0f, -5.0f); //ģ�ͱ任������ǰ������һ����ʾ�ƶ����������(x:0,y:0,z:-5)���
//
//	glScalef(1.0f, 2.0f, 1.0f); //ģ�ͱ任�����������壨x:1, y:2���� z:1 �����ǳ������ĳ����壩;
//
//	glutWireCube(2.0f); // �����߿�������
////------------step3: ģ�ͱ任 end----------
//	glFlush();
//}
//
//void reshape(int w, int h)
//{
////----------step1: �ӿڱ任 -------
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h); //ָ���ӿڣ���ȡ��߶�δָ�������Ǵ��ڵĿ��ߣ�
//
////----------step2: ͶӰ�任 begin-------
//	glMatrixMode(GL_PROJECTION); //�ѵ�ǰ����ָ��Ϊ����ͶӰ�任(GL_PROJECTION��ͶӰ����)
//
//	glLoadIdentity();//�Ե�ǰ��ͶӰ������г�ʼ��
//
//	glFrustum(-1.0f, 1.0f, -1.0f, 1.0f, 1.5f, 20.0f); //����һ����ʾ͸����ͼƽ��ͷ��ľ��󣬲������뵱ǰ�ľ������()
//
////	gluPerspective(
//	//-----------step2:ͶӰ�任 end-----------
//}

//------------------------------Exmple12:ģ����ͼ�任˳��-------------------------

//
//void myDisplay(void)
//{
//	glMatrixMode(GL_MODELVIEW);
//
//	glLoadIdentity();
//	
//	//gluLookAt(0.0f, 0.0f, 2.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.5f, 0.0f);
//	//glTranslatef(N); //�ѵ�ǰ������һ����ʾ����ľ���N���
//
//	//glTranslatef(M); //�ѵ�ǰ������һ����ʾ����ľ���M���
//
//	//glTranslatef(L); //�ѵ�ǰ������һ����ʾ����ľ���L���
//
//	//glBegin(GL_POINTS); //���ƶ����ģʽ
//	//	glVertex3f(v); //���ƶ���v
//	//glEnd() //��������
//
//// ģ����ͼ����˳��ֱ�����ˣ�I��N��M��L��I��ʾ��λ�������ΪNML, �����任�Ķ�����NMLv,��˱任����N(M(Lv)),
////   v������L��ˣ�Lv����M��ˣ�MLv����N��ˡ�����v�ı任˳���ǰ����෴��˳�����ġ�
//
//	glTranslatef(0, 2, -5); //3��λ��
//
//	glScalef(5, 5, -5); //2���Ŵ�
//
//	glRotatef(90, 0, 0, -5); //1������ת
//
//	glBegin(GL_LINES);
//		glVertex2f(0, 0.5);
//		glVertex2f(1, 0.5);
//	glEnd();
//
//	glFlush();
//}


//��ʼ��
void init(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_FLAT);
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	//glFrustum(-1.0f, 1.0f, -1.0f, 1.0f, 1.5f, 20.0f);
	if (w <= h)
		glOrtho(-50.0, 50.0, -50.0 * (GLsizei)h /(GLsizei)w, 50 * (GLsizei)h / (GLsizei)w, -1.0, 1.0);
	else
		glOrtho(-50.0 * (GLsizei)w / (GLsizei)h, 50.0 * (GLsizei)w / (GLsizei)h, -50.0, 50.0, -1.0, 1.0);


	glMatrixMode(GL_MODELVIEW);
}

void drawTriangle()
{
	glBegin(GL_LINE_LOOP);
		//glVertex2f(0.0, 0.0);  //ԭ��Ϊ��Ļ���ĵ�
		glVertex2f(0.0, 25.0); 
		glVertex2f(25.0, -25.0);
		glVertex2f(-25.0, -25.0);
	glEnd();
}

void myDisplay(void)
{
	glLoadIdentity(); //�������ģ�͵ı仯Ч�����Ծ���ֵ���г�ʼ������ֹ�����任�����ۻ�Ч��(Ч�ʵ�)
	glColor3f(1.0f, 1.0f, 1.0f);
	drawTriangle(); //����һ���߿�������

	glEnable(GL_LINE_STIPPLE); //����һ�������ߵ�������
	glLineStipple(1, 0xf0f0);
	glLoadIdentity();
	glTranslatef(-20.0, 0.0, 0.0); //��X�������ƶ�20������
	drawTriangle();
	
	glLineStipple(1, 0xf00f); //�ٻ���һ�������ߵ�������
	glLoadIdentity();
	glScalef(1.5, 0.5, 1.0); //�����γ��Ŵ�1.5��������С0.5��
	drawTriangle();

	glLineStipple(1, 0x8888); //�ڻ���һ����������
	glLoadIdentity();
	glRotatef(90.0, 0.0, 0.0, 1.0); //��ת90�ȣ�ģ��������ϵһͬ��ʱ����ת
	drawTriangle();
	glDisable(GL_LINE_STIPPLE);

	glFlush();
}

int main(int argc, char *argv[]) //argc: argument component����������argv[]��argument value����ֵ
{
	//��GLUT���г�ʼ��
	glutInit(&argc, argv); 

	//��ʼ����ʾģʽ��ʹ��arg��ɫ�Լ�������()
	//GLUT_SINGLE�����壺�����е�ָ���ڴ�����ִ�У�ֱ���ڴ����ϻ�ͼ��Ч�ʵͣ������������ڵ���ֻ��ʾ���Ƕ�̬��ͼƬ
	//GLUT_DOUBLE˫���壺��ͼָ����һ����������ɣ�ָ�����֮��ͨ������ָ�����ɵ�ͼ��������ʾ����Ļ�ϣ�Ч�ʺܿ졣OPENGL��ͼ���ô˷�����
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); 
	
	//���ô�������ʾ��Ļ�е�λ��(��Ļ����Ϊԭ��)
	glutInitWindowPosition(100, 400); 

	//���ô��ڵĳߴ�
	glutInitWindowSize(500, 500);

	//�������ڲ�����title�������glutMainLoop���ܿ�������
	glutCreateWindow("һ��Ҫ��ְ���OpenGL");

	//��ʼ��
	init();

	//���û�ͼ����
	glutDisplayFunc(&myDisplay);

	//���ڴ�С�ı亯��
	glutReshapeFunc(reshape); 

	//������Ϣѭ�������ڹرղŻ᷵��
	glutMainLoop();

	return 0;
}
