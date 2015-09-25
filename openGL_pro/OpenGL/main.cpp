#include <iostream>
#include "glut.h" //GLUT工具包提供glut开头的函数
#include <math.h>
using namespace std;

/*------------开始学习时间： 20150817
--学习地址:
http://blog.csdn.net/slience_perseverance/article/details/8096233
http://www.cnblogs.com/crazyxiaom/articles/2073586.html
--在glBegin()和glEnd()之间可调用的函数和类型
函数				函数意义
glVertext*()	设置顶点坐标
glColor*()		设置当前颜色
glIndex*()		设置颜色表
glNormal*()		设置法向坐标
glCoord*()		产生坐标
glCallList(),glCallLists() 执行显示列表
glTexCoord*()	设置纹理坐标
glEdgeFlag*()	控制边界绘制
glMaterial*()	设置材质

类型				说明
GL_POINTS		单个顶点集
GL_LINES		多组双顶点线段
GL_POLYGON		单个简单填充凸多边形
GL_TRIANGLES	多组独立填充三角形
GL_QUADS		多组独立填充四边形
GL_LINE_STRIP	不闭合折线
GL_LINE_LOOP	闭合折线
GL_TRIANGLE_STRIP	线形连续填充三角形串
GL_TRIANGLE_FAN		扇形连续填充三角形串
GL_QUAD_STRIP	连续填充四边形串

glxxxxxd: 末字母d的含义：
b:8位整数（GLbype)范围:0~127
s:16位整数(GLshort)范围:-2^16/2 + 0.5 ~ 2^16/2 - 0.5  (-32768 ~ 32767)
us:16位无符号整数（GLushort)0 ~ 2^16
i:32位整数(GLint和GLsizei)范围:-2^32/2 + 0.5 ~ 2^32/2 - 0.5 
f:32位浮点数(GLfloat和GLclampf) 范围:0.0~1.0
d:64位浮点数(GLdouble和GLdoubled) 范围:0.0~1.0
v:表示传递的几个参数使用指针方式
*/
const GLfloat Pi = 3.1415926536f;
//------------------------------Exmple1:绘制一个白色的矩形-------------------------

//void myDisplay(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT); //清除，GL_COLOR_BUFFER_BIT：清除颜色缓冲区
//	glRectf(-0.5f, -0.4f, 0.4f, 0.4f); //绘制一个矩形，x, y, width ,height
//	glFlush(); //设置立即执行前面的OPENGL命令，而不是在缓冲区等待
//}
//

//------------------------------Exmple2:绘制一个圆形-------------------------

//
//#include <math.h>
//const int dots = 50;
//const GLfloat R = 0.5f;
//void myDisplay(void)
//{
//	int i;
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0f, 1.0f, 0); // 设置绘制颜色
//	glBegin(GL_POLYGON); //绘制开始：多边形绘制模式
//	//glBegin(GL_POINTS); //绘制开始：多点绘制模式
//	//glBegin(GL_LINES); //绘制开始：直线绘制模式
//	//glBegin(GL_LINE_LOOP); //绘制开始：闭合直线绘制模式（连接成一个圆）
//	//glBegin(GL_LINE_STRIP); //绘制开始：连续的直线绘制模式(初始点连接到终点）
//	//glBegin(GL_TRIANGLES); //绘制开始：多组独立填充三角形绘制模式
//	for (int i = 0; i < dots; i++)
//	{
//		glVertex2f(R * cos(2 * Pi / dots * i), R * sin(2 * Pi / dots * i));
//	}
//	glEnd(); //绘制结束
//
//	glFlush();
//}

