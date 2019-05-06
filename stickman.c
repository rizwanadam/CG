
#define GLUT_DISABLE_ATEXIT_HACK
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<stdbool.h>

 int rightHandAngle = 180; // Angle of lower right hand
 bool mouseLeftState = false; // Is left mouse clicked?
 bool mouseRightState = false; // Is right mouse clicked?
 int rightHandMove = 2; // If left mouse clicked, right hand will rotate 2 degrees.
 int leftLegMove = 1; // If right mouse clicked, left leg will move by 1.
 int rightLegMove = -1; // If right mouse clicked, right leg will move by 1.
 int leftLegAngle = 90; // If right mouse clicked, this variable will be used to rotate left leg and it initialized to 90 degrees for first position of leg.
 int rightLegAngle = 90; // If right mouse clicked, this variable will be used to rotate right leg and it initialized to 90 degrees for first position of leg.
 float zMove = 0.0; // If right mouse clicked, this variable will be used to change position of object. Object will move on z-axis.

 void display(){
         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

         glPushMatrix(); //BODY
         glColor3f(1.0, 0.647, 0.0);
         glTranslatef(0.0, 221, zMove);
         glRotatef(90, 1.0, 0.0, 0.0);
         GLUquadricObj* body = gluNewQuadric();
         gluQuadricDrawStyle(body, GLU_FILL);
         gluCylinder(body, 120, 120, 300, 30, 30);
         glPopMatrix();

         glPushMatrix(); //LEFT UPPER ARM
         glColor3f(0.180f, 0.545f, 0.341f);
         glTranslatef(-80, 160, zMove);
         glRotatef(-45, 0.0, 0.0, 1.0);
         glRotatef(90, 1.0, 0.0, 0.0);
         GLUquadricObj* leftUpperArm = gluNewQuadric();
         gluQuadricDrawStyle(leftUpperArm, GLU_FILL);
         gluCylinder(leftUpperArm, 16, 16, 200, 30, 30);
         glPopMatrix();

         glPushMatrix(); // LEFT UPPER ARM AND BODY CONNECTION
         glColor3f(1.0, 0.0, 0.0);
         glPushMatrix();
         glTranslatef(-80.0, 160, zMove);
         glutSolidSphere(16, 30, 30);
         glPopMatrix();

         glPushMatrix(); //LEFT LOWER ARM
         glColor3f(1.0, 1.0, 0.0);
         glTranslatef(-221.5, 19.5, zMove);
         glRotatef(225, 0.0, 0.0, 1.0);
         glRotatef(90, 1.0, 0.0, 0.0);
         GLUquadricObj* leftLowerArm = gluNewQuadric();
         gluQuadricDrawStyle(leftLowerArm, GLU_FILL);
         gluCylinder(leftLowerArm, 16, 16, 200, 30, 30);
         glPopMatrix();

         glPushMatrix(); // LEFT LOWER ARM AND LEFT UPPER ARM CONNECTION
         glColor3f(1.0, 0.0, 0.0);
         glPushMatrix();
         glTranslatef(-221.5, 19.5, zMove);
         glutSolidSphere(16, 30, 30);
         glPopMatrix();

         glPushMatrix(); //RIGHT UPPER ARM
         glColor3f(0.180f, 0.545f, 0.341f);
         glTranslatef(80, 160, zMove);
         glRotatef(90, 0.0, 0.0, 1.0);
         glRotatef(90, 1.0, 0.0, 0.0);
         GLUquadricObj* rightUpperArm = gluNewQuadric();
         gluQuadricDrawStyle(rightUpperArm, GLU_FILL);
         gluCylinder(rightUpperArm, 16, 16, 200, 30, 30);
         glPopMatrix();

         glPushMatrix(); // RIGHT UPPER ARM AND BODY CONNECTION
         glColor3f(1.0, 0.0, 0.0);
         glPushMatrix();
         glTranslatef(80, 160, zMove);
         glutSolidSphere(16, 30, 30);
         glPopMatrix();

         glPushMatrix(); //RIGHT LOWER ARM
         glColor3f(1.0, 1.0, 0.0);
         glTranslatef(280, 160, zMove);
         glRotatef((GLfloat)rightHandAngle, 0.0, 0.0, 1.0);
         glRotatef(90, 1.0, 0.0, 0.0);
         GLUquadricObj* rightLowerArm = gluNewQuadric();
         gluQuadricDrawStyle(rightLowerArm, GLU_FILL);
         gluCylinder(rightLowerArm, 16, 16, 200, 30, 30);
         glPopMatrix();

         glPushMatrix(); // RIGHT LOWER ARM AND RIGHT UPPER ARM CONNECTION
         glColor3f(1.0, 0.0, 0.0);
         glPushMatrix();
         glTranslatef(280, 160, zMove);
         glutSolidSphere(16, 30, 30);
         glPopMatrix();

         glPushMatrix(); //LEFT LEG
         glColor3f(0.180f, 0.545f, 0.341f);
         glTranslatef(-35, -20, zMove);
         glRotatef(-15, 0.0, 0.0, 1.0);
         glRotatef((GLfloat)leftLegAngle, 1.0, 0.0, 0.0);
         GLUquadricObj* leftLeg = gluNewQuadric();
         gluQuadricDrawStyle(leftLeg, GLU_FILL);
         gluCylinder(leftLeg, 16, 16, 400, 30, 30);
         glPopMatrix();

         glPushMatrix(); // LEFT LEG AND BODY CONNECTION
         glColor3f(1.0, 0.0, 0.0);
         glPushMatrix();
         glTranslatef(-35, -20, zMove);
         glutSolidSphere(16, 30, 30);
         glPopMatrix();

         glPushMatrix(); //RIGHT LEG
         glColor3f(0.180f, 0.545f, 0.341f);
         glTranslatef(35, -20, zMove);
         glRotatef(15, 0.0, 0.0, 1.0);
         glRotatef((GLfloat)rightLegAngle, 1.0, 0.0, 0.0);
         GLUquadricObj* rightLeg = gluNewQuadric();
         gluQuadricDrawStyle(rightLeg, GLU_FILL);
         gluCylinder(rightLeg, 16, 16, 400, 30, 30);
         glPopMatrix();

         glPushMatrix(); // RIGHT LEG AND BODY CONNECTION
         glColor3f(1.0, 0.0, 0.0);
         glPushMatrix();
         glTranslatef(35, -20, zMove);
         glutSolidSphere(16, 30, 30);
         glPopMatrix();

         glPushMatrix(); //NECK
         glColor3f(0.0, 0.0, 0.545);
         glTranslatef(0.0, 251, zMove);
         glRotatef(90, 1.0, 0.0, 0.0);
         GLUquadricObj* neck = gluNewQuadric();
         gluQuadricDrawStyle(neck, GLU_FILL);
         gluCylinder(neck, 20, 20, 30, 30, 30);
         glPopMatrix();

         glPushMatrix(); // HEAD
         glColor3f(1.0, 0.647, 0.0);
         glPushMatrix();
         glTranslatef(0.0, 350, zMove);
         glutSolidSphere(100, 30, 30);
         glPopMatrix();


         if (mouseLeftState == true){ // If left mouse clicked right hand of object will shake its lower arm
             if (rightHandAngle >= 225) { // If angle is greater than 225 incrementing degree will become decrement
                 rightHandMove = -rightHandMove;
             }
             else if (rightHandAngle <= 135){ // If angle is lower than 135 decrementing degree will become increment
                 rightHandMove = -rightHandMove;
             }
             rightHandAngle = (rightHandAngle + rightHandMove) % 360; // changing angle of right hand.
         }
         if (mouseRightState == true){ // If right mouse clicked the object will ve moved and legs' angles will be changed.
             if (leftLegAngle > 110){
                 leftLegMove = -leftLegMove;
             }
             else if (leftLegAngle < 70){
                 leftLegMove = -leftLegMove;
             }
             leftLegAngle = (leftLegAngle + leftLegMove) % 360; // Changing angle of left leg

             if (rightLegAngle > 110) {
                 rightLegMove = -rightLegMove;
             }
             else if (rightLegAngle < 70){
                 rightLegMove = -rightLegMove;
             }
             rightLegAngle = (rightLegAngle + rightLegMove) % 360; // Changing angle of right leg
             zMove += 1.5f; // Moving object on the z-axis
         }
     glutSwapBuffers();
 }
 void keyboard(unsigned char key, int x, int y){
     if (key == 27) // exit when user hits <esc>
         exit(EXIT_SUCCESS);
 }
 void rotate(int key, int x, int y)
 {
     if (key == GLUT_KEY_LEFT){
         glRotatef(-1, 0.0, 1.0, 0.0);    // Rotates left by 1 degree
         glutPostRedisplay();
     }
     if (key == GLUT_KEY_RIGHT){

         glRotatef(1, 0.0, 1.0, 0.0);    // Rotates right by 1 degree
         glutPostRedisplay();
     }
     if (key == GLUT_KEY_UP){
         glRotatef(1, 1.0, 0.0, 0.0);    // Rotates up by 1 degree
         glutPostRedisplay();
     }
     if (key == GLUT_KEY_DOWN){
         glRotatef(-1, 1.0, 0.0, 0.0);    // Rotates down by 1 degree
         glutPostRedisplay();
     }
 }
 void mouse(int button, int state, int x, int y){
     if (GLUT_LEFT_BUTTON == button && state == GLUT_DOWN && mouseLeftState == false){ // If left button is clicked, left state will be true for shaking lower arm
         mouseLeftState = true;
     }
     else if (GLUT_LEFT_BUTTON == button && state == GLUT_DOWN && mouseLeftState == true){ // If left button is clicked again, left state will be false and shaking will stop.
         mouseLeftState = false;
     }
     else if (GLUT_RIGHT_BUTTON == button && state == GLUT_DOWN && mouseRightState == false){ // If right button is clicked again, moving of object and rotation of legs will stop.
         mouseRightState = true;
     }
     else if (GLUT_RIGHT_BUTTON == button && state == GLUT_DOWN && mouseRightState == true){ // If right button is clicked, right state will be true and moving object and rotation of legs will start
         mouseRightState = false;
     }
 }
 void timer(int notUsed) // Timer is for animation. This function provides us to redisplay all objects by every 100 miliseconds
 {
     glutPostRedisplay();
     glutTimerFunc(100, timer, 0);
 }
 int main(int argc, char *argv[]){
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
     glEnable(GL_DEPTH_TEST); // Hidden surface removal
     glutInitWindowSize(1200, 700);
     glutCreateWindow(argv[0]);
     glClearColor(0.0, 1.0, 1.0, 0.0);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glOrtho(-750.0, 750.0, -500.0, 500.0, -500.0, 500.0); // Changing the coordinate system.
     glutDisplayFunc(display);
     glutSpecialFunc(rotate);
     glutKeyboardFunc(keyboard);
     glutMouseFunc(mouse);
     timer(0);
     glutMainLoop();
     return EXIT_SUCCESS;
 }
