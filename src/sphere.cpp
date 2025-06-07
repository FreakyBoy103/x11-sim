#include "../include/sphere.h"

#include <iostream>

Sphere::Sphere(float x, float y, float el, int size){

  this->x = x;
  this->y = y;
  this->el = el;
  this->vy = 0;
  this->size = size;

}

void Sphere::sphere_loop(float gravity, int floor){
  vy += gravity;
  y += vy;

  if(y >= (floor - size)){
    y = floor - size;
    vy *= -el; //Riduce la velocita del 70%
  }

}


