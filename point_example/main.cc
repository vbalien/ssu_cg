#define GL_SILENCE_DEPRECATION
#ifdef _WIN32
#include <GL/glut.h>
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
  glColor3f(1.f, 1.f, 1.f);
  glGetFloatv(GL_POINT_SIZE_RANGE, size);
  glPointSize(size[0]);
  glBegin(GL_POINTS);
  for (angle = 0.f; angle <= 2.f * PI; angle += PI / 30.f)
    glVertex3f(0.5f * cosf(angle), 0.5f * sinf(angle), 0.f);
  glEnd();
  glFlush();
  glutSwapBuffers();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutCreateWindow("Point Example");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}