//------------------------------Exmple3:绘制一个五角星-------------------------
/* 五角星的5个顶点
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
//	glBegin(GL_LINE_LOOP); //A->C->E->B->D->A的顺序，可以一笔将五角星画出
//		glVertex2fv(PointA);
//		glVertex2fv(PointC);
//		glVertex2fv(PointE);
//		glVertex2fv(PointB);
//		glVertex2fv(PointD);
//	glEnd();
//	glFlush();
//}

//------------------------------Exmple4:绘制正弦函数图-------------------------

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

//------------------------------Exmple5:绘制三角形\多边形图-------------------------

 //void myDisplay(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	//glBegin(GL_TRIANGLES);	//多组独立填充三角形 只能绘制单个三角形
//	//glBegin(GL_TRIANGLE_FAN);	//扇形连续填充三角形串
//	glBegin(GL_TRIANGLE_STRIP);	//线形连续填充三角形串
//	//glBegin(GL_POLYGON);		//单个简单填充凸多边形
//	//glBegin(GL_QUADS);		//多组独立填充四边形
//	//glBegin(GL_QUAD_STRIP);	//连续填充四边形串
//		glVertex2f(-0.5f, 0.5f);
//		glVertex2f(0.5f, 0.5f);
//		glVertex2f(0.0f, -0.5f);
//		glVertex2f(-0.25f, -0.75f);
//		glVertex2f(0.25f, -0.75f);
//
//	glEnd();
//	glFlush();
//}
 
//------------------------------Exmple7:绘制点、线、点线-------------------------

//
//void myDisplay(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0f, 0.0f, 0.0f);
//	glPointSize(10.0f); //设置点大小
//	glBegin(GL_POINTS);//绘制多个点 （GL_POINT单个点无法在glBegin~glEnd中绘制）
//		glVertex2f(0.0f, 0.0f);
//		glVertex2f(0.5f, 0.5f);
//	glEnd();
//
//	glEnable(GL_LINE_STIPPLE); //启用点画线功能
//	////设置直线的当前点画模式（factor：重复因子，每个像素的重复数,pattern:模式,低位向高位绘制)
//	glLineStipple(3 , 0x3f07);  //模式0x3f07(二进制：11111100000111),先绘制低位3个像素，5位留空，再绘制6个像素;重复因子为2：绘制6个像素，10个留空，再绘制12个像素
//	//glLineStipple(1 , 0xffff); // 模式0xffff(二进制：111111111111111))，直线
//	//glLineStipple(0 , 0x8001); // 模式0x8001(二进制：1000000000000001))
//	glBegin(GL_LINES);
//		glVertex2f(-1.0f, -0.5f);
//		glVertex2f(1.0f, -0.5f);
//	glEnd();
//	glDisable(GL_LINE_STIPPLE); //关闭点画线功能
//
//	glLineWidth(5.0f); //设置线宽
//	glBegin(GL_LINES); //绘制单条线段
//		glVertex2f(-1.0f, 0.0f);
//		glVertex2f(1.0f, 1.0f);
//	glEnd();
//
//	glFlush();
//}

//------------------------------Exmple8:剔除多边形的一个面后，被挡着的面出现-------------------------

//1:glPolygonMode设置多边形绘制方式：正面 or 反面，填充 or 线性 or 点
//2:glFrontFace设置投影多边形的环绕绘制方向：逆时针方向 or 顺时针方向
//3:glCullFace设置剔除（需enable开启和disable关闭）：剔除正面 or 剔除反面
//void myDisplay(void)
//{
//	glClearColor(1.0f,1.0f,1.0f,1.0f);
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0f, 0.0f, 0.0f);
//
//	glPolygonMode(GL_FRONT, GL_FILL); //设置正面填充模式
//	glPolygonMode(GL_BACK, GL_LINE); //设置反面线性模式
//	glPolygonMode(GL_BACK, GL_POINT); //设置反面点模式
//	glFrontFace(GL_CW); //GL_CCW:窗口投影上多边形的顶点顺序为逆时针方向的表面为正面
//
//	glBegin(GL_POLYGON);
//		glVertex2f(-0.5f, 0.5f); 
//		glVertex2f(0.5f, 0.5f);
//		glVertex2f(0.5f, -0.5f);
//		glVertex2f(-0.5f, -0.5f);
//	glEnd();
//
////	glPolygonMode(GL_FRONT, GL_FILL); //设置正面填充模式， 
////	glPolygonMode(GL_BACK, GL_LINE);  //设置反面线性模式
////	glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);  //设置正面、反面点画模式
////	glFrontFace(GL_CCW); //GL_CCW:窗口投影上多边形的顶点顺序为逆时针方向的表面为正面--环绕方向
////	glFrontFace(GL_CW); //设置多边形的正面模式：GL_CW:顶点顺序为顺时针方向的表面被认为是正面
//	
//	glPolygonMode(GL_FRONT, GL_FILL); //设置正面填充模式， 正面填充被剔除了
//	glColor3f(0.0f, 1.0f, 0.0f);
//	glEnable(GL_CULL_FACE); //启用剔除功能
//	glCullFace(GL_FRONT); //剔除正面,
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

//------------------------------Exmple9:绘制点画多边形（镂空）-------------------------

//1:glPolygonStipple定义点画（需enable开启和disable关闭）：传入大小128的文件指针数组
//#include <stdio.h>
//#include <stdlib.h>
////static GLubyte Mask[128] = 
////{
////
////     0x00, 0x00, 0x00, 0x00,    //   这是最下面的一行
////
////     0x00, 0x00, 0x00, 0x00,
////
////     0x03, 0x80, 0x01, 0xC0,    //   麻
////
////     0x06, 0xC0, 0x03, 0x60,    //   烦
////
////     0x04, 0x60, 0x06, 0x20,    //   的
////
////     0x04, 0x30, 0x0C, 0x20,    //   初
////
////     0x04, 0x18, 0x18, 0x20,    //   始
////
////     0x04, 0x0C, 0x30, 0x20,    //   化
////
////     0x04, 0x06, 0x60, 0x20,    //   ，
////
////     0x44, 0x03, 0xC0, 0x22,    //   不
////
////     0x44, 0x01, 0x80, 0x22,    //   建
////
////     0x44, 0x01, 0x80, 0x22,    //   议
////
////     0x44, 0x01, 0x80, 0x22,    //   使
////
////     0x44, 0x01, 0x80, 0x22,    //   用
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
////     0x10, 0x00, 0x00, 0x08    // 这是最上面的一行
////
////};
//void myDisplay(void)
//{
//	static GLubyte Mask[128]; //长128 宽128
//	FILE *fp;
//	fp = fopen("Resource/mask.bmp", "rb"); //代替数组的高度:32 宽度:32 单色位图图片
//	if (!fp)
//		exit(0);
//
//	if (fseek(fp, -(int)sizeof(Mask), SEEK_END)) //移动文件指针到-(int)sizeof(Mask)这个位置
//		exit(0);
//
//	if (!fread(Mask, sizeof(Mask), 1, fp)) //读取 sizeof(Mask)个字节到Mask
//		exit(0);
//	fclose(fp);
//
//	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0f, 0.0f, 0.0f);
//
//	glEnable(GL_POLYGON_STIPPLE); //启动多边形点画模式
//	glPolygonStipple(Mask); //定义点画模式：Mask:是一个指向32*32的位图指针（0和1的掩码：1绘制，0：不绘制）
//	glRectf(-0.5f, -0.5f, 0.0f, 0.0f); //长宽128/32=4张图片
//	
//	glDisable(GL_POLYGON_STIPPLE); //关闭多边形点画模式
//	glColor3f(0.0f, 0.0f, 1.0f);
//	glRectf(0.0f, 0.0f, 0.5f, 0.5f);
//	glFlush();
//}

//------------------------------Exmple10:绘制指定着色颜色的8边形-------------------------

//1:glClearColor设置清楚后屏幕所剩的颜色
//2:glShadeModel设置颜色填充方式：单调or平滑
//void myDisplay(void)
//{
////	glShadeModel(GL_FLAT); //设置模型单调方式
//	glShadeModel(GL_SMOOTH); //设置模型平滑方式
//	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glBegin(GL_TRIANGLE_FAN);
//	glColor3f(1.0f, 1.0f, 1.0f); //设置白色为指定的清除色，不同的清除色，绘制出的模型颜色值不同
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
//int main(int argc, char *argv[]) //argc: argument component变量个数，argv[]：argument value变量值
//{
//	//对GLUT进行初始化
//	glutInit(&argc, argv); 
//
//	//初始化显示模式：使用arg颜色以及单缓冲()
//	//GLUT_SINGLE单缓冲：将所有的指令在窗口上执行，直接在窗口上绘图，效率低，易闪屏。用于单独只显示幅非动态的图片
//	//GLUT_DOUBLE双缓冲：绘图指令在一个缓冲区完成，指令完成之后，通过交换指令把完成的图像立即显示在屏幕上，效率很快。OPENGL绘图常用此方法。
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); 
//	
//	//设置窗口在显示屏幕中的位置(屏幕左上为原点)
//	glutInitWindowPosition(100, 600); 
//
//	//设置窗口的尺寸
//	glutInitWindowSize(400, 400);
//
//	//创建窗口并设置title，需调用glutMainLoop才能看到窗口
//	glutCreateWindow("一定要坚持啊！OpenGL");
//
//	//设置绘图函数
//	glutDisplayFunc(&myDisplay);
//
//	//进行消息循环，窗口关闭才会返回
//	glutMainLoop();
//
//	return 0;
//}


//------------------------------三维变换-------------------------
/*
1.视图变换：将照相机固定在三脚架上并使它对准场景 
	gluLookAt()：设置照相机的位置,前三个参数表示观察点的位置，中间三个参数表示观察目标的位置，后三个表示从（0,0,0）到(x,y,z)的直线，观察者认为的“上”的方向
2.模型变换：设置模型的位置和方向
	glTranslate*():把当前矩阵与一个表示移动物体的矩阵相乘，三个参数表示三个左上的位移值
	glScale*():把当前矩阵与一个表示缩放物体的矩阵相乘，三个参数表示该方向上的缩放比例
	glRotate*():把当前矩阵与一个表示旋转的物体的矩阵相乘，物体将绕着原点(0,0,0)到参数(x,y,z)的方向逆时针旋转，angle表示角度
3.投影变化：为照相机选择镜头 
	glFrustum()：指定使用透视投影(使远处的物体看上去小一点) 
	glOrtho(): 创建一个正交的视景体，指定正投影（把物体直接映射在屏幕上，而不影响它们的相对大小）
4.视口变换：决定了场景所映射的有效屏幕区域的形状
	glViewport()：指定窗口内部有效屏幕空间的原点、宽高
---
glMatrixMode() :指定修改的模型矩阵(GL_MODEVIEW:模型视图矩阵，GL_PROJECTION:投影矩阵，GL_TEXTURE:纹理矩阵）
glLoadIdentity():把当前的可修改矩阵设置为4*4的单位矩阵，供未来的变换函数使用，在投影或视图变换前调用

PS: 1.矩阵变换顺序是与代码指定的顺序是相反的
	2.物体旋转的时候，坐标系统随着物体旋转；移动的时候，坐标系统随着物体移动

*/

