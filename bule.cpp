//
// @Author: Yan Matheus Goncalves Fontao
// @Github: https://github.com/YanMatheus
//
#include <GL/glut.h>

GLfloat angle, fAspect;
GLdouble obsX=0, obsY=0, obsZ=200;

void Desenha(void){
								glClear(GL_COLOR_BUFFER_BIT);
								glColor3f(0.0f, 1.0f, 1.0f);
								glutWireTeapot(50.0f);
								glutSwapBuffers();
}

void Inicializa (void){
								GLfloat glAmbient[4]={0.2,0.2,0.2,1.0};
								GLfloat glDiffuse[4]={1,0,0,1.0};
								GLfloat glSpecular[4]={1.0, 1.0, 1.0, 1.0};
								GLfloat glPosition[4]={0.0, 50.0, 50.0, 1.0};

								GLfloat specularLevel[4]={1.0,1.0,1.0,1.0};
								GLint specularMaterial = 60;

								glClearColor(1.0f,1.0f,1.0f, 1.0f);

								glShadeModel(GL_SMOOTH);

								glMaterialfv(GL_FRONT,GL_SPECULAR, specularLevel);
								glMateriali(GL_FRONT,GL_SHININESS,specularMaterial);

								glLightModelfv(GL_LIGHT_MODEL_AMBIENT, glAmbient);

								glLightfv(GL_LIGHT0, GL_AMBIENT, glAmbient);
								glLightfv(GL_LIGHT0, GL_DIFFUSE, glDiffuse );
								glLightfv(GL_LIGHT0, GL_SPECULAR, glSpecular );
								glLightfv(GL_LIGHT0, GL_POSITION, glPosition );

								glEnable(GL_COLOR_MATERIAL);
								glEnable(GL_LIGHTING);
								glEnable(GL_LIGHT0);
								glEnable(GL_DEPTH_TEST);
								angle=45;

}

void PosicionaObservador(void){
								glMatrixMode(GL_MODELVIEW);
								glLoadIdentity();
								gluLookAt(obsX,obsY,obsZ, 0,0,0, 0,1,0);
}

void EspecificaParametrosVisualizacao(void){
								glMatrixMode(GL_PROJECTION);
								glLoadIdentity();

								gluPerspective(angle,fAspect,0.4,500);

								glMatrixMode(GL_MODELVIEW);
								glLoadIdentity();

								gluLookAt(0,80,200, 0,0,0, 0,1,0);
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h){
								if ( h == 0 ) h = 1;

								glViewport(0, 0, w, h);

								fAspect = (GLfloat)w/(GLfloat)h;

								EspecificaParametrosVisualizacao();
}

void GerenciaMouse(int button, int state, int x, int y){
								if (button == GLUT_LEFT_BUTTON)
																if (state == GLUT_DOWN) {
																								if (angle >= 10) angle -= 5;
																}
								if (button == GLUT_RIGHT_BUTTON)
																if (state == GLUT_DOWN) {
																								if (angle <= 130) angle += 5;
																}
								EspecificaParametrosVisualizacao();
								glutPostRedisplay();
}

void Teclado(unsigned char tecla, int x, int y){

								if (tecla == 119) {
																obsY +=10;
								} else if(tecla == 97) {
																obsX -=10;
								}else if(tecla == 100) {
																obsX +=10;
								}else if(tecla == 115) {
																obsY -=10;
								}
								else if(tecla == 113) {
																obsZ +=10;
								}
								else if(tecla == 101) {
																obsZ -=10;
								}
								else if(tecla == 27) {
																exit(0);
								}
								else if(tecla == 120) {

								} glLoadIdentity();
								gluLookAt(obsX,obsY,obsZ, 0,0,0, 0,1,0);
								glutPostRedisplay();
}


int main(int argc, char** argv){
								glutInit(&argc, argv);
								glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
								glutInitWindowSize(800,800);
								glutCreateWindow("Utilize A W S D Q E");
								glutDisplayFunc(Desenha);
								glutReshapeFunc(AlteraTamanhoJanela);
								glutMouseFunc(GerenciaMouse);
								Inicializa();
								glutKeyboardFunc(Teclado);
								glutMainLoop();
}
