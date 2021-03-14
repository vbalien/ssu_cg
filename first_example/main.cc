#ifdef _WIN32
#include <GL/glut.h>
#elif __APPLE__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#else
#include <GLUT/glut.h>
#endif

void reshape(int w, int h)
{
  glLoadIdentity();
  glViewport(0, 0, w, h);
  gluOrtho2D(0.0, 100.0, 0.0, 100.);
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.f, 0.f, 0.f);
  glRectf(30.f, 30.f, 50.f, 50.f);
  glutSwapBuffers();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutCreateWindow("First Example");
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}