//------------------------------Exmple12:绘制一个透视投影的立方体-------------------------

//void myDisplay(void)
//{
//	glShadeModel(GL_FLAT);
//	
////----------step3: 模型变换 begin------
//	glMatrixMode(GL_MODELVIEW); //把当前矩阵指定为用于模型视图变换(GL_MODELVIEW：模型视图矩阵)
//
//	glLoadIdentity(); //模型视图矩阵进行初始化
////------------step3.1: 视图变换 ----------
////	gluLookAt(0.0f,0.0f,5.0f, 0.0f,0.0f,0.0f, 0.0f,1.0f,0.0f); //视图变换，设置照相机的位置（x:0,y:0,z:5)、中心视角（x:0,y:0,z:0）朝上向量(x:0,y:1,z:0)
//
////------------step3.1: 使用模型变换 ----------
//	glTranslatef(0.0f, 0.0f, -5.0f); //模型变换，将当前矩阵与一个表示移动的物体矩阵(x:0,y:0,z:-5)相乘
//
//	glScalef(1.0f, 2.0f, 1.0f); //模型变换，设置立方体（x:1, y:2倍， z:1 ，高是长两倍的长方体）;
//
//	glutWireCube(2.0f); // 绘制线框立方体
////------------step3: 模型变换 end----------
//	glFlush();
//}
//
//void reshape(int w, int h)
//{
////----------step1: 视口变换 -------
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h); //指定视口（宽度、高度未指定，而是窗口的宽、高）
//
////----------step2: 投影变换 begin-------
//	glMatrixMode(GL_PROJECTION); //把当前矩阵指定为用于投影变换(GL_PROJECTION：投影矩阵)
//
//	glLoadIdentity();//对当前的投影矩阵进行初始化
//
//	glFrustum(-1.0f, 1.0f, -1.0f, 1.0f, 1.5f, 20.0f); //定义一个表示透视视图平截头体的矩阵，并把它与当前的矩阵相乘()
//
////	gluPerspective(
//	//-----------step2:投影变换 end-----------
//}

