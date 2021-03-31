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
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_DEPTH_TEST);
  glLoadIdentity();
  glColor3f(0.3f, 0.3f, 0.3f);
  gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 1.0, 1.0, 0.0);
  glutWireTeapot(0.5);
  glFlush();
  glutSwapBuffers();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(400, 400);
  glutCreateWindow("gluLookAt Example");
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}