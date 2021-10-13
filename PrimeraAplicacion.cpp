

//////////////////////////////////////////////////////
/*      PRÁCTICAS INFORMÁTICA INDUSTRIAL ETSIDI     */
//////////////////////////////////////////////////////
//
// Curso: 2020-2021
// Ejercicio 1
// Derechos: Asignatura Informática Industrial


#include <iostream> // (iostream class) The iostream library es una object-oriented library que provee funciones i/o usando streams 
#include <stdio.h>	// Librería (biblioteca) Standard Input and Output Library que usa streams para operar con dispositivos E/S físicos
#include <math.h>	// Header <cmath> declara un conjunto de funciones para operación matemática

typedef struct
{
	// Estructura tipo punto 2D
	float x;
	float y;
}punto;

typedef struct 
{
	punto centro;
	float radio;
} circunferencia;

typedef struct
{
	punto p1;
	punto p2;
}segmento;

/* 
 * Funcion: distPuntoSeg
 *
 * Calcula la distancia de un punto @p a un segmento @s
 * Devuelve la distancia @d
 */
float distPuntoSeg(punto* p, segmento *s)
{
	// Vector director del segmento. 
	float vx = s->p1.x - s->p2.x;
	float vy= s->p1.y - s->p2.y;

	if (vx == 0.0)
		return p->x;
	else if (vy == 0.0)
		return p->y;
	else
	{
		float ms = vy / vx;							// Pendiente del segmento
		float bs = s->p1.y - (ms * s->p1.x);		// Termino independiente del segmento/recta

		// Recta perpendicular al segmento que pasa por p
		float mp = (-1) / ms;						// Pendiente de la perpendicular al segumento
		float bp = p->y - (mp * p->x);				// Término independiente de la perpendicular que pasa por p
		float xc = (bp - bs) / (ms-mp);				// Punto de corte de ambas rectas (xc,yc)
		float yc = (mp * xc) + bp;

		// Distancia entre p y el punto de corte (xc,yc)
		float dx = abs(p->x - xc);
		float dy = abs(p->y - yc);
		float d = sqrt(dx * dx + dy * dy);
		return d;
	}
}

/*
 * Funcion: segmentoDatos
 *
 * Solicita los dos puntos de un segmento y los asigna a @s
 */
void segmentoDatos(segmento* s)
{
	printf_s("\n Coordenadas del primer punto del segmento (p1x, p1y)\n");
	scanf_s("%f %f", &s->p1.x, &s->p1.y);
	printf_s("\n Coordenadas del segundo punto del segmento (p2x, p2y)\n");
	scanf_s("%f %f", &s->p2.x, &s->p2.y);
}

/*
 * Funcion: colision
 *
 * Evalúa si existe colisión entre la esfera de radio @r
 * y el segmento a una distancia @d de su centro
 */
bool colision(float d, float r)
{
	if (d >= r)
		return 0; // No hay colisión
	else
		return 1; // Hay colisión
}


/*
 * Funcion: main
 *
 * Evalúa si existe colisión entre una esfera y un segmento
 */
int main()
{
	segmento s;
	circunferencia c;
	printf_s("Coordenadas del centro de la circunferencia px, py:\n"); // Circunferencia
	scanf_s("%f %f", &c.centro.x, &c.centro.y);
	printf_s("Radio de la circunferencia R:\n");
	scanf_s("%f", &c.radio);
	segmentoDatos(&s);													// Segmento
	float d=distPuntoSeg(&c.centro, &s);								// Calcula distancia 
	printf_s("\n La distancia es d= %f", d);
	bool col = colision(d, c.radio);									// Evalúa colisión
	printf_s("\n Colision: %d", col);
}

