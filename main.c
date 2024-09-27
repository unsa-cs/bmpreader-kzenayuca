#include "bmp.h"
#include <GL/glut.h>
#include <stdio.h>

//comentario
BMPImage *image;

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  if (image) {
    drawBMP(image);
  }
  glFlush();
}

int main(int argc, char* argv[]) {
  //char filename[256];
	/*
	argv[0] = ./bmpReaer
       	argv[1] = image.bmp	
	 */	
	if(argc != 2)
	{
		printf("No suficientes Argumentos.\n");
		exit(-1);
	}

  // Pedir al usuario el nombre del archivo BMP
  //printf("Ingrese el nombre del archivo BMP (con extensión): ");
  //scanf("%255s", filename);

  image = readBMP(argv[1]);

  if (!image) return 1;

  // Inicializar GLUT
  int argcA = 1; // Necesario para evitar problemas con glutInit
  char *argvA[1] = { "" }; // Argumento vacío para GLUT
  glutInit(&argcA, argvA);

  // Establecer el modo de visualización
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(image->width, image->height);
  glutCreateWindow("Visualizador de BMP");

  glLoadIdentity();
  glOrtho(0, image->width, image->height, 0, -1, 1);

  glutDisplayFunc(display);
  glutMainLoop();

  freeBMP(image);
  return 0;
}
