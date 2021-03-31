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
  glViewport(0, 0, 300, 300);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  // 빨간색 사각형
  glPushMatrix();
  {
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidCube(0.3);
  }
  glPopMatrix();
  // 녹색 사각형
  glLoadIdentity();
  glPushMatrix();
  {
    glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.6f, 0.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glutSolidCube(0.3);
  }
  glPopMatrix();
  // 파란 사각형
  glLoadIdentity();
  glPushMatrix();
  {
    glTranslatef(0.6f, 0.0f, 0.0f);
    glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glutSolidCube(0.3);
  }
  glPopMatrix();

  glFlush();
  glutSwapBuffers();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);
  glutInitWindowSize(300, 300);
  glutCreateWindow("Transformation Example");
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}