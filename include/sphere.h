#ifndef SPHERE_H
#define SPHERE_H

class Sphere{
public: 
  float x, y;
  float vy; //Vertical velocity
  float el; //Elasticita
  int size;

  void sphere_loop(float gravity, int floor);
  Sphere(float x, float y, float el, int size);
};

#endif