//------------------------------Exmple12:模型视图变换顺序-------------------------

//
//void myDisplay(void)
//{
//	glMatrixMode(GL_MODELVIEW);
//
//	glLoadIdentity();
//	
//	//gluLookAt(0.0f, 0.0f, 2.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.5f, 0.0f);
//	//glTranslatef(N); //把当前矩阵与一个表示物体的矩阵N相乘
//
//	//glTranslatef(M); //把当前矩阵与一个表示物体的矩阵M相乘
//
//	//glTranslatef(L); //把当前矩阵与一个表示物体的矩阵L相乘
//
//	//glBegin(GL_POINTS); //绘制多个点模式
//	//	glVertex3f(v); //绘制顶点v
//	//glEnd() //结束绘制
//
//// 模型视图矩阵按顺序分别包含了：I、N、M、L，I表示单位矩阵，最后为NML, 经过变换的顶点是NMLv,因此变换就是N(M(Lv)),
////   v首先与L相乘，Lv再与M相乘，MLv再与N相乘。顶点v的变换顺序是按照相反的顺序发生的。
//
//	glTranslatef(0, 2, -5); //3：位移
//
//	glScalef(5, 5, -5); //2：放大
//
//	glRotatef(90, 0, 0, -5); //1：先旋转
//
//	glBegin(GL_LINES);
//		glVertex2f(0, 0.5);
//		glVertex2f(1, 0.5);
//	glEnd();
//
//	glFlush();
//}


