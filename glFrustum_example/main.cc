#ifdef _WIN32
#include <GL/glut.h>
#elif __APPLE__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include <math.h>

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glShadeModel(GL_FLAT);
  glColor3f(0.0f, 0.0f, 1.0f);
  glLoadIdentity();
  gluLookAt(1.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  glScalef(1.0f, 2.0f, 1.0f);
  glutWireTeapot(3.0);
  glFlush();
  glutSwapBuffers();
}

void reshape(int w, int h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(800, 400);
  glutCreateWindow("gluFrustum Example");
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
}