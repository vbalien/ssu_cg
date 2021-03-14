#ifdef _WIN32
#include <GL/glut.h>
#elif __APPLE__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include <math.h>

#define PI 3.14f

void display()
{
  GLfloat size[2];
  GLfloat angle;
  glClear(GL_COLOR_BUFFER_BIT);
  glShadeModel(GL_SMOOTH);
  glBegin(GL_TRIANGLES);
  {
    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(0.f, .5f, 0.f);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-.5f, -.5f, 0.f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(.5f, -.5f, 0.f);
  }
  glEnd();
  glFlush();
  glutSwapBuffers();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutCreateWindow("Triangle Example");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}