//初始化
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
		//glVertex2f(0.0, 0.0);  //原点为屏幕中心点
		glVertex2f(0.0, 25.0); 
		glVertex2f(25.0, -25.0);
		glVertex2f(-25.0, -25.0);
	glEnd();
}

void myDisplay(void)
{
	glLoadIdentity(); //隔离各个模型的变化效果，对矩阵值进行初始化，防止连续变换产生累积效果(效率低)
	glColor3f(1.0f, 1.0f, 1.0f);
	drawTriangle(); //绘制一个线框三角形

	glEnable(GL_LINE_STIPPLE); //绘制一个短虚线点三角形
	glLineStipple(1, 0xf0f0);
	glLoadIdentity();
	glTranslatef(-20.0, 0.0, 0.0); //向X负方向移动20个像素
	drawTriangle();
	
	glLineStipple(1, 0xf00f); //再绘制一个长虚线点三角形
	glLoadIdentity();
	glScalef(1.5, 0.5, 1.0); //三角形长放大1.5倍，宽缩小0.5倍
	drawTriangle();

	glLineStipple(1, 0x8888); //在绘制一个点三角形
	glLoadIdentity();
	glRotatef(90.0, 0.0, 0.0, 1.0); //旋转90度，模型与坐标系一同逆时针旋转
	drawTriangle();
	glDisable(GL_LINE_STIPPLE);

	glFlush();
}

int main(int argc, char *argv[]) //argc: argument component变量个数，argv[]：argument value变量值
{
	//对GLUT进行初始化
	glutInit(&argc, argv); 

	//初始化显示模式：使用arg颜色以及单缓冲()
	//GLUT_SINGLE单缓冲：将所有的指令在窗口上执行，直接在窗口上绘图，效率低，易闪屏。用于单独只显示幅非动态的图片
	//GLUT_DOUBLE双缓冲：绘图指令在一个缓冲区完成，指令完成之后，通过交换指令把完成的图像立即显示在屏幕上，效率很快。OPENGL绘图常用此方法。
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); 
	
	//设置窗口在显示屏幕中的位置(屏幕左上为原点)
	glutInitWindowPosition(100, 400); 

	//设置窗口的尺寸
	glutInitWindowSize(500, 500);

	//创建窗口并设置title，需调用glutMainLoop才能看到窗口
	glutCreateWindow("一定要坚持啊！OpenGL");

	//初始化
	init();

	//设置绘图函数
	glutDisplayFunc(&myDisplay);

	//窗口大小改变函数
	glutReshapeFunc(reshape); 

	//进行消息循环，窗口关闭才会返回
	glutMainLoop();

	return 0;